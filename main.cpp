#include<iostream>
#include "RandomMaker.h"


int main()
{
	std::vector<int> tempvec;

	bool flag= getRandomArraySafe(tempvec,2,29,45,45);
	if (flag)
	{
		for (size_t i = 0; i < tempvec.size(); i++)
		{
			std::cout << tempvec[i] << std::endl;
		}
		
	}
	
	return 0;
}