//Drew Overgaard
//Comp 53
//Project 5 Sorting Algorithm
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <fstream>

using namespace std;

void fillArray(int[], int);
void SelectionSort(int[], int);
void InsertionSort(int[], int);
void Merge(int[], int, int, int);
void MergeSort(int[], int i, int k);
int Partition(int[], int i, int k);
void Quicksort(int[], int i, int k);
void BubbleSort(int[], int);

int main()
{
	int *numbers;
	int SIZE = 20000;		//20000
	long start;				//Used for the clock function
	long stop;
	ofstream myfile;		//Used to output results to a text file
	myfile.open("SortingData.txt");

	//I used this do while loop just for insertion sort because I was trying to fix it
	do
	{
		numbers = new int[SIZE];
		fillArray(numbers, SIZE);
		start = clock();
		InsertionSort(numbers, SIZE);
		stop = clock();
		cout << "Insertion Sort of " << SIZE << " elements took " << stop - start << " milliseconds." << endl;
		delete[]numbers;
		SIZE = SIZE * 2;
	} while (SIZE <= 640000);

	/*
	//I used this do while to test Quciksort and Mergesort
	do
	{
		numbers = new int[SIZE];
		fillArray(numbers, SIZE);
		start = clock();
		Quicksort(numbers, 0, SIZE - 1);
		//MergeSort(numbers, 0, SIZE);
		stop = clock();
		cout << "Quick Sort of " << SIZE << " elements took " << stop - start << " milliseconds." << endl;
		delete[]numbers;
		SIZE = SIZE * 2;
	} while (SIZE <= 640000);
										//Stop

	//I used this do while loop to test Bubble and Selection
	
	do
	{
		numbers = new int[SIZE];
		fillArray(numbers, SIZE);

		start = clock();
		//BubbleSort(numbers, SIZE);
		//SelectionSort(numbers, SIZE);
		InsertionSort(numbers, SIZE); //---Put sort functions here
		stop = clock();

		//This is here for testing
		/*
		for (int i = 0; i < SIZE; i++)
		{
			cout << numbers[i] << endl;
		}
		//End comment bracket here
		

		cout << "Insertion Sort of " << SIZE << " elements took " << stop - start << " milliseconds." << endl;

		myfile << "Insertion Sort " << SIZE << " elements took " << stop - start << " milliseconds." << endl;

		delete[]numbers;

		SIZE = SIZE * 2;

	} while (SIZE <= 640000);		//640000
	*/


	myfile.close(); //I ended up taking screenshots of the command promt instead of using the file
}

void fillArray(int numbers[], int size)	//Fill the array with random numbers to sort
{
	for (int i = 0; i < size; i++)
	{
		numbers[i] = (rand() % 1001)*(rand() % 1001) + rand();
	}
}

void SelectionSort(int numbers[], int numberSize)
{
	int i = 0;
	int j = 0;
	int indexSmallest = 0;
	int temp = 0;

	for (i = 0; i < numberSize; ++i)
	{
		indexSmallest = i;
		for (j = i + 1; j < numberSize; ++j)
		{
			if (numbers[j] < numbers[indexSmallest])
			{
				indexSmallest = j;
			}
		}

		temp = numbers[i];
		numbers[i] = numbers[indexSmallest];
		numbers[indexSmallest] = temp;
	}
}

void InsertionSort(int numbers[], int numberSize)
{
	int j;
	int temp = 0;

	for (int i = 1; i < numberSize; ++i)
	{
		j = i;

		while (j > 0 && numbers[j] < numbers[j - 1])
		{
			temp = numbers[j];
			numbers[j] = numbers[j - 1];
			numbers[j - 1] = temp;
			--j;
			//cout << "Hello?" << endl;
		}
	}
	return;
}

void BubbleSort(int numbers[], int numberSize)
{
	for (int i = 0; i < numberSize; ++i)
	{
		for (int j = 0; j < numberSize - i - 1; ++j)
		{
			if (numbers[j] > numbers[j + 1])
			{
				int temp = numbers[j];
				numbers[j] = numbers[j + 1];
				numbers[j + 1] = temp;
			}
		}
	}
}


void Merge(int numbers[], int i, int j, int k)
{
	int mergedSize = k - i + 1;
	int *mergedNumbers;				//Need to declare mergedNumbers as a dynamically allocated array
	mergedNumbers = new int[mergedSize];
	//int mergedNumbers[mergedSize];  //--------------------FIXME
	//int mergedNumbers[5];
	int mergePos = 0;
	int leftPos = 0;
	int rightPos = 0;

	leftPos = i;
	rightPos = j + 1;

	while (leftPos <= j && rightPos <= k)
	{
		if (numbers[leftPos] < numbers[rightPos])
		{
			mergedNumbers[mergePos] = numbers[leftPos];
			++leftPos;
		}
		else
		{
			mergedNumbers[mergePos] = numbers[rightPos];
			++rightPos;
		}
		++mergePos;
	}

	while (leftPos <= j)
	{
		mergedNumbers[mergePos] = numbers[leftPos];
		++leftPos;
		++mergePos;
	}

	while (rightPos <= k)
	{
		mergedNumbers[mergePos] = numbers[rightPos];
		++rightPos;
		++mergePos;
	}

	for (mergePos = 0; mergePos < mergedSize; ++mergePos)
	{
		numbers[i + mergePos] = mergedNumbers[mergePos];
	}
}

void MergeSort(int numbers[], int i, int k)
{
	int j = 0;

	if (i < k)
	{
		j = (i + k) / 2;
		MergeSort(numbers, i, j);
		MergeSort(numbers, j + 1, k);

		Merge(numbers, i, j, k);
	}
}

int Partition(int numbers[], int i, int k)
{
	int l = 0;
	int h = 0;
	int midpoint = 0;
	int pivot = 0;
	int temp = 0;
	bool done = false;

	midpoint = i + (k - i) / 2;
	pivot = numbers[midpoint];

	l = i;
	h = k;

	while (!done)
	{
		while (numbers[l] < pivot)
		{
			++l;
		}

		while (pivot < numbers[h])
		{
			--h;
		}

		if (l >= h)
		{
			done = true;
		}
		else
		{
			temp = numbers[l];
			numbers[l] = numbers[h];
			numbers[h] = temp;

			++l;
			--h;
		}
	}
	return h;
}

void Quicksort(int numbers[], int i, int k)
{
	int j = 0;

	if (i >= k)
	{
		return;
	}

	j = Partition(numbers, i, k);

	Quicksort(numbers, i, j);	//Sort the lower section

	Quicksort(numbers, j + 1, k);		//Sort the high section

	//cout << "We got here!" << endl;

	return;
}