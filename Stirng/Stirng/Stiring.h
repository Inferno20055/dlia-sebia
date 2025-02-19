#pragma once
using namespace std;
#include <iostream>
class String
{
private:
    int length;    // ����� ������ ��� ����� ����-�����������
    char* str;     // ��������� �� ������������ ������ ��������

public:
    // ����������� � ����������-�������
    String(const char* s) {
        length = 0;
        while (s[length] != '\0') { // ��������� ����� ������
            length++;
        }
        str = new char[length + 1]; // +1 ��� ����-�����������
        for (int i = 0; i < length; i++) { // �������� ������
            str[i] = s[i];
        }
        str[length] = '\0'; // ��������� ����-����������
    }

    // ����������� � ���������� ����� ������
    String(int len) {
        length = len;
        str = new char[length + 1]; // +1 ��� ����-�����������
        str[0] = '\0'; // �������������� ������ ������
    }

    // ����������� �����������
    String(const String& other) {
        length = other.length; // �������� �����
        str = new char[length + 1]; // �������� ������
        for (int i = 0; i < length; i++) { // �������� ������
            str[i] = other.str[i];
        }
        str[length] = '\0'; // ��������� ����-����������
    }

    // ����������
    ~String() {
        delete[] str; // ����������� ������
    }

    // ����� ��� ����������� ������ �� ������
    void display() const {
        cout << str << endl;
        // ������� ������
    }

    // ������, ����������� ������
    void setString(const char* s) {
        int newLength = 0;
        while (s[newLength] != '\0') { // ��������� ����� �����
            newLength++;
        }

        if (newLength > length) { // ���� ����� ����� ������ �������
            delete[] str; // ����������� ������ ������
            str = new char[newLength + 1]; // �������� ����� ������
            length = newLength; // ��������� �����
        }

        for (int i = 0; i < length; i++) { // �������� ����� ������
            str[i] = s[i];
        }
        str[length] = '\0'; // ��������� ����-����������
    }

    // ����� ��� ��������� ����� ������
    int getLength() const {
        return length; // �������
    }
};

