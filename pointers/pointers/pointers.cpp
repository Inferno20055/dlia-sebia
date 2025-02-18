#include <iostream>
#include "pointer.h"
#include "car.h"
#include <conio.h>
#include "fraction.h"
#include "Student.h"
using namespace std;

void Car::Input() {
    cout << "Введите информацию об автомобиле" << endl;

    cin.ignore(); 
    cout << "Введите марку автомобиля: ";
    cin.getline(stamp, 40); 

    cout << "Введите год выпуска: ";
    cin.getline(year, 40); 
    
}
void Fraction::Print_2() {
    
}
void Car::Print_1() {
    cout << "Информация об автомобиле" << endl;
    cout << "Марка автомобиля: " << stamp << endl;
    cout << "Год выпуска: " << year << endl;
    cout << "Лошадиные силы: " << horsepower << endl;
}
void Pointer::Print() {
    cout << "Координаты точки: " << x << ", " << y << ", " << z << endl;
}
void Student::Input() {
    cout << "Введите ФИО студента: ";
    cin.ignore();
    cin.getline(name, 21);
    cout << "Введите дату рождения: ";
    cin.getline(date_of_birth, 20);
    cout << "Введите контактный телефон: ";
    cin.getline(tel, 13);
    cout << "Введите город: ";
    cin.getline(city, 40);
    cout << "Введите страну: ";
    cin.getline(country, 30);


    cout << "Введите город и страну (где находится учебное заведение): ";
    cin.getline(city_and_country, 50);

}
void Student::Print() {
    cout << "ФИО: " << name << endl;
    cout << "Дата рождения: " << date_of_birth << endl;
    cout << "Контактный телефон: " << tel << endl;
    cout << "Город: " << city << endl;
    cout << "Страна: " << country << endl;
    cout << "Город и страна учебного заведения: " << city_and_country << endl;

}
int main() {
    setlocale(LC_ALL, "RU");
    int horsepower = 118; 
    Car myCar(&horsepower); 
    myCar.Input();
    myCar.Print_1(); 

    int a = 10, b = 14, c = 9;
    Pointer point(&a, &b, &c);
    point.Print(); 

    int divider = 8;
    Student student;


    student.Input();


    cout << endl << "Успеваемость студента:" << endl;
    student.Print();
    student.setgroup(1);
    student.setychzav("Ziv");
    cout << "Учебное заведение: " << student.setychzav("Ziv") << endl;
    cout << "Номер группы: " << student.setgroup(1) << endl;
    _getch();
    return 0;
}