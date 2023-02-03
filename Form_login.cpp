#include <iostream>
#include<string>
#include<fstream>
#include <cstdlib>
using namespace std;

int RegUser()
{
	string password, name;
	cout << "Введите имя: " << endl; cin >> name;
	cout << "Придумайте пароль: " << endl; cin >> password;
	ofstream File;
	File.open(name + ".txt");
	File << name << endl << password;
	File.close();
	if (File.is_open())
	{
		cout << "Что то пошло не так!";
	}
	else
	{
		cout << "Вы успешно зарегистрировались!" << endl;
	}
	return 0;
}


bool LoginCheck()
{
	string password, name, un, pw;
	cout << "Введите имя:" << endl; cin >> name;
	cout << "Введите пароль:" << endl; cin >> password;
	ifstream read(name + " .txt");
	while (read)
	{
		getline(read, un);
		getline(read, pw);
	}
	if (un == name && pw == password)
	{
		return true;
	}
	else
	{
		return false;
	}
	read.close();

}

bool Chek() {

	int status = LoginCheck();
	if (!status)
	{
		cout << "Не правильный логин или пароль" << endl;
		system("PAUSE");
		return 0;
	}
	else
	{
		cout << "Вы успешно вошли" << endl;
		return 1;
	}
}




int main()
{
	setlocale(LC_ALL, "rus");
	cout << "Выберите 1 чдля Регистрации:" << endl;
	cout << "Выберите 2 чтобы войти" << endl;
	cout << "Выберите 3 чтобы выйти:" << endl;
	int menu;
	cin >> menu;
	switch (menu)
	{
	case 1:RegUser();
		main();
		break;

	case 2:Chek();
		break;
	case 3:
		exit(0);
		break;
	default:
		cout << "Что то пошло  не так" << endl;
	}

}
