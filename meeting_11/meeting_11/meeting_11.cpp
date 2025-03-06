#include <iostream>
#include<cmath>
using namespace std;
template<typename T>
T Calculate(T* arr,int size) {
	if (size <= 0)
	{
		cout<<"размерность массива не может быть меньше или равна нулю" << endl;
	}
	T sum = 0;
	for (int i = 0; i < size; i++)
	{
		sum += arr[i];
	}
	return sum / size;
}
template<typename T>
T Len(T a,T x,T b) {
	return (a * x) + b;
}
template<typename T>
T Fun(T a,T b,T x,T c) {
	return (a * pow(x, 2)) + (b*x) + c;
}
template<typename T>
T MaxEl(T a,T b) {

	if (a>b)
	{
		cout << "Наибольшее число из двух"<<endl;
		return a;
	}
	else if (a==b)
	{
		cout << "Числа равны:" << endl;
	}
	else
	{
		cout << "Наибольшее число из двух" << endl;
		return b;
	}
}
template<typename T>
T MinEl(T a1, T b1) {

	if (a1 < b1)
	{
		cout << "Наименьшее  число из двух" << endl;
		return a1;
	}
	else if (a1 == b1)
	{
		cout << "Числа равны:" << endl;
	}
	else
	{
		cout << "Наименьшее число из двух" << endl;
		return b1;
	}
}
int main()
{
	setlocale(LC_ALL,"ru");
	const int size = 5;
	float array[] = { 1.2,2.5,3,4,5 };
	cout << "Среднее арефметическое: " << Calculate(array,size)<<endl;

	int a = 4;
	int b = 5;
	cout <<"Наибольшее число из " << a << " и " << b <<": " << MaxEl(a, b) << endl;

	float a1=2;
	float b1 = 1.2;
	cout << "Наименьшее число из " << a1 << " и " << b1 << ": " << MinEl(a1, b1) << endl;

	int a2=2,x=1,b2=3,c=1;
	cout << "Ответ квадратного уровнения: " << Fun(a2, x, b2, c) << endl;
	
	int a3=2, x2=1, b3=4;
	cout << "Ответ ленейного уровнения: " << Len(a3,x2,b3) << endl;

}

