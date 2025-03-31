#include <iostream>
#include <vector>
#include <string>
#include <memory>
#include"DeliveryStrategy.h"
#include"Observer.h"
#include"Request.h"
#include"Command.h"
#include"Visitor.h"

using namespace std;

int main()
{
	setlocale(LC_ALL,"Ru");
    //1
    /*int choice;
    cout << "Выберите способ расчета стоимости доставки:\n";
    cout << "1. Фиксированная ставка\n";
    cout << "2. По весу\n";
    cout << "3. По расстоянию\n";
    cout << "Ваш выбор: ";
    cin >> choice;

    DeliveryStrategy* strategy = nullptr;

    switch (choice) {
    case 1:
        strategy = new FlatRateDelivery();
        break;
    case 2:
        strategy = new WeightBasedDelivery();
        break;
    case 3:
        strategy = new DistanceBasedDelivery();
        break;
    default:
        cout << "Неверный выбор!" << endl;
        return 1;
    }

    Order order(strategy);
    double totalCost = order.calculateTotalCost();
    cout << "Стоимость доставки: " << totalCost << " рублей" << endl;

    delete strategy;*/
    //2
    /*WeatherData weatherData;

    SMSNotification smsObserver;
    EmailNotification emailObserver;
    PhoneNotification phoneObserver;

    weatherData.addObserver(&smsObserver);
    weatherData.addObserver(&emailObserver);
    weatherData.addObserver(&phoneObserver);

    weatherData.setMeasurements(20.0, 760.0, 70.0);
    weatherData.setMeasurements(22.0, 755.0, 65.0);*/
    //3
    //// Создание обработчиков
    //JuniorSupport junior;
    //SeniorSupport senior;
    //ManagerSupport manager;

    //// Установка цепочки обработки
    //junior.setNextHandler(&senior);
    //senior.setNextHandler(&manager);

    //// Создание запроса
    //Request request("Проблема с настройкой программного обеспечения");

    //// Обработка запроса
    //junior.handleRequest(request);
    //4
    /*TextEditor editor;
    editor.setText("Пример текста для редактирования.");

    int choice;
    while (true) {
        cout << "Доступные команды:" << endl;
        cout << "1. Копировать выделенный текст" << endl;
        cout << "2. Вставить скопированный текст" << endl;
        cout << "3. Удалить выделенный текст" << endl;
        cout << "4. Отменить последнее действие" << endl;
        cout << "Ваш выбор: ";
        cin >> choice;

        switch (choice) {
        case 1: {
            auto command = make_shared<CopyCommand>(editor);
            editor.addCommand(command);
            break;
        }
        case 2: {
            auto command = make_shared<PasteCommand>(editor);
            editor.addCommand(command);
            break;
        }
        case 3: {
            auto command = make_shared<DeleteCommand>(editor);
            editor.addCommand(command);
            break;
        }
        case 4: {
            editor.undo();
            break;
        }
        default:
            cout << "Неверный выбор. Попробуйте снова." << endl;
        }

        cout << "Текущий текст: " << editor.getText() << endl;
    }*/
    //5
    Rectangle rectangle(5, 3);
    Circle circle(4);
    Triangle triangle(3, 4, 5);

    AreaCalculator areaCalculator;
    PerimeterCalculator perimeterCalculator;

    cout << "Фигура: Прямоугольник" << endl;
    rectangle.accept(areaCalculator);
    rectangle.accept(perimeterCalculator);
    cout << endl;

    cout << "Фигура: Круг" << endl;
    circle.accept(areaCalculator);
    circle.accept(perimeterCalculator);
    cout << endl;

    cout << "Фигура: Треугольник" << endl;
    triangle.accept(areaCalculator);
    triangle.accept(perimeterCalculator);
    cout << endl;
	return 0;
}
