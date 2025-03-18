#pragma once
#include <iostream>
#include <string>
#include <memory>
using namespace std;

class Car {
private:
    string brand;
    string model;
    int year;

public:
    Car(const string& brand, const string& model, int year)
        : brand(brand), model(model), year(year) {
    }

    ~Car() {}
    void displayInfo() const {
        cout << "Марка: " << brand << endl;
        cout << "Модель: " << model << endl;
        cout << "Год выпуска: " << year << endl;
    }

    string getBrand() const { return brand; }
    string getModel() const { return model; }
    int getYear() const { return year; }

    string setBrand(string bran) {
        brand = bran;
    }
    string setModel(string Mode) {
        model = Mode;
    }
    int setYear(int yer) {
        year = yer;
    }
};
