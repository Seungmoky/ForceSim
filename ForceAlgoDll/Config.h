#pragma once
#ifdef _MSC_VER
#define ALIGNED_4_OPTION __declspec(align(4))
#define ALIGNED_2_OPTION __declspec(align(2))
#else
#define ALIGNED_4_OPTION __attribute__((aligned(4)))
#define ALIGNED_2_OPTION __attribute__((aligned(2)))
#endif

#ifdef _MSC_VER
#define DLL_EXPORT __declspec(dllexport)
#define DLL_CALL   __cdecl
#else
#define DLL_EXPORT
#define DLL_CALL
#endif

#define SUPPORT_FSR_CAL_AS_INTERPOLATION	1
#define SUPPORT_FORCE_BUTTON_NODE			6
#define DEF_USE_LINEAR_LEAST_SQUARE	0
#define DEF_USE_CUBIC_INTERPOLATION	1
#define DEF_USE_RAWDATA_NORMALIZE	1
#define DEF_USE_TEST_NORMALIZE_OPTION 1
#define DEF_FIX_SENSOR_START	0
#define DEF_FIX_SENSOR_END		5

typedef signed char s8;
typedef unsigned char u8;
typedef signed short s16;
typedef unsigned short u16;
typedef signed int s32;
typedef unsigned int u32;
typedef signed long long s64;
typedef unsigned long long u64;

typedef struct ALIGNED_4_OPTION _point
{
    s16 x;
    s16 y;
} point_t;

#define ztCLIP(VALUE, MIN, MAX) (VALUE < MIN ? MIN : (VALUE > MAX ? MAX : VALUE))
extern s16 var_scaler[SUPPORT_FORCE_BUTTON_NODE];