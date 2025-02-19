#pragma once
using namespace std;
#include <iostream>
class String
{
private:
    int length;    // Длина строки без учета нуль-терминатора
    char* str;     // Указатель на динамический массив символов

public:
    // Конструктор с параметром-строкой
    String(const char* s) {
        length = 0;
        while (s[length] != '\0') { // Вычисляем длину строки
            length++;
        }
        str = new char[length + 1]; // +1 для нуль-терминатора
        for (int i = 0; i < length; i++) { // Копируем строку
            str[i] = s[i];
        }
        str[length] = '\0'; // Добавляем нуль-терминатор
    }

    // Конструктор с параметром длина строки
    String(int len) {
        length = len;
        str = new char[length + 1]; // +1 для нуль-терминатора
        str[0] = '\0'; // Инициализируем пустую строку
    }

    // Конструктор копирования
    String(const String& other) {
        length = other.length; // Копируем длину
        str = new char[length + 1]; // Выделяем память
        for (int i = 0; i < length; i++) { // Копируем строку
            str[i] = other.str[i];
        }
        str[length] = '\0'; // Добавляем нуль-терминатор
    }

    // Деструктор
    ~String() {
        delete[] str; // Освобождаем память
    }

    // Метод для отображения строки на экране
    void display() const {
        cout << str << endl;
        // Выводим строку
    }

    // Сеттер, принимающий строку
    void setString(const char* s) {
        int newLength = 0;
        while (s[newLength] != '\0') { // Вычисляем новую длину
            newLength++;
        }

        if (newLength > length) { // Если новая длина больше текущей
            delete[] str; // Освобождаем старую память
            str = new char[newLength + 1]; // Выделяем новую память
            length = newLength; // Обновляем длину
        }

        for (int i = 0; i < length; i++) { // Копируем новую строку
            str[i] = s[i];
        }
        str[length] = '\0'; // Добавляем нуль-терминатор
    }

    // Метод для получения длины строки
    int getLength() const {
        return length; // Возвращ
    }
};

