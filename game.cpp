// game.cpp
#pragma once
#include <iostream>
#include <string>
#include <SDL.h>

#include "game.hpp"
#include "Level.hpp"
#include <iostream>
#include "mover.hpp"
#include "Player.hpp"

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
				//SDL_SetRenderDrawColor(gRenderer, 0xFF, 0xFF, 0xFF, 0xFF); FROM HW2
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
//
	
    return true;
}

void Game::close()
{
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

/*void Game::run() {
    bool quit = false;
	bool quit1=false;
    SDL_Event e;
	std::string gameState="Running";
	int player;
	Player boy;
	Player girl;
	Level::Difficulty difficulty;

    // Load title screen image
    if (!loadMedia()) {
        std::cerr << "Failed to load media. Exiting." << std::endl;
        return;
    }

	SDL_RenderCopy(gRenderer, titleTexture.texture, nullptr, nullptr);
    SDL_RenderPresent(gRenderer);
		
    // Wait for a click event
    bool titleScreenClicked = false;
    while (!titleScreenClicked && !quit) {
	
        while (SDL_PollEvent(&e) != 0) {
			
            if (e.type == SDL_KEYDOWN && e.key.keysym.sym == SDLK_ESCAPE) {
                quit = true;
            } 
            else if (e.type == SDL_MOUSEBUTTONDOWN) {
                 if (e.button.x >= 246 && e.button.x <= 557 && e.button.y >= 524 && e.button.y <= 602) {
                titleScreenClicked = true;
            }
			}
        }}
    
    //if (quit1==true){return;}
	/*
       quit=false;             
                    
                
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
				quit1=true;}
            else if (e.type == SDL_KEYDOWN && e.key.keysym.sym == SDLK_ESCAPE) {
                quit = true;
            } 
            else if (e.type == SDL_MOUSEBUTTONDOWN) {
				
                 if (e.button.x >= 98 && e.button.x <= 269 && e.button.y <= 577 && e.button.y >= 626) {
					player=0;//boy
                    Clicked = true;}
				else if(e.button.x >= 535 && e.button.x <= 707 && e.button.y <= 622 && e.button.y >= 578){
					player=1;//girl
                   Clicked = true;
				}
            
			}
        }
    }*/
	
	//if (quit1==true){return;}
	/*SDL_SetRenderDrawColor(gRenderer, 0, 0, 0, 0);
    SDL_RenderClear(gRenderer);

	difficulty = Level::Easy;
	Level level1(difficulty);

    SDL_RenderCopy(gRenderer, mazebgTexture.texture, nullptr, nullptr);
    SDL_RenderPresent(gRenderer);
    //generator = new Maze{level1.getMazeSize(), SCREEN_WIDTH, SCREEN_HEIGHT, gRenderer};  
	generator=new Maze{10, SCREEN_WIDTH, SCREEN_HEIGHT, gRenderer};
	delete generator;
	generator=nullptr;
	return;
	     //adding
    generator->generate_maze();
	generator->DrawMaze();
	generator->drawitems();
	

	boy.addPlayer(gRenderer,"boy.png",740,740,70,70,generator->gridSize);
	girl.addPlayer(gRenderer,"girl.png",740,740,70,70,generator->gridSize);
	
	//SDL_Rect boy={770, 770, 35, 35};
	SDL_RenderPresent(gRenderer);
	if (player==0){
		//gameState=move(gRenderer, e.key.keysym.sym,mazebgTexture,generator,boy,points,gameState);
		SDL_RenderCopy( gRenderer, boy.playertexture.texture, nullptr,boy.mover);}
	else{
		//gameState=move(gRenderer, e.key.keysym.sym,mazebgTexture,generator,girl,points,gameState);
		SDL_RenderCopy( gRenderer, girl.playertexture.texture, nullptr,girl.mover);
		}
    //SDL_RenderCopy( gRenderer, boy.playertexture.texture, nullptr,boy.mover);
	SDL_RenderPresent(gRenderer);
    
    // Event loop
    while (!quit) {
        while (SDL_PollEvent(&e) != 0) {
            if (e.type == SDL_QUIT) {
                quit = true;
				quit1=true;
            }
			if (gameState=="WON" || (boy.curr_x==0 && boy.curr_y==0) || (girl.curr_x==0 && girl.curr_y==0)){
				gameState="Running";
				quit=true;}
			else if(e.type == SDL_KEYDOWN && gameState!="WON")	{
				if (player==0){
				gameState=move(gRenderer, e.key.keysym.sym,mazebgTexture,generator,boy,points,gameState);}
				else{
					gameState=move(gRenderer, e.key.keysym.sym,mazebgTexture,generator,girl,points,gameState);
				}
            
            }
   
        
    }}/*
	if (quit1==true){return;}
	
		
	delete generator;
	generator=nullptr;
	gameState="Running";
	quit=false;

    SDL_RenderClear(gRenderer);
    if (!loadMedia()) {
        std::cerr << "Failed to load media. Exiting." << std::endl;
        return;
    }

	difficulty = Level::Medium;
	Level level2(difficulty);

    SDL_RenderCopy(gRenderer, mazebgTexture.texture, nullptr, nullptr);
    SDL_RenderPresent(gRenderer);
    generator = new Maze(level2.getMazeSize(), SCREEN_WIDTH, SCREEN_HEIGHT, gRenderer);       //adding
    generator->generate_maze();
	generator->DrawMaze();
	generator->drawitems();
	
	boy.addPlayer(gRenderer,"boy.png",770,770,35,35,generator->gridSize);
	girl.addPlayer(gRenderer,"girl.png",770,770,35,35,generator->gridSize);
	//SDL_Rect boy={770, 770, 35, 35};
	SDL_RenderPresent(gRenderer);
    SDL_RenderCopy( gRenderer, boy.playertexture.texture, nullptr,boy.mover);
	SDL_RenderPresent(gRenderer);
    
    // Event loop
    while (!quit) {
        while (SDL_PollEvent(&e) != 0) {
            if (e.type == SDL_QUIT) {
                quit = true;
				quit1=true;
            }
			if (gameState=="WON" || (boy.curr_x==0 && boy.curr_y==0) || (girl.curr_x==0 && girl.curr_y==0)){
				gameState="Running";
				quit=true;}
			else if(e.type == SDL_KEYDOWN && gameState!="WON")	{
				if (player==0){
				gameState=move(gRenderer, e.key.keysym.sym,mazebgTexture,generator,boy,points,gameState);}
				else{
					gameState=move(gRenderer, e.key.keysym.sym,mazebgTexture,generator,girl,points,gameState);
				}
				
				}
            
        }
   
        
    }

	
	if (quit1==true){return;}
	
delete generator;
	generator=nullptr;
	gameState="Running";
	quit=false;

    SDL_RenderClear(gRenderer);
    if (!loadMedia()) {
        std::cerr << "Failed to load media. Exiting." << std::endl;
        return;
    }

	difficulty = Level::Hard;
	Level level3(difficulty);

    SDL_RenderCopy(gRenderer, mazebgTexture.texture, nullptr, nullptr);
    SDL_RenderPresent(gRenderer);
    generator = new Maze(level3.getMazeSize(), SCREEN_WIDTH, SCREEN_HEIGHT, gRenderer);       //adding
    generator->generate_maze();
	generator->DrawMaze();
	generator->drawitems();
	
	boy.addPlayer(gRenderer,"boy.png",770,770,35,35,generator->gridSize);
	girl.addPlayer(gRenderer,"girl.png",770,770,35,35,generator->gridSize);
	//SDL_Rect boy={770, 770, 35, 35};
	SDL_RenderPresent(gRenderer);
    SDL_RenderCopy( gRenderer, boy.playertexture.texture, nullptr,boy.mover);
	SDL_RenderPresent(gRenderer);
    
    // Event loop
    while (!quit) {
        while (SDL_PollEvent(&e) != 0) {
            if (e.type == SDL_QUIT) {
                quit = true;
				quit1=true;
            }
			if (gameState=="WON" || (boy.curr_x==0 && boy.curr_y==0) || (girl.curr_x==0 && girl.curr_y==0)){
				gameState="Running";
				quit=true;}
			else if(e.type == SDL_KEYDOWN && gameState!="WON")	{
				if (player==0){
				gameState=move(gRenderer, e.key.keysym.sym,mazebgTexture,generator,boy,points,gameState);}
				else{
					gameState=move(gRenderer, e.key.keysym.sym,mazebgTexture,generator,girl,points,gameState);
				}
				
				}
            
            
        }
   
        
    }
	if (quit1==true){return;}
	
delete generator;
	generator=nullptr;
	gameState="Running";
	quit=false;

    SDL_RenderClear(gRenderer);
    if (!loadMedia()) {
        std::cerr << "Failed to load media. Exiting." << std::endl;
        return;
    }

	difficulty = Level::Hardest;
	Level level4(difficulty);

    SDL_RenderCopy(gRenderer, mazebgTexture.texture, nullptr, nullptr);
    SDL_RenderPresent(gRenderer);
    generator = new Maze(level4.getMazeSize(), SCREEN_WIDTH, SCREEN_HEIGHT, gRenderer);       //adding
    generator->generate_maze();
	generator->DrawMaze();
	generator->drawitems();
	
	boy.addPlayer(gRenderer,"boy.png",770,770,35,35,generator->gridSize);
	girl.addPlayer(gRenderer,"girl.png",770,770,35,35,generator->gridSize);
	//SDL_Rect boy={770, 770, 35, 35};
	SDL_RenderPresent(gRenderer);
    SDL_RenderCopy( gRenderer, boy.playertexture.texture, nullptr,boy.mover);
	SDL_RenderPresent(gRenderer);
    
    // Event loop
    while (!quit) {
        while (SDL_PollEvent(&e) != 0) {
            if (e.type == SDL_QUIT) {
                quit = true;
				quit1=true;
            }
			if (gameState=="WON" || (boy.curr_x==0 && boy.curr_y==0) || (girl.curr_x==0 && girl.curr_y==0)){
				gameState="Running";
				quit=true;}
			else if(e.type == SDL_KEYDOWN && gameState!="WON")	{
				if (player==0){
				gameState=move(gRenderer, e.key.keysym.sym,mazebgTexture,generator,boy,points,gameState);}
				else{
					gameState=move(gRenderer, e.key.keysym.sym,mazebgTexture,generator,girl,points,gameState);
				}
				
				}
            
            
        }
   
        
    }*/

//}

void Game::run() {
    bool quit=false;
	bool quit1=false;
    SDL_Event e;
		 
	std::string gameState="Running";
	int player;

    // Load title screen image
    if (!loadMedia()) {
        std::cerr << "Failed to load media. Exiting." << std::endl;
        return;
    }

	SDL_RenderCopy(gRenderer, titleTexture.texture, nullptr, nullptr);
    SDL_RenderPresent(gRenderer);
	
    // Wait for a click event
    bool titleScreenClicked = false;
    while (!titleScreenClicked && !quit) {
	
        while (SDL_PollEvent(&e) != 0) {
			if (e.type == SDL_QUIT) {
                quit = true;
				quit1=true;}
            if (e.type == SDL_KEYDOWN && e.key.keysym.sym == SDLK_ESCAPE) {
                quit = true;
            } 
            else if (e.type == SDL_MOUSEBUTTONDOWN) {
                 if (e.button.x >= 246 && e.button.x <= 557 && e.button.y >= 524 && e.button.y <= 602) {
                titleScreenClicked = true;
            }
			}
        }
    }
	
	/*if (quit1==false){
       quit=false;             
                    
                
    // Generate and display maze
	
	SDL_SetRenderDrawColor(gRenderer, 0, 0, 0, 0);
	SDL_RenderClear(gRenderer);
	SDL_RenderCopy(gRenderer, selectplayer.texture, nullptr, nullptr);
    SDL_RenderPresent(gRenderer);
	int mouseX, mouseY;
                    
    // Wait for a click event
    bool Clicked = false;
	
    while (!Clicked && !quit) {
	
        while (SDL_PollEvent(&e) != 0) {
			if (e.type == SDL_QUIT) {
                quit = true;
				quit1=true;}
            if (e.type == SDL_KEYDOWN && e.key.keysym.sym == SDLK_ESCAPE) {
                quit = true;
            } 
            else if (e.type == SDL_MOUSEBUTTONDOWN) {
				SDL_GetMouseState(&mouseX, &mouseY);
                    std::cout << "Mouse clicked at: X = " << mouseX << ", Y = " << mouseY << std::endl;
                 /*if (e.button.x >= 246 && e.button.x <= 557 && e.button.y >= 524 && e.button.y <= 602) {
					player=0;//boy
                    Clicked = true;}
				else if(e.button.x >= 246 && e.button.x <= 557 && e.button.y >= 524 && e.button.y <= 602){
					player=1;//girl
                   Clicked = true;
				}
            
			}
        }
    }
	}*/
	
  
    
	SDL_SetRenderDrawColor(gRenderer, 0, 0, 0, 0);
	
    SDL_RenderClear(gRenderer);
	
    SDL_RenderPresent(gRenderer);
  
	Level::Difficulty difficulty = Level::Easy;
	Level level1(difficulty);

    SDL_RenderCopy(gRenderer, mazebgTexture.texture, nullptr, nullptr);
    SDL_RenderPresent(gRenderer);
	

    generator=new Maze(level1.getMazeSize(), SCREEN_WIDTH, SCREEN_HEIGHT, gRenderer);
	generator->generate_maze();

    //generator->placeCollectibles();
	for (int i=0; i<generator->gridSize;i++){
		for (int j=0; j<generator->gridSize;j++){
            std::cout<<1;
            if (generator->grids[i][j].collectible==nullptr){std::cout<<2;}
            else{
			generator->grids[i][j].collectible->show();}
		}
	}
	std::cout<<"done";
	if (generator->grids.empty())   {std::cout<<"empty";} //adding
	std::cout<<"d";
    //generator->DrawMaze();
	std::cout<<"r";
    

	//generator->DrawMaze();
	
	//generator->drawitems();
	Player boy;
	Player girl;
          
		boy.addPlayer(gRenderer,"boy.png",740,740,70,70,10);
	    girl.addPlayer(gRenderer,"girl.png",740,740,70,70,10);
	
	//SDL_Rect boy={770, 770, 35, 35};
	SDL_RenderPresent(gRenderer);
    SDL_RenderCopy( gRenderer, boy.playertexture.texture, nullptr,boy.mover);
	SDL_RenderPresent(gRenderer);
    
    // Event loop
    while (!quit) {
        while (SDL_PollEvent(&e) != 0) {
            if (e.type == SDL_QUIT) {
                quit = true;
				quit1=true;
            }
			if (gameState=="WON" || (boy.curr_x==0 && boy.curr_y==0) || (girl.curr_x==0 && girl.curr_y==0)){
				gameState="Running";
				quit=true;}
			else if(e.type == SDL_KEYDOWN && gameState!="WON")	{
				if (player==0){
				gameState=move(gRenderer, e.key.keysym.sym,mazebgTexture,generator,boy,points,gameState);}
				else{
					gameState=move(gRenderer, e.key.keysym.sym,mazebgTexture,generator,girl,points,gameState);
				}
            
            }
   
        
    }}}
	/*if (quit1==false){
		
	delete generator;
	generator=nullptr;
	gameState="Running";
	quit=false;

    SDL_RenderClear(gRenderer);
    if (!loadMedia()) {
        std::cerr << "Failed to load media. Exiting." << std::endl;
        return;
    }

	Level::Difficulty difficulty = Level::Medium;
	Level level2(difficulty);

    SDL_RenderCopy(gRenderer, mazebgTexture.texture, nullptr, nullptr);
    SDL_RenderPresent(gRenderer);
    generator = new Maze(level2.getMazeSize(), SCREEN_WIDTH, SCREEN_HEIGHT, gRenderer);       //adding
    generator->generate_maze();
	generator->DrawMaze();
	generator->drawitems();
	Player boy;
	Player girl;
	boy.addPlayer(gRenderer,"boy.png",770,770,35,35,generator->gridSize);
	girl.addPlayer(gRenderer,"girl.png",770,770,35,35,generator->gridSize);
	//SDL_Rect boy={770, 770, 35, 35};
	SDL_RenderPresent(gRenderer);
    SDL_RenderCopy( gRenderer, boy.playertexture.texture, nullptr,boy.mover);
	SDL_RenderPresent(gRenderer);
    
    // Event loop
    while (!quit) {
        while (SDL_PollEvent(&e) != 0) {
            if (e.type == SDL_QUIT) {
                quit = true;
				quit1=true;
            }
			if (gameState=="WON" || (boy.curr_x==0 && boy.curr_y==0) || (girl.curr_x==0 && girl.curr_y==0)){
				gameState="Running";
				quit=true;}
			else if(e.type == SDL_KEYDOWN && gameState!="WON")	{
				if (player==0){
				gameState=move(gRenderer, e.key.keysym.sym,mazebgTexture,generator,boy,points,gameState);}
				else{
					gameState=move(gRenderer, e.key.keysym.sym,mazebgTexture,generator,girl,points,gameState);
				}
				
				}
            
        }
   
        
    }

	}
	if (quit1==false){
delete generator;
	generator=nullptr;
	gameState="Running";
	quit=false;

    SDL_RenderClear(gRenderer);
    if (!loadMedia()) {
        std::cerr << "Failed to load media. Exiting." << std::endl;
        return;
    }

	Level::Difficulty difficulty = Level::Hard;
	Level level3(difficulty);

    SDL_RenderCopy(gRenderer, mazebgTexture.texture, nullptr, nullptr);
    SDL_RenderPresent(gRenderer);
    generator = new Maze(level3.getMazeSize(), SCREEN_WIDTH, SCREEN_HEIGHT, gRenderer);       //adding
    generator->generate_maze();
	generator->DrawMaze();
	generator->drawitems();
	Player boy,girl;
	boy.addPlayer(gRenderer,"boy.png",770,770,35,35,generator->gridSize);
	girl.addPlayer(gRenderer,"girl.png",770,770,35,35,generator->gridSize);
	//SDL_Rect boy={770, 770, 35, 35};
	SDL_RenderPresent(gRenderer);
    SDL_RenderCopy( gRenderer, boy.playertexture.texture, nullptr,boy.mover);
	SDL_RenderPresent(gRenderer);
    
    // Event loop
    while (!quit) {
        while (SDL_PollEvent(&e) != 0) {
            if (e.type == SDL_QUIT) {
                quit = true;
				quit1=true;
            }
			if (gameState=="WON" || (boy.curr_x==0 && boy.curr_y==0) || (girl.curr_x==0 && girl.curr_y==0)){
				gameState="Running";
				quit=true;}
			else if(e.type == SDL_KEYDOWN && gameState!="WON")	{
				if (player==0){
				gameState=move(gRenderer, e.key.keysym.sym,mazebgTexture,generator,boy,points,gameState);}
				else{
					gameState=move(gRenderer, e.key.keysym.sym,mazebgTexture,generator,girl,points,gameState);
				}
				
				}
            
            
        }
   
        
    }}
	if (quit1==false){
delete generator;
	generator=nullptr;
	gameState="Running";
	quit=false;

    SDL_RenderClear(gRenderer);
    if (!loadMedia()) {
        std::cerr << "Failed to load media. Exiting." << std::endl;
        return;
    }

	Level::Difficulty difficulty = Level::Hardest;
	Level level4(difficulty);

    SDL_RenderCopy(gRenderer, mazebgTexture.texture, nullptr, nullptr);
    SDL_RenderPresent(gRenderer);
    generator = new Maze(level4.getMazeSize(), SCREEN_WIDTH, SCREEN_HEIGHT, gRenderer);       //adding
    generator->generate_maze();
	generator->DrawMaze();
	generator->drawitems();
	Player boy,girl;
	boy.addPlayer(gRenderer,"boy.png",770,770,35,35,generator->gridSize);
	girl.addPlayer(gRenderer,"girl.png",770,770,35,35,generator->gridSize);
	//SDL_Rect boy={770, 770, 35, 35};
	SDL_RenderPresent(gRenderer);
    SDL_RenderCopy( gRenderer, boy.playertexture.texture, nullptr,boy.mover);
	SDL_RenderPresent(gRenderer);
    
    // Event loop
    while (!quit) {
        while (SDL_PollEvent(&e) != 0) {
            if (e.type == SDL_QUIT) {
                quit = true;
				quit1=true;
            }
			if (gameState=="WON" || (boy.curr_x==0 && boy.curr_y==0) || (girl.curr_x==0 && girl.curr_y==0)){
				gameState="Running";
				quit=true;}
			else if(e.type == SDL_KEYDOWN && gameState!="WON")	{
				if (player==0){
				gameState=move(gRenderer, e.key.keysym.sym,mazebgTexture,generator,boy,points,gameState);}
				else{
					gameState=move(gRenderer, e.key.keysym.sym,mazebgTexture,generator,girl,points,gameState);
				}
				
				}
            
            
        }
   
        
    }

}}*/



