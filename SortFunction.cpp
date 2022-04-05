#include "SortFunction.h"
#include"MathTool.h"
#include"MathToolcpp.hpp"
#include "RandomMaker.h"

//ð�����򡾸�ֵ���±꡿
//ʱ�临�Ӷȣ�O(n^2)
//�ռ临�Ӷȣ�O��1��
//�㷨�ȶ��ȣ��ȶ�
//����˼�룺һ��ѡ��һ���б��е�ֵ��ע����ֵ��
//	�����ֵ���׻���ð����һ��ȷ��һ�����ֵ�����ף�������Сֵ��ð����
bool sort_Bubble(std::vector<int>& ioArray)
{
	bool res = false;
	if (ioArray.size() < 2) return res;
	for (size_t i = 0; i < ioArray.size(); i++)
	{
		for (size_t j=0; j < (ioArray.size()-i-1); j++)
		{
			if (ioArray[j]> ioArray[j+1])//�³�ð��
			{
				Swap(ioArray[j], ioArray[j + 1]);
			}
		}
	}
	res = true;
	return res;
}

//ѡ�����򡾸��±���ֵ��
//ʱ�临�Ӷȣ�O(n^2)
//�ռ临�Ӷȣ�O��1��
//�㷨�ȶ��ȣ���
//����˼�룺һ��ѡ��һ���б��е��±��ӦԪ�أ����Դ�����ѡ��
//	��������Ϊ��С��������󣩣���ʣ�µ�Ԫ�رȽϣ��Ӷ�ȷ����һ���±��Ӧ��
//	Ԫ��ֵ
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


//��������
//ʱ�临�Ӷȣ�O(n^2)
//�ռ临�Ӷȣ�O��1��
//�㷨�ȶ��ȣ��ȶ�
//����˼�룺��һ����С���������п�ʼ��ֻ��һ��Ԫ��һ������
//	 ������������У����������Ԫ����Ϊ����Ԫ��
//	 ����Ƚϣ�С�������򣩣�������Ԫ��һ��λ��
bool sort_Insert(std::vector<int>& ioArray)
{
	bool res = false;
	if (ioArray.size() < 2) return res;
	for (size_t i = 1; i < ioArray.size(); i++)//����Ϊ1�����в�Ҫ����
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


//�鲢����
//ʱ�临�Ӷȣ�O(nlogn)
//�ռ临�Ӷȣ�O��n��
//�㷨�ȶ��ȣ��ȶ�
//����˼�룺ʹ�÷����滮��˼�롾���±���з�����
//	Ĭ�ϻ��ֵĽڵ�ѡΪ�е�
//	һֱ���ֵ�������Ȼ���򣬼�����ֻ��һ������ʱ��
//	ʹ��merge������������������кϲ�Ϊ����Ĵ�����
bool sort_Merge(std::vector<int>& ioArray)
{
	bool res = false;
	if (ioArray.size() <2) return res;
	processMerge(ioArray, 0, (ioArray.size() - 1));
	res = true;
	return res;
}


//��������
//ʱ�临�Ӷȣ�O(nlogn)
//�ռ临�Ӷȣ�O��logn��
//�㷨�ȶ��ȣ���
//����˼�룺ʹ�÷����滮��˼�롾��ֵ���з�����
//	��ѡ��һ��Ԫ����Ϊ�ָ�����С�����Ļ���С�������������Ļ���������
//	1.0�汾�л�Ĭ�Ͻ����һ������Ϊ���ֵ�Ԫ�أ�Ȼ�����ʹ�������ĵ�һ��Ԫ�ؽ�����O(n^2)��
//	2.0�汾�л�Ĭ�Ͻ����һ������Ϊ���ֵ�Ԫ�أ�����Ϊ�������򡢵�������С��������������O(n^2)��
//	3.0�汾�л�������ֵ�����������ķ���(��ԭ���������Ѿ������ú���������֣���û���������)
//	�����֮������ֵ���ƫ�ˣ����־�û�������壬��û�л���һ����
//	�����յ��㷨�У����ǲ������ֵ�����������ķ����������ѡ�񻮷�ֵ
//	���ŵĿռ临�Ӷ�ȡ�������ĵݹ����
//	���ŵ����и��Ӷȶ��������Ľ��
bool sort_Quick3(std::vector<int>& ioArray)
{
	bool res = false;
	if (ioArray.size() <2) return res;
	processQuick3(ioArray, 0, ioArray.size()-1);
	res = true;
	return res;
}

//������
//ʱ�临�Ӷȣ�O(nlogn)
//�ռ临�Ӷȣ�O��1��
//�㷨�ȶ��ȣ���
//	����˼�룺����ʹ���˷��ε�˼�룬ͬʱ�����˶ѵĶ������ṹ
//	������Ϊ����һ������ѻ���С���ѣ�ÿһ�ε�����ṹ�����������С��
//	����ֻ��Ҫ���ϵ�ȥά������ṹ�Ϳ��ԣ�ά������ṹ���ö����нڵ�
//	�������ĸ��ӶȻ�����
bool sort_Heap(std::vector<int>& ioArray)
{
	bool res = false;
	if (ioArray.size() < 2) return res;
	for (size_t i = 0; i < ioArray.size(); i++)
	{
		heapinsert(ioArray,i);//��������
	}
	int heapsize = ioArray.size();
	Swap(ioArray[0], ioArray[--heapsize]);//�Ѹ������һ������������ʱ�Ѿ��Ǵ���ѡ�
	while (heapsize>0)
	{
		heapify(ioArray,0,heapsize);//ÿһ�������³�����Ҫ����Ϊ����һ����׼����
		Swap(ioArray[0], ioArray[--heapsize]);//֮���ٰ����һ�����͸�����
	}
	res = true;
	return res;
}





int processMerge(std::vector<int>& ioArray, int left, int right)
{
	if (left==right) return ioArray[left];//ֱ�����ɲ��Ϊֹ
	int mid = left +((right - left) >> 1);//��ֹ���
	int leftMax = processMerge(ioArray, left, mid);
	int rightMax = processMerge(ioArray,mid+1,right);
	merge(ioArray,left,mid,right);
	return __max(leftMax,rightMax);
}



void processQuick3(std::vector<int>& ioArray, int left, int right)
{
	if (left<right)
	{
		Swap(ioArray[getRandomNum(left, right)],ioArray[right]);//ѡһ������������Ҳ�
		std::vector<int> tempvec;
		tempvec=partition(ioArray,left,right);
		processQuick3(ioArray, left, tempvec[0] - 1);//С������
		processQuick3(ioArray, tempvec[1] +1, right);//��������
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
	while (p1<=mid)//�ұ��Ѿ�������
	{
		tempvec[i++] = ioArray[p1++];
	}
	while (p2<=right)//����Ѿ�������
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
	int less = left - 1;//С�������ұ߽�
	int more = right;//����������߽�
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
	int left = index * 2 + 1;//�������±꣬��2��ʾ����һ��
	while (left<heapsize)//�Լ����к���
	{
		//�Ƚ����Һ��ӵ�ֵ
		int largest = ((left + 1 < heapsize) && (ioArray[left + 1] > ioArray[left])) ? left + 1 : left;
		//�ȽϺ��Ӻ͸���˭�����largest��
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
