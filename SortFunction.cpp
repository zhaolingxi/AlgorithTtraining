#include "SortFunction.h"
#include"MathTool.h"
#include"MathToolcpp.hpp"

//ð�����򡾸�ֵ���±꡿
//ʱ�临�Ӷȣ�O(n^2)
//�ռ临�Ӷȣ�O��1��
//�㷨�ȶ��ȣ��ȶ�
//����˼�룺һ��ѡ��һ���б��е�ֵ��ע����ֵ��
//	�����ֵ���׻���ð����һ��ȷ��һ�����ֵ�����ף�������Сֵ��ð����
bool sort_Bubble(std::vector<int>& ioArray)
{
	bool res = false;
	if (ioArray.size()==0) return res;
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
	if (ioArray.size() == 0) return res;
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


//��������
//ʱ�临�Ӷȣ�O(nlogn)
//�ռ临�Ӷȣ�O��logn��
//�㷨�ȶ��ȣ���
//����˼�룺ʹ�÷����滮��˼��
//	��ѡ��һ��Ԫ����Ϊ�ָ�����С�����Ļ���С�������������Ļ���������
//	Ȼ�����Ƕ�С�����ʹ������ٴν��������Ļ��ֲ�����ֱ������Ԫ�ز��ɷ�Ϊֹ
//	�����յ��㷨�У����ǲ������ֵ�����������ķ���
bool sort_Quick(std::vector<int>& ioArray)
{
	bool res = false;
	if (ioArray.size() == 0) return res;
	
	res = true;
	return res;
}
