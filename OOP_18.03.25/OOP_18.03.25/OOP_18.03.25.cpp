#include <iostream>
#include <string>
#include <memory>
#include<algorithm>

#include"Car.h"
#include"Fruit.h"

using namespace std;

int main() {
    setlocale(LC_ALL,"Ru");
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
    vector<Fruit> fruits={ 
        Fruit("Яблоко", 0.50, 0.2),
        Fruit("Банан", 0.30, 0.15),
        Fruit("Апельсин", 0.80, 0.25),
        Fruit("Киви", 1.20, 0.1),
        Fruit("Груша", 1.00, 0.3) };
    cout << "Фрукты цена которых больше 1 доллора." << endl;
    for (const auto& fruit:fruits)
    {
        if (fruit.getPrice()>1.00) {
            cout << fruit.getName() << " - $" << fruit.getPrice() << endl;
        }
    }

    return 0;
}