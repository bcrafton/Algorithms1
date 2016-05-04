#include <iostream>
#include <string>
using namespace std;

struct Donut
{
	string flavor;
	double price;
	Donut* prev = NULL;
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

struct DonutTray
{
	Donut* head = NULL;
	Donut* tail = NULL;
	int length = 0;
	DonutTray(){}
	void append(Donut* donut);
	void prepend(Donut* donut);
	void insert(Donut* donut, int index);
	void remove(int index);
	void display()
	{
		Donut* current = head;
		int counter = 0;
		while (current != NULL)
		{
			cout << "[" << counter << "] ";
			current->display();
			current = current->next;
			counter++;
		}
		cout << "======================" << endl;
	}
};

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
	Donut* vanilla = new Donut("Vanilla", 1.99);
	Donut* strawberry = new Donut("Strawberry", 0.99);
	Donut* caramel = new Donut("Caramel", 2.99);
	Donut* coffee = new Donut("Coffee", 1.99);

	// create a donut tray
	DonutTray* tray = new DonutTray;

	// append some donuts
	tray->append(chocolate);
	tray->append(boston);
	tray->append(jelly);
	tray->append(glazed);

	tray->display();

	// prepend some donuts
	tray->prepend(eclair);
	tray->prepend(snowy);
	tray->prepend(glazed2);
	tray->prepend(moon);

	tray->display();

	// insert some donuts
	tray->insert(vanilla, 2);
	tray->insert(strawberry, 4);
	tray->insert(caramel, 7);
	tray->insert(coffee, 9);
	tray->display();

	// remove some donuts
	tray->remove(3);
	tray->display();
	tray->remove(5);
	tray->display();
}

void DonutTray::append(Donut* donut)
{
	this->length++;
	if ((head == NULL) && (tail == NULL))
	{
		head = donut; 
		tail = donut; 
	}
	else
	{
		donut->next = NULL; 
		donut->prev = tail;
		tail->next = donut; 
		tail = donut; 
	}
}

void DonutTray::prepend(Donut* donut)
{
	this->length++; 
	if ((head == NULL) && (tail == NULL))
	{
		head = donut; 
		tail = donut; 
	}
	else
	{
		donut->next = head; 
		donut->prev = NULL;
		head->prev = donut; 
		head = donut; 
	}
}
/*
void DonutTray::insert(Donut* donut, int index)
{
	if(this->length < index)
	{
		cout << "not long enough to insert: " ;
		donut->display(); 
	}
	else if(head == NULL)
	{
		head = donut; 
	}
	else
	{
		Donut *prevPtr = this->head;
		Donut *nextPtr; 
		for(int i=0; i<index-1; i++)
		{
			prevPtr = prevPtr->next; 
		}
		nextPtr = prevPtr->next; 
		
		//x->x;
		//x->|x|->x; 
		
		donut->prev = prevPtr; 
		prevPtr->next = donut;
		
		donut->next = nextPtr;
		nextPtr->prev = donut; 
		(this->length)++;
	}
}
*/
void DonutTray::insert(Donut* donut, int index)
{
	Donut *current;
	current = head;  
	int counter = 0;
	if(this->length < index)
	{
		cout << "not long enough to insert: " ;
		donut->display(); 
		cout << "length" << this->length; 
	}
	else if(index == 0)
	{
		prepend(donut);
	}
	else if(index == this->length-1)
	{
		append(donut); 
	}
	else
	{
		while(current != NULL)
		{
			if(counter == index)
			{
				donut->next = current; 
				donut->prev = current->prev;
				
				donut->prev->next = donut; 
				current->prev = donut; 	
			}
			current = current->next; 
			counter++; 
		}
		(this->length)++;
	}
}
/*
void DonutTray::remove(int index)
{
	if(this->length < index)
	{
		cout << "not long enough to remove: " ;
		cout << index << endl; 
	}
	else
	{
		Donut *prevPtr = this->head;
		Donut *nextPtr; 
		for(int i=0; i<index-1; i++)
		{
			prevPtr = prevPtr->next; 
		}
		Donut *temp = prevPtr->next; 
		nextPtr = prevPtr->next->next; 
		
		prevPtr->next = nextPtr;
		nextPtr->prev = prevPtr; 
		(this->length)--;
		delete(temp); 
	}
}
*/
void DonutTray::remove(int index)
{
	Donut *current, *nextPtr, *prevPtr;
	current = head;  
	int counter = 0;
	if(this->length < index)
	{
		cout << "not long enough to remove: " ;
		cout << index << endl; 
	}
	else if(head == NULL)
	{
		cout << "nothing to remove" << endl;
	}
	else if(this->length-1 == index)
	{
		Donut *temp = tail; 
		tail->prev->next = NULL; 
		tail = tail->prev; 
		delete(temp); 
		this->length--; 
	}
	else if(index == 0)
	{
		Donut *temp = head; 
		head->next->prev = NULL; 
		head = head->next; 
		delete(temp); 
		length--; 
	}
	else
	{
		while(current != NULL)
		{
			if(counter == index)
			{
				nextPtr = current->next;
				prevPtr = current->prev; 
				
				prevPtr->next = nextPtr;
				nextPtr->prev = prevPtr; 
				
				(this->length)--;
				delete(current); 
			}
			current = current->next; 
			counter++; 
		}
	}
}
