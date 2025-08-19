#ifndef GAME_H
#define GAME_H

#include <SDL3/SDL.h>

class Game {
    private:
        int screen_w, screen_h;
        float player_x, player_y, player_speed;
        double line_rot;
        double time_passed;
    public:
        Game(int screen_w, int screen_h);

        void update(double dt);
        void draw(SDL_Renderer *renderer);
        void setWindowSize(int screen_w, int screen_h);
};

#endif