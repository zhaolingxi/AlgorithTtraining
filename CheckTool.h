#pragma once
#include<vector>

//cout nums or t
template <typename T>
void CoutAVector(std::vector<T>& oArray);

//cout nums and pointer address
template <typename T>
void CoutAVectorwithAddress(std::vector<T>& oArray);

//两个数列是否相等
template <typename T>
bool IsSame(std::vector<T>& ioArray1, std::vector<T>& ioArray2);