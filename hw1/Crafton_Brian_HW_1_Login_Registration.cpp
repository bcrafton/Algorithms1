#include <iostream>
#include <string>

using namespace std;


void login();
int option1();
int option2();

int answer;
string userName, password;

int main()
{
	login();
}

void login()
{
	cout <<"[1] Login" << endl << "[2] Register" << endl << "[3] Login as a Guest" << endl << "[0] Quit" << endl ;
	cin >> answer;
	if (answer == 1)
	{
		if(option1()==0)
		{
			login();
		}
	}
	if (answer == 2)
	{
		if(option2()==0)
		{
			login();
		}
	}
}

int option1()
{
	cout << "enter user name: ";
	cin >> userName;
	cout << "enter password: ";
	cin >> password;
	if (userName == "alice" && password == "wonderland")
	{
		cout << "follow me down the rabit hole" << endl; 
	}
	else if (userName == "thomas" && password == "anderson")
	{
		cout << "there is no spoon" << endl; 
	}
	else if (userName == "yoda" && password == "minch")
	{
		cout << "Do. Or do not. There is no try" << endl; 
	}
	else 
	{
		cout << "Sorry, your username or password is invalid" << endl;
		return 0;
	}
	return 1;
}
int option2()
{
	string passwordVerify;
	cout << "enter user name: ";
	cin >> userName;
	cout << "enter password: ";
	cin >> password;
	cout << "verify password: ";
	cin >> passwordVerify;
	if (password != passwordVerify)
	{
		cout << "Passwords must match" << endl; 
		return 0;
	}
	login(); 
	return 1; 
}

