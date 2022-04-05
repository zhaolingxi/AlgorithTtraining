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

//归并排序
//时间复杂度：O(nlogn)
//空间复杂度：O（n）
//算法稳定度：稳定
//排序思想：使用分区规划的思想【按下标进行分区】
//	默认划分的节点选为中点
//	一直划分到数组自然有序，即数组只有一个数的时候
//	使用merge方法，将有序的子数列合并为有序的大数列
bool sort_Merge(std::vector<int>& ioArray);

//快速排序
//时间复杂度：O(nlogn)
//空间复杂度：O（logn）
//算法稳定度：无
//排序思想：使用分区规划的思想【按值进行分区】
//	先选定一个元素作为分隔符，小于它的划进小于区，大于它的划进大于区
//	1.0版本中会默认将最后一个数作为划分的元素，然后将它和大于区域的第一个元素交换【O(n^2)】
//	2.0版本中会默认将最后一个数作为划分的元素，划分为大于区域、等于区域、小于区域三个区域【O(n^2)】
//	3.0版本中会加入随机值，避免最坏情况的发生(当原来的数列已经有序，拿后面的数划分，就没有最大区域)
//	简而言之，划分值打的偏了，划分就没有了意义，和没有划分一样了
//	在最终的算法中，我们掺入随机值来避免最坏情况的发生，即随机选择划分值
bool sort_Quick3(std::vector<int>& ioArray);


//堆排序
//时间复杂度：O(nlogn)
//空间复杂度：O（1）
//算法稳定度：无
//	排序思想：还是使用了分治的思想，同时利用了堆的二叉树结构
//	我们人为构建一个大根堆或者小根堆，每一次调整完结构根就是最大（最小）
//	我们只需要不断的去维护这个结构就可以，维护这个结构不用动所有节点
//	所以它的复杂度还可以
bool sort_Heap(std::vector<int>& ioArray);


//希尔排序（不重要，一般就存在于课本和考试上）

//归并排序辅助函数
int processMerge(std::vector<int>& ioArray,int left,int right);
void merge(std::vector<int>& ioArray, int left, int mid, int right);

//快排辅助函数
void processQuick3(std::vector<int>& ioArray, int left, int right);
//干两件事情：确定边界、子数列排序
std::vector<int> partition(std::vector<int> &ioArray, int left, int right);


//维护堆结构（向下）
void heapify(std::vector<int>& ioArray, int index, int heapsize);

//维护堆结构（向上）
void heapinsert(std::vector<int>& ioArray, int index);