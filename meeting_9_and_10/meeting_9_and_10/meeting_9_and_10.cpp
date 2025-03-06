#include <iostream>
using namespace std;
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

int main() {
    setlocale(LC_ALL, "ru");
    Complex num1, num2;

    cin >> num1;
    cin >> num2;

    // Вывод комплексных чисел
    cout << "Комплексное число 1: " << num1 << endl;
    cout << "Комплексное число 2: " << num2 << endl;

    // Сложение
    Complex sum = num1 + num2;
    cout << "Сумма: " << sum << endl;

    // Вычитание
    Complex difference = num1 - num2;
    cout << "Разность: " << difference << endl;

    // Сравнение
    if (num1 == num2) {
        cout << "Комплексные числа равны." << endl;
    }
    else {
        cout << "Комплексные числа не равны." << endl;
    }

    return 0;
}