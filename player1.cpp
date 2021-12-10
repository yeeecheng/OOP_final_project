#include <iostream>
#include <conio.h>
#include "windowsFunction.h"
#include "player1.h"    
#include <windows.h>
using namespace std;


player1::player1(){
    playerX = 16, playerY = 16;
    initialPosition();
    player1Movement();
}

void player1::initialPosition()
{
    windowsFunction::gotoxy(playerX - 2, playerY + 1);
    cout << "��   �� ";
    windowsFunction::gotoxy(playerX - 2, playerY);
    cout << "�� ���� ";
    windowsFunction::gotoxy(playerX - 2, playerY - 1);
    cout << "�� ���� ";
}


void player1::player1Movement(){//player1 movement 

    bool gameEnd = false;
    while(!gameEnd){
        switch (input = getch())
        {
        case 119:
            windowsFunction::gotoxy(playerX - 2, playerY + 1);
            cout << "      ";
            windowsFunction::gotoxy(playerX - 2, playerY);
            cout << "��   �� ";
            windowsFunction::gotoxy(playerX - 2, playerY - 1);
            cout << "�� ���� ";
            windowsFunction::gotoxy(playerX - 2, playerY - 2);
            cout << "�� ���� ";
            playerY--;
            break;
        case 115:
            windowsFunction::gotoxy(playerX - 2, playerY - 1);
            cout << "      ";
            windowsFunction::gotoxy(playerX - 2, playerY);
            cout << "��   �� ";
            windowsFunction::gotoxy(playerX - 2, playerY + 1);
            cout << "�� ���� ";
            windowsFunction::gotoxy(playerX - 2, playerY + 2);
            cout << "�� ���� ";
            playerY++;
            break;
        case 97:
            windowsFunction::gotoxy(playerX - 4, playerY - 1);
            cout << "�� �� ��   ";
            windowsFunction::gotoxy(playerX - 4, playerY);
            cout << "�ס�    ";
            windowsFunction::gotoxy(playerX - 4, playerY + 1);
            cout << "�� �� ��   ";
            playerX-=2;
            break;
        case 100:
            windowsFunction::gotoxy(playerX - 2, playerY - 1);
            cout << "  �� �� �� ";
            windowsFunction::gotoxy(playerX - 2, playerY);
            cout << "    ����";
            windowsFunction::gotoxy(playerX - 2, playerY + 1);
            cout << "  �� �� �� ";
            playerX+=2;
            break;
        case 96:// ~
            gameEnd = true;
            break;
        default:
            break;
        }
    }
}
