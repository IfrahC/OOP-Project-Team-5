#include "Audio.hpp"

Audio::Audio() : bgMusic(nullptr), coinSound(nullptr), diamondSound(nullptr) {} //constructor

Audio::~Audio() //dtor
{
    close();
}
bool Audio:: loadMusic(const char* filename)
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

bool Audio:: loadCoin(const char* filename)
{
	//Loading success flag
	bool success = true;

	Mix_Chunk *coin = NULL;

	coin = Mix_LoadCoin( "filename" );

	if(coin == NULL)
	{
		printf("Unable to load sound: %s \n", Mix_GetError());
		success = false;
	}
	return success;
}

bool Audio:: loadDiamond(const char* filename)
{
	//Loading success flag
	bool success = true;

	Mix_Chunk *diamond = NULL;

	diamond = Mix_LoadDiamond( "filename" );

	if(diamond == NULL)
	{
		printf("Unable to load sound: %s \n", Mix_GetError());
		success = false;
	}
	return success;
}

bool Audio:: initMixer()
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

void Audio:: close()
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
