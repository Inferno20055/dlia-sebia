#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <memory>
using namespace std;

class Shape {
public:
    virtual void accept(class Visitor& visitor) = 0; 
    virtual ~Shape() {}
};

// ����� ��� ��������������
class Rectangle : public Shape {
private:
    double length;
    double width;

public:
    Rectangle(double l, double w) : length(l), width(w) {}

    double getLength() const { return length; }
    double getWidth() const { return width; }

    void accept(Visitor& visitor) override;
};

// ����� ��� �����
class Circle : public Shape {
private:
    double radius;

public:
    Circle(double r) : radius(r) {}

    double getRadius() const { return radius; }

    void accept(Visitor& visitor) override;
};

// ����� ��� ������������
class Triangle : public Shape {
private:
    double a, b, c; 

public:
    Triangle(double side1, double side2, double side3) : a(side1), b(side2), c(side3) {}

    double getA() const { return a; }
    double getB() const { return b; }
    double getC() const { return c; }

    void accept(Visitor& visitor) override;
};

// ����������� ����� ����������
class Visitor {
public:
    virtual void visit(Rectangle& rectangle) = 0;
    virtual void visit(Circle& circle) = 0;
    virtual void visit(Triangle& triangle) = 0;
    virtual ~Visitor() {}
};

// ����� ��� ���������� �������
class AreaCalculator : public Visitor {
public:
    void visit(Rectangle& rectangle) override {
        double area = rectangle.getLength() * rectangle.getWidth();
        cout << "������� ��������������: " << area << " ��.�" << endl;
    }

    void visit(Circle& circle) override {
        double area = 3.14 * circle.getRadius() * circle.getRadius();
        cout << "������� �����: " << area << " ��.�" << endl;
    }

    void visit(Triangle& triangle) override {
        double s = (triangle.getA() + triangle.getB() + triangle.getC()) / 2; 
        double area = sqrt(s * (s - triangle.getA()) * (s - triangle.getB()) * (s - triangle.getC()));
        cout << "������� ������������: " << area << " ��.�" << endl;
    }
};

// ����� ��� ���������� ���������
class PerimeterCalculator : public Visitor {
public:
    void visit(Rectangle& rectangle) override {
        double perimeter = 2 * (rectangle.getLength() + rectangle.getWidth());
        cout << "�������� ��������������: " << perimeter << " �" << endl;
    }

    void visit(Circle& circle) override {
        double perimeter = 2 * 3.14 * circle.getRadius();
        cout << "�������� �����: " << perimeter << " �" << endl;
    }

    void visit(Triangle& triangle) override {
        double perimeter = triangle.getA() + triangle.getB() + triangle.getC();
        cout << "�������� ������������: " << perimeter << " �" << endl;
    }
};

// ���������� ������ accept ��� ��������������
void Rectangle::accept(Visitor& visitor) {
    visitor.visit(*this);
}

// ���������� ������ accept ��� �����
void Circle::accept(Visitor& visitor) {
    visitor.visit(*this);
}

// ���������� ������ accept ��� ������������
void Triangle::accept(Visitor& visitor) {
    visitor.visit(*this);
}
