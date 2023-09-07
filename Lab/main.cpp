#include<iostream>
using namespace std;

class Student
{
	char* name;
	int age;
	char* email;
public:
	Student()
	{
		cout << "Constructor by def.\n";
		name = nullptr;
		email = nullptr;
		age = 0;
	}
	Student(const char* n, const char* e, int a)// Oleg 20
	{
		name = new char[strlen(n) + 1]; // выделяем память при создани  объекта !!
		strcpy_s(name, strlen(n) + 1, n);

		email = new char[strlen(e) + 1]; // выделяем память при создани  объекта !!
		strcpy_s(email, strlen(e) + 1, e);
		age = a;
		cout << "Constructor 3 params\n";
	}
	void Input()
	{
		char buff[20];
		cout << "Enter name: ";
		cin >> buff;
		if (name != nullptr)
		{
			cout << "Delete -> " << name << "... \n";
			delete[]name;
		}
		name = new char[strlen(buff) + 1];
		strcpy_s(name, strlen(buff) + 1, buff);

		char buff1[36];
		cout << "Enter email: ";
		cin >> buff1;
		if (email != nullptr)
		{
			cout << "Delete -> " << email << "... \n";
		}
		email = new char[strlen(buff1) + 1];
		strcpy_s(email, strlen(buff1) + 1, buff1);

		cout << "Enter age: ";
		cin >> age;
	}
	void Print()
	{
		cout << "Name: " << name << "\tAge: " << age << " Email: " << email << endl;
	}
	~Student()
	{
		delete[] name; // явно освобождаем память при уничтожении объекта !!!!
		cout << "Destructor\n";
	}



};

int main()
{
	Student obj1("Oleg", "olegdogcom", 20);
	obj1.Print();
	obj1.Input();
	obj1.Print();

}

/* добавить:
   * поле емайл(char*)
   * конструктор  с 3я параметрами
   * методы аксессоры
   * удаление выделенной динамической памяти в деструкторе.
*/