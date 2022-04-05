#include "RandomMaker.h"
#include<ctime>
#include<cstdlib>
#include <random>

bool getRandomArrayOld(std::vector<int>& ioArray, int minValue, int maxValue,
	int minLength, int maxLength)
{
	bool res = false;
	if (minValue> maxValue || minLength > maxLength || minLength <0 ||
		(maxValue- minValue)>32757 ||(maxLength - minLength)>=32757)//不符合随机值发生要求
	{
		return res;
	}
	ioArray.clear();
	srand(time(nullptr));//随机种子
	int arraysize = ((rand() % (maxLength - minLength +1))+ minLength);
	int arrayvalue;
	while (arraysize> ioArray.size())
	{
		arrayvalue = ((rand() % (maxValue - minValue + 1)) + minValue);
		ioArray.emplace_back(arrayvalue);
	}
	res = true;
	return res;
}

bool getRandomArraySafe(std::vector<int>& ioArray, int minValue, int maxValue, 
	int minLength, int maxLength)
{
	bool res = false;
	if (minValue > maxValue || minLength > maxLength || minLength < 0)//不符合随机值发生要求
	{
		return res;
	}
	ioArray.clear();
	std::random_device rd;//产生种子
	std::mt19937 gen(rd());//梅森引擎
	std::uniform_int_distribution<int> arraysizes(minLength, maxLength);//均匀分布
	std::uniform_int_distribution<int> arrayvalues(minValue, maxValue);
	int arraysize = arraysizes(gen);
	int arrayvalue;
	while (arraysize > ioArray.size())
	{
		arrayvalue = arrayvalues(gen);
		ioArray.emplace_back(arrayvalue);
	}
	res = true;
	return res;
}

int getRandomNum(int minValue, int maxValue)
{
	std::random_device rd;//产生种子
	std::mt19937 gen(rd());//梅森引擎
	std::uniform_int_distribution<int> array(minValue, maxValue);
	return array(gen);
}
