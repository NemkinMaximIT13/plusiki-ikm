#include <iostream>
#include <string>
using namespace std;

bool IsCorrect(string& input) //�������� "�� ������"
{
    int len = input.length();
    if (len <= 20)//�������� �� ��, ������� �� ����������� ���������� �������� � ��������������� ����� ��� ����� ������� �����
    {
        cout << "����� ���������� ���� ����� ������ ������������, ����������, ���������� ������ ������ �����:" << endl;
        return false;
    }
    string numbers = "1234567890";
    for (int i = 0; i < len; i++)//�������� �� ��, �� �������� �� ��������� ������ ���� ��� ������ ��������, ����� ����.
    {
        if (numbers.find(input[i]) == numbers.npos)
        {
            cout << "� ��������� ���� ������ ���� ������������ �������, ����������, ���������� ������ ������ �����:" << endl;
            return false;
        }
    }
    if (input[0] == '0')//�������� �� ��, ��� �� ���� ������� ����� � �������� ������.
    {
        cout << "�������� ����� �� ������ ��������� ������� ����, ���������� ���������� ������ ������ �����:" << endl;
        return false;
    }
    return true;
}

int comparelen(string& a, string& b) { //��������� ��� ��������� ���� �����.
    if (a.length() < b.length()) return -1;
    if (a.length() > b.length()) return 1;
    //���� ����� ����� ���������, �� ���������� ��������� �� ��������.
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
    for (int i = A.size() - 1; i >= 0; i--) //����������� ��������� ���������, ������� � ������������� �������.
    {
        int x = (A[i] - '0') - (B[i] - '0') - carry;
        if (x < 0) //������� ������ �������
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
    while (A.length() > 1 && A[0] == '0') //���� � ���������� ��������� ��������� ������� ����, �� ��������� ������� �� 
    {
        A.substr(1, A.length());
    }

    return A;
}
