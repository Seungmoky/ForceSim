#ifndef _FORCE_RAWDATA_H
#define _FORCE_RAWDATA_H
#include "Config.h"

#if(SUPPORT_FSR_CAL_AS_INTERPOLATION)
#define DEF_FIX_SENSOR_START 0
#define DEF_FIX_SENSOR_END  5

#define DEF_WEIGHT_CNT 1
#define DEF_ZONE_X_CNT 18
#define DEF_ZONE_Y_CNT 13

const s16 x_divide[DEF_ZONE_X_CNT] = { 94, 220, 346, 472, 599, 724, 851, 977, 1103, 1229, 1355, 1481, 1607, 1733, 1859, 1985, 2111, 2237 };
const s16 y_divide[DEF_ZONE_Y_CNT] = { 76, 200, 324, 447, 571, 694, 818, 942, 1065, 1189, 1312, 1436, 1560 };
const s16 FSR_Weight_Items[DEF_WEIGHT_CNT] = { 150 };
const s16 scaler[SUPPORT_FORCE_BUTTON_NODE] = { 229, 253, 247, 235, 355, 397 };
// Curve fitting slopes (Q8 fixed-point, actual_slope = FSR_Slope[j] / 256.0)
const s16 FSR_Slope[SUPPORT_FORCE_BUTTON_NODE] = { 387, 426, 413, 394, 544, 614 };
const s16 FSR_Zone[DEF_ZONE_Y_CNT * DEF_ZONE_X_CNT * DEF_WEIGHT_CNT][SUPPORT_FORCE_BUTTON_NODE] =
{
    // W_sum Corrected Weights (Q8 fixed-point, sigma=300.0px, ref=150g)
    // usage: sum(sensor_j * 150/scaler_j * stored[i][j]) >> 8 ≈ 150
    //18x13_SP_QR005_smutual_0823_0916_260402
    //18x13_SP_QR006_smutual_0823_0916_260402
    //18x13_SP_QR018_smutual_0823_0916_260402
    //18x13_SP_QR032_smutual_0823_0916_260402
    //18x13_SP_QR043_smutual_0823_0916_260402
    //18x13_SP_QR045_smutual_0823_0916_260402
    //18x13_SP_QR080_smutual_0823_0916_260402
    //18x13_SP_QR085_smutual_0823_0916_260402

        // 1 - x: 94, y: 76 org LB
        // Sa, Sb, Sc, Sd, Se, Sf
        {274, 7, 16, 5, 24, 11}, //150g

        // 2 - x: 220, y: 76 org LB
        // Sa, Sb, Sc, Sd, Se, Sf
        {335, 10, 22, 7, 40, 16}, //150g

        // 3 - x: 346, y: 76 org LB
        // Sa, Sb, Sc, Sd, Se, Sf
        {390, 18, 33, 12, 79, 27}, //150g

        // 4 - x: 472, y: 76 org LB
        // Sa, Sb, Sc, Sd, Se, Sf
        {379, 29, 44, 18, 144, 42}, //150g

        // 5 - x: 599, y: 76 org LB
        // Sa, Sb, Sc, Sd, Se, Sf
        {273, 35, 44, 21, 203, 47}, //150g

        // 6 - x: 724, y: 76 org LB
        // Sa, Sb, Sc, Sd, Se, Sf
        {150, 31, 32, 18, 213, 38}, //150g

        // 7 - x: 851, y: 76 org LB
        // Sa, Sb, Sc, Sd, Se, Sf
        {76, 25, 20, 13, 205, 28}, //150g

        // 8 - x: 977, y: 76 org LB
        // Sa, Sb, Sc, Sd, Se, Sf
        {42, 22, 14, 11, 200, 21}, //150g

        // 9 - x: 1103, y: 76 org LB
        // Sa, Sb, Sc, Sd, Se, Sf
        {27, 23, 10, 10, 201, 18}, //150g

        // 10 - x: 1229, y: 76 org LB
        // Sa, Sb, Sc, Sd, Se, Sf
        {23, 29, 10, 11, 206, 18}, //150g

        // 11 - x: 1355, y: 76 org LB
        // Sa, Sb, Sc, Sd, Se, Sf
        {24, 48, 12, 15, 216, 23}, //150g

        // 12 - x: 1481, y: 76 org LB
        // Sa, Sb, Sc, Sd, Se, Sf
        {29, 91, 15, 24, 227, 32}, //150g

        // 13 - x: 1607, y: 76 org LB
        // Sa, Sb, Sc, Sd, Se, Sf
        {35, 180, 20, 37, 238, 44}, //150g

        // 14 - x: 1733, y: 76 org LB
        // Sa, Sb, Sc, Sd, Se, Sf
        {38, 315, 23, 49, 216, 51}, //150g

        // 15 - x: 1859, y: 76 org LB
        // Sa, Sb, Sc, Sd, Se, Sf
        {29, 408, 19, 46, 144, 43}, //150g

        // 16 - x: 1985, y: 76 org LB
        // Sa, Sb, Sc, Sd, Se, Sf
        {17, 399, 12, 32, 75, 27}, //150g

        // 17 - x: 2111, y: 76 org LB
        // Sa, Sb, Sc, Sd, Se, Sf
        {10, 327, 7, 21, 37, 15}, //150g

        // 18 - x: 2237, y: 76 org LB
        // Sa, Sb, Sc, Sd, Se, Sf
        {6, 257, 5, 16, 22, 10}, //150g

        // 19 - x: 94, y: 200 org LB
        // Sa, Sb, Sc, Sd, Se, Sf
        {247, 5, 14, 4, 18, 9}, //150g

        // 20 - x: 220, y: 200 org LB
        // Sa, Sb, Sc, Sd, Se, Sf
        {306, 8, 20, 6, 31, 14}, //150g

        // 21 - x: 346, y: 200 org LB
        // Sa, Sb, Sc, Sd, Se, Sf
        {363, 15, 32, 10, 67, 25}, //150g

        // 22 - x: 472, y: 200 org LB
        // Sa, Sb, Sc, Sd, Se, Sf
        {376, 26, 48, 18, 140, 44}, //150g

        // 23 - x: 599, y: 200 org LB
        // Sa, Sb, Sc, Sd, Se, Sf
        {280, 34, 50, 22, 215, 53}, //150g

        // 24 - x: 724, y: 200 org LB
        // Sa, Sb, Sc, Sd, Se, Sf
        {154, 31, 36, 19, 240, 45}, //150g

        // 25 - x: 851, y: 200 org LB
        // Sa, Sb, Sc, Sd, Se, Sf
        {73, 24, 22, 14, 233, 31}, //150g

        // 26 - x: 977, y: 200 org LB
        // Sa, Sb, Sc, Sd, Se, Sf
        {37, 19, 13, 10, 227, 22}, //150g

        // 27 - x: 1103, y: 200 org LB
        // Sa, Sb, Sc, Sd, Se, Sf
        {22, 18, 9, 9, 226, 17}, //150g

        // 28 - x: 1229, y: 200 org LB
        // Sa, Sb, Sc, Sd, Se, Sf
        {19, 24, 9, 10, 232, 18}, //150g

        // 29 - x: 1355, y: 200 org LB
        // Sa, Sb, Sc, Sd, Se, Sf
        {21, 43, 11, 15, 242, 24}, //150g

        // 30 - x: 1481, y: 200 org LB
        // Sa, Sb, Sc, Sd, Se, Sf
        {27, 87, 15, 25, 253, 36}, //150g

        // 31 - x: 1607, y: 200 org LB
        // Sa, Sb, Sc, Sd, Se, Sf
        {34, 180, 21, 41, 259, 50}, //150g

        // 32 - x: 1733, y: 200 org LB
        // Sa, Sb, Sc, Sd, Se, Sf
        {36, 315, 23, 54, 221, 56}, //150g

        // 33 - x: 1859, y: 200 org LB
        // Sa, Sb, Sc, Sd, Se, Sf
        {25, 389, 17, 47, 133, 43}, //150g

        // 34 - x: 1985, y: 200 org LB
        // Sa, Sb, Sc, Sd, Se, Sf
        {14, 366, 10, 31, 62, 24}, //150g

        // 35 - x: 2111, y: 200 org LB
        // Sa, Sb, Sc, Sd, Se, Sf
        {7, 290, 5, 18, 28, 12}, //150g

        // 36 - x: 2237, y: 200 org LB
        // Sa, Sb, Sc, Sd, Se, Sf
        {5, 232, 4, 14, 17, 8}, //150g

        // 37 - x: 94, y: 324 org LB
        // Sa, Sb, Sc, Sd, Se, Sf
        {235, 5, 19, 4, 19, 11}, //150g

        // 38 - x: 220, y: 324 org LB
        // Sa, Sb, Sc, Sd, Se, Sf
        {292, 8, 25, 6, 33, 16}, //150g

        // 39 - x: 346, y: 324 org LB
        // Sa, Sb, Sc, Sd, Se, Sf
        {347, 15, 39, 11, 69, 30}, //150g

        // 40 - x: 472, y: 324 org LB
        // Sa, Sb, Sc, Sd, Se, Sf
        {361, 26, 58, 19, 143, 51}, //150g

        // 41 - x: 599, y: 324 org LB
        // Sa, Sb, Sc, Sd, Se, Sf
        {283, 35, 62, 24, 230, 66}, //150g

        // 42 - x: 724, y: 324 org LB
        // Sa, Sb, Sc, Sd, Se, Sf
        {163, 33, 46, 22, 271, 59}, //150g

        // 43 - x: 851, y: 324 org LB
        // Sa, Sb, Sc, Sd, Se, Sf
        {78, 26, 27, 16, 266, 41}, //150g

        // 44 - x: 977, y: 324 org LB
        // Sa, Sb, Sc, Sd, Se, Sf
        {38, 20, 16, 12, 258, 28}, //150g

        // 45 - x: 1103, y: 324 org LB
        // Sa, Sb, Sc, Sd, Se, Sf
        {23, 19, 11, 10, 258, 22}, //150g

        // 46 - x: 1229, y: 324 org LB
        // Sa, Sb, Sc, Sd, Se, Sf
        {19, 24, 10, 11, 263, 23}, //150g

        // 47 - x: 1355, y: 324 org LB
        // Sa, Sb, Sc, Sd, Se, Sf
        {22, 44, 13, 18, 272, 31}, //150g

        // 48 - x: 1481, y: 324 org LB
        // Sa, Sb, Sc, Sd, Se, Sf
        {28, 91, 18, 31, 284, 46}, //150g

        // 49 - x: 1607, y: 324 org LB
        // Sa, Sb, Sc, Sd, Se, Sf
        {36, 187, 24, 51, 285, 64}, //150g

        // 50 - x: 1733, y: 324 org LB
        // Sa, Sb, Sc, Sd, Se, Sf
        {36, 307, 25, 65, 228, 67}, //150g

        // 51 - x: 1859, y: 324 org LB
        // Sa, Sb, Sc, Sd, Se, Sf
        {25, 370, 18, 57, 135, 49}, //150g

        // 52 - x: 1985, y: 324 org LB
        // Sa, Sb, Sc, Sd, Se, Sf
        {14, 347, 11, 38, 64, 28}, //150g

        // 53 - x: 2111, y: 324 org LB
        // Sa, Sb, Sc, Sd, Se, Sf
        {7, 280, 6, 23, 30, 15}, //150g

        // 54 - x: 2237, y: 324 org LB
        // Sa, Sb, Sc, Sd, Se, Sf
        {5, 223, 4, 18, 18, 10}, //150g

        // 55 - x: 94, y: 447 org LB
        // Sa, Sb, Sc, Sd, Se, Sf
        {234, 7, 32, 6, 26, 16}, //150g

        // 56 - x: 220, y: 447 org LB
        // Sa, Sb, Sc, Sd, Se, Sf
        {284, 10, 41, 9, 43, 24}, //150g

        // 57 - x: 346, y: 447 org LB
        // Sa, Sb, Sc, Sd, Se, Sf
        {337, 18, 60, 14, 83, 42}, //150g

        // 58 - x: 472, y: 447 org LB
        // Sa, Sb, Sc, Sd, Se, Sf
        {342, 29, 79, 23, 155, 67}, //150g

        // 59 - x: 599, y: 447 org LB
        // Sa, Sb, Sc, Sd, Se, Sf
        {277, 38, 82, 29, 242, 86}, //150g

        // 60 - x: 724, y: 447 org LB
        // Sa, Sb, Sc, Sd, Se, Sf
        {173, 38, 63, 27, 292, 82}, //150g

        // 61 - x: 851, y: 447 org LB
        // Sa, Sb, Sc, Sd, Se, Sf
        {90, 31, 39, 22, 298, 63}, //150g

        // 62 - x: 977, y: 447 org LB
        // Sa, Sb, Sc, Sd, Se, Sf
        {48, 26, 24, 17, 292, 46}, //150g

        // 63 - x: 1103, y: 447 org LB
        // Sa, Sb, Sc, Sd, Se, Sf
        {30, 25, 17, 15, 295, 38}, //150g

        // 64 - x: 1229, y: 447 org LB
        // Sa, Sb, Sc, Sd, Se, Sf
        {25, 32, 15, 18, 300, 39}, //150g

        // 65 - x: 1355, y: 447 org LB
        // Sa, Sb, Sc, Sd, Se, Sf
        {27, 53, 18, 26, 302, 49}, //150g

        // 66 - x: 1481, y: 447 org LB
        // Sa, Sb, Sc, Sd, Se, Sf
        {34, 103, 23, 44, 312, 69}, //150g

        // 67 - x: 1607, y: 447 org LB
        // Sa, Sb, Sc, Sd, Se, Sf
        {40, 194, 29, 69, 301, 88}, //150g

        // 68 - x: 1733, y: 447 org LB
        // Sa, Sb, Sc, Sd, Se, Sf
        {38, 299, 29, 85, 239, 88}, //150g

        // 69 - x: 1859, y: 447 org LB
        // Sa, Sb, Sc, Sd, Se, Sf
        {28, 351, 22, 78, 147, 65}, //150g

        // 70 - x: 1985, y: 447 org LB
        // Sa, Sb, Sc, Sd, Se, Sf
        {17, 330, 13, 57, 76, 39}, //150g

        // 71 - x: 2111, y: 447 org LB
        // Sa, Sb, Sc, Sd, Se, Sf
        {10, 270, 8, 38, 39, 22}, //150g

        // 72 - x: 2237, y: 447 org LB
        // Sa, Sb, Sc, Sd, Se, Sf
        {7, 221, 6, 31, 25, 15}, //150g

        // 73 - x: 94, y: 571 org LB
        // Sa, Sb, Sc, Sd, Se, Sf
        {227, 10, 60, 9, 37, 27}, //150g

        // 74 - x: 220, y: 571 org LB
        // Sa, Sb, Sc, Sd, Se, Sf
        {270, 14, 74, 13, 57, 38}, //150g

        // 75 - x: 346, y: 571 org LB
        // Sa, Sb, Sc, Sd, Se, Sf
        {317, 23, 97, 20, 101, 62}, //150g

        // 76 - x: 472, y: 571 org LB
        // Sa, Sb, Sc, Sd, Se, Sf
        {318, 33, 115, 28, 168, 93}, //150g

        // 77 - x: 599, y: 571 org LB
        // Sa, Sb, Sc, Sd, Se, Sf
        {265, 42, 113, 35, 246, 119}, //150g

        // 78 - x: 724, y: 571 org LB
        // Sa, Sb, Sc, Sd, Se, Sf
        {183, 44, 90, 35, 301, 123}, //150g

        // 79 - x: 851, y: 571 org LB
        // Sa, Sb, Sc, Sd, Se, Sf
        {108, 40, 60, 31, 315, 105}, //150g

        // 80 - x: 977, y: 571 org LB
        // Sa, Sb, Sc, Sd, Se, Sf
        {64, 36, 39, 26, 313, 86}, //150g

        // 81 - x: 1103, y: 571 org LB
        // Sa, Sb, Sc, Sd, Se, Sf
        {43, 36, 29, 26, 314, 76}, //150g

        // 82 - x: 1229, y: 571 org LB
        // Sa, Sb, Sc, Sd, Se, Sf
        {37, 46, 26, 30, 321, 79}, //150g

        // 83 - x: 1355, y: 571 org LB
        // Sa, Sb, Sc, Sd, Se, Sf
        {37, 70, 28, 43, 323, 91}, //150g

        // 84 - x: 1481, y: 571 org LB
        // Sa, Sb, Sc, Sd, Se, Sf
        {42, 120, 33, 66, 328, 113}, //150g

        // 85 - x: 1607, y: 571 org LB
        // Sa, Sb, Sc, Sd, Se, Sf
        {46, 201, 37, 98, 309, 129}, //150g

        // 86 - x: 1733, y: 571 org LB
        // Sa, Sb, Sc, Sd, Se, Sf
        {43, 284, 35, 119, 245, 121}, //150g

        // 87 - x: 1859, y: 571 org LB
        // Sa, Sb, Sc, Sd, Se, Sf
        {32, 324, 27, 115, 161, 91}, //150g

        // 88 - x: 1985, y: 571 org LB
        // Sa, Sb, Sc, Sd, Se, Sf
        {22, 312, 19, 94, 94, 59}, //150g

        // 89 - x: 2111, y: 571 org LB
        // Sa, Sb, Sc, Sd, Se, Sf
        {14, 262, 12, 71, 53, 36}, //150g

        // 90 - x: 2237, y: 571 org LB
        // Sa, Sb, Sc, Sd, Se, Sf
        {10, 216, 9, 57, 35, 25}, //150g

        // 91 - x: 94, y: 694 org LB
        // Sa, Sb, Sc, Sd, Se, Sf
        {204, 13, 105, 13, 46, 39}, //150g

        // 92 - x: 220, y: 694 org LB
        // Sa, Sb, Sc, Sd, Se, Sf
        {239, 18, 125, 17, 69, 56}, //150g

        // 93 - x: 346, y: 694 org LB
        // Sa, Sb, Sc, Sd, Se, Sf
        {279, 27, 153, 25, 112, 87}, //150g

        // 94 - x: 472, y: 694 org LB
        // Sa, Sb, Sc, Sd, Se, Sf
        {280, 37, 167, 34, 171, 126}, //150g

        // 95 - x: 599, y: 694 org LB
        // Sa, Sb, Sc, Sd, Se, Sf
        {241, 45, 156, 41, 235, 161}, //150g

        // 96 - x: 724, y: 694 org LB
        // Sa, Sb, Sc, Sd, Se, Sf
        {176, 48, 122, 43, 277, 174}, //150g

        // 97 - x: 851, y: 694 org LB
        // Sa, Sb, Sc, Sd, Se, Sf
        {118, 47, 88, 41, 299, 170}, //150g

        // 98 - x: 977, y: 694 org LB
        // Sa, Sb, Sc, Sd, Se, Sf
        {79, 46, 62, 39, 303, 157}, //150g

        // 99 - x: 1103, y: 694 org LB
        // Sa, Sb, Sc, Sd, Se, Sf
        {57, 49, 47, 41, 302, 148}, //150g

        // 100 - x: 1229, y: 694 org LB
        // Sa, Sb, Sc, Sd, Se, Sf
        {49, 60, 41, 48, 305, 150}, //150g

        // 101 - x: 1355, y: 694 org LB
        // Sa, Sb, Sc, Sd, Se, Sf
        {47, 84, 40, 65, 308, 161}, //150g

        // 102 - x: 1481, y: 694 org LB
        // Sa, Sb, Sc, Sd, Se, Sf
        {49, 129, 43, 95, 307, 177}, //150g

        // 103 - x: 1607, y: 694 org LB
        // Sa, Sb, Sc, Sd, Se, Sf
        {51, 194, 45, 134, 289, 183}, //150g

        // 104 - x: 1733, y: 694 org LB
        // Sa, Sb, Sc, Sd, Se, Sf
        {46, 256, 42, 164, 235, 163}, //150g

        // 105 - x: 1859, y: 694 org LB
        // Sa, Sb, Sc, Sd, Se, Sf
        {36, 287, 33, 169, 166, 123}, //150g

        // 106 - x: 1985, y: 694 org LB
        // Sa, Sb, Sc, Sd, Se, Sf
        {26, 275, 24, 150, 106, 83}, //150g

        // 107 - x: 2111, y: 694 org LB
        // Sa, Sb, Sc, Sd, Se, Sf
        {17, 235, 16, 122, 65, 53}, //150g

        // 108 - x: 2237, y: 694 org LB
        // Sa, Sb, Sc, Sd, Se, Sf
        {13, 196, 12, 101, 44, 37}, //150g

        // 109 - x: 94, y: 818 org LB
        // Sa, Sb, Sc, Sd, Se, Sf
        {162, 15, 162, 15, 48, 48}, //150g

        // 110 - x: 220, y: 818 org LB
        // Sa, Sb, Sc, Sd, Se, Sf
        {188, 20, 188, 20, 69, 69}, //150g

        // 111 - x: 346, y: 818 org LB
        // Sa, Sb, Sc, Sd, Se, Sf
        {214, 27, 214, 27, 105, 105}, //150g

        // 112 - x: 472, y: 818 org LB
        // Sa, Sb, Sc, Sd, Se, Sf
        {224, 37, 224, 37, 154, 154}, //150g

        // 113 - x: 599, y: 818 org LB
        // Sa, Sb, Sc, Sd, Se, Sf
        {200, 45, 200, 45, 202, 202}, //150g

        // 114 - x: 724, y: 818 org LB
        // Sa, Sb, Sc, Sd, Se, Sf
        {156, 48, 156, 48, 233, 233}, //150g

        // 115 - x: 851, y: 818 org LB
        // Sa, Sb, Sc, Sd, Se, Sf
        {111, 48, 111, 48, 243, 243}, //150g

        // 116 - x: 977, y: 818 org LB
        // Sa, Sb, Sc, Sd, Se, Sf
        {78, 48, 78, 48, 240, 240}, //150g

        // 117 - x: 1103, y: 818 org LB
        // Sa, Sb, Sc, Sd, Se, Sf
        {60, 51, 60, 51, 237, 237}, //150g

        // 118 - x: 1229, y: 818 org LB
        // Sa, Sb, Sc, Sd, Se, Sf
        {51, 62, 51, 62, 239, 239}, //150g

        // 119 - x: 1355, y: 818 org LB
        // Sa, Sb, Sc, Sd, Se, Sf
        {49, 84, 49, 84, 247, 247}, //150g

        // 120 - x: 1481, y: 818 org LB
        // Sa, Sb, Sc, Sd, Se, Sf
        {50, 121, 50, 121, 253, 253}, //150g

        // 121 - x: 1607, y: 818 org LB
        // Sa, Sb, Sc, Sd, Se, Sf
        {50, 169, 50, 169, 242, 242}, //150g

        // 122 - x: 1733, y: 818 org LB
        // Sa, Sb, Sc, Sd, Se, Sf
        {47, 217, 47, 217, 209, 209}, //150g

        // 123 - x: 1859, y: 818 org LB
        // Sa, Sb, Sc, Sd, Se, Sf
        {37, 233, 37, 233, 154, 154}, //150g

        // 124 - x: 1985, y: 818 org LB
        // Sa, Sb, Sc, Sd, Se, Sf
        {27, 218, 27, 218, 102, 102}, //150g

        // 125 - x: 2111, y: 818 org LB
        // Sa, Sb, Sc, Sd, Se, Sf
        {19, 186, 19, 186, 66, 66}, //150g

        // 126 - x: 2237, y: 818 org LB
        // Sa, Sb, Sc, Sd, Se, Sf
        {14, 157, 14, 157, 46, 46}, //150g

        // 127 - x: 94, y: 942 org LB
        // Sa, Sb, Sc, Sd, Se, Sf
        {107, 13, 209, 14, 40, 47}, //150g

        // 128 - x: 220, y: 942 org LB
        // Sa, Sb, Sc, Sd, Se, Sf
        {124, 17, 238, 18, 56, 68}, //150g

        // 129 - x: 346, y: 942 org LB
        // Sa, Sb, Sc, Sd, Se, Sf
        {148, 24, 269, 26, 84, 108}, //150g

        // 130 - x: 472, y: 942 org LB
        // Sa, Sb, Sc, Sd, Se, Sf
        {166, 34, 280, 37, 126, 171}, //150g

        // 131 - x: 599, y: 942 org LB
        // Sa, Sb, Sc, Sd, Se, Sf
        {154, 41, 238, 45, 159, 232}, //150g

        // 132 - x: 724, y: 942 org LB
        // Sa, Sb, Sc, Sd, Se, Sf
        {122, 43, 175, 48, 173, 276}, //150g

        // 133 - x: 851, y: 942 org LB
        // Sa, Sb, Sc, Sd, Se, Sf
        {86, 41, 116, 46, 167, 293}, //150g

        // 134 - x: 977, y: 942 org LB
        // Sa, Sb, Sc, Sd, Se, Sf
        {60, 38, 77, 45, 153, 295}, //150g

        // 135 - x: 1103, y: 942 org LB
        // Sa, Sb, Sc, Sd, Se, Sf
        {45, 40, 56, 47, 144, 294}, //150g

        // 136 - x: 1229, y: 942 org LB
        // Sa, Sb, Sc, Sd, Se, Sf
        {40, 47, 47, 58, 146, 297}, //150g

        // 137 - x: 1355, y: 942 org LB
        // Sa, Sb, Sc, Sd, Se, Sf
        {40, 65, 46, 84, 160, 306}, //150g

        // 138 - x: 1481, y: 942 org LB
        // Sa, Sb, Sc, Sd, Se, Sf
        {43, 95, 49, 129, 177, 308}, //150g

        // 139 - x: 1607, y: 942 org LB
        // Sa, Sb, Sc, Sd, Se, Sf
        {45, 134, 51, 194, 184, 289}, //150g

        // 140 - x: 1733, y: 942 org LB
        // Sa, Sb, Sc, Sd, Se, Sf
        {43, 169, 48, 264, 168, 243}, //150g

        // 141 - x: 1859, y: 942 org LB
        // Sa, Sb, Sc, Sd, Se, Sf
        {34, 174, 38, 295, 127, 171}, //150g

        // 142 - x: 1985, y: 942 org LB
        // Sa, Sb, Sc, Sd, Se, Sf
        {24, 151, 26, 276, 83, 106}, //150g

        // 143 - x: 2111, y: 942 org LB
        // Sa, Sb, Sc, Sd, Se, Sf
        {17, 126, 18, 243, 55, 67}, //150g

        // 144 - x: 2237, y: 942 org LB
        // Sa, Sb, Sc, Sd, Se, Sf
        {12, 104, 13, 203, 38, 45}, //150g

        // 145 - x: 94, y: 1065 org LB
        // Sa, Sb, Sc, Sd, Se, Sf
        {61, 9, 232, 11, 27, 38}, //150g

        // 146 - x: 220, y: 1065 org LB
        // Sa, Sb, Sc, Sd, Se, Sf
        {74, 13, 272, 15, 39, 58}, //150g

        // 147 - x: 346, y: 1065 org LB
        // Sa, Sb, Sc, Sd, Se, Sf
        {93, 19, 303, 22, 60, 97}, //150g

        // 148 - x: 472, y: 1065 org LB
        // Sa, Sb, Sc, Sd, Se, Sf
        {113, 28, 312, 33, 92, 165}, //150g

        // 149 - x: 599, y: 1065 org LB
        // Sa, Sb, Sc, Sd, Se, Sf
        {113, 35, 264, 42, 119, 245}, //150g

        // 150 - x: 724, y: 1065 org LB
        // Sa, Sb, Sc, Sd, Se, Sf
        {89, 35, 179, 43, 121, 296}, //150g

        // 151 - x: 851, y: 1065 org LB
        // Sa, Sb, Sc, Sd, Se, Sf
        {59, 30, 105, 39, 103, 307}, //150g

        // 152 - x: 977, y: 1065 org LB
        // Sa, Sb, Sc, Sd, Se, Sf
        {38, 25, 62, 34, 83, 303}, //150g

        // 153 - x: 1103, y: 1065 org LB
        // Sa, Sb, Sc, Sd, Se, Sf
        {28, 25, 42, 35, 74, 305}, //150g

        // 154 - x: 1229, y: 1065 org LB
        // Sa, Sb, Sc, Sd, Se, Sf
        {25, 30, 36, 45, 76, 311}, //150g

        // 155 - x: 1355, y: 1065 org LB
        // Sa, Sb, Sc, Sd, Se, Sf
        {27, 41, 36, 68, 89, 314}, //150g

        // 156 - x: 1481, y: 1065 org LB
        // Sa, Sb, Sc, Sd, Se, Sf
        {33, 66, 42, 120, 112, 327}, //150g

        // 157 - x: 1607, y: 1065 org LB
        // Sa, Sb, Sc, Sd, Se, Sf
        {38, 99, 47, 204, 131, 314}, //150g

        // 158 - x: 1733, y: 1065 org LB
        // Sa, Sb, Sc, Sd, Se, Sf
        {37, 124, 45, 296, 126, 256}, //150g

        // 159 - x: 1859, y: 1065 org LB
        // Sa, Sb, Sc, Sd, Se, Sf
        {29, 121, 34, 342, 96, 170}, //150g

        // 160 - x: 1985, y: 1065 org LB
        // Sa, Sb, Sc, Sd, Se, Sf
        {19, 95, 22, 316, 60, 95}, //150g

        // 161 - x: 2111, y: 1065 org LB
        // Sa, Sb, Sc, Sd, Se, Sf
        {13, 74, 14, 276, 38, 56}, //150g

        // 162 - x: 2237, y: 1065 org LB
        // Sa, Sb, Sc, Sd, Se, Sf
        {9, 60, 10, 225, 26, 36}, //150g

        // 163 - x: 94, y: 1189 org LB
        // Sa, Sb, Sc, Sd, Se, Sf
        {33, 6, 237, 7, 17, 27}, //150g

        // 164 - x: 220, y: 1189 org LB
        // Sa, Sb, Sc, Sd, Se, Sf
        {41, 9, 284, 10, 24, 43}, //150g

        // 165 - x: 346, y: 1189 org LB
        // Sa, Sb, Sc, Sd, Se, Sf
        {58, 14, 325, 17, 40, 80}, //150g

        // 166 - x: 472, y: 1189 org LB
        // Sa, Sb, Sc, Sd, Se, Sf
        {77, 22, 336, 28, 66, 152}, //150g

        // 167 - x: 599, y: 1189 org LB
        // Sa, Sb, Sc, Sd, Se, Sf
        {82, 29, 278, 38, 87, 242}, //150g

        // 168 - x: 724, y: 1189 org LB
        // Sa, Sb, Sc, Sd, Se, Sf
        {63, 27, 173, 38, 82, 291}, //150g

        // 169 - x: 851, y: 1189 org LB
        // Sa, Sb, Sc, Sd, Se, Sf
        {39, 21, 90, 31, 63, 296}, //150g

        // 170 - x: 977, y: 1189 org LB
        // Sa, Sb, Sc, Sd, Se, Sf
        {23, 16, 47, 25, 46, 288}, //150g

        // 171 - x: 1103, y: 1189 org LB
        // Sa, Sb, Sc, Sd, Se, Sf
        {16, 15, 30, 25, 38, 290}, //150g

        // 172 - x: 1229, y: 1189 org LB
        // Sa, Sb, Sc, Sd, Se, Sf
        {15, 17, 25, 32, 39, 298}, //150g

        // 173 - x: 1355, y: 1189 org LB
        // Sa, Sb, Sc, Sd, Se, Sf
        {18, 26, 27, 53, 50, 305}, //150g

        // 174 - x: 1481, y: 1189 org LB
        // Sa, Sb, Sc, Sd, Se, Sf
        {23, 44, 34, 104, 69, 314}, //150g

        // 175 - x: 1607, y: 1189 org LB
        // Sa, Sb, Sc, Sd, Se, Sf
        {30, 71, 41, 201, 91, 312}, //150g

        // 176 - x: 1733, y: 1189 org LB
        // Sa, Sb, Sc, Sd, Se, Sf
        {31, 90, 41, 315, 93, 252}, //150g

        // 177 - x: 1859, y: 1189 org LB
        // Sa, Sb, Sc, Sd, Se, Sf
        {23, 82, 29, 368, 68, 154}, //150g

        // 178 - x: 1985, y: 1189 org LB
        // Sa, Sb, Sc, Sd, Se, Sf
        {14, 59, 17, 341, 40, 79}, //150g

        // 179 - x: 2111, y: 1189 org LB
        // Sa, Sb, Sc, Sd, Se, Sf
        {8, 41, 10, 284, 23, 41}, //150g

        // 180 - x: 2237, y: 1189 org LB
        // Sa, Sb, Sc, Sd, Se, Sf
        {6, 32, 7, 229, 16, 26}, //150g

        // 181 - x: 94, y: 1312 org LB
        // Sa, Sb, Sc, Sd, Se, Sf
        {19, 4, 235, 5, 11, 19}, //150g

        // 182 - x: 220, y: 1312 org LB
        // Sa, Sb, Sc, Sd, Se, Sf
        {25, 6, 288, 8, 16, 33}, //150g

        // 183 - x: 346, y: 1312 org LB
        // Sa, Sb, Sc, Sd, Se, Sf
        {38, 11, 339, 14, 29, 68}, //150g

        // 184 - x: 472, y: 1312 org LB
        // Sa, Sb, Sc, Sd, Se, Sf
        {56, 18, 350, 25, 50, 139}, //150g

        // 185 - x: 599, y: 1312 org LB
        // Sa, Sb, Sc, Sd, Se, Sf
        {61, 24, 279, 35, 65, 227}, //150g

        // 186 - x: 724, y: 1312 org LB
        // Sa, Sb, Sc, Sd, Se, Sf
        {46, 22, 165, 34, 59, 273}, //150g

        // 187 - x: 851, y: 1312 org LB
        // Sa, Sb, Sc, Sd, Se, Sf
        {27, 16, 78, 26, 42, 269}, //150g

        // 188 - x: 977, y: 1312 org LB
        // Sa, Sb, Sc, Sd, Se, Sf
        {16, 12, 38, 20, 28, 259}, //150g

        // 189 - x: 1103, y: 1312 org LB
        // Sa, Sb, Sc, Sd, Se, Sf
        {11, 10, 23, 19, 22, 258}, //150g

        // 190 - x: 1229, y: 1312 org LB
        // Sa, Sb, Sc, Sd, Se, Sf
        {10, 11, 19, 24, 23, 264}, //150g

        // 191 - x: 1355, y: 1312 org LB
        // Sa, Sb, Sc, Sd, Se, Sf
        {13, 18, 22, 44, 31, 276}, //150g

        // 192 - x: 1481, y: 1312 org LB
        // Sa, Sb, Sc, Sd, Se, Sf
        {18, 32, 29, 93, 47, 291}, //150g

        // 193 - x: 1607, y: 1312 org LB
        // Sa, Sb, Sc, Sd, Se, Sf
        {25, 53, 37, 193, 66, 294}, //150g

        // 194 - x: 1733, y: 1312 org LB
        // Sa, Sb, Sc, Sd, Se, Sf
        {26, 68, 37, 323, 71, 240}, //150g

        // 195 - x: 1859, y: 1312 org LB
        // Sa, Sb, Sc, Sd, Se, Sf
        {19, 60, 27, 390, 52, 142}, //150g

        // 196 - x: 1985, y: 1312 org LB
        // Sa, Sb, Sc, Sd, Se, Sf
        {11, 38, 14, 353, 28, 65}, //150g

        // 197 - x: 2111, y: 1312 org LB
        // Sa, Sb, Sc, Sd, Se, Sf
        {6, 24, 8, 288, 15, 31}, //150g

        // 198 - x: 2237, y: 1312 org LB
        // Sa, Sb, Sc, Sd, Se, Sf
        {4, 18, 5, 226, 10, 18}, //150g

        // 199 - x: 94, y: 1436 org LB
        // Sa, Sb, Sc, Sd, Se, Sf
        {14, 4, 240, 5, 9, 18}, //150g

        // 200 - x: 220, y: 1436 org LB
        // Sa, Sb, Sc, Sd, Se, Sf
        {19, 5, 295, 7, 13, 30}, //150g

        // 201 - x: 346, y: 1436 org LB
        // Sa, Sb, Sc, Sd, Se, Sf
        {30, 10, 348, 14, 24, 64}, //150g

        // 202 - x: 472, y: 1436 org LB
        // Sa, Sb, Sc, Sd, Se, Sf
        {45, 17, 359, 25, 42, 134}, //150g

        // 203 - x: 599, y: 1436 org LB
        // Sa, Sb, Sc, Sd, Se, Sf
        {50, 22, 279, 34, 53, 214}, //150g

        // 204 - x: 724, y: 1436 org LB
        // Sa, Sb, Sc, Sd, Se, Sf
        {37, 19, 159, 32, 46, 248}, //150g

        // 205 - x: 851, y: 1436 org LB
        // Sa, Sb, Sc, Sd, Se, Sf
        {23, 14, 76, 25, 33, 243}, //150g

        // 206 - x: 977, y: 1436 org LB
        // Sa, Sb, Sc, Sd, Se, Sf
        {14, 10, 38, 20, 23, 235}, //150g

        // 207 - x: 1103, y: 1436 org LB
        // Sa, Sb, Sc, Sd, Se, Sf
        {10, 9, 23, 19, 18, 231}, //150g

        // 208 - x: 1229, y: 1436 org LB
        // Sa, Sb, Sc, Sd, Se, Sf
        {9, 10, 19, 25, 18, 236}, //150g

        // 209 - x: 1355, y: 1436 org LB
        // Sa, Sb, Sc, Sd, Se, Sf
        {11, 15, 22, 44, 25, 248}, //150g

        // 210 - x: 1481, y: 1436 org LB
        // Sa, Sb, Sc, Sd, Se, Sf
        {16, 26, 28, 90, 37, 262}, //150g

        // 211 - x: 1607, y: 1436 org LB
        // Sa, Sb, Sc, Sd, Se, Sf
        {22, 43, 36, 189, 52, 271}, //150g

        // 212 - x: 1733, y: 1436 org LB
        // Sa, Sb, Sc, Sd, Se, Sf
        {24, 56, 37, 328, 59, 230}, //150g

        // 213 - x: 1859, y: 1436 org LB
        // Sa, Sb, Sc, Sd, Se, Sf
        {18, 49, 26, 400, 44, 137}, //150g

        // 214 - x: 1985, y: 1436 org LB
        // Sa, Sb, Sc, Sd, Se, Sf
        {10, 30, 13, 357, 23, 61}, //150g

        // 215 - x: 2111, y: 1436 org LB
        // Sa, Sb, Sc, Sd, Se, Sf
        {5, 18, 7, 290, 12, 28}, //150g

        // 216 - x: 2237, y: 1436 org LB
        // Sa, Sb, Sc, Sd, Se, Sf
        {3, 13, 5, 227, 8, 17}, //150g

        // 217 - x: 94, y: 1560 org LB
        // Sa, Sb, Sc, Sd, Se, Sf
        {16, 5, 258, 6, 10, 23}, //150g

        // 218 - x: 220, y: 1560 org LB
        // Sa, Sb, Sc, Sd, Se, Sf
        {20, 7, 311, 9, 15, 37}, //150g

        // 219 - x: 346, y: 1560 org LB
        // Sa, Sb, Sc, Sd, Se, Sf
        {31, 11, 363, 17, 25, 73}, //150g

        // 220 - x: 472, y: 1560 org LB
        // Sa, Sb, Sc, Sd, Se, Sf
        {43, 18, 364, 28, 40, 139}, //150g

        // 221 - x: 599, y: 1560 org LB
        // Sa, Sb, Sc, Sd, Se, Sf
        {45, 21, 276, 35, 48, 206}, //150g

        // 222 - x: 724, y: 1560 org LB
        // Sa, Sb, Sc, Sd, Se, Sf
        {34, 19, 159, 33, 41, 228}, //150g

        // 223 - x: 851, y: 1560 org LB
        // Sa, Sb, Sc, Sd, Se, Sf
        {22, 14, 82, 28, 30, 222}, //150g

        // 224 - x: 977, y: 1560 org LB
        // Sa, Sb, Sc, Sd, Se, Sf
        {14, 11, 44, 23, 22, 212}, //150g

        // 225 - x: 1103, y: 1560 org LB
        // Sa, Sb, Sc, Sd, Se, Sf
        {11, 10, 28, 24, 18, 208}, //150g

        // 226 - x: 1229, y: 1560 org LB
        // Sa, Sb, Sc, Sd, Se, Sf
        {10, 11, 24, 30, 19, 213}, //150g

        // 227 - x: 1355, y: 1560 org LB
        // Sa, Sb, Sc, Sd, Se, Sf
        {12, 16, 25, 50, 24, 223}, //150g

        // 228 - x: 1481, y: 1560 org LB
        // Sa, Sb, Sc, Sd, Se, Sf
        {16, 25, 30, 95, 33, 237}, //150g

        // 229 - x: 1607, y: 1560 org LB
        // Sa, Sb, Sc, Sd, Se, Sf
        {21, 39, 37, 190, 47, 251}, //150g

        // 230 - x: 1733, y: 1560 org LB
        // Sa, Sb, Sc, Sd, Se, Sf
        {24, 51, 40, 331, 54, 226}, //150g

        // 231 - x: 1859, y: 1560 org LB
        // Sa, Sb, Sc, Sd, Se, Sf
        {19, 47, 30, 417, 44, 147}, //150g

        // 232 - x: 1985, y: 1560 org LB
        // Sa, Sb, Sc, Sd, Se, Sf
        {11, 30, 16, 376, 25, 71}, //150g

        // 233 - x: 2111, y: 1560 org LB
        // Sa, Sb, Sc, Sd, Se, Sf
        {6, 19, 9, 307, 14, 35}, //150g

        // 234 - x: 2237, y: 1560 org LB
        // Sa, Sb, Sc, Sd, Se, Sf
        {4, 15, 6, 242, 10, 21}, //150g

};
#endif

#endif