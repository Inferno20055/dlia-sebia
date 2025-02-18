#pragma once
class Fraction
{
private:
	int divisible;
public:
	
	Fraction(int* newdivisible =nullptr) {
		divisible = (newdivisible != nullptr) ? *newdivisible : 0;
	}
	~Fraction() {
		if (divider!=nullptr)
		{
			delete[]divider;
		}
	}
	int divider[50];
	int set_divisible()const {
		return divisible;
	}
	int get_divisible(const int& newdivisible) {
		return divisible = newdivisible;
	}
	void Input_1();
	void Print_2();
};

