#include <iostream>
#include <string>
using namespace std;

struct Employee {
	string firstName, lastName;
	float salary;
};

struct Department {
	string name;
	Employee director;
	Employee* employees;
	int currentSize;
	int maxSize;
};

void displayEmployee(Employee employee);
void displayDepartment(Department* department);
Employee createEmployee();
void addEmployee(Department* department, Employee employee);

int main()
{
	// create some employees
	Employee ada = { "Ada", "Lovelace", 325123 };
	Employee babbage = { "Charlie", "Babbage", 234432 };
	Employee turing = { "Alan", "Turing", 323323 };
	Employee von = { "John", "von Neumann", 432234 };

	displayEmployee(ada);

	// create an array of employees
	Employee* employees = new Employee[10];
	employees[0] = ada;
	employees[1] = babbage;
	employees[2] = turing;
	employees[3] = von;

	// create a "CS" department,
	// employee von is the directory,
	// the employees are the employees listed above,
	// currently has 4 employees,
	// with a max of 10 employees
	Department cs = { "CS", von, employees, 4, 10 };

	displayDepartment(&cs);
	Employee newEmployee = createEmployee();
	addEmployee(&cs, newEmployee);
	displayDepartment(&cs);
}

void displayEmployee(Employee employee)
{
	cout << employee.firstName << " " << employee.lastName << " $" << employee.salary << endl; 
}

void displayDepartment(Department* department)
{
	cout << department->name << " department" << endl; 
	cout << "Director: ";
	displayEmployee(department->director); 
	for(int i=0; i<department->currentSize; i++)
	{
		cout << i << ") ";
		displayEmployee(department->employees[i]);
	}
}

Employee createEmployee() 
{
	Employee newEmployee; 
	cout << endl; 
	cout << "PLease enter the employee's first name: " ;
	cin >> newEmployee.firstName; 
	cout << "PLease enter the employee's last name: " ;
	cin >> newEmployee.lastName; 
	cout << "PLease enter the employee's salary: " ;
	cin >> newEmployee.salary; 
	cout << endl; 
	return newEmployee;	
}

void addEmployee(Department* department, Employee employee) 
{
	if(department->currentSize == department->maxSize)
	{
		Employee *temp = department->employees; 
		department->employees = new Employee[department->maxSize+1];
		
		for(int i=0; i<department->maxSize; i++)
		{
			department->employees[i] = temp[i];
		}
		department->employees[department->maxSize] = employee; 
		department->currentSize++; 
		department->maxSize++; 
	}
	else
	{
		department->employees[department->currentSize] = employee;
		department->currentSize++;
	}
}
