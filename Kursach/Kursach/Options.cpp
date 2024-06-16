#include "User.h"

void deleteLine(string filename, int lineNumber) {
    ifstream file(filename);
    string line;
    vector<string> lines;
    while (getline(file, line)) {
        lines.push_back(line);
    }
    file.close();

    lines.erase(lines.begin() + lineNumber - 1);

    ofstream outFile(filename);
    int i = 0;
    for (string line : lines) {
        i++;
        if (i == lines.size()) outFile << line;
        else
        outFile << line << endl;
    }
    outFile.close();
}

void ShowConsoleCursor(bool showFlag)
{
    HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO     cursorInfo;
    GetConsoleCursorInfo(out, &cursorInfo);
    cursorInfo.bVisible = showFlag; // set the cursor visibility
    SetConsoleCursorInfo(out, &cursorInfo);
}

void Ramka() {
    Color a;
    SetConsoleTextAttribute(hhCon, a.getTextColor());
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    GetConsoleScreenBufferInfo(hhCon, &csbi);
    int width = csbi.srWindow.Right - csbi.srWindow.Left + 1;
    int height = csbi.srWindow.Bottom - csbi.srWindow.Top + 1;
    SetConsoleOutputCP(CP_UTF8);
    CursorPos(0, 0);
    for (int i = 0; i < width; i++) {
        if (i == 0 || i == width - 1) cout << u8"█";
        else
            cout << u8"▀";
    }
    for (int i = 1; i < height - 1; i++) {

        CursorPos(0, i); cout << u8"█";
        CursorPos(width - 1, i); cout << u8"█";
    }
    CursorPos(0, height - 1);
    for (int i = 0; i < width; i++) {
        if (i == 0 || i == width - 1) cout << u8"█";
        else
            cout << u8"▄";
    }
}

bool isInt(string str) {
    string bukvs = "0123456789";
    bool isNum;
    for (int i = 0; i < str.size(); i++) {
        isNum = false;
        for (int j = 0; j < bukvs.size(); j++) {
            if (str[i] == bukvs[j]) {
                isNum = true;
            }
        }
        if (!isNum) return false;
    }
    return true;
}

void start() {
    SetConsoleOutputCP(1251);
    char x = 85, y = 20;
    CursorPos(x, y);
    cout << "------------------------" << endl;
    y++;
    CursorPos(x, y);
    y++;
    cout << "" << endl;
    CursorPos(x, y);
    y++;
    cout << "o          O           o" << endl;
    CursorPos(x, y);
    y++;
    cout << "" << endl;
    CursorPos(x, y);
    y++;
    cout << "------------------------" << endl;
    CursorPos(x, y);
    cout << "Загрузка.";
    Sleep(200);
    system("cls");
    // /          —           \\
    //////////////////////////////////////////////////////////////////////////////////
    
    x = 85, y = 20;
    CursorPos(x, y);
    cout << "------------------------" << endl;
    y++;
    CursorPos(x, y);
    y++;
    cout << "" << endl;
    CursorPos(x, y);
    y++;
    cout << "o          o           O" << endl;
    CursorPos(x, y);
    y++;
    cout << "" << endl;
    CursorPos(x, y);
    y++;
    cout << "------------------------" << endl;
    CursorPos(x, y);
    cout << "Загрузка..";
    Sleep(200);
    system("cls");
    //////////////////////////////////////////////////////////////////////////////////
    
    x = 85, y = 20;
    CursorPos(x, y);
    cout << "------------------------" << endl;
    y++;
    CursorPos(x, y);
    y++;
    cout << "" << endl;
    CursorPos(x, y);
    y++;
    cout << "O          o           o" << endl;
    CursorPos(x, y);
    y++;
    cout << "" << endl;
    CursorPos(x, y);
    y++;
    cout << "------------------------" << endl;
    CursorPos(x, y);
    cout << "Загрузка...";
    Sleep(200);
    system("cls");
    //////////////////////////////////////////////////////////////////////////////////
    
    x = 85, y = 20;
    CursorPos(x, y);
    cout << "------------------------" << endl;
    y++;
    CursorPos(x, y);
    y++;
    cout << "" << endl;
    CursorPos(x, y);
    y++;
    cout << "o          O           o" << endl;
    CursorPos(x, y);
    y++;
    cout << "" << endl;
    CursorPos(x, y);
    y++;
    cout << "------------------------" << endl;
    CursorPos(x, y);
    cout << "Загрузка.";
    Sleep(200);
    system("cls");
    //////////////////////////////////////////////////////////////////////////////////
    
    x = 85, y = 20;
    CursorPos(x, y);
    cout << "------------------------" << endl;
    y++;
    CursorPos(x, y);
    y++;
    cout << "" << endl;
    CursorPos(x, y);
    y++;
    cout << "o          o           O" << endl;
    CursorPos(x, y);
    y++;
    cout << "" << endl;
    CursorPos(x, y);
    y++;
    cout << "------------------------" << endl;
    CursorPos(x, y);
    cout << "Загрузка..";
    Sleep(200);
    system("cls");
    //////////////////////////////////////////////////////////////////////////////////
    
    x = 85, y = 20;
    CursorPos(x, y);
    cout << "------------------------" << endl;
    y++;
    CursorPos(x, y);
    y++;
    cout << "" << endl;
    CursorPos(x, y);
    y++;
    cout << "O          o           o" << endl;
    CursorPos(x, y);
    y++;
    cout << "" << endl;
    CursorPos(x, y);
    y++;
    cout << "------------------------" << endl;
    CursorPos(x, y);
    cout << "Загрузка...";
    Sleep(200);
    system("cls");
    //////////////////////////////////////////////////////////////////////////////////
    
    x = 85, y = 20;
    CursorPos(x, y);
    cout << "------------------------" << endl;
    y++;
    CursorPos(x, y);
    y++;
    cout << "" << endl;
    CursorPos(x, y);
    y++;
    cout << "o          O           o" << endl;
    CursorPos(x, y);
    y++;
    cout << "" << endl;
    CursorPos(x, y);
    y++;
    cout << "------------------------" << endl;
    CursorPos(x, y);
    cout << "Загрузка.";
    Sleep(200);
    system("cls");
    //////////////////////////////////////////////////////////////////////////////////
    
    x = 85, y = 20;
    CursorPos(x, y);
    cout << "------------------------" << endl;
    y++;
    CursorPos(x, y);
    y++;
    cout << "" << endl;
    CursorPos(x, y);
    y++;
    cout << "o          o           O" << endl;
    CursorPos(x, y);
    y++;
    cout << "" << endl;
    CursorPos(x, y);
    y++;
    cout << "------------------------" << endl;
    CursorPos(x, y);
    cout << "Загрузка..";
    Sleep(200);
    system("cls");
    //////////////////////////////////////////////////////////////////////////////////
    
    x = 85, y = 20;
    CursorPos(x, y);
    cout << "------------------------" << endl;
    y++;
    CursorPos(x, y);
    y++;
    cout << "" << endl;
    CursorPos(x, y);
    y++;
    cout << "^-^        ^-^       ^-^" << endl;
    CursorPos(x, y);
    y++;
    cout << "" << endl;
    CursorPos(x, y);
    y++;
    cout << "------------------------" << endl;
    CursorPos(x, y);
    cout << "Загрузка...";
    Sleep(500);
    system("cls");
}