#include <iostream>
#include <windows.h>
#include <string>
#include <fstream>
#include <conio.h>
#include <vector>
using namespace std;

int main()
{
    SetConsoleTitle(L"User Base Users");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    system("mode con cols=70 lines=100");
    cout << "База данных пользователей:" << endl;
    ifstream fin("base_users.txt");
    vector<string> lines; string line; int y=0;
    while (getline(fin, line)) {
        lines.push_back(line);
        y++;
    }
    int max = 15;
    cout << "Всего пользователей: " << y << endl;
    for (string lin : lines) {
        int n = max - lin.size();
        string p;
        for (int j = 0; j < n; j++) p += " ";
        cout << "+---------------+" << endl;
        cout << "|" << lin << p << "|" << endl;
    }
    cout << "+---------------+" << endl;
    fin.close();
    _getch();
    system("cls");
}