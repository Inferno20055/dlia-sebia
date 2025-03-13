#include <iostream>
#include <string>
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
//задание 2
class Car {
public:
    virtual void display() const = 0;
    virtual string getCarType() const = 0; // новый метод для получения типа автомобиля
    virtual ~Car() {}
};

class CarFactory {
public:
    virtual Car* createCar() const = 0;
    virtual ~CarFactory() {}
};

class ToyotaCorolla : public Car {
public:
    void display() const override {
        cout << "Это Toyota Corolla." << endl;
    }

    string getCarType() const override {
        return "Toyota Corolla";
    }
};

class ToyotaFactory : public CarFactory {
public:
    Car* createCar() const override {
        return new ToyotaCorolla();
    }
};

class BMWX5 : public Car {
public:
    void display() const override {
        cout << "Это BMW X5." << endl;
    }

    string getCarType() const override {
        return "BMW X5";
    }
};

class BMWFactory : public CarFactory {
public:
    Car* createCar() const override {
        return new BMWX5();
    }
};
//задание 3
class Computer {
public:
    virtual void showConfiguration() const = 0;
    virtual Computer* clone() const = 0; 
    virtual ~Computer() {}
};

// Конкретный класс для настольного компьютера
class DesktopComputer : public Computer {
private:
    string cpu;
    string ram;
    string storage;

public:
    DesktopComputer(const string& cpu, const string& ram, const string& storage)
        : cpu(cpu), ram(ram), storage(storage) {}

    void showConfiguration() const override {
        cout << "Конфигурация настольного компьютера:" << endl;
        cout << "ЦП: " << cpu << endl;
        cout << "ОЗУ: " << ram << endl;
        cout << "Хранение: " << storage << endl;
    }

    Computer* clone() const override {
        return new DesktopComputer(*this); 
    }
};

// Конкретный класс для ноутбука
class LaptopComputer : public Computer {
private:
    string cpu;
    string ram;
    string storage;
    string batteryLife;

public:
    LaptopComputer(const string& cpu, const string& ram, const string& storage, const string& batteryLife)
        : cpu(cpu), ram(ram), storage(storage), batteryLife(batteryLife) {}

    void showConfiguration() const override {
        cout << "Конфигурация ноутбука:" << endl;
        cout << "ЦП: " << cpu << endl;
        cout << "ОЗУ: " << ram << endl;
        cout << "Хранение: " << storage << endl;
        cout << "Время работы от батареи: " << batteryLife << endl;
    }

    Computer* clone() const override {
        return new LaptopComputer(*this); 
    }
};
int main()
{
    setlocale(LC_ALL, "Ru");
    //задание 1
    //Circle circle(5.0);
    //Square square(4.0);
    //Triangle triangle(3.0, 6.0);

    ////полиморфизм
    //Shape* s = &circle;
    //s->area();
    //Shape* h = &square;
    //h->area();
    //Shape* a = &triangle;
    //a->area();


    //cout << "Площадь круга: " << circle.area() << endl;
    //cout << "Площадь квадрата: " << square.area() << endl;
    //cout << "Площадь треугольника: " << triangle.area() << endl;
    //задание 2
   /* CarFactory* toyotaFactory = new ToyotaFactory();
    Car* toyotaCar = toyotaFactory->createCar();
    toyotaCar->display();
    cout << "Тип автомобиля: " << toyotaCar->getCarType() << endl;

    CarFactory* bmwFactory = new BMWFactory();
    Car* bmwCar = bmwFactory->createCar();
    bmwCar->display();
    cout << "Тип автомобиля: " << bmwCar->getCarType() << endl;

    delete toyotaCar;
    delete toyotaFactory;
    delete bmwCar;
    delete bmwFactory;*/
    //задание 3
    Computer* desktop1 = new DesktopComputer("Intel i7", "16GB", "1TB SSD");
    Computer* laptop1 = new LaptopComputer("Intel i5", "8GB", "512GB SSD", "8 часов");

    cout << "Оригинальные конфигурации:" << endl;
    desktop1->showConfiguration();
    laptop1->showConfiguration();

    Computer* desktop2 = desktop1->clone();
    Computer* laptop2 = laptop1->clone();

    cout << "\nКлонированные конфигурации:" << endl;
    desktop2->showConfiguration();
    laptop2->showConfiguration();

    delete desktop1;
    delete laptop1;
    delete desktop2;
    delete laptop2;

    return 0;
}
