#include <SDL.h>
#include <SDL_mixer.h>
#include <iostream>

bool loadMusic()
{
	//Loading success flag
	bool success = true; //if loading successful

    Mix_Music *bgMusic = NULL; //pointer of type mix_music declared and innitialized to null

	bgMusic = Mix_LoadMUS( "filename" ); 

	if(bgMusic == NULL)
    {
		printf("Unable to load music: %s \n", Mix_GetError());
		success = false;
	}
	return success;
}

bool loadCoin()
{
	//Loading success flag
	bool success = true;

    Mix_Coin *coin = NULL;

	coin = Mix_LoadCoin( "filename" );

	if(coin == NULL)
    {
		printf("Unable to load sound: %s \n", Mix_GetError());
		success = false;
	}
	return success;
}

bool loadDiamond()
{
	//Loading success flag
	bool success = true;

    Mix_Diamond *diamond = NULL;

	diamond = Mix_LoadDiamond( "filename" );

	if(diamond == NULL)
    {
		printf("Unable to load sound: %s \n", Mix_GetError());
		success = false;
	}
	return success;
}

bool initMixer()
{
    bool success = true;

    Mix_init(MIX_INIT_MP3);
    SDL_Init(SDL_INIT_AUDIO);

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
    Mix_FreeCoin(coin);
    coin = NULL;
    Mix_FreeDiamond(diamond);
    diamond = NULL;

    //quit SDL subsystems
    Mix_Quit();
}
