#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include "config_parser.h"

static void trim(char* s)
{
    char* p = s;
    char* end;

    while (isspace((unsigned char)*p)) p++;
    if (p != s) memmove(s, p, strlen(p) + 1);

    end = s + strlen(s) - 1;
    while (end >= s && isspace((unsigned char)*end))
    {
        *end = '\0';
        --end;
    }
}

int load_debug_config(const char* file_path, DebugConfig* out_cfg)
{
    FILE* fp;
    char line[512];
    char section[64] = "";

    if (!out_cfg) return 0;

    out_cfg->enable = 0;
    strcpy(out_cfg->log_file, "log.txt");
    out_cfg->tp_width = 2304;
    out_cfg->tp_height = 1600;
    out_cfg->table_cols = 18;
    out_cfg->table_rows = 13;

    fp = fopen(file_path, "r");
    if (!fp) return 0;

    while (fgets(line, sizeof(line), fp))
    {
        char* eq;
        trim(line);

        if (line[0] == '\0' || line[0] == ';' || line[0] == '#')
            continue;

        if (line[0] == '[')
        {
            char* end = strchr(line, ']');
            if (end)
            {
                *end = '\0';
                strcpy(section, line + 1);
            }
            continue;
        }

        eq = strchr(line, '=');
        if (!eq) continue;

        *eq = '\0';
        {
            char key[128];
            char value[256];
            strcpy(key, line);
            strcpy(value, eq + 1);
            trim(key);
            trim(value);

            if (strcmp(section, "debug") == 0)
            {
                if (strcmp(key, "enable") == 0) out_cfg->enable = atoi(value);
                else if (strcmp(key, "log_file") == 0) strcpy(out_cfg->log_file, value);
            }
            else if (strcmp(section, "touchpad") == 0)
            {
                if (strcmp(key, "width") == 0) out_cfg->tp_width = atoi(value);
                else if (strcmp(key, "height") == 0) out_cfg->tp_height = atoi(value);
            }
            else if (strcmp(section, "section") == 0)
            {
                if (strcmp(key, "cols") == 0) out_cfg->table_cols = atoi(value);
                else if (strcmp(key, "rows") == 0) out_cfg->table_rows = atoi(value);
            }
        }
    }

    fclose(fp);
    return 1;
}