#pragma once
#include <iostream>
using namespace std;

class String
{
private:
    int length;    
    char* str;     

public:
    String(const char* s) {
        length = 0;
        while (s[length] != '\0') { 
            length++;
        }
        str = new char[length + 1];
        for (int i = 0; i < length; i++) { 
            str[i] = s[i];
        }
        str[length] = '\0'; 
    }

    // Конструктор с параметром длина строки
    String(int len) {
        length = len;
        str = new char[length + 1]; 
        str[0] = '\0'; 
    }

    // Конструктор копирования
    String(const String& other) {
        length = other.length; 
        str = new char[length + 1]; 
        for (int i = 0; i < length; i++) { 
            str[i] = other.str[i];
        }
        str[length] = '\0';
    }

    // Деструктор
    ~String() {
        delete[] str;
    }

    // Метод для отображения строки на экране
    void display() const {
        cout << str << endl;
       
    }

    // Сеттер, принимающий строку
    void setString(const char* s) {
        int newLength = 0;
        while (s[newLength] != '\0') { 
            newLength++;
        }

        if (newLength > length) {
            delete[] str; 
            str = new char[newLength + 1]; 
            length = newLength;
        }

        for (int i = 0; i < length; i++) { 
            str[i] = s[i];
        }
        str[length] = '\0';
    }

   
    int getLength() const {
        return length; 
    }
};

