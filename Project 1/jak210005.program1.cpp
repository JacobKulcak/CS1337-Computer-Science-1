//Made using Microsoft Visual Studio 2022 Community on an ASUS Laptop running Windows 11//

#include <iostream>
#include <iomanip>
#include <math.h>
#include <time.h>
using namespace std;

void showArray(int arr[], int size) {
	for (int i = 0; i < size; i++) {
		cout << "Array[" << i << "] = " << arr[i] << endl;
	}
}

int linearSearch(int arr[], int size, int value)
{
	int index = 0;      // Used as a subscript to search the array
	int position = -1;  // To record the position of search value
	bool found = false; // Flag to indicate if value was found



	while (index < size && !found)
	{
		if (arr[index] == value) // If the value is found
		{
			found = true; // Set the flag
			position = index; // Record the value's subscript
		}

		index++; // Go to the next element
	}

	return position; // Return the position, or -1
}

int binarySearch(int array[], int size, int value)
{
	int first = 0,         // First array element
		last = size - 1,       // Last array element
		middle,                // Mid point of search
		position = -1;         // Position of search value
	bool found = false;    // Flag



	while (!found && first <= last)
	{

		middle = (first + last) / 2;     // Calculate mid point
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


	return position;
}

int getTarget(int arr[], int size) {
	return arr[(rand() % size)];
}

void fillArray(int intArr[], int intArrSize, bool boolArr[], int boolArrSize) {

	for (int i = 0; i < boolArrSize; i++) {
		boolArr[i] = false;
	}

	int loop = 0;
	int val;
	
	while (loop < intArrSize) {
		val = rand() % boolArrSize;
		if (boolArr[val] == false) {
			intArr[loop] = val;
			boolArr[val] = true;
			loop++;
		}
	}

}

void testLinearSearch(int arr[], int size){
	clock_t start = clock();
	int target = 0;
	int index = 0;

	for (int i = 0; i <= 1000000; i++) {
		target = getTarget(arr, size);
		index = linearSearch(arr, size, target);
	}

	clock_t stop = clock();

	double time = CLOCKS_PER_SEC;
	stop = (stop - start) / time * 1000;
	cout << "Elapsed = " << stop << endl;
}

void testBinarySearch(int arr[], int size) {
	clock_t start = clock();
	int target = 0;
	int index = 0;

	for (int i = 0; i <= 1000000; i++) {
		target = getTarget(arr, size);
		index = binarySearch(arr, size, target);
	}

	clock_t stop = clock();
	
	double time = CLOCKS_PER_SEC;
	stop = (stop - start) / time * 1000;
	cout << "Elapsed = " << stop << endl;
}

void bubbleSort(int array[], int size)
{
	int maxElement;
	int index;

	for (maxElement = size - 1; maxElement > 0; maxElement--)
	{
		for (index = 0; index < maxElement; index++)
		{
			if (array[index] > array[index + 1])
			{
				swap(array[index], array[index + 1]);
			}
		}
	}
}

void selectionSort(int array[], int size)
{
	int minIndex, minValue;

	for (int start = 0; start < (size - 1); start++)
	{
		minIndex = start;
		minValue = array[start];
		for (int index = start + 1; index < size; index++)
		{
			if (array[index] < minValue)
			{
				minValue = array[index];
				minIndex = index;
			}
		}
		swap(array[minIndex], array[start]);
	}
}

void swap(int& a, int& b)
{
	int temp = a;
	a = b;
	b = temp;
}

int main(){
	int  result, targetVal, intArr[10], intArr2[1000];
	bool boolArr[100], boolArr2[10000];

	int melencolia[4][4] = { {16,3,2,13}, {5,10,11,8}, {9,6,7,12}, {4,15,14,1} }; //Bonus
	/*The 2D array shown in Albrecht Durer's Melencolia I has a unique characteristic where
	adding the four numbers of any row, column, or corner group yields the sum of 34. Adding
	the four numbers in the center also yields this sum, as well as the four numbers of both
	diagonal lines.*/

	srand(clock()); //Insert clock seed into random number generator

	cout << "Jacob Kulcak \nCS 1337-502 \nProgram 1\n##########################" << endl;

	//Demonstrate Bubble Sort
	cout << "Bubble Sort" << endl;
	fillArray(intArr, 10, boolArr, 100);
	cout << "Before" << endl;
	showArray(intArr, 10);
	cout << "-----" << endl;
	cout << "After" << endl;
	bubbleSort(intArr, 10);
	showArray(intArr, 10);
	cout << "##########################" << endl;

	//Demonstrate Selection Sort
	cout << "Selection Sort" << endl;
	fillArray(intArr, 10, boolArr, 100);
	cout << "Before" << endl;
	showArray(intArr, 10);
	cout << "-----" << endl;
	cout << "After" << endl;
	selectionSort(intArr, 10);
	showArray(intArr, 10);
	cout << "##########################" << endl;

	//Demonstrate Linear Search
	cout << "Linear Search" << endl;
	fillArray(intArr, 10, boolArr, 100);
	targetVal = getTarget(intArr, 10);
	showArray(intArr, 10);
	result = linearSearch(intArr, 10, targetVal);
	cout << "-----" << endl;
	cout << "Target: " << targetVal << " Index: " << result << endl;
	cout << "##########################" << endl;

	//Demonstrate Binary Search
	cout << "Binary Search" << endl;
	fillArray(intArr, 10, boolArr, 100);
	targetVal = getTarget(intArr, 10);
	bubbleSort(intArr, 10);
	showArray(intArr, 10);
	result = binarySearch(intArr, 10, targetVal);
	cout << "-----" << endl;
	cout << "Target: " << targetVal << " Index: " << result << endl;
	cout << "##########################" << endl;

	//Benchmark
	cout << "Benchmarks" << endl;
	fillArray(intArr2, 1000, boolArr2, 10000);
	bubbleSort(intArr2, 1000);
	cout << "Test Linear Search" << endl;
	testLinearSearch(intArr2, 1000);
	cout << "Test Binary Search" << endl;
	testBinarySearch(intArr2, 1000);
	cout << "##########################" << endl;
}
