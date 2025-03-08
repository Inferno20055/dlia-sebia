#include <iostream>
#include <cstring>
using namespace std;
//встреча 9
class Array {
private:
    int* data;
    size_t size;

public:
    // Конструктор по умолчанию
    Array(size_t s) : size(s) {
        data = new int[size];
        for (size_t i = 0; i < size; ++i) {
            data[i] = 0; 
        }
    }

    // Деструктор
    ~Array() {
        delete[] data;
    }

    // Печать массива
    void print() {
        for (size_t i = 0; i < size; i++) {
            cout << data[i] << " ";
        }
        cout << endl;
    }

    // Перегрузка оператора []
    int& operator[](size_t index) {
        if (index >= size) throw out_of_range("Индекс за пределами допустимого");
        return data[index];
    }

    // Перегрузка оператора ()
    void operator()(int increment) {
        for (size_t i = 0; i < size; ++i) {
            data[i] += increment;
        }
    }

    // Преобразование к int (сумма элементов)
    operator int() const {
        int sum = 0;
        for (size_t i = 0; i < size; ++i) {
            sum += data[i];
        }
        return sum;
    }

    // Преобразование к char*
    operator char* () const {
        char* str = new char[size * 11]; 
        strcpy(str, ""); 
        for (size_t i = 0; i < size; ++i) {
            char buffer[12];
            sprintf(buffer, "%d ", data[i]);
            strcat(str, buffer);
        }
        return str;
    }
};
class String {
public:
    String(const char* str = "") : value(str) {}

    friend ostream& operator<<(ostream& os, const String& str) {
        os << str.value;
        return os;
    }

    String operator+(const String& other) const {
        return String((value + other.value).c_str());
    }

    String operator*(const String& other) const {
        string result;
        for (char c : value) {
            if (other.value.find(c) != string::npos) {
                result += c;
            }
        }
        return String(result.c_str());
    }

    String operator/(const String& other) const {
        string result;
        for (char c : value) {
            if (other.value.find(c) == string::npos) {
                result += c;
            }
        }
        return String(result.c_str());
    }

    void Show() const {
        cout << value << endl;
    }

    operator const char* () const {
        return value.c_str();
    }

private:
    string value;
};
class MyString {
public:
    char* str;  // Указатель на массив символов
    size_t length; // Длина строки

    MyString() : str(nullptr), length(0) {}

    MyString(const char* s) {
        length = strlen(s);
        str = new char[length + 1];
        strcpy(str, s);
    }

    MyString(const MyString& other) {
        length = other.length;
        str = new char[length + 1];
        strcpy(str, other.str);
    }

    ~MyString() {
        delete[] str;
    }

    MyString& operator=(const MyString& other) {
        if (this != &other) {
            delete[] str;
            length = other.length;
            str = new char[length + 1];
            strcpy(str, other.str);
        }
        return *this;
    }

    void display() const {
        if (str) {
            cout << str;
        }
        else {
            cout << "null";
        }
    }
};

class var {
public:
    enum Type { INT, DOUBLE, STRING, NONE } type;
    union {
        int intValue;
        double doubleValue;
        MyString stringValue;
    };

    var() : type(NONE) {}

    var(int value) : type(INT), intValue(value) {}

    var(double value) : type(DOUBLE), doubleValue(value) {}

    var(const MyString& value) : type(STRING), stringValue(value) {}

    var(const char* value) : type(STRING), stringValue(MyString(value)) {}

    ~var() {
        if (type == STRING) {
            stringValue.~MyString();  
        }
    }

    var operator+(const var& other) const {
        if (type == INT) {
            if (other.type == INT) {
                return var(intValue + other.intValue);
            }
            else if (other.type == DOUBLE) {
                return var(intValue + other.doubleValue);
            }
            else if (other.type == STRING) {
                return var(intValue + atoi(other.stringValue.str));
            }
        }
        else if (type == DOUBLE) {
            if (other.type == INT) {
                return var(doubleValue + other.intValue);
            }
            else if (other.type == DOUBLE) {
                return var(doubleValue + other.doubleValue);
            }
            else if (other.type == STRING) {
                return var(doubleValue + atof(other.stringValue.str));
            }
        }
        else if (type == STRING) {
            if (other.type == STRING) {
                return var(MyString(strcat(new char[strlen(stringValue.str) + strlen(other.stringValue.str) + 1], stringValue.str, other.stringValue.str)));
            }
        }
        return var();  
    }

    var operator-(const var& other) const {
        if (type == INT) {
            if (other.type == INT) {
                return var(intValue - other.intValue);
            }
            else if (other.type == DOUBLE) {
                return var(intValue - other.doubleValue);
            }
        }
        else if (type == DOUBLE) {
            if (other.type == INT) {
                return var(doubleValue - other.intValue);
            }
            else if (other.type == DOUBLE) {
                return var(doubleValue - other.doubleValue);
            }
        }
        return var();  
    }

    var operator*(const var& other) const {
        if (type == STRING && other.type == STRING) {
            MyString result;
            for (size_t i = 0; i < stringValue.length; i++) {
                for (size_t j = 0; j < other.stringValue.length; j++) {
                    if (stringValue.str[i] == other.stringValue.str[j]) {
                        result.str[result.length++] = stringValue.str[i];
                        break;
                    }
                }
            }
            result.str[result.length] = '\0';
            return var(result);
        }
        return var(); 
    }

    var operator/(const var& other) const {
        if (type == STRING && other.type == STRING) {
            MyString result;
            for (size_t i = 0; i < stringValue.length; i++) {
                bool found = false;
                for (size_t j = 0; j < other.stringValue.length; j++) {
                    if (stringValue.str[i] == other.stringValue.str[j]) {
                        found = true;
                        break;
                    }
                }
                if (!found) {
                    result.str[result.length++] = stringValue.str[i];
                }
            }
            result.str[result.length] = '\0';
            return var(result);
        }
        return var(); 
    }

    bool operator==(const var& other) const {
        if (type == INT && other.type == INT) {
            return intValue == other.intValue;
        }
        else if (type == DOUBLE && other.type == DOUBLE) {
            return doubleValue == other.doubleValue;
        }
        else if (type == STRING && other.type == STRING) {
            return strcmp(stringValue.str, other.stringValue.str) == 0;
        }
        return false;
    }


    void display() const {
        switch (type) {
        case INT:
            cout << intValue;
            break;
        case DOUBLE:
            cout << doubleValue;
            break;
        case STRING:
            stringValue.display();
            break;
        default:
            cout << "None";
            break;
        }
    }
};


//встреча 10
class Complex {
private:
    double real;
    double imag;

public:
    // Конструкторы
    Complex(double r = 0.0, double i = 0.0) : real(r), imag(i) {}

    // Дружественная функция для перегрузки оператора вывода (<<)
    friend ostream& operator<<(ostream& os, const Complex& c) {
        os << c.real << (c.imag >= 0 ? " + " : " - ") << fabs(c.imag) << "i";
        return os;
    }

    // Дружественная функция для перегрузки оператора ввода (>>)
    friend istream& operator>>(istream& is, Complex& c) {
        cout << "Введите действительную и мнимую части: ";
        is >> c.real >> c.imag;
        return is;
    }

    // Операция сложения
    Complex operator+(const Complex& other) const {
        return Complex(real + other.real, imag + other.imag);
    }

    // Операция вычитания
    Complex operator-(const Complex& other) const {
        return Complex(real - other.real, imag - other.imag);
    }

    // Операция сравнения на равенство
    bool operator==(const Complex& other) const {
        return (real == other.real) && (imag == other.imag);
    }

    // Операция неравенства
    bool operator!=(const Complex& other) const {
        return !(*this == other);
    }

    // Перегрузка оператора функций ()
    Complex operator()() const {
        return *this;
    }
};
class Time {
private:
    int hours;
    int minutes;
    int seconds;

    void normalize() {
        if (seconds >= 60) {
            minutes += seconds / 60;
            seconds %= 60;
        }
        if (minutes >= 60) {
            hours += minutes / 60;
            minutes %= 60;
        }
        hours %= 24; 
    }

public:
    Time() : hours(0), minutes(0), seconds(0) {}

    Time(int h, int m, int s) : hours(h), minutes(m), seconds(s) {
        normalize();
    }

    void increment() {
        seconds++;
        normalize();
    }

    Time& operator++() {
        increment();
        return *this;
    }

    Time& operator--() {
        if (seconds == 0) {
            if (minutes == 0) {
                if (hours > 0) {
                    hours--;
                    minutes = 59;
                    seconds = 59;
                }
            }
            else {
                minutes--;
                seconds = 59;
            }
        }
        else {
            seconds--;
        }
        return *this;
    }

    // Перегрузка операции !=
    bool operator!=(const Time& other) const {
        return (hours != other.hours || minutes != other.minutes || seconds != other.seconds);
    }

    // Перегрузка операции ==
    bool operator==(const Time& other) const {
        return (hours == other.hours && minutes == other.minutes && seconds == other.seconds);
    }

    // Перегрузка операции >
    bool operator>(const Time& other) const {
        return (hours > other.hours) || (hours == other.hours && minutes > other.minutes) || (hours == other.hours && minutes == other.minutes && seconds > other.seconds);
    }

    // Перегрузка операции <
    bool operator<(const Time& other) const {
        return (other > *this);
    }

    // Перегрузка оператора >> для ввода
    friend istream& operator>>(istream& is, Time& t) {
        char delimit1, delimit2; 
        is >> t.hours >> delimit1 >> t.minutes >> delimit2 >> t.seconds;
        t.normalize();
        return is;
    }

    // Перегрузка оператора << для вывода
    friend ostream& operator<<(ostream& os, const Time& t) {
        os << t.hours << ":" << t.minutes << ":" << t.seconds;
        return os;
    }

    // Перегрузка оператора +=
    Time& operator+=(const Time& other) {
        seconds += other.seconds;
        minutes += other.minutes;
        hours += other.hours;
        normalize();
        return *this;
    }

    // Перегрузка оператора -=
    Time& operator-=(const Time& other) {
        if (seconds < other.seconds) {
            seconds += 60;
            minutes--;
        }
        seconds -= other.seconds;

        if (minutes < other.minutes) {
            minutes += 60;
            hours--;
        }
        minutes -= other.minutes;
        hours -= other.hours;

        if (hours < 0) hours = 0;

        normalize();
        return *this;
    }

    // Перегрузка оператора () для доступа к времени
    void operator()() const {
        cout << hours << ":" << minutes << ":" << seconds << endl;
    }
};
int main() {
    setlocale(LC_ALL, "ru");
    //встреча 9
    //задание 1
    /*Array arr(5);

    
    for (size_t i = 0; i < 5; ++i) {
        arr[i] = i + 1; 
    }

    cout << "Исходный массив: ";
    arr.print();

    arr(2);
    cout << "После увеличения на 2: ";
    arr.print();

    int sum = arr; 
    cout << "Сумма элементов: " << sum << endl;

    char* str = arr; 
    cout << "Массив в виде строки: " << str << endl;

    delete[] str; */
    //задание 2
    var a = 15;
    var b = "Привет";
    var c = 7.8;
    var d = "50";

    b = a + d;
    if (a == b) {
        cout << "равны" << endl;
    }
    else {
        cout << "Не равны" << endl;
    }

    // Пример с операцией * и /
    var e = MyString("Microsoft");
    var f = MyString("Windows");
    var g = e * f; // Пересекаем символы
    var h = e / f; // Удаляем символы из первой строки по символам второй строки
    cout << "Пересечение: "; g.display(); cout << endl;
    cout << "Разница: "; h.display(); cout << endl;
    //встреча 10
    //задание 1
    //Complex num1, num2;

    //cin >> num1;
    //cin >> num2;

    //// Вывод комплексных чисел
    //cout << "Комплексное число 1: " << num1 << endl;
    //cout << "Комплексное число 2: " << num2 << endl;

    //// Сложение
    //Complex sum = num1 + num2;
    //cout << "Сумма: " << sum << endl;

    //// Вычитание
    //Complex difference = num1 - num2;
    //cout << "Разность: " << difference << endl;

    //// Сравнение
    //if (num1 == num2) {
    //    cout << "Комплексные числа равны." << endl;
    //}
    //else {
    //    cout << "Комплексные числа не равны." << endl;
    //}
    // задание 2
    //Time t1(10, 59, 59);
    //Time t2(2, 30, 45);

    //cout << "Начальное время t1: " << t1 << endl;

    //++t1; // Увеличиваем t1 на 1 секунду
    //cout << "После увеличения t1: " << t1 << endl;

    //--t1; // Уменьшаем t1 на 1 секунду
    //cout << "После уменьшения t1: " << t1 << endl;

    //t1 += t2; // Суммируем времена
    //cout << "t1 + t2: " << t1 << endl;

    //t1 -= t2; // Вычитаем времена
    //cout << "t1 - t2: " << t1 << endl;

    //cout << "Введите время (hh:mm:ss): ";
    //Time t3;
    //cin >> t3; // Ввод времени
    //cout << "Вы вошли: " << t3 << endl;

    return 0;
}