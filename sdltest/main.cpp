//
//  main.cpp
//  test
//
//  Created by Alan on 2019/6/13.
//  Copyright © 2019年 Alan. All rights reserved.
//
#include <iostream>
#include <SDL.h>
#include <SDL_image.h>

using namespace std;

#define bool int
#define false 0
#define true (!false)

int main(int argc,char* argv[]){
    bool quit = true;
    SDL_Event sdl_event;
    //SDL初始化
    SDL_Init(SDL_INIT_EVERYTHING);
    //初始化图片层
    IMG_Init(IMG_INIT_JPG);
    //初始化SDL窗口
    SDL_Window* window = SDL_CreateWindow("simple SDL Window", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 800, 800,SDL_WINDOW_SHOWN);
    SDL_Renderer* render = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    
    SDL_RenderClear(render);
    
    SDL_Surface* image = IMG_Load("/Users/alan/sdltest/sdltest/image/DNF.png");
    
    if (image == NULL) {
        cout<<"image is null"<<endl;
    }
    
    SDL_Rect box,walk[8];
    
    box.x = 0;
    box.y = 100;
    box.h = image->h;
    box.w = image->w / 8;
    for (int i = 0; i < 8; i++) {
        walk[i].w = image->w /8;
        walk[i].h = image->h;
        walk[i].x = i*walk[i].w;
        walk[i].y = 0;
    }
    
    SDL_Texture* texture = SDL_CreateTextureFromSurface(render, image);
    
    int i = 0;
    while (quit) {
        SDL_WaitEvent(&sdl_event);
        
        switch (sdl_event.type) {
            case SDL_QUIT:
                quit = false;
                break;
            default:
                cout<<i<<endl;
                break;
        }
        
        SDL_RenderClear(render);
        SDL_RenderCopy(render, texture, &walk[i], &box);
        i = (i+1)%8;
        box.x = (box.x+10)%(box.w*8);
        SDL_RenderPresent(render);
        SDL_Delay(90);
    }
    //清除资源
    SDL_DestroyTexture(texture);
    SDL_FreeSurface(image);
    SDL_DestroyRenderer(render);
    SDL_DestroyWindow(window);
    
    cout<<"jieshu"<<endl;
    IMG_Quit();
    SDL_Quit();
    return 0;
}

