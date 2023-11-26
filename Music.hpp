#ifndef MUSIC_H
#define MUSIC_H
#include <SDL.h>
#include <SDL_mixer.h>

class Music {
public:
    Music(); //constructor
    ~Music(); //destructor

    bool init(); //initializer
    bool loadMusic(const char* path); //loading music
    void play(int loops); //playing music
    void close(); //closing music

private:
    Mix_Music* music;
};

#endif // MUSIC_H
