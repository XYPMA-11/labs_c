#include "pch.h"
#include <iostream>
#include <ctime>
#include <locale>

using namespace std;


int Search(int* array, int n, int value)
{
	for (int i = 0; i <  n; i++)
	{
		if (array[i] == value)
		{
			return array[i];
		}
			
	}
	return NULL;
}

void QuickSort(int* array, int first, int last)
{
	int left = first;
	int right = last - 1;
	int pivot = left;
	int temp = 0;
	
	do
	{
		while (array[right] > array[pivot])
		{
			right--;
		}

		while (array[left] < array[pivot])
		{
			left++;
		}

		if (left <= right)
		{
			temp = array[left];
			array[left] = array[right];
			array[right] = temp;
			left++;
			right--;
		}
	} while (left <= right);

	if (right > 0)
	{
		QuickSort(array, first, right + 1 );
	}
	if (left < last)
	{
		QuickSort(&array[left], first, last - left);
	}
	
}

void QuickSortNonRecursion(int* array, int first, int last)
{
	const int size = 100;
	int firstStack[size], lastStack[size];
	int posStack = 1;
	firstStack[posStack] = first;
	lastStack[posStack] = last;
	while (posStack != 0)
	{
		first = firstStack[posStack];
		last = lastStack[posStack];
		posStack--;
		while (first < last)
		{
			int firstBorder = first;
			int lastBorder = last;
			int mediumIndex = (first + last) / 2;
			int mediumElement = array[mediumIndex];
			while (firstBorder <= lastBorder)
			{
				while (array[firstBorder] < mediumElement)
					firstBorder++;
				while (array[lastBorder] > mediumElement)
					lastBorder--;
				if (firstBorder <= lastBorder)
				{
					int temp = array[firstBorder];
					array[firstBorder] = array[lastBorder];
					array[lastBorder] = temp;
					firstBorder++;
					lastBorder--;

				}
			}
			if (firstBorder < mediumIndex)
			{
				if (firstBorder < last)
				{
					posStack++;
					firstStack[posStack] = firstBorder;
					lastStack[posStack] = last;
				}
				last = lastBorder;
			}
			else
			{
				if (lastBorder > first)
				{
					posStack++;
					firstStack[posStack] = first;
					lastStack[posStack] = lastBorder;
				}
				first = firstBorder;
			}
		}
	}
}

int BSearch(int* array, int value, int left, int right)
{
	while (left <= right)
	{
		int medium = left + (right - left) / 2;
		if (value < array[medium])
		{
			right = medium - 1;
		}
		else if (value > array[medium])
		{
			left = medium + 1;
		}
		else return medium;
	}
	return -1;

}

int RBSearch( int* array, int value, int left, int right)
{
	if (right < left) return -1;
	int midpoint = (left + right) / 2;
	if (array[midpoint] > value) return RBSearch(array, value, left, midpoint - 1);
	if (array[midpoint] < value) return RBSearch(array, value, midpoint + 1, right);
	if (value == array[midpoint]) return midpoint;
	return -1;
}

void PrintArray(int* array, int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << array[i] << " ";
	}
}

int main()
{
	setlocale(LC_ALL, "Russian");
	std::clock_t start;
	double duration;

	int firstElement = 0;
	int LastElement = 50;
	int findElement = 5;

	int n = 100;
	int N = 10000;
	int* array = new int[n];
	int* Array = new int[N];

	srand(time(nullptr));

	for (int i = 0; i < n; i++)
	{
		int temp = rand() % 21 - 10;
		array[i] = temp;
	}

	for (int i = 0; i < N; i++)
	{
		Array[i] = rand() % 2001 - 1000;
	}
	//1

	cout << "Поиск в неотсортированном массиве: " << Search(Array, N, 20) << endl;

	//2

	cout << "Неотсортированный массив: " << endl;
	PrintArray(array, LastElement);
	QuickSort(array, firstElement, LastElement);
	cout << "\nОтсортированный массив: " << endl;
	PrintArray(array, LastElement);

	//3

	if (BSearch(array, findElement, firstElement, LastElement) != -1)
	{
		cout << "\nПозиция " << findElement << " в массиве: " << BSearch(array, findElement, firstElement, LastElement) << endl;
	}
	else cout << "\nЭлемент не найден!" << endl;

	//4

	start = std::clock();
	for (int i = 0; i < 10000; i++)
	{
		Search(Array, N, 20);
	}
	duration = (std::clock() - start) / (double)CLOCKS_PER_SEC;
	cout << "Скорость поиска в неотсортированном массиве: " <<  duration << endl;

	QuickSort(Array, 0, 10000);
	
	start = clock();
	for (int i = 0; i < 10000; i++)
	{
		BSearch(Array, 5, 0, 10000);
	}
	duration = (std::clock() - start) / (double)CLOCKS_PER_SEC;
	cout << "Скорость поиска в отсортированном массиве: " << duration << endl;
	return 0;
}


