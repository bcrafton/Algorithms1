#include <iostream>
using namespace std;

void displayIntArray(int arr[], int size);
float averageIntArray(int arr[], int size);
void readIntArray(int arr[], int size);
int* copyArray(int arr[], int size);
int* concatenateIntArrays(int arr1[], int arr2[], int size1, int size2);
int* subArray(int arr[], int size, int start, int count);

int main()
{
	// Read 2 dynamic arrays
	int size1, size2, size3;
	cout << "Size of arr1: ";
	cin >> size1;
	cout << "Size of arr2: ";
	cin >> size2;

	int* arr1 = new int[size1];
	int* arr2 = new int[size2];

	readIntArray(arr1, size1);
	readIntArray(arr2, size2);

	// concatenate two arrays into a third
	int* arr3;
	arr3 = concatenateIntArrays(arr1, arr2, size1, size2);

	size3 = size1 + size2;
	cout << "Concatenated Array:" << endl;
	displayIntArray(arr3, size3);

	getchar();

	// Copy an array
	int* copy = copyArray(arr1, size1);
	cout << "Copied Array:" << endl;
	displayIntArray(copy, size1);

	// Get sub array
	// Read parent array
	int size4;
	cout << "Array Size: ";
	cin >> size4;
	int* arr4 = new int[size4];
	readIntArray(arr4, size4);

	// get sub array
	int start, count;
	cout << "Start: ";
	cin >> start;
	cout << "Count: ";
	cin >> count;
	int* sub = subArray(arr4, size4, start, count);

	// display sub array
	cout << "Sub Array:" << endl;
	displayIntArray(sub, count);

	getchar();
	getchar();
}


void displayIntArray(int arr[], int size)
{
	for(int i=0;i<size;i++)
	{
		cout << "arr[" << i << "] = " << arr[i] << endl;
	}
}

void readIntArray(int arr[], int size)
{
	for(int i=0;i<size;i++)
	{
		cin >> arr[i]; // input elements  up to size
	}
}

int* copyArray(int arr[], int size)
{
	int *newArray = new int[size]; 
	for(int i=0;i<size;i++)
	{
		newArray[i] = arr[i]; 
	}
	return newArray; 
}

int* concatenateIntArrays(int arr1[], int arr2[], int size1, int size2)
{
	int *newArray = new int[size1+size2];
	for(int i=0;i<size1;i++)
	{
		newArray[i] = arr1[i]; 
	} 
	for(int i=0;i<size2;i++)
	{
		newArray[size1+i] = arr2[i]; 
	}
	return newArray;
}

int* subArray(int arr[], int size, int start, int count)
{
	int *newArray = new int[size];
	for(int i=0; i<count; i++)
	{
		newArray[i] = arr[start+i];
	}
	return newArray; 
}

float averageIntArray(int arr[], int size)
{
	float sum=0; 
	float average; 
	for(int i=0; i<size; i++)
	{
		sum = sum + arr[i]; 
	}
	average = sum/size; 
	cout << "the average of the array is " << average << endl; 
	return average; 
}
