#include <iostream>
#include "Shape.h"
#include <cmath>
using namespace std;

int main()
{
	setlocale(LC_ALL,"Ru");

	const int size = 5;
	Shape* arr = new Shape[size];

	for (int i = 0; i < size; i++)
	{
		arr[i].setReal(i + 1);
		arr[i].setMnim((i + 1) * 2);
	}

	for (int i = 0; i < size; i++)
	{
		cout << "Комплексные числа " << i + 1 << ": " << endl;
		arr[i].Print();
		cout << endl;
	}

	delete[]arr;

	return 0;
}

