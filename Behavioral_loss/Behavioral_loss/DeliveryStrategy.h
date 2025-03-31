#pragma once
#include <iostream>
using namespace std;

class DeliveryStrategy {
public:
    virtual double calculateCost() = 0; 
    virtual ~DeliveryStrategy() {}
};

// Конкретная стратегия: Фиксированная ставка
class FlatRateDelivery : public DeliveryStrategy {
public:
    double calculateCost() override {
        return 500.0; 
    }
};

// Конкретная стратегия: По весу
class WeightBasedDelivery : public DeliveryStrategy {
public:
    double calculateCost() override {
        double weight;
        cout << "Введите вес товара (кг): ";
        cin >> weight;
        return weight * 10.0; 
    }
};

// Конкретная стратегия: По расстоянию
class DistanceBasedDelivery : public DeliveryStrategy {
public:
    double calculateCost() override {
        double distance;
        cout << "Введите расстояние (км): ";
        cin >> distance;
        return distance * 20.0; 
    }
};

// Класс заказа
class Order {
private:
    DeliveryStrategy* strategy; 

public:
    Order(DeliveryStrategy* strategy) : strategy(strategy) {}

    double calculateTotalCost() {
        return strategy->calculateCost();
    }
};
