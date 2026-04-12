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
const s16 scaler[SUPPORT_FORCE_BUTTON_NODE] = { 145, 150, 163, 155, 314, 319 };
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
        {232, 6, 14, 4, 20, 9}, //150g

        // 2 - x: 220, y: 76 org LB
        // Sa, Sb, Sc, Sd, Se, Sf
        {301, 9, 19, 6, 36, 14}, //150g

        // 3 - x: 346, y: 76 org LB
        // Sa, Sb, Sc, Sd, Se, Sf
        {383, 18, 32, 12, 77, 27}, //150g

        // 4 - x: 472, y: 76 org LB
        // Sa, Sb, Sc, Sd, Se, Sf
        {384, 29, 45, 19, 147, 42}, //150g

        // 5 - x: 599, y: 76 org LB
        // Sa, Sb, Sc, Sd, Se, Sf
        {261, 33, 42, 20, 194, 45}, //150g

        // 6 - x: 724, y: 76 org LB
        // Sa, Sb, Sc, Sd, Se, Sf
        {132, 28, 28, 15, 188, 34}, //150g

        // 7 - x: 851, y: 76 org LB
        // Sa, Sb, Sc, Sd, Se, Sf
        {63, 21, 17, 11, 171, 23}, //150g

        // 8 - x: 977, y: 76 org LB
        // Sa, Sb, Sc, Sd, Se, Sf
        {34, 18, 11, 9, 163, 17}, //150g

        // 9 - x: 1103, y: 76 org LB
        // Sa, Sb, Sc, Sd, Se, Sf
        {22, 18, 8, 8, 161, 14}, //150g

        // 10 - x: 1229, y: 76 org LB
        // Sa, Sb, Sc, Sd, Se, Sf
        {18, 24, 8, 9, 166, 15}, //150g

        // 11 - x: 1355, y: 76 org LB
        // Sa, Sb, Sc, Sd, Se, Sf
        {20, 39, 9, 12, 176, 19}, //150g

        // 12 - x: 1481, y: 76 org LB
        // Sa, Sb, Sc, Sd, Se, Sf
        {24, 77, 13, 20, 193, 27}, //150g

        // 13 - x: 1607, y: 76 org LB
        // Sa, Sb, Sc, Sd, Se, Sf
        {33, 165, 18, 34, 218, 41}, //150g

        // 14 - x: 1733, y: 76 org LB
        // Sa, Sb, Sc, Sd, Se, Sf
        {39, 329, 24, 51, 225, 54}, //150g

        // 15 - x: 1859, y: 76 org LB
        // Sa, Sb, Sc, Sd, Se, Sf
        {32, 452, 21, 51, 160, 47}, //150g

        // 16 - x: 1985, y: 76 org LB
        // Sa, Sb, Sc, Sd, Se, Sf
        {18, 414, 12, 34, 78, 28}, //150g

        // 17 - x: 2111, y: 76 org LB
        // Sa, Sb, Sc, Sd, Se, Sf
        {9, 299, 6, 19, 34, 14}, //150g

        // 18 - x: 2237, y: 76 org LB
        // Sa, Sb, Sc, Sd, Se, Sf
        {5, 213, 4, 13, 19, 9}, //150g

        // 19 - x: 94, y: 200 org LB
        // Sa, Sb, Sc, Sd, Se, Sf
        {203, 4, 12, 3, 15, 7}, //150g

        // 20 - x: 220, y: 200 org LB
        // Sa, Sb, Sc, Sd, Se, Sf
        {265, 7, 17, 5, 27, 12}, //150g

        // 21 - x: 346, y: 200 org LB
        // Sa, Sb, Sc, Sd, Se, Sf
        {341, 14, 30, 10, 63, 24}, //150g

        // 22 - x: 472, y: 200 org LB
        // Sa, Sb, Sc, Sd, Se, Sf
        {374, 26, 47, 18, 139, 43}, //150g

        // 23 - x: 599, y: 200 org LB
        // Sa, Sb, Sc, Sd, Se, Sf
        {263, 32, 47, 20, 202, 50}, //150g

        // 24 - x: 724, y: 200 org LB
        // Sa, Sb, Sc, Sd, Se, Sf
        {133, 27, 31, 16, 207, 39}, //150g

        // 25 - x: 851, y: 200 org LB
        // Sa, Sb, Sc, Sd, Se, Sf
        {60, 20, 18, 11, 190, 25}, //150g

        // 26 - x: 977, y: 200 org LB
        // Sa, Sb, Sc, Sd, Se, Sf
        {29, 15, 11, 8, 180, 17}, //150g

        // 27 - x: 1103, y: 200 org LB
        // Sa, Sb, Sc, Sd, Se, Sf
        {18, 14, 7, 7, 177, 14}, //150g

        // 28 - x: 1229, y: 200 org LB
        // Sa, Sb, Sc, Sd, Se, Sf
        {15, 19, 7, 8, 181, 14}, //150g

        // 29 - x: 1355, y: 200 org LB
        // Sa, Sb, Sc, Sd, Se, Sf
        {17, 34, 9, 12, 191, 19}, //150g

        // 30 - x: 1481, y: 200 org LB
        // Sa, Sb, Sc, Sd, Se, Sf
        {22, 72, 13, 21, 208, 29}, //150g

        // 31 - x: 1607, y: 200 org LB
        // Sa, Sb, Sc, Sd, Se, Sf
        {30, 161, 19, 37, 231, 45}, //150g

        // 32 - x: 1733, y: 200 org LB
        // Sa, Sb, Sc, Sd, Se, Sf
        {36, 318, 23, 54, 223, 57}, //150g

        // 33 - x: 1859, y: 200 org LB
        // Sa, Sb, Sc, Sd, Se, Sf
        {27, 410, 18, 50, 140, 45}, //150g

        // 34 - x: 1985, y: 200 org LB
        // Sa, Sb, Sc, Sd, Se, Sf
        {13, 355, 9, 30, 61, 23}, //150g

        // 35 - x: 2111, y: 200 org LB
        // Sa, Sb, Sc, Sd, Se, Sf
        {6, 250, 4, 16, 24, 11}, //150g

        // 36 - x: 2237, y: 200 org LB
        // Sa, Sb, Sc, Sd, Se, Sf
        {4, 186, 3, 11, 14, 7}, //150g

        // 37 - x: 94, y: 324 org LB
        // Sa, Sb, Sc, Sd, Se, Sf
        {191, 4, 15, 3, 16, 9}, //150g

        // 38 - x: 220, y: 324 org LB
        // Sa, Sb, Sc, Sd, Se, Sf
        {251, 7, 21, 5, 28, 14}, //150g

        // 39 - x: 346, y: 324 org LB
        // Sa, Sb, Sc, Sd, Se, Sf
        {319, 14, 36, 10, 64, 27}, //150g

        // 40 - x: 472, y: 324 org LB
        // Sa, Sb, Sc, Sd, Se, Sf
        {350, 25, 56, 18, 139, 50}, //150g

        // 41 - x: 599, y: 324 org LB
        // Sa, Sb, Sc, Sd, Se, Sf
        {262, 32, 57, 22, 213, 61}, //150g

        // 42 - x: 724, y: 324 org LB
        // Sa, Sb, Sc, Sd, Se, Sf
        {138, 28, 39, 19, 230, 50}, //150g

        // 43 - x: 851, y: 324 org LB
        // Sa, Sb, Sc, Sd, Se, Sf
        {62, 21, 22, 13, 212, 33}, //150g

        // 44 - x: 977, y: 324 org LB
        // Sa, Sb, Sc, Sd, Se, Sf
        {30, 16, 12, 9, 200, 22}, //150g

        // 45 - x: 1103, y: 324 org LB
        // Sa, Sb, Sc, Sd, Se, Sf
        {17, 14, 8, 7, 198, 17}, //150g

        // 46 - x: 1229, y: 324 org LB
        // Sa, Sb, Sc, Sd, Se, Sf
        {14, 19, 8, 9, 201, 17}, //150g

        // 47 - x: 1355, y: 324 org LB
        // Sa, Sb, Sc, Sd, Se, Sf
        {17, 34, 10, 14, 211, 24}, //150g

        // 48 - x: 1481, y: 324 org LB
        // Sa, Sb, Sc, Sd, Se, Sf
        {23, 73, 14, 25, 228, 37}, //150g

        // 49 - x: 1607, y: 324 org LB
        // Sa, Sb, Sc, Sd, Se, Sf
        {32, 164, 21, 45, 249, 56}, //150g

        // 50 - x: 1733, y: 324 org LB
        // Sa, Sb, Sc, Sd, Se, Sf
        {35, 300, 24, 63, 223, 66}, //150g

        // 51 - x: 1859, y: 324 org LB
        // Sa, Sb, Sc, Sd, Se, Sf
        {26, 376, 19, 58, 137, 50}, //150g

        // 52 - x: 1985, y: 324 org LB
        // Sa, Sb, Sc, Sd, Se, Sf
        {13, 328, 10, 36, 61, 26}, //150g

        // 53 - x: 2111, y: 324 org LB
        // Sa, Sb, Sc, Sd, Se, Sf
        {6, 240, 5, 20, 26, 13}, //150g

        // 54 - x: 2237, y: 324 org LB
        // Sa, Sb, Sc, Sd, Se, Sf
        {4, 177, 3, 14, 14, 8}, //150g

        // 55 - x: 94, y: 447 org LB
        // Sa, Sb, Sc, Sd, Se, Sf
        {193, 6, 27, 5, 22, 14}, //150g

        // 56 - x: 220, y: 447 org LB
        // Sa, Sb, Sc, Sd, Se, Sf
        {246, 9, 36, 7, 37, 21}, //150g

        // 57 - x: 346, y: 447 org LB
        // Sa, Sb, Sc, Sd, Se, Sf
        {310, 17, 55, 13, 77, 39}, //150g

        // 58 - x: 472, y: 447 org LB
        // Sa, Sb, Sc, Sd, Se, Sf
        {326, 28, 75, 21, 148, 64}, //150g

        // 59 - x: 599, y: 447 org LB
        // Sa, Sb, Sc, Sd, Se, Sf
        {254, 35, 75, 26, 221, 79}, //150g

        // 60 - x: 724, y: 447 org LB
        // Sa, Sb, Sc, Sd, Se, Sf
        {146, 32, 53, 23, 246, 69}, //150g

        // 61 - x: 851, y: 447 org LB
        // Sa, Sb, Sc, Sd, Se, Sf
        {72, 25, 31, 17, 236, 50}, //150g

        // 62 - x: 977, y: 447 org LB
        // Sa, Sb, Sc, Sd, Se, Sf
        {37, 20, 18, 13, 224, 35}, //150g

        // 63 - x: 1103, y: 447 org LB
        // Sa, Sb, Sc, Sd, Se, Sf
        {23, 19, 13, 11, 223, 29}, //150g

        // 64 - x: 1229, y: 447 org LB
        // Sa, Sb, Sc, Sd, Se, Sf
        {19, 24, 12, 13, 226, 30}, //150g

        // 65 - x: 1355, y: 447 org LB
        // Sa, Sb, Sc, Sd, Se, Sf
        {21, 41, 14, 20, 232, 38}, //150g

        // 66 - x: 1481, y: 447 org LB
        // Sa, Sb, Sc, Sd, Se, Sf
        {27, 82, 19, 35, 250, 55}, //150g

        // 67 - x: 1607, y: 447 org LB
        // Sa, Sb, Sc, Sd, Se, Sf
        {35, 168, 25, 60, 262, 76}, //150g

        // 68 - x: 1733, y: 447 org LB
        // Sa, Sb, Sc, Sd, Se, Sf
        {37, 288, 28, 82, 230, 85}, //150g

        // 69 - x: 1859, y: 447 org LB
        // Sa, Sb, Sc, Sd, Se, Sf
        {28, 350, 22, 78, 147, 65}, //150g

        // 70 - x: 1985, y: 447 org LB
        // Sa, Sb, Sc, Sd, Se, Sf
        {16, 306, 13, 53, 71, 36}, //150g

        // 71 - x: 2111, y: 447 org LB
        // Sa, Sb, Sc, Sd, Se, Sf
        {8, 233, 7, 33, 34, 19}, //150g

        // 72 - x: 2237, y: 447 org LB
        // Sa, Sb, Sc, Sd, Se, Sf
        {5, 179, 5, 25, 20, 12}, //150g

        // 73 - x: 94, y: 571 org LB
        // Sa, Sb, Sc, Sd, Se, Sf
        {193, 9, 51, 8, 32, 23}, //150g

        // 74 - x: 220, y: 571 org LB
        // Sa, Sb, Sc, Sd, Se, Sf
        {239, 13, 65, 11, 51, 34}, //150g

        // 75 - x: 346, y: 571 org LB
        // Sa, Sb, Sc, Sd, Se, Sf
        {293, 21, 90, 18, 93, 58}, //150g

        // 76 - x: 472, y: 571 org LB
        // Sa, Sb, Sc, Sd, Se, Sf
        {302, 32, 109, 27, 160, 89}, //150g

        // 77 - x: 599, y: 571 org LB
        // Sa, Sb, Sc, Sd, Se, Sf
        {242, 39, 104, 32, 225, 109}, //150g

        // 78 - x: 724, y: 571 org LB
        // Sa, Sb, Sc, Sd, Se, Sf
        {155, 37, 77, 30, 255, 104}, //150g

        // 79 - x: 851, y: 571 org LB
        // Sa, Sb, Sc, Sd, Se, Sf
        {86, 32, 48, 24, 251, 84}, //150g

        // 80 - x: 977, y: 571 org LB
        // Sa, Sb, Sc, Sd, Se, Sf
        {49, 27, 30, 20, 241, 66}, //150g

        // 81 - x: 1103, y: 571 org LB
        // Sa, Sb, Sc, Sd, Se, Sf
        {33, 28, 22, 19, 238, 58}, //150g

        // 82 - x: 1229, y: 571 org LB
        // Sa, Sb, Sc, Sd, Se, Sf
        {28, 35, 20, 23, 243, 60}, //150g

        // 83 - x: 1355, y: 571 org LB
        // Sa, Sb, Sc, Sd, Se, Sf
        {29, 54, 21, 33, 249, 70}, //150g

        // 84 - x: 1481, y: 571 org LB
        // Sa, Sb, Sc, Sd, Se, Sf
        {34, 97, 26, 54, 265, 91}, //150g

        // 85 - x: 1607, y: 571 org LB
        // Sa, Sb, Sc, Sd, Se, Sf
        {40, 176, 32, 85, 270, 113}, //150g

        // 86 - x: 1733, y: 571 org LB
        // Sa, Sb, Sc, Sd, Se, Sf
        {41, 271, 34, 113, 234, 115}, //150g

        // 87 - x: 1859, y: 571 org LB
        // Sa, Sb, Sc, Sd, Se, Sf
        {32, 319, 27, 113, 158, 89}, //150g

        // 88 - x: 1985, y: 571 org LB
        // Sa, Sb, Sc, Sd, Se, Sf
        {20, 293, 17, 89, 88, 55}, //150g

        // 89 - x: 2111, y: 571 org LB
        // Sa, Sb, Sc, Sd, Se, Sf
        {12, 233, 11, 63, 48, 32}, //150g

        // 90 - x: 2237, y: 571 org LB
        // Sa, Sb, Sc, Sd, Se, Sf
        {8, 181, 7, 48, 29, 21}, //150g

        // 91 - x: 94, y: 694 org LB
        // Sa, Sb, Sc, Sd, Se, Sf
        {180, 12, 92, 11, 41, 34}, //150g

        // 92 - x: 220, y: 694 org LB
        // Sa, Sb, Sc, Sd, Se, Sf
        {218, 17, 113, 16, 62, 51}, //150g

        // 93 - x: 346, y: 694 org LB
        // Sa, Sb, Sc, Sd, Se, Sf
        {261, 25, 144, 23, 105, 82}, //150g

        // 94 - x: 472, y: 694 org LB
        // Sa, Sb, Sc, Sd, Se, Sf
        {267, 35, 159, 32, 163, 120}, //150g

        // 95 - x: 599, y: 694 org LB
        // Sa, Sb, Sc, Sd, Se, Sf
        {221, 42, 143, 38, 216, 148}, //150g

        // 96 - x: 724, y: 694 org LB
        // Sa, Sb, Sc, Sd, Se, Sf
        {150, 41, 105, 37, 237, 149}, //150g

        // 97 - x: 851, y: 694 org LB
        // Sa, Sb, Sc, Sd, Se, Sf
        {96, 38, 71, 33, 242, 138}, //150g

        // 98 - x: 977, y: 694 org LB
        // Sa, Sb, Sc, Sd, Se, Sf
        {62, 36, 48, 31, 237, 123}, //150g

        // 99 - x: 1103, y: 694 org LB
        // Sa, Sb, Sc, Sd, Se, Sf
        {44, 37, 36, 31, 232, 114}, //150g

        // 100 - x: 1229, y: 694 org LB
        // Sa, Sb, Sc, Sd, Se, Sf
        {37, 46, 31, 37, 235, 115}, //150g

        // 101 - x: 1355, y: 694 org LB
        // Sa, Sb, Sc, Sd, Se, Sf
        {37, 66, 32, 51, 242, 127}, //150g

        // 102 - x: 1481, y: 694 org LB
        // Sa, Sb, Sc, Sd, Se, Sf
        {40, 106, 35, 78, 253, 146}, //150g

        // 103 - x: 1607, y: 694 org LB
        // Sa, Sb, Sc, Sd, Se, Sf
        {45, 173, 40, 119, 257, 163}, //150g

        // 104 - x: 1733, y: 694 org LB
        // Sa, Sb, Sc, Sd, Se, Sf
        {44, 246, 40, 157, 226, 156}, //150g

        // 105 - x: 1859, y: 694 org LB
        // Sa, Sb, Sc, Sd, Se, Sf
        {36, 282, 33, 166, 163, 121}, //150g

        // 106 - x: 1985, y: 694 org LB
        // Sa, Sb, Sc, Sd, Se, Sf
        {25, 265, 23, 145, 102, 80}, //150g

        // 107 - x: 2111, y: 694 org LB
        // Sa, Sb, Sc, Sd, Se, Sf
        {16, 216, 15, 112, 60, 49}, //150g

        // 108 - x: 2237, y: 694 org LB
        // Sa, Sb, Sc, Sd, Se, Sf
        {11, 171, 11, 88, 38, 32}, //150g

        // 109 - x: 94, y: 818 org LB
        // Sa, Sb, Sc, Sd, Se, Sf
        {146, 13, 146, 13, 44, 44}, //150g

        // 110 - x: 220, y: 818 org LB
        // Sa, Sb, Sc, Sd, Se, Sf
        {174, 18, 174, 18, 64, 64}, //150g

        // 111 - x: 346, y: 818 org LB
        // Sa, Sb, Sc, Sd, Se, Sf
        {203, 26, 203, 26, 99, 99}, //150g

        // 112 - x: 472, y: 818 org LB
        // Sa, Sb, Sc, Sd, Se, Sf
        {213, 35, 213, 35, 147, 147}, //150g

        // 113 - x: 599, y: 818 org LB
        // Sa, Sb, Sc, Sd, Se, Sf
        {184, 41, 184, 41, 186, 186}, //150g

        // 114 - x: 724, y: 818 org LB
        // Sa, Sb, Sc, Sd, Se, Sf
        {135, 42, 135, 42, 202, 202}, //150g

        // 115 - x: 851, y: 818 org LB
        // Sa, Sb, Sc, Sd, Se, Sf
        {91, 39, 91, 39, 199, 199}, //150g

        // 116 - x: 977, y: 818 org LB
        // Sa, Sb, Sc, Sd, Se, Sf
        {62, 38, 62, 38, 190, 190}, //150g

        // 117 - x: 1103, y: 818 org LB
        // Sa, Sb, Sc, Sd, Se, Sf
        {47, 40, 47, 40, 185, 185}, //150g

        // 118 - x: 1229, y: 818 org LB
        // Sa, Sb, Sc, Sd, Se, Sf
        {40, 48, 40, 48, 187, 187}, //150g

        // 119 - x: 1355, y: 818 org LB
        // Sa, Sb, Sc, Sd, Se, Sf
        {39, 67, 39, 67, 198, 198}, //150g

        // 120 - x: 1481, y: 818 org LB
        // Sa, Sb, Sc, Sd, Se, Sf
        {42, 101, 42, 101, 211, 211}, //150g

        // 121 - x: 1607, y: 818 org LB
        // Sa, Sb, Sc, Sd, Se, Sf
        {45, 152, 45, 152, 217, 217}, //150g

        // 122 - x: 1733, y: 818 org LB
        // Sa, Sb, Sc, Sd, Se, Sf
        {45, 209, 45, 209, 201, 201}, //150g

        // 123 - x: 1859, y: 818 org LB
        // Sa, Sb, Sc, Sd, Se, Sf
        {37, 229, 37, 229, 151, 151}, //150g

        // 124 - x: 1985, y: 818 org LB
        // Sa, Sb, Sc, Sd, Se, Sf
        {26, 213, 26, 213, 100, 100}, //150g

        // 125 - x: 2111, y: 818 org LB
        // Sa, Sb, Sc, Sd, Se, Sf
        {18, 175, 18, 175, 62, 62}, //150g

        // 126 - x: 2237, y: 818 org LB
        // Sa, Sb, Sc, Sd, Se, Sf
        {13, 141, 13, 141, 41, 41}, //150g

        // 127 - x: 94, y: 942 org LB
        // Sa, Sb, Sc, Sd, Se, Sf
        {96, 12, 186, 12, 36, 42}, //150g

        // 128 - x: 220, y: 942 org LB
        // Sa, Sb, Sc, Sd, Se, Sf
        {113, 15, 217, 17, 51, 62}, //150g

        // 129 - x: 346, y: 942 org LB
        // Sa, Sb, Sc, Sd, Se, Sf
        {141, 23, 256, 25, 80, 103}, //150g

        // 130 - x: 472, y: 942 org LB
        // Sa, Sb, Sc, Sd, Se, Sf
        {159, 32, 267, 35, 120, 163}, //150g

        // 131 - x: 599, y: 942 org LB
        // Sa, Sb, Sc, Sd, Se, Sf
        {142, 37, 219, 41, 147, 214}, //150g

        // 132 - x: 724, y: 942 org LB
        // Sa, Sb, Sc, Sd, Se, Sf
        {105, 37, 151, 41, 150, 239}, //150g

        // 133 - x: 851, y: 942 org LB
        // Sa, Sb, Sc, Sd, Se, Sf
        {70, 33, 95, 38, 137, 240}, //150g

        // 134 - x: 977, y: 942 org LB
        // Sa, Sb, Sc, Sd, Se, Sf
        {47, 30, 61, 35, 121, 233}, //150g

        // 135 - x: 1103, y: 942 org LB
        // Sa, Sb, Sc, Sd, Se, Sf
        {35, 31, 44, 37, 112, 229}, //150g

        // 136 - x: 1229, y: 942 org LB
        // Sa, Sb, Sc, Sd, Se, Sf
        {31, 37, 37, 46, 114, 232}, //150g

        // 137 - x: 1355, y: 942 org LB
        // Sa, Sb, Sc, Sd, Se, Sf
        {32, 52, 37, 67, 128, 244}, //150g

        // 138 - x: 1481, y: 942 org LB
        // Sa, Sb, Sc, Sd, Se, Sf
        {36, 79, 41, 108, 148, 257}, //150g

        // 139 - x: 1607, y: 942 org LB
        // Sa, Sb, Sc, Sd, Se, Sf
        {40, 120, 45, 174, 164, 258}, //150g

        // 140 - x: 1733, y: 942 org LB
        // Sa, Sb, Sc, Sd, Se, Sf
        {42, 163, 46, 255, 162, 235}, //150g

        // 141 - x: 1859, y: 942 org LB
        // Sa, Sb, Sc, Sd, Se, Sf
        {34, 171, 37, 291, 125, 168}, //150g

        // 142 - x: 1985, y: 942 org LB
        // Sa, Sb, Sc, Sd, Se, Sf
        {23, 147, 25, 268, 81, 103}, //150g

        // 143 - x: 2111, y: 942 org LB
        // Sa, Sb, Sc, Sd, Se, Sf
        {16, 117, 17, 226, 51, 63}, //150g

        // 144 - x: 2237, y: 942 org LB
        // Sa, Sb, Sc, Sd, Se, Sf
        {11, 93, 12, 181, 34, 40}, //150g

        // 145 - x: 94, y: 1065 org LB
        // Sa, Sb, Sc, Sd, Se, Sf
        {53, 8, 200, 9, 24, 33}, //150g

        // 146 - x: 220, y: 1065 org LB
        // Sa, Sb, Sc, Sd, Se, Sf
        {66, 11, 244, 13, 35, 52}, //150g

        // 147 - x: 346, y: 1065 org LB
        // Sa, Sb, Sc, Sd, Se, Sf
        {87, 18, 284, 20, 56, 90}, //150g

        // 148 - x: 472, y: 1065 org LB
        // Sa, Sb, Sc, Sd, Se, Sf
        {108, 26, 298, 31, 88, 158}, //150g

        // 149 - x: 599, y: 1065 org LB
        // Sa, Sb, Sc, Sd, Se, Sf
        {104, 32, 243, 39, 109, 226}, //150g

        // 150 - x: 724, y: 1065 org LB
        // Sa, Sb, Sc, Sd, Se, Sf
        {76, 30, 154, 37, 104, 254}, //150g

        // 151 - x: 851, y: 1065 org LB
        // Sa, Sb, Sc, Sd, Se, Sf
        {47, 24, 85, 31, 83, 248}, //150g

        // 152 - x: 977, y: 1065 org LB
        // Sa, Sb, Sc, Sd, Se, Sf
        {30, 20, 48, 27, 65, 237}, //150g

        // 153 - x: 1103, y: 1065 org LB
        // Sa, Sb, Sc, Sd, Se, Sf
        {22, 19, 33, 27, 57, 235}, //150g

        // 154 - x: 1229, y: 1065 org LB
        // Sa, Sb, Sc, Sd, Se, Sf
        {19, 23, 27, 35, 59, 240}, //150g

        // 155 - x: 1355, y: 1065 org LB
        // Sa, Sb, Sc, Sd, Se, Sf
        {21, 33, 28, 53, 70, 247}, //150g

        // 156 - x: 1481, y: 1065 org LB
        // Sa, Sb, Sc, Sd, Se, Sf
        {27, 54, 34, 98, 92, 268}, //150g

        // 157 - x: 1607, y: 1065 org LB
        // Sa, Sb, Sc, Sd, Se, Sf
        {33, 88, 42, 181, 116, 278}, //150g

        // 158 - x: 1733, y: 1065 org LB
        // Sa, Sb, Sc, Sd, Se, Sf
        {35, 119, 43, 284, 121, 245}, //150g

        // 159 - x: 1859, y: 1065 org LB
        // Sa, Sb, Sc, Sd, Se, Sf
        {29, 122, 34, 343, 96, 170}, //150g

        // 160 - x: 1985, y: 1065 org LB
        // Sa, Sb, Sc, Sd, Se, Sf
        {18, 91, 21, 301, 57, 91}, //150g

        // 161 - x: 2111, y: 1065 org LB
        // Sa, Sb, Sc, Sd, Se, Sf
        {11, 67, 13, 249, 34, 51}, //150g

        // 162 - x: 2237, y: 1065 org LB
        // Sa, Sb, Sc, Sd, Se, Sf
        {8, 52, 9, 194, 23, 31}, //150g

        // 163 - x: 94, y: 1189 org LB
        // Sa, Sb, Sc, Sd, Se, Sf
        {27, 5, 198, 6, 14, 22}, //150g

        // 164 - x: 220, y: 1189 org LB
        // Sa, Sb, Sc, Sd, Se, Sf
        {36, 8, 248, 9, 21, 37}, //150g

        // 165 - x: 346, y: 1189 org LB
        // Sa, Sb, Sc, Sd, Se, Sf
        {53, 13, 301, 16, 37, 74}, //150g

        // 166 - x: 472, y: 1189 org LB
        // Sa, Sb, Sc, Sd, Se, Sf
        {74, 21, 323, 27, 63, 146}, //150g

        // 167 - x: 599, y: 1189 org LB
        // Sa, Sb, Sc, Sd, Se, Sf
        {75, 26, 256, 35, 80, 223}, //150g

        // 168 - x: 724, y: 1189 org LB
        // Sa, Sb, Sc, Sd, Se, Sf
        {53, 23, 147, 32, 70, 248}, //150g

        // 169 - x: 851, y: 1189 org LB
        // Sa, Sb, Sc, Sd, Se, Sf
        {31, 17, 72, 25, 50, 236}, //150g

        // 170 - x: 977, y: 1189 org LB
        // Sa, Sb, Sc, Sd, Se, Sf
        {18, 13, 36, 20, 35, 223}, //150g

        // 171 - x: 1103, y: 1189 org LB
        // Sa, Sb, Sc, Sd, Se, Sf
        {13, 11, 23, 19, 29, 222}, //150g

        // 172 - x: 1229, y: 1189 org LB
        // Sa, Sb, Sc, Sd, Se, Sf
        {12, 13, 19, 24, 30, 228}, //150g

        // 173 - x: 1355, y: 1189 org LB
        // Sa, Sb, Sc, Sd, Se, Sf
        {14, 20, 21, 42, 39, 237}, //150g

        // 174 - x: 1481, y: 1189 org LB
        // Sa, Sb, Sc, Sd, Se, Sf
        {19, 36, 27, 84, 56, 254}, //150g

        // 175 - x: 1607, y: 1189 org LB
        // Sa, Sb, Sc, Sd, Se, Sf
        {26, 62, 36, 175, 80, 273}, //150g

        // 176 - x: 1733, y: 1189 org LB
        // Sa, Sb, Sc, Sd, Se, Sf
        {29, 86, 39, 302, 89, 242}, //150g

        // 177 - x: 1859, y: 1189 org LB
        // Sa, Sb, Sc, Sd, Se, Sf
        {23, 82, 29, 367, 68, 154}, //150g

        // 178 - x: 1985, y: 1189 org LB
        // Sa, Sb, Sc, Sd, Se, Sf
        {13, 55, 16, 321, 38, 74}, //150g

        // 179 - x: 2111, y: 1189 org LB
        // Sa, Sb, Sc, Sd, Se, Sf
        {7, 35, 9, 248, 20, 36}, //150g

        // 180 - x: 2237, y: 1189 org LB
        // Sa, Sb, Sc, Sd, Se, Sf
        {5, 26, 6, 191, 13, 21}, //150g

        // 181 - x: 94, y: 1312 org LB
        // Sa, Sb, Sc, Sd, Se, Sf
        {15, 3, 192, 4, 9, 16}, //150g

        // 182 - x: 220, y: 1312 org LB
        // Sa, Sb, Sc, Sd, Se, Sf
        {21, 5, 248, 7, 14, 28}, //150g

        // 183 - x: 346, y: 1312 org LB
        // Sa, Sb, Sc, Sd, Se, Sf
        {35, 10, 312, 13, 27, 63}, //150g

        // 184 - x: 472, y: 1312 org LB
        // Sa, Sb, Sc, Sd, Se, Sf
        {54, 18, 337, 24, 48, 134}, //150g

        // 185 - x: 599, y: 1312 org LB
        // Sa, Sb, Sc, Sd, Se, Sf
        {56, 22, 259, 32, 60, 210}, //150g

        // 186 - x: 724, y: 1312 org LB
        // Sa, Sb, Sc, Sd, Se, Sf
        {39, 19, 139, 29, 50, 231}, //150g

        // 187 - x: 851, y: 1312 org LB
        // Sa, Sb, Sc, Sd, Se, Sf
        {22, 13, 63, 21, 33, 214}, //150g

        // 188 - x: 977, y: 1312 org LB
        // Sa, Sb, Sc, Sd, Se, Sf
        {12, 9, 30, 16, 22, 201}, //150g

        // 189 - x: 1103, y: 1312 org LB
        // Sa, Sb, Sc, Sd, Se, Sf
        {8, 7, 17, 14, 17, 197}, //150g

        // 190 - x: 1229, y: 1312 org LB
        // Sa, Sb, Sc, Sd, Se, Sf
        {8, 9, 15, 19, 17, 202}, //150g

        // 191 - x: 1355, y: 1312 org LB
        // Sa, Sb, Sc, Sd, Se, Sf
        {10, 14, 17, 34, 24, 214}, //150g

        // 192 - x: 1481, y: 1312 org LB
        // Sa, Sb, Sc, Sd, Se, Sf
        {15, 26, 23, 75, 38, 235}, //150g

        // 193 - x: 1607, y: 1312 org LB
        // Sa, Sb, Sc, Sd, Se, Sf
        {21, 46, 32, 168, 58, 256}, //150g

        // 194 - x: 1733, y: 1312 org LB
        // Sa, Sb, Sc, Sd, Se, Sf
        {25, 66, 36, 314, 69, 233}, //150g

        // 195 - x: 1859, y: 1312 org LB
        // Sa, Sb, Sc, Sd, Se, Sf
        {19, 60, 27, 393, 52, 143}, //150g

        // 196 - x: 1985, y: 1312 org LB
        // Sa, Sb, Sc, Sd, Se, Sf
        {10, 36, 13, 328, 26, 61}, //150g

        // 197 - x: 2111, y: 1312 org LB
        // Sa, Sb, Sc, Sd, Se, Sf
        {5, 21, 7, 247, 13, 26}, //150g

        // 198 - x: 2237, y: 1312 org LB
        // Sa, Sb, Sc, Sd, Se, Sf
        {3, 15, 4, 184, 8, 15}, //150g

        // 199 - x: 94, y: 1436 org LB
        // Sa, Sb, Sc, Sd, Se, Sf
        {11, 3, 196, 4, 7, 14}, //150g

        // 200 - x: 220, y: 1436 org LB
        // Sa, Sb, Sc, Sd, Se, Sf
        {16, 5, 254, 6, 11, 26}, //150g

        // 201 - x: 346, y: 1436 org LB
        // Sa, Sb, Sc, Sd, Se, Sf
        {28, 9, 323, 13, 22, 60}, //150g

        // 202 - x: 472, y: 1436 org LB
        // Sa, Sb, Sc, Sd, Se, Sf
        {44, 16, 349, 24, 41, 130}, //150g

        // 203 - x: 599, y: 1436 org LB
        // Sa, Sb, Sc, Sd, Se, Sf
        {47, 20, 262, 32, 50, 201}, //150g

        // 204 - x: 724, y: 1436 org LB
        // Sa, Sb, Sc, Sd, Se, Sf
        {32, 17, 136, 27, 40, 212}, //150g

        // 205 - x: 851, y: 1436 org LB
        // Sa, Sb, Sc, Sd, Se, Sf
        {18, 11, 61, 20, 26, 195}, //150g

        // 206 - x: 977, y: 1436 org LB
        // Sa, Sb, Sc, Sd, Se, Sf
        {11, 8, 30, 16, 18, 183}, //150g

        // 207 - x: 1103, y: 1436 org LB
        // Sa, Sb, Sc, Sd, Se, Sf
        {7, 7, 18, 15, 14, 178}, //150g

        // 208 - x: 1229, y: 1436 org LB
        // Sa, Sb, Sc, Sd, Se, Sf
        {7, 8, 15, 19, 14, 182}, //150g

        // 209 - x: 1355, y: 1436 org LB
        // Sa, Sb, Sc, Sd, Se, Sf
        {9, 12, 17, 34, 20, 195}, //150g

        // 210 - x: 1481, y: 1436 org LB
        // Sa, Sb, Sc, Sd, Se, Sf
        {13, 21, 23, 73, 30, 213}, //150g

        // 211 - x: 1607, y: 1436 org LB
        // Sa, Sb, Sc, Sd, Se, Sf
        {19, 38, 32, 166, 46, 238}, //150g

        // 212 - x: 1733, y: 1436 org LB
        // Sa, Sb, Sc, Sd, Se, Sf
        {24, 55, 37, 324, 58, 227}, //150g

        // 213 - x: 1859, y: 1436 org LB
        // Sa, Sb, Sc, Sd, Se, Sf
        {18, 49, 27, 406, 44, 139}, //150g

        // 214 - x: 1985, y: 1436 org LB
        // Sa, Sb, Sc, Sd, Se, Sf
        {9, 28, 12, 332, 22, 57}, //150g

        // 215 - x: 2111, y: 1436 org LB
        // Sa, Sb, Sc, Sd, Se, Sf
        {4, 15, 6, 247, 11, 24}, //150g

        // 216 - x: 2237, y: 1436 org LB
        // Sa, Sb, Sc, Sd, Se, Sf
        {3, 11, 4, 183, 7, 13}, //150g

        // 217 - x: 94, y: 1560 org LB
        // Sa, Sb, Sc, Sd, Se, Sf
        {13, 4, 215, 5, 9, 19}, //150g

        // 218 - x: 220, y: 1560 org LB
        // Sa, Sb, Sc, Sd, Se, Sf
        {18, 6, 273, 8, 13, 32}, //150g

        // 219 - x: 346, y: 1560 org LB
        // Sa, Sb, Sc, Sd, Se, Sf
        {29, 11, 344, 16, 24, 69}, //150g

        // 220 - x: 472, y: 1560 org LB
        // Sa, Sb, Sc, Sd, Se, Sf
        {42, 17, 360, 27, 40, 137}, //150g

        // 221 - x: 599, y: 1560 org LB
        // Sa, Sb, Sc, Sd, Se, Sf
        {42, 20, 263, 34, 45, 195}, //150g

        // 222 - x: 724, y: 1560 org LB
        // Sa, Sb, Sc, Sd, Se, Sf
        {29, 16, 139, 29, 36, 198}, //150g

        // 223 - x: 851, y: 1560 org LB
        // Sa, Sb, Sc, Sd, Se, Sf
        {18, 12, 67, 23, 25, 181}, //150g

        // 224 - x: 977, y: 1560 org LB
        // Sa, Sb, Sc, Sd, Se, Sf
        {11, 9, 35, 19, 18, 168}, //150g

        // 225 - x: 1103, y: 1560 org LB
        // Sa, Sb, Sc, Sd, Se, Sf
        {8, 8, 22, 18, 14, 164}, //150g

        // 226 - x: 1229, y: 1560 org LB
        // Sa, Sb, Sc, Sd, Se, Sf
        {8, 9, 19, 24, 15, 168}, //150g

        // 227 - x: 1355, y: 1560 org LB
        // Sa, Sb, Sc, Sd, Se, Sf
        {10, 13, 20, 40, 19, 178}, //150g

        // 228 - x: 1481, y: 1560 org LB
        // Sa, Sb, Sc, Sd, Se, Sf
        {13, 20, 25, 79, 28, 197}, //150g

        // 229 - x: 1607, y: 1560 org LB
        // Sa, Sb, Sc, Sd, Se, Sf
        {19, 35, 34, 171, 42, 226}, //150g

        // 230 - x: 1733, y: 1560 org LB
        // Sa, Sb, Sc, Sd, Se, Sf
        {24, 52, 40, 336, 55, 230}, //150g

        // 231 - x: 1859, y: 1560 org LB
        // Sa, Sb, Sc, Sd, Se, Sf
        {20, 49, 31, 438, 46, 155}, //150g

        // 232 - x: 1985, y: 1560 org LB
        // Sa, Sb, Sc, Sd, Se, Sf
        {10, 29, 16, 357, 24, 67}, //150g

        // 233 - x: 2111, y: 1560 org LB
        // Sa, Sb, Sc, Sd, Se, Sf
        {5, 17, 8, 267, 12, 30}, //150g

        // 234 - x: 2237, y: 1560 org LB
        // Sa, Sb, Sc, Sd, Se, Sf
        {4, 12, 5, 198, 8, 17}, //150g

};
#endif

#endif