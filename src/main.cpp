#include <SDL3/SDL.h>
#include <SDL3_image/SDL_image.h>
#include <SDL3_ttf/SDL_ttf.h>
#include <string>
#include <memory>
#include <iostream>

#include "game.hpp"

SDL_Window *window = nullptr;
SDL_Renderer *renderer = nullptr;

bool running = true;

void handleEvent(SDL_Event event, std::unique_ptr<Game> &game) {
    switch (event.type)
    {
    case SDL_EVENT_KEY_DOWN:
        switch(event.key.key){
            case SDLK_ESCAPE:
                running = false;
                break;
            case SDLK_F11:
                if (SDL_GetWindowFlags(window) & SDL_WINDOW_FULLSCREEN != 0) {
                    SDL_SetWindowFullscreen(window, false);
                } else {
                    SDL_SetWindowFullscreen(window, true);
                }
                break;
        }
        break;
    case SDL_EVENT_WINDOW_CLOSE_REQUESTED:
        running = false;
        break;
    case SDL_EVENT_WINDOW_RESIZED:
        game->setWindowSize(event.display.data1, event.display.data2);
        break;
    default:
        break;
    }
}

int main(int argc, char *argv[]) {
    SDL_Log("FUCK YOU WORLD\n");
    SDL_Init(SDL_INIT_VIDEO);
    TTF_Init();

    int window_width = 800;
    int window_height = 600;

    if (!SDL_CreateWindowAndRenderer("SiduliKolme", window_width, window_height, 0, &window, &renderer)) {
        SDL_Log("Failed to create window / renderer: %s", SDL_GetError());
        return SDL_APP_FAILURE;
    }
    SDL_SetWindowResizable(window, true);

    TTF_Font *font = TTF_OpenFont("res/AdwaitaMonoNerdFont-Regular.ttf", 24);
    if (!font) {
        SDL_Log("Failed to load font: %s", SDL_GetError());
        return SDL_APP_FAILURE;
    }

    SDL_StartTextInput(window);

    std::unique_ptr<Game> game = std::make_unique<Game>(window_width, window_height);

    std::cout << "Starting game loop\n";
    Uint64 previous_time = SDL_GetTicksNS();
    while (running) {
        SDL_Event event;
        while (SDL_PollEvent(&event)) {
            handleEvent(event, game);
        }

        Uint64 current_time = SDL_GetTicksNS();
        double dt = (double)(current_time - previous_time) / 1000000000;
        previous_time = current_time;

        game->update(dt);
        game->draw(renderer);

        SDL_RenderPresent(renderer);
    }

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
}
