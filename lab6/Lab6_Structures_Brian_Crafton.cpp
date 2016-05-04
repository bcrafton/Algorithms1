#include <iostream>
using namespace std;

struct Complex {
	float real;
	float imaginary;
};

void displayComplex(Complex n);
Complex addComplex(Complex a, Complex b);
Complex subtractComplex(Complex a, Complex b);
Complex multiplyComplex(Complex a, Complex b);
void tryToSetComplexByValue(Complex a, float real, float imaginary);
void setComplexByReference(Complex &a, float real, float imaginary);
void setComplexByPointer(Complex *a, float real, float imaginary);

int main()
{
	Complex x = { 3, 2 };
	Complex y = { 1, 4 };
	displayComplex(x);
	displayComplex(y);

	Complex sum = addComplex(x, y);
	displayComplex(sum);

	Complex diff = subtractComplex(x, y);
	displayComplex(diff);

	Complex product = multiplyComplex(x, y);
	displayComplex(product);

	tryToSetComplexByValue(x, 4, 5);
	displayComplex(x);

	setComplexByReference(x, 4, 5);
	displayComplex(x);

	setComplexByPointer(&x, 5, 6);
	displayComplex(x);

	getchar();
}

void displayComplex(Complex n)
{
	if(n.imaginary >= 0)
		cout << n.real << " + i" << n.imaginary << endl; 
	else
		cout << n.real << " - i" << -1*(n.imaginary) << endl; 
}

Complex addComplex(Complex a, Complex b)
{
	//Complex c = {a.real + b.real, a.imaginary + b.imaginary}; 
	Complex c;
	c.real = a.real + b.real;
	c.imaginary = a.imaginary + b.imaginary;
	
	return c; 	
}

Complex subtractComplex(Complex a, Complex b)
{
	//Complex c = {a.real - b.real, a.imaginary - b.imaginary}; 
	Complex c;
	c.real = a.real - b.real;
	c.imaginary = a.imaginary - b.imaginary;
	
	return c; 
}

Complex multiplyComplex(Complex a, Complex b)
{
	Complex c;
	c.real = a.real * b.real - a.imaginary * b.imaginary; //subtract imaginarys since i*i = -1
	c.imaginary = a.real * b.imaginary + a.imaginary * b.real;
	
	return c; 
}

void tryToSetComplexByValue(Complex a, float real, float imaginary)
{
	a.real = real; 
	a.imaginary = imaginary;
	
	/*The reason that this fails is that a is a new structure so editing a will not change
	the value that was passed since it is passing the value not the structure itself.*/ 
}

void setComplexByReference(Complex &a, float real, float imaginary) // c++ handles this 
{ // like is pass by reference, c++ does the pointer stuff for u, all user has to do is use '&' in function signiture

	// it really gets pointer but function handles it for you
	a.real = real; 
	a.imaginary = imaginary;
	/*The reason that this actually works is that a is actually pointing to the struct that is
	being changed. Instead of passing a value equal to the struct it is passing a pointer which can edit the
	structure itself.*/
}

void setComplexByPointer(Complex *a, float real, float imaginary)
{
	// it gets a pointer, but this time c++ does not handle it for user
	a->real = real; 
	a->imaginary = imaginary;
}
