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
HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);

int main() {
    SetConsoleTitle(L"Search");
    system("color 0f");
    system("mode con cols=165 lines=1000");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    string word;
    ifstream for_search("search.txt");
    getline(for_search, word);
    for_search.close();
    ifstream file("katalog.txt");
    vector<vector<string>> matrix;
    string line;

    // Проверка открытия файла
    if (!file.is_open()) {
        cerr << "Не удалось открыть файл." << std::endl;
        exit(0);
    }
    cout << " +========================================================================================================================================================+" << endl;
    cout << "||";
    SetConsoleTextAttribute(h, 11);
    cout << "номер водителя  | начальная точка| конечная точка | дата отправки  | дата прибытия  | тип кузова     | вес(т)         | обЪём(м ^ 3)   | номер          ";
    SetConsoleTextAttribute(h, 15);
    cout << "|| " << endl;
    // Чтение файла построчно
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
        j++;
        for (int i = 0; i < row.size(); i++) {
            if (j == stoi(word)) {
                cout << "||";
                for (auto& element : row) {
                    int n = element.size();
                    const int Max = 16;
                    int n1 = Max - n;
                    string probel;
                    for (int i = 0; i < n1; i++) probel += " ";
                    if (element == word) {
                        SetConsoleTextAttribute(h, 175);
                        cout << element;
                        SetConsoleTextAttribute(h, 15);
                        cout << probel << "|";
                    }
                    else
                        cout << element << probel << "|";
                }
                string num = to_string(j);
                cout << j;
                for (int i = 0; i < 16 - num.size(); i++) {
                    cout << " ";
                }
                cout << "||";
                cout << "\n +--------------------------------------------------------------------------------------------------------------------------------------------------------+" << endl;
                break;
            }
        }
    }
    _getch();
    system("cls");
}