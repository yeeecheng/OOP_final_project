#ifndef PLAYER1_H
#define PLAYER1_H


class player1{
    public:
        player1();
    private:
        void initialPosition();
        void player1Movement();
        int input;
        int playerX;
        int playerY;
};

#endif