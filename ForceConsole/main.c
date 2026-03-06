#include <stdio.h>
#include "config_parser.h"
#include "debug_runner.h"
#include "Config.h"
#include <windows.h>

s16 var_scaler[SUPPORT_FORCE_BUTTON_NODE] = { 300, 300, 300, 300, 300, 300 };

int main(void)
{
    DebugConfig cfg;

    if (!load_debug_config("setting.conf", &cfg))
    {
        printf("failed to load setting.conf\n");
        return 1;
    }

    if (!cfg.enable)
    {
        printf("debug mode disabled. ForceConsole will not run.\n");
        return 0;
    }

    if (!run_debug_console(&cfg))
    {
        printf("debug console failed.\n");
        return 1;
    }
    system("pause");

    return 0;
}