#include "User.h"

void menu() {
    User_vh user;
    Color a;
    system("cls");
    SetConsoleOutputCP(1251);
    string T[] = { "Войти", "Регистрация", "Войти как админ", "Прочее ", "Руководсвто", "Цвета", "Выход" };
    char aT = 0;
    char c;
    Ramka();
    //Нажмите Esc чтобы выйти
    for (int i = 0; i < 4; i++) {
        CursorPos(25, i); cout << u8"█";
    }
   CursorPos(1, 4);
    for (int i = 1; i < 26; i++) {
        if (i == 25) cout << u8"█";
        else
            cout << u8"▄";
    }
    SetConsoleOutputCP(1251);
    CursorPos(1, 2);
    cout << "Нажмите Esc чтобы выйти";

    while (true)
    {
        char x = 80, y = 10;
        CursorPos(x, y);
        SetConsoleTextAttribute(hhCon, a.getTextColor());
        SetConsoleOutputCP(CP_UTF8);
        cout << u8"      ▄▌▐▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▌";
        CursorPos(x, 11);
        cout << u8"   ▄▄██▌█               t r a n s - i n f o                     ▌";
        CursorPos(x, 12);
        cout << u8"▄▄▄▌▐██▌█                     welcome                           ▌";
        CursorPos(x, 13);
        cout << u8"███████▌█▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▌";
        CursorPos(x, 14);
        cout << u8"▀(@)▀▀▀▀▀▀▀(@)(@)▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀(@)▀   ";
        SetConsoleOutputCP(1251);
        x = 105, y = 20;
        CursorPos(x, y);
        for (char i = 0; i < size(T); i++)
        {
            int siz = T[i].size();
            const int siz_max = 15;
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
            cout << u8"╔═══════════════╗";
            CursorPos(x, y++);
            cout << u8"║";
            SetConsoleOutputCP(1251);
            cout << probel << T[i] << probel;
            SetConsoleOutputCP(CP_UTF8);
            cout << u8"║" << endl;
            CursorPos(x, y++);
            SetConsoleOutputCP(CP_UTF8);
            cout << u8"╚═══════════════╝"; 
        }
        c = _getch();
        if (c == -32) c = _getch();
        switch (c)
        {
        case ESC:
            system("cls");
            exit(0);
        case 9:
            system("start Rick_Roll.exe");
            break;
        case 'R':
        case 'r':
        case 'к':
        case 'К':
            ShellExecute(0, L"open", L"https://jut.su/re-zerou-kara/", NULL, NULL, SW_SHOWDEFAULT); //https://x.com/kosmoplay/status/1802087974555058587?t=fR6XFzLP_PHpivZ20DXOZA&s=19
            break;
        case 'z':
        case 'Z':
        case 'Я':
        case 'я':
            ShellExecute(0, L"open", L"https://pin.it/YmoTbgkG3", NULL, NULL, SW_SHOWDEFAULT); 
            break;
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
                user.Inter();
                break;
            }
            case 1:
            {
                system("CLS");
                user.registration();
                break;
            }
            case 2:
            {
                system("CLS");
                user.InterByAdmin();
                break;
            }
            case 3:
            {
                system("cls");
                options();
                break;
            }
            case 4:
            {
                system("cls");
                Rukovodstvo();
                break;
            }
            case 5:
            {
                system("cls");
                MenuColorSet();
                break;
            }
            case 6:
            {
                system("cls");
                exit(0);
            }
            default:
                cout << "" << (char)c << endl;
            }
        }
    }
}

void menuAdmin() {
    Admin admin;
    Color a;
    system("cls");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    string T[] = { "Добавить в коталог", "Убрать из коталога", "Каталог ","Изменить перевозки", "->", "Выход" };
    char aT = 0;
    char c;
    Ramka();
    for (int i = 0; i < 4; i++) {
        CursorPos(25, i); cout << u8"█";
    }
    CursorPos(0, 4);
    for (int i = 0; i < 26; i++) {
        if (i == 0 || i == 25) cout << u8"█";
        else
            cout << u8"▄";
    }
    SetConsoleOutputCP(1251);
    CursorPos(1, 2);
    cout << "Нажмите Esc чтобы выйти";
    while (true)
    {
        char x = 80, y = 10;
        CursorPos(x, y);
        SetConsoleTextAttribute(hhCon, a.getTextColor());
        SetConsoleOutputCP(CP_UTF8);
        cout << u8"      ▄▌▐▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▌";
        CursorPos(x, 11);
        cout << u8"   ▄▄██▌█                t r a n s - i n f o                    ▌";
        CursorPos(x, 12);
        cout << u8"▄▄▄▌▐██▌█                        1 / 2                          ▌";
        CursorPos(x, 13);
        cout << u8"███████▌█▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▌";
        CursorPos(x, 14);
        cout << u8"▀(@)▀▀▀▀▀▀▀(@)(@)▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀(@)▀   ";
        SetConsoleOutputCP(1251);
        CursorPos(100, 16);
        cout << "---| Работа с катологом |---";
        x = 97, y = 18;
        CursorPos(x, y);
        for (char i = 0; i < size(T); i++)
        {
            int siz = T[i].size();
            const int siz_max = 32;
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
            cout << u8"╔════════════════════════════════╗";
            CursorPos(x, y++);
            cout << u8"║";
            SetConsoleOutputCP(1251);
            if (n==13) cout << probel << T[i] << probel << " ";
            else if (n == 27) cout << probel << T[i] << probel << " ";
            else if (n == 11) cout << probel << T[i] << probel << " ";
            else if (n == 7) cout << probel << T[i] << probel << " ";
            else
                cout << probel << T[i] << probel;
            SetConsoleOutputCP(CP_UTF8);
            cout << u8"║" << endl;
            CursorPos(x, y++);
            SetConsoleOutputCP(CP_UTF8);
            cout << u8"╚════════════════════════════════╝";
            SetConsoleTextAttribute(hhCon, a.getTextColor());
        }
        c = _getch();
        if (c == -32) c = _getch();
        switch (c)
        {
        case ESC:
            system("cls");
            exit(0);
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
        case RIGHT:
        case 'd':
        case 'D':
        case 'в':
        case 'В':
            menuAdmin2();
            break;
        case ENTER:
            switch (aT)
            {
            case 0:
            {
                system("cls");
                admin.InterToCatalog();
                break;
            }
            case 1:
            {
                system("CLS");
                admin.DeleteFromCatalog();
                break;
            }
            case 2:
            {
                system("CLS");
                admin.Catalog();
                break;
            }
            case 3:
            {
                system("CLS");
                admin.ChangeZak();
                break;
            }
            case 4:
            {
                system("CLS");
                menuAdmin2();
                break;
            }
            case 5:
            {
                system("CLS");
                menu();
                break;
            }
            default:
                cout << "" << (char)c << endl;
            }
        }
    }
}

void menuAdmin2() {
    Admin admin;
    Color a;
    system("cls");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    string T[] = { "База данных пользователей", "Узнать информацию о пользователе", "Добавить пользователя", "Удалить пользвателя", "Сменить имя ", "Сменить пароль", "Сменить номер ", "<-"};
    char aT = 0;
    char c;
    Ramka();
    for (int i = 0; i < 4; i++) {
        CursorPos(25, i); cout << u8"█";
    }
    CursorPos(0, 4);
    for (int i = 0; i < 26; i++) {
        if (i == 0 || i == 25) cout << u8"█";
        else
            cout << u8"▄";
    }
    SetConsoleOutputCP(1251);
    CursorPos(1, 2);
    cout << "Нажмите Esc чтобы выйти";
    while (true)
    {
        char x = 80, y = 10;
        CursorPos(x, y);
        SetConsoleTextAttribute(hhCon, a.getTextColor());
        SetConsoleOutputCP(CP_UTF8);
        cout << u8"      ▄▌▐▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▌";
        CursorPos(x, 11);
        cout << u8"   ▄▄██▌█                t r a n s - i n f o                    ▌";
        CursorPos(x, 12);
        cout << u8"▄▄▄▌▐██▌█                        2 / 2                          ▌";
        CursorPos(x, 13);
        cout << u8"███████▌█▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▌";
        CursorPos(x, 14);
        cout << u8"▀(@)▀▀▀▀▀▀▀(@)(@)▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀(@)▀   ";
        SetConsoleOutputCP(1251);
        CursorPos(100, 16);
        cout << "---| Работа с пользователями |---";
        x = 100, y = 18;
        CursorPos(x, y);
        for (char i = 0; i < size(T); i++)
        {
            int siz = T[i].size();
            const int siz_max = 32;
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
            cout << u8"╔════════════════════════════════╗";
            CursorPos(x, y++);
            cout << u8"║";
            SetConsoleOutputCP(1251);
            if (n == 13) cout << probel << T[i] << probel << " ";
            else if (n == 27) cout << probel << T[i] << probel << " ";
            else if (n == 11) cout << probel << T[i] << probel << " ";
            else if (n == 7) cout << probel << T[i] << probel << " ";
            else
                cout << probel << T[i] << probel;
            SetConsoleOutputCP(CP_UTF8);
            cout << u8"║" << endl;
            CursorPos(x, y++);
            SetConsoleOutputCP(CP_UTF8);
            cout << u8"╚════════════════════════════════╝";
            SetConsoleTextAttribute(hhCon, a.getTextColor());
        }
        c = _getch();
        if (c == -32) c = _getch();
        switch (c)
        {
        case ESC:
            system("cls");
            exit(0);
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
        case LEFT:
        case 'a':
        case 'A':
        case 'Ф':
        case 'ф':
            menuAdmin();
            break;
        case ENTER:
            switch (aT)
            {
            case 0:
            {
                system("cls");
                admin.UserBaseDan();
                break;
            }
            case 1:
            {
                system("CLS");
                admin.UserInformation();
                break;
            }
            case 2:
            {
                system("CLS");
                admin.AddUser();
                break;
            }
            case 3:
            {
                system("CLS");
                admin.DeleteUser();
                break;
            }
            case 4:
            {
                system("CLS");
                admin.ChangeName();
                break;
            }
            case 5:
            {
                system("cls");
                admin.ChangePassword();
                break;
            }
            case 6:
                system("cls");
                admin.ChangeNum();
                break;
            case 7:
            {
                system("cls");
                menuAdmin();
                break;
            }
            default:
                cout << "" << (char)c << endl;
            }
        }
    }
}

void menuPolz(string name) {
    system("cls");
    User user(name);
    Color a;
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    string T[] = { "Перевозки (просмотр)", "Добавить перевозку", "Личный кабинет", "Поиск (номер) ", "Поиск ", "->"};
    char aT = 0;
    char c;
    Ramka();
    for (int i = 0; i < 4; i++) {
        CursorPos(25, i); cout << u8"█";
    }
    CursorPos(0, 4);
    for (int i = 0; i < 26; i++) {
        if (i == 0 || i == 25) cout << u8"█";
        else
            cout << u8"▄";
    }
    SetConsoleOutputCP(1251);
    CursorPos(1, 2);
    cout << "Нажмите Esc чтобы выйти";
    while (true)
    {
        char x = 80, y = 10;
        CursorPos(x, y);
        SetConsoleTextAttribute(hhCon, a.getTextColor());
        SetConsoleOutputCP(CP_UTF8);
        cout << u8"      ▄▌▐▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▌";
        CursorPos(x, 11);
        cout << u8"   ▄▄██▌█                t r a n s - i n f o                    ▌";
        CursorPos(x, 12);
        cout << u8"▄▄▄▌▐██▌█                         1/2                           ▌";
        CursorPos(x, 13);
        cout << u8"███████▌█▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▌";
        CursorPos(x, 14);
        cout << u8"▀(@)▀▀▀▀▀▀▀(@)(@)▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀(@)▀   ";
        SetConsoleOutputCP(1251);
        CursorPos(100, 16);
        cout << "---|Приветствую " << name << "|---";
        x = 100, y = 18;
        CursorPos(x, y);
        for (char i = 0; i < size(T); i++)
        {
            int siz = T[i].size();
            const int siz_max = 24;
            int n = siz_max - siz;
            int n2 = n / 2;
            string probel;
            if (n == 1) {
                probel = " ";
            }
            else
            for (int j = 0; j < n2; j++) probel += " ";
            if (i == aT) SetConsoleTextAttribute(hhCon, a.getInputColor1());
            else SetConsoleTextAttribute(hhCon, a.getTextColor());
            CursorPos(x, y++);
            cout << endl;
            CursorPos(x, y++);
            SetConsoleOutputCP(CP_UTF8);
            cout << u8"╔════════════════════════╗";
            CursorPos(x, y++);
            cout << u8"║";
            SetConsoleOutputCP(1251);
            if (n == 1) cout << T[i] << probel;
            else if (n == 3) cout << probel << T[i] << probel << " ";
            else
            cout << probel << T[i] << probel;
            SetConsoleOutputCP(CP_UTF8);
            cout << u8"║" << endl;
            CursorPos(x, y++);
            SetConsoleOutputCP(CP_UTF8);
            cout << u8"╚════════════════════════╝";
            SetConsoleTextAttribute(hhCon, a.getTextColor());
        }
        c = _getch();
        if (c == -32) c = _getch();
        switch (c)
        {
        case ESC:
            system("cls");
            exit(0);
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
        case RIGHT:
        case 'd':
        case 'D':
        case 'в':
        case 'В':
            menuPolz2(name);
            break;
        case ENTER:
            switch (aT)
            {
            case 0:
            {
                system("CLS");
                user.ViewCatalog();
                break;
            }
            case 1:
            {
                system("CLS");
                user.MakeOrder();
                break;
            }
            case 2:
            {
                system("CLS");
                user.MyInf();
                break;
            }
            case 3:
            {
                system("CLS");
                user.SearchNum();
                break;
            }
            case 4:
            {
                system("CLS");
                user.Search();
                break;
            }
            case 5:
            {
                menuPolz2(name);
            }
            default:
                cout << "" << (char)c << endl;
            }
        }
    }
}

void menuPolz2(string name) {
    system("cls");
    User user(name);
    Color a;
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    string T[] = { "Смена цвета ", "Руководство ", "<-", "Главное меню"};
    char aT = 0;
    char c;
    Ramka();
    for (int i = 0; i < 4; i++) {
        CursorPos(25, i); cout << u8"█";
    }
    CursorPos(0, 4);
    for (int i = 0; i < 26; i++) {
        if (i == 0 || i == 25) cout << u8"█";
        else
            cout << u8"▄";
    }
    SetConsoleOutputCP(1251);
    CursorPos(1, 2);
    cout << "Нажмите Esc чтобы выйти";
    while (true)
    {
        char x = 80, y = 10;
        CursorPos(x, y);
        SetConsoleTextAttribute(hhCon, a.getTextColor());
        SetConsoleOutputCP(CP_UTF8);
        cout << u8"      ▄▌▐▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▌";
        CursorPos(x, 11);
        cout << u8"   ▄▄██▌█                t r a n s - i n f o                    ▌";
        CursorPos(x, 12);
        cout << u8"▄▄▄▌▐██▌█                         2/2                           ▌";
        CursorPos(x, 13);
        cout << u8"███████▌█▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▌";
        CursorPos(x, 14);
        cout << u8"▀(@)▀▀▀▀▀▀▀(@)(@)▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀(@)▀   ";
        SetConsoleOutputCP(1251);
        CursorPos(100, 16);
        cout << "---|Приветствую " << name << "|---";
        x = 102, y = 18;
        CursorPos(x, y);
        for (char i = 0; i < size(T); i++)
        {
            int siz = T[i].size();
            const int siz_max = 20;
            int n = siz_max - siz;
            int n2 = n / 2;
            string probel;
            if (n == 1) {
                probel = " ";
            }
            else
                for (int j = 0; j < n2; j++) probel += " ";
            if (i == aT) SetConsoleTextAttribute(hhCon, a.getInputColor1());
            else SetConsoleTextAttribute(hhCon, a.getTextColor());
            CursorPos(x, y++);
            cout << endl;
            CursorPos(x, y++);
            SetConsoleOutputCP(CP_UTF8);
            cout << u8"╔════════════════════╗";
            CursorPos(x, y++);
            cout << u8"║";
            SetConsoleOutputCP(1251);
            if (n == 1) cout << T[i] << probel;
            else if (n == 3) cout << probel << T[i] << probel << " ";
            else
                cout << probel << T[i] << probel;
            SetConsoleOutputCP(CP_UTF8);
            cout << u8"║" << endl;
            CursorPos(x, y++);
            SetConsoleOutputCP(CP_UTF8);
            cout << u8"╚════════════════════╝";
            SetConsoleTextAttribute(hhCon, a.getTextColor());
        }
        c = _getch();
        if (c == -32) c = _getch();
        switch (c)
        {
        case ESC:
            system("cls");
            exit(0);
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
        case LEFT:
        case 'a':
        case 'A':
        case 'Ф':
        case 'ф':
            menuPolz(name);
            break;
        case ENTER:
            switch (aT)
            {
            case 0:
            {
                MenuColorSet();
                break;
            }
            case 1:
            {
                system("cls");
                Rukovodstvo();
                break;
            }
            case 2:
            {
                menuPolz(name);
                break;
            }
            case 3:
            {
                menu();
                break;
            }
            default:
                cout << "" << (char)c << endl;
            }
        }
    }
}

void options() {
    system("cls");
    Color a;
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    string T[] = { "Узнать о разработчике", "Связаться с разработчиком", "GitHub ", "Главное меню" };
    char aT = 0;
    char c;
    SetConsoleTextAttribute(hhCon, a.getTextColor());
    Ramka();
    for (int i = 0; i < 4; i++) {
        CursorPos(25, i); cout << u8"█";
    }
    CursorPos(0, 4);
    for (int i = 0; i < 26; i++) {
        if (i == 0 || i == 25) cout << u8"█";
        else
            cout << u8"▄";
    }
    SetConsoleOutputCP(1251);
    CursorPos(1, 2);
    cout << "Нажмите Esc чтобы выйти";
    while (true)
    {
        char x = 94, y = 20;
        CursorPos(x, y);
        for (char i = 0; i < size(T); i++)
        {
            int siz = T[i].size();
            const int siz_max = 25;
            int n = siz_max - siz;
            int n2 = n / 2;
            string probel;
            if (n == 1) {
                probel = " ";
            }
            else
                for (int j = 0; j < n2; j++) probel += " ";
            if (i == aT) SetConsoleTextAttribute(hhCon, a.getInputColor1());
            else SetConsoleTextAttribute(hhCon, a.getTextColor());
            CursorPos(x, y++);
            cout << endl;
            CursorPos(x, y++);
            SetConsoleOutputCP(CP_UTF8);
            cout << u8"╔═════════════════════════╗";
            CursorPos(x, y++);
            cout << u8"║";
            SetConsoleOutputCP(1251);
            if (n==3) cout << probel << T[i] << probel << " ";
            else if (n == 13) cout << probel << T[i] << probel << " ";
            else
            cout << probel << T[i] << probel;
            SetConsoleOutputCP(CP_UTF8);
            cout << u8"║" << endl;
            CursorPos(x, y++);
            SetConsoleOutputCP(CP_UTF8);
            cout << u8"╚═════════════════════════╝";
            SetConsoleTextAttribute(hhCon, a.getTextColor());
        }
        c = _getch();
        if (c == -32) c = _getch();
        switch (c)
        {
        case ESC:
            system("cls");
            Ramka();
            return;
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
                int n = MessageBox(0, L"Разработчик Картун Я.С 75 Мс", L"Прочее", MB_OK | MB_ICONINFORMATION);
                break;
            }
            case 1:
            {
                int n = MessageBox(0, L"Писать в телеграмм @motras_06", L"Прочее", MB_OKCANCEL | MB_ICONINFORMATION);
                switch (n)
                {
                case IDOK:
                    ShellExecute(0, L"open", L"https://t.me/motras_06", NULL, NULL, SW_SHOWDEFAULT);
                    break;
                case IDCANCEL:
                    break;
                }
                break;
            }
            case 2:
            {
                int n = MessageBox(0, L"Перейти на GitHub?", L"Прочее", MB_OKCANCEL | MB_ICONINFORMATION);
                switch (n)
                {
                case IDOK:
                    ShellExecute(0, L"open", L"https://github.com/Motras06", NULL, NULL, SW_SHOWDEFAULT);
                    break;
                case IDCANCEL:
                    break;
                }
                break;
            }
            case 3:
            {
                menu();
                break;
            }
            default:
                cout << "" << (char)c << endl;
            }
        }
    }
}

void MenuColorSet() {
    system("cls");
    Color a;
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    string T[] = { "Сменить цвет текста", "Сменить цвет выбора(1)", "Сменить цвет выбора(2)", "Назад" };
    char aT = 0;
    char c;
    SetConsoleTextAttribute(hhCon, a.getTextColor());
    Ramka();
    for (int i = 0; i < 4; i++) {
        CursorPos(25, i); cout << u8"█";
    }
    CursorPos(0, 4);
    for (int i = 0; i < 26; i++) {
        if (i == 0 || i == 25) cout << u8"█";
        else
            cout << u8"▄";
    }
    SetConsoleOutputCP(1251);
    CursorPos(1, 2);
    cout << "Нажмите Esc чтобы выйти";
    while (true)
    {
        char x = 94, y = 20;
        CursorPos(x, y);
        for (char i = 0; i < size(T); i++)
        {
            int siz = T[i].size();
            const int siz_max = 25;
            int n = siz_max - siz;
            int n2 = n / 2;
            string probel;
            if (n == 1) {
                probel = " ";
            }
            else
                for (int j = 0; j < n2; j++) probel += " ";
            if (i == aT) SetConsoleTextAttribute(hhCon, a.getInputColor1());
            else SetConsoleTextAttribute(hhCon, a.getTextColor());
            CursorPos(x, y++);
            cout << endl;
            CursorPos(x, y++);
            SetConsoleOutputCP(CP_UTF8);
            cout << u8"╔═════════════════════════╗";
            CursorPos(x, y++);
            cout << u8"║";
            SetConsoleOutputCP(1251);
            if (n == 3) cout << probel << T[i] << probel << " ";
            else if (n == 13) cout << probel << T[i] << probel << " ";
            else
                cout << probel << T[i] << probel;
            SetConsoleOutputCP(CP_UTF8);
            cout << u8"║" << endl;
            CursorPos(x, y++);
            SetConsoleOutputCP(CP_UTF8);
            cout << u8"╚═════════════════════════╝";
            SetConsoleTextAttribute(hhCon, a.getTextColor());
        }
        c = _getch();
        if (c == -32) c = _getch();
        switch (c)
        {
        case ESC:
            system("cls");
            Ramka();
            return;
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
                SetTextColor();
                break;
            }
            case 1:
            {
                system("cls");
                SetInputColor1();
                break;
            }
            case 2:
            {
                system("cls");
                SetInputColor2();
                break;
            }
            case 3:
            {
                system("cls");
                Ramka();
                return;
                break;
            }
            default:
                cout << "" << (char)c << endl;
            }
        }
    }
}

void Rukovodstvo() {
    Ramka();
    SetConsoleOutputCP(1251);
    CursorPos(10, 3);
    SleepMessagText("Руководсвто по пользованию:");
    CursorPos(10, 5);
    SleepMessagText("1.Не баловаться с разрешением окна, это способствует сбиванию отрисовки и работе некоторых функций;");
    CursorPos(10, 7);
    SleepMessagText("2.Как в меню админа, так и вменю пользователя можно пользоваться стрелочками для перемещения между страницами;");
    CursorPos(10, 9);
    SleepMessagText("3.Если вы случайно зашли в ту или иную функцию, то можно нажать клавишу Esc, которая вернёт вас обратно;");
    CursorPos(10, 11);
    SleepMessagText("4.Рекомендуеться не баловаться с функциями, а разумно их использовать (причина даже после тестировки некоторые баги могут быть не выявлены);");
    CursorPos(10, 13);
    SleepMessagText("5.Всё остальное можно будет найти в ПЗ к проекту;");
    Sleep(3000);
    MessageBox(NULL, L"Теперь вы ознакомлены с руководством", L"Записка", MB_OK);
    system("cls");
    Ramka();
}

void SetTextColor() {
    system("cls");
    Color a;
    int text, input1, input2;
    ifstream getcol("color.txt");
    getcol >> text;
    getcol >> input1;
    getcol >> input2;
    getcol.close();
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    string T[] = { "Синий", "Зелёный", "Аква ", "Желтый ", "Красный", "Белый", "Серый", "Меню " };
    char aT = 0;
    char c;
    SetConsoleTextAttribute(hhCon, a.getTextColor());
    Ramka();
    for (int i = 0; i < 4; i++) {
        CursorPos(25, i); cout << u8"█";
    }
    CursorPos(0, 4);
    for (int i = 0; i < 26; i++) {
        if (i == 0 || i == 25) cout << u8"█";
        else
            cout << u8"▄";
    }
    SetConsoleOutputCP(1251);
    CursorPos(1, 2);
    cout << "Нажмите Esc чтобы выйти";
    while (true)
    {
        char x = 94, y = 20;
        CursorPos(x, y);
        for (char i = 0; i < size(T); i++)
        {
            int siz = T[i].size();
            const int siz_max = 25;
            int n = siz_max - siz;
            int n2 = n / 2;
            string probel;
            if (n == 1) {
                probel = " ";
            }
            else
                for (int j = 0; j < n2; j++) probel += " ";
            if (i == aT) SetConsoleTextAttribute(hhCon, a.getInputColor1());
            else SetConsoleTextAttribute(hhCon, a.getTextColor());
            CursorPos(x, y++);
            cout << endl;
            CursorPos(x, y++);
            SetConsoleOutputCP(CP_UTF8);
            cout << u8"╔═════════════════════════╗";
            CursorPos(x, y++);
            cout << u8"║";
            SetConsoleOutputCP(1251);
            if (n == 3) cout << probel << T[i] << probel << " ";
            else if (n == 13) cout << probel << T[i] << probel << " ";
            else
                cout << probel << T[i] << probel;
            SetConsoleOutputCP(CP_UTF8);
            cout << u8"║" << endl;
            CursorPos(x, y++);
            SetConsoleOutputCP(CP_UTF8);
            cout << u8"╚═════════════════════════╝";
            SetConsoleTextAttribute(hhCon, a.getTextColor());
        }
        c = _getch();
        if (c == -32) c = _getch();
        switch (c)
        {
        case ESC:
            system("cls");
            Ramka();
            return;
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
                ofstream setcol("color.txt");
                if (input1!=9) text = 9;
                setcol << text << endl;
                setcol << input1 << endl;
                setcol << input2;
                setcol.close();
                a.Construct();
                break;
            }
            case 1:
            {
                ofstream setcol("color.txt");
                if (input1 != 10) text = 10;
                setcol << text << endl;
                setcol << input1 << endl;
                setcol << input2;
                setcol.close();
                a.Construct();
                break;
            }
            case 2:
            {
                ofstream setcol("color.txt");
                if (input1 != 11) text = 11;
                setcol << text << endl;
                setcol << input1 << endl;
                setcol << input2;
                setcol.close();
                a.Construct();
                break;
            }
            case 3:
            {
                ofstream setcol("color.txt");
                if (input1 != 14) text = 14;
                setcol << text << endl;
                setcol << input1 << endl;
                setcol << input2;
                setcol.close();
                a.Construct();
                break;
            }
            case 4:
            {
                ofstream setcol("color.txt");
                if (input1 != 12) text = 12;
                setcol << text << endl;
                setcol << input1 << endl;
                setcol << input2;
                setcol.close();
                a.Construct();
                break;
            }
            case 5:
            {
                ofstream setcol("color.txt");
                if (input1 != 15) text = 15;
                setcol << text << endl;
                setcol << input1 << endl;
                setcol << input2;
                setcol.close();
                a.Construct();
                break;
            }
            case 6:
            {
                ofstream setcol("color.txt");
                if (input1 != 8) text = 8;
                setcol << text << endl;
                setcol << input1 << endl;
                setcol << input2;
                setcol.close();
                a.Construct();
                break;
            }
            case 7:
            {
                system("cls");
                Ramka();
                return;
                break;
            }
            default:
                cout << "" << (char)c << endl;
            }
        }
    }
}

void SetInputColor1() {
    system("cls");
    Color a;
    int text, input1, input2;
    ifstream getcol("color.txt");
    getcol >> text;
    getcol >> input1;
    getcol >> input2;
    getcol.close();
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    string T[] = { "Синий", "Зелёный", "Аква ", "Желтый ", "Красный", "Меню "};
    char aT = 0;
    char c;
    SetConsoleTextAttribute(hhCon, a.getTextColor());
    Ramka();
    for (int i = 0; i < 4; i++) {
        CursorPos(25, i); cout << u8"█";
    }
    CursorPos(0, 4);
    for (int i = 0; i < 26; i++) {
        if (i == 0 || i == 25) cout << u8"█";
        else
            cout << u8"▄";
    }
    SetConsoleOutputCP(1251);
    CursorPos(1, 2);
    cout << "Нажмите Esc чтобы выйти";
    while (true)
    {
        char x = 94, y = 20;
        CursorPos(x, y);
        for (char i = 0; i < size(T); i++)
        {
            int siz = T[i].size();
            const int siz_max = 25;
            int n = siz_max - siz;
            int n2 = n / 2;
            string probel;
            if (n == 1) {
                probel = " ";
            }
            else
                for (int j = 0; j < n2; j++) probel += " ";
            if (i == aT) SetConsoleTextAttribute(hhCon, a.getInputColor1());
            else SetConsoleTextAttribute(hhCon, a.getTextColor());
            CursorPos(x, y++);
            cout << endl;
            CursorPos(x, y++);
            SetConsoleOutputCP(CP_UTF8);
            cout << u8"╔═════════════════════════╗";
            CursorPos(x, y++);
            cout << u8"║";
            SetConsoleOutputCP(1251);
            if (n == 3) cout << probel << T[i] << probel << " ";
            else if (n == 13) cout << probel << T[i] << probel << " ";
            else
                cout << probel << T[i] << probel;
            SetConsoleOutputCP(CP_UTF8);
            cout << u8"║" << endl;
            CursorPos(x, y++);
            SetConsoleOutputCP(CP_UTF8);
            cout << u8"╚═════════════════════════╝";
            SetConsoleTextAttribute(hhCon, a.getTextColor());
        }
        c = _getch();
        if (c == -32) c = _getch();
        switch (c)
        {
        case ESC:
            system("cls");
            Ramka();
            return;
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
                ofstream setcol("color.txt");
                if (text != 9) input1 = 9;
                setcol << text << endl;
                setcol << input1 << endl;
                setcol << input2;
                setcol.close();
                a.Construct();
                break;
            }
            case 1:
            {
                ofstream setcol("color.txt");
                if (text != 10) input1 = 10;
                setcol << text << endl;
                setcol << input1 << endl;
                setcol << input2;
                setcol.close();
                a.Construct();
                break;
            }
            case 2:
            {
                ofstream setcol("color.txt");
                if (text != 11) input1 = 11;
                setcol << text << endl;
                setcol << input1 << endl;
                setcol << input2;
                setcol.close();
                a.Construct();
                break;
            }
            case 3:
            {
                ofstream setcol("color.txt");
                if (text != 14) input1 = 14;
                setcol << text << endl;
                setcol << input1 << endl;
                setcol << input2;
                setcol.close();
                a.Construct();
                break;
            }
            case 4:
            {
                ofstream setcol("color.txt");
                if (text != 12) input1 = 12;
                setcol << text << endl;
                setcol << input1 << endl;
                setcol << input2;
                setcol.close();
                a.Construct();
                break;
            }
            case 5:
            {
                system("cls");
                Ramka();
                return;
                break;
            }
            default:
                cout << "" << (char)c << endl;
            }
        }
    }
}

void SetInputColor2() {
    system("cls");
    Color a;
    int text, input1, input2;
    ifstream getcol("color.txt");
    getcol >> text;
    getcol >> input1;
    getcol >> input2;
    getcol.close();
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    string T[] = { "Синий", "Зелёный", "Аква ", "Желтый ", "Красный", "Меню " };
    char aT = 0;
    char c;
    SetConsoleTextAttribute(hhCon, a.getTextColor());
    Ramka();
    for (int i = 0; i < 4; i++) {
        CursorPos(25, i); cout << u8"█";
    }
    CursorPos(0, 4);
    for (int i = 0; i < 26; i++) {
        if (i == 0 || i == 25) cout << u8"█";
        else
            cout << u8"▄";
    }
    SetConsoleOutputCP(1251);
    CursorPos(1, 2);
    cout << "Нажмите Esc чтобы выйти";
    while (true)
    {
        CursorPos(100, 16);
        SetConsoleOutputCP(1251);
        SetConsoleTextAttribute(hhCon, a.getInputColor2());
        cout << "~~Пример~~";
        SetConsoleTextAttribute(hhCon, a.getTextColor());
        char x = 94, y = 20;
        CursorPos(x, y);
        for (char i = 0; i < size(T); i++)
        {
            int siz = T[i].size();
            const int siz_max = 25;
            int n = siz_max - siz;
            int n2 = n / 2;
            string probel;
            if (n == 1) {
                probel = " ";
            }
            else
                for (int j = 0; j < n2; j++) probel += " ";
            if (i == aT) SetConsoleTextAttribute(hhCon, a.getInputColor1());
            else SetConsoleTextAttribute(hhCon, a.getTextColor());
            CursorPos(x, y++);
            cout << endl;
            CursorPos(x, y++);
            SetConsoleOutputCP(CP_UTF8);
            cout << u8"╔═════════════════════════╗";
            CursorPos(x, y++);
            cout << u8"║";
            SetConsoleOutputCP(1251);
            if (n == 3) cout << probel << T[i] << probel << " ";
            else if (n == 13) cout << probel << T[i] << probel << " ";
            else
                cout << probel << T[i] << probel;
            SetConsoleOutputCP(CP_UTF8);
            cout << u8"║" << endl;
            CursorPos(x, y++);
            SetConsoleOutputCP(CP_UTF8);
            cout << u8"╚═════════════════════════╝";
            SetConsoleTextAttribute(hhCon, a.getTextColor());
        }
        c = _getch();
        if (c == -32) c = _getch();
        switch (c)
        {
        case ESC:
            system("cls");
            Ramka();
            return;
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
                ofstream setcol("color.txt");
                input2 = 9;
                setcol << text << endl;
                setcol << input1 << endl;
                setcol << input2;
                setcol.close();
                a.Construct();
                break;
            }
            case 1:
            {
                ofstream setcol("color.txt");
                input2 = 10;
                setcol << text << endl;
                setcol << input1 << endl;
                setcol << input2;
                setcol.close();
                a.Construct();
                break;
            }
            case 2:
            {
                ofstream setcol("color.txt");
                input2 = 11;
                setcol << text << endl;
                setcol << input1 << endl;
                setcol << input2;
                setcol.close();
                a.Construct();
                break;
            }
            case 3:
            {
                ofstream setcol("color.txt");
                input2 = 14;
                setcol << text << endl;
                setcol << input1 << endl;
                setcol << input2;
                setcol.close();
                a.Construct();
                break;
            }
            case 4:
            {
                ofstream setcol("color.txt");
                input2 = 12;
                setcol << text << endl;
                setcol << input1 << endl;
                setcol << input2;
                setcol.close();
                a.Construct();
                break;
            }
            case 5:
            {
                system("cls");
                Ramka();
                return;
                break;
            }
            default:
                cout << "" << (char)c << endl;
            }
        }
    }
}

///~~~~Готово~~~~