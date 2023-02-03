#include <iostream>
using namespace std;
template<typename T>
class SmartPointer
{
public:
	//передаем  указатель на T ( new int это указатель)
	SmartPointer(T* ptr):ptr(ptr) 
	{

	}
	// чистим память 
	~SmartPointer()
	{
		delete ptr;
	}

	// & возващаем ссылку на T чтобы не работать с  копией объекта а на прямую 
	T& operator *() 
	{
		return *ptr;   //возвращаем разыменованный указатель ptr 
	}
private:
	T* ptr; //шаблонный потому что умные указатели работают с любым видоим данных 
};

int main()
{
	setlocale(LC_ALL, "rus");
	//возвращаем указатель new int в конструктор 
	SmartPointer <int> Pointer = new int(5); // new  -возвращает адрес памяти
	//выводим разыменованный ОБЪЕКТ
	cout << *Pointer << endl;
}

