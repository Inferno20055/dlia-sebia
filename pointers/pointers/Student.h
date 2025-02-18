#pragma once
class Student
{
private:
    int group;
    string ychzav;

public:
    Student(int* newgroup = nullptr) { group = (newgroup != nullptr) ? *newgroup:0;
    }
    ~Student() {
        if (name!=nullptr)
        {
            delete[]name;
        }
        if (date_of_birth != nullptr)
        {
            delete[]date_of_birth;
        }
        if (tel != nullptr)
        {
            delete[]tel;
        }
        if (city != nullptr)
        {
            delete[]city;
        }
        if (country != nullptr)
        {
            delete[]country;
        }
        if (city_and_country != nullptr)
        {
            delete[]city_and_country;
        }
    
    }
    char name[21];
    char date_of_birth[20];
    char tel[13];
    char city[40];
    char country[30];
    char city_and_country[50];



    void Input();

    void Print();
    int getgroup() const {
        return group;
    }
    int setgroup(const int& newGroup) {
        return group = newGroup;
    }
    string getychzav()const {
        return ychzav;
    }
    string setychzav(const string& newychzav) {
        return ychzav = newychzav;
    }

};

