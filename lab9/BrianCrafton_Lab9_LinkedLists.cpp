#include <iostream>
#include <string>
using namespace std;

struct Donut
{
	string flavor = "Chocolate";
	double price = 0.0;
	Donut* next = NULL;
	Donut(){}
	Donut(string flavor, double price)
	{
		this->flavor = flavor;
		this->price = price;
	}
	void display()
	{
		cout << flavor << "\t$" << price << endl;
	}
};

void appendDonut(Donut* head, Donut* donut);
void displayList(Donut* head);
int lengthOfList(Donut* head);
Donut* findFirstDonutFlavor(Donut* head, string flavor);

int main()
{
	// create some donuts
	Donut* chocolate = new Donut("Chocolate", 0.99);
	Donut* boston = new Donut("Boston Crm", 1.99);
	Donut* jelly = new Donut("Jelly", 2.99);
	Donut* glazed = new Donut("Glazed", 1.99);
	Donut* eclair = new Donut("Eclair", 1.99);
	Donut* snowy = new Donut("Snowy", 0.99);
	Donut* glazed2 = new Donut("Glazed", 0.99);
	Donut* moon = new Donut("Moonraker", 2.99);

	// create the list pointing to the first donut
	Donut* list = chocolate;

	// append the rest of the donuts to the end of list
	appendDonut(list, boston);
	appendDonut(list, jelly);
	appendDonut(list, glazed);
	appendDonut(list, eclair);
	appendDonut(list, snowy);
	appendDonut(list, glazed2);
	appendDonut(list, moon);

	// display each of the donuts
	displayList(list);
	// get the length of the list
	int length = lengthOfList(list);
	cout << length << " Donuts" << endl;

	// search for the first donut 
	Donut* foundDonut = findFirstDonutFlavor(list, "Glazed");
	if (foundDonut != NULL)
	{
		cout << "Found Donut:" << endl;
		foundDonut->display();
	}
}

void appendDonut(Donut* head, Donut* donut)
{
	Donut *ptr = head; 
	while(ptr->next != NULL)
	{
		ptr = ptr->next; 
	}
	ptr->next = donut; 
}
void displayList(Donut* head)
{
	int counter = 0; 
	for(Donut *ptr = head; ptr != NULL; ptr = ptr->next)
	{
		cout << "[" << counter << "] ";
		ptr->display();
		counter++; 
	}
}
int lengthOfList(Donut* head)
{
	int counter = 0;
	for(Donut *ptr = head; ptr != NULL; ptr = ptr->next)
		counter++; 
	return counter; 
}
Donut* findFirstDonutFlavor(Donut* head, string flavor)
{
	for(Donut *ptr = head; ptr != NULL; ptr = ptr->next)
	{
		if(ptr->flavor == flavor)
			return ptr;
	}
	return NULL; 
}
