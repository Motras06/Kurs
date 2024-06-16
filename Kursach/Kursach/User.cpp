#include "User.h"

User::User(string username_) {
    SetConsoleOutputCP(1251);
    this->filename = username_ + ".txt";
    ifstream fin(this->filename);
    string n, p, f; 
    getline(fin, n);
    getline(fin, p);
    getline(fin, f);
    this->username = n;
    this->password = p;
    this->inf = f;
    fin.close();
}

void User::ChangePassword() {
    Color a;
    Ramka();
    SetConsoleOutputCP(1251);
    ifstream f(this->filename);
    if (!f.is_open()) {
        CursorPos(20, 8);
        SleepMessagText("error");
        Sleep(1000);
        menuPolz2(this->username);
    }
    string password, new_password;
    CursorPos(20, 8);
    cout << "Введите пароль: ";
    SetConsoleTextAttribute(hhCon, a.getInputColor1());
    int ch = 0; bool eyes = false;
    while (true) {
        ch = _getch();
        if (size(password) > 0) {
            if (eyes == false) { funk1(); }
            else { funk2(password); }
        }
        if (ch == 13) {
            if (this->password != password) {
                int nn = MessageBox(NULL, L"Пароль введен не верно", L"Ошибка", MB_OK);
                password = "";
                CursorPos(36, 8);
                cout << "                                    ";
                CursorPos(36, 8);
            }
            else
                break;
        }
        if (ch == ESC) MyInf();
        if (ch == RIGHT) {
            eyes = true;  cout << (char)8 << ' ' << char(8);
            password.erase(password.length() - 1);
            CursorPos(36, 8); cout << password;
        }
        if (ch == LEFT) {
            eyes = false;  cout << (char)8 << ' ' << char(8);
            password.erase(password.length() - 1);
            CursorPos(36, 8);
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
            if (size(password) > 29) {
            }
            else if (ch != 13 && ch != RIGHT && ch != LEFT) {
                cout << char(ch);
                password += char(ch);
            }
        }
    }
    SetConsoleTextAttribute(hhCon, a.getInputColor1());
    cout << " +";
    SetConsoleTextAttribute(hhCon, a.getTextColor());
    CursorPos(20, 10);
    SleepMessagText("Введите новый пароль: ");
    SetConsoleTextAttribute(hhCon, a.getInputColor1());
    ch = 0;
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
                    CursorPos(42, 10); cout << "                          "; CursorPos(42, 10);
                }
            }
            else
                break;
        }
        if (ch == ESC) MyInf();
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
    cout << " +";
    SetConsoleTextAttribute(hhCon, a.getTextColor());
    this->password = new_password;
    ofstream fileinput(this->filename);
    fileinput << this->username << endl;
    fileinput << this->password << endl;
    fileinput << this->inf;
    fileinput.close();
    CursorPos(20, 12);
    SleepMessagYes("**Пароль успешно изменён**");
    Sleep(1000);
    MyInf();
}

void User::ViewCatalog() {
    system("start Katalog.exe");
    menuPolz(this->username);
}

void User::MakeOrder() {
    Color a;
    Ramka();
    SetConsoleOutputCP(1251);
    string num;
    CursorPos(20, 20);
    cout << "Нажмите [Tab] чтобы просмотреть перевозки";
    CursorPos(20, 6);
    cout << "Введите номер интересующей вас перевозки: ";
    int buf;  int ch = 0;
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
            system("start Katalog.exe");
        }
        if (ch == ESC) menuPolz(this->username);
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
    catch (const std::exception&) {
        CursorPos(20, 8);
        SleepMessagNo("**Это не номер**");
        Sleep(1000);
        num = "";
        system("cls");
        MakeOrder();
    }
    buf--;
    ifstream f("katalog.txt");
    vector<string> lines;
    string line; int num1 = 0;
    while (!f.eof()) {
        getline(f, line);
        num1++;
    }
    if (buf < num1 && buf >= 0) {
        f.seekg(0);
        while (!f.eof()) {
            getline(f, line);
            lines.push_back(line);
        }
        f.close();
        {
            int y = 0; string firstsymb;
            ifstream ff("zakaz" + this->filename);
            ff >> firstsymb;
            if (firstsymb == "") y++;
            ff.close();
            ofstream fin("zakaz" + this->filename, ios_base::in | ios_base::ate);
            if (y == 1)
                fin << lines[buf];
            else
                fin << endl << lines[buf];
            fin.close();
        }
        CursorPos(20, 8);
        SleepMessagYes("**Вы добавили перевозку к себе в заказы**");
        Sleep(1000);
        menuPolz(this->username);
    }
    else {
        CursorPos(20, 8);
        SleepMessagNo("**Такого номера нет в каталоге**");
        f.close();
        Sleep(1000);
        num = "";
        system("cls");
        MakeOrder();
    }
}

void User::DeleteShipment() {
    Color a;
    Ramka();
    SetConsoleOutputCP(1251);
    ifstream f("zakaz" + this->filename);
    string line; int n = 0;
    vector<string> lines;
    while (getline(f, line)) {
        n++;
    }
    f.close();
    CursorPos(20, 20);
    cout << "Нажмите [Tab] чтобы просмотреть свои перевозки";
    CursorPos(20, 6);
    cout << "Введите намер строки которую вы хотите удалить: "; string num;
    int buf;  int ch = 0;
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
            string user = "zakaz" + this->filename;
            f << user;
            f.close();
            system("start MyZakaz.exe");
        }
        if (ch == ESC) MyInf();
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
    catch (const std::exception&) {
        CursorPos(20, 8);
        SleepMessagNo("**Это не номер**");
        Sleep(1000);
        system("cls");
        num = "";
        DeleteShipment();
    }
    if (buf <= n) {
        deleteLine("zakaz" + this->filename, buf);
        CursorPos(20, 8);
        SleepMessagYes("**Cтрока удалена***");
        Sleep(1000);
        MyInf();
    }
    else {
        CursorPos(20, 8);
        SleepMessagNo("**Такой строчки нет**");
        Sleep(1000);
        system("cls");
        num = "";
        DeleteShipment();
    }
}

void User::MyOrder() {
    SetConsoleOutputCP(1251);
    ofstream f("user.txt");
    string user = "zakaz" + this->filename;
    f << user;
    f.close();
    system("start MyZakaz.exe");
    MyInf();
}

void User::DeleteAkk() {
    Color a;
    Ramka();
    SetConsoleOutputCP(1251);
    ifstream fin(this->filename);
    string password, username;
    getline(fin, this->username);
    getline(fin, this->password);
    fin.close();
    CursorPos(20, 6);
    SleepMessagText("Введите пароль пользователя: "); 
    SetConsoleTextAttribute(hhCon, a.getInputColor1());
    int ch = 0; bool eyes = false;
    while (true) {
        ch = _getch();
        if (size(password) > 0) {
            if (eyes == false) { funk1(); }
            else { funk2(password); }
        }
        if (ch == 13) {
            if (this->password != password) {
                int nn = MessageBox(NULL, L"Пароль введен не верно", L"Ошибка", MB_OK);
                password = "";
                CursorPos(49, 6);
                cout << "                                    ";
                CursorPos(49, 6);
            }
            else
                break;
        }
        if (ch == ESC) MyInf();
        if (ch == RIGHT) {
            eyes = true;  cout << (char)8 << ' ' << char(8);
            password.erase(password.length() - 1);
            CursorPos(49, 6); cout << password;
        }
        if (ch == LEFT) {
            eyes = false;  cout << (char)8 << ' ' << char(8);
            password.erase(password.length() - 1);
            CursorPos(49, 6);
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
            if (size(password) > 29) {
            }
            else if (ch != 13 && ch != RIGHT && ch != LEFT) {
                cout << char(ch);
                password += char(ch);
            }
        }
    }
    SetConsoleTextAttribute(hhCon, a.getTextColor());
    if (password == this->password) {
        SetConsoleTextAttribute(hhCon, a.getInputColor1());
        cout << " +";
        SetConsoleOutputCP(1251);
        SetConsoleTextAttribute(hhCon, a.getTextColor());
        ofstream qout1(this->filename);
        string path1 = this->filename;
        const char* j = path1.c_str();
        qout1.close();
        remove(j);
        ofstream qout2("zakaz" + this->filename);
        string path2 = "zakaz" + this->filename;
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
            if (line1 == this->username) {
                deleteLine("base_users.txt", k);
            }
        }
        file.close();
        CursorPos(20, 8);
        SleepMessagYes("**Пользователь успешно удалён**");
        Sleep(1000);
        menu();
    }
}

void User::Search() {
    Color a;
    Ramka();
    SetConsoleOutputCP(1251);
    CursorPos(20, 20);
    cout << "Нажмите [Tab] чтобы просмотреть перевозки";
    CursorPos(20, 6);
    SleepMessagText("Введите параметр для поиска: ");
    SetConsoleTextAttribute(hhCon, a.getInputColor1());
    string parametr;
    int ch = 0;
    while (true) {
        ch = _getch();
        if (size(parametr) > 0) {
            cout << (char)8 << ' ' << (char)8;
            cout << parametr[parametr.size() - 1];
        }
        if (ch == 13) {
            break;
        }
        if (ch == 9) {
            system("start Katalog.exe");
        }
        if (ch == ESC) menuPolz(this->username);
        if (ch == 8) {
            if (!parametr.empty()) {
                cout << (char)8 << ' ' << char(8);
                parametr.erase(parametr.length() - 1);
            }
        }
        else {
            if (size(parametr) > 16) {
            }
            else if (ch != 13 && ch != 9) {
                cout << char(ch);
                parametr += char(ch);
            }
        }
    }
    SetConsoleTextAttribute(hhCon, a.getTextColor());
    ofstream file("search.txt");
    file << parametr;
    file.close();
    system("start Search.exe");
    Sleep(1000);
    menuPolz(this->username);
}

void User::SearchNum(){
    Color a;
    Ramka();
    SetConsoleOutputCP(1251);
    CursorPos(20, 20);
    cout << "Нажмите [Tab] чтобы просмотреть перевозки";
    CursorPos(20, 6);
    cout << "Введите номер для поиска: ";
    SetConsoleTextAttribute(hhCon, a.getInputColor1());
    string parametr;
    int ch = 0;
    while (true) {
        ch = _getch();
        if (size(parametr) > 0) {
            cout << (char)8 << ' ' << (char)8;
            cout << parametr[parametr.size() - 1];
        }
        if (ch == 13) {
            if (parametr.size() > 4 || !isInt(parametr)) {
                CursorPos(20, 8);
                SleepMessagNo("**это не номер строки**");
                Sleep(2000);
                parametr = "";
                system("cls");
                SearchNum();
            }
            else
                break;
        }
        if (ch == 9) {
            system("start Katalog.exe");
        }
        if (ch == ESC) menuPolz(this->username);
        if (ch == 8) {
            if (!parametr.empty()) {
                cout << (char)8 << ' ' << char(8);
                parametr.erase(parametr.length() - 1);
            }
        }
        else {
            if (size(parametr) > 16) {
            }
            else if (ch != 13 && ch != 9) {
                cout << char(ch);
                parametr += char(ch);
            }
        }
    }
    SetConsoleTextAttribute(hhCon, a.getTextColor());
    ofstream file("search.txt");
    file << parametr;
    file.close();
    system("start SearchNum.exe");
    Sleep(1000);
    menuPolz(this->username);
}

void User::ChangeName() {
    Color a;
    Ramka();
    SetConsoleOutputCP(1251);
    fstream f(this->filename);
    if (!f.is_open()) {
        CursorPos(20, 8);
        SleepMessagNo("error");
        Sleep(3000);
        menuPolz2(this->username);
    }
    f.close();
    string password, new_name;
    CursorPos(20, 8);
    cout << "Введите пароль: ";
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
        if (ch == ESC) MyInf();
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
    if (password != this->password) {
        CursorPos(20, 10);
        SleepMessagNo("**Пароль введён неверно**");
        Sleep(1000);
        password = "";
        system("cls");
        ChangeName();
    }
    SetConsoleTextAttribute(hhCon, a.getInputColor1());
    cout << " +";
    SetConsoleOutputCP(1251);
    SetConsoleTextAttribute(hhCon, a.getTextColor());
    CursorPos(20, 10);
    cout << "Введите новое имя: ";
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
        if (ch == ESC) MyInf();
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
        string buf_name = this->username;
        string oldfilename = this->filename;
        string newfilename = new_name + ".txt";
        this->username = new_name;
        ofstream fileinput(this->filename);
        fileinput << this->username << endl;
        fileinput << this->password << endl;
        fileinput << this->inf;
        fileinput.close();
        rename(oldfilename.c_str(), newfilename.c_str());
        oldfilename = "zakaz" + this->filename;
        newfilename = "zakaz" + new_name + ".txt";
        rename(oldfilename.c_str(), newfilename.c_str());
        this->filename = new_name + ".txt";
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
        MyInf();
}

void User::MyInf() {
    system("cls");
    Ramka();
    Color a;
    SetConsoleOutputCP(1251);
    CursorPos(20, 6);
    cout << "Имя пользователя: ";
    SleepMessagYes(this->username);
    CursorPos(20, 8);
    cout << "Номер телефона пользователя: ";
    SleepMessagYes(this->inf);
    CursorPos(20, 10);
    cout << "Пароль: ";
    SetConsoleTextAttribute(hhCon, a.getInputColor1());
    for (int i = 0; i < this->password.size(); i++) {
        if (i < 4) {
            cout << this->password[i];
            Sleep(10);
        }
        else {
            cout << "*"; Sleep(10);
        }
    }
    SetConsoleTextAttribute(hhCon, a.getTextColor());

    SetConsoleOutputCP(1251);
    string T[] = { "Сменить имя", "Сменить пароль ", "Сменить номер", "Мои перевозки", "Изменить перевозки ", "Удалить аккаунт", "Назад" };
    char aT = 0;
    char c;
    Ramka();
    while (true)
    {
        char x = 80, y = 10;
        CursorPos(x, y);
        SetConsoleTextAttribute(hhCon, a.getTextColor());
        x = 25, y = 20;
        CursorPos(x, y);
        for (char i = 0; i < size(T); i++)
        {
            int siz = T[i].size();
            const int siz_max = 24;
            int n = siz_max - siz;
            int n2 = n / 2;
            string probel;
            for (int j = 0; j < n2; j++) probel += " ";
            if (i == aT) SetConsoleTextAttribute(hhCon, a.getInputColor1());
            else SetConsoleTextAttribute(hhCon, a.getTextColor());
            CursorPos(x, y++);
            cout << endl;
            CursorPos(x, y++);
            SetConsoleOutputCP(CP_UTF8);
            cout << u8"╔═══════════════════════╗";
            CursorPos(x, y++);
            cout << u8"║";
            SetConsoleOutputCP(1251);
            cout << probel << T[i] << probel;
            SetConsoleOutputCP(CP_UTF8);
            cout << u8"║" << endl;
            CursorPos(x, y++);
            SetConsoleOutputCP(CP_UTF8);
            cout << u8"╚═══════════════════════╝";
        }
        c = _getch();
        if (c == -32) c = _getch();
        switch (c)
        {
        case ESC:
            system("cls");
            menuPolz(this->username);
        case UP:
        case 'w':
        case 'W':
        case 'Ц':
        case 'ц':
            if (aT > 0)
                --aT;
            break;
        case DOWN:
        case 'ы':
        case 'Ы':
        case 's':
        case 'S':
            if (aT < size(T) - 1)
                ++aT;
            break;
        case ENTER:
            switch (aT)
            {
            case 0:
            {
                system("cls");
                ChangeName();
                break;
            }
            case 1:
            {
                system("CLS");
                ChangePassword();
                break;
            }
            case 2:
            {
                system("CLS");
                ChangeNum();
                break;
            }
            case 3:
            {
                system("cls");
                MyOrder();
                break;
            }
            case 4:
            {
                system("cls");
                DeleteShipment();
                break;
            }
            case 5:
            {
                system("cls");
                DeleteAkk();
                break;
            }
            case 6:
            {
                system("cls");
                menuPolz(this->username);
            }
            default:
                cout << "" << (char)c << endl;
            }
        }
    }
}

void User::ChangeNum() {
    Color a;
    Ramka();
    SetConsoleOutputCP(1251);
    fstream f(this->filename);
    if (!f.is_open()) {
        CursorPos(20, 8);
        SleepMessagText("error");
        Sleep(1000);
        menuPolz2(this->username);
    }
    f.close();
    string password, new_inf, ff;
    CursorPos(20, 8);
    cout << "Введите пароль: ";
    SetConsoleTextAttribute(hhCon, a.getInputColor1());
    int ch = 0; bool eyes = false;
    while (true) {
        ch = _getch();
        if (size(password) > 0) {
            if (eyes == false) { funk1(); }
            else { funk2(password); }
        }
        if (ch == 13) {
            if (this->password != password) {
                int nn = MessageBox(NULL, L"Пароль введен не верно", L"Ошибка", MB_OK);
                password = "";
                CursorPos(36, 8);
                cout << "                                    ";
                CursorPos(36, 8);
            }
            else
                break;
        }
        if (ch == ESC) MyInf();
        if (ch == RIGHT) {
            eyes = true;  cout << (char)8 << ' ' << char(8);
            password.erase(password.length() - 1);
            CursorPos(36, 8); cout << password;
        }
        if (ch == LEFT) {
            eyes = false;  cout << (char)8 << ' ' << char(8);
            password.erase(password.length() - 1);
            CursorPos(36, 8);
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
            if (size(password) > 29) {
            }
            else if (ch != 13) {
                cout << char(ch);
                password += char(ch);
            }
        }
    }
    SetConsoleTextAttribute(hhCon, a.getInputColor1());
    cout << " +";
    SetConsoleOutputCP(1251);
    SetConsoleTextAttribute(hhCon, a.getTextColor());
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
        if (ch == ESC) MyInf();
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
    this->inf = new_inf;
    ofstream fileinput(this->filename);
    fileinput << this->username << endl;
    fileinput << this->password << endl;
    fileinput << this->inf;
    fileinput.close();
    CursorPos(20, 12);
    SleepMessagYes("**Телефон успешно изменён**");
    Sleep(1000);
    system("cls");
    MyInf();
}
   