//Drew Overgaard
//Comp 53
//Project 4 Adding, Subtracting, Multiplying, and Dividing Fractions

#include <iostream>
#include "Fraction.h";

using namespace std;

Fraction::Fraction(int n, int d)
{
	numerator = n;
	denominator = d;
}

int Fraction::GCD(int one, int two)		//The greatest common divisor function is used in simplification
{
	if (two == 0)
	{
		return one;
	}
	else
	{
		return GCD(two, one % two);
	}
}

Fraction Fraction::operator+(Fraction rhs)
{
	Fraction Addition;
	int g = 0;

	Addition.numerator = (numerator * rhs.denominator) + (denominator * rhs.numerator); //Multiply the opposite num and den of both fraction and add to get numerator
	Addition.denominator = denominator * rhs.denominator;

	g = GCD(Addition.numerator, Addition.denominator);

	Addition.numerator = Addition.numerator / g;
	Addition.denominator = Addition.denominator / g;

	return Addition;
}

Fraction Fraction::operator-(Fraction rhs)
{
	Fraction Subtraction;				//Do the same thing for addition just subtract the numerator values
	int g = 0;

	Subtraction.numerator = (numerator * rhs.denominator) - (denominator * rhs.numerator); //Multiply the opposite num and den of both fraction and subtract to get numerator
	Subtraction.denominator = denominator * rhs.denominator;

	g = GCD(Subtraction.numerator, Subtraction.denominator);

	Subtraction.numerator = Subtraction.numerator / g;
	Subtraction.denominator = Subtraction.denominator / g;

	return Subtraction;
}

Fraction Fraction::operator*(Fraction rhs)
{
	Fraction Multiplication;		
	int g = 0;

	Multiplication.numerator = numerator * rhs.numerator; 
	Multiplication.denominator = denominator * rhs.denominator;

	g = GCD(Multiplication.numerator, Multiplication.denominator);	//Call the GCD recursive function to get the greatest common divisor

	Multiplication.numerator = Multiplication.numerator / g;			//Divide num and den by the GCD and that is the simplified result
	Multiplication.denominator = Multiplication.denominator / g;

	return Multiplication;
}

Fraction Fraction::operator/(Fraction rhs)
{
	Fraction Division;
	int g = 0;

	Division.numerator = numerator * rhs.denominator;			//Divide numerator by the other fractions denominator to get the numerator
	Division.denominator = denominator * rhs.numerator;

	g = GCD(Division.numerator, Division.denominator);	//Call the GCD recursive function to get the greatest common divisor

	Division.numerator = Division.numerator / g;			//Divide num and den by the GCD and that is the simplified result
	Division.denominator = Division.denominator / g;

	return Division;
}

Fraction Fraction::operator++(int)						//Have this in here from the lab
{
	Fraction plusPlus;

	plusPlus.numerator = denominator + numerator;
	plusPlus.denominator = denominator;

	numerator = denominator + numerator;

	return plusPlus;
}

Fraction::operator double()				//Overloading the double typecast operator
{
	double overload = 0.0;

	double n = numerator;	//One of the ints, in this case num, needed to be converted to a double

	overload = n / denominator; 

	return overload;
}

//Fraction operator++(); this would be ++x

bool Fraction::operator>(Fraction rhs)					//Have this in here from the lab
{
	if (numerator * rhs.denominator > rhs.numerator * denominator)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool Fraction::operator<(Fraction rhs)					//Have this in here from the lab
{
	if (numerator * rhs.denominator < rhs.numerator * denominator)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool Fraction::operator==(Fraction rhs)					//Have this in here from the lab
{
	if (numerator * rhs.denominator == rhs.numerator * denominator)
	{
		return true;
	}
	else
	{
		return false;
	}

}

ostream& operator<<(ostream &out, Fraction &rhs)
{
	out << rhs.numerator << "/" << rhs.denominator;
	return out;
}

istream& operator>>(istream &in, Fraction &rhs)
{
	char junk;
	in >> rhs.numerator;
	in >> junk;				//Read the plus sign into junk because we don't want to have it in the equation
	in >> rhs.denominator;

	return in;
}