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

// ����������� ����� �����������
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

// ���������� ����������: ������� ����������
class JuniorSupport : public SupportHandler {
public:
    void handleRequest(Request request) override {
        cout << "������� ����������: " << request.description << endl;
        cout << "� ���������, � �� ���� ������ ��� ��������." << endl;
        SupportHandler::handleRequest(request);
    }
};

// ���������� ����������: ������� ����������
class SeniorSupport : public SupportHandler {
public:
    void handleRequest(Request request) override {
        cout << "������� ����������: " << request.description << endl;
        cout << "�������� ������� ������." << endl;
    }
};

// ���������� ����������: ��������
class ManagerSupport : public SupportHandler {
public:
    void handleRequest(Request request) override {
        cout << "��������: " << request.description << endl;
        cout << "�������� ������� ������." << endl;
    }
};
