#include <iostream>
#include <string.h>
#include "Price.h"

using namespace std;

// конструктор по умолчанию
Price::Price()
{
    this->name = "None";
    this->store = "None";
    this->cost = "None";

    cout << "Вызван конструктор по умолчанию класса Price" << endl;
}

// конструктор с параметром
Price::Price(string name, string store, string cost)
{
    this->name = name;
    this->store = store;
    this->cost = cost;

    cout << "Вызван конструктор с параметром класса Price" << endl;
}

// конструктор копирования
Price::Price(const Price &p)
{
    this->name = p.name;
    this->store = p.store;
    this->cost = p.cost;

    cout << "Вызван конструктор копирования класса Price" << endl;
}

// деструктор
Price::~Price()
{
    cout << "Вызван деструктор класса Price" << endl;
}

// метод извлечения полей
void Price::Extract()
{
    cout << *this;
}

// метод получения полей
void Price::Get()
{
    // обнуляем поток ввода
    string buf;
    getline(cin, buf);

    string choice; // переменная выбора поля
    cout << "\nЧто хотите получить?\n" <<
                "1 - Название\n" <<
                "2 - Магазин\n" <<
                "3 - Стоимость\n" <<
                "4 - Все поля" << endl;
    cout << "Выбор: ";
    cin >> choice; // ввод

    // обработка исключительных ситуаций
    try
    {
        for (int id = 0; id < choice.size(); id ++)
        {
            if (choice[id] >= 'A' && choice[id] <= 'Z') throw "Error";
        }
    }
    catch(const char*mssg)
    {
        cout << "Неверный ввод" << endl;
    }

    if (choice == "1") cout << "Название: " << this->name << endl;
    else if (choice == "2") cout << "Магазин: " << this->store << endl;
    else if (choice == "3") cout << "Стоимость: " << this->cost << endl;
    else if (choice == "4") cout << "Название: " << this->name << " | Магазин: " << this->store << " | Стоимость: " << this->cost << endl;
    else
    {
        cout << "Ошибка выбора" << endl;
        exit(0);
    }
}

// метод получения информации о товаре
void Price::GetInformatio()
{
    cout << "Название: " << this->name << " | Магазин: " << this->store << " | Стоимость: " << this->cost << endl;
}

// метод получения поля названия (для сортировки)
string Price::GetName()
{
    return this->name;
}

// метод получения магазина
string Price::GetStore()
{
    return this->store;
}

// метод получения цены
string Price::GetCost()
{
    return this->cost;
}

// метод установки значения
void Price::Set()
{
    // обнуляем поток ввода
    string buf;
    getline(cin, buf);

    cin >> *this;
}

void Price::Change()
{
    // обнуляем поток ввода
    string buf;
    getline(cin, buf);

    string choice;
    cout << "\nЧто хотите получить?\n" <<
                "1 - Название\n" <<
                "2 - Магазин\n" <<
                "3 - Цена\n" << endl;
    cout << "Выбор: ";
    cin >> choice;

    // обработка исключительных ситуаций
    try
    {
        for (int id = 0; id < choice.size(); id ++)
        {
            if (choice[id] >= 'A' && choice[id] <= 'Z') throw "Error";
        }
    }
    catch(const char*mssg)
    {
        cout << "Неверный ввод" << endl;
    }

    if (choice == "1")
    {
        getline(cin, choice);

        cout << "Название: ";
        getline(cin, this->name);
    }

    else if (choice == "2")
    {
        getline(cin, choice);

        cout << "Магазин: ";
        getline(cin, this->store);
    }

    else if (choice == "3")
    {
        getline(cin, choice);

        cout << "Цена: ";
        getline(cin, this->cost);
    }

    else
    {
        cout << "Ошибка выбора" << endl;
        exit(0);
    }
}

// перегрузка оператора вывода
std::ostream &operator<< (std::ostream &stream, Price &p) // перегрузка оператора извлеченния
{
    stream << "\nВсе поля класса:" << endl;
    stream << p.name << endl;
    stream << p.store << endl;
    stream << p.cost << endl;

    return stream;
}

// перегрузка оператора ввода
std::istream &operator>> (std::istream &stream, Price &p) // перегрузка оператора вставки
{
    string buf;

    cout << "\nВставка значений:" << endl;
    cout << "Названиие: ";
    getline(stream, buf);
    p.name = buf;

    cout << "Магазин: ";
    getline(stream, buf);
    p.store = buf;

    cout << "Цена: ";
    getline(stream, buf);
    p.cost = buf;

    return stream;
}
