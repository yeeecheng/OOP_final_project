#ifndef WINDOWSFUNCTION_H
#define WINDOWSFUNCTION_H

class windowsFunction{
    public:
        windowsFunction();
        void gotoxy(int = 0, int = 0);
        void setColor(int = 1);
    private:
        void full_screen();
};
#endif