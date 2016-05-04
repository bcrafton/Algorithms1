#include <iostream>
#include <string>
using namespace std;

struct Donut {
	string flavor;
	int age;
	double price;
	Donut* prev = NULL;
	Donut* next = NULL;
	Donut(){}
	Donut(string flavor, int age, double price){
		this->flavor = flavor;
		this->age = age;
		this->price = price;
	}
	// implement the copy constructors
	Donut(const Donut &otherDonut);
	Donut(const Donut *otherDonut);
	void display() {
		cout << flavor << "\t$" << price << "\t" << age << endl;
	}
};

struct DonutTray
{
	Donut* head = NULL; // head of the list of donuts
	Donut* tail = NULL; // tail of the list of donuts
	int length = 0;		// number of donuts in the tray

	DonutTray(){}

	// implement the copy constructor
	// copies a another tray into this tray
	DonutTray(const DonutTray &otherTray);

	// implement the appendDonut method
	// appends a donut at the end of the tray
	// feel free to reuse implementations
	// from labs or other past assignments
	void appendDonut(Donut* donut);

	// removes the donut from the list
	void removeDonut(Donut* donut);

	// implement the display() method
	// iterates over this tray
	// displaying each of the elements
	void display();

	// implement the concatenate() method
	// concatenates another tray
	// at the end of this tray
	void concatenate(const DonutTray* otherTray);

	// implement the removeStaleDonuts() method
	// iterates over the tray removing stale donuts
	// donuts are stale if their age is grater than
	// maxAge
	void removeStaleDonuts(int maxAge);
};

// here's an implementation of copy that
// doesn't quite work. The new tray does
// display as the original tray, but since
// it refers to the original elements, you
// can't manipulate the elements without
// also manipulating the original elements

// meaning the copies wud share elements... wants completely new list of same (value wise) elements. 
DonutTray* badCopy(const DonutTray* other)
{
	DonutTray* newTray = new DonutTray();
	newTray->head = other->head;
	newTray->tail = other->tail;
	newTray->length = other->length;
	return newTray;
}
// a better implementation of copy would
// create an exact replica of the original
// tray, but the elements would be brand
// new instances that have the same values
// as the original tray, but they can be
// manipulated independently from the original
// tray
DonutTray* goodCopy(const DonutTray* otherTray);

int main()
{
	Donut* chocolate = new Donut("Chocola", 12, 0.99);
	Donut* vanilla = new Donut("Vanilla", 13, 1.99);
	Donut* strawberry = new Donut("Strawbe", 14, 2.99);
	Donut* glazed = new Donut("Glazed", 15, 0.99);
	Donut* boston = new Donut("Boston", 12, 1.99);
	Donut* cream = new Donut("Cream", 13, 2.99);

	// test display method
	cout << "Display Donut" << endl;
	chocolate->display();

	// test the copy constructor
	// make sure each has its own
	// member variables
	cout << endl << "Donut Copy Constructor" << endl;
	Donut crispy("Crispy", 11, 0.59);
	Donut copy = crispy;
	copy.display();
	crispy.display();

	copy.price += 1.00;
	crispy.price += 2.00;

	copy.display();
	crispy.display();

	// create a tray
	cout << endl << "Create tray1" << endl;
	DonutTray* tray1 = new DonutTray();
	tray1->appendDonut(chocolate);
	tray1->appendDonut(vanilla);
	tray1->appendDonut(strawberry);
	tray1->display();

	// create another tray
	cout << endl << "Create tray2" << endl;
	DonutTray* tray2 = new DonutTray();
	tray2->appendDonut(glazed);
	tray2->appendDonut(boston);
	tray2->appendDonut(cream);
	tray2->display();

	// test concatenate tray2 into tray1
	cout << endl << "Concatenate tray2 to tray1" << endl;
	tray1->concatenate(tray2);
	tray1->display();

	// make sure tray2 was not affected
	tray2->display();

	// but if we append to tray2,
	// tray1 will change too
	// but that's ok for now
	tray2->appendDonut(&crispy);
	tray2->display();
	tray1->display();

	cout << endl << "Bad Copy" << endl;
	/* test badCopy. realize that changing one
	* tray changes the other
	*/

	DonutTray* badCopyTray = badCopy(tray2);
	// display both trays verifying the look the same
	tray2->display();
	badCopyTray->display();
	// change one of the donuts in the copy tray
	badCopyTray->head->price += 1.00;
	// realize that price changed
	// for original tray as well
	badCopyTray->head->display();
	tray2->head->display();

	// test goodCopy and verify that changing
	cout << endl << "Good Copy" << endl;
	// copied donut does not affect original tray
	DonutTray* goodCopyTray = goodCopy(tray2);
	// display both trays verifying the look the same
	tray2->display();
	goodCopyTray->display();
	// change the donuts in both tray
	tray2->head->price += 2.00;
	goodCopyTray->head->price += 3.00;
	// realize that prices changed independently
	goodCopyTray->head->display();
	tray2->head->display();

	cout << endl << "Remove Stale Donuts" << endl;
	tray1->display();
	tray1->removeStaleDonuts(13);
	tray1->display();

	getchar();
}



Donut::Donut(const Donut& other)
{
	this->flavor = other.flavor;
	this->age = other.age;
	this->price = other.price;
	this->prev = other.prev;
	this->next = other.next;
}
Donut::Donut(const Donut* other)
{
	this->flavor = other->flavor;
	this->age = other->age;
	this->price = other->price;
	this->prev = other->prev;
	this->next = other->next;
}


DonutTray::DonutTray(const DonutTray &other)
{
	this->length = other.length;
	
	for(Donut *ptr = other.head; ptr!=NULL; ptr=ptr->next)
	{
		Donut* copy = new Donut(ptr);
		this->appendDonut(copy);
	}
}

void DonutTray::appendDonut(Donut* donut)
{
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

void DonutTray::display()
{
	int counter = 0; 
	for(Donut *ptr = this->head; ptr!=NULL; ptr=ptr->next)
	{
		cout << "[" << counter << "] ";
		ptr->display(); 
		counter++;
	}
}
/*
void DonutTray::concatenate(const DonutTray* other) 
{
	DonutTray *temp = new DonutTray(*other); 
	this->tail->next = temp->head;
	this->tail = temp->tail; 
}
*/
void DonutTray::concatenate(const DonutTray* other)
{
	this->tail->next = other->head;
	this->tail = other->tail; 
}

DonutTray* goodCopy(const DonutTray* other)
{
	DonutTray* newTray = new DonutTray();
	newTray->length = other->length;
	
	for(Donut *ptr = other->head; ptr!=NULL; ptr=ptr->next)
	{
		Donut* copy = new Donut(ptr);
		newTray->appendDonut(copy);
	}
	
	return newTray;
}

void DonutTray::removeStaleDonuts(int maxAge)
{
	for(Donut *ptr = this->head; ptr!=NULL; ptr=ptr->next)
	{
		if(ptr->age > maxAge)
		{
			removeDonut(ptr); 
		}
	}
}

void DonutTray::removeDonut(Donut* donut)
{ 
	if(head == NULL && tail == NULL)
	{
		return;
	}
	else if(head == tail)
	{
		delete(head); 
		head = NULL;
		tail = NULL; 
	}
	else if(donut == head)
	{
		Donut *temp = head; 
		head = head->next;
		head->prev = NULL; //dont want this node to point to anything before it since it is head
		delete(temp); // delete will deallocate the previous node but it will not delete it if it does not need to so it 
		//will still be read if head->prev is not set to NULL; 
	}
	else if(donut == tail)
	{
		Donut *temp = tail; 
		tail = tail->prev;
		tail->next = NULL;  //dont want this node to point to anything after it since it is tail
		delete(temp);// delete will deallocate the previous node but it will not delete it if it does not need to so it 
		//will still be read if head->prev is not set to NULL; 
	}
	else
	{
		donut->prev->next = donut->next; 
		donut->next->prev = donut->prev; 
		delete(donut); 
	}
}
