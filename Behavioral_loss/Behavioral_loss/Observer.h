#pragma once
#include <iostream>
#include <vector>
#include <string>
using namespace std;
class Observer {
public:
    virtual void update(float temperature, float pressure, float humidity) = 0;
    virtual ~Observer() {}
};

// ����������� ����� ��������
class WeatherSubject {
public:
    virtual void addObserver(Observer* observer) = 0;
    virtual void removeObserver(Observer* observer) = 0;
    virtual void notifyObservers() = 0;
    virtual ~WeatherSubject() {}
};

// ���������� ����� ��������
class WeatherData : public WeatherSubject {
private:
    vector<Observer*> observers;
    float temperature;
    float pressure;
    float humidity;

public:
    void setMeasurements(float temp, float pres, float hum) {
        temperature = temp;
        pressure = pres;
        humidity = hum;
        notifyObservers();
    }

    void addObserver(Observer* observer) override {
        observers.push_back(observer);
    }

    void removeObserver(Observer* observer) override {
        observers.erase(remove(observers.begin(), observers.end(), observer), observers.end());
    }

    void notifyObservers() override {
        for (Observer* observer : observers) {
            observer->update(temperature, pressure, humidity);
        }
    }
};

// �����������: ����������� �� SMS
class SMSNotification : public Observer {
public:
    void update(float temperature, float pressure, float humidity) override {
        cout << "SMS: ������ ����������! �����������: " << temperature
            << "C, ��������: " << pressure << " �� ��. ��., ���������: " << humidity << "%" << endl;
    }
};

// �����������: ����������� �� Email
class EmailNotification : public Observer {
public:
    void update(float temperature, float pressure, float humidity) override {
        cout << "Email: ����� ���������� � ������. �����������: " << temperature
            << "C, ��������: " << pressure << " �� ��. ��., ���������: " << humidity << "%" << endl;
    }
};

// �����������: ����������� �� �������
class PhoneNotification : public Observer {
public:
    void update(float temperature, float pressure, float humidity) override {
        cout << "Phone: ���������� ������! �����������: " << temperature
            << "C, ��������: " << pressure << " �� ��. ��., ���������: " << humidity << "%" << endl;
    }
};

