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

// Абстрактный класс Субъекта
class WeatherSubject {
public:
    virtual void addObserver(Observer* observer) = 0;
    virtual void removeObserver(Observer* observer) = 0;
    virtual void notifyObservers() = 0;
    virtual ~WeatherSubject() {}
};

// Конкретный класс Субъекта
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

// Наблюдатель: Уведомление по SMS
class SMSNotification : public Observer {
public:
    void update(float temperature, float pressure, float humidity) override {
        cout << "SMS: Погода изменилась! Температура: " << temperature
            << "C, Давление: " << pressure << " мм рт. ст., Влажность: " << humidity << "%" << endl;
    }
};

// Наблюдатель: Уведомление по Email
class EmailNotification : public Observer {
public:
    void update(float temperature, float pressure, float humidity) override {
        cout << "Email: Новая информация о погоде. Температура: " << temperature
            << "C, Давление: " << pressure << " мм рт. ст., Влажность: " << humidity << "%" << endl;
    }
};

// Наблюдатель: Уведомление на телефон
class PhoneNotification : public Observer {
public:
    void update(float temperature, float pressure, float humidity) override {
        cout << "Phone: Обновление погоды! Температура: " << temperature
            << "C, Давление: " << pressure << " мм рт. ст., Влажность: " << humidity << "%" << endl;
    }
};

