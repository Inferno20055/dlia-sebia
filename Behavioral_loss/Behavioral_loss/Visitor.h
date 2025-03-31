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

// Класс для прямоугольника
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

// Класс для круга
class Circle : public Shape {
private:
    double radius;

public:
    Circle(double r) : radius(r) {}

    double getRadius() const { return radius; }

    void accept(Visitor& visitor) override;
};

// Класс для треугольника
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

// Абстрактный класс посетителя
class Visitor {
public:
    virtual void visit(Rectangle& rectangle) = 0;
    virtual void visit(Circle& circle) = 0;
    virtual void visit(Triangle& triangle) = 0;
    virtual ~Visitor() {}
};

// Класс для вычисления площади
class AreaCalculator : public Visitor {
public:
    void visit(Rectangle& rectangle) override {
        double area = rectangle.getLength() * rectangle.getWidth();
        cout << "Площадь прямоугольника: " << area << " кв.м" << endl;
    }

    void visit(Circle& circle) override {
        double area = 3.14 * circle.getRadius() * circle.getRadius();
        cout << "Площадь круга: " << area << " кв.м" << endl;
    }

    void visit(Triangle& triangle) override {
        double s = (triangle.getA() + triangle.getB() + triangle.getC()) / 2; 
        double area = sqrt(s * (s - triangle.getA()) * (s - triangle.getB()) * (s - triangle.getC()));
        cout << "Площадь треугольника: " << area << " кв.м" << endl;
    }
};

// Класс для вычисления периметра
class PerimeterCalculator : public Visitor {
public:
    void visit(Rectangle& rectangle) override {
        double perimeter = 2 * (rectangle.getLength() + rectangle.getWidth());
        cout << "Периметр прямоугольника: " << perimeter << " м" << endl;
    }

    void visit(Circle& circle) override {
        double perimeter = 2 * 3.14 * circle.getRadius();
        cout << "Периметр круга: " << perimeter << " м" << endl;
    }

    void visit(Triangle& triangle) override {
        double perimeter = triangle.getA() + triangle.getB() + triangle.getC();
        cout << "Периметр треугольника: " << perimeter << " м" << endl;
    }
};

// Реализация метода accept для прямоугольника
void Rectangle::accept(Visitor& visitor) {
    visitor.visit(*this);
}

// Реализация метода accept для круга
void Circle::accept(Visitor& visitor) {
    visitor.visit(*this);
}

// Реализация метода accept для треугольника
void Triangle::accept(Visitor& visitor) {
    visitor.visit(*this);
}
