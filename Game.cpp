#include "Game.h"
#include "TextureManager.h"
#include "GameObject.h"
#include "Map.h"
//*********************** 宣告物件 ****************************
GameObject *player;
GameObject *enemy;
Map *map;
//************************************************************
SDL_Renderer *Game :: renderer = nullptr;

Game::Game(){
    
    Game::init("tank_war", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 750, 598, true);
    while(Game::running()){
        Game::handleEvents();
        Game::update();
        Game::render();
    }

    Game::clean();
}

Game::~Game(){

}

void Game::init(const char *title, int xpos, int ypos, int width, int height, bool fullscreen){


    //******************************** 啟動畫面設定 **********************************
    int flags = 0;
    if(fullscreen){
        flags = SDL_WINDOW_FULLSCREEN;
        //flags = SDL_WINDOW_OPENGL;
    }

    if(SDL_Init(SDL_INIT_EVERYTHING)==0){
        cout << "Subsystems Initialised!.." << endl;

        window = SDL_CreateWindow(title, xpos,ypos, width, height, flags);
        if(window){
            cout << "Window created!" << endl;
        }
        else {
            cout << "!Window failed created" << endl;
        }

        renderer = SDL_CreateRenderer(window,-1,SDL_RENDERER_ACCELERATED|SDL_RENDERER_TARGETTEXTURE);
        if(renderer){
            //SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
            cout << "Renderer created!" << endl;
        }
        else {
            cout << "!Renderer failed created" << endl;
        }

        isRunning = true;
    }
    else {
        isRunning = false;
        cout << "!Subsystems failed Initialised" << endl;
    }

    //*************************** 生成物件 *********************************

    player = new GameObject("image/tank.png", 600, 520);// ( 圖片路徑 , 生成視窗x,y位置 )
    enemy = new GameObject("image/tank1.png", 0, 0);
    map = new Map();

    //***********************************************************************
}

void Game::handleEvents(){

    //********************* 畫面關閉按鍵設置 ****************************
    SDL_Event event;
    SDL_PollEvent(&event);
    switch (event.type)
    {
    case SDL_QUIT:
        isRunning = false;
        break;
    case SDL_KEYDOWN:
        isRunning = false;
        break;
    default:
        break;
    }
}

void Game::update(){
    player->Update();
    enemy->Update();
    
}

void Game::render(){
    SDL_RenderClear(renderer);
    map->DrawMap();
    player->Render();
    enemy->Render();
    SDL_RenderPresent(renderer);
}

void Game::clean(){
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    SDL_Quit();
    cout << "Game Cleaned" << endl;
}


bool Game::running(){
    return isRunning;
}