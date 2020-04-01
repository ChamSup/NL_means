#include <iostream>
#include <fstream>
using namespace std;
template <int Num,typename Tm,typename Tv>
void ReadFileVec(char *fp, Tm OutBuf[Num])
{
	int i;
	int j;
	Tv val;

	ifstream fp_strmi(fp);
	if (!fp_strmi.is_open())
	{
		cerr << "Error!\nThe file is not able to open!" << '\n';
	}
	else
	{
		for (i = 0; i < Num; i++)
		{
			fp_strmi >> val;
			OutBuf[i] = Tm(val);
		}
	}
	fp_strmi.close();
	cout << setw(60) << setfill('-') << '-' << '\n';
	cout << "Read file successfully!\n";
	cout << setw(60) << setfill('-') << '-' << '\n';
}
