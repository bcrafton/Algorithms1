#include <iostream>
using namespace std;
void displayApplication(int appIndex, string appNames[], float appPrices[], int appCount);
void displayAllApplications(string appNames[], float appPrices[], int appCount);
void swapApps(int appIndex1, int appIndex2, string appNames[], float appPrices[]);
int  binarySearchForPrice(float searchPrice, float appPrices[], int first, int last);
int pivot(int first, int last, string appNames[],float appPrices[]);
int _pivotLocation(int pivotLocation, int leftCursor, int rightCursor); 
void quickSort(int first, int last, string appNames[], float appPrices[]);
int lessThan(float a, float b);
int greaterThan(float a, float b);


int main()
{
	string appNames[] =
	{
		"Pages", "Keynote", "Numbers",
		"Word", "PowerPoint", "Excel",
		"Documents", "Presentation", "Sheets"
	};

	float appPrices[] =
	{
		3.99, 2.99, 1.99,
		19.99, 29.99, 39.99,
		34.99, 24.99, 14.99
	};

	displayAllApplications(appNames, appPrices, 9);
	quickSort(0, 8, appNames, appPrices);
	displayAllApplications(appNames, appPrices, 9);
	int foundIndex = binarySearchForPrice(25.99, appPrices, 0, 9);

	if (foundIndex == -1)
	{
		cout << "Not Found" << endl;
	}
	else
	{
		cout << "Found at index " << foundIndex << endl;
	}

	getchar();
}


int  binarySearchForPrice(float searchPrice, float appPrices[], int first, int last)
{
	int index; 
	if(first>last)
	{
		index = -1;
	}
	else 
	{
		int mid = (first+last)/2;
		if(searchPrice == appPrices[mid])
		{
			index = mid;
		}
		else
		{
			if(searchPrice < appPrices[mid]) // if we are looking for a number (searchPrice) lower than where (appPrices[mid]) we are we need to go lower
			{
				//cout << "search price: " << searchPrice << " Price of current loc: " << appPrices[mid] << endl; 
				//cout << "lower" << endl; 
				index = binarySearchForPrice(searchPrice, appPrices, first, mid-1);
			}
			else // if we are looking for a number (searchPrice) higher than where (appPrices[mid]) we are we need to go higher
			{
				//cout << "search price: " << searchPrice << " Price of current loc: " << appPrices[mid] << endl; 
				//cout << "higher" << endl ;
				index = binarySearchForPrice(searchPrice, appPrices, mid+1, last); 
				
			}
		}
	}
	return index; 
}

void swapApps(int appIndex1, int appIndex2, string appNames[], float appPrices[])
{
	float temp;
	string _temp; 
	
	temp = appPrices[appIndex1];
	appPrices[appIndex1] = appPrices[appIndex2];
	appPrices[appIndex2] = temp;
	
	_temp = appNames[appIndex1];
	appNames[appIndex1] = appNames[appIndex2];
	appNames[appIndex2] = _temp; 
}

void displayAllApplications(string appNames[], float appPrices[], int appCount)
{
	int i;
	cout << endl << "---------------------------------------------------" << endl; 
	for(i=0;i<appCount;i++)
	{
		cout << i << ") " << appNames[i] << " $" << appPrices[i] << endl;
	}
	cout << "---------------------------------------------------" << endl;
}

void displayApplication(int appIndex, string appNames[], float appPrices[], int appCount)
{
	if(appIndex >= appCount)
		cout << "App does not exist" << endl;
	else
		cout << appIndex << ") " << appNames[appIndex] << " $" << appPrices[appIndex] << endl;	
}

int _pivotLocation(int pivotLocation, int leftCursor, int rightCursor)
{
	if(leftCursor == pivotLocation)
	{
		return rightCursor;
	}
	else if(rightCursor == pivotLocation)
	{
		return leftCursor;
	}
	else 
		return pivotLocation;
}

void quickSort(int first, int last, string appNames[], float appPrices[])
{
      int pivotLocation = pivot(first, last, appNames, appPrices);
        
      if (first < pivotLocation-1) 
            quickSort(first, pivotLocation-1, appNames, appPrices); // recursive funtion quickSort from first to the previous pivot
            
      if (pivotLocation+1 < last)
            quickSort(pivotLocation+1, last, appNames, appPrices); // recursive funtion quickSort from previous pivot to last
}

int pivot(int first, int last, string appNames[],float appPrices[])
{
	  int p = first; 
	  float pValue = appPrices[p]; 
	  
	  for(int i = first + 1; i<=last; i++)
	  {
	  	if(appPrices[i] < pValue)
	  	{
	  		p++; 
	  		swapApps(p, i, appNames,  appPrices);
	  	}
	  }
	  swapApps(first, p, appNames, appPrices); 
	  return p; 
}


int lessThan(float a, float b) 
{
	if(a<b)
	{
		return 1;	
	}
	return 0; 
}

int greaterThan(float a, float b)
{
	if(a>b)
	{
		return 1; 
	}
	return 0; 
}


