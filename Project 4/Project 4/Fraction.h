//Drew Overgaard
//Comp 53
//Project 4 Adding, Subtracting, Multiplying, and Dividing Fractions

#include <iostream>

using namespace std;

class Fraction{
private:
	int numerator;
	int denominator;

	int GCD(int one, int two);


public:
	Fraction(int n = 0, int d = 1);

	Fraction operator++(int); //x++ we add the int in order to do a post increment

	Fraction operator+(Fraction rhs);
	Fraction operator-(Fraction rhs);
	Fraction operator*(Fraction rhs);
	Fraction operator/(Fraction rhs);

	operator double(); //Need to overload the typecasting operator

	//Fraction operator++(); this would be ++x

	bool operator>(Fraction rhs); //Copy of object on the right hand side		//Have this in here from the lab

	bool operator<(Fraction rhs);			//Have this in here from the lab

	bool operator==(Fraction rhs);			//Have this in here from the lab

	friend ostream& operator<<(ostream &out, Fraction &rhs); //Reference to the cout in main
	friend istream& operator>>(istream &in, Fraction &rhs);
};