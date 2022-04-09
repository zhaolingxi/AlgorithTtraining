#include<iostream>
#include "RandomMaker.h"
#include"SortFunction.h"
#include"CheckTool.h"
#include"CheckTool.hpp"


int main()
{
	std::vector<int> tempvec;

	bool flag = getRandomArraySafe(tempvec, 2, 129, 16, 16);
	if (flag)
	{
		CoutAVector(tempvec);
	}

	//	flag=sort_Bubble(tempvec);
	std::vector<int> tempvec1 = tempvec;
	flag = sort_Selection(tempvec1);
	//flag= sort_Insert(tempvec);
	//flag = sort_Merge(tempvec);
	//flag = sort_Quick3(tempvec);
	//flag = sort_Heap(tempvec);
	//flag = sort_Heap(tempvec);
	flag = sort_Bucket(tempvec);
 	//flag = sort_Bucket2(tempvec);
	if (IsSame(tempvec1, tempvec)) 
	{
		std::cout << "true" << std::endl;
	}
	else
	{
		std::cout << "false" << std::endl;
	}
	return 0;
}
