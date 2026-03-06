#pragma once
#include <stdio.h>
#include "force_console_types.h"

int parse_scaler_line(const char* line, int out_scaler[6]);
int parse_log_entry_line(const char* line, LogEntry* out_entry);