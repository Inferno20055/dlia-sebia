#pragma once
#include <iostream>
using namespace std;

class Rectangle {
private:
    double width;  
    double height; 

public:
    // Конструктор по умолчанию
    Rectangle() : width(0.0), height(0.0) {}

    // Конструктор с параметрами
    Rectangle(double w, double h) : width(w), height(h) {}

    // Деструктор
    ~Rectangle() {
        
    }

    // Геттер для ширины
    double getWidth() const {
        return width;
    }

    // Сеттер для ширины
    void setWidth(double w) {
        width = w;
    }

    // Геттер для высоты
    double getHeight() const {
        return height;
    }

    // Сеттер для высоты
    void setHeight(double h) {
        height = h;
    }

    // Метод для вычисления площади
    double area() const {
        return width * height;
    }

    // Метод для вычисления периметра
    double perimeter() const {
        return 2 * (width + height);
    }

    // Метод для вывода данных о прямоугольнике
    void print() const {
        cout << "Width: " << width << ", Height: " << height << endl;
        cout << "Area: " << area() << ", Perimeter: " << perimeter() << endl;
    }
};

