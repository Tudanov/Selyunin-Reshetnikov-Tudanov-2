#include "Library.h"
#include <iostream>

using namespace std;

int _stateMenu;
void DataInitialization()
{
	ofstream _buf("Buffer.txt");
	if (!_buf)
		cout << "Ошибка создания буферного файла!" << endl;
	_buf.close();
}

void DataEntry()
{
	string _surname;
	int _phoneNum;
	string _city;
	int n;
	cout << "Введите количество данных: ";
	cin >> n;
	ofstream record("Buffer.txt", ios::app);

	if (record)
	{
		record << n << endl;

		for (int i = 0; i < n; i++)
		{
			cout << "Введите данные №1 (Фамилия): ";
			cin >> _surname;
			cout << "Введите данные №2 (Номер телефона): ";
			cin >> _phoneNum;
			cout << "Введите данные №3 (Город): ";
			cin >> _city;
			record << _surname << endl;
			record << _phoneNum << endl;
			if (i < n - 1)
				record << _city << endl;
			else
				record << _city;
			cout << "_____________" << endl;
		}
	}
	else
		cout << "Ошибка открытия файла" << endl;
	record.close();
}

void DataReading(string fileName)
{
	ifstream reading(fileName);
	ofstream record("Buffer.txt", ios::out);
	if (reading)
	{
		if (record)
		{
			string _surname;
			int _phoneNum;
			string _city;
			int n;
			reading >> n;
			record << n << endl;
			for (int i = 0; i < n; i++)
			{
				reading >> _surname;
				reading >> _phoneNum;
				if (i < n - 1)
					record << _city << endl;
				else
					record << _city;
			}
			cout << "Данные считаны" << endl;
		}
		else
			cout << "Ошибка открытия буфера!" << endl;
	}
	else
		cout << "Ошибка открытия файла!" << endl;
}

void Print()
{
	ifstream reading("Buffer.txt");
	if (reading)
	{
		string _surname;
		int _phoneNum;
		string _city;
		int n;
		reading >> n;
		cout << "Количество данных: " << n << endl << endl;
		for (int i = 0; i < n; i++)
		{
			cout << "Данные об №" << i + 1 << endl;
			reading >> _surname;
			cout << "Данные №1 (Фамилия): " << _surname << endl;
			reading >> _phoneNum;
			cout << "Данные №2 (Номер телефона): " << _phoneNum << endl;
			reading >> _city;
			cout << "Данные №3 (Город): " << _city << endl;
			cout << "___________________________" << endl;
		}
	}
	else
		cout << "Ошибка открытия файла" << endl;
	reading.close();
}

void DataChange()
{
	Copy();
	ifstream reading("Buffer_.txt");//????????????????????????????
	ofstream record("Buffer.txt", ios::out);
	if (reading)
	{
		if (record)
		{
			string _surname;
			int _phoneNum;
			string _city;
			int n, _n;
			reading >> n;
			cout << "Выберите номер изменяемого элемента (от 1 до " << n << "): ";
			cin >> _n;
			_n++;
			system("cls");
			record << n << endl;
			if (_n >= 0 && _n < n)
			{
				for (int i = 0; i < n; i++)
				{
					if (i != _n)
					{
						reading >> _surname;
						record << _surname << endl;
						reading >> _phoneNum;
						record << _phoneNum << endl;
						reading >> _city;
						if (i < n - 1)
							record << _city << endl;
						else
							record << _city;
					}
					else
					{
						cout << "Введите данные №1 (Фамилия): ";
						cin >> _surname;

						cout << "Введите данные №2 (Номер телефона): ";
						cin >> _phoneNum;

						cout << "Введите данные №3 (Город): ";
						cin >> _city;

						record << _surname << endl;
						record << _phoneNum << endl;
						if (i < n - 1)
							record << _city << endl;
						else
							record << _city;
						reading >> _surname;
						reading >> _phoneNum;
						reading >> _city;
					}
				}
				cout << "Данные измененны!" << endl;
			}
			else
				cout << "Номер введён не верно!" << endl;
		}
		else
			cout << "Ошибка открытия файла!" << endl;
	}
	else
		cout << "Ошибка открытия буферного файла!" << endl;

	record.close();
}

void Copy()
{
	ifstream reading("Buffer.txt");
	ofstream record("Buffer_.txt", ios::out);
	if (reading)
	{
		if (record)
		{
			string _surname;
			int _phoneNum;
			string _city;
			int n;
			reading >> n;
			record << n << endl;
			for (int i = 0; i < n; i++)
			{
				reading >> _surname;
				record << _surname << endl;
				reading >> _phoneNum;
				record << _phoneNum << endl;
				reading >> _city;
				if (i < n - 1)
					record << _city << endl;
				else
					record << _city;
			}
		}
		else
			cout << "Ошибка открытия файла!" << endl;
	}
	else
		cout << "Ошибка открытия буферного файла!" << endl;
	record.close();
	reading.close();
}

void Menu()
{
	cout << "Выберите действие:" << endl
		<< "(0) Выходиз программы." << endl
		<< "(1) Ввод данных." << endl
		<< "(2) Вывод данных." << endl
		<< "(3) Изменение данных." << endl
		<< "(4) Удаление данных." << endl
		<< "(5) Добавление данных." << endl
		<< "(6) Сохранение данных." << endl
		<< "Ваш выбор: ";
	cin >> _stateMenu;
}

void main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	DataInitialization();

	Menu();

	int _actions;
	string fileName;

	while (_stateMenu != 0)
	{
		switch (_stateMenu)
		{
		case 1:
			system("cls");

			cout << "Ввод вручную или из файла?: ";
			cin >> _actions;

			system("cls");

			if (_actions == 1)
			{
				DataEntry();
			}
			else
			{
				cout << "Введите название файла: ";
				cin >> fileName;

				DataReading(fileName);
			}
			system("pause");
			system("cls");
			Menu();
			break;
		case 2:
			system("cls");
			Print();
			system("pause");
			system("cls");
			Menu();
			break;
		case 3:
			system("cls");
			DataChange();
			system("pause");
			system("cls");
			Menu();
			break;
		case 4:
			system("cls");
			DeleteData();
			system("pause");
			Menu();
			break;
		case 5:
			system("cls");
			AddData();
			system("pause");
			system("cls");
			Menu();
			break;
		case 6:
			system("cls");
			cout << "Введите название файла: ";
			cin >> fileName;
			system("cls");
		}
	}
}