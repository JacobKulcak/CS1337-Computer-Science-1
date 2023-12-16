#include <iomanip>
#include <iostream>
#include <vector>
#include <string>
#include <cctype>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <string.h>


using namespace std;


void showArray(int data[], int length)
{
	cout << "[";
	for (int loop = 0; loop < length; loop++)
	{
		cout << data[loop];
		cout << "][";
	}
	cout << "]";
}

int linearSearchTrace(int arr[], int size, int value)
{
	int index = 0;      // Used as a subscript to search the array
	int position = -1;  // To record the position of search value
	bool found = false; // Flag to indicate if value was found



	while (index < size && !found)
	{
		cout << index << ",";
		if (arr[index] == value) // If the value is found 
		{
			found = true; // Set the flag 
			position = index; // Record the value's subscript
		}

		index++; // Go to the next element
	}
	cout << endl;

	return position; // Return the position, or -1
}



int binarySearchTrace(int array[], int size, int value)
{
	int first = 0,         // First array element
		last = size - 1,       // Last array element
		middle,                // Mid point of search
		position = -1;         // Position of search value
	bool found = false;    // Flag



	while (!found && first <= last)
	{

		middle = (first + last) / 2;     // Calculate mid point
		cout << middle << ",";
		if (array[middle] == value)      // If value is found at mid
		{
			found = true;
			position = middle;
		}
		else if (array[middle] > value)  // If value is in lower half
			last = middle - 1;
		else
			first = middle + 1;           // If value is in upper half



	}
	cout << endl;

	return position;
}


//***************************************************
// The swap function swaps a and b in memory.       *
//***************************************************
void swap(int& a, int& b)
{
	int temp = a;
	a = b;
	b = temp;
}

//********************************************************************
// The selectionSort function sorts an int array in ascending order. *
//********************************************************************
void selectionSortTrace(int array[], int size)
{
	int minIndex, minValue;
	cout << "Begin" << endl;
	showArray(array, size);
	cout << endl;
	for (int start = 0; start < (size - 1); start++)
	{
		minIndex = start;
		minValue = array[start];
		for (int index = start + 1; index < size; index++)
		{
			showArray(array, size);
			cout << "==>";

			if (array[index] < minValue)
			{
				minValue = array[index];
				minIndex = index;
			}

			showArray(array, size);
			cout << endl;
		}
		swap(array[minIndex], array[start]);
	}
	cout << "End" << endl;
	showArray(array, size);
	cout << endl;
}

//*****************************************************************
// The bubbleSort function sorts an int array in ascending order. 
//****************************************************************
void bubbleSortTrace(int array[], int size)
{
	int maxElement;
	int index;

	cout << "Begin" << endl;
	showArray(array, size);
	cout << endl;
	for (maxElement = size - 1; maxElement > 0; maxElement--)
	{

		for (index = 0; index < maxElement; index++)
		{
			showArray(array, size);
			cout << "==>";

			if (array[index] > array[index + 1])
			{
				swap(array[index], array[index + 1]);
			}

			showArray(array, size);
			cout << endl;
		}

	}
	cout << "End" << endl;
	showArray(array, size);
	cout << endl;
}




void sample6()
{
	int data1[] = { 5, 11, 14, 10, 7, 420, 99, 23, 500, 69 };

	cout << "Bubble Sort" << endl;
	bubbleSortTrace(data1, 10);
	cout << endl << endl;
}

void sample7()
{
	cout << "Selection Sort" << endl;
	int data2[] = { 2147483647, 72, 2, 2, 15, 6, 312, 2020, 8007, 11,7 };
	selectionSortTrace(data2, 11);
	cout << endl << endl;
}

void sample8()
{
	cout << "Linear Search" << endl;

	int data3[] = { 83, 56, 0, 5, 1, 16, 69, 42, 21, 2021, -9 };
	int result1 = 0;

	result1 = linearSearchTrace(data3, 11, 69);
	cout << "69 is at " << result1 << endl;
	result1 = linearSearchTrace(data3, 11, 1);
	cout << "1 is at " << result1 << endl;
	result1 = linearSearchTrace(data3, 11, -9);
	cout << "-9 is at " << result1 << endl;

	cout << endl << endl;
}

void sample9()
{
	cout << "Binary Search" << endl;

	int data4[] = { 13, 6, 9, 29, 17 ,40, 101,52,69,616,50 };
	int result2 = 0;

	selectionSortTrace(data4, 11);

	result2 = binarySearchTrace(data4, 11, 101);
	cout << "101 is at " << result2 << endl;
	result2 = binarySearchTrace(data4, 11, 52);
	cout << "52 is at " << result2 << endl;
	result2 = binarySearchTrace(data4, 11, 21);
	cout << "21 is at " << result2 << endl;
	result2 = binarySearchTrace(data4, 11, 616);
	cout << "616 is at " << result2 << endl;

	cout << endl << endl;

}

void sample10() {
	fstream Jack("Sparrow.txt");
	Jack.close();
}

void sample11() {
	ofstream outputFile("Data.txt");
	outputFile.close();
	ifstream inputFile("Data.txt");
	//Read data
	inputFile.close();
}


int main()
{
	sample10();
	return 0;
}