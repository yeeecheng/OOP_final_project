#include <iostream>
#include <conio.h>
#include "windowsFunction.h"
#include "player1.h"
using namespace std;

player1::player1(){
    movement();
}

void player1::movement(){//player1 movement 
    windowsFunction WF;
    int x = 1, y = 1;
    WF.gotoxy(x, y);
    cout << "�����";
    WF.gotoxy(x, y+1);
    cout << "������";
    WF.gotoxy(x, y+2);
    cout << "��  ��";
    bool gameEnd = false;
    while(!gameEnd){
        int input = getch();
        switch(input){
            case 119:
                WF.gotoxy(x, y);
                cout << " "<<" ";
                y--;
                WF.gotoxy(x, y );
                cout << "��>";
                break;
            case 115:
                WF.gotoxy(x, y);
                cout << " "<<" ";
                y++;
                WF.gotoxy(x, y);
                cout << "��>";
                break;
            case 97:
                WF.gotoxy(x, y);
                cout << " "<<" ";
                x--;
                WF.gotoxy(x, y);
                cout << "��>";
                break;
            case 100:
                WF.gotoxy(x , y);
                cout << " "<<" ";
                x++;
                WF.gotoxy(x, y);
                cout << "��>";
                break;
            case 96:
                gameEnd = true;
                break;
            default:
                break;
        }
    }
}
