#pragma once
#include <iostream>
using namespace std;

class DeliveryStrategy {
public:
    virtual double calculateCost() = 0; 
    virtual ~DeliveryStrategy() {}
};

// ���������� ���������: ������������� ������
class FlatRateDelivery : public DeliveryStrategy {
public:
    double calculateCost() override {
        return 500.0; 
    }
};

// ���������� ���������: �� ����
class WeightBasedDelivery : public DeliveryStrategy {
public:
    double calculateCost() override {
        double weight;
        cout << "������� ��� ������ (��): ";
        cin >> weight;
        return weight * 10.0; 
    }
};

// ���������� ���������: �� ����������
class DistanceBasedDelivery : public DeliveryStrategy {
public:
    double calculateCost() override {
        double distance;
        cout << "������� ���������� (��): ";
        cin >> distance;
        return distance * 20.0; 
    }
};

// ����� ������
class Order {
private:
    DeliveryStrategy* strategy; 

public:
    Order(DeliveryStrategy* strategy) : strategy(strategy) {}

    double calculateTotalCost() {
        return strategy->calculateCost();
    }
};
