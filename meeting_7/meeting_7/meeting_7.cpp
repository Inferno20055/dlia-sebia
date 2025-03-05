#include <iostream>
using namespace std;
class Circle {
private:
    float radius;

public:
    Circle(float r = 1):radius(r) {}

    float& getradius() {
        return radius;
    }
    bool operator==(const Circle& other)const {
        return radius == other.radius;
    }
    bool operator>(const Circle& other)const {
        return(2 * 3.14 * radius) > (2 * 3.14 * other.radius);
    }
    Circle& operator+=(double value) {
        radius += value;
        return *this;
    }
    Circle& operator-=(double value) {
        radius -= value;
        if (radius < 0)  radius = 0; 
        return *this;
    }
    float circumference()const {
        return 2 * 3.14 * radius;
    }
    void Print() {
        cout << "Радиус окружности: " << radius << ", Окружность: " << circumference() << endl;
    }
};
class Airplane {
private:
    char type[50];
    int passenger;
    int max_passenger;
    void copyType(const char* t) {
        for (int i = 0; i < sizeof(type) - 1 && t[i] != '\0'; i++) {
            type[i] = t[i];
        }
        type[sizeof(type) - 1] = '\0';
    }

    // Метод для сравнения строк
    bool isEqual(const char* other) const {
        for (int i = 0; i < sizeof(type); i++) {
            if (type[i] != other[i]) {
                return false;
            }
            if (type[i] == '\0') {
                return true;
            }
        }
        return true;
    }
public:
    //конструктор
    Airplane(const char* t, int max_p) : passenger(0), max_passenger(max_p) {
        copyType(t);
    }
    bool operator==(const Airplane& other) {
        return strcmp(this->type, other.type) == 0;
    }
    Airplane& operator++() {
        if (passenger < max_passenger)
        {
            passenger++;
        }
        else
        {
            cout << "Максимальное количество пасажиров достигнуто." << endl;
        }
        return *this;
    }
    Airplane& operator--() {
        if (passenger > 0)
        {
            passenger--;
        }
        else
        {
            cout << "Нет пассажиров для уменьшения" << endl;
        }
        return *this;
    }
    bool operator>(const Airplane& other) {
        return this->max_passenger > other.max_passenger;
    }
    void PrintInfo() {
        cout << "Тип: " << type << ", Пассажиры: " << passenger << ", Максимум: " << max_passenger << endl;
    }
    //деструктор закоментирован так как вызывает исключение!
    /*
    ~Airplane() {
        delete[]type;
    }*/
    //гетеры и сетеры
    int getpassenger()const {
        return passenger;
    }
    int getmax_passenger()const {
        return max_passenger;
    }
    int setpassenger(int pas) {
        pas = passenger;
    }
    int setmax_passenger(int m_pas) {
        m_pas = max_passenger;
    }
};
int main()
{
    setlocale(LC_ALL,"RU");
    Circle circle1(5);
    Circle circle2(3);
    if (circle1==circle2||circle2==circle1)
    {
        cout << "Радиусы равны" << endl;
    }
    else
    {
        cout << "Радиусы не равны" << endl;
    }
    if (circle1 > circle2) {
        cout << "Circle 1 длиннее, чем Circle 2." << endl;
    }
    else {
        cout << "Circle 1 не длиннее, чем Circle 2." << endl;
    }
    circle1 += 2;
    circle2 -= 1;
    
    circle1.Print();
    circle2.Print();
    
    Airplane plane1("Boeing 737", 180);
    Airplane plane2("Airbus A320", 150);


    if (plane1 == plane2) {
        cout << "Самолеты одного типа." << endl;
    }
    else {
        cout << "Самолеты разных типов." << endl;
    }


    ++plane1;
    ++plane1;
    --plane1;

    if (plane1 > plane2) {
        cout << "Plane1 больше по максимальному количеству пассажиров." << endl;
    }
    else {
        cout << "Plane2 больше или равен по максимальному количеству пассажиров." << endl;
    }


    plane1.PrintInfo();
    plane2.PrintInfo();
    return 0;
}

