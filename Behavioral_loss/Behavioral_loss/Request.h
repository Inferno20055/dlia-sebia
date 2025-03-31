#pragma once
#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Request {
public:
    string description;

    Request(const string& desc) : description(desc) {}
};

// Абстрактный класс обработчика
class SupportHandler {
protected:
    SupportHandler* nextHandler;

public:
    SupportHandler() : nextHandler(nullptr) {}

    void setNextHandler(SupportHandler* handler) {
        nextHandler = handler;
    }

    virtual void handleRequest(Request request) {
        if (nextHandler != nullptr) {
            nextHandler->handleRequest(request);
        }
    }

    virtual ~SupportHandler() {}
};

// Конкретный обработчик: Младший специалист
class JuniorSupport : public SupportHandler {
public:
    void handleRequest(Request request) override {
        cout << "Младший специалист: " << request.description << endl;
        cout << "К сожалению, я не могу решить эту проблему." << endl;
        SupportHandler::handleRequest(request);
    }
};

// Конкретный обработчик: Старший специалист
class SeniorSupport : public SupportHandler {
public:
    void handleRequest(Request request) override {
        cout << "Старший специалист: " << request.description << endl;
        cout << "Проблема успешно решена." << endl;
    }
};

// Конкретный обработчик: Менеджер
class ManagerSupport : public SupportHandler {
public:
    void handleRequest(Request request) override {
        cout << "Менеджер: " << request.description << endl;
        cout << "Проблема успешно решена." << endl;
    }
};
