#include <iostream>
#include<fstream>
#include "NL_means.h"
#include "ReadFileVec.h"
#include "WriteFileVec.h"
using namespace std;

int main()
{
	din_t din_r[N] = { 0 };
	din_t din_g[N] = { 0 };
	din_t din_b[N] = { 0 };

	dout_t dout_r[N1] = { 0 };
	dout_t dout_g[N1] = { 0 };
	dout_t dout_b[N1] = { 0 };
	int err = 0;
	//源图像
	char* fp_r = "noi_r.txt";
	char* fp_g = "noi_g.txt";
	char* fp_b = "noi_b.txt";
	//输出去噪图像
	char* fp_r_out = "denoised_r.txt";
	char* fp_g_out = "denoised_g.txt";
	char* fp_b_out = "denoised_b.txt";

	ReadFileVec <N, din_t, din_t> (fp_r, din_r);
	ReadFileVec <N, din_t, din_t> (fp_g, din_g);
	ReadFileVec <N, din_t, din_t> (fp_b, din_b);

	NL_means(dout_r, din_r);
	NL_means(dout_g, din_g);
	NL_means(dout_b, din_b);

	WriteFileVec <N1, dout_t> (fp_r_out, dout_r);
	WriteFileVec <N1, dout_t> (fp_g_out, dout_g);
	WriteFileVec <N1, dout_t> (fp_b_out, dout_b);

	for (int i = 0; i < N1; i++)
	{
		cout << "data_out = " << dout_r[i] <<' '<< dout_g[i] <<' '<< dout_b[i] << '\n';
	}

	cout << setw(60) << setfill('-') << '-' << '\n';

	cout << setw(60) << setfill('-') << '-' << '\n';

	return 0;
}
