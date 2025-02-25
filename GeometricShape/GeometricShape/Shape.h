#pragma once
#include <iostream>
#include <cmath>
using namespace std;
class Shape
{
private:
	double real;
	double mnim;
public:
	//конструктор
	Shape(double r=0,double m=0) :real(r),mnim(m) {}
	//гетеры и сетеры
	double getReal()const {
		return real;
	}
	double getmnim()const {
		return mnim;
	}
	void setReal(double r) {
		real = r;
	}
	void setMnim(double m) {
		mnim = m;
	}
	//оператор сложения
	Shape operator+(const Shape& other)const {
		return Shape(real+other.real,mnim+ other.mnim);
	}
	//оператор вычитания
	Shape operator-(const Shape& other)const {
		return Shape(real - other.real, mnim - other.mnim);
	}
	//оператор умножения на комплексное число
	Shape operator*(const Shape& other)const {
		return Shape(real * other.real - mnim * other.mnim,
					 real * other.real + mnim * other.mnim);
	}
	//оператор умножения на действительное число
	Shape operator*(double scal)const {
		return Shape(real * scal, mnim * scal);
	}
	//для вычисления модуля
	double moduls()const {
		return sqrt(real * real + mnim * mnim);
	}
	//для вычисления аргумента
	double arguments()const {
		return atan2(mnim,real);
	}
	void Print() {
		cout << real;
		if (mnim<=0)
		{
			cout << "+ " << mnim << "i" << endl;
		}
		else
		{
			cout << "- " << -mnim << "i" << endl;
		}
	}
};

