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
#include <algorithm>
using namespace std;
HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);

//!Data

struct Data {
    int numInFile;
    string num;
    string fPlace;
    string sPlace;
    string fDate;
    string sDate;
    string type;
    int mass;
    int volume;

    Data(vector<string>vec) :
        num{ vec[0] },
        fPlace{ vec[1] },
        sPlace{ vec[2] },
        fDate{ vec[3] },
        sDate{ vec[4] },
        type{ vec[5] },
        mass{ stoi(vec[6]) },
        volume{ stoi(vec[7]) }
    {
    }

    size_t size()
    {
        return 8;
    }

    string operator[](int index)
    {
        switch (index)
        {
        case 0:
            return num;
        case 1:
            return fPlace;
        case 2:
            return sPlace;
        case 3:
            return fDate;
        case 4:
            return sDate;
        case 5:
            return type;
        case 6:
            return to_string(mass);
        case 7:
            return to_string(volume);
        default:
            break;
        }
    }
};

//!sort Vector Of Data

void sortByNum(vector<Data>& data, const int& SORT, int& previusSORT) {
    if (SORT == previusSORT)
    {
        sort(data.begin(), data.end(), [](Data first, Data second) {
            return first.num > second.num;
            });
        previusSORT = -1;
    }
    else
    {
        sort(data.begin(), data.end(), [](Data first, Data second) {
            return first.num < second.num;
            });
        previusSORT = SORT;
    }
}

void sortByfPlace(vector<Data>& data, const int& SORT, int& previusSORT) {
    if (SORT == previusSORT)
    {
        sort(data.begin(), data.end(), [](Data first, Data second) {
            return first.fPlace > second.fPlace;
            });
        previusSORT = -1;
    }
    else
    {
        sort(data.begin(), data.end(), [](Data first, Data second) {
            return first.fPlace < second.fPlace;
            });
        previusSORT = SORT;
    }
}

void sortBysPlace(vector<Data>& data, const int& SORT, int& previusSORT) {
    if (SORT == previusSORT)
    {
        sort(data.begin(), data.end(), [](Data first, Data second) {
            return first.sPlace > second.sPlace;
            });
        previusSORT = -1;
    }
    else
    {
        sort(data.begin(), data.end(), [](Data first, Data second) {
            return first.sPlace < second.sPlace;
            });
        previusSORT = SORT;
    }
}

void sortByfDate(vector<Data>& data, const int& SORT, int& previusSORT) {
    if (SORT == previusSORT)
    {
        sort(data.begin(), data.end(), [](Data first, Data second) {
            return first.fDate > second.fDate;
            });
        previusSORT = -1;
    }
    else
    {
        sort(data.begin(), data.end(), [](Data first, Data second) {
            return first.fDate < second.fDate;
            });
        previusSORT = SORT;
    }
}

void sortBysDate(vector<Data>& data, const int& SORT, int& previusSORT) {
    if (SORT == previusSORT)
    {
        sort(data.begin(), data.end(), [](Data first, Data second) {
            return first.sDate > second.sDate;
            });
        previusSORT = -1;
    }
    else
    {
        sort(data.begin(), data.end(), [](Data first, Data second) {
            return first.sDate < second.sDate;
            });
        previusSORT = SORT;
    }
}

void sortByType(vector<Data>& data, const int& SORT, int& previusSORT) {
    if (SORT == previusSORT)
    {
        sort(data.begin(), data.end(), [](Data first, Data second) {
            return first.type > second.type;
            });
        previusSORT = -1;
    }
    else
    {
        sort(data.begin(), data.end(), [](Data first, Data second) {
            return first.type < second.type;
            });
        previusSORT = SORT;
    }
}

void sortByMass(vector<Data>& data, const int& SORT, int& previusSORT) {
    if (SORT == previusSORT)
    {
        sort(data.begin(), data.end(), [](Data first, Data second) {
            return first.mass > second.mass;
            });
        previusSORT = -1;
    }
    else
    {
        sort(data.begin(), data.end(), [](Data first, Data second) {
            return first.mass < second.mass;
            });
        previusSORT = SORT;
    }
}

void sortByVolume(vector<Data>& data, const int& SORT, int& previusSORT) {
    if (SORT == previusSORT)
    {
        sort(data.begin(), data.end(), [](Data first, Data second) {
            return first.volume > second.volume;
            });
        previusSORT = -1;
    }
    else
    {
        sort(data.begin(), data.end(), [](Data first, Data second) {
            return first.volume < second.volume;
            });
        previusSORT = SORT;
    }
}

void sortByFnum(vector<Data>& data, const int& SORT, int& previusSORT) {
    if (SORT == previusSORT)
    {
        sort(data.begin(), data.end(), [](Data first, Data second) {
            return first.numInFile > second.numInFile;
            });
        previusSORT = -1;
    }
    else
    {
        sort(data.begin(), data.end(), [](Data first, Data second) {
            return first.numInFile < second.numInFile;
            });
        previusSORT = SORT;
    }
}


void sortData(vector<Data>& data, const int& SORT, int& previusSORT)
{
    switch (SORT) {
    case 1:
        sortByNum(data, SORT, previusSORT);
        break;
    case 2:
        sortByfPlace(data, SORT, previusSORT);
        break;
    case 3:
        sortBysPlace(data, SORT, previusSORT);
        break;
    case 4:
        sortByfDate(data, SORT, previusSORT);
        break;
    case 5:
        sortBysDate(data, SORT, previusSORT);
        break;
    case 6:
        sortByType(data, SORT, previusSORT);
        break;
    case 7:
        sortByMass(data, SORT, previusSORT);
        break;
    case 8:
        sortByVolume(data, SORT, previusSORT);
        break;
    case 9:
        sortByFnum(data, SORT, previusSORT);
        break;
    }
}



//!functions

void getData(vector<Data>& data)
{
    ifstream file("katalog.txt");
    // Чтение файла построчно
    if (!file.is_open()) {
        cerr << "Не удалось открыть файл." << std::endl;
        exit(0);
    }
    string line;
    // Проверка открытия файла
    for (int i = 0; getline(file, line); i++) {
        istringstream iss(line);
        vector<string> row;
        string num;

        // Чтение чисел из строки и добавление в строку матрицы
        while (iss >> num) {
            row.push_back(num);
        }
        Data buff(row);
        buff.numInFile = i + 1;
        // Добавление строки в матрицу
        data.push_back(buff);
    }
}

void print(vector<Data>& data) {
    cout << " +========================================================================================================================================================+" << endl;
    cout << "||";
    SetConsoleTextAttribute(h, 11);
    cout << "номер водителя  | начальная точка| конечная точка | дата отправки  | дата прибытия  | тип кузова     | вес(т)         | обЪём(м ^ 3)   | номер          ";
    SetConsoleTextAttribute(h, 15);
    cout << "|| " << endl;

    cout << " +--------------------------------------------------------------------------------------------------------------------------------------------------------+" << endl;
    for (auto& row : data) {
        for (int i = 0; i < row.size(); i++) {
            cout << "||";
            for (int index = 0; index < row.size(); index++) {
                auto element = row[index];
                int n = element.size();
                const int Max = 16;
                int n1 = Max - n;
                string probel;
                for (int i = 0; i < n1; i++) probel += " ";

                cout << element << probel << "|";
            }
            string num = to_string(row.numInFile);
            cout << row.numInFile;
            for (int i = 0; i < 16 - num.size(); i++) {
                cout << " ";
            }
            cout << "||";
            cout << "\n +--------------------------------------------------------------------------------------------------------------------------------------------------------+" << endl;
            break;

        }
    }
    cout << endl;
}

int printSort() {
    cout << "Выберите параметр для сортировки: ";
    cout << endl;
    cout << "[1]Номер перевозчика [2]Место отправки [3]Место прибытия [4]Дата отправления [5]Дата прибытия [6]Тип [7]Масса [8]Объём [9]Номер в каталоге";
    switch (_getch()) {
    case '1':
        return 1;
        break;
    case '2':
        return 2;
        break;
    case '3':
        return 3;
        break;
    case '4':
        return 4;
        break;
    case '5':
        return 5;
        break;
    case '6':
        return 6;
        break;
    case '7':
        return 7;
        break;
    case '8':
        return 8;
        break;
    case '9':
        return 9;
        break;
    }
}

//!main

int main() {
    SetConsoleTitle(L"Search");
    system("color 0f");
    system("mode con cols=165 lines=1000");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    int SORT = -1;
    int previusSORT = -1;
    for (;;) {
        vector<Data> data;
        getData(data);
        sortData(data, SORT, previusSORT);
        print(data);
        SORT = printSort();
        system("cls");
    }
    _getch();
    system("cls");
}