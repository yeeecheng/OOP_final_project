#include "GameObject.h"
#include "TextureManager.h"

GameObject::GameObject(const char* texturesheet,int x,int y){

    
    objTexture = TextureManager::LoadTexture(texturesheet);

    xpos = x;
    ypos = y;
}

void GameObject::Update(){
    
    srcRect.h = 46;//原始圖片大小
    srcRect.w = 60;
    srcRect.x = 0;
    srcRect.y = 0;

    destRect.x = xpos;
    destRect.y = ypos;
    destRect.h = srcRect.h;//調整圖片大小
    destRect.w = srcRect.w;
}

void GameObject::Render(){
    SDL_RenderCopy(Game::renderer, objTexture, &srcRect, &destRect);
}