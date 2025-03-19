#include <iostream>
#include <string>
#include <memory>
#include<vector>
#include<algorithm>
#include"Car.h"
#include"Fruit.h"
using namespace std;
int main()
{
    setlocale(LC_ALL, "Ru");
    //zadanie 1
    unique_ptr<Car> myCar = make_unique<Car>("Toyota", "Camry", 2020);
    shared_ptr<Car> myCar1 = make_shared<Car>("Toyota", "Camry", 2020);
    shared_ptr<Car> myCar2 = myCar1;
    weak_ptr<Car> myWeakCar = myCar1;

    myCar1->displayInfo();
    myCar2->displayInfo();
    cout << "Количество владельцев: " << myCar1.use_count() << endl;

    if (auto sharedCar = myWeakCar.lock()) {
        cout << "Объект все еще существует." << endl;
        sharedCar->displayInfo();
    }
    else {
        cout << "Объект больше не существует." << endl;
    }
    cout << endl;

    //zadanie 2
     // Шаг 2: Создание списка фруктов
    vector<Fruit> fruits = {
        Fruit("Яблоко", 0.80, 0.2),
        Fruit("банан", 1.20, 0.15),
        Fruit("Вишня", 2.00, 0.1),
        Fruit("Ананас", 1.50, 3.50),
        Fruit("Малина", 1.00, 0.05)
    };

    // Шаг 3a: Вывести все фрукты, цена которых больше $1.00
    double threshold = 1.00;
    cout << "Фрукты, цена которых превышает $"  << ":\n";
    for_each(fruits.begin(), fruits.end(), [threshold](const Fruit& fruit) {
        if (fruit.price > threshold) {
            fruit.display();
        }
        });
    cout << endl;
    // Шаг 3b: Найти самый тяжелый фрукт
    auto heaviestFruit = max_element(fruits.begin(), fruits.end(), [](const Fruit& a, const Fruit& b) {
        return a.weight < b.weight;
        });

    if (heaviestFruit != fruits.end()) {
        cout << "Самый тяжелый фрукт: ";
        heaviestFruit->display();
    }
    cout << endl;
    // Шаг 3c: Отсортировать фрукты по возрастанию цены
    sort(fruits.begin(), fruits.end(), [](const Fruit& a, const Fruit& b) {
        return a.price < b.price;
        });

    cout << "Фрукты, отсортированные по цене:\n";
    for (const auto& fruit : fruits) {
        fruit.display();
    }
    return 0;
}
