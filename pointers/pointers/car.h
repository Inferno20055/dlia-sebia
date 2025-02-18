#pragma once
#include <iostream>
using namespace std;

class Car {
private:
    int horsepower;
public:
    Car(const int* newhorsepower = nullptr) {
        horsepower = (newhorsepower != nullptr) ? *newhorsepower : 0;
    }
    ~Car() {
        if (stamp!=nullptr)
        {
            delete[]stamp;
        }
        if (year!=nullptr)
        {
            delete[]year;
        }

    }

    char stamp[40];
    char year[40]; 
    int set_horsepower() const {
        return horsepower;
    }
    void get_horsepower(const int& newhorsepower) {
        horsepower = newhorsepower;
    }
    void Print_1();
    void Input();
};