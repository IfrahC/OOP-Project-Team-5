// texture.hpp
#ifndef TEXTURE_HPP
#define TEXTURE_HPP

#include <SDL.h>
#include <SDL_image.h>
#include <string>

class Texture
{
public:
    Texture();
    ~Texture();

    SDL_Texture *load(SDL_Renderer *renderer, const std::string &path);
    void destroy();

    SDL_Texture *texture;
};

#endif // TEXTURE_HPP
