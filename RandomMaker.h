#pragma once
#include<vector>

//ʹ��randȡ��ķ�ʽ�ṩ������飬������Ϊint,
//param��min\max valueΪֵ��Χ��min\max lengthΪ����
bool getRandomArrayOld(std::vector<int> &ioArray,int minValue,int maxValue,
	int minLength,int maxLength);

//ʹ��÷ɭ���淽ʽ�ṩ������飬������Ϊint
//param��min\max valueΪֵ��Χ��min\max lengthΪ����
bool getRandomArraySafe(std::vector<int>& ioArray, int minValue, int maxValue,
	int minLength, int maxLength);