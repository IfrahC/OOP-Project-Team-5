// DO NOT CHANGE THIS FILE
#pragma once
#include "mover.hpp"
#include "MazeRunner.hpp"
#include <SDL_ttf.h>
std::string move(SDL_Renderer* gRenderer, SDL_Keycode key,Texture mazebgTexture,Maze* generator , Player &boy,Score& points,std::string gameState){
    if (generator->grids[boy.curr_x][boy.curr_y].haveCoin==true){
        generator->grids[boy.curr_x][boy.curr_y].collectible->collect(points);
             std::cout<<points.getscore();
             generator->grids[boy.curr_x][boy.curr_y].haveCoin=false;
         }
        else if (generator->grids[boy.curr_x][boy.curr_y].haveDiamond==true){
              generator->grids[boy.curr_x][boy.curr_y].collectible->collect(points);
              std::cout<<points.getscore();
              generator->grids[boy.curr_x][boy.curr_y].haveDiamond=false;
           }
    if (gameState=="WON"){return gameState;}
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
void renderScore(SDL_Renderer* renderer, const Score& score);
void update(SDL_Renderer* gRenderer,Texture mazebgTexture,Maze* generator,Player& boy,Score& points,std::string gameState){
    std::cout<<gameState<<std::endl;
    boy.playertexture.texture=boy.playertexture.load(gRenderer,boy.texturePath);
    mazebgTexture.texture=mazebgTexture.load(gRenderer, "soil.png");
    if(boy.playertexture.texture==nullptr){std::cout<<"null";}
    SDL_RenderClear(gRenderer);
    SDL_RenderCopy(gRenderer, mazebgTexture.texture, nullptr, nullptr);
	generator->DrawMaze();
    generator->drawitems();
    renderScore(gRenderer,points);
	SDL_RenderCopy( gRenderer, boy.playertexture.texture, nullptr, boy.mover );
	SDL_RenderPresent( gRenderer );	
		
}


void renderScore(SDL_Renderer* renderer, const Score& score) {
    // Load a font
    TTF_Font* font = TTF_OpenFont("ToThePointRegular-n9y4.ttf", 24); 

    if (!font) {
        // Handle error (font not loaded)
        //std::cerr << "Failed to load font! SDL_ttf Error: " << TTF_GetError() << std::endl;
        return;
    }

    SDL_Color textColor = {255, 255, 255}; 

  
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
