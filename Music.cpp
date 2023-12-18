#include "Music.hpp"
#include <cstdio>

#include "Music.hpp"
#include <cstdio>

Music::Music() : backgroundMusic(nullptr) {}

Music::~Music()
{
    close();
}

bool Music::init()
{
    if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0)
    {
        printf("SDL_mixer could not initialize! SDL_mixer Error: %s\n", Mix_GetError());
        return false;
    }

    return true;
}

bool Music::loadBackgroundMusic(const char *path)
{
    backgroundMusic = Mix_LoadMUS(path);
    if (backgroundMusic == nullptr)
    {
        printf("Failed to load background music: %s\n", Mix_GetError());
        return false;
    }

    return true;
}

void Music::playBackgroundMusic(int loops)
{
    if (backgroundMusic != nullptr)
    {
        Mix_PlayMusic(backgroundMusic, loops);
    }
}

void Music::close()
{
    if (backgroundMusic != nullptr)
    {
        Mix_FreeMusic(backgroundMusic);
        backgroundMusic = nullptr;
    }

    Mix_CloseAudio();
}
