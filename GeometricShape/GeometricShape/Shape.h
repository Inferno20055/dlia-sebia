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
	//�����������
	Shape(double r=0,double m=0) :real(r),mnim(m) {}
	//������ � ������
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
	//�������� ��������
	Shape operator+(const Shape& other)const {
		return Shape(real+other.real,mnim+ other.mnim);
	}
	//�������� ���������
	Shape operator-(const Shape& other)const {
		return Shape(real - other.real, mnim - other.mnim);
	}
	//�������� ��������� �� ����������� �����
	Shape operator*(const Shape& other)const {
		return Shape(real * other.real - mnim * other.mnim,
					 real * other.real + mnim * other.mnim);
	}
	//�������� ��������� �� �������������� �����
	Shape operator*(double scal)const {
		return Shape(real * scal, mnim * scal);
	}
	//��� ���������� ������
	double moduls()const {
		return sqrt(real * real + mnim * mnim);
	}
	//��� ���������� ���������
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

