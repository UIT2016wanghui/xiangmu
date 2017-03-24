/*************************************************************************
> File Name: quicksort.cpp
> Author: wh
> Description: quick sort
> Created Time: 
************************************************************************/
#include<iostream>
using namespace std;
void swap(int &a, int &b)//a b���������a[i]��a[j]
{
	int tmp;
	tmp = a;
	a = b;
	b = tmp;
}
int partion1(int a[], int left, int right)
{

	int tmp = a[left];//�ؼ�Ԫ��tmp
	while (left < right)
	{
		while ((tmp <= a[right]) && (left < right))
			right--;//���������ҵ�һ���ȹؼ�Ԫ��С
		a[left] = a[right];
		while ((tmp > a[left]) && (left < right))
			left++;//���������ҵ�һ���ȹؼ�Ԫ�ش�
		a[right] = a[left];
	}
	a[left] = tmp;//��ߵ�Ԫ��Ϊ�ؼ�Ԫ��
	return left;//������ߵ����
}
int partion2(int a[], int left, int right)
{
	int tmp = a[left];
	int i = left;

	for (int j = left + 1; j <= right; j++)
	{
		if (a[j]<tmp)
		{
			i++;
			swap(a[i], a[j]);
		}
	}
	swap(a[left], a[i]);
	return i;
}

//���������һ�ַ���
void quicksort1(int a[], int left, int right)
{
	int p;
	if (left< right)
	{
		p = partion1(a, left, right);//���»��ֻ���
		quicksort1(a, left, p - 1);//��߿�������
		quicksort1(a, p + 1, right);//�ұ߿�������
	}
}
//��������ڶ��ַ���
void quicksort2(int a[], int left, int right)
{
	int p;
	if (left< right)
	{
		p = partion2(a, left, right);
		quicksort2(a, left, p - 1);
		quicksort2(a, p + 1, right);
	}
}

int main(int arg, char *agv[])
{
	int i;
	int a[] = { 3, 6, 9, 1, 0, 16 };
	cout << "befor sort is :" << endl;
	for ( i = 0; i<6; i++)//���ԭʼ����
		cout << a[i] << " ";
	cout << endl;
	/*1************************************/
	quicksort1(a, 0, 5);//���ú���quicksort1
	cout << "�������򷽷�1 :" << endl;
	for (i = 0; i<6; i++)
		cout << a[i] << " ";
	cout << endl;
	/*2*****************************************/
	cout << "�������򷽷�2 :" << endl;
	quicksort2(a, 0, 5);
	for (int i = 0; i<6; i++)
		cout << a[i] << " ";
	cout << endl;

	return 0;
}
