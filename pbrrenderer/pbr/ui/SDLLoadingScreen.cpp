/**
 * @file SDLLoadingScreen.cpp
 * @brief Defines a loading screen object using SDL2
 * @author D3PSI
 */
#ifndef SDL_LOADING_SCREEN_CPP
#define SDL_LOADING_SCREEN_CPP

#include "SDLLoadingScreen.hpp"
#include "../PBR.hpp"


SDLLoadingScreen::SDLLoadingScreen(const char* _image) {
    if(SDL_Init(SDL_INIT_EVERYTHING) < 0)
        std::string error = SDL_GetError();
    window = SDL_CreateWindow(
        pbr::TITLE,
        SDL_WINDOWPOS_UNDEFINED,
        SDL_WINDOWPOS_UNDEFINED,
        1216,
        614,
        SDL_WINDOW_ALLOW_HIGHDPI | SDL_WINDOW_BORDERLESS);
    renderer = SDL_CreateRenderer(
        window,
        -1,
        SDL_RENDERER_ACCELERATED);
    if(window == nullptr)
        std::string error = SDL_GetError();
    imageSurface = IMG_Load(_image);
    if(imageSurface == nullptr)
        std::string error = SDL_GetError();
    background = SDL_CreateTextureFromSurface(renderer, imageSurface);
    SDL_SetWindowIcon(window, imageSurface);
    std::thread t0(&SDLLoadingScreen::loop, this);
    t0.detach();
}

PBR_STATUS SDLLoadingScreen::loop() {
    SDL_Event e;
    while(!closeVar) {
        while(SDL_PollEvent(&e)) {
            if (e.type == SDL_QUIT) {
                closeMutex.lock();
                closeVar = true;
                closeMutex.unlock();
            }
        }
        SDL_RenderCopy(
            renderer,
            background,
            NULL,
            NULL);
        SDL_RenderPresent(renderer);
    }
    clean();
    return PBR_OK;
}

PBR_STATUS SDLLoadingScreen::close() {
    this->closeMutex.lock();
    this->closeVar = true;
    this->closeMutex.unlock();
    return PBR_OK;
}

PBR_STATUS SDLLoadingScreen::clean() {
    SDL_FreeSurface(imageSurface);
    SDL_DestroyTexture(background);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    IMG_Quit();
    SDL_Quit();
    return PBR_OK;
}

#endif      // SDL_LOADING_SCREEN_CPP