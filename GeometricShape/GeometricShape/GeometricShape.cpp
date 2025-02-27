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

    // Вывод комплексных чисел
    for (int i = 0; i < size; i++)
    {
        cout << "Комплексные числа " << i + 1 << ": " << endl;
        arr[i].Print();
        cout << endl;
    }

    // Пример сложения
    Shape sum = arr[0] + arr[1];
    cout << "Сумма первого и второго комплексного числа: ";
    sum.Print();

    // Пример вычитания
    Shape difference = arr[1] - arr[0];
    cout << "Разность второго и первого комплексного числа: ";
    difference.Print();

    // Пример умножения на комплексное число
    Shape product = arr[0] * arr[1];
    cout << "Произведение первого и второго комплексного числа: ";
    product.Print();

    // Пример умножения на действительное число
    double scalar = 2.0;
    Shape scaled = arr[0] * scalar;
    cout << "Первое комплексное число, умноженное на " << scalar << ": ";
    scaled.Print();

   
    delete[] arr;


	return 0;
}

