#ifndef AUDIO_HPP
#define AUDIO_HPP

#include <SDL.h>
#include <SDL_mixer.h>
#include <iostream>

class Audio {
public:
    Audio();
    ~Audio();

    bool loadMusic(const char* filename);
    bool loadCoin(const char* filename);
    bool loadDiamond(const char* filename);
    bool initMixer();
    void close();

private:
    Mix_Music* bgMusic;
    Mix_Chunk* coinSound;
    Mix_Chunk* diamondSound;
};
