#include<iostream>
#include<string>
#include<Windows.h>
#include<fstream>
#include "Excaption.h"
using namespace std;

int main()
{
    setlocale(LC_ALL, "rus");  
	//вызываем функцию Foo
	try 
	{
		Foo(1);
	}
	//Ловим исключение класса exception
	catch (exception& ex ) // указываем ссылку на класс exception ,ex - объект
	{
		cout << "Число меньше 0 " << endl;
	}
	//Ловим исключение класса Myexcaption
	catch (Myexcaption& ex)  // указываем ссылку на класс Myexcaption,ex - объект 
	{
		cout << "Число  = 1" <<  endl;
	}
	return 0;
    
}
