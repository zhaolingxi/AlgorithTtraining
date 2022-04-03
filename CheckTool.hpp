#include"CheckTool.h"
#include<iostream>
template<typename T>
inline void CoutAVector(std::vector<T>& oArray)
{
	for (size_t i = 0; i < oArray.size(); i++)
	{
		std::cout << oArray[i] << " ";
	}
	std::cout << std::endl;
}

template<typename T>
inline void CoutAVectorwithAddress(std::vector<T>& oArray)
{
	for (size_t i = 0; i < oArray.size(); i++)
	{
		std::cout <<"nums:" << oArray[i] << " " << "Address: " << &oArray[i];
	}
	std::cout << std::endl;
}

template<typename T>
inline bool IsSame(std::vector<T>& ioArray1, std::vector<T>& ioArray2)
{
	bool res = true;
	if (ioArray1.size() != ioArray2.size()) return false;
	for (size_t i = 0; i < ioArray1.size(); i++)
	{
		if (ioArray1[i] != ioArray2[i])
		{
			res = false;
			break;
		}
	}
	return res;
}
