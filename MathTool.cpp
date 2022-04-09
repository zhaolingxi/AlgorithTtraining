#include"MathTool.h"

int maxbits(std::vector<int>& ioArray)
{
	int max = INT_MIN;
	for (size_t i = 0; i < ioArray.size(); i++)
	{
		max = __max(max, ioArray[i]);
	}
	int res = 0;
	while (max != 0)
	{
		res++;
		max = max / 10;
	}
	return res;
}


int getDigit(int iNum, int d)
{
	return ((iNum / (int)pow(10, d - 1)) % 10);
}