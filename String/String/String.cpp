#include <iostream>
#include "String.h"
using namespace std;
int main()
{
    setlocale(LC_ALL, "Ru");
    String str1("Привет мир!"); 

    String str2(10); 
    str2.setString("Short"); 
    str2.display(); 

    String str3 = str1; 
    str3.display(); 

    str1.setString("Dynamic memory handling!"); 
    str1.display(); 

    return 0;
}
