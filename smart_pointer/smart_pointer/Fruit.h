#pragma once
#include <iostream>
#include <string>
#include <memory>
#include<algorithm>
using namespace std;
class Fruit {
public:
    string name;
    double price;
    double weight;

    Fruit(string n, double p, double w) : name(n), price(p), weight(w) {}

   
    void display() const {
        cout << name << " - $" << price << ", " << weight << " kg\n";
    }
    ~Fruit() {}
    string getName()const {
        return name;
    }
    double getPrice()const {
        return price;
    }
    double getWeight()const {
        return weight;
    }
    string setName(string Name) {
        name = Name;
    }
    double setPrice(double Price) {
        price = Price;
    }
    double setWeight(double Weight) {
        weight = Weight;
    }
};

