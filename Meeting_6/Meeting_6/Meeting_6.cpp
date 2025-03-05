#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <ctime>

using namespace std;
//задание 1
class Date {
private:
    int day;
    int month;
    int year;

    // Проверка корректности даты
    bool isValidDate(int d, int m, int y) const {
        if (y < 1 || m < 1 || m > 12 || d < 1 || d > 31) {
            return false;
        }
        // Проверка на количество дней в месяце
        if (m == 2) {
            // Высокосный год
            if ((y % 4 == 0 && y % 100 != 0) || (y % 400 == 0)) {
                return d <= 29;
            }
            return d <= 28;
        }
        if (m == 4 || m == 6 || m == 9 || m == 11) {
            return d <= 30;
        }
        return true; 
    }

public:
    Date(int d, int m, int y) : day(d), month(m), year(y) {
        if (!isValidDate(day, month, year)) {
            cout << "Некорректная дата!" << endl;
            day = month = year = 0; 
        }
    }

    // Вывод даты
    void display() const {
        cout << day << "/" << month << "/" << year << endl;
    }

    // Разность дат
    int operator-(const Date& other) const {
        struct tm a = { 0 }, b = { 0 };
        a.tm_mday = day;
        a.tm_mon = month - 1; 
        a.tm_year = year - 1900; 
        b.tm_mday = other.day;
        b.tm_mon = other.month - 1;
        b.tm_year = other.year - 1900;

        time_t x = mktime(&a);
        time_t y = mktime(&b);
        double seconds = difftime(x, y);
        return static_cast<int>(seconds / (60 * 60 * 24)); 
    }

    // Увеличение даты на определенное количество дней
    Date operator+(int days) const {
        time_t rawtime;
        struct tm* timeinfo;

        // Создание текущей даты
        time(&rawtime);
        timeinfo = localtime(&rawtime);
        timeinfo->tm_mday = day;
        timeinfo->tm_mon = month - 1; 
        timeinfo->tm_year = year - 1900; 

        // Увеличиваем дату на указанное количество дней
        timeinfo->tm_mday += days;

        // Приводим время в порядок
        mktime(timeinfo); 
        return Date(timeinfo->tm_mday, timeinfo->tm_mon + 1, timeinfo->tm_year + 1900);
    }
};
//задание 2
class MyString {
private:
    char* str;
    size_t length;

public:
    // Конструктор
    MyString(const char* s) {
        length = 0;
        while (s[length] != '\0') {
            length++;
        }
        str = new char[length + 1];
        for (size_t i = 0; i < length; i++) {
            str[i] = s[i];
        }
        str[length] = '\0'; 
    }

    // Деструктор
    ~MyString() {
        delete[] str; 
    }

    // Метод для отображения строки
    void display() const {
        std::cout << str << std::endl;
    }

    // Перегрузка оператора * для нахождения пересечения строк
    MyString operator*(const MyString& other) const {
        char* intersection = new char[length + other.length + 1]; 
        size_t index = 0;

        // Находим пересечение символов двух строк
        for (size_t i = 0; i < length; i++) {
            for (size_t j = 0; j < other.length; j++) {
                if (str[i] == other.str[j]) {
                   
                    bool found = false;
                    for (size_t k = 0; k < index; k++) {
                        if (intersection[k] == str[i]) {
                            found = true;
                            break;
                        }
                    }
                    if (!found) {
                        intersection[index++] = str[i];
                    }
                }
            }
        }
        intersection[index] = '\0'; 

        return MyString(intersection); 
    }
};
int main() {
    //задание 1
    setlocale(LC_ALL,"Ru");
    /*Date date1(10, 10, 2023);
    Date date2(1, 1, 2024);

    cout << "Дата 1: ";
    date1.display();
    cout << "Дата 2: ";
    date2.display();

    // Вычисление разности дат
    int daysDifference = date2 - date1;
    cout << "Разность в днях: " << daysDifference << endl;

    // Увеличение даты на определенное количество дней
    Date newDate = date1 + 20; 
    cout << "Новая дата (10/10/2023 + 20 дней): ";
    newDate.display();*/
    //задание 2
    MyString str1("руди верни сотку");
    MyString str2("где мои руки");

    cout << "Строка 1: ";
    str1.display();
    cout << "Строка 2: ";
    str2.display();

    MyString intersection = str1 * str2; 
    cout << "Пересечение: ";
    intersection.display();
    return 0;
}