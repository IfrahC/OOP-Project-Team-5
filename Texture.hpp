// texture.hpp
#ifndef TEXTURE_H
#define TEXTURE_H

#include "include/SDL2/SDL.h"
#include "include/SDL2/SDL_image.h"
#include <string>

class Texture {
public:
    Texture();
    ~Texture();

    SDL_Texture* load(SDL_Renderer* renderer, const std::string& path);
    void destroy();

    SDL_Texture* texture;
};

#endif // TEXTURE_H

