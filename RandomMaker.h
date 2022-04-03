#pragma once
#include<vector>

bool getRandomArrayOld(std::vector<int> &ioArray,int minValue,int maxValue,
	int minLength,int maxLength);

bool getRandomArraySafe(std::vector<int>& ioArray, int minValue, int maxValue,
	int minLength, int maxLength);