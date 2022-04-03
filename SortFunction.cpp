#include "SortFunction.h"
#include"MathTool.h"
#include"MathToolcpp.hpp"

//冒泡排序【给值找下标】
//时间复杂度：O(n^2)
//空间复杂度：O（1）
//算法稳定度：稳定
//排序思想：一次选择一个列表中的值（注意是值）
//	将这个值沉底或者冒出，一次确定一个最大值（沉底）或者最小值（冒出）
bool sort_Bubble(std::vector<int>& ioArray)
{
	bool res = false;
	if (ioArray.size()==0) return res;
	for (size_t i = 0; i < ioArray.size(); i++)
	{
		for (size_t j=0; j < (ioArray.size()-i-1); j++)
		{
			if (ioArray[j]> ioArray[j+1])//下沉冒泡
			{
				Swap(ioArray[j], ioArray[j + 1]);
			}
		}
	}
	res = true;
	return res;
}

//选择排序【给下标找值】
//时间复杂度：O(n^2)
//空间复杂度：O（1）
//算法稳定度：无
//排序思想：一次选择一个列表中的下标对应元素（可以从左到右选择）
//	将它假设为最小（或者最大），和剩下的元素比较，从而确定这一个下标对应的
//	元素值
bool sort_Selection(std::vector<int>& ioArray)
{
	bool res = false;
	if (ioArray.size() == 0) return res;
	for (size_t i = 0; i < ioArray.size(); i++)
	{
		for (size_t j = i+1; j < ioArray.size(); j++)
		{
			if (ioArray[i]> ioArray[j])
			{
				Swap(ioArray[i], ioArray[j]);
			}
		}
	}
	res = true;
	return res;
}


//插入排序
//时间复杂度：O(n^2)
//空间复杂度：O（1）
//算法稳定度：稳定
//排序思想：从一个最小的有序数列开始（只有一个元素一定有序）
//	 逐步扩大这个数列，将后纳入的元素作为插入元素
//	 按序比较（小数列有序），给插入元素一个位置
bool sort_Insert(std::vector<int>& ioArray)
{
	bool res = false;
	if (ioArray.size() == 0) return res;
	for (size_t i = 1; i < ioArray.size(); i++)//长度为1的序列不要排序
	{
		for (size_t j = i; j >0; j--)
		{
			if (ioArray[j]<ioArray[j-1])
			{
				Swap(ioArray[j], ioArray[j-1]);
			}
		}
	}
	res = true;
	return res;
}


//快速排序
//时间复杂度：O(nlogn)
//空间复杂度：O（logn）
//算法稳定度：无
//排序思想：使用分区规划的思想
//	先选定一个元素作为分隔符，小于它的划进小于区，大于它的划进大于区
//	然后我们对小于区和大于区再次进行上述的划分操作，直到单个元素不可分为止
//	在最终的算法中，我们掺入随机值来避免最坏情况的发生
bool sort_Quick(std::vector<int>& ioArray)
{
	bool res = false;
	if (ioArray.size() == 0) return res;
	
	res = true;
	return res;
}
