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
const s16 scaler[SUPPORT_FORCE_BUTTON_NODE] = { 175, 181, 197, 188, 410, 417 };
const s16 FSR_Zone[DEF_ZONE_Y_CNT * DEF_ZONE_X_CNT * DEF_WEIGHT_CNT][SUPPORT_FORCE_BUTTON_NODE] =
{
    // W_sum Corrected Weights (Q8 fixed-point, sigma=300.0px, ref=150g)
    // usage: sum(sensor_j * 150/scaler_j * stored[i][j]) >> 8 ≈ 150
    //18x13_SP_QR005_smutual_0823_0916_260402
    //18x13_SP_QR006_smutual_0823_0916_260402
    //18x13_SP_QR018_smutual_0823_0916_260402
    //18x13_SP_QR032_smutual_0823_0916_260402
    //18x13_SP_QR043_smutual_0823_0916_260402
    //18x13_SP_QR080_smutual_0823_0916_260402
    //18x13_SP_QR085_smutual_0823_0916_260402
    //18x13_SP_QR045_smutual_0823_0916_260402

        // 1 - x: 94, y: 76 org LB
        // Sa, Sb, Sc, Sd, Se, Sf
        {280, 7, 17, 5, 25, 11}, //150g

        // 2 - x: 220, y: 76 org LB
        // Sa, Sb, Sc, Sd, Se, Sf
        {365, 11, 24, 8, 43, 17}, //150g

        // 3 - x: 346, y: 76 org LB
        // Sa, Sb, Sc, Sd, Se, Sf
        {468, 22, 39, 14, 94, 33}, //150g

        // 4 - x: 472, y: 76 org LB
        // Sa, Sb, Sc, Sd, Se, Sf
        {480, 37, 56, 23, 183, 53}, //150g

        // 5 - x: 599, y: 76 org LB
        // Sa, Sb, Sc, Sd, Se, Sf
        {335, 43, 54, 26, 249, 58}, //150g

        // 6 - x: 724, y: 76 org LB
        // Sa, Sb, Sc, Sd, Se, Sf
        {172, 36, 36, 20, 245, 44}, //150g

        // 7 - x: 851, y: 76 org LB
        // Sa, Sb, Sc, Sd, Se, Sf
        {83, 28, 22, 15, 224, 30}, //150g

        // 8 - x: 977, y: 76 org LB
        // Sa, Sb, Sc, Sd, Se, Sf
        {45, 24, 14, 11, 214, 22}, //150g

        // 9 - x: 1103, y: 76 org LB
        // Sa, Sb, Sc, Sd, Se, Sf
        {29, 24, 11, 10, 211, 19}, //150g

        // 10 - x: 1229, y: 76 org LB
        // Sa, Sb, Sc, Sd, Se, Sf
        {24, 31, 10, 12, 217, 19}, //150g

        // 11 - x: 1355, y: 76 org LB
        // Sa, Sb, Sc, Sd, Se, Sf
        {26, 52, 12, 16, 230, 25}, //150g

        // 12 - x: 1481, y: 76 org LB
        // Sa, Sb, Sc, Sd, Se, Sf
        {32, 101, 17, 26, 252, 36}, //150g

        // 13 - x: 1607, y: 76 org LB
        // Sa, Sb, Sc, Sd, Se, Sf
        {42, 215, 24, 44, 284, 53}, //150g

        // 14 - x: 1733, y: 76 org LB
        // Sa, Sb, Sc, Sd, Se, Sf
        {51, 422, 31, 66, 288, 69}, //150g

        // 15 - x: 1859, y: 76 org LB
        // Sa, Sb, Sc, Sd, Se, Sf
        {40, 564, 26, 64, 199, 59}, //150g

        // 16 - x: 1985, y: 76 org LB
        // Sa, Sb, Sc, Sd, Se, Sf
        {22, 506, 15, 41, 95, 34}, //150g

        // 17 - x: 2111, y: 76 org LB
        // Sa, Sb, Sc, Sd, Se, Sf
        {11, 362, 7, 23, 41, 17}, //150g

        // 18 - x: 2237, y: 76 org LB
        // Sa, Sb, Sc, Sd, Se, Sf
        {6, 258, 5, 16, 22, 10}, //150g

        // 19 - x: 94, y: 200 org LB
        // Sa, Sb, Sc, Sd, Se, Sf
        {246, 5, 14, 4, 18, 9}, //150g

        // 20 - x: 220, y: 200 org LB
        // Sa, Sb, Sc, Sd, Se, Sf
        {321, 8, 21, 6, 33, 14}, //150g

        // 21 - x: 346, y: 200 org LB
        // Sa, Sb, Sc, Sd, Se, Sf
        {416, 17, 36, 12, 77, 29}, //150g

        // 22 - x: 472, y: 200 org LB
        // Sa, Sb, Sc, Sd, Se, Sf
        {465, 32, 59, 22, 173, 54}, //150g

        // 23 - x: 599, y: 200 org LB
        // Sa, Sb, Sc, Sd, Se, Sf
        {336, 41, 60, 26, 258, 64}, //150g

        // 24 - x: 724, y: 200 org LB
        // Sa, Sb, Sc, Sd, Se, Sf
        {172, 35, 41, 21, 269, 50}, //150g

        // 25 - x: 851, y: 200 org LB
        // Sa, Sb, Sc, Sd, Se, Sf
        {78, 26, 23, 14, 248, 33}, //150g

        // 26 - x: 977, y: 200 org LB
        // Sa, Sb, Sc, Sd, Se, Sf
        {38, 20, 14, 10, 235, 23}, //150g

        // 27 - x: 1103, y: 200 org LB
        // Sa, Sb, Sc, Sd, Se, Sf
        {23, 19, 10, 9, 232, 18}, //150g

        // 28 - x: 1229, y: 200 org LB
        // Sa, Sb, Sc, Sd, Se, Sf
        {19, 25, 9, 10, 237, 19}, //150g

        // 29 - x: 1355, y: 200 org LB
        // Sa, Sb, Sc, Sd, Se, Sf
        {22, 44, 11, 16, 251, 25}, //150g

        // 30 - x: 1481, y: 200 org LB
        // Sa, Sb, Sc, Sd, Se, Sf
        {29, 94, 16, 27, 272, 38}, //150g

        // 31 - x: 1607, y: 200 org LB
        // Sa, Sb, Sc, Sd, Se, Sf
        {40, 209, 24, 48, 300, 58}, //150g

        // 32 - x: 1733, y: 200 org LB
        // Sa, Sb, Sc, Sd, Se, Sf
        {46, 406, 30, 69, 284, 73}, //150g

        // 33 - x: 1859, y: 200 org LB
        // Sa, Sb, Sc, Sd, Se, Sf
        {33, 508, 23, 62, 174, 56}, //150g

        // 34 - x: 1985, y: 200 org LB
        // Sa, Sb, Sc, Sd, Se, Sf
        {16, 433, 12, 36, 74, 28}, //150g

        // 35 - x: 2111, y: 200 org LB
        // Sa, Sb, Sc, Sd, Se, Sf
        {7, 303, 5, 19, 29, 13}, //150g

        // 36 - x: 2237, y: 200 org LB
        // Sa, Sb, Sc, Sd, Se, Sf
        {5, 225, 3, 13, 16, 8}, //150g

        // 37 - x: 94, y: 324 org LB
        // Sa, Sb, Sc, Sd, Se, Sf
        {231, 5, 18, 4, 19, 10}, //150g

        // 38 - x: 220, y: 324 org LB
        // Sa, Sb, Sc, Sd, Se, Sf
        {305, 8, 26, 6, 34, 17}, //150g

        // 39 - x: 346, y: 324 org LB
        // Sa, Sb, Sc, Sd, Se, Sf
        {388, 17, 44, 12, 78, 33}, //150g

        // 40 - x: 472, y: 324 org LB
        // Sa, Sb, Sc, Sd, Se, Sf
        {434, 31, 69, 23, 172, 62}, //150g

        // 41 - x: 599, y: 324 org LB
        // Sa, Sb, Sc, Sd, Se, Sf
        {333, 41, 73, 29, 271, 77}, //150g

        // 42 - x: 724, y: 324 org LB
        // Sa, Sb, Sc, Sd, Se, Sf
        {180, 37, 51, 24, 298, 65}, //150g

        // 43 - x: 851, y: 324 org LB
        // Sa, Sb, Sc, Sd, Se, Sf
        {81, 27, 28, 17, 277, 43}, //150g

        // 44 - x: 977, y: 324 org LB
        // Sa, Sb, Sc, Sd, Se, Sf
        {39, 20, 16, 12, 262, 29}, //150g

        // 45 - x: 1103, y: 324 org LB
        // Sa, Sb, Sc, Sd, Se, Sf
        {23, 19, 11, 10, 259, 22}, //150g

        // 46 - x: 1229, y: 324 org LB
        // Sa, Sb, Sc, Sd, Se, Sf
        {19, 24, 10, 11, 263, 23}, //150g

        // 47 - x: 1355, y: 324 org LB
        // Sa, Sb, Sc, Sd, Se, Sf
        {22, 44, 13, 18, 276, 31}, //150g

        // 48 - x: 1481, y: 324 org LB
        // Sa, Sb, Sc, Sd, Se, Sf
        {30, 95, 19, 33, 298, 48}, //150g

        // 49 - x: 1607, y: 324 org LB
        // Sa, Sb, Sc, Sd, Se, Sf
        {41, 212, 27, 58, 323, 72}, //150g

        // 50 - x: 1733, y: 324 org LB
        // Sa, Sb, Sc, Sd, Se, Sf
        {44, 381, 31, 80, 283, 83}, //150g

        // 51 - x: 1859, y: 324 org LB
        // Sa, Sb, Sc, Sd, Se, Sf
        {32, 465, 23, 71, 170, 62}, //150g

        // 52 - x: 1985, y: 324 org LB
        // Sa, Sb, Sc, Sd, Se, Sf
        {16, 399, 12, 43, 74, 32}, //150g

        // 53 - x: 2111, y: 324 org LB
        // Sa, Sb, Sc, Sd, Se, Sf
        {8, 291, 6, 24, 31, 15}, //150g

        // 54 - x: 2237, y: 324 org LB
        // Sa, Sb, Sc, Sd, Se, Sf
        {5, 215, 4, 17, 17, 10}, //150g

        // 55 - x: 94, y: 447 org LB
        // Sa, Sb, Sc, Sd, Se, Sf
        {234, 7, 32, 6, 26, 16}, //150g

        // 56 - x: 220, y: 447 org LB
        // Sa, Sb, Sc, Sd, Se, Sf
        {299, 11, 43, 9, 45, 26}, //150g

        // 57 - x: 346, y: 447 org LB
        // Sa, Sb, Sc, Sd, Se, Sf
        {379, 20, 67, 16, 94, 47}, //150g

        // 58 - x: 472, y: 447 org LB
        // Sa, Sb, Sc, Sd, Se, Sf
        {405, 34, 93, 27, 183, 79}, //150g

        // 59 - x: 599, y: 447 org LB
        // Sa, Sb, Sc, Sd, Se, Sf
        {322, 44, 95, 33, 281, 100}, //150g

        // 60 - x: 724, y: 447 org LB
        // Sa, Sb, Sc, Sd, Se, Sf
        {189, 41, 68, 30, 318, 90}, //150g

        // 61 - x: 851, y: 447 org LB
        // Sa, Sb, Sc, Sd, Se, Sf
        {94, 32, 40, 22, 308, 65}, //150g

        // 62 - x: 977, y: 447 org LB
        // Sa, Sb, Sc, Sd, Se, Sf
        {48, 26, 24, 17, 293, 46}, //150g

        // 63 - x: 1103, y: 447 org LB
        // Sa, Sb, Sc, Sd, Se, Sf
        {30, 25, 17, 15, 291, 38}, //150g

        // 64 - x: 1229, y: 447 org LB
        // Sa, Sb, Sc, Sd, Se, Sf
        {25, 32, 15, 17, 296, 39}, //150g

        // 65 - x: 1355, y: 447 org LB
        // Sa, Sb, Sc, Sd, Se, Sf
        {27, 53, 18, 26, 303, 50}, //150g

        // 66 - x: 1481, y: 447 org LB
        // Sa, Sb, Sc, Sd, Se, Sf
        {35, 108, 24, 46, 326, 72}, //150g

        // 67 - x: 1607, y: 447 org LB
        // Sa, Sb, Sc, Sd, Se, Sf
        {45, 217, 33, 77, 338, 98}, //150g

        // 68 - x: 1733, y: 447 org LB
        // Sa, Sb, Sc, Sd, Se, Sf
        {47, 365, 36, 104, 292, 107}, //150g

        // 69 - x: 1859, y: 447 org LB
        // Sa, Sb, Sc, Sd, Se, Sf
        {35, 433, 27, 96, 181, 80}, //150g

        // 70 - x: 1985, y: 447 org LB
        // Sa, Sb, Sc, Sd, Se, Sf
        {19, 373, 15, 64, 86, 44}, //150g

        // 71 - x: 2111, y: 447 org LB
        // Sa, Sb, Sc, Sd, Se, Sf
        {10, 282, 8, 40, 41, 23}, //150g

        // 72 - x: 2237, y: 447 org LB
        // Sa, Sb, Sc, Sd, Se, Sf
        {7, 217, 6, 30, 24, 15}, //150g

        // 73 - x: 94, y: 571 org LB
        // Sa, Sb, Sc, Sd, Se, Sf
        {234, 11, 62, 9, 38, 28}, //150g

        // 74 - x: 220, y: 571 org LB
        // Sa, Sb, Sc, Sd, Se, Sf
        {290, 16, 79, 14, 61, 41}, //150g

        // 75 - x: 346, y: 571 org LB
        // Sa, Sb, Sc, Sd, Se, Sf
        {359, 26, 110, 22, 114, 71}, //150g

        // 76 - x: 472, y: 571 org LB
        // Sa, Sb, Sc, Sd, Se, Sf
        {375, 39, 136, 33, 198, 110}, //150g

        // 77 - x: 599, y: 571 org LB
        // Sa, Sb, Sc, Sd, Se, Sf
        {308, 49, 131, 40, 286, 138}, //150g

        // 78 - x: 724, y: 571 org LB
        // Sa, Sb, Sc, Sd, Se, Sf
        {200, 48, 99, 39, 330, 135}, //150g

        // 79 - x: 851, y: 571 org LB
        // Sa, Sb, Sc, Sd, Se, Sf
        {112, 41, 62, 32, 327, 109}, //150g

        // 80 - x: 977, y: 571 org LB
        // Sa, Sb, Sc, Sd, Se, Sf
        {64, 36, 40, 27, 315, 87}, //150g

        // 81 - x: 1103, y: 571 org LB
        // Sa, Sb, Sc, Sd, Se, Sf
        {43, 36, 29, 25, 311, 76}, //150g

        // 82 - x: 1229, y: 571 org LB
        // Sa, Sb, Sc, Sd, Se, Sf
        {36, 46, 26, 30, 318, 78}, //150g

        // 83 - x: 1355, y: 571 org LB
        // Sa, Sb, Sc, Sd, Se, Sf
        {37, 71, 28, 43, 326, 92}, //150g

        // 84 - x: 1481, y: 571 org LB
        // Sa, Sb, Sc, Sd, Se, Sf
        {44, 127, 34, 70, 346, 119}, //150g

        // 85 - x: 1607, y: 571 org LB
        // Sa, Sb, Sc, Sd, Se, Sf
        {52, 227, 42, 110, 349, 146}, //150g

        // 86 - x: 1733, y: 571 org LB
        // Sa, Sb, Sc, Sd, Se, Sf
        {52, 343, 43, 144, 296, 146}, //150g

        // 87 - x: 1859, y: 571 org LB
        // Sa, Sb, Sc, Sd, Se, Sf
        {39, 395, 33, 140, 196, 110}, //150g

        // 88 - x: 1985, y: 571 org LB
        // Sa, Sb, Sc, Sd, Se, Sf
        {25, 358, 21, 108, 108, 67}, //150g

        // 89 - x: 2111, y: 571 org LB
        // Sa, Sb, Sc, Sd, Se, Sf
        {15, 283, 13, 76, 58, 39}, //150g

        // 90 - x: 2237, y: 571 org LB
        // Sa, Sb, Sc, Sd, Se, Sf
        {10, 219, 9, 58, 35, 25}, //150g

        // 91 - x: 94, y: 694 org LB
        // Sa, Sb, Sc, Sd, Se, Sf
        {217, 14, 112, 14, 49, 42}, //150g

        // 92 - x: 220, y: 694 org LB
        // Sa, Sb, Sc, Sd, Se, Sf
        {264, 20, 138, 19, 76, 62}, //150g

        // 93 - x: 346, y: 694 org LB
        // Sa, Sb, Sc, Sd, Se, Sf
        {320, 31, 176, 29, 128, 100}, //150g

        // 94 - x: 472, y: 694 org LB
        // Sa, Sb, Sc, Sd, Se, Sf
        {331, 44, 197, 40, 202, 149}, //150g

        // 95 - x: 599, y: 694 org LB
        // Sa, Sb, Sc, Sd, Se, Sf
        {281, 53, 181, 48, 274, 188}, //150g

        // 96 - x: 724, y: 694 org LB
        // Sa, Sb, Sc, Sd, Se, Sf
        {194, 53, 135, 47, 305, 192}, //150g

        // 97 - x: 851, y: 694 org LB
        // Sa, Sb, Sc, Sd, Se, Sf
        {125, 50, 92, 44, 315, 179}, //150g

        // 98 - x: 977, y: 694 org LB
        // Sa, Sb, Sc, Sd, Se, Sf
        {81, 47, 63, 40, 309, 160}, //150g

        // 99 - x: 1103, y: 694 org LB
        // Sa, Sb, Sc, Sd, Se, Sf
        {58, 49, 47, 41, 304, 149}, //150g

        // 100 - x: 1229, y: 694 org LB
        // Sa, Sb, Sc, Sd, Se, Sf
        {49, 60, 41, 49, 308, 151}, //150g

        // 101 - x: 1355, y: 694 org LB
        // Sa, Sb, Sc, Sd, Se, Sf
        {48, 87, 41, 67, 317, 166}, //150g

        // 102 - x: 1481, y: 694 org LB
        // Sa, Sb, Sc, Sd, Se, Sf
        {53, 138, 46, 102, 330, 190}, //150g

        // 103 - x: 1607, y: 694 org LB
        // Sa, Sb, Sc, Sd, Se, Sf
        {58, 223, 52, 154, 331, 210}, //150g

        // 104 - x: 1733, y: 694 org LB
        // Sa, Sb, Sc, Sd, Se, Sf
        {56, 311, 51, 199, 286, 198}, //150g

        // 105 - x: 1859, y: 694 org LB
        // Sa, Sb, Sc, Sd, Se, Sf
        {44, 349, 41, 206, 202, 150}, //150g

        // 106 - x: 1985, y: 694 org LB
        // Sa, Sb, Sc, Sd, Se, Sf
        {30, 324, 28, 177, 124, 98}, //150g

        // 107 - x: 2111, y: 694 org LB
        // Sa, Sb, Sc, Sd, Se, Sf
        {20, 262, 18, 136, 73, 60}, //150g

        // 108 - x: 2237, y: 694 org LB
        // Sa, Sb, Sc, Sd, Se, Sf
        {14, 207, 13, 107, 46, 39}, //150g

        // 109 - x: 94, y: 818 org LB
        // Sa, Sb, Sc, Sd, Se, Sf
        {176, 16, 176, 16, 53, 53}, //150g

        // 110 - x: 220, y: 818 org LB
        // Sa, Sb, Sc, Sd, Se, Sf
        {211, 22, 211, 22, 78, 78}, //150g

        // 111 - x: 346, y: 818 org LB
        // Sa, Sb, Sc, Sd, Se, Sf
        {249, 32, 249, 32, 122, 122}, //150g

        // 112 - x: 472, y: 818 org LB
        // Sa, Sb, Sc, Sd, Se, Sf
        {265, 44, 265, 44, 182, 182}, //150g

        // 113 - x: 599, y: 818 org LB
        // Sa, Sb, Sc, Sd, Se, Sf
        {234, 52, 234, 52, 236, 236}, //150g

        // 114 - x: 724, y: 818 org LB
        // Sa, Sb, Sc, Sd, Se, Sf
        {174, 54, 174, 54, 260, 260}, //150g

        // 115 - x: 851, y: 818 org LB
        // Sa, Sb, Sc, Sd, Se, Sf
        {118, 51, 118, 51, 259, 259}, //150g

        // 116 - x: 977, y: 818 org LB
        // Sa, Sb, Sc, Sd, Se, Sf
        {81, 49, 81, 49, 248, 248}, //150g

        // 117 - x: 1103, y: 818 org LB
        // Sa, Sb, Sc, Sd, Se, Sf
        {61, 52, 61, 52, 242, 242}, //150g

        // 118 - x: 1229, y: 818 org LB
        // Sa, Sb, Sc, Sd, Se, Sf
        {52, 63, 52, 63, 245, 245}, //150g

        // 119 - x: 1355, y: 818 org LB
        // Sa, Sb, Sc, Sd, Se, Sf
        {51, 88, 51, 88, 258, 258}, //150g

        // 120 - x: 1481, y: 818 org LB
        // Sa, Sb, Sc, Sd, Se, Sf
        {54, 131, 54, 131, 275, 275}, //150g

        // 121 - x: 1607, y: 818 org LB
        // Sa, Sb, Sc, Sd, Se, Sf
        {58, 196, 58, 196, 280, 280}, //150g

        // 122 - x: 1733, y: 818 org LB
        // Sa, Sb, Sc, Sd, Se, Sf
        {57, 265, 57, 265, 255, 255}, //150g

        // 123 - x: 1859, y: 818 org LB
        // Sa, Sb, Sc, Sd, Se, Sf
        {46, 284, 46, 284, 187, 187}, //150g

        // 124 - x: 1985, y: 818 org LB
        // Sa, Sb, Sc, Sd, Se, Sf
        {32, 260, 32, 260, 122, 122}, //150g

        // 125 - x: 2111, y: 818 org LB
        // Sa, Sb, Sc, Sd, Se, Sf
        {22, 212, 22, 212, 76, 76}, //150g

        // 126 - x: 2237, y: 818 org LB
        // Sa, Sb, Sc, Sd, Se, Sf
        {15, 171, 15, 171, 50, 50}, //150g

        // 127 - x: 94, y: 942 org LB
        // Sa, Sb, Sc, Sd, Se, Sf
        {116, 14, 225, 15, 43, 51}, //150g

        // 128 - x: 220, y: 942 org LB
        // Sa, Sb, Sc, Sd, Se, Sf
        {138, 19, 264, 20, 62, 76}, //150g

        // 129 - x: 346, y: 942 org LB
        // Sa, Sb, Sc, Sd, Se, Sf
        {173, 28, 314, 30, 98, 126}, //150g

        // 130 - x: 472, y: 942 org LB
        // Sa, Sb, Sc, Sd, Se, Sf
        {197, 40, 332, 44, 149, 203}, //150g

        // 131 - x: 599, y: 942 org LB
        // Sa, Sb, Sc, Sd, Se, Sf
        {180, 47, 278, 52, 186, 271}, //150g

        // 132 - x: 724, y: 942 org LB
        // Sa, Sb, Sc, Sd, Se, Sf
        {136, 47, 195, 53, 193, 307}, //150g

        // 133 - x: 851, y: 942 org LB
        // Sa, Sb, Sc, Sd, Se, Sf
        {92, 43, 124, 49, 178, 313}, //150g

        // 134 - x: 977, y: 942 org LB
        // Sa, Sb, Sc, Sd, Se, Sf
        {62, 40, 79, 46, 158, 304}, //150g

        // 135 - x: 1103, y: 942 org LB
        // Sa, Sb, Sc, Sd, Se, Sf
        {46, 40, 57, 48, 147, 300}, //150g

        // 136 - x: 1229, y: 942 org LB
        // Sa, Sb, Sc, Sd, Se, Sf
        {40, 48, 48, 60, 149, 304}, //150g

        // 137 - x: 1355, y: 942 org LB
        // Sa, Sb, Sc, Sd, Se, Sf
        {42, 68, 48, 87, 167, 319}, //150g

        // 138 - x: 1481, y: 942 org LB
        // Sa, Sb, Sc, Sd, Se, Sf
        {47, 103, 53, 140, 193, 335}, //150g

        // 139 - x: 1607, y: 942 org LB
        // Sa, Sb, Sc, Sd, Se, Sf
        {52, 154, 58, 224, 212, 333}, //150g

        // 140 - x: 1733, y: 942 org LB
        // Sa, Sb, Sc, Sd, Se, Sf
        {53, 207, 58, 323, 206, 297}, //150g

        // 141 - x: 1859, y: 942 org LB
        // Sa, Sb, Sc, Sd, Se, Sf
        {42, 212, 46, 360, 155, 209}, //150g

        // 142 - x: 1985, y: 942 org LB
        // Sa, Sb, Sc, Sd, Se, Sf
        {29, 179, 31, 328, 99, 126}, //150g

        // 143 - x: 2111, y: 942 org LB
        // Sa, Sb, Sc, Sd, Se, Sf
        {19, 142, 20, 275, 62, 76}, //150g

        // 144 - x: 2237, y: 942 org LB
        // Sa, Sb, Sc, Sd, Se, Sf
        {13, 113, 14, 219, 41, 49}, //150g

        // 145 - x: 94, y: 1065 org LB
        // Sa, Sb, Sc, Sd, Se, Sf
        {64, 10, 242, 11, 29, 40}, //150g

        // 146 - x: 220, y: 1065 org LB
        // Sa, Sb, Sc, Sd, Se, Sf
        {81, 14, 296, 16, 42, 63}, //150g

        // 147 - x: 346, y: 1065 org LB
        // Sa, Sb, Sc, Sd, Se, Sf
        {107, 21, 347, 25, 68, 111}, //150g

        // 148 - x: 472, y: 1065 org LB
        // Sa, Sb, Sc, Sd, Se, Sf
        {134, 33, 370, 39, 109, 196}, //150g

        // 149 - x: 599, y: 1065 org LB
        // Sa, Sb, Sc, Sd, Se, Sf
        {132, 40, 308, 49, 138, 286}, //150g

        // 150 - x: 724, y: 1065 org LB
        // Sa, Sb, Sc, Sd, Se, Sf
        {98, 39, 199, 48, 134, 328}, //150g

        // 151 - x: 851, y: 1065 org LB
        // Sa, Sb, Sc, Sd, Se, Sf
        {62, 31, 110, 41, 108, 323}, //150g

        // 152 - x: 977, y: 1065 org LB
        // Sa, Sb, Sc, Sd, Se, Sf
        {39, 26, 63, 35, 85, 309}, //150g

        // 153 - x: 1103, y: 1065 org LB
        // Sa, Sb, Sc, Sd, Se, Sf
        {28, 25, 43, 36, 75, 308}, //150g

        // 154 - x: 1229, y: 1065 org LB
        // Sa, Sb, Sc, Sd, Se, Sf
        {26, 30, 36, 45, 77, 314}, //150g

        // 155 - x: 1355, y: 1065 org LB
        // Sa, Sb, Sc, Sd, Se, Sf
        {28, 43, 37, 70, 91, 323}, //150g

        // 156 - x: 1481, y: 1065 org LB
        // Sa, Sb, Sc, Sd, Se, Sf
        {35, 71, 45, 128, 120, 350}, //150g

        // 157 - x: 1607, y: 1065 org LB
        // Sa, Sb, Sc, Sd, Se, Sf
        {43, 113, 54, 233, 150, 359}, //150g

        // 158 - x: 1733, y: 1065 org LB
        // Sa, Sb, Sc, Sd, Se, Sf
        {45, 151, 54, 360, 153, 311}, //150g

        // 159 - x: 1859, y: 1065 org LB
        // Sa, Sb, Sc, Sd, Se, Sf
        {36, 151, 42, 425, 119, 211}, //150g

        // 160 - x: 1985, y: 1065 org LB
        // Sa, Sb, Sc, Sd, Se, Sf
        {22, 111, 25, 367, 69, 111}, //150g

        // 161 - x: 2111, y: 1065 org LB
        // Sa, Sb, Sc, Sd, Se, Sf
        {14, 82, 16, 302, 42, 62}, //150g

        // 162 - x: 2237, y: 1065 org LB
        // Sa, Sb, Sc, Sd, Se, Sf
        {9, 62, 11, 235, 27, 38}, //150g

        // 163 - x: 94, y: 1189 org LB
        // Sa, Sb, Sc, Sd, Se, Sf
        {33, 6, 239, 7, 17, 27}, //150g

        // 164 - x: 220, y: 1189 org LB
        // Sa, Sb, Sc, Sd, Se, Sf
        {44, 9, 300, 11, 26, 45}, //150g

        // 165 - x: 346, y: 1189 org LB
        // Sa, Sb, Sc, Sd, Se, Sf
        {65, 16, 367, 20, 46, 91}, //150g

        // 166 - x: 472, y: 1189 org LB
        // Sa, Sb, Sc, Sd, Se, Sf
        {92, 26, 400, 34, 78, 181}, //150g

        // 167 - x: 599, y: 1189 org LB
        // Sa, Sb, Sc, Sd, Se, Sf
        {96, 33, 325, 44, 101, 283}, //150g

        // 168 - x: 724, y: 1189 org LB
        // Sa, Sb, Sc, Sd, Se, Sf
        {69, 30, 190, 42, 91, 321}, //150g

        // 169 - x: 851, y: 1189 org LB
        // Sa, Sb, Sc, Sd, Se, Sf
        {40, 22, 93, 32, 65, 308}, //150g

        // 170 - x: 977, y: 1189 org LB
        // Sa, Sb, Sc, Sd, Se, Sf
        {24, 17, 48, 26, 46, 292}, //150g

        // 171 - x: 1103, y: 1189 org LB
        // Sa, Sb, Sc, Sd, Se, Sf
        {16, 15, 30, 25, 38, 290}, //150g

        // 172 - x: 1229, y: 1189 org LB
        // Sa, Sb, Sc, Sd, Se, Sf
        {15, 17, 25, 32, 39, 298}, //150g

        // 173 - x: 1355, y: 1189 org LB
        // Sa, Sb, Sc, Sd, Se, Sf
        {18, 27, 28, 54, 51, 309}, //150g

        // 174 - x: 1481, y: 1189 org LB
        // Sa, Sb, Sc, Sd, Se, Sf
        {25, 46, 36, 109, 73, 332}, //150g

        // 175 - x: 1607, y: 1189 org LB
        // Sa, Sb, Sc, Sd, Se, Sf
        {34, 81, 47, 227, 103, 354}, //150g

        // 176 - x: 1733, y: 1189 org LB
        // Sa, Sb, Sc, Sd, Se, Sf
        {37, 110, 49, 384, 113, 307}, //150g

        // 177 - x: 1859, y: 1189 org LB
        // Sa, Sb, Sc, Sd, Se, Sf
        {28, 101, 36, 453, 84, 190}, //150g

        // 178 - x: 1985, y: 1189 org LB
        // Sa, Sb, Sc, Sd, Se, Sf
        {16, 67, 20, 390, 46, 90}, //150g

        // 179 - x: 2111, y: 1189 org LB
        // Sa, Sb, Sc, Sd, Se, Sf
        {9, 43, 11, 300, 25, 43}, //150g

        // 180 - x: 2237, y: 1189 org LB
        // Sa, Sb, Sc, Sd, Se, Sf
        {6, 32, 7, 231, 16, 26}, //150g

        // 181 - x: 94, y: 1312 org LB
        // Sa, Sb, Sc, Sd, Se, Sf
        {18, 4, 233, 5, 11, 19}, //150g

        // 182 - x: 220, y: 1312 org LB
        // Sa, Sb, Sc, Sd, Se, Sf
        {26, 6, 300, 8, 17, 34}, //150g

        // 183 - x: 346, y: 1312 org LB
        // Sa, Sb, Sc, Sd, Se, Sf
        {43, 12, 381, 16, 33, 76}, //150g

        // 184 - x: 472, y: 1312 org LB
        // Sa, Sb, Sc, Sd, Se, Sf
        {67, 22, 418, 30, 59, 166}, //150g

        // 185 - x: 599, y: 1312 org LB
        // Sa, Sb, Sc, Sd, Se, Sf
        {72, 28, 329, 41, 76, 267}, //150g

        // 186 - x: 724, y: 1312 org LB
        // Sa, Sb, Sc, Sd, Se, Sf
        {51, 24, 181, 37, 65, 300}, //150g

        // 187 - x: 851, y: 1312 org LB
        // Sa, Sb, Sc, Sd, Se, Sf
        {29, 17, 82, 27, 43, 279}, //150g

        // 188 - x: 977, y: 1312 org LB
        // Sa, Sb, Sc, Sd, Se, Sf
        {16, 12, 39, 20, 29, 262}, //150g

        // 189 - x: 1103, y: 1312 org LB
        // Sa, Sb, Sc, Sd, Se, Sf
        {11, 10, 23, 19, 22, 258}, //150g

        // 190 - x: 1229, y: 1312 org LB
        // Sa, Sb, Sc, Sd, Se, Sf
        {10, 11, 19, 24, 23, 264}, //150g

        // 191 - x: 1355, y: 1312 org LB
        // Sa, Sb, Sc, Sd, Se, Sf
        {13, 18, 22, 45, 32, 280}, //150g

        // 192 - x: 1481, y: 1312 org LB
        // Sa, Sb, Sc, Sd, Se, Sf
        {19, 34, 31, 98, 50, 307}, //150g

        // 193 - x: 1607, y: 1312 org LB
        // Sa, Sb, Sc, Sd, Se, Sf
        {28, 60, 42, 218, 75, 332}, //150g

        // 194 - x: 1733, y: 1312 org LB
        // Sa, Sb, Sc, Sd, Se, Sf
        {32, 84, 46, 399, 87, 296}, //150g

        // 195 - x: 1859, y: 1312 org LB
        // Sa, Sb, Sc, Sd, Se, Sf
        {24, 74, 33, 485, 65, 177}, //150g

        // 196 - x: 1985, y: 1312 org LB
        // Sa, Sb, Sc, Sd, Se, Sf
        {12, 44, 16, 400, 32, 74}, //150g

        // 197 - x: 2111, y: 1312 org LB
        // Sa, Sb, Sc, Sd, Se, Sf
        {6, 25, 8, 299, 16, 32}, //150g

        // 198 - x: 2237, y: 1312 org LB
        // Sa, Sb, Sc, Sd, Se, Sf
        {4, 18, 5, 222, 10, 18}, //150g

        // 199 - x: 94, y: 1436 org LB
        // Sa, Sb, Sc, Sd, Se, Sf
        {14, 4, 237, 5, 9, 18}, //150g

        // 200 - x: 220, y: 1436 org LB
        // Sa, Sb, Sc, Sd, Se, Sf
        {20, 6, 308, 8, 14, 31}, //150g

        // 201 - x: 346, y: 1436 org LB
        // Sa, Sb, Sc, Sd, Se, Sf
        {34, 11, 393, 16, 27, 73}, //150g

        // 202 - x: 472, y: 1436 org LB
        // Sa, Sb, Sc, Sd, Se, Sf
        {55, 20, 433, 30, 50, 161}, //150g

        // 203 - x: 599, y: 1436 org LB
        // Sa, Sb, Sc, Sd, Se, Sf
        {59, 26, 333, 40, 63, 256}, //150g

        // 204 - x: 724, y: 1436 org LB
        // Sa, Sb, Sc, Sd, Se, Sf
        {42, 21, 176, 35, 51, 275}, //150g

        // 205 - x: 851, y: 1436 org LB
        // Sa, Sb, Sc, Sd, Se, Sf
        {24, 15, 80, 26, 34, 255}, //150g

        // 206 - x: 977, y: 1436 org LB
        // Sa, Sb, Sc, Sd, Se, Sf
        {14, 11, 39, 21, 23, 240}, //150g

        // 207 - x: 1103, y: 1436 org LB
        // Sa, Sb, Sc, Sd, Se, Sf
        {10, 9, 23, 19, 18, 233}, //150g

        // 208 - x: 1229, y: 1436 org LB
        // Sa, Sb, Sc, Sd, Se, Sf
        {9, 10, 19, 25, 19, 238}, //150g

        // 209 - x: 1355, y: 1436 org LB
        // Sa, Sb, Sc, Sd, Se, Sf
        {12, 16, 22, 45, 26, 255}, //150g

        // 210 - x: 1481, y: 1436 org LB
        // Sa, Sb, Sc, Sd, Se, Sf
        {17, 28, 30, 96, 39, 278}, //150g

        // 211 - x: 1607, y: 1436 org LB
        // Sa, Sb, Sc, Sd, Se, Sf
        {25, 49, 41, 216, 60, 310}, //150g

        // 212 - x: 1733, y: 1436 org LB
        // Sa, Sb, Sc, Sd, Se, Sf
        {30, 71, 47, 414, 74, 290}, //150g

        // 213 - x: 1859, y: 1436 org LB
        // Sa, Sb, Sc, Sd, Se, Sf
        {22, 61, 33, 503, 55, 172}, //150g

        // 214 - x: 1985, y: 1436 org LB
        // Sa, Sb, Sc, Sd, Se, Sf
        {11, 34, 15, 403, 26, 69}, //150g

        // 215 - x: 2111, y: 1436 org LB
        // Sa, Sb, Sc, Sd, Se, Sf
        {5, 19, 7, 299, 13, 29}, //150g

        // 216 - x: 2237, y: 1436 org LB
        // Sa, Sb, Sc, Sd, Se, Sf
        {3, 13, 4, 221, 8, 16}, //150g

        // 217 - x: 94, y: 1560 org LB
        // Sa, Sb, Sc, Sd, Se, Sf
        {16, 5, 260, 6, 11, 23}, //150g

        // 218 - x: 220, y: 1560 org LB
        // Sa, Sb, Sc, Sd, Se, Sf
        {21, 7, 331, 10, 16, 39}, //150g

        // 219 - x: 346, y: 1560 org LB
        // Sa, Sb, Sc, Sd, Se, Sf
        {35, 13, 420, 19, 29, 85}, //150g

        // 220 - x: 472, y: 1560 org LB
        // Sa, Sb, Sc, Sd, Se, Sf
        {53, 22, 448, 34, 49, 171}, //150g

        // 221 - x: 599, y: 1560 org LB
        // Sa, Sb, Sc, Sd, Se, Sf
        {54, 26, 336, 43, 58, 250}, //150g

        // 222 - x: 724, y: 1560 org LB
        // Sa, Sb, Sc, Sd, Se, Sf
        {38, 21, 180, 38, 46, 257}, //150g

        // 223 - x: 851, y: 1560 org LB
        // Sa, Sb, Sc, Sd, Se, Sf
        {23, 15, 88, 29, 32, 237}, //150g

        // 224 - x: 977, y: 1560 org LB
        // Sa, Sb, Sc, Sd, Se, Sf
        {15, 12, 46, 24, 23, 220}, //150g

        // 225 - x: 1103, y: 1560 org LB
        // Sa, Sb, Sc, Sd, Se, Sf
        {11, 10, 29, 24, 19, 215}, //150g

        // 226 - x: 1229, y: 1560 org LB
        // Sa, Sb, Sc, Sd, Se, Sf
        {11, 12, 24, 31, 20, 220}, //150g

        // 227 - x: 1355, y: 1560 org LB
        // Sa, Sb, Sc, Sd, Se, Sf
        {13, 17, 26, 52, 25, 234}, //150g

        // 228 - x: 1481, y: 1560 org LB
        // Sa, Sb, Sc, Sd, Se, Sf
        {17, 27, 33, 103, 36, 258}, //150g

        // 229 - x: 1607, y: 1560 org LB
        // Sa, Sb, Sc, Sd, Se, Sf
        {25, 46, 44, 223, 55, 295}, //150g

        // 230 - x: 1733, y: 1560 org LB
        // Sa, Sb, Sc, Sd, Se, Sf
        {31, 67, 52, 431, 70, 295}, //150g

        // 231 - x: 1859, y: 1560 org LB
        // Sa, Sb, Sc, Sd, Se, Sf
        {25, 61, 39, 545, 57, 192}, //150g

        // 232 - x: 1985, y: 1560 org LB
        // Sa, Sb, Sc, Sd, Se, Sf
        {13, 35, 19, 435, 29, 82}, //150g

        // 233 - x: 2111, y: 1560 org LB
        // Sa, Sb, Sc, Sd, Se, Sf
        {7, 20, 9, 324, 15, 37}, //150g

        // 234 - x: 2237, y: 1560 org LB
        // Sa, Sb, Sc, Sd, Se, Sf
        {4, 15, 6, 240, 10, 21}, //150g

};
#endif

#endif