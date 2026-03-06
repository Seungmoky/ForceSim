#include <stdio.h>
#include <string.h>
#include "debug_runner.h"
#include "log_parser.h"
#include "Config.h"

s16 estimate_weight(s16 x_coord, s16 y_coord, s16* sensor_values);

extern s16 var_scaler[SUPPORT_FORCE_BUTTON_NODE];

static int calc_sx(int x, int tp_width, int table_cols)
{
    int sx;
    if (tp_width <= 0 || table_cols <= 0) return 0;
    sx = x * table_cols / tp_width;
    return ztCLIP(sx, 0, table_cols - 1);
}

static int calc_sy(int y, int tp_height, int table_rows)
{
    int sy;
    if (tp_height <= 0 || table_rows <= 0) return 0;
    sy = y * table_rows / tp_height;
    sy = ztCLIP(sy, 0, table_rows - 1);
    sy = (table_rows - 1) - sy;
    return sy;
}

int run_debug_console(const DebugConfig* cfg)
{
    char log_path[512];
    FILE* fp;
    char line[1024];
    int scaler[6];
    int idx = 0;

    if (!cfg) return 0;

    sprintf(log_path, "logs\\%s", cfg->log_file);

    fp = fopen(log_path, "r");
    if (!fp)
    {
        printf("failed to open log file: %s\n", log_path);
        return 0;
    }
    printf("log_file=%s, tp=%dx%d, table=%dx%d\n",
        cfg->log_file, cfg->tp_width, cfg->tp_height, cfg->table_cols, cfg->table_rows);

    printf("%5s %4s %4s %4s %4s %4s %4s %4s %4s %4s %4s %3s %3s\n",
        "idx", "X", "Y", "P", "Sa", "Sb", "Sc", "Sd", "Se", "Sf", "D", "SX", "SY");

    while (fgets(line, sizeof(line), fp))
    {
        if (parse_scaler_line(line, scaler))
        {
            int i;
            for (i = 0; i < 6; ++i)
                var_scaler[i] = (s16)scaler[i];

            printf("Scaler applied: %d, %d, %d, %d, %d, %d\n",
                scaler[0], scaler[1], scaler[2], scaler[3], scaler[4], scaler[5]);
            printf("%5s %4s %4s %4s %4s %4s %4s %4s %4s %4s %4s %3s %3s\n",
                "idx", "X", "Y", "P", "Sa", "Sb", "Sc", "Sd", "Se", "Sf", "D", "SX", "SY");
            continue;
        }

        {
            LogEntry e;
            s16 sensor_values[6];
            s16 new_p;
            int delta;
            int sx, sy;

            if (!parse_log_entry_line(line, &e))
                continue;

            sensor_values[0] = (s16)e.s[0];
            sensor_values[1] = (s16)e.s[1];
            sensor_values[2] = (s16)e.s[2];
            sensor_values[3] = (s16)e.s[3];
            sensor_values[4] = (s16)e.s[4];
            sensor_values[5] = (s16)e.s[5];

            new_p = estimate_weight((s16)e.x, (s16)e.y, sensor_values);
            delta = (int)new_p - e.old_p;
            sx = calc_sx(e.x, cfg->tp_width, cfg->table_cols);
            sy = calc_sy(e.y, cfg->tp_height, cfg->table_rows);

            printf("%5d %4d %4d %4d %4d %4d %4d %4d %4d %4d %4d %3d %3d\n",
                idx,
                e.x, e.y, new_p,
                e.s[0], e.s[1], e.s[2], e.s[3], e.s[4], e.s[5],
                delta, sx, sy);

            idx++;
        }
    }

    fclose(fp);
    return 1;
}