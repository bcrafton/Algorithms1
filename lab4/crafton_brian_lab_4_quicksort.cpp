#include <iostream>
#include <string>
using namespace std;

void displayAllApplicationNames(string appNames[], int appCount);
void swapAppNames(int appIndex1, int appIndex2, string appNames[]);
int  pivot(int first, int last, string appNames[]);
void quickSort(int first, int last, string appNames[]);
int _first(string a, string b); // helper function
int _last(string a, string b); // helper function
int _pivotLocation(int pivotLocation, int leftCursor, int rightCursor); // helper function

int main()
{
	string appNames[] =
	{
		"Pages", "Keynote", "Numbers",
		"Word", "PowerPoint", "Excel",
		"Documents", "Presentation", "Sheets"
	};

	displayAllApplicationNames(appNames, 9);
	cout << endl;
	swapAppNames(3, 6, appNames);
	displayAllApplicationNames(appNames, 9);
	cout << endl;
	quickSort(0, 8, appNames);
	displayAllApplicationNames(appNames, 9);

	getchar();
}

void displayAllApplicationNames(string appNames[], int appCount)
{
	int i;
	for(i=0;i<appCount;i++)
	{
		cout << appNames[i] << endl;
	}
}

void swapAppNames(int appIndex1, int appIndex2, string appNames[])
{
	string temp = appNames[appIndex1];
	appNames[appIndex1] = appNames[appIndex2];
	appNames[appIndex2] = temp; 
}


//takes a pivot location
//use leftCursor and rightCursor as left and right cursors.
	// find element to left of pivot that is greater than the pivot = leftCursor
	// find element to right of pivot that is less than the pivot = rightCursor
		// cursors will both stop at pivot since it is not greater than itself or less than itself
	// it will either swap an incorrectly placed 'leftCursor' with either an incorrectly placed rightCursor OR
		//it will swap it with the pivot
	// it will either swap an incorrectly placed 'rightCursor' with either an incorrectly placed leftCursor OR
		//it will swap it will the pivot
	// once all elements on the left side of the pivot are less than it AND once all the elments onthe right side of the pivot are greater than it
		// the function returns the location of the pivot since that is the final location of that element. 
	
	// IMPORTANT TO NOTE THAT THE LEFT AND RIGHT CURSORS CANNOT GO PAST THE PIVOT SINCE THE PIVOT CAN NOT BE LESS THAN ITSELF OR GREATER THAN ITSELF. 
		// MEANING A NUMBER ON THE LEFT SIDE OF THE PIVOT THAT IS GREATER THAN IT CAN ONLY SWAP WITH THE PIVOT OR A NUMBER ON THE RIGHT SIDE THAT IS LESS
		//THAN THE PIVOT. AND:
		// MEANING A NUMBER ON THE RIGHT SIDE OF THE PIVOT THAT IS LESS THAN IT CAN ONLY SWAP WITH THE PIVOT OR A NUMBER ON THE LEFT SIDE THAT IS GREATER
		//THAN THE PIVOT.
		
		
		//TLDR:
		//chooses a pivot and places all elements less than it on left and all elements greater on right, then returns the final location of the pivot
			//that does not need to be changed 
int pivot(int first, int last, string appNames[])
{
	  int leftCursor = first, rightCursor = last; // take left cursor = leftCursor, right cursor = rightCursor
      int pivotLocation = (first+last)/2;  // take pivot location to be middle of function
      string pivot = appNames[pivotLocation]; 
      
      while (leftCursor <= rightCursor) // while the left side of the pivot has a number greater than it OR the right side of the pivot has a number less than it
	  { 
            while(_first(appNames[leftCursor], pivot)) // while there is no number to the left of the pivot that is greater than it
                  leftCursor++;
            while(_last(appNames[rightCursor], pivot)) // while there is no number to the right of the pivot that is less than it 
                  rightCursor--;
            if (leftCursor <= rightCursor) // if the cursors have not overlapped
			{
				if(pivotLocation == _pivotLocation(pivotLocation, leftCursor, rightCursor)) // if the pivot location has not moved then increment
				{ // important to implement this since if an invalid rightCursor or leftCursor is swapped with the pivot then it cannot be incremented since pivot is not less than or greater than itself.
					swapAppNames(leftCursor,rightCursor,appNames);
				  	leftCursor++;
                 	rightCursor--;
				}
				else 
				{
				  	pivotLocation = _pivotLocation(pivotLocation, leftCursor, rightCursor); // it works with and without this. 
                  	swapAppNames(leftCursor,rightCursor,appNames);
				}
            }
      };
      return pivotLocation; // return the pivot location since it is now in the proper place
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

void quickSort(int first, int last, string appNames[])
{
      int pivotLocation = pivot(first, last, appNames);
        
    
      if (first < pivotLocation-1) 
            quickSort(first, pivotLocation-1, appNames); // recursive funtion quickSort from first to the previous pivot
            
      if (pivotLocation+1 < last)
            quickSort(pivotLocation+1, last, appNames); // recursive funtion quickSort from previous pivot to last
}

// 'a' < 'b' 
// if a[i] < b[i] 
// then a comes first
int _first(string a, string b) // string a comes first ... before string b. 
{ //equal to lessThan
	for(int i=0; i<a.length(); i++)
	{
		if(a[i]<b[i])
		{
			return 1;
		}
		else if(a[i]>b[i])
		{
			return 0;
		}
	}
	return 0;
}

// 'a' < 'b' 
// if a[i] > b[i] 
// then a comes last
int _last(string a, string b) // string a comes last ... after string b
{	//equal to greaterThan
	for(int i=0; i<a.length(); i++)
	{
		if(a[i]<b[i])
		{
			return 0;
		}
		else if(a[i]>b[i])
		{
			return 1;
		}
	}
	return 0; 
}
