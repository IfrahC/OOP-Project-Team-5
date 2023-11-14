#include <SDL.h>
#include <SDL_mixer.h>
#include <iostream>

bool loadMusic()
{
	//Loading success flag
	bool success = true;

    Mix_Music *bgMusic = NULL;

	bgMusic = Mix_LoadMUS( "filename" );

	if(bgMusic == NULL){
		printf("Unable to load music: %s \n", Mix_GetError());
		success = false;
	}
	return success;
}

bool initMixer()
{
    Mix_init(MIX_INIT_MP3);

    if( Mix_OpenAudio( 44100, MIX_DEFAULT_FORMAT, 2, 2048 ) < 0 )
    {
        printf( "SDL_mixer could not initialize! SDL_mixer Error: %s\n", Mix_GetError() );
        success = false;
    }
    return success;
}

void close()
{
    //destroy window
    Mix_FreeMusic(bgMusic);
	bgMusic = NULL;

    //quit SDL subsystems
    Mix_Quit();
}
