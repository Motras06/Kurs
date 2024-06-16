#include "User.h"

void User_vh::registration()
{
    Color a;
    Ramka();
    SetConsoleOutputCP(CP_UTF8);
    CursorPos(65, 38);
    cout << u8"██████╗░███████╗░██████╗░██╗░██████╗████████╗██████╗░░█████╗░████████╗██╗░█████╗░███╗░░██╗";
    CursorPos(65, 39);
    cout << u8"██╔══██╗██╔════╝██╔════╝░██║██╔════╝╚══██╔══╝██╔══██╗██╔══██╗╚══██╔══╝██║██╔══██╗████╗░██║";
    CursorPos(65, 40);
    cout << u8"██████╔╝█████╗░░██║░░██╗░██║╚█████╗░░░░██║░░░██████╔╝███████║░░░██║░░░██║██║░░██║██╔██╗██║";
    CursorPos(65, 41);
    cout << u8"██╔══██╗██╔══╝░░██║░░╚██╗██║░╚═══██╗░░░██║░░░██╔══██╗██╔══██║░░░██║░░░██║██║░░██║██║╚████║";
    CursorPos(65, 42);
    cout << u8"██║░░██║███████╗╚██████╔╝██║██████╔╝░░░██║░░░██║░░██║██║░░██║░░░██║░░░██║╚█████╔╝██║░╚███║";
    CursorPos(65, 43);
    cout << u8"╚═╝░░╚═╝╚══════╝░╚═════╝░╚═╝╚═════╝░░░░╚═╝░░░╚═╝░░╚═╝╚═╝░░╚═╝░░░╚═╝░░░╚═╝░╚════╝░╚═╝░░╚══╝";
    SetConsoleOutputCP(1251);
    cin.ignore(cin.rdbuf()->in_avail());
    CursorPos(20, 6);
    cout << "ЗАПОЛНЕНИЕ ИНФОРМАЦИИ О ПОЛЬЗОВАТЕЛЕ" << endl;
    CursorPos(20, 7);
    cout << "(P.s все пробелы в имени и пароле будут удалены)" << endl;
    CursorPos(20, 9);
    cout << "Введите имя пользователя (3-10 симв): ";
    SetConsoleTextAttribute(hhCon, a.getInputColor1());
    string new_name;  string new_pass;
    int ch = 0;
    while (true) {
        ch = _getch();
        if (size(this->username) > 0) {
            cout << (char)8 << ' ' << (char)8;
            cout << this->username[this->username.size() - 1];
        }
        if (ch == 13) {
            new_name = this->username;
            new_name.erase(remove(new_name.begin(), new_name.end(), ' '), new_name.end());
            if (size(new_name) < 3 || size(new_name) > 10) {
                int a = MessageBox(NULL, L"Имя вне границ", L"Ошибка", MB_OK);
                switch (a) {
                case IDOK:
                    system("cls");
                    this->username = "";
                    registration();
                }
            }
            else
                break;
        }
        if (ch == ESC) menu();
        if (ch == 8) {
            if (!this->username.empty()) {
                cout << (char)8 << ' ' << char(8);
                this->username.erase(this->username.length() - 1);
            }
        }
        else {
            if (size(this->username) > 9) {
            }
            else if (ch != 13) {
                cout << char(ch);
                this->username += char(ch);
            }
        }
    }
    SetConsoleTextAttribute(hhCon, a.getTextColor());


    ifstream proverka(new_name + ".txt");

    if (!proverka) {
        proverka.close();
        SetConsoleTextAttribute(hhCon, a.getInputColor1());
        cout << " +";
        SetConsoleTextAttribute(hhCon, a.getTextColor());
        CursorPos(20, 20);
        cout << "Видимость настраиваеться клавишами [Right] и [Left]";
        CursorPos(20, 11);
        cout << "Введите пароль (3-10 симв): ";
        SetConsoleTextAttribute(hhCon, a.getInputColor1());
        ch = 0; bool eyes = false;
        while (true) {
            ch = _getch();
            if (size(this->password) > 0) {
                if (eyes == false) { funk1(); }
                else { funk2(this->password); }
            }
            if (ch == 13) {
                new_pass = this->password;
                new_pass.erase(remove(new_pass.begin(), new_pass.end(), ' '), new_pass.end());
                if (size(new_pass) < 3 || size(new_pass) > 10) {
                    int a = MessageBox(NULL, L"Пароль вне границ", L"Ошибка", MB_OK);
                    switch (a) {
                    case IDOK:
                        CursorPos(48, 11); cout << "                                "; CursorPos(48, 11);
                        this->password = "";
                    }
                }
                else
                    break;
            }
            if (ch == ESC) menu();
            if (ch == RIGHT) {
                eyes = true; cout << (char)8 << ' ' << char(8);
                this->password.erase(this->password.length() - 1);
                CursorPos(48, 11); cout << this->password;
            }
            if (ch == LEFT) {
                eyes = false;  cout << (char)8 << ' ' << char(8);
                this->password.erase(this->password.length() - 1);
                CursorPos(48, 11);
                for (int i = 0; i < this->password.size(); i++) {
                    cout << "*";
                }
            }
            if (ch == 8) {
                if (!this->password.empty()) {
                    cout << (char)8 << ' ' << char(8);
                    this->password.erase(this->password.length() - 1);
                }
            }
            else {
                if (size(this->password) > 9) {
                }
                else if (ch != 13 && ch != RIGHT && ch != LEFT) {
                    cout << char(ch);
                    this->password += char(ch);
                }
            }
        }
        SetConsoleTextAttribute(hhCon, a.getInputColor1());
        cout << " +";
        SetConsoleTextAttribute(hhCon, a.getTextColor());
        CursorPos(20, 13);
        string ff, ff1;
        cout << "Введите номер телефона: ";
        SetConsoleTextAttribute(hhCon, a.getInputColor1());
        cout << "80";
        ch = 0;
        while (true) {
            ch = _getch();
            if (size(ff) > 0) {
                cout << (char)8 << ' ' << char(8);
                cout << ff[ff.size() - 1];
            }
            if (ch == 13) {
                ff1 = "80" + ff;
                ff1.erase(remove(ff1.begin(), ff1.end(), ' '), ff1.end());
                SetConsoleTextAttribute(hhCon, a.getTextColor());
                if (ff.size() != 9 || !isInt(ff)) {
                    int a1 = MessageBox(NULL, L"Это не номер телефона", L"Ошибка", MB_OK);
                    CursorPos(46, 13); cout << "                            "; CursorPos(46, 13);
                    ff1 = ""; ff = "";  SetConsoleTextAttribute(hhCon, a.getInputColor1());
                }
                else
                    break;
            }
            if (ch == ESC) menu();
            if (ch == 8) {
                if (!ff.empty()) {
                    cout << (char)8 << ' ' << char(8);
                    ff.erase(ff.length() - 1);
                }
            }
            else {
                if (size(ff) > 8) {
                }
                else if (ch != 13) {
                    cout << char(ch);
                    ff += char(ch);
                }
            }
        }
        ofstream fout(new_name + ".txt");
        fout << new_name << endl;
        fout << new_pass << endl;
        fout << ff1 << endl;
        fout.close();
        string name = new_name;
        ofstream zak("zakaz" + new_name + ".txt");
        zak.close();
        int y = 0; string firstsymb; //!тут
        ifstream fff("base_users.txt");
        fff >> firstsymb;
        if (firstsymb == "") y++;
        fff.close();
        ofstream f("base_users.txt", ios_base::in | ios_base::ate);
        if (y == 1)
            f << new_name;
        else
            f << endl << new_name;
        f.close();
        CursorPos(20, 15);
        SleepMessagYes("**Пользователь создан**");
        Sleep(2000);
        menuPolz(name);
    }
    else {
        proverka.close();
        CursorPos(20, 11);
        int a1 = MessageBox(NULL, L"Такой пользователь уже есть", L"Ошибка", MB_OK);
        system("cls");
        this->username = "";
        registration();
    }
}

void User_vh::Inter()
{
    Color a;
    Ramka();
    SetConsoleOutputCP(CP_UTF8);
    CursorPos(65, 38);
    cout << u8"███████╗███╗░░██╗████████╗██████╗░░█████╗░███╗░░██╗░█████╗░███████╗";
    CursorPos(65, 39);
    cout << u8"██╔════╝████╗░██║╚══██╔══╝██╔══██╗██╔══██╗████╗░██║██╔══██╗██╔════╝";
    CursorPos(65, 40);
    cout << u8"█████╗░░██╔██╗██║░░░██║░░░██████╔╝███████║██╔██╗██║██║░░╚═╝█████╗░░";
    CursorPos(65, 41);
    cout << u8"██╔══╝░░██║╚████║░░░██║░░░██╔══██╗██╔══██║██║╚████║██║░░██╗██╔══╝░░";
    CursorPos(65, 42);
    cout << u8"███████╗██║░╚███║░░░██║░░░██║░░██║██║░░██║██║░╚███║╚█████╔╝███████╗";
    CursorPos(65, 43);
    cout << u8"╚══════╝╚═╝░░╚══╝░░░╚═╝░░░╚═╝░░╚═╝╚═╝░░╚═╝╚═╝░░╚══╝░╚════╝░╚══════╝";
    SetConsoleOutputCP(1251);
    cin.ignore(cin.rdbuf()->in_avail());
    CursorPos(20, 5);
    cout << "ВХОД В СУЩЕСТВУЮЩИЙ АККАУНТ";
    CursorPos(20, 6);
    cout << "Введите имя пользователя: ";
    SetConsoleTextAttribute(hhCon, a.getInputColor1());
    int ch = 0;
    while (true) {
        ch = _getch();
        if (size(this->username) > 0) {
            cout << (char)8 << ' ' << (char)8;
            cout << this->username[this->username.size() - 1];
        }
        if (ch == 13) {
            break;
        }
        if (ch == ESC) menu();
        if (ch == 8) {
            if (!this->username.empty()) {
                cout << (char)8 << ' ' << char(8);
                this->username.erase(this->username.length() - 1);
            }
        }
        else {
            if (size(this->username) > 29) {
            }
            else if (ch != 13) {
                cout << char(ch);
                this->username += char(ch);
            }
        }
    }
    SetConsoleTextAttribute(hhCon, a.getTextColor());
    if (this->username == "katalog" || this->username == "base_users" || this->username == "admin" || this->username == "user" || this->username == "search" || this->username == "color") {
        int a = MessageBox(NULL, L"Отказано в доступе", L"Ошибка", MB_OK);
        switch (a) {
        case IDOK:
            Inter();
            break;
        }
    }
    string n1, p1;
    ifstream fin(this->username + ".txt");
    getline(fin, n1); getline(fin, p1);
    if (fin.is_open())
    {
        SetConsoleTextAttribute(hhCon, a.getInputColor1());
        cout << " +";
        SetConsoleTextAttribute(hhCon, a.getTextColor());
        CursorPos(20, 15);
        cout << "Видимость настраиваеться клавишами [Right] и [Left]";
        CursorPos(20, 8);
        cout << "введите пороль: ";
        SetConsoleTextAttribute(hhCon, a.getInputColor1());
        int ch = 0; bool eyes = false;
        while (true) {
            ch = _getch();
            if (size(this->password) > 0) {
                if (eyes == false) { funk1(); }
                else { funk2(this->password); }
            }
            if (ch == 13) {
                if (this->password != p1) {
                    int nn = MessageBox(NULL, L"Пароль введен не верно", L"Ошибка", MB_OK);
                    this->password = "";
                    CursorPos(36, 8);
                    cout << "                                    ";
                    CursorPos(36, 8);
                }
                else
                    break;
            }
            if (ch == ESC) menu();
            if (ch == RIGHT) {
                eyes = true;  cout << (char)8 << ' ' << char(8);
                this->password.erase(this->password.length() - 1);
                CursorPos(36, 8); cout << this->password;
            }
            if (ch == LEFT) {
                eyes = false;  cout << (char)8 << ' ' << char(8);
                this->password.erase(this->password.length() - 1);
                CursorPos(36, 8);
                for (int i = 0; i < this->password.size(); i++) {
                    cout << "*";
                }
            }
            if (ch == 8) {
                if (!this->password.empty()) {
                    cout << (char)8 << ' ' << char(8);
                    this->password.erase(this->password.length() - 1);
                }
            }
            else {
                if (size(this->password) > 29) {
                }
                else if (ch != 13 && ch != RIGHT && ch != LEFT) {
                    cout << char(ch);
                    this->password += char(ch);
                }
            }
        }
        SetConsoleTextAttribute(hhCon, a.getTextColor());
        if (this->password == p1) {
            SetConsoleTextAttribute(hhCon, a.getInputColor1());
            cout << " +";
            SetConsoleTextAttribute(hhCon, a.getTextColor());
            CursorPos(20, 10);
            SleepMessagYes("**Вход осуществлён**");
            Sleep(1000);
            system("cls");
        }
    }
    else
    {
        int a = MessageBox(NULL, L"Пользователь не найден", L"Ошибка", MB_OK);
        switch (a) {
        case IDOK:
            system("cls");
            this->username = "";
            Inter();
            break;
        }
    }
    fin.close();
    string name = this->username;
    SetConsoleTextAttribute(hhCon, a.getTextColor());
    menuPolz(name);
}

void User_vh::InterByAdmin()
{
    Color a;
    cin.ignore(cin.rdbuf()->in_avail());
    Ramka();
    SetConsoleOutputCP(CP_UTF8);
    CursorPos(45, 38);
    cout << u8"███████╗███╗░░██╗████████╗██████╗░░█████╗░███╗░░██╗░█████╗░███████╗  ░█████╗░██████╗░███╗░░░███╗██╗███╗░░██╗";
    CursorPos(45, 39);
    cout << u8"██╔════╝████╗░██║╚══██╔══╝██╔══██╗██╔══██╗████╗░██║██╔══██╗██╔════╝  ██╔══██╗██╔══██╗████╗░████║██║████╗░██║";
    CursorPos(45, 40);
    cout << u8"█████╗░░██╔██╗██║░░░██║░░░██████╔╝███████║██╔██╗██║██║░░╚═╝█████╗░░  ███████║██║░░██║██╔████╔██║██║██╔██╗██║";
    CursorPos(45, 41);
    cout << u8"██╔══╝░░██║╚████║░░░██║░░░██╔══██╗██╔══██║██║╚████║██║░░██╗██╔══╝░░  ██╔══██║██║░░██║██║╚██╔╝██║██║██║╚████║";
    CursorPos(45, 42);
    cout << u8"███████╗██║░╚███║░░░██║░░░██║░░██║██║░░██║██║░╚███║╚█████╔╝███████╗  ██║░░██║██████╔╝██║░╚═╝░██║██║██║░╚███║";
    CursorPos(45, 43);
    cout << u8"╚══════╝╚═╝░░╚══╝░░░╚═╝░░░╚═╝░░╚═╝╚═╝░░╚═╝╚═╝░░╚══╝░╚════╝░╚══════╝  ╚═╝░░╚═╝╚═════╝░╚═╝░░░░░╚═╝╚═╝╚═╝░░╚══╝";
    SetConsoleOutputCP(1251);
    CursorPos(20, 6);
    cout << "ВХОД В КАЧЕСТВЕ АДМИНА" << endl;
    ifstream admin("admin.txt");
    string pass;
    getline(admin, pass);
    CursorPos(20, 14);
    cout << "Видимость настраиваеться клавишами [Right] и [Left]";
    CursorPos(20, 8);
    cout << "Введите пароль администратора: ";
    SetConsoleTextAttribute(hhCon, a.getInputColor1());
    int ch = 0; bool eyes = false;
    while (true) {
        ch = _getch();
        if (size(this->password) > 0) {
            if (eyes == false) { funk1(); }
            else { funk2(this->password); }
        }
        if (ch == 13) {
            break;
        }
        if (ch == ESC) menu();
        if (ch == RIGHT) {
            eyes = true;  cout << (char)8 << ' ' << char(8);
            this->password.erase(this->password.length() - 1);
            CursorPos(51, 8); cout << this->password;

        }
        if (ch == LEFT) {
            eyes = false;  cout << (char)8 << ' ' << char(8);
            this->password.erase(this->password.length() - 1);
            CursorPos(51, 8);
            for (int i = 0; i < this->password.size(); i++) {
                cout << "*";
            }
        }
        if (ch == 8) {
            if (!this->password.empty()) {
                cout << (char)8 << ' ' << char(8);
                this->password.erase(this->password.length() - 1);
            }
        }
        else {
            if (size(this->password) > 29) {
            }
            else if (ch != 13 && ch != RIGHT && ch != LEFT) {
                cout << char(ch);
                this->password += char(ch);
            }
        }
    }
    SetConsoleTextAttribute(hhCon, a.getTextColor());
    if (this->password == pass) {
        SetConsoleTextAttribute(hhCon, a.getInputColor1());
        cout << " +";
        SetConsoleTextAttribute(hhCon, a.getTextColor());
        CursorPos(20, 10);
        SleepMessagYes("**Пороль введён верно**");
        Sleep(1000);
        menuAdmin();
    }
    else {
        CursorPos(20, 10);
        SleepMessagNo("**Пороль введён неверно**");
        Sleep(1000);
        system("cls");
        this->password = "";
        InterByAdmin();
    }
}
