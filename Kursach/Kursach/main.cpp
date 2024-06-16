#include "User.h"

int main() {
	SetConsoleTitle(L"Trans-Info");
	SetConsoleCP(1251);
	DisableF11();
	const int NotUsed = system("color 0f");
	UnwrapScreen();
	SendMessage(GetConsoleWindow(), WM_SYSKEYDOWN, VK_RETURN, 0x20000000);
	ShowConsoleCursor(false);
	system("CLS");
	start();
	menu();
}