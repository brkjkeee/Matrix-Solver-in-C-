#include<iostream>
#include "fraction.h"
#define EOS '\n'

using namespace std;

int test() {
	setlocale(LC_ALL, "Russian");
	int m1[2] = { 1, 1 }, m2[2] = {1, 1}, i;
	
	cout << "������� ����� A: ";
	i = 0;
	do {
		cin >> m1[i];
		i++;
	} while (cin.get() != EOS);
	
	
	cout << "������� ����� B: ";
	i = 0;
	do {
		cin >> m2[i];
		i++;
	} while (cin.get() != EOS);
	

	Fraction a(m1[0], m1[1]);
	Fraction b(m2[0], m2[1]);
	Fraction c;

	c = a.Sum(b);
	cout << "����� A+B: ";
	c.show();

	c = a.Difference(b);
	cout << "����. A-B: ";
	c.show();

	c = a.Product(b);
	cout << "���.  A*B: ";
	c.show();

	c = a.Division(b);
	cout << "���.  A/B: ";
	c.show();



	system("Pause");
	return 0;
}