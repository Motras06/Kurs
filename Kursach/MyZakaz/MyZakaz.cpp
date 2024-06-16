#include <iostream>
#include <cmath>
#include <Windows.h>
#include <iomanip>
#include <vector>
#include <fstream>
#include <ctime>
#include <string>
#include <conio.h>
#include <sstream>
using namespace std;
const HANDLE hhCon = GetStdHandle(STD_OUTPUT_HANDLE);

int main() {
    SetConsoleTitle(L"Order");
    system("mode con cols=165 lines=1000");    
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    ifstream filen("user.txt");
    string filename;
    getline(filen, filename);
    filen.close();
    ifstream file(filename);
    vector<vector<string>> matrix;
    string line;
    if (!file.is_open()) {
        cerr << "Не удалось открыть файл." << std::endl;
        exit(0);
    }
    cout << "\t\t\t" << "Просмотр заказа:" << endl;
    cout << " +========================================================================================================================================================+" << endl;
    cout << "||";
    SetConsoleTextAttribute(hhCon, 11);
    cout << "номер водителя  | начальная точка| конечная точка | дата отправки  | дата прибытия  | тип кузова     | вес(т)         | обЪём(м ^ 3)   | номер          ";
    SetConsoleTextAttribute(hhCon, 15);
    cout << "|| " << endl;
    while (getline(file, line)) {
        istringstream iss(line);
        vector<string> row;
        string num;

        // Чтение чисел из строки и добавление в строку матрицы
        while (iss >> num) {
            row.push_back(num);
        }

        // Добавление строки в матрицу
        matrix.push_back(row);
    }
    cout << " +--------------------------------------------------------------------------------------------------------------------------------------------------------+" << endl;
    int j = 0;
    for (auto& row : matrix) {
        cout << "||";
        for (auto& element : row) {
            int n = element.size();
            const int Max = 16;
            int n1 = Max - n;
            string probel;
            for (int i = 0; i < n1; i++) probel += " ";
            cout << element << probel << "|";
        }
        j++; string num = to_string(j);
        cout << j;
        for (int i = 0; i < 16 - num.size(); i++) {
            cout << " ";
        }
        cout << "||";
        cout << "\n +--------------------------------------------------------------------------------------------------------------------------------------------------------+" << endl;;
    }
    _getch();
    system("cls");
}