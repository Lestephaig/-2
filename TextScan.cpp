#include <iostream>
#include <fstream>
#include <string>
#include "TextScan.h"

using namespace std;

void TextScaner()
{
    fstream file; // создаем поток ввода
    file.open("Text.txt"); // открытие файла

    if (!file.is_open()) // если файл не открылся
    {
        cout << "Ошибка открытия файла!" << endl;
        exit(0);
    }

    else
    {
        string line; // строка, в которую будут считываться значения из файла
        string suggestion;
        string *arraySuggestion = new string[1000000];

        while (!file.eof()) // пока не конец файла
        {
            string bufLine;
            getline(file, bufLine); // считываем строку
            line += bufLine + '\n';
        }

        bool flagFirst = false;
        int idS = 0;

        for (int id = 0; id < line.size()+1; id++)
        {
            suggestion += line[id];
            if (line[id] == '.' || line[id] == '?' || line[id] == '!')
            {
                arraySuggestion[idS++] = suggestion;
                suggestion.clear();
            }
        }
        // cout << arraySuggestion[1];
        // cout << arraySuggestion[0];
        while (idS >= 0) cout << arraySuggestion[idS--];
        delete [] arraySuggestion;
    }

    file.close(); // закрываем файл
}
