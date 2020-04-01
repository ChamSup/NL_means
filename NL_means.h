#ifndef NL_means_H_
#define NL_means_H_

#include <ap_int.h>
#include <stdio.h>

#define ImgWidth 128	        //图像宽度
#define ImgHeight 128	        //图像高度
#define h 0.6		              //滤波平滑参数
#define square_h h*h					//滤波平滑参数平方
#define N ImgWidth*ImgHeight	//图像数据量
#define search_R 9            //搜索窗半径
#define patch_R 5				      //图像块半径
#define Img_row_max (ImgHeight - patch_R*2)
#define Img_col_max (ImgWidth - patch_R*2)
#define N1 Img_row_max*Img_col_max

typedef float dout_t;
typedef float din_t;

void NL_means(dout_t Img_out[N1], din_t Img_in[N]);

#endif
