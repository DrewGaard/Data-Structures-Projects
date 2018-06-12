//Drew Overgaard
//Comp 53
//Project 4 Adding, Subtracting, Multiplying, and Dividing Fractions

#include "Fraction.h"
#include <iostream>

using namespace std;

int main()
{
	Fraction X, Y, Z;


	cout << "Enter two fractions (in the form numerator/denominator): ";
	cin >> X;
	cin >> Y;

	Z = X + Y;
	cout << X << " + " << Y << " = " << Z << endl;

	Z = X - Y;
	cout << X << " - " << Y << " = " << Z << endl;

	Z = X * Y;
	cout << X << " * " << Y << " = " << Z << endl;

	Z = X / Y;
	cout << X << " / " << Y << " = " << Z << endl;

	cout << X << " as a double is " << (double)X << endl;

	system("pause");
	return 0;
}