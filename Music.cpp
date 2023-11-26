#include "Music.hpp"
#include <cstdio>

Music::Music() : music(nullptr) {}

Music::~Music() {
    close();
}

bool Music::init() {
    if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0) {
        printf("SDL_mixer could not initialize! SDL_mixer Error: %s\n", Mix_GetError());
        return false;
    }

    return true;
}

bool Music::loadMusic(const char* path) { //loading music with the path provided
    music = Mix_LoadMUS(path);
    if (music == nullptr) {
        printf("Failed to load music: %s\n", Mix_GetError());
        return false;
    }

    return true;
}

void Music::play(int loops) { //deals with playin the music
    if (music != nullptr) {
        Mix_PlayMusic(music, loops);
    }
}

void Music::close() { //freeing
    if (music != nullptr) {
        Mix_FreeMusic(music);
        music = nullptr;
    }

    Mix_CloseAudio();
}
