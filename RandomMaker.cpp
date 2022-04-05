#include "RandomMaker.h"
#include<ctime>
#include<cstdlib>
#include <random>

bool getRandomArrayOld(std::vector<int>& ioArray, int minValue, int maxValue,
	int minLength, int maxLength)
{
	bool res = false;
	if (minValue> maxValue || minLength > maxLength || minLength <0 ||
		(maxValue- minValue)>32757 ||(maxLength - minLength)>=32757)//���������ֵ����Ҫ��
	{
		return res;
	}
	ioArray.clear();
	srand(time(nullptr));//�������
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
	if (minValue > maxValue || minLength > maxLength || minLength < 0)//���������ֵ����Ҫ��
	{
		return res;
	}
	ioArray.clear();
	std::random_device rd;//��������
	std::mt19937 gen(rd());//÷ɭ����
	std::uniform_int_distribution<int> arraysizes(minLength, maxLength);//���ȷֲ�
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
	std::random_device rd;//��������
	std::mt19937 gen(rd());//÷ɭ����
	std::uniform_int_distribution<int> array(minValue, maxValue);
	return array(gen);
}
