// Stirng.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include "String.h"
using namespace std;
int main()
{
    setlocale(LC_ALL, "Ru");
    String str1("Hello, world!"); // Конструктор с параметром-строкой
    str1.display(); // Выводим строку

    String str2(10); // Конструктор с параметром длина строки
    str2.setString("Short"); // Устанавливаем строку
    str2.display(); // Выводим строку

    String str3 = str1; // Конструктор копирования
    str3.display(); // Выводим скопированную строку

    str1.setString("Dynamic memory handling!"); // Устанавливаем новую строку
    str1.display(); // Выводим обновлённую строку

    return 0;
}

