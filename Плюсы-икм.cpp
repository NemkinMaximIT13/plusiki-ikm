#include <iostream>
#include <string>
#include "Header.h"
using namespace std;

int main()
{
    string chislo1, chislo2;
    //Ввод чисел с проверкой корректности ввода
    cout << "Введите первое число:" << endl;
    cin >> chislo1;
    while (!IsCorrect(chislo1))
    { 
        cin >> chislo1;
    }
    cout << "Введите второе число:" << endl;
    cin >> chislo2;
    while (!IsCorrect(chislo2))
    {
        cin >> chislo2;
    }
    cout << "-----------------------------------------------------" << endl;
    while (comparelen(chislo1, chislo2) > 0)//до тех пор, пока первое число не станет меньше второго или не будет ему равно, будет производиться постоянное вычитание
    {
        chislo1 = Vichitanie(chislo1, chislo2);
    }
    if (comparelen(chislo1, chislo2) == 0)
    {
        cout << "Остаток от деления равен 0";
    }
    else
    {
        cout << "Остаток от деления равен " << chislo1;
    }
}
