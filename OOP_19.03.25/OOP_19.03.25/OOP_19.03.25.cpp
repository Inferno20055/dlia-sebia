#include <iostream>
#include <thread>
#include <mutex>
#include<vector>
#include<chrono>
using namespace std;
//задание 1
/**/
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
        cout <<  " Номер: " << (c - 'A' + 1) << " Буква: " << c<< endl;
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
}
int main() {
    setlocale(LC_ALL,"Ru");
    /**/
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

    cout << "Программа завершена." << endl;
    return 0;
}