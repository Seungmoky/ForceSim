#include "Config.h"
#include "Force_Rawdata_point_18by13.h"
#define DEF_SENSOR_CNT SUPPORT_FORCE_BUTTON_NODE
#if(DEF_USE_TEST_NORMALIZE_OPTION)
u16 ALIGNED_2_OPTION var_Test_Normalize = 1;
#endif

s16 Solve_Linear_ls_Weight(struct _point* coord_0, struct _point* coord_1, s16* Target_V, s16 cnt, float* error)
{
	int i;
	int sum_y_sen;
	int sum_y_ref[2];
	int delta_y;
	s32 result_wegith;

	sum_y_sen = sum_y_ref[0] = sum_y_ref[1] = 0;
	for (i = DEF_FIX_SENSOR_START; i < DEF_FIX_SENSOR_START + cnt; i++)
	{
		s32 temp = (s32)Target_V[i];
#if(DEF_USE_TEST_NORMALIZE_OPTION)
		if (var_Test_Normalize)
			temp = temp * 300 / var_scaler[i];
		else
			temp = temp;
#else
#if(DEF_USE_RAWDATA_NORMALIZE)
		temp = temp * 300 / var_scaler[i];
#else
		temp = temp;
#endif
#endif
		sum_y_sen += temp;
		sum_y_ref[0] += coord_0[i].y;
		sum_y_ref[1] += coord_1[i].y;
	}

	delta_y = (sum_y_ref[1] - sum_y_ref[0]);
	if (delta_y > 0)
		result_wegith = (sum_y_sen - sum_y_ref[0]) * 80 / delta_y + 110;
	else
		result_wegith = -1;

	return (s16)result_wegith;
}

s16 cubic_interpolate_fixed(s16 p[4], s32 t_q10) {
	s32 p0 = p[0], p1 = p[1], p2 = p[2], p3 = p[3];
	s32 c1 = p2 - p0;
	s32 c2 = (p0 * 2) - (p1 * 5) + (p2 * 4) - p3;
	s32 c3 = -p0 + (p1 * 3) - (p2 * 3) + p3;
	s64 val1 = ((s64)t_q10 * c3);
	s64 val2 = ((s64)c2 << 10) + val1;
	s64 val3 = ((s64)t_q10 * val2) >> 10;
	s64 val4 = ((s64)c1 << 10) + val3;
	s64 final_offset = (((s64)t_q10 * val4) >> 10) >> 1;
	s64 result_q10 = ((s64)p1 << 10) + final_offset;
	return (s16)((result_q10 + 512) >> 10);
}

void find_fractional_info(s16 coord, const s16 div_array[], int count, int* out_idx, s32* out_t_q10) {
	int i; /* C89: 변수 선언은 함수 시작 부분에서 */
	s32 diff;

	if (coord <= div_array[0]) {
		*out_idx = 0;
		*out_t_q10 = 0;
		return;
	}
	if (coord >= div_array[count - 1]) {
		*out_idx = count - 2;
		*out_t_q10 = 1024;
		return;
	}

	for (i = 0; i < count - 1; ++i) {
		if (coord >= div_array[i] && coord < div_array[i + 1]) {
			*out_idx = i;
			diff = div_array[i + 1] - div_array[i];
			if (diff == 0) {
				*out_t_q10 = 0;
			}
			else {
				*out_t_q10 = (((s32)(coord - div_array[i])) << 10) / diff;
			}
			return;
		}
	}
}


s16 estimate_weight(s16 x_coord, s16 y_coord, s16* sensor_values) {
#define DEF_WEIGHT_BOUNDARY_LOW_INDEX	1
#define DEF_WEIGHT_BOUNDARY_HIGH_INDEX	3
	/* C89: 모든 변수를 함수 시작 부분에 선언 */
	int x1_idx, y1_idx;
	s32 tx_q10, ty_q10;
	int w_idx, s_idx, i, j;
	s16 control_points[4][4];
	int y_ctrl_idx, x_ctrl_idx, zone_idx;
	s16 p_interp_y[4];
	float error;
	s16 final_weight;

	struct _point coord_0[DEF_SENSOR_CNT];
	struct _point coord_1[DEF_SENSOR_CNT];

	find_fractional_info(x_coord, x_divide, DEF_ZONE_X_CNT, &x1_idx, &tx_q10);
	find_fractional_info(y_coord, y_divide, DEF_ZONE_Y_CNT, &y1_idx, &ty_q10);

	for (w_idx = 0; w_idx < DEF_WEIGHT_CNT; ++w_idx) {
		if ((w_idx == DEF_WEIGHT_BOUNDARY_LOW_INDEX) || (w_idx == DEF_WEIGHT_BOUNDARY_HIGH_INDEX))
		{
			for (s_idx = 0; s_idx < DEF_SENSOR_CNT; ++s_idx) {
				for (i = 0; i < 4; ++i) {
					y_ctrl_idx = ztCLIP(y1_idx - 1 + i, 0, DEF_ZONE_Y_CNT - 1);
					for (j = 0; j < 4; ++j) {
						x_ctrl_idx = ztCLIP(x1_idx - 1 + j, 0, DEF_ZONE_X_CNT - 1);
						zone_idx = (y_ctrl_idx * DEF_ZONE_X_CNT + x_ctrl_idx) * DEF_WEIGHT_CNT + w_idx;
#if(DEF_USE_TEST_NORMALIZE_OPTION)
						if (var_Test_Normalize)
							control_points[i][j] = FSR_Zone[zone_idx][s_idx];
						else
							control_points[i][j] = FSR_Zone[zone_idx][s_idx] * var_scaler[s_idx] / 300;
#else
#if(DEF_USE_RAWDATA_NORMALIZE)
						control_points[i][j] = FSR_Zone[zone_idx][s_idx];
#else
						control_points[i][j] = FSR_Zone[zone_idx][s_idx] * var_scaler[s_idx] / 300;
#endif
#endif
					}
				}

				for (i = 0; i < 4; ++i) {
					p_interp_y[i] = cubic_interpolate_fixed(control_points[i], tx_q10);
				}

				if (w_idx == DEF_WEIGHT_BOUNDARY_LOW_INDEX)
				{
					coord_0[s_idx].y = cubic_interpolate_fixed(p_interp_y, ty_q10);
					coord_0[s_idx].x = FSR_Weight_Items[w_idx];
				}
				else
				{
					coord_1[s_idx].y = cubic_interpolate_fixed(p_interp_y, ty_q10);
					coord_1[s_idx].x = FSR_Weight_Items[w_idx];
				}
			}
		}
	}

	final_weight = Solve_Linear_ls_Weight(coord_0, coord_1, sensor_values, DEF_SENSOR_CNT, &error);

	return final_weight;
}
