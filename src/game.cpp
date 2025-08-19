#include "game.hpp"
#include <iostream>
#include <SDL3/SDL.h>
#include <cmath>

Game::Game(int screen_w, int screen_h):
screen_w(screen_w),
screen_h(screen_h),
player_speed(250) {}

void Game::update(double dt) {
    const bool* keyboard = SDL_GetKeyboardState(NULL);

    if (keyboard[SDL_SCANCODE_W]) {
        player_y -= player_speed * dt;
    }
    if (keyboard[SDL_SCANCODE_S]) {
        player_y += player_speed * dt;
    }
    if (keyboard[SDL_SCANCODE_A]) {
        player_x -= player_speed * dt;
    }
    if (keyboard[SDL_SCANCODE_D]) {
        player_x += player_speed * dt;
    }

    line_rot += sin(time_passed / 25 * M_PI) * 0.05 * dt;
    time_passed += dt;
}

void Game::draw(SDL_Renderer *renderer) {
    SDL_SetRenderDrawColor(renderer, 0x00, 0x00, 0x00, 0xff);
    SDL_RenderClear(renderer);

    //float line_size = screen_w > screen_h ? screen_h / 2 : screen_w / 2;
    float line_size = sqrt(screen_w*screen_w + screen_h*screen_h);
    SDL_SetRenderDrawColor(renderer, 0xff, 0xff, 0xff, 0xff);
    
    int n_lines = 200;
    for (int i = 0; i < n_lines; i++) {
        char sign = 2 * (i % 2) - 1;
        float angle = line_rot * ((float) (n_lines - i) / 4) * sign;
        SDL_RenderLine(renderer,
                (float) screen_w / 2 + cos(angle) * line_size,
                (float) screen_h / 2 + sin(angle) * line_size,
                (float) screen_w / 2 + cos(angle) * -line_size,
                (float) screen_h / 2 + sin(angle) * -line_size
        );
    }
    /*SDL_RenderLine(renderer,
        (float) screen_w / 2 + cosf(line_rot) * line_size,
        (float) screen_h / 2 + sinf(line_rot) * line_size,
        (float) screen_w / 2 + cosf(line_rot + M_PI) * line_size,
        (float) screen_h / 2 + sinf(line_rot + M_PI) * line_size
    );

    SDL_RenderLine(renderer,
        (float) screen_w / 2 + cosf(-line_rot * 0.75 + M_PI / 2) * line_size,
        (float) screen_h / 2 + sinf(-line_rot * 0.75 + M_PI / 2) * line_size,
        (float) screen_w / 2 + cosf(-line_rot * 0.75 + M_PI + M_PI / 2) * line_size,
        (float) screen_h / 2 + sinf(-line_rot * 0.75 + M_PI + M_PI / 2) * line_size
    );

    SDL_RenderLine(renderer,
        (float) screen_w / 2 + cosf(line_rot * 0.5) * line_size,
        (float) screen_h / 2 + sinf(line_rot * 0.5) * line_size,
        (float) screen_w / 2 + cosf(line_rot * 0.5 + M_PI) * line_size,
        (float) screen_h / 2 + sinf(line_rot * 0.5 + M_PI) * line_size
    );

    SDL_RenderLine(renderer,
        (float) screen_w / 2 + cosf(-line_rot * 0.25 + M_PI / 2) * line_size,
        (float) screen_h / 2 + sinf(-line_rot * 0.25 + M_PI / 2) * line_size,
        (float) screen_w / 2 + cosf(-line_rot * 0.25 + M_PI + M_PI / 2) * line_size,
        (float) screen_h / 2 + sinf(-line_rot * 0.25 + M_PI + M_PI / 2) * line_size
    );*/
}

void Game::setWindowSize(int screen_w, int screen_h) {
    this->screen_w = screen_w;
    this->screen_h = screen_h;
}
