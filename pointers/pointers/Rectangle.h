#pragma once
#include <iostream>
using namespace std;

class Rectangle {
private:
    double width;  
    double height; 

public:
    // ����������� �� ���������
    Rectangle() : width(0.0), height(0.0) {}

    // ����������� � �����������
    Rectangle(double w, double h) : width(w), height(h) {}

    // ����������
    ~Rectangle() {
        
    }

    // ������ ��� ������
    double getWidth() const {
        return width;
    }

    // ������ ��� ������
    void setWidth(double w) {
        width = w;
    }

    // ������ ��� ������
    double getHeight() const {
        return height;
    }

    // ������ ��� ������
    void setHeight(double h) {
        height = h;
    }

    // ����� ��� ���������� �������
    double area() const {
        return width * height;
    }

    // ����� ��� ���������� ���������
    double perimeter() const {
        return 2 * (width + height);
    }

    // ����� ��� ������ ������ � ��������������
    void print() const {
        cout << "Width: " << width << ", Height: " << height << endl;
        cout << "Area: " << area() << ", Perimeter: " << perimeter() << endl;
    }
};

