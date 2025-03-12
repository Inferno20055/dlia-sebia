#include <iostream>
using namespace std;

template<typename T>
class Array {
private:
    T* data;         
    int size;         
    int capacity;    

    void resize(int newCapacity) {
        T* newData = new T[newCapacity]; 
        for (int i = 0; i < size; i++) {
            newData[i] = data[i]; 
        }
        delete[] data; 
        data = newData; 
        capacity = newCapacity; 
    }

public:
    Array() : data(nullptr), size(0), capacity(0) {}

    ~Array() {
        delete[] data; 
    }

    int getsize() const {
        return size; 
    }

    void setsize(int newSize, int grow = 1) {
        if (newSize > capacity) {
            int newCapacity = capacity + grow;
            while (newCapacity < newSize) {
                newCapacity += grow;
            }
            resize(newCapacity); 
        }
        size = newSize; 
    }

    int getupperbound() const {
        return size > 0 ? size - 1 : -1; 
    }

    bool IsEmpty() const {
        return size == 0;
    }

    void FreeExtra() {
        resize(size); 
    }

    void RemoveAll() {
        size = 0; 
    }

    T& GetAt(int index) {
        if (index < 0 || index >= size) {
            cout << "Индекс вне границы." << endl;
            exit(1); 
        }
        return data[index]; 
    }

    void SetAt(int index, const T& value) {
        if (index < 0 || index >= size) {
            cout << "Индекс вне границы." << endl;
            exit(1);
        }
        data[index] = value; 
    }

    T& operator[](int index) {
        return GetAt(index); 
    }

    void Add(const T& value) {
        setsize(size + 1); 
        data[size - 1] = value; 
    }

    void Append(const Array<T>& other) {
        for (int i = 0; i < other.size; ++i) {
            Add(other.data[i]); 
        }
    }

    Array<T>& operator=(const Array<T>& other) {
        if (this != &other) {
            delete[] data;
            size = other.size;
            capacity = other.capacity;
            data = new T[capacity];
            for (int i = 0; i < size; ++i) {
                data[i] = other.data[i]; 
            }
        }
        return *this; 
    }

    T* GetData() {
        return data; 
    }

    void InsertAt(int index, const T& value) {
        if (index < 0 || index > size) {
            cout << "Индекс вне границы." << endl;
            exit(1); 
        }
        Add(value);
        for (int i = size - 1; i > index; i--) {
            data[i] = data[i - 1];
        }
        data[index] = value;
    }

    void RemoveAt(int index) {
        if (index < 0 || index >= size) {
            cout << "Индекс вне границы." << endl;
            exit(1); 
        }
        for (int i = index; i < size - 1; i++) {
            data[i] = data[i + 1];
        }
        --size; 
    }
};

int main() {
    setlocale(LC_ALL, "Ru");
    Array<int> arr;
    arr.setsize(5);
    arr.SetAt(0, 10);
    arr.SetAt(1, 20);
    arr.SetAt(2, 30);
    arr.SetAt(3, 40);
    arr.SetAt(4, 50);

    cout << "Элементы массива: " << endl;
    for (int i = 0; i < arr.getsize(); i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    arr.Add(60); // Добавляем элемент
    cout << "После добавления 60: " << endl;
    for (int i = 0; i < arr.getsize(); i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    arr.InsertAt(1, 45); // Вставляем 45 в индекс 1
    cout << "После вставки 45 в индекс 1:" << endl;
    for (int i = 0; i < arr.getsize(); i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    arr.RemoveAt(4); // Удаляем элемент с индексом 4
    cout << "После удаления элемента с индексом 4: " << endl;
    for (int i = 0; i < arr.getsize(); i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    arr.RemoveAll(); // Удаляем все элементы

    cout << "После удаления всех элементов остается пусто? " << (arr.IsEmpty() ? "yes" : "no") << endl;

    return 0;
}