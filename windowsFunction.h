#ifndef WINDOWSFUNCTION_H
#define WINDOWSFUNCTION_H

class windowsFunction{
    friend class player1;

public:
    windowsFunction();

private:
    static void gotoxy(int = 0, int = 0);
    static void setColor(int = 1);
    void full_screen();
};
#endif