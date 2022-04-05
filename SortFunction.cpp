#include "SortFunction.h"
#include"MathTool.h"
#include"MathToolcpp.hpp"
#include "RandomMaker.h"

//冒泡排序【给值找下标】
//时间复杂度：O(n^2)
//空间复杂度：O（1）
//算法稳定度：稳定
//排序思想：一次选择一个列表中的值（注意是值）
//	将这个值沉底或者冒出，一次确定一个最大值（沉底）或者最小值（冒出）
bool sort_Bubble(std::vector<int>& ioArray)
{
	bool res = false;
	if (ioArray.size() < 2) return res;
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
	if (ioArray.size() < 2) return res;
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
	if (ioArray.size() < 2) return res;
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


//归并排序
//时间复杂度：O(nlogn)
//空间复杂度：O（n）
//算法稳定度：稳定
//排序思想：使用分区规划的思想【按下标进行分区】
//	默认划分的节点选为中点
//	一直划分到数组自然有序，即数组只有一个数的时候
//	使用merge方法，将有序的子数列合并为有序的大数列
bool sort_Merge(std::vector<int>& ioArray)
{
	bool res = false;
	if (ioArray.size() <2) return res;
	processMerge(ioArray, 0, (ioArray.size() - 1));
	res = true;
	return res;
}


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
//	快排的空间复杂度取决于它的递归层数
//	快排的所有复杂度都是期望的结果
bool sort_Quick3(std::vector<int>& ioArray)
{
	bool res = false;
	if (ioArray.size() <2) return res;
	processQuick3(ioArray, 0, ioArray.size()-1);
	res = true;
	return res;
}

//堆排序
//时间复杂度：O(nlogn)
//空间复杂度：O（1）
//算法稳定度：无
//	排序思想：还是使用了分治的思想，同时利用了堆的二叉树结构
//	我们人为构建一个大根堆或者小根堆，每一次调整完结构根就是最大（最小）
//	我们只需要不断的去维护这个结构就可以，维护这个结构不用动所有节点
//	所以它的复杂度还可以
bool sort_Heap(std::vector<int>& ioArray)
{
	bool res = false;
	if (ioArray.size() < 2) return res;
	for (size_t i = 0; i < ioArray.size(); i++)
	{
		heapinsert(ioArray,i);//整体大根堆
	}
	int heapsize = ioArray.size();
	Swap(ioArray[0], ioArray[--heapsize]);//把根和最后一个数交换【此时已经是大根堆】
	while (heapsize>0)
	{
		heapify(ioArray,0,heapsize);//每一个数向下沉【主要就是为了下一步做准备】
		Swap(ioArray[0], ioArray[--heapsize]);//之后再把最后一个数和根交换
	}
	res = true;
	return res;
}





int processMerge(std::vector<int>& ioArray, int left, int right)
{
	if (left==right) return ioArray[left];//直到不可拆分为止
	int mid = left +((right - left) >> 1);//防止溢出
	int leftMax = processMerge(ioArray, left, mid);
	int rightMax = processMerge(ioArray,mid+1,right);
	merge(ioArray,left,mid,right);
	return __max(leftMax,rightMax);
}



void processQuick3(std::vector<int>& ioArray, int left, int right)
{
	if (left<right)
	{
		Swap(ioArray[getRandomNum(left, right)],ioArray[right]);//选一个随机数放在右侧
		std::vector<int> tempvec;
		tempvec=partition(ioArray,left,right);
		processQuick3(ioArray, left, tempvec[0] - 1);//小于区域
		processQuick3(ioArray, tempvec[1] +1, right);//大于区域
	}
}

void merge(std::vector<int>& ioArray, int left, int mid, int right)
{
	std::vector<int> tempvec(right- left+1);
	int i = 0;
	int p1 = left;
	int p2 = mid + 1;
	while (p1<=mid && p2<=right)
	{
		tempvec[i++]=(ioArray[p1]<=ioArray[p2]?ioArray[p1++]:ioArray[p2++]);
	}
	while (p1<=mid)//右边已经跑完了
	{
		tempvec[i++] = ioArray[p1++];
	}
	while (p2<=right)//左边已经跑完了
	{
		tempvec[i++] = ioArray[p2++];
	}
	for (size_t i = 0; i < tempvec.size(); i++)
	{
		ioArray[left+i] = tempvec[i];
	}
}

std::vector<int> partition(std::vector<int>& ioArray, int left, int right)
{
	int less = left - 1;//小于区域右边界
	int more = right;//大于区域左边界
	while (left<more)
	{
		if (ioArray[left]< ioArray[right])//ioArray[right] is base number
		{
			Swap(ioArray[++less],ioArray[left++]);
		}
		else if (ioArray[left] > ioArray[right])
		{
			Swap(ioArray[--more], ioArray[left]);
		}
		else
		{
			left++;
		}
	}
	Swap(ioArray[more],ioArray[right]);
	return (std::vector<int>{ less+1,more });
}

void heapify(std::vector<int>& ioArray, int index, int heapsize)
{
	int left = index * 2 + 1;//左子树下标，乘2表示向下一层
	while (left<heapsize)//自己还有孩子
	{
		//比较左右孩子的值
		int largest = ((left + 1 < heapsize) && (ioArray[left + 1] > ioArray[left])) ? left + 1 : left;
		//比较孩子和父，谁配得上largest、
		largest = ioArray[largest] > ioArray[index] ? largest : index;
		if (largest==index)
		{
			break;
		}
		Swap(ioArray[largest], ioArray[index]);
		index = largest;
		left= index * 2 + 1;
	}
}

void heapinsert(std::vector<int>& ioArray, int index)
{
	while (ioArray[index]>ioArray[(index-1)/2])
	{
		Swap(ioArray[index], ioArray[(index - 1) / 2]);
		index = (index - 1) / 2;
	}
}
