#pragma once
class Pointer
{
private:
    int x;
    int y;
    int z;

public:
    
    Pointer(int* newX = nullptr, int* newY = nullptr, int* newZ = nullptr) {
        x = (newX != nullptr) ? *newX : 0;
        y = (newY != nullptr) ? *newY : 0;
        z = (newZ != nullptr) ? *newZ : 0;
    }
    ~Pointer() {
         
    }
    int set_x() const {
        return x;
    }

    int get_x(const int& newX) {
        return x = newX;
    }

    int set_y() const {
        return y;
    }

    int get_y(const int& newY) {
        return y = newY;
    }

    int set_z() const {
        return z;
    }

    int get_z(const int& newZ) {
        return z = newZ;
    }

    void Print();

};