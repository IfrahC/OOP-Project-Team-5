
#pragma once
#include <SDL.h>
#include <SDL_mixer.h>
#include <iostream>

class Music
{
public:
    Music();
    ~Music();

    bool init();
    bool loadBackgroundMusic(const char *path);

    void playBackgroundMusic(int loops);

    void close();

private:
    Mix_Music *backgroundMusic; // For background music
};
