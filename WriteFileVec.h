#include <iostream>
#include <fstream>
using namespace std;
template <int Num, typename Tm>
void WriteFileVec(char* fp, Tm InBuf[Num])
{
	int i;
	int j;

	ofstream fp_strmo(fp);
	if (!fp_strmo.is_open())
	{
		cerr << "Error!\nThe file is not able to open!\n";
	}
	else
	{
		for (i = 0; i < Num; i++)
		{
			fp_strmo << InBuf[i] << '\n';
		}
	}
	fp_strmo.close();
	cout << setw(60) << setfill('-') << '-' << '\n';
	cout << "Data has been successfully stored to target file!\n";
	cout << setw(60) << setfill('-') << '-' << '\n';
}
