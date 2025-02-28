#include <iostream>
#include <cmath>

using namespace std;
//базовый класс
class Shape {
public:
   
    double area() const {//для вычисления площади
        return 0; 
    }
};

// Производный класс: Круг
class Circle : public Shape {
private:
    double radius; 

public:
    Circle(double r) : radius(r) {} 

    double area() const { 
        return 3.14 * radius * radius; 
    }
    ~Circle() {

    }
};

// Производный класс: Квадрат
class Square : public Shape {
private:
    double side; 

public:
    Square(double s) : side(s) {} 

    double area() const { 
        return side * side; 
    }
    ~Square() {
    
    }
};

// Производный класс: Треугольник
class Triangle : public Shape {
private:
    double base;   
    double height; 

public:
    Triangle(double b, double h) : base(b), height(h) {} 

    double area() const { 
        return 0.5 * base * height; 
    }
    ~Triangle() {

    }
};

int main() {
    setlocale(LC_ALL,"Ru");
    
    Circle circle(5.0);
    Square square(4.0);
    Triangle triangle(3.0, 6.0);
    
    //полиморфизм
    Shape* s=&circle;
    s->area();
    Shape* h = &square;
    h->area();
    Shape* a = &triangle;
    a->area();

    cout << "Площадь круга: " << circle.area() << endl;
    cout << "Площадь квадрата: " << square.area() << endl;
    cout << "Площадь треугольника: " << triangle.area() << endl;
   
    return 0;
}