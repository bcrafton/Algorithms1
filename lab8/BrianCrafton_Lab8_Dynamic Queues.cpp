#include <iostream>
#include <string>
using namespace std;

// structure representing a donut
struct Donut
{
	string flavor = "";
	float price = 0.0;

	// constructor to initialize member variables
	Donut(string flvr, float prc)
	{
		flavor = flvr;
		price = prc;
	}

	// default, no argument constructor
	Donut(){}
};

// structure representing a collection of donuts
struct DonutTray
{
	// dynamic array of pointers to donuts
	// first * is for the dynamic array
	// second * is for pointer to donut
	Donut** donuts;

	// maximum number of donuts in tray
	int capacity;

	// boundary indices of queue
	int front = 0, back = 0;

	// how many donuts are currently in the queue
	int count = 0;

	// constructor to initialize the tray
	DonutTray(int size)
	{
		// set the capacity and allocate the array
		capacity = size;
		donuts = new Donut*[capacity];
	}
		/*	
		donuts is an array of pointers.
		each pointer in the array points to actual donut objects
		is a 2d array				
		 		   ->	donuts[0]	->	*donuts[0]
		 		   ->	donuts[1]  		... each one of these is an actual donut object
		 dounuts   ->	donuts[2]
				   ->	donuts[3]
		 		   ->	donuts[4]
						...each one of these is 
						an pointer 
						that points to actual 
						donut objects
		
		the reason it seemed to be 2 dimensional was because I thought the pointers in the array
		pointer to another array.
		they actually just point to real donut objects
		
		donut *ptr = new donut; // pointer just pointing to a donut |THIS WAS THE CASE|
		dount *ptr = new donut[10]; // pointer pointing to an array of donuts. 
		*/
};

// putting and removing donuts from the tray
void   enqueueDonut(DonutTray* tray, Donut* donut);
Donut* dequeueDonut(DonutTray* tray);

// display a single donut and the whole tray
void   displayDonut(Donut* donut);
void   displayDonutTray(DonutTray* tray);

int main()
{
	// create some donuts
	Donut* chocolate = new Donut("Chocolate", 0.99);
	Donut* boston = new Donut("Boston Crm", 0.99);
	Donut* jelly = new Donut("Jelly", 0.99);
	Donut* glazed = new Donut("Glazed", 0.99);
	Donut* eclair = new Donut("Eclair", 0.99);
	Donut* snowy = new Donut("Snowy", 0.99);
	Donut* moon = new Donut("Moonraker", 0.99);

	// create a small tray that can hold 5 donuts
	DonutTray* tray = new DonutTray(50);

	// add 4 donuts to the tray and display it
	enqueueDonut(tray, chocolate);
	enqueueDonut(tray, boston);
	enqueueDonut(tray, jelly);
	enqueueDonut(tray, glazed);
	displayDonutTray(tray);

	// remove a donut from the tray, display the donut and tray
	Donut* donut = dequeueDonut(tray);
	displayDonut(donut);
	displayDonutTray(tray);

	// add two more donuts and display the tray
	enqueueDonut(tray, eclair);
	enqueueDonut(tray, snowy);
	displayDonutTray(tray);

	// remove and display two donuts, and add one more
	donut = dequeueDonut(tray);
	displayDonut(donut);
	donut = dequeueDonut(tray);
	displayDonut(donut);
	enqueueDonut(tray, moon);

	// display final tray
	displayDonutTray(tray);
}

void displayDonut(Donut* donut)
{
	char tab = 9; 
	cout << donut->flavor << ":" << tab << "$" << donut->price << endl; 
}

void displayDonutTray(DonutTray* tray) // recieving pointers to donut objects rather than donut
{
	for(int i=tray->front; i<tray->back; i++) // iterates through queue of donuts
	{
		cout << "[" << i << "] "; 
		displayDonut(tray->donuts[i]); // feeds displayDonut a pointer to the donut object
	}
}

void enqueueDonut(DonutTray* tray, Donut* donut)
{
	if(tray->back < tray->capacity)
	{
		tray->donuts[tray->back] = donut; //add pointer to array of pointers
		(tray->back)++; 
		(tray->count)++; 
	}
	else
	{
		cout << "Try has filled its capacity" << endl; 
	}
}

Donut* dequeueDonut(DonutTray* tray) 
{
	if(tray->front < tray->capacity)
	{	
		(tray->front)++;
		(tray->count)--;
		return tray->donuts[tray->front-1];//we incremented earlier in fucntion so just subtract one to get dequeued donut 
	}
	else 
	{
		cout << "No donuts left" << endl; 
		return NULL; 
	}
}
