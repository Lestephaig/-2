#ifndef PRICE_H
#define PRICE_H

#include <iostream>
#include <string.h>
using namespace std;

class Price
{
private:
    string name; // название товара
    string store; // магазин
    string cost; // стоимость

public:
    Price(); // конструктор по умолчанию
    Price(string name, string store, string cost); // конструктор с параметром
    Price(const Price &p); // конструктор копирования
    ~Price(); // деструктор

    void Extract(); // метод извлечения значения
    void Get(); // метод получения полей
    void GetInformatio(); // метод получения информации о конкретном товаре
    string GetName(); // метод получения поля названия для упорядочивания
    string GetStore(); // метод получения магазина
    string GetCost(); // метод получения стоимости
    void Set(); // метод установки значения
    void Change(); // метод редактирования значений

    friend ostream &operator<< (ostream &stream, Price &p); // перегрузка оператора извлеченния
    friend istream &operator>> (istream &stream, Price &p); // перегрузка оператора вставки
};

#endif
