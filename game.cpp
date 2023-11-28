// game.cpp
#pragma once
#include <iostream>
#include <string>
#include <SDL.h>

#include "game.hpp"
#include "Level.hpp"
#include <iostream>

#include "Player.hpp"

Game::~Game(){ // game class destructor
close();
}

bool Game::init()
{
	// Initialization flag
	std::cout<<"init";
	bool success = true;

	// Initialize SDL
	if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_EVENTS | SDL_INIT_TIMER) < 0)
	{
		printf("SDL could not initialize! SDL Error: %s\n", SDL_GetError());
		success = false;
	}
	else
	{
		// Set texture filtering to linear
		if (!SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "1"))
		{
			printf("Warning: Linear texture filtering not enabled!");
		}

		// Create window
		gWindow = SDL_CreateWindow("Maze Escape", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
		if (gWindow == NULL)
		{
			printf("Window could not be created! SDL Error: %s\n", SDL_GetError());
			success = false;
		}
		else
		{
			// Create renderer for window
			gRenderer = SDL_CreateRenderer(gWindow, -1, SDL_RENDERER_ACCELERATED);
			if (gRenderer == NULL)
			{
				printf("Renderer could not be created! SDL Error: %s\n", SDL_GetError());
				success = false;
			}
			else
			{
				// Initialize renderer color
				
                SDL_SetRenderDrawColor(gRenderer, 0xFF, 0xFF, 0xFF, 0xFF);
				// Initialize PNG loading
				int imgFlags = IMG_INIT_PNG;
				if (!(IMG_Init(imgFlags) & imgFlags))
				{
					printf("SDL_image could not initialize! SDL_image Error: %s\n", IMG_GetError());
					success = false;
				}

               
			}
		}
	}

	return success;
}

bool Game::loadMedia()
{
   //loading all the media (images,sound)

	  titleTexture.texture=titleTexture.load(gRenderer, "forestfrenxy.png");
    if (titleTexture.texture == nullptr) {
        std::cerr << "Failed to create texture from title image!" << std::endl;
        return false;
    }

    mazebgTexture.texture=mazebgTexture.load(gRenderer, "soil.png");
    if (mazebgTexture.texture== nullptr) {
        std::cerr << "Failed to create texture from maze background image!" << std::endl;
        return false;
    }
	boy.texture=boy.load(gRenderer, "boy.png");
    if (boy.texture== nullptr) {
        std::cerr << "Failed to create texture from maze background image!" << std::endl;
        return false;
    }
	girl.texture=girl.load(gRenderer, "girl.png");
    if (girl.texture== nullptr) {
        std::cerr << "Failed to create texture from maze background image!" << std::endl;
        return false;
    }
	selectplayer.texture=selectplayer.load(gRenderer, "characterselect.jpeg");
    if (selectplayer.texture== nullptr) {
        std::cerr << "Failed to create texture from maze background image!" << std::endl;
        return false;
    }
	selectlevel.texture=selectlevel.load(gRenderer, "Level select.png");
    if (selectplayer.texture== nullptr) {
        std::cerr << "Failed to create texture from maze background image!" << std::endl;
        return false;
    }
	scoredisplay.texture=selectlevel.load(gRenderer, "scoredisplay.jpg");
    if (selectplayer.texture== nullptr) {
        std::cerr << "Failed to create texture from maze background image!" << std::endl;
        return false;
    }
	if (!backgroundMusic.init()) {
    std::cerr << "Failed to initialize music. Exiting." << std::endl;
    return false;
    }

    if (!backgroundMusic.loadMusic("Sakura-Girl.mp3")) {
    std::cerr << "Failed to load music. Exiting." << std::endl;
    return false;
   }
if (!collectiblemusic.init()) {
    std::cerr << "Failed to initialize music. Exiting." << std::endl;
    return false;
   }

    if (!collectiblemusic.loadMusic("coin.mp3")) {
    std::cerr << "Failed to load music. Exiting." << std::endl;
    return false;
    }
    
    return true;
}

void Game::close()
{
	backgroundMusic.close();
	collectiblemusic.close();
	delete generator;
	generator=nullptr;

	// Destroy window
	SDL_DestroyRenderer(gRenderer);
	SDL_DestroyWindow(gWindow);
	gWindow = NULL;
	gRenderer = NULL;
	// Quit SDL subsystems
    IMG_Quit();
	SDL_Quit();

}
void renderScore(SDL_Renderer* renderer, const Score& score,std::string text);
void levelselection(SDL_Event& e,bool& quit,Texture& mazebgTexture,Texture& selectlevel,SDL_Renderer *gRenderer,bool& Clicked,int& level);

void Game::run() { //main game loop is within it
    bool quit=false;
	bool quit1=false;
    SDL_Event e;	 
	std::string gameState="Running"; //initial gamestate
	int player;

    // Load title screen image
    if (!loadMedia()) {
        std::cerr << "Failed to load media. Exiting." << std::endl;
        return;
    }
    backgroundMusic.play(-1); //playing backgroundmusic indefinitely
	SDL_RenderCopy(gRenderer, titleTexture.texture, nullptr, nullptr);
    SDL_RenderPresent(gRenderer);
	
    //displaying the title screen
    bool titleScreenClicked = false;
    while (!titleScreenClicked && !quit) {
	
        while (SDL_PollEvent(&e) != 0) {
			if (e.type == SDL_QUIT) {
                quit = true;
				}
            
            else if (e.type == SDL_MOUSEBUTTONDOWN) {
                 if (e.button.x >= 246 && e.button.x <= 557 && e.button.y >= 524 && e.button.y <= 602) {
                titleScreenClicked = true;
            }
			}
        }
    }
	
	if (quit==true){ return;}
              
                    
                
    // displaying playerselection screen so that player can be selected
	//if player=0 then its a boy otherwise its a girl
	
	SDL_SetRenderDrawColor(gRenderer, 0, 0, 0, 0);
	SDL_RenderClear(gRenderer);
	SDL_RenderCopy(gRenderer, selectplayer.texture, nullptr, nullptr);
    SDL_RenderPresent(gRenderer);
	
                    
    // Wait for a click event
    bool Clicked = false;
	
    while (!Clicked && !quit) {
	
        while (SDL_PollEvent(&e) != 0) {
			if (e.type == SDL_QUIT) {
                quit = true;
				}
            else if (e.type == SDL_MOUSEBUTTONDOWN) {
                if (e.button.x >= 97 && e.button.x <= 270 && e.button.y >= 576 && e.button.y <= 626) {
					player=0;//boy
                    Clicked = true;}
				else if(e.button.x >= 535 && e.button.x <= 707 && e.button.y <= 622 && e.button.y >= 578){
					player=1;//girl
                   Clicked = true;}
            
			}
        }
    }
	
	if (quit==true){return;}

	Clicked=false;
	int level;
	Player boy;
	Player girl;
    int stoptime;
	int winscore;
	Level::Difficulty difficulty;
	//this function displays the levelselection screen and stores the vales accordingly in level integer
	//level=1->easy, level=2->medium, level=3->hard
	levelselection(e,quit,mazebgTexture,selectlevel,gRenderer,Clicked,level);
    
		
	generator=new Maze(); //maze constructed
	//based on the level a grid will be generated and player dimensions will be selected
	//game conditions will also be selected like the minimum score and max time required to win the game
    switch(level){
	case 1:{
	difficulty = Level::Easy;
	Level level1(difficulty);
	generator->gridmaker(level1.getMazeSize(),SCREEN_WIDTH, SCREEN_HEIGHT, gRenderer);

	boy.addPlayer(gRenderer,"boy.png",740,740,70,70,generator->gridSize);
	girl.addPlayer(gRenderer,"girl.png",720,720,80,80,generator->gridSize);
	stoptime=60;
	winscore=35;
	break;}
	case 2:{
	difficulty = Level::Medium;
	Level level2(difficulty);
	generator->gridmaker(level2.getMazeSize(),SCREEN_WIDTH, SCREEN_HEIGHT, gRenderer);
	boy.addPlayer(gRenderer,"boy.png",755,755,45,45,generator->gridSize);
	girl.addPlayer(gRenderer,"girl.png",740,740,60,60,generator->gridSize);
	stoptime=120;
	winscore=75;
	break;}
    case 3:{
	difficulty = Level::Hard;
	Level level3(difficulty);
	generator->gridmaker(level3.getMazeSize(),SCREEN_WIDTH, SCREEN_HEIGHT, gRenderer);
	boy.addPlayer(gRenderer,"boy.png",770,770,35,35,generator->gridSize);
	girl.addPlayer(gRenderer,"girl.png",770,770,35,35,generator->gridSize);
	stoptime=160;
	winscore=120;
	break;}}

	generator->generate_maze(); //maze pattern generation
	generator->DrawMaze(); //drawing the maze
    generator->drawitems(); //drawing the collectibles
	SDL_RenderPresent(gRenderer);
	if (player==0){ //displaying appropriate player
    SDL_RenderCopy( gRenderer, boy.playertexture.texture, nullptr,boy.mover);}
	else{SDL_RenderCopy( gRenderer, girl.playertexture.texture, nullptr,girl.mover);}
	SDL_RenderPresent(gRenderer);
	TTF_Init(); //initializng font 
	


    stopwatch.start(); //starting the stopwatch
    // Event loop
	

    while (!quit) {
	
        while (SDL_PollEvent(&e) != 0) {
            if (e.type == SDL_QUIT) {
                quit = true;
				
				
            }
			// if max time is reached or the player reaches the destination 
			if ( stopwatch.elapsed()>= stoptime || gameState=="WON" || (boy.curr_x==0 && boy.curr_y==0) || (girl.curr_x==0 && girl.curr_y==0)){
				stopwatch.stop(); //stopwatch is stopped and reset
				stopwatch.reset();
				//if player is at destination and the target score is reached so the game is won
				if (((boy.curr_x==0 && boy.curr_y==0) || (girl.curr_x==0 && girl.curr_y==0)) && points.getscore()>=winscore){
                     gameState="GAME WON";
				}
				//otherwise game is lost
				else{
					gameState="GAME LOST";
				}
				//setting current poitions of the players to starting point
				boy.curr_x=(generator->gridSize)-1;boy.curr_y=(generator->gridSize)-1;
				girl.curr_x=(generator->gridSize)-1;girl.curr_y=(generator->gridSize)-1;

				
				//displaying the score screen
				SDL_SetRenderDrawColor(gRenderer, 0, 0, 0, 0);
	            SDL_RenderClear(gRenderer);
				SDL_RenderCopy(gRenderer, scoredisplay.texture, nullptr, nullptr);
				//displays the score and the gamestate whether lost or won
				renderScore(gRenderer,points,gameState);
				SDL_RenderPresent(gRenderer);
				
				SDL_Delay(10000);
				quit= true;
				}
		
			else if(e.type == SDL_KEYDOWN && gameState=="Running")	{
				//if game is running m which is the gamemanager will handle the conditions of the movement of the player
				if (player==0){
				gameState=manager.move(gRenderer, e.key.keysym.sym,mazebgTexture,generator,boy,points,gameState,collectiblemusic,backgroundMusic);}
				else{
					gameState=manager.move(gRenderer, e.key.keysym.sym,mazebgTexture,generator,girl,points,gameState,collectiblemusic,backgroundMusic);
				}
            
            }
   
        
    }}
	}


//the function that displays level screen
void levelselection(SDL_Event& e,bool& quit,Texture& mazebgTexture,Texture& selectlevel,SDL_Renderer *gRenderer,bool& Clicked,int& level){
	
	SDL_SetRenderDrawColor(gRenderer, 0, 0, 0, 0);
	SDL_RenderClear(gRenderer);
	SDL_RenderCopy(gRenderer, selectlevel.texture, nullptr, nullptr);
    SDL_RenderPresent(gRenderer);
	
                    
 
	
    while (!Clicked && !quit) {
	
        while (SDL_PollEvent(&e) != 0) {
			if (e.type == SDL_QUIT) {
                quit = true;
				}
            else if (e.type == SDL_MOUSEBUTTONDOWN) {
				
                if (e.button.x >= 97 && e.button.x <= 413 && e.button.y >= 64 && e.button.y <= 230) {
					level=1;//easy
                    Clicked = true;}
				else if(e.button.x >= 94 && e.button.x <= 404 && e.button.y <= 429 && e.button.y >= 266){
					level=2;//medium
                   Clicked = true;}
                else if(e.button.x >= 97 && e.button.x <= 418 && e.button.y <= 634 && e.button.y >= 469){
					level=3;//hard
                   Clicked = true;}
			}
        }
    }
    
	SDL_SetRenderDrawColor(gRenderer, 0, 0, 0, 0);
	
    SDL_RenderClear(gRenderer);
	
    SDL_RenderPresent(gRenderer);
    SDL_RenderCopy(gRenderer, mazebgTexture.texture, nullptr, nullptr); //rendering maze background
    SDL_RenderPresent(gRenderer);
        
		
	
   
}
void renderScore(SDL_Renderer* renderer, const Score& score,std::string text) {
    // Load a font
    TTF_Font* font = TTF_OpenFont("C:\\Users\\USER\\Desktop\\MAZE PROJECT\\font.ttf", 60); 
	TTF_Font* font1 = TTF_OpenFont("C:\\Users\\USER\\Desktop\\MAZE PROJECT\\font.ttf", 70);
    //text color
    SDL_Color textColor = {0, 0, 0}; 

  
    std::string scoreText = "Score: " + std::to_string(score.getscore());
    
    // Render score text
    SDL_Surface* textSurface = TTF_RenderText_Solid(font, scoreText.c_str(), textColor); //score
	SDL_Surface* textSurface1 = TTF_RenderText_Solid(font1, text.c_str(), textColor); //gamestate

    if (!textSurface) {
        // Handle error (text surface not created)
        std::cerr << "Failed to create text surface! SDL_ttf Error: " << TTF_GetError() << std::endl;
        TTF_CloseFont(font);
        return;
    }


    SDL_Texture* textTexture = SDL_CreateTextureFromSurface(renderer, textSurface); //score
    SDL_Texture* textTexture1 = SDL_CreateTextureFromSurface(renderer, textSurface1); //gamestate
    if (!textTexture) {
        // Handle error (texture not created)
        std::cerr << "Failed to create text texture! SDL Error: " << SDL_GetError() << std::endl;
        SDL_FreeSurface(textSurface);
        TTF_CloseFont(font);
        return;
    }

    SDL_Rect textRect1 = {250, 350, textSurface1->w, textSurface1->h}; //gamestate
    SDL_Rect textRect = {300, 430, textSurface->w, textSurface->h}; //score

    // Render the text
    SDL_RenderCopy(renderer, textTexture, nullptr, &textRect); //score
    SDL_RenderCopy(renderer, textTexture1, nullptr, &textRect1); //gamestate
    // Cleanup
    SDL_FreeSurface(textSurface);
    SDL_DestroyTexture(textTexture);
    
	SDL_FreeSurface(textSurface1);
    SDL_DestroyTexture(textTexture1);
    TTF_CloseFont(font);
	TTF_CloseFont(font1);
}

