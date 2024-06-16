#pragma once

#define _WIN32_WINNT 0x0500
#include <iostream>
#include <cmath>
#include <Windows.h>
#include <iomanip>
#include <vector>
#include <fstream>
#include <ctime>
#include <string>
#include <conio.h>
#include <cstdlib>
#include <stdio.h>
#include <algorithm>
#include <cstdio>
#define ESC 27
#define UP 72
#define DOWN 80
#define ENTER 13
#define LEFT 75
#define RIGHT 77
using namespace std;

const HANDLE hhCon = GetStdHandle(STD_OUTPUT_HANDLE);

void menuAdmin();
void menuAdmin2();
void menu();
void MenuColorSet();
void menuPolz(string name);
void menuPolz2(string name);
bool isInt(string str);
void deleteLine(string filename, int lineNumber);
void Ramka();
void Rukovodstvo();
void options();
void SetTextColor();
void SetInputColor1();
void SetInputColor2();
void start();

class User_vh {
private:
    string username;
    string password;
    string inf;
public:
    void registration();
    void Inter();
    void InterByAdmin();
    ~User_vh() {};
};

class User {
private:
    string filename;
    string username;
    string password;
    string inf;
public:
    User(string username_);
    void ChangePassword();
    void ChangeName();
    void ChangeNum();
    void ViewCatalog();
    void MakeOrder();
    void DeleteShipment();
    void MyOrder();
    void DeleteAkk();
    void Search(); 
    void SearchNum(); 
    void MyInf();
    //void Sort(); //TODO: make
};

class Admin {
public:
    void AddUser();
    void UserBaseDan();
    void UserInformation();
    void InterToCatalog();
    void DeleteFromCatalog();
    void DeleteUser();
    void Catalog();
    void ChangeName();
    void ChangePassword();
    void ChangeNum();
    void ChangeZak();
};

class Color {
private:
    int textcolor;
    int inputcolor1;
    int inputcolor2;
public:
    Color() {
        Construct();
    }
    void Construct() {
        ifstream colorset("color.txt");
        int text, inputyes, inputno;
        colorset >> text;
        colorset >> inputyes;
        colorset >> inputno;
        this->textcolor = text;
        this->inputcolor1 = inputyes;
        this->inputcolor2 = inputno;
        colorset.close();
    }
    int getTextColor() { return this->textcolor; }
    int getInputColor1() { return this->inputcolor1; }
    int getInputColor2() { return this->inputcolor2; }
};

static void SleepMessagYes(string text) {
    Color a;
    SetConsoleTextAttribute(hhCon, a.getInputColor1());
    for (int i = 0; i < size(text); i++) {
        Sleep(10);
        cout << text[i];
    }
    SetConsoleTextAttribute(hhCon, a.getTextColor());
}
static void SleepMessagNo(string text) {
    Color a;
    SetConsoleTextAttribute(hhCon, a.getInputColor2());
    for (int i = 0; i < size(text); i++) {
        Sleep(10);
        cout << text[i];
    }
    SetConsoleTextAttribute(hhCon, a.getTextColor());
}
static void SleepMessagText(string text) {
    Color a;
    SetConsoleTextAttribute(hhCon, a.getTextColor());
    for (int i = 0; i < size(text); i++) {
        Sleep(10);
        cout << text[i];
    }
}

static void UnwrapScreen()
{
    COORD NewSBSize;
    SMALL_RECT DisplayArea = { 0, 0, 0, 0 };
    NewSBSize = GetLargestConsoleWindowSize(hhCon);
    SetConsoleScreenBufferSize(hhCon, NewSBSize);
    DisplayArea.Right = NewSBSize.X - 1;
    DisplayArea.Bottom = NewSBSize.Y - 1;
    SetConsoleWindowInfo(hhCon, TRUE, &DisplayArea);
}

void ShowConsoleCursor(bool showFlag);

static void DisableF11() {
    DWORD prevMode;
    GetConsoleMode(hhCon, &prevMode);
    SetConsoleMode(hhCon, prevMode & (~ENABLE_PROCESSED_INPUT));
}

static void CursorPos(short x, short y)
{
    SetConsoleCursorPosition(hhCon, { x,y });
}

static void funk1() {
    cout << (char)8 << ' ' << char(8);
    cout << "*";
}

static void funk2(string word) {
    cout << (char)8 << ' ' << char(8);
    cout << word[word.size() - 1];
}