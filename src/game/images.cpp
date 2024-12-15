#include "images.h"
#include "assets/alien.h"
#include "assets/bullet.h"
#include "assets/player.h"

SDL_Surface *images::alien_surface = nullptr;
SDL_Surface *images::bullet_surface = nullptr;
SDL_Surface *images::player_surface = nullptr;

SDL_Texture *images::alien_texture = nullptr;
SDL_Texture *images::bullet_texture = nullptr;
SDL_Texture *images::player_texture = nullptr;

SDL_FRect *images::alien_src_rect = nullptr;
SDL_FRect *images::player_src_rect = nullptr;
SDL_FRect *images::bullet_src_rect = nullptr;

float *images::alien_aspect = nullptr;
float *images::bullet_aspect = nullptr;
float *images::player_aspect = nullptr;

void images::LoadImages(SDL_Renderer *renderer)
{
    // surfaces
    images::alien_surface = utils::loadEmbeddedBMP(renderer, alien_bmp, alien_bmp_len);
    images::bullet_surface = utils::loadEmbeddedBMP(renderer, bullet_bmp, bullet_bmp_len);
    images::player_surface = utils::loadEmbeddedBMP(renderer, player_bmp, player_bmp_len);

    // textures
    images::alien_texture = SDL_CreateTextureFromSurface(renderer, images::alien_surface);
    images::bullet_texture = SDL_CreateTextureFromSurface(renderer, images::bullet_surface);
    images::player_texture = SDL_CreateTextureFromSurface(renderer, images::player_surface);

    // setting up the src sizes;
    float w, h;

    SDL_GetTextureSize(images::alien_texture, &w, &h);
    SDL_FRect alien_src_rect{0, 0, w, h};
    float alien_aspect = w / h;
    images::alien_aspect = &alien_aspect;
    images::alien_src_rect = &alien_src_rect;

    SDL_GetTextureSize(images::player_texture, &w, &h);
    SDL_FRect player_src_rect{0, 0, w, h};
    float player_aspect = w / h;
    images::player_aspect = &player_aspect;
    images::player_src_rect = &player_src_rect;

    SDL_GetTextureSize(images::bullet_texture, &w, &h);
    SDL_FRect bullet_src_rect{0, 0, w, h};
    float bullet_aspect = w / h;
    images::bullet_aspect = &bullet_aspect;
    images::bullet_src_rect = &bullet_src_rect;
}

void images::UnloadImages()
{
    SDL_DestroySurface(images::alien_surface);
    SDL_DestroySurface(images::bullet_surface);
    SDL_DestroySurface(images::player_surface);

    SDL_DestroyTexture(images::alien_texture);
    SDL_DestroyTexture(images::bullet_texture);
    SDL_DestroyTexture(images::player_texture);
}