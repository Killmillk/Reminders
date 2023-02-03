#include <iostream>
using namespace std;

class Rectangle
{
public: 
    Rectangle(int w = 1, int h = 1) 
    {
        //выделяем память и присваиваем данные переменным
        width = new int;
        height = new int;
        *width = w;
        *height = h;
    } 
    ~Rectangle()
    { 
        //освобождаем память 
        delete width;
        delete height;
    }
    
    void display() const
    {
        //выводим в консоль
        cout << "Width: " << *width << endl;
        cout << "Height: " << *height << endl;
    }   
    Rectangle(const Rectangle& src);// протоип функции
    Rectangle& operator=(const Rectangle& src); // протоип функции(перегрузка = ) 
    //сеттеры 
    int setWidth(int w) { *width = w; return w; }
    int setHeight(int h) { *height = h; return h; }
private:
    int* width, * height;
};

Rectangle::Rectangle(const Rectangle& copy)
{
    // выделяем память под новый объект
    width = new int;
    height = new int;

    // разыменовываем указатели и копируем содержимое адреса памяти, на который они ссылаются 
    *width = *(copy.width);
    *height = *(copy.height);
}
Rectangle& Rectangle::operator = (const Rectangle& copy) // Перегружаем оператор = для объектов 
{
    // проверяем на самоприсваивание
    if (this == &copy)
    {
        return *this;
    }
    // освобождаем занятую память
    delete width;
    delete height;

    // выделяем память
    width = new int;
    height = new int;

    // разыменовываем указатели и копируем содержимое адреса памяти, на который они ссылаются
    *width = *(copy.width);
    *height = *(copy.height);

    // возвращаем ссылку на перезаписанный объект

    return *this;
}
int main()
{
    Rectangle rect1(1, 7);
    Rectangle rect2 = rect1;
    rect1.setHeight(10);
    cout << "First Rectangle: " << endl;
    rect1.display();
    cout << "Second Rectangle: " << endl;
    rect2.display();
    return 0;
}
