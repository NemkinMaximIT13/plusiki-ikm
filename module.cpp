#include <iostream>
#include <string>
using namespace std;

bool IsCorrect(string& input) //проверка "на дурака"
{
    int len = input.length();
    if (len <= 20)//проверка на то, набрано ли минимальное количество символов в неотрицательном числе без учета ведущих нулей
    {
        cout << "Длина введенного вами числа меньше необходимого, пожалуйста, попробуйте ввести другое число:" << endl;
        return false;
    }
    string numbers = "1234567890";
    for (int i = 0; i < len; i++)//проверка на то, не содержит ли введенная строка букв или других символов, кроме цифр.
    {
        if (numbers.find(input[i]) == numbers.npos)
        {
            cout << "В введенной вами строке есть некорректные символы, пожалуйста, попробуйте ввести другое число:" << endl;
            return false;
        }
    }
    if (input[0] == '0')//Проверка на то, что не было введено число с ведущими нулями.
    {
        cout << "Вводимое число не должно содержать ведущие нули, пожалуйста попробуйте ввести другое число:" << endl;
        return false;
    }
    return true;
}

int comparelen(string& a, string& b) { //программа для сравнения двух чисел.
    if (a.length() < b.length()) return -1;
    if (a.length() > b.length()) return 1;
    //Если длина строк совпадает, то начинается сравнение по символам.
    for (int i = 0; i < a.length(); i++) {
        if (a[i] < b[i]) return -1;
        if (a[i] > b[i]) return 1;
    }
    return 0;
}

string Vichitanie(string& a, string& b) {
    string A = a;
    string B = b;
    if (B.size() < A.size()) 
    {
        B.insert(B.begin(), A.size() - B.size(), '0');
    }

    int carry = 0;
    for (int i = A.size() - 1; i >= 0; i--) //Поразрядное вычитание столбиком, начиная с максимального разряда.
    {
        int x = (A[i] - '0') - (B[i] - '0') - carry;
        if (x < 0) //Перенос одного десятка
        {
            x += 10;
            carry = 1;
        }
        else 
        {
            carry = 0;
        }
        A[i] = char(x + '0');
    }
    while (A.length() > 1 && A[0] == '0') //Если в результате вычитания появились ведущие нули, то программа убирает их 
    {
        A.substr(1, A.length());
    }

    return A;
}
