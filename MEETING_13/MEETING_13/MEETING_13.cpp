
#include <string>
#include <iostream>
using namespace std;
//задание 1 закоментированног чтобы не ломать код
/*class CharStack {
private:
    string stack; 
    int capacity;      

public:
    // Конструктор
    CharStack(int size) {
        capacity = size;  
        stack.reserve(capacity);  
    }

    // Метод для помещения символа в стек
    void push(char c) {
        if (isFull()) {
            cout << "Стек полон, невозможно добавить символ '" << c << "'." << endl;
            return;
        }
        stack += c; 
    }

    // Метод для вытаскивания символа из стека
    char pop() {
        if (isEmpty()) {
            cout << "Стек пуст, невозможно вытащить символ." << endl;
            return '\0'; 
        }
        char topChar = stack.back(); 
        stack.pop_back(); 
        return topChar;   
    }

    // Метод для получения верхнего символа без удаления
    char peek() const {
        if (isEmpty()) {
            cout << "Стек пуст, нет верхнего символа." << endl;
            return '\0'; 
        }
        return stack.back();
    }

    // Метод для проверки, пуст ли стек
    bool isEmpty() const {
        return stack.empty(); 
    }

    // Метод для проверки, полон ли стек
    bool isFull() const {
        return stack.size() == capacity; 
    }

    // Метод для получения количества символов в стеке
    int size() const {
        return static_cast<int>(stack.size());
    }

    // Метод для очистки стека
    void clear() {
        stack.clear();
    }
};*/
//задание 2 тот же класс но динамический.
class CharStack {
private:
    char* stack;
    int capacity;
    int top;

    void resize() {
        capacity *= 2;
        char* newStack = new char[capacity];
        for (int i = 0; i <= top; ++i) {
            newStack[i] = stack[i];
        }
        delete[] stack;
        stack = newStack;
    }

public:
    CharStack(int size) {
        capacity = size;
        stack = new char[capacity];
        top = -1;
    }

    ~CharStack() {
        delete[] stack;
    }

    void push(char c) {
        if (isFull()) {
            resize();
        }
        stack[++top] = c;
    }

    char pop() {
        if (isEmpty()) {
            cout << "Стек пуст, невозможно вытащить символ." << endl;
            return '\0';
        }
        return stack[top--];
    }

    char peek() const {
        if (isEmpty()) {
            cout << "Стек пуст, нет верхнего символа." << endl;
            return '\0';
        }
        return stack[top];
    }

    bool isEmpty() const {
        return top == -1;
    }

    bool isFull() const {
        return top == capacity - 1;
    }

    int size() const {
        return top + 1;
    }

    void clear() {
        top = -1;
    }
};

int main()
{
    setlocale(LC_ALL,"ru");
    CharStack charStack(5); 

    charStack.push('A');
    charStack.push('B');
    charStack.push('C');
    charStack.push('D');
    charStack.push('E');

    cout << "Верхний символ стека: " << charStack.peek() << endl; 

    charStack.push('F'); 

    cout << "Количество символов в стеке: " << charStack.size() << endl; 

    cout << "Вытаскиваем символ: " << charStack.pop() << endl; 
    cout << "Вытаскиваем символ: " << charStack.pop() << endl; 

    cout << "Количество символов в стеке после выталкивания: " << charStack.size() << endl;

    charStack.clear(); 
    cout << "Стек очищен. Пуст ли стек? " << (charStack.isEmpty() ? "Да" : "Нет") << endl;

    return 0;
}

