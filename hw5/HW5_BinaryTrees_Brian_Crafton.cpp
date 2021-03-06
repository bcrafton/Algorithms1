#include <iostream>
#include <string>
using namespace std;

enum DepartmentType
{
	HR, ENGINEERING, SALES, MARKETING
};

class Employee
{
private:
	string firstName;
	string lastName;
	double salary;
	DepartmentType departmentType;
public:
	void display()
	{
		cout << firstName << " " << lastName << " $" << salary << endl;
	}
	Employee(){}
	Employee(string fName, string lName, double salary, DepartmentType dept)
	{
		setFirstName(fName);
		setLastName(lName);
		setSalary(salary);
		setDepartmentType(dept);
	}
	void setFirstName(string fName)
	{
		this->firstName = fName;
	}
	void setLastName(string lName)
	{
		this->lastName = lName;
	}
	void setSalary(double salary)
	{
		if (salary > 0)
		{
			this->salary = salary;
		}
	}
	void setDepartmentType(DepartmentType departmentType)
	{
		this->departmentType = departmentType;
	}
	string getFirstName() { return firstName; }
	string getLastName()  { return lastName; }
	double getSalary()    { return salary; }
	DepartmentType getDepartmentType() { return departmentType; }
};

struct EmployeeNode
{
	Employee* employee;
	EmployeeNode* left = NULL;
	EmployeeNode* right = NULL;
	EmployeeNode(){}
	EmployeeNode(Employee* employee)
	{
		this->employee = employee;
	}
};

class EmployeeBinarySearchTree
{
private:
	EmployeeNode* root = NULL;
	void insert(EmployeeNode* node, EmployeeNode** root);
	void traverseInOrder(EmployeeNode* root);
	void traversePreOrder(EmployeeNode* root);
	void traversePostOrder(EmployeeNode* root);
	Employee* breadthFirstSearch(string firstName, EmployeeNode* root);
	Employee* depthFirstSearch(string firstName, EmployeeNode* root);
public:
	void insert(Employee* employee);
	void remove(string firstName);
	Employee* breadthFirstSearch(string firstName);
	Employee* depthFirstSearch(string firstName);
	void traverseInOrder();
	void traversePreOrder();
	void traversePostOrder();
};

void EmployeeBinarySearchTree::insert(EmployeeNode* node, EmployeeNode** root)
{
	if (*root == NULL)
	{
		*root = node;
		return;
	}
	if (node->employee->getFirstName() >= (*root)->employee->getFirstName())
	{
		insert(node, &((*root)->right));
	}
	else if (node->employee->getFirstName() < (*root)->employee->getFirstName())
	{
		insert(node, &((*root)->left));
	}
}

void EmployeeBinarySearchTree::insert(Employee* employee)
{
	EmployeeNode* node = new EmployeeNode(employee);
	if (root == NULL)
	{
		root = node;
		return;
	}
	insert(node, &root);
}

void EmployeeBinarySearchTree::traverseInOrder()
{
	if (root->left != NULL)
		traverseInOrder(root->left);
	root->employee->display(); 
	if (root->right != NULL)
		traverseInOrder(root->right);
}

void EmployeeBinarySearchTree::traversePreOrder()
{
	root->employee->display(); 
	if (root->left != NULL)
		traversePreOrder(root->left);
	if (root->right != NULL)
		traversePreOrder(root->right);
}

void EmployeeBinarySearchTree::traversePostOrder()
{
	if (root->left != NULL)
		traversePostOrder(root->left);
	if (root->right != NULL)
		traversePostOrder(root->right);
	root->employee->display(); 
}

void EmployeeBinarySearchTree::traverseInOrder(EmployeeNode* root)
{
	if (root->left != NULL)
		traverseInOrder(root->left);
	root->employee->display(); 
	if (root->right != NULL)
		traverseInOrder(root->right);
}

void EmployeeBinarySearchTree::traversePreOrder(EmployeeNode* root)
{
	root->employee->display(); 
	if (root->left != NULL)
		traversePreOrder(root->left);
	if (root->right != NULL)
		traversePreOrder(root->right);
}

void EmployeeBinarySearchTree::traversePostOrder(EmployeeNode* root)
{
	if (root->left != NULL)
		traversePostOrder(root->left);
	if (root->right != NULL)
		traversePostOrder(root->right);
	root->employee->display(); 
}

Employee* EmployeeBinarySearchTree::depthFirstSearch(string firstName)
{
	if (root != NULL)
	{
		if (firstName == root->employee->getFirstName())
		{
			return root->employee;
		}
		else if (firstName > root->employee->getFirstName())
		{
			return depthFirstSearch(firstName, root->right);
		}
		else if (firstName < root->employee->getFirstName())
		{
			return depthFirstSearch(firstName, root->left);
		}
	}
	return NULL;
}

Employee* EmployeeBinarySearchTree::depthFirstSearch(string firstName, EmployeeNode* root)
{
	if (root != NULL)
	{
		if (firstName == root->employee->getFirstName())
		{
			return root->employee;
		}
		else if (firstName.compare(root->employee->getFirstName()) > 0)
		{
			return depthFirstSearch(firstName, root->right);
		}
		else if (firstName.compare(root->employee->getFirstName()) <= 0)
		{
			return depthFirstSearch(firstName, root->left);
		}
	}
	return NULL;
}

Employee* EmployeeBinarySearchTree::breadthFirstSearch(string firstName)
{
	 return NULL; 
}

Employee* EmployeeBinarySearchTree::breadthFirstSearch(string firstName, EmployeeNode* root)
{
	return NULL; 
}

void EmployeeBinarySearchTree::remove(string firstName)
{
}


int main()
{
	Employee* alice = new Employee("Alice", "Wonderland", 3211232, ENGINEERING);
	Employee* bob = new Employee("Bob", "Marley", 3211232, MARKETING);
	Employee* charlie = new Employee("Charlie", "Gargia", 3211232, MARKETING);
	Employee* dan = new Employee("Daniel", "Craig", 123123, HR);
	Employee* edward = new Employee("Edward", "Norton", 21211212, ENGINEERING);
	Employee* frank = new Employee("Frank", "Herbert", 233223, SALES);
	Employee* gregory = new Employee("Gregory", "Peck", 344334, MARKETING);

	EmployeeBinarySearchTree* tree = new EmployeeBinarySearchTree();

	tree->insert(dan);
	tree->insert(bob);
	tree->insert(alice);
	tree->insert(charlie);
	tree->insert(frank);
	tree->insert(edward);
	tree->insert(gregory);

	/*
		The tree now looks like this:

					Daniel
			Bob				Frank
		Alice		Charlie		Edward		Gregory
	*/

	cout << endl << "In Order: " << endl;
	tree->traverseInOrder();

	cout << endl << "Pre Order: " << endl;
	tree->traversePreOrder();

	cout << endl << "Post Order: " << endl;
	tree->traversePostOrder();

	cout << endl << "Depth First Search: " << endl;
	Employee* found = tree->depthFirstSearch("Bob");
	if (found != NULL)
	{
		found->display();
	}
	else
	{
		cout << "Not Found" << endl;
	}

	cout << endl << "Breadth First Search: " << endl;
	found = tree->breadthFirstSearch("Frank");
	if (found != NULL)
	{
		found->display();
	}
	else
	{
		cout << "Not Found" << endl;
	}
	getchar();
}

/*
	Sample Output:

	In Order:
	Alice Wonderland $3.21123e+006
	Bob Marley $3.21123e+006
	Charlie Gargia $3.21123e+006
	Daniel Craig $123123
	Edward Norton $2.12112e+007
	Frank Herbert $233223
	Gregory Peck $344334

	Pre Order:
	Daniel Craig $123123
	Bob Marley $3.21123e+006
	Alice Wonderland $3.21123e+006
	Charlie Gargia $3.21123e+006
	Frank Herbert $233223
	Edward Norton $2.12112e+007
	Gregory Peck $344334

	Post Order:
	Alice Wonderland $3.21123e+006
	Charlie Gargia $3.21123e+006
	Bob Marley $3.21123e+006
	Edward Norton $2.12112e+007
	Gregory Peck $344334
	Frank Herbert $233223
	Daniel Craig $123123

	Depth First Search:
	Bob Marley $3.21123e+006

	Breadth First Search:
	Frank Herbert $233223
*/
