#include "ForceApi.h"

// estimate_weight는 Force_Calibration.c 안에 있으니까 extern 선언
extern s16 estimate_weight(s16 x_coord, s16 y_coord, s16* sensor_values);

// Config.h에 extern으로 선언돼 있고, ForceState.c에서 실제 정의됨
extern s16 var_scaler[SUPPORT_FORCE_BUTTON_NODE];

void DLL_CALL Force_SetScaler(const s16* scaler6)
{
    int i;
    for (i = 0; i < SUPPORT_FORCE_BUTTON_NODE; i++)
        var_scaler[i] = scaler6[i];
}

s16 DLL_CALL Force_EstimateWeight(s16 x, s16 y, const s16* sensor6)
{
    // estimate_weight가 s16*를 받으니 캐스팅
    return estimate_weight(x, y, (s16*)sensor6);
}