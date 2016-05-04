#include <iostream>
using namespace std;

int print();

int main()
{
	print();
}

int print()
{
	int x; 
	cout << "[1] Create an Application " << endl << "[2] List all Applications" << endl << "[3] Find Applications" << endl << "[4] Create a Page" << endl << "[5] List all Pages" << endl << "[6] Find Pages" << endl << "[0] Quit" << endl; 
	cin >> x; 
	switch(x)
	{
	case (1):
		cout << "Create an Application" << endl << endl;
		print();
		break;
	case (2):
		cout << "List all Applications" << endl << endl;
		print();
		break;
	case (3):
		cout << "Find Applications" << endl << endl;
		print();
		break;
	case (4):
		cout << "Creat a page" << endl << endl;
		print();
		break;
	case (5):
		cout << "List all Pages" << endl << endl;
		print();
		break;
	case (6):
		cout << "Find Pages" << endl << endl;
		print();
		break;
	case (0):
		return 0;
		break;
	}
	return 1;
}
