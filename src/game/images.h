#pragma once
#include <SDL3/SDL.h>
#include "util.h"

namespace images
{
    extern SDL_Surface *alien_surface;
    extern SDL_Surface *alienf2_surface;
    extern SDL_Surface *bullet_surface;
    extern SDL_Surface *player_surface;
    extern SDL_Surface *playerf2_surface;
    extern SDL_Surface *zap1_surface;
    extern SDL_Surface *zap1f2_surface;
    extern SDL_Surface *zap2_surface;
    extern SDL_Surface *zap3_surface;

    extern SDL_FRect alien_src_rect;
    extern SDL_Texture *alien_texture;
    extern SDL_Texture *alienf2_texture;
    extern float alien_aspect;
    extern SDL_FRect bullet_src_rect;
    extern SDL_Texture *bullet_texture;
    extern float bullet_aspect;
    extern SDL_FRect player_src_rect;
    extern SDL_Texture *player_texture;
    extern SDL_Texture *playerf2_texture;
    extern float player_aspect;

    extern SDL_FRect zap_src_rect;
    extern SDL_Texture *zap1_texture;
    extern SDL_Texture *zap1f2_texture;
    extern SDL_Texture *zap2_texture;
    extern SDL_Texture *zap3_texture;

    void LoadImages(SDL_Renderer *renderer);
    void UnloadImages();
};