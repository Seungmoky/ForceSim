#include <stdio.h>
#include <string.h>
#include "log_parser.h"

int parse_scaler_line(const char* line, int out_scaler[6])
{
    return sscanf(
        line,
        "[%*[^]]] Scaler1:%d,Scaler2:%d,Scaler3:%d,Scaler4:%d,Scaler5:%d,Scaler6:%d",
        &out_scaler[0], &out_scaler[1], &out_scaler[2],
        &out_scaler[3], &out_scaler[4], &out_scaler[5]
    ) == 6;
}

int parse_log_entry_line(const char* line, LogEntry* out_entry)
{
    if (!out_entry) return 0;

    return sscanf(
        line,
        "[%*[^]]] X:%d,Y:%d,S1=%d,S2=%d,S3=%d,S4=%d,S5=%d,S6=%d,P:%d",
        &out_entry->x,
        &out_entry->y,
        &out_entry->s[0],
        &out_entry->s[1],
        &out_entry->s[2],
        &out_entry->s[3],
        &out_entry->s[4],
        &out_entry->s[5],
        &out_entry->old_p
    ) == 9;
}