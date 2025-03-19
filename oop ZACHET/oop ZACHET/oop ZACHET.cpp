#include <iostream>
#include <thread>
#include <mutex>
#include<vector>
#include<chrono>
#include <random>
using namespace std;
//задание 1
/*
mutex mtx;
int turn = 0;

void printNumbers() {
    for (int i = 1; i <= 100; ++i) {
        unique_lock<mutex> lock(mtx);
        while (turn != 0) {
            lock.unlock();
            this_thread::yield();
            lock.lock();
        }
        turn = 1;
    }
}

void printLetters() {
    for (char c = 'A'; c <= 'Z'; ++c) {
        unique_lock<mutex> lock(mtx);
        while (turn != 1) {
            lock.unlock();
            this_thread::yield();
            lock.lock();

        }
        cout << " Номер: " << (c - 'A' + 1) << " Буква: " << c << endl;
        turn = 0;

    }
}
//задание 2
const int MAX_SIZE = 10;
vector<int> sharedArray;
mutex mtx1;
bool finished = false;

void producer() {
    for (int i = 0; i < 20; ++i) {
        this_thread::sleep_for(chrono::milliseconds(100));
        unique_lock<mutex> lock(mtx1);
        if (sharedArray.size() < MAX_SIZE) {
            sharedArray.push_back(i);
            cout << "Добавлено: " << i << " | Текущий размер: " << sharedArray.size() << endl;
        }
        else {
            cout << "Массив полон, ждем удаления элемента..." << endl;
        }
    }
    finished = true;
}

void consumer() {
    while (!finished || !sharedArray.empty()) {
        this_thread::sleep_for(chrono::milliseconds(150));
        unique_lock<mutex> lock(mtx1);
        if (!sharedArray.empty()) {
            int value = sharedArray.back();
            sharedArray.pop_back();
            cout << "Удалено: " << value << " | Текущий размер: " << sharedArray.size() << endl;
        }
        else {
            if (!finished) {
                cout << "Массив пуст, ждем добавления элемента..." << endl;
            }
        }
    }
}*/
//zadanie 3
/*class ConditionExample {
private:
    mutex mtx;
    condition_variable cv;
    bool ready = false;

public:
    void worker() {
        unique_lock<mutex> lock(mtx);
        cout << "Рабочий поток ожидает уведомления..." << endl;
        while (!ready) {
            cv.wait(lock);
        }
        cout << "Рабочий поток получил уведомление и продолжает работу!" << endl;
    }

    void notify() {
        {
            lock_guard<mutex> lock(mtx);
            ready = true;
            cout << "Главный поток установил условие." << endl;
        }
        cv.notify_one();
    }

};*/
class Buffer {
private:
    vector<int> buffer;
    size_t maxSize;
    size_t count;
    mutex mtx;
public:
    Buffer(size_t size) : maxSize(size), count(0) {}

    void add(int value) {
        unique_lock<mutex> lock(mtx);
        while (count >= maxSize) {
            lock.unlock();
            this_thread::yield();
            lock.lock();
        }
        buffer.push_back(value);
        count++;
        cout << "Производитель добавил: " << value << endl;
    }

    int remove() {
        unique_lock<mutex> lock(mtx);
        while (count <= 0) {
            lock.unlock();
            this_thread::yield();
            lock.lock();
        }
        int value = buffer.front();
        buffer.erase(buffer.begin());
        count--;
        cout << "Потребитель забрал: " << value << endl;
        return value;
    }


};

class Producer {
private:
    Buffer& buffer;
public:
    Producer(Buffer& buf) : buffer(buf) {}

    void produce() {
        random_device rd;
        mt19937 gen(rd());
        uniform_int_distribution<> dis(1, 100);

        for (int i = 0; i < 10; ++i) {
            int value = dis(gen);
            buffer.add(value);
            this_thread::sleep_for(chrono::milliseconds(100));
        }
    }


};

class Consumer {
private:
    Buffer& buffer;
public:

    Consumer(Buffer& buf) : buffer(buf) {}

    void consume() {
        int sum = 0;
        for (int i = 0; i < 10; ++i) {
            int value = buffer.remove();
            sum += value;
            this_thread::sleep_for(chrono::milliseconds(150));
        }
        cout << "Среднее значение: " << sum / 10.0 << endl;
    }


};
int main() {
    setlocale(LC_ALL, "Ru");
    /*
    thread numberThread(printNumbers);
    thread letterThread(printLetters);


    numberThread.join();
    letterThread.join();
    cout << endl;
    //
    thread producerThread(producer);
    thread consumerThread(consumer);

    producerThread.join();
    consumerThread.join();

    cout << "Программа завершена." << endl;*/
    //zadanie 3
    /*cout << endl;
    ConditionExample example;
    thread workerThread(&ConditionExample::worker, &example);
    this_thread::sleep_for(chrono::seconds(2));
    example.notify();
    workerThread.join();*/
    /**/cout << endl;
    //
    Buffer buffer(5);
    Producer producer(buffer);
    Consumer consumer(buffer);

    thread producerThread(&Producer::produce, &producer);
    thread consumerThread(&Consumer::consume, &consumer);

    producerThread.join();
    consumerThread.join();
    return 0;
}
