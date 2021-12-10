#include "windowsFunction.h"
#include <windows.h>
#include <iostream>
using namespace std;

windowsFunction::windowsFunction(){
    full_screen();
}

void windowsFunction::gotoxy(int xpos, int ypos)//change the pointer position 
{
    COORD scrn;
    HANDLE hOuput = GetStdHandle(STD_OUTPUT_HANDLE);
    scrn.X = xpos; scrn.Y = ypos;
    SetConsoleCursorPosition(hOuput,scrn);
}

void windowsFunction::setColor(int color)//change  color of something 
{
    HANDLE hConsole;
    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole,color);
}

void windowsFunction::full_screen(){
    HWND hwnd = GetForegroundWindow();//full_screen
    int cx = GetSystemMetrics(SM_CXSCREEN);
    int cy = GetSystemMetrics(SM_CXSCREEN);

    LONG l_WinStyle = GetWindowLong(hwnd, GWL_STYLE);
    SetWindowLong(hwnd, GWL_STYLE, (l_WinStyle | WS_POPUP | WS_MAXIMIZE) & ~WS_CAPTION & ~WS_THICKFRAME & ~WS_BORDER);

    SetWindowPos(hwnd, HWND_TOP, 0, 0, cx, cy, 0);
}