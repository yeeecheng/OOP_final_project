#include "Game.h"

class Map{
    public:
        Map();
        ~Map();

        void LoadMap(int arr[26][26]);
        void DrawMap();

    private:
        SDL_Rect src, dest;
        SDL_Texture * block;
        SDL_Texture * river;
        SDL_Texture * tile;

        int map[26][26];
};