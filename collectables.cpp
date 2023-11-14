#include<iostream>
#include "collectables.hpp"
#include "Score.cpp"
#include <vector>
using namespace std;

// Define a Collectible class
class Collectible {
    public:
        SDL_Texture* texture;
        SDL_Rect position;
        //pure virtual function score incrementation
        virtual int updateScore(Score& score) = 0;

        // Load the image into the texture
        void loadTexture(SDL_Renderer* renderer, const char* path) {
            SDL_Surface* surface = IMG_Load(path);
            texture = SDL_CreateTextureFromSurface(renderer, surface);
            SDL_FreeSurface(surface);
        }

        // Render the collectible object
        void render(SDL_Renderer* renderer) {
            SDL_RenderCopy(renderer, texture, NULL, &position);
        }

        // Check for collision with the player
        bool checkCollision(SDL_Rect player) {
            return SDL_HasIntersection(&position, &player);
        }
};

class Coin : public Collectible {
    public:
        int updateScore(Score& score) override {
            ++score;
        }
};

class Diamond : public Collectible {
    public:
        int updateScore(Score& score) override {
            score+=5;
        }
};