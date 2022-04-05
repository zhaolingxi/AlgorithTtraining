#pragma once
#include<vector>

//使用rand取余的方式提供随机数组，该数组为int,
//param：min\max value为值范围；min\max length为长度
bool getRandomArrayOld(std::vector<int> &ioArray,int minValue,int maxValue,
	int minLength,int maxLength);

//使用梅森引擎方式提供随机数组，该数组为int
//param：min\max value为值范围；min\max length为长度
bool getRandomArraySafe(std::vector<int>& ioArray, int minValue, int maxValue,
	int minLength, int maxLength);

//获取一个随机数
int getRandomNum(int minValue, int maxValue);