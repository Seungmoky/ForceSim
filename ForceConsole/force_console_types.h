#pragma once

typedef struct DebugConfig
{
    int enable;
    char log_file[260];
    int tp_width;
    int tp_height;
    int table_cols;
    int table_rows;
} DebugConfig;

typedef struct LogEntry
{
    int x;
    int y;
    int s[6];
    int old_p;
} LogEntry;