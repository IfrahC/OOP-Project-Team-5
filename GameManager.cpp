// DO NOT CHANGE THIS FILE
#pragma once
#include "GameManager.hpp"
#include "MazeRunner.hpp"

#include <SDL_ttf.h>

std::string GameManager:: move(SDL_Renderer* gRenderer, SDL_Keycode key,Texture& mazebgTexture,Maze* generator , Player &boy,Score& points,std::string gameState,Music& collectiblemusic,Music& bg){
    //collection of coins and diamonds
    if (generator->grids[boy.curr_x][boy.curr_y].haveCoin==true){
        generator->grids[boy.curr_x][boy.curr_y].collectible->collect(points);
        collectiblemusic.play(1);
        generator->grids[boy.curr_x][boy.curr_y].haveCoin=false;
            
        }
    else if (generator->grids[boy.curr_x][boy.curr_y].haveDiamond==true){
        generator->grids[boy.curr_x][boy.curr_y].collectible->collect(points);
          
        collectiblemusic.play(1);
        generator->grids[boy.curr_x][boy.curr_y].haveDiamond=false;
         
        }
           
    if (gameState=="WON"){return gameState;}
    //makemove function called depending upon the key pressed
    if (key == SDLK_UP && gameState=="Running"){
        gameState=makeMove("North",generator,boy,points,gameState);
    }
    else if (key == SDLK_DOWN  && gameState=="Running") {
        gameState=makeMove("South",generator,boy,points,gameState);
    }
    else if (key == SDLK_RIGHT  && gameState=="Running") {
        gameState=makeMove("East",generator,boy,points,gameState);
    }
    else if (key == SDLK_LEFT  && gameState=="Running") {
        gameState=makeMove("West",generator,boy,points,gameState);
    }
    else {
        std::cout<<"hello";
    }

    update(gRenderer,mazebgTexture,generator,boy,points,gameState); 
    return gameState;
}
//function for rendering maze,background,score continuously with updated things
void GameManager::update(SDL_Renderer* gRenderer,Texture& mazebgTexture,Maze* generator,Player& boy,Score& points,std::string gameState){
    
    SDL_RenderClear(gRenderer);
    SDL_RenderCopy(gRenderer, mazebgTexture.texture, nullptr, nullptr);
	generator->DrawMaze();
    generator->drawitems();
    renderScore(gRenderer,points);
	SDL_RenderCopy( gRenderer, boy.playertexture.texture, nullptr, boy.mover );
	SDL_RenderPresent( gRenderer );	
		
}

//score rendering function
void GameManager::renderScore(SDL_Renderer* renderer, const Score& score) {
    // Load a font
    TTF_Font* font = TTF_OpenFont("C:\\Users\\USER\\Desktop\\MAZE PROJECT\\font.ttf", 50); 
    SDL_Color textColor = {0, 0, 0}; 
    std::string scoreText = "Score: " + std::to_string(score.getscore());

    // Render score text
    SDL_Surface* textSurface = TTF_RenderText_Solid(font, scoreText.c_str(), textColor);

    if (!textSurface) {
        // Handle error (text surface not created)
        std::cerr << "Failed to create text surface! SDL_ttf Error: " << TTF_GetError() << std::endl;
        TTF_CloseFont(font);
        return;
    }

    SDL_Texture* textTexture = SDL_CreateTextureFromSurface(renderer, textSurface);

    if (!textTexture) {
        // Handle error (texture not created)
        std::cerr << "Failed to create text texture! SDL Error: " << SDL_GetError() << std::endl;
        SDL_FreeSurface(textSurface);
        TTF_CloseFont(font);
        return;
    }

    
    SDL_Rect textRect = {10, 10, textSurface->w, textSurface->h};

    // Render the text
    SDL_RenderCopy(renderer, textTexture, nullptr, &textRect);

    // Cleanup
    SDL_FreeSurface(textSurface);
    SDL_DestroyTexture(textTexture);
    TTF_CloseFont(font);
}
