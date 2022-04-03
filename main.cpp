#include<iostream>
#include "RandomMaker.h"
#include"SortFunction.h"
#include"CheckTool.h"
#include"CheckTool.hpp"

int main()
{
	std::vector<int> tempvec;

	bool flag= getRandomArraySafe(tempvec,2,29,15,25);
	if (flag)
	{
		CoutAVector(tempvec);
	}
	
	//	flag=sort_Bubble(tempvec);
	/*std::vector<int> tempvec1 = tempvec;
	flag= sort_Selection(tempvec1);
	flag= sort_Insert(tempvec);
	if (IsSame(tempvec1, tempvec))
	{
		std::cout << "true" << std::endl;
	}*/
	return 0;
}