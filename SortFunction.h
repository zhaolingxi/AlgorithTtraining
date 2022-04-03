#pragma once
#include<vector>

//冒泡排序【给值找下标】
//时间复杂度：O(n^2)
//空间复杂度：O（1）
//算法稳定度：稳定
//排序思想：一次选择一个列表中的值（注意是值）
//	将这个值沉底或者冒出，一次确定一个最大值（沉底）或者最小值（冒出）
bool sort_Bubble(std::vector<int> &ioArray);

//选择排序【给下标找值】
//时间复杂度：O(n^2)
//空间复杂度：O（1）
//算法稳定度：无
//排序思想：一次选择一个列表中的下标对应元素（可以从左到右选择）
//	将它假设为最小（或者最大），和剩下的元素比较，从而确定这一个下标对应的
//	元素值
bool sort_Selection(std::vector<int>& ioArray);

//插入排序
//时间复杂度：O(n^2)
//空间复杂度：O（1）
//算法稳定度：稳定
//排序思想：从一个最小的有序数列开始（只有一个元素一定有序）
//	 逐步扩大这个数列，将后纳入的元素作为插入元素
//	 按序比较（小数列有序），给插入元素一个位置
bool sort_Insert(std::vector<int>& ioArray);

//快速排序
bool sort_Quick(std::vector<int>& ioArray);

////归并排序
//bool sort_Merge(std::vector<int>& ioArray);
//
////堆排序
//bool sort_Heap(std::vector<int>& ioArray);


//希尔排序（不重要，一般就存在于课本和考试上）