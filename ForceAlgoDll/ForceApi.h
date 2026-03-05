#pragma once
#include "Config.h"

#ifdef __cplusplus
extern "C" {
#endif

#ifdef _MSC_VER
#define DLL_EXPORT __declspec(dllexport)
#define DLL_CALL   __cdecl
#else
#define DLL_EXPORT
#define DLL_CALL
#endif

    // scaler 6개를 DLL 내부 var_scaler에 설정
    DLL_EXPORT void DLL_CALL Force_SetScaler(const s16* scaler6);

    // (x,y, sensor6) 입력 -> 펌웨어 방식 Pressure(또는 Weight) 출력
    DLL_EXPORT s16  DLL_CALL Force_EstimateWeight(s16 x, s16 y, const s16* sensor6);

#ifdef __cplusplus
}
#endif