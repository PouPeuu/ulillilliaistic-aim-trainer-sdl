#ifndef RENDER_HELPER_H
#define RENDER_HELPER_H

#include <SDL3/SDL.h>
#include <memory>

class RenderHelper {
    private:
        SDL_Renderer *renderer;
    public:
        RenderHelper(SDL_Renderer *sdl);

        void drawLine(float x1, float y1, float x2, float y2);

        //SDL_Renderer *getSDL();
};

#endif