/*************************************************************************
> File Name: quicksort.cpp
> Author: wh
> Description: quick sort
> Created Time: 
************************************************************************/
#include<iostream>
using namespace std;
void swap(int &a, int &b)//a b互换下面的a[i]和a[j]
{
	int tmp;
	tmp = a;
	a = b;
	b = tmp;
}
int partion1(int a[], int left, int right)
{

	int tmp = a[left];//关键元素tmp
	while (left < right)
	{
		while ((tmp <= a[right]) && (left < right))
			right--;//从右向左找第一个比关键元素小
		a[left] = a[right];
		while ((tmp > a[left]) && (left < right))
			left++;//从左向右找第一个比关键元素大
		a[right] = a[left];
	}
	a[left] = tmp;//左边的元素为关键元素
	return left;//返回左边的序号
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

//快速排序第一种方法
void quicksort1(int a[], int left, int right)
{
	int p;
	if (left< right)
	{
		p = partion1(a, left, right);//重新划分划分
		quicksort1(a, left, p - 1);//左边快速排序
		quicksort1(a, p + 1, right);//右边快速排序
	}
}
//快速排序第二种方法
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
	for ( i = 0; i<6; i++)//输出原始数据
		cout << a[i] << " ";
	cout << endl;
	/*1************************************/
	quicksort1(a, 0, 5);//调用函数quicksort1
	cout << "快速排序方法1 :" << endl;
	for (i = 0; i<6; i++)
		cout << a[i] << " ";
	cout << endl;
	/*2*****************************************/
	cout << "快速排序方法2 :" << endl;
	quicksort2(a, 0, 5);
	for (int i = 0; i<6; i++)
		cout << a[i] << " ";
	cout << endl;

	return 0;
}
