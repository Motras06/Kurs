#include "User.h"

void Admin::AddUser()
{
    Color a;
    string username;
    string password;
    string inf;
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
    cout << "ЗАПОЛНЕНИЕ ИНФОРМАЦИЮ О ПОЛЬЗОВАТЕЛЕ" << endl;
    CursorPos(20, 7);
    cout << "(P.s все пробелы в имени и пароле будут удалены)" << endl;
    CursorPos(20, 9);
    SleepMessagText("Введите имя пользователя:  ");
    SetConsoleTextAttribute(hhCon, a.getInputColor1());
    int ch = 0; string new_name; string new_pass;
    while (true) {
        ch = _getch();
        if (size(username) > 0) {
            cout << (char)8 << ' ' << (char)8;
            cout << username[username.size() - 1];
        }
        if (ch == 13) {
            new_name = username;
            new_name.erase(remove(new_name.begin(), new_name.end(), ' '), new_name.end());
            if (size(new_name) < 3 || size(new_name) > 10) {
                int a = MessageBox(NULL, L"Имя вне границ", L"Ошибка", MB_OK);
                switch (a) {
                case IDOK:
                    system("cls");
                    username = "";
                    AddUser();
                }
            }
            else
                break;
        }
        if (ch == ESC) menuAdmin2();
        if (ch == 8) {
            if (!username.empty()) {
                cout << (char)8 << ' ' << char(8);
                username.erase(username.length() - 1);
            }
        }
        else {
            if (size(username) > 9) {
            }
            else if (ch != 13) {
                cout << char(ch);
                username += char(ch);
            }
        }
    }
    SetConsoleTextAttribute(hhCon, a.getTextColor());
    ifstream proverka(new_name + ".txt");
    if (!proverka) {
        proverka.close();
        CursorPos(48 + username.size(), 9);
        SetConsoleTextAttribute(hhCon, a.getInputColor1());
        cout << " +";
        SetConsoleTextAttribute(hhCon, a.getTextColor());

        CursorPos(20, 11);
        SleepMessagText("Введите пароль: ");
        SetConsoleTextAttribute(hhCon, a.getInputColor1());
        ch = 0; bool eyes = false;
        while (true) {
            ch = _getch();
            if (size(password) > 0) {
                if (eyes == false) { funk1(); }
                else { funk2(password); }
            }
            if (ch == 13) {
                new_pass = password;
                new_pass.erase(remove(new_pass.begin(), new_pass.end(), ' '), new_pass.end());
                if (size(new_pass) < 3 || size(new_pass) > 10) {
                    int a = MessageBox(NULL, L"Пароль вне границ", L"Ошибка", MB_OK);
                    switch (a) {
                    case IDOK:
                        CursorPos(48, 11); cout << "                                "; CursorPos(48, 11);
                        password = "";
                    }
                }
                else
                    break;
            }
            if (ch == ESC) menuAdmin2();
            if (ch == RIGHT) {
                eyes = true; cout << (char)8 << ' ' << char(8);
                password.erase(password.length() - 1);
                CursorPos(48, 11); cout << password;
            }
            if (ch == LEFT) {
                eyes = false;  cout << (char)8 << ' ' << char(8);
                password.erase(password.length() - 1);
                CursorPos(48, 11);
                for (int i = 0; i < password.size(); i++) {
                    cout << "*";
                }
            }
            if (ch == 8) {
                if (!password.empty()) {
                    cout << (char)8 << ' ' << char(8);
                    password.erase(password.length() - 1);
                }
            }
            else {
                if (size(password) > 9) {
                }
                else if (ch != 13 && ch != RIGHT && ch != LEFT) {
                    cout << char(ch);
                    password += char(ch);
                }
            }
        }
        SetConsoleTextAttribute(hhCon, a.getTextColor());
        
        
        CursorPos(38 + password.size(), 11);
        SetConsoleTextAttribute(hhCon, a.getInputColor1());
        cout << " +";
        SetConsoleTextAttribute(hhCon, a.getTextColor());
        Sleep(200);
        CursorPos(20, 13);
        string ff, ff1;
        SleepMessagText("Введите номер телефона:");
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
            if (ch == ESC) menuAdmin2();
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
        Sleep(1000);
        menuAdmin2();
    }
    else {
        proverka.close();
        CursorPos(20, 11);
        SleepMessagNo("**Такой пользователь уже есть, попробуйте снова**");
        Sleep(1000);
        username = "";
        system("cls");
        AddUser();
    }
}

void Admin::UserBaseDan() {
    system("start UserBaseDan.exe");
    menuAdmin2();
}

void Admin::UserInformation() {
    Color a;
    Ramka();
    SetConsoleOutputCP(1251);
    CursorPos(140, 45); 
    cout << "Чтобы посмотреть базу данных пользователей нажмите [Tab]";
    CursorPos(20, 6);
    SleepMessagText("Введите имя интеречующего вас пользователя: ");
    string user; 
    SetConsoleTextAttribute(hhCon, a.getInputColor1());
    int ch = 0;
    while (true) {
        ch = _getch();
        if (size(user) > 0) {
            cout << (char)8 << ' ' << (char)8;
            cout << user[user.size() - 1];
        }
        if (ch == 13) {
            break;
        }
        if (ch == 9) system("start UserBaseDan.exe");
        if (ch == ESC) menuAdmin2();
        if (ch == 8) {
            if (!user.empty()) {
                cout << (char)8 << ' ' << char(8);
                user.erase(user.length() - 1);
            }
        }
        else {
            if (size(user) > 29) {
            }
            else if (ch != 13 && ch != 48) {
                cout << char(ch);
                user += char(ch);
            }
        }
    }
    SetConsoleTextAttribute(hhCon, a.getTextColor());
    ifstream fin(user + ".txt");
    if (fin) {
        CursorPos(20, 8);
        SleepMessagText("Информация о пользователе: ");
        char x = 20, y = 10;
        vector<string> lines; string line;
        while (getline(fin, line)) {
            lines.push_back(line);
        }
        for (string lin : lines) {
            CursorPos(x, y++);
            cout << lin << endl;
        }
        fin.close();
        CursorPos(x, y+2);
        SleepMessagText("Перевозки пользователя: ");
        ifstream f("zakaz" + user + ".txt");
            vector<string> lines1; string line1;
            while (getline(f, line1)) {
                lines1.push_back(line1);
            }
        if (!line1.empty()){ 
            for (string lin : lines1) {
                CursorPos(x, y + 4);
                cout << lin << endl;
                y++;
            }
        }
        else {
            CursorPos(x, y + 4);
            Sleep(1000);
            SleepMessagText("**У пользователя нет перевозок**");
        }
        f.close();
        _getch();
        menuAdmin2();
    }
    else {
        CursorPos(20, 8);
        SleepMessagNo("**Такого пользователя нет**");
        Sleep(1000);
        user = "";
        system("cls");
        UserInformation();
    }
}

void Admin::InterToCatalog() {
    Color a;
    Ramka();
    SetConsoleOutputCP(1251);
    string num, mest1, mest2, date1, date2, type, massa, obiom;
    /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    CursorPos(20, 6);
    SleepMessagText("Введите номер телефона перевозчика: ");
    SetConsoleTextAttribute(hhCon, a.getInputColor1());
    cout << "80";
    int ch = 0; string fnum;
    while (true) {
        ch = _getch();
        if (size(num) > 0) {
            cout << (char)8 << ' ' << char(8);
            cout << num[num.size() - 1];
        }
        if (ch == 13) {
            fnum = "80" + num;
            fnum.erase(remove(fnum.begin(), fnum.end(), ' '), fnum.end());
            SetConsoleTextAttribute(hhCon, a.getTextColor());
            if (num.size() != 9 || !isInt(num)) {
                CursorPos(20, 8);
                SleepMessagNo("**это не номер телефона**");
                Sleep(2000);
                num = "";
                system("cls");
                InterToCatalog();
            }
            else
                break;
        }
        if (ch == ESC) menuAdmin();
        if (ch == 8) {
            if (!num.empty()) {
                cout << (char)8 << ' ' << char(8);
                num.erase(num.length() - 1);
            }
        }
        else {
            if (size(num) > 8) {
            }
            else if (ch != 13) {
                cout << char(ch);
                num += char(ch);
            }
        }
    }
    /////////////////////////////////////////////////////////////////////////////////////////////////////////
    CursorPos(20, 8);
    SleepMessagText("Введите место загрузки: ");
    SetConsoleTextAttribute(hhCon, a.getInputColor1());
    ch = 0;
    while (true) {
        ch = _getch();
        if (size(mest1) > 0) {
            cout << (char)8 << ' ' << (char)8;
            cout << mest1[mest1.size() - 1];
        }
        if (ch == 13) {
            if (mest1.size() < 2) {
                CursorPos(20, 10);
                int a = MessageBox(NULL, L"Такого города нет", L"Ошибка", MB_OK);
                switch (a) {
                case IDOK:
                    mest1 = "";
                    CursorPos(44, 8); cout << "                                          "; CursorPos(44, 8);
                }
            }
            else {
                mest1.erase(remove(mest1.begin(), mest1.end(), ' '), mest1.end());
                break;
            }
        }
        if (ch == ESC) menuAdmin();
        if (ch == 8) {
            if (!mest1.empty()) {
                cout << (char)8 << ' ' << char(8);
                mest1.erase(mest1.length() - 1);
            }
        }
        else {
            if (size(mest1) > 11) {
            }
            else if (ch != 13) {
                cout << char(ch);
                mest1 += char(ch);
            }
        }
    }
    SetConsoleTextAttribute(hhCon, a.getTextColor());
    ////////////////////////////////////////////////////////////////////////////////////////////////////////
    CursorPos(20, 10);
    SleepMessagText("Введите место выгрузки: ");
    SetConsoleTextAttribute(hhCon, a.getInputColor1());
    ch = 0;
    while (true) {
        ch = _getch();
        if (size(mest2) > 0) {
            cout << (char)8 << ' ' << (char)8;
            cout << mest2[mest2.size() - 1];
        }
        if (ch == 13) {
            if (mest2.size() < 2) {
                CursorPos(20, 10);
                int a = MessageBox(NULL, L"Такого города нет", L"Ошибка", MB_OK);
                switch (a) {
                case IDOK:
                    mest2 = "";
                    CursorPos(44, 8); cout << "                                          "; CursorPos(44, 8);
                }
            }
            else {
                mest2.erase(remove(mest2.begin(), mest2.end(), ' '), mest2.end());
                break;
            }
        }
        if (ch == ESC) menuAdmin();
        if (ch == 8) {
            if (!mest2.empty()) {
                cout << (char)8 << ' ' << char(8);
                mest2.erase(mest2.length() - 1);
            }
        }
        else {
            if (size(mest2) > 11) {
            }
            else if (ch != 13) {
                cout << char(ch);
                mest2 += char(ch);
            }
        }
    }
    SetConsoleTextAttribute(hhCon, a.getTextColor());
    ////////////////////////////////////////////////////////////////////////////////////////////////////////
    CursorPos(20, 12);
    SleepMessagText("Введите дату загрузки: ");
    CursorPos(20, 13);
    SleepMessagText("Введите день: ");
    SetConsoleTextAttribute(hhCon, a.getInputColor1());
    string date; int buf; ch = 0;
    while (true) {
        ch = _getch();
        if (size(date) > 0) {
            cout << (char)8 << ' ' << (char)8;
            cout << date[date.size() - 1];
        }
        if (ch == 13) {
            try {
                buf = stoi(date);
                if (buf > 0 && buf <= 31) {
                    if (buf < 10) {
                        date1 += "0" + date + ".";
                        break;
                    }
                    else {
                        date1 += date + ".";
                        break;
                    }
                }
                else {
                    date = "";
                    CursorPos(34, 13); cout << "    "; CursorPos(34, 13);
                }
            }
            catch (const exception&) {
                CursorPos(20, 15);
                SleepMessagNo("Это не день");
                Sleep(1000);
                CursorPos(20, 15); SleepMessagText("                      ");
                date = "";
                CursorPos(34, 13); cout << "    "; CursorPos(34, 13);
                SetConsoleTextAttribute(hhCon, a.getInputColor1());
            }
        }
        if (ch == ESC) menuAdmin();
        if (ch == 8) {
            if (!date.empty()) {
                cout << (char)8 << ' ' << char(8);
                date.erase(date.length() - 1);
            }
        }
        else {
            if (size(date) > 3) {
            }
            else if (ch != 13) {
                cout << char(ch);
                date += char(ch);
            }
        }
    }
    /////////
    CursorPos(20, 14);
    SleepMessagText("Введите месяц: ");
    SetConsoleTextAttribute(hhCon, a.getInputColor1());
    date = ""; ch = 0;
    while (true) {
        ch = _getch();
        if (size(date) > 0) {
            cout << (char)8 << ' ' << (char)8;
            cout << date[date.size() - 1];
        }
        if (ch == 13) {
            try {
                buf = stoi(date);
                if (buf > 0 && buf <= 31) {
                    if (buf < 10) {
                        date1 += "0" + date + ".";
                        break;
                    }
                    else {
                        date1 += date + ".";
                        break;
                    }
                }
                else {
                    date = "";
                    CursorPos(35, 14); cout << "    "; CursorPos(35, 14);
                }
            }
            catch (const std::exception&) {
                CursorPos(20, 16);
                SleepMessagNo("Это не месяц");
                Sleep(1000);
                CursorPos(20, 16); SleepMessagText("                      ");
                date = "";
                CursorPos(35, 14); cout << "    "; CursorPos(35, 14);
                SetConsoleTextAttribute(hhCon, a.getInputColor1());
            }
        }
        if (ch == ESC) menuAdmin();
        if (ch == 8) {
            if (!date.empty()) {
                cout << (char)8 << ' ' << char(8);
                date.erase(date.length() - 1);
            }
        }
        else {
            if (size(date) > 3) {
            }
            else if (ch != 13) {
                cout << char(ch);
                date += char(ch);
            }
        }
    }
    ///////
    CursorPos(20, 15);
    SleepMessagText("Введите год: ");
    SetConsoleTextAttribute(hhCon, a.getInputColor1());
    cout << "20";
    date = ""; ch = 0;
    while (true) {
        ch = _getch();
        if (size(date) > 0) {
            cout << (char)8 << ' ' << (char)8;
            cout << date[date.size() - 1];
        }
        if (ch == 13) {
            try {
                buf = stoi(date);
                if (buf > 0 && buf <= 99) {
                    if (buf < 10) {
                        if (size(date) == 2) {
                            date = date[1];
                        }
                        date1 += "200" + date;
                        break;
                    }
                    else {
                        date1 += "20" + date;
                        break;
                    }
                }
                else {
                    date = "";
                    CursorPos(35, 15); cout << "    "; CursorPos(35, 15);
                }
            }
            catch (const exception&) {
                CursorPos(20, 17);
                SleepMessagNo("Это не год");
                Sleep(1000);
                CursorPos(20, 17); SleepMessagText("                      ");
                date = "";
                CursorPos(35, 15); cout << "    "; CursorPos(35, 15);
                SetConsoleTextAttribute(hhCon, a.getInputColor1());
            }
        }
        if (ch == ESC) menuAdmin();
        if (ch == 8) {
            if (!date.empty()) {
                cout << (char)8 << ' ' << char(8);
                date.erase(date.length() - 1);
            }
        }
        else {
            if (size(date) > 3) {
            }
            else if (ch != 13) {
                cout << char(ch);
                date += char(ch);
            }
        }
    }
    ////////////////////////////////////////////////////////////////////////////////////////////////////////
    CursorPos(20, 17);
    SleepMessagText("Введите дату выгрузки: ");
    CursorPos(20, 18);
    SleepMessagText("Введите день: ");
    SetConsoleTextAttribute(hhCon, a.getInputColor1());
    date = ""; ch = 0;
    while (true) {
        ch = _getch();
        if (size(date) > 0) {
            cout << (char)8 << ' ' << (char)8;
            cout << date[date.size() - 1];
        }
        if (ch == 13) {
            try {
                buf = stoi(date);
                if (buf > 0 && buf <= 31) {
                    if (buf < 10) {
                        date2 += "0" + date + ".";
                        break;
                    }
                    else {
                        date2 += date + ".";
                        break;
                    }
                }
                else {
                    date = "";
                    CursorPos(34, 18); cout << "    "; CursorPos(34, 18);
                }
            }
            catch (const exception&) {
                CursorPos(20, 20);
                SleepMessagNo("Это не день");
                Sleep(1000);
                CursorPos(20, 20); SleepMessagText("                      ");
                date = "";
                CursorPos(34, 18); cout << "    "; CursorPos(34, 18);
                SetConsoleTextAttribute(hhCon, a.getInputColor1());
            }
        }
        if (ch == ESC) menuAdmin();
        if (ch == 8) {
            if (!date.empty()) {
                cout << (char)8 << ' ' << char(8);
                date.erase(date.length() - 1);
            }
        }
        else {
            if (size(date) > 3) {
            }
            else if (ch != 13) {
                cout << char(ch);
                date += char(ch);
            }
        }
    }
    /////////
    CursorPos(20, 19);
    SleepMessagText("Введите месяц: ");
    SetConsoleTextAttribute(hhCon, a.getInputColor1());
    date = ""; ch = 0;
    while (true) {
        ch = _getch();
        if (size(date) > 0) {
            cout << (char)8 << ' ' << (char)8;
            cout << date[date.size() - 1];
        }
        if (ch == 13) {
            try {
                buf = stoi(date);
                if (buf > 0 && buf <= 31) {
                    if (buf < 10) {
                        date2 += "0" + date + ".";
                        break;
                    }
                    else {
                        date2 += date + ".";
                        break;
                    }
                }
                else {
                    date = "";
                    CursorPos(35, 19); cout << "    "; CursorPos(35, 19);
                }
            }
            catch (const exception&) {
                CursorPos(20, 21);
                SleepMessagNo("Это не месяц");
                Sleep(1000);
                CursorPos(20, 21); SleepMessagText("                      ");
                date = "";
                CursorPos(35, 19); cout << "    "; CursorPos(35, 19);
                SetConsoleTextAttribute(hhCon, a.getInputColor1());
            }
        }
        if (ch == ESC) menuAdmin();
        if (ch == 8) {
            if (!date.empty()) {
                cout << (char)8 << ' ' << char(8);
                date.erase(date.length() - 1);
            }
        }
        else {
            if (size(date) > 3) {
            }
            else if (ch != 13) {
                cout << char(ch);
                date += char(ch);
            }
        }
    }
    ///////
    CursorPos(20, 20);
    SleepMessagText("Введите год: "); 
    SetConsoleTextAttribute(hhCon, a.getInputColor1());
    cout << "20";
    date = ""; ch = 0;
    while (true) {
        ch = _getch();
        if (size(date) > 0) {
            cout << (char)8 << ' ' << (char)8;
            cout << date[date.size() - 1];
        }
        if (ch == 13) {
            try {
                buf = stoi(date);
                if (buf > 0 && buf <= 99) {
                    if (buf < 10) {
                        if (size(date) == 2) {
                            date = date[1];
                        }
                        date2 += "200" + date;
                        break;
                    }
                    else {
                        date2 += "20" + date;
                        break;
                    }
                }
                else {
                    date = "";
                    CursorPos(35, 20); cout << "    "; CursorPos(35, 20);
                }
            }
            catch (const exception&) {
                CursorPos(20, 22);
                SleepMessagNo("Это не год");
                Sleep(1000);
                CursorPos(20, 22); SleepMessagText("                      ");
                date = "";
                CursorPos(35, 20); cout << "    "; CursorPos(35, 20);
                SetConsoleTextAttribute(hhCon, a.getInputColor1());
            }
        }
        if (ch == ESC) menuAdmin();
        if (ch == 8) {
            if (!date.empty()) {
                cout << (char)8 << ' ' << char(8);
                date.erase(date.length() - 1);
            }
        }
        else {
            if (size(date) > 3) {
            }
            else if (ch != 13) {
                cout << char(ch);
                date += char(ch);
            }
        }
    }
    SetConsoleTextAttribute(hhCon, a.getTextColor());
    ////////////////////////////////////////////////////////////////////////////////////////////////////////
    CursorPos(20, 23);
    SleepMessagText("Выберите тип кузова: ");
    SetConsoleTextAttribute(hhCon, a.getInputColor1()); bool b = true;
    CursorPos(20, 24); 
    cout << "[0]Тент [1]Jumbo [2]Автосцепка [3]Рефрижератор [4]Изометрич. [5]Контейнеровоз [6]Автовоз";
    while (b) {
        switch (_getch()) {
        case '0':
            type = "Тент";
            b = false;
            break;
        case '1':
            type = "Jumbo";
            b = false;
            break;
        case '2':
            type = "Автосцепка";
            b = false;
            break;
        case '3':
            type = "Рефрижератор";
            b = false;
            break;
        case '4':
            type = "Изометрич.";
            b = false;
            break;
        case '5':
            type = "Контейнеровоз";
            b = false;
            break;
        case '6':
            type = "Автовоз";
            b = false;
            break;
        case VK_ESCAPE:
            menuAdmin();
            break;
        default:
            CursorPos(20, 26);
            SleepMessagNo("**Такого нет**");
            CursorPos(20, 26);
            Sleep(1000);
            SleepMessagText("                       ");
            break;
        }
    } 
    SetConsoleTextAttribute(hhCon, a.getTextColor());
    CursorPos(20, 80);
    cout << "\tИтог: " << type;
    ////////////////////////////////////////////////////////////////////////////////////////////////////////
    CursorPos(20, 26);
    SleepMessagText("Введите вес(1-100т): ");
    SetConsoleTextAttribute(hhCon, a.getInputColor1());
    ch = 0;
    while (true) {
        ch = _getch();
        if (size(massa) > 0) {
            cout << (char)8 << ' ' << (char)8;
            cout << massa[massa.size() - 1];
        }
        if (ch == 13) {
            try {
                buf = stoi(massa);
                if (massa.size() == 0) { 
                    CursorPos(20, 28); 
                    SleepMessagNo("**Такого весса нет**"); 
                    Sleep(1000); 
                    CursorPos(20, 28);
                    SleepMessagNo("                        ");
                    massa = "";
                    CursorPos(41, 26);
                    cout << "                                    ";
                    CursorPos(41, 26);
                    SetConsoleTextAttribute(hhCon, a.getInputColor1());
                }
                if (buf > 0 && buf <= 100) {
                    break;
                }
                else {
                    massa = "";
                    CursorPos(41, 26);
                    cout << "                                    ";
                    CursorPos(41, 26);
                    SetConsoleTextAttribute(hhCon, a.getInputColor1());
                }
            }
            catch (const exception&) {
                CursorPos(20, 28);
                SleepMessagNo("**Это не номер**");
                Sleep(1000);
                CursorPos(20, 28);
                SleepMessagNo("                  ");
                massa = "";
                CursorPos(41, 26);
                cout << "                                    ";
                CursorPos(41, 26);
                SetConsoleTextAttribute(hhCon, a.getInputColor1());
            }
        }
        if (ch == ESC) menuAdmin();
        if (ch == 8) {
            if (!massa.empty()) {
                cout << (char)8 << ' ' << char(8);
                massa.erase(massa.length() - 1);
            }
        }
        else {
            if (size(massa) > 11) {
            }
            else if (ch != 13) {
                cout << char(ch);
                massa += char(ch);
            }
        }
    }
    ////////////////////////////////////////////////////////////////////////////////////////////////////////
    CursorPos(20, 28);
    SleepMessagText("Введите объём(1-100 м^3): ");
    SetConsoleTextAttribute(hhCon, a.getInputColor1());
    ch = 0;
    while (true) {
        ch = _getch();
        if (size(obiom) > 0) {
            cout << (char)8 << ' ' << (char)8;
            cout << obiom[obiom.size() - 1];
        }
        if (ch == 13) {
            try {
                buf = stoi(obiom);
                if (obiom.size() == 0) {
                    CursorPos(20, 30);
                    SleepMessagNo("**Такого объёма нет**");
                    Sleep(1000);
                    CursorPos(20, 30);
                    SleepMessagNo("                        ");
                    obiom = "";
                    CursorPos(47, 28);
                    cout << "                                    ";
                    CursorPos(47, 28);
                    SetConsoleTextAttribute(hhCon, a.getInputColor1());
                }
                if (buf > 0 && buf <= 100) {
                    break;
                }
                else {
                    obiom = "";
                    CursorPos(47, 28);
                    cout << "                                    ";
                    CursorPos(47, 28);
                    SetConsoleTextAttribute(hhCon, a.getInputColor1());
                }
            }
            catch (const exception&) {
                CursorPos(20, 30);
                SleepMessagNo("**Это не номер**");
                Sleep(1000);
                CursorPos(20, 30);
                SleepMessagNo("                  ");
                obiom = "";
                CursorPos(47, 28);
                cout << "                                    ";
                CursorPos(47, 28);
                SetConsoleTextAttribute(hhCon, a.getInputColor1());
            }
        }
        if (ch == ESC) menuAdmin();
        if (ch == 8) {
            if (!obiom.empty()) {
                cout << (char)8 << ' ' << char(8);
                obiom.erase(obiom.length() - 1);
            }
        }
        else {
            if (size(obiom) > 4) {
            }
            else if (ch != 13) {
                cout << char(ch);
                obiom += char(ch);
            }
        }
    }
    ////////////////////////////////////////////////////////////////////////////////////////////////////////
    CursorPos(20, 30);
    SleepMessagText("Итог: "); cout << fnum << " " << mest1 << " " << mest2 << " " << date1 << " " << date2 << " " << type << " " << massa << " " << obiom;
    ofstream f("katalog.txt", ios_base::in | ios_base::ate);
    f << endl << fnum << " " << mest1 << " " << mest2 << " " << date1 << " " << date2 << " " << type << " " << massa << " " << obiom;
    f.close();
    CursorPos(20, 32);
    SleepMessagYes("**Перевозка успешно добавлена**"); _getch();
    menuAdmin();
}

void Admin::DeleteFromCatalog() {
    Color a;
    Ramka();
    SetConsoleOutputCP(1251);
    ifstream f("katalog.txt");
    string line; int n = 0;
    vector<string> lines;
    while (getline(f, line)) {
        n++;
    }
    f.close();
    CursorPos(20, 20);
    cout << "Нажмите [Tab] чтобы просмотреть перевозки";
    CursorPos(20, 6);
    SleepMessagText("Введите намер строки которую вы хотите удалить из католога: ");
    SetConsoleTextAttribute(hhCon, a.getInputColor1());
    string num; int b; int ch = 0;
    while (true) {
        ch = _getch();
        if (size(num) > 0) {
            cout << (char)8 << ' ' << char(8);
            cout << num[num.size()-1];
        }
        if (ch == 13) {
            break;
        }
        if (ch == 9) system("start Katalog.exe");
        if (ch == ESC) menuAdmin();
        if (ch == 8) {
            if (!num.empty()) {
                cout << (char)8 << ' ' << char(8);
                num.erase(num.length() - 1);
            }
        }
        else {
            if (size(num) > 9) {
            }
            else if (ch != 13 && ch != 9) {
                cout << char(ch);
                num += char(ch);
            }
        }
    }
    try {
        b = stoi(num);
    }
    catch (const exception&) {
        CursorPos(20, 8);
        SleepMessagNo("**Это не номер строки**");
        Sleep(1000);
        system("cls");
        num = "";
        DeleteFromCatalog();
    }
    SetConsoleTextAttribute(hhCon, a.getTextColor());
    if (b <= n) {
        deleteLine("katalog.txt", b);
        CursorPos(20, 8);
        SleepMessagYes("**строка удалена***");
        Sleep(1000);
        system("cls");
        menuAdmin();
    }
    else {
        CursorPos(20, 8);
        SleepMessagNo("**Такой строчки нет**");
        Sleep(1000);
        system("cls");
        num = "";
        DeleteFromCatalog();
    }
}

void Admin::DeleteUser() {
    Color a;
    Ramka();
    SetConsoleOutputCP(1251);
    ifstream admin("admin.txt");
    string pass, password, username;
    getline(admin, pass);
    admin.close();
    CursorPos(20, 8);
    SleepMessagText("Введите пароль администратора: ");
    SetConsoleTextAttribute(hhCon, a.getInputColor1());
    int ch = 0;
    while (true) {
        ch = _getch();
        if (size(password) > 0) {
            cout << (char)8 << ' ' << char(8);
            cout << "*";
        }
        if (ch == 13) {
            break;
        }
        if (ch == ESC) menuAdmin2();
        if (ch == 8) {
            if (!password.empty()) {
                cout << (char)8 << ' ' << char(8);
                password.erase(password.length() - 1);
            }
        }
        else {
            if (size(password) > 29) {
            }
            else if (ch != 13) {
                cout << char(ch);
                password += char(ch);
            }
        }
    }
    SetConsoleTextAttribute(hhCon, a.getTextColor());
    if (password == pass) {
        SetConsoleTextAttribute(hhCon, a.getInputColor1());
        cout << " +";
        SetConsoleTextAttribute(hhCon, a.getTextColor());
        CursorPos(20, 10);
    }
    else {
        CursorPos(20, 10);
        Sleep(1000);
        SleepMessagNo("**Пороль введён неверно**");
        Sleep(1000);
        menuAdmin2();
    }
    SleepMessagText("Введите имя пользователя которого нужна удалить: ");
    SetConsoleTextAttribute(hhCon, a.getInputColor1());
    ch = 0;
    while (true) {
        ch = _getch();
        if (size(username) > 0) {
            cout << (char)8 << ' ' << (char)8;
            cout << username[username.size() - 1];
        }
        if (ch == 13) {
            break;
        }
        if (ch == ESC) menuAdmin2();
        if (ch == 8) {
            if (!username.empty()) {
                cout << (char)8 << ' ' << char(8);
                username.erase(username.length() - 1);
            }
        }
        else {
            if (size(username) > 29) {
            }
            else if (ch != 13) {
                cout << char(ch);
                username += char(ch);
            }
        }
    }
    SetConsoleTextAttribute(hhCon, a.getTextColor());
    ifstream gg(username + ".txt");
    if (gg) {
        if (username != "katalog" && username != "base_users" && username != "admin" && username != "user" && username != "search" && username != "color") {
            string filename = username + ".txt";
            ofstream qout(filename);
            string path = filename;
            const char* j = path.c_str();
            qout.close();
            gg.close();
            remove(j);
            ofstream qout2("zakaz" + username + ".txt");
            string path2 = "zakaz" + username + ".txt";
            const char* i = path2.c_str();
            qout2.close();
            remove(i);
            ifstream file("base_users.txt");
            string line;
            vector<string> lines;
            while (getline(file, line)) {
                lines.push_back(line);
            }
            int k = 0;
            for (string line1 : lines) {
                k++;
                if (line1 == username) {
                    deleteLine("base_users.txt", k);
                }
            }
            file.close();
            CursorPos(20, 12);
            SleepMessagYes("**Пользователь успешно удалён**");
            Sleep(2000);
            menuAdmin2();
        }
        else {
            CursorPos(20, 12);
            SleepMessagNo("**Такого пользователя нет**");
            Sleep(1000);
            menuAdmin2();
        }
    }
    else {
        CursorPos(20, 12);
        SleepMessagNo("**Такого пользователя нет**");
        Sleep(1000);
        menuAdmin2();
    }
}

void Admin::Catalog() {
    SetConsoleOutputCP(1251);
    system("start Katalog.exe");
    menuAdmin();
}

void Admin::ChangeName() {
    Color a;
    Ramka();
    SetConsoleOutputCP(1251);
    string user, user1, new_name, password, inf; string filename;
    CursorPos(20, 8);
    SleepMessagText("Введите имя пользователя: ");
    SetConsoleTextAttribute(hhCon, a.getInputColor1());
    int ch = 0;
    while (true) {
        ch = _getch();
        if (size(user) > 0) {
            cout << (char)8 << ' ' << char(8);
            cout << user[user.size() - 1];
        }
        if (ch == 13) {
            SetConsoleTextAttribute(hhCon, a.getTextColor());
            filename = user + ".txt";
            ifstream f(filename);
            getline(f, user1);
            getline(f, password);
            getline(f, inf);
            if (user == "katalog" || user == "base_users" || user == "admin" || user == "user" || user == "search" || user == "color") {
                int b = MessageBox(NULL, L"Отказано в доступе", L"Ошибка", MB_OK);
                switch (b) {
                case IDOK:
                    user = "";
                    CursorPos(47, 8);
                    cout << "                               ";
                    CursorPos(47, 8);
                }
            }
            if (!f.is_open()) {
                CursorPos(20, 8);
                SleepMessagText("**Такого пользователя нет**");
                Sleep(1000);
                CursorPos(20, 8);
                SleepMessagText("                                     ");
                user = "";
                CursorPos(47, 8);
                cout << "                               ";
                CursorPos(47, 8);
                f.close();
            }
            else {
                f.close();
                break;
            }
        }
        if (ch == 9) system("start UserBaseDan.exe");
        if (ch == ESC) menuAdmin2();
        if (ch == 8) {
            if (!user.empty()) {
                cout << (char)8 << ' ' << char(8);
                user.erase(user.length() - 1);
            }
        }
        else {
            if (size(user) > 10) {
            }
            else if (ch != 13 && ch != 9) {
                cout << char(ch);
                user += char(ch);
            }
        }
    }

    CursorPos(20, 10);
    SleepMessagText("Введите новое имя: ");
    SetConsoleTextAttribute(hhCon, a.getInputColor1());
    ch = 0;
    while (true) {
        ch = _getch();
        if (size(new_name) > 0) {
            cout << (char)8 << ' ' << char(8);
            cout << new_name[new_name.size() - 1];
        }
        if (ch == 13) {
            new_name.erase(remove(new_name.begin(), new_name.end(), ' '), new_name.end());
            ifstream test(new_name + ".txt");
            if (size(new_name) < 3 || size(new_name) > 10) {
                int a = MessageBox(NULL, L"Новое имя вне границ", L"Ошибка", MB_OK);
                switch (a) {
                case IDOK:
                    test.close();
                    new_name = "";
                    CursorPos(39, 10); cout << "                              "; CursorPos(39, 10);
                }
            }
            else if (test) {
                int a = MessageBox(NULL, L"Такой пользователь уже есть", L"Ошибка", MB_OK);
                switch (a) {
                case IDOK:
                    test.close();
                    new_name = "";
                    CursorPos(39, 10); cout << "                              "; CursorPos(39, 10);
                }
            }
            else
                break;
        }
        if (ch == ESC) menuAdmin2();
        if (ch == 8) {
            if (!new_name.empty()) {
                cout << (char)8 << ' ' << char(8);
                new_name.erase(new_name.length() - 1);
            }
        }
        else {
            if (size(new_name) > 29) {
            }
            else if (ch != 13) {
                cout << char(ch);
                new_name += char(ch);
            }
        }
    }

    SetConsoleTextAttribute(hhCon, a.getTextColor());
    string buf_name = user;
    string oldfilename = filename;
    string newfilename = new_name + ".txt";
    //user = new_name;
    ofstream fileinput(filename);
    fileinput << new_name << endl;
    fileinput << password << endl;
    fileinput << inf;
    fileinput.close();
    rename(oldfilename.c_str(), newfilename.c_str());
    oldfilename = "zakaz" + filename;
    newfilename = "zakaz" + new_name + ".txt";
    rename(oldfilename.c_str(), newfilename.c_str());
    filename = new_name + ".txt";
    ifstream file("base_users.txt");
    string line;
    vector<string> lines;
    while (getline(file, line)) {
        lines.push_back(line);
    }
    int k = 0;
    for (string line1 : lines) {
        k++;
        if (line1 == buf_name) {
            deleteLine("base_users.txt", k);
        }
    }
    file.close();

    int y = 0; string firstsymb;
    ifstream ff2("base_users.txt");
    ff2 >> firstsymb;
    if (firstsymb == "") y++;
    ff2.close();
    ofstream ffff1("base_users.txt", ios_base::in | ios_base::ate);
    if (y == 1)
        ffff1 << new_name;
    else
        ffff1 << endl << new_name;
    ffff1.close();
    CursorPos(20, 12);
    SleepMessagYes("**Имя успешно изменёно**");
    Sleep(1000);
    system("cls");
    menuAdmin2();
}

void Admin::ChangePassword() {
    Color a;
    Ramka();
    SetConsoleOutputCP(1251);
    CursorPos(20, 8);
    SleepMessagText("Введите имя пользователя: ");
    SetConsoleTextAttribute(hhCon, a.getInputColor1());
    string user, password, new_password, inf; string filename;
    int ch = 0;
    while (true) {
        ch = _getch();
        if (size(user) > 0) {
            cout << (char)8 << ' ' << char(8);
            cout << user[user.size() - 1];
        }
        if (ch == 13) {
            SetConsoleTextAttribute(hhCon, a.getTextColor());
            filename = user + ".txt";
            ifstream f(filename);
            getline(f, user);
            getline(f, password);
            getline(f, inf);
            if (user == "katalog" || user == "base_users" || user == "admin" || user == "user" || user == "search" || user == "color") {
                int b = MessageBox(NULL, L"Отказано в доступе", L"Ошибка", MB_OK);
                switch (b) {
                case IDOK:
                    user = "";
                    CursorPos(47, 8);
                    cout << "                               ";
                    CursorPos(47, 8);
                }
            }
            if (!f.is_open()) {
                CursorPos(20, 8);
                SleepMessagText("**Такого пользователя нет**");
                Sleep(1000);
                CursorPos(20, 8);
                SleepMessagText("                                     ");
                user = "";
                CursorPos(47, 8);
                cout << "                               ";
                CursorPos(47, 8);
                f.close();
            }
            else {
                f.close();
                break;
            }
        }
        if (ch == ESC) menuAdmin2();
        if (ch == 9) system("start UserBaseDan.exe");
        if (ch == 8) {
            if (!user.empty()) {
                cout << (char)8 << ' ' << char(8);
                user.erase(user.length() - 1);
            }
        }
        else {
            if (size(user) > 29) {
            }
            else if (ch != 13 && ch != 9) {
                cout << char(ch);
                user += char(ch);
            }
        }
    }
    CursorPos(20, 10);
    SleepMessagText("Введите новый пароль: ");
    SetConsoleTextAttribute(hhCon, a.getInputColor1() );
    ch = 0; bool eyes = false;
    while (true) {
        ch = _getch();
        if (size(new_password) > 0) {
            if (eyes == false) { funk1(); }
            else { funk2(new_password); }
        }
        if (ch == 13) {
            if (new_password.size() < 3 || new_password.size() > 10) {
                int a = MessageBox(NULL, L"Новый пароль вне границ", L"Ошибка", MB_OK);
                switch (a) {
                case IDOK:
                    new_password = "";
                    CursorPos(44, 10); cout << "                          "; CursorPos(44, 10);
                }
            }
            else
                break;
        }
        if (ch == ESC) menuAdmin2();
        if (ch == RIGHT) {
            eyes = true;  cout << (char)8 << ' ' << char(8);
            new_password.erase(new_password.length() - 1);
            CursorPos(42, 10); cout << new_password;
        }
        if (ch == LEFT) {
            eyes = false;  cout << (char)8 << ' ' << char(8);
            new_password.erase(new_password.length() - 1);
            CursorPos(42, 10);
            for (int i = 0; i < new_password.size(); i++) {
                cout << "*";
            }
        }
        if (ch == 8) {
            if (!new_password.empty()) {
                cout << (char)8 << ' ' << char(8);
                new_password.erase(new_password.length() - 1);
            }
        }
        else {
            if (size(new_password) > 10) {
            }
            else if (ch != 13 && ch != RIGHT && ch != LEFT) {
                cout << char(ch);
                new_password += char(ch);
            }
        }
    }
    SetConsoleTextAttribute(hhCon, a.getTextColor());
    ofstream fileinput(filename);
    fileinput << user << endl;
    fileinput << new_password << endl;
    fileinput << inf;
    fileinput.close();
    CursorPos(20, 12);
    SleepMessagYes("**Пароль успешно изменён**");
    Sleep(1000);
    menuAdmin2();
}

void Admin::ChangeNum() {
    Color a;
    Ramka();
    SetConsoleOutputCP(1251);
    CursorPos(20, 8);
    SleepMessagText("Введите имя пользователя: ");
    SetConsoleTextAttribute(hhCon, a.getInputColor1());
    string user, password, inf; string filename;
    int ch = 0;
    while (true) {
        ch = _getch();
        if (size(user) > 0) {
            cout << (char)8 << ' ' << char(8);
            cout << user[user.size() - 1];
        }
        if (ch == 13) {
            SetConsoleTextAttribute(hhCon, a.getTextColor());
            filename = user + ".txt";
            ifstream f(filename);
            getline(f, user);
            getline(f, password);
            getline(f, inf);
            if (user == "katalog" || user == "base_users" || user == "admin" || user == "user" || user == "search" || user == "color") {
                int b = MessageBox(NULL, L"Отказано в доступе", L"Ошибка", MB_OK);
                switch (b) {
                case IDOK:
                    user = "";
                    CursorPos(47, 8);
                    cout << "                               ";
                    CursorPos(47, 8);
                }
            }
            if (!f.is_open()) {
                CursorPos(20, 8);
                SleepMessagText("**Такого пользователя нет**");
                Sleep(1000);
                CursorPos(20, 8);
                SleepMessagText("                                     ");
                user = "";
                CursorPos(47, 8);
                cout << "                               ";
                CursorPos(47, 8);
                f.close();
            }
            else {
                f.close();
                break;
            }
        }
        if (ch == ESC) menuAdmin2();
        if (ch == 9) system("start UserBaseDan.exe");
        if (ch == 8) {
            if (!user.empty()) {
                cout << (char)8 << ' ' << char(8);
                user.erase(user.length() - 1);
            }
        }
        else {
            if (size(user) > 29) {
            }
            else if (ch != 13 && ch != 9) {
                cout << char(ch);
                user += char(ch);
            }
        }
    }
    
    string new_inf, ff;
    CursorPos(20, 10);
    SleepMessagText("Введите новый номер телефона: ");
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
            new_inf = "80" + ff;
            new_inf.erase(remove(new_inf.begin(), new_inf.end(), ' '), new_inf.end());
            SetConsoleTextAttribute(hhCon, a.getTextColor());
            if (ff.size() != 9 || !isInt(ff)) {
                int a1 = MessageBox(NULL, L"Это не номер телефона", L"Ошибка", MB_OK);
                CursorPos(50, 10); cout << "                            "; CursorPos(46, 13);
                new_inf = ""; ff = "";  SetConsoleTextAttribute(hhCon, a.getInputColor1());
            }
            else
                break;
        }
        if (ch == ESC) menuAdmin2();
        if (ch == 8) {
            if (!ff.empty()) {
                cout << (char)8 << ' ' << char(8);
                ff.erase(ff.length() - 1);
            }
        }
        else {
            if (size(ff) > 29) {
            }
            else if (ch != 13) {
                cout << char(ch);
                ff += char(ch);
            }
        }
    }
    inf = new_inf;
    ofstream fileinput(filename);
    fileinput << user << endl;
    fileinput << password << endl;
    fileinput << inf;
    fileinput.close();
    CursorPos(20, 12);
    SleepMessagYes("**Телефон успешно изменён**");
    Sleep(1000);
    system("cls");
    menuAdmin2();
}

void Admin::ChangeZak() {
    Color a;
    Ramka();
    SetConsoleOutputCP(1251);
    CursorPos(20, 6);
    SleepMessagText("Введите имя пользователя: ");
    SetConsoleTextAttribute(hhCon, a.getInputColor1());
    string user, password, inf; string filename;
    int ch = 0;
    while (true) {
        ch = _getch();
        if (size(user) > 0) {
            cout << (char)8 << ' ' << char(8);
            cout << user[user.size() - 1];
        }
        if (ch == 13) {
            SetConsoleTextAttribute(hhCon, a.getTextColor());
            filename = user + ".txt";
            ifstream f(filename);
            getline(f, user);
            getline(f, password);
            getline(f, inf);
            if (user == "katalog" || user == "base_users" || user == "admin" || user == "user" || user == "search" || user == "color") {
                int b = MessageBox(NULL, L"Отказано в доступе", L"Ошибка", MB_OK);
                switch (b) {
                case IDOK:
                    user = "";
                    CursorPos(47, 6);
                    cout << "                               ";
                    CursorPos(47, 6);
                }
            }
            if (!f.is_open()) {
                CursorPos(20, 6);
                SleepMessagText("**Такого пользователя нет**");
                Sleep(1000);
                CursorPos(20, 6);
                SleepMessagText("                                     ");
                user = "";
                CursorPos(47, 6);
                cout << "                               ";
                CursorPos(47, 6);
                f.close();
            }
            else {
                f.close();
                break;
            }
        }
        if (ch == ESC) menuAdmin2();
        if (ch == 9) system("start UserBaseDan.exe");
        if (ch == 8) {
            if (!user.empty()) {
                cout << (char)8 << ' ' << char(8);
                user.erase(user.length() - 1);
            }
        }
        else {
            if (size(user) > 29) {
            }
            else if (ch != 13 && ch != 9) {
                cout << char(ch);
                user += char(ch);
            }
        }
    }
    SetConsoleOutputCP(1251);
    ifstream f("zakaz" + filename);
    string line; int n = 0;
    vector<string> lines;
    while (getline(f, line)) {
        n++;
    }
    f.close();
    CursorPos(20, 20);
    cout << "Нажмите [Tab] чтобы просмотреть свои перевозки";
    CursorPos(20, 8);
    SleepMessagText("Введите намер строки которую вы хотите удалить: "); string num;
    int buf; ch = 0;
    SetConsoleTextAttribute(hhCon, a.getInputColor1());
    while (true) {
        ch = _getch();
        if (size(num) > 0) {
            cout << (char)8 << ' ' << (char)8;
            cout << num[num.size() - 1];
        }
        if (ch == 13) {
            break;
        }
        if (ch == 9) {
            ofstream f("user.txt");
            string user = "zakaz" + filename;
            f << user;
            f.close();
            system("start MyZakaz.exe");
        }
        if (ch == ESC) menuAdmin();
        if (ch == 8) {
            if (!num.empty()) {
                cout << (char)8 << ' ' << char(8);
                num.erase(num.length() - 1);
            }
        }
        else {
            if (size(num) > 20) {
            }
            else if (ch != 13 && ch != 9) {
                cout << char(ch);
                num += char(ch);
            }
        }
    }
    SetConsoleTextAttribute(hhCon, a.getTextColor());
    try {
        buf = stoi(num);
    }
    catch (const exception&) {
        CursorPos(20, 8);
        SleepMessagNo("**Это не номер**");
        Sleep(1000);
        system("cls");
        num = "";
        ChangeZak();
    }
    if (buf <= n) {
        deleteLine("zakaz" + filename, buf);
        CursorPos(20, 10);
        SleepMessagYes("**Cтрока удалена***");
        Sleep(1000);
        menuAdmin();
    }
    else {
        CursorPos(20, 10);
        SleepMessagNo("**Такой строчки нет**");
        Sleep(1000);
        system("cls");
        num = "";
        ChangeZak();
    }
}

///~~~~Готово~~~~