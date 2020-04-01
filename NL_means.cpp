#include "NL_means.h"
#include "math.h"

din_t SrcImg[ImgWidth][ImgHeight];
int maxVal(int a, int b);
int minVal(int a, int b);

void NL_means(dout_t Img_out[N1], din_t Img_in[N])
{
	int i = 0;
	int cnt = 0;
	int row_num = 0;	//行数
	int col_num = 0;	//列数
	float average;
	float weight;
	float weight_sum;
	int rmin, rmax, smin, smax;	//搜索窗范围
	float Dist = 0;	//加权欧氏距离

	//存储图像数据
	loop1:
	for (i = 0; i < N; i++)
	{
		SrcImg[row_num][col_num] = Img_in[i];
		col_num++;
		if (col_num == ImgWidth)
		{
			col_num = 0;
			row_num++;
		}
	}

	//遍历图像
	loop2:
	for (row_num = 0; row_num < Img_row_max; row_num++)
	{
		loop_col:
		for (col_num = 0; col_num < Img_col_max; col_num++)
		{
			int row_num1 = row_num + patch_R;
			int col_num1 = col_num + patch_R;
			average = 0;
			weight_sum = 0;
			//确定搜索窗口
			rmin = maxVal(row_num1 - search_R, patch_R);
			rmax = minVal(row_num1 + search_R, Img_row_max + patch_R - 1);
			smin = maxVal(col_num1 - search_R, patch_R);
			smax = minVal(col_num1 + search_R, Img_col_max + patch_R - 1);
			loop_p:	// p 代表搜索窗行
			for (int p = rmin; p <= rmax; p++)
			{
				loop_q:	// q 代表搜索窗列
				for (int q = smin; q <= smax; q++)
				{
					loop_m:	// m 代表图像块行
					for (int m = 0; m <= (patch_R*2); m++)
					{
						loop_n:	// n 代表图像块列
						for (int n = 0; n <= (patch_R*2); n++)
						{
							Dist = Dist + (SrcImg[row_num + m][col_num + n] - SrcImg[p - patch_R + m][q - patch_R + n])
										* (SrcImg[row_num + m][col_num + n] - SrcImg[p - patch_R + m][q - patch_R + n]);
						}
					}
					weight = exp((-Dist) / (square_h));
					weight_sum = weight_sum + weight;
					average = average + weight * SrcImg[p][q];
					Dist = 0;
				}
			}
			Img_out[col_num + (row_num*Img_col_max)] = average / weight_sum;
		}
	}
}

int maxVal(int a, int b)
{
	if (a >= b)
		return a;
	else
		return b;
}

int minVal(int a, int b)
{
	if (a <= b)
		return a;
	else
		return b;
}
