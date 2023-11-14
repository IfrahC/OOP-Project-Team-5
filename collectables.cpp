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
        virtual int updateScore(int s) const = 0;

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
        int updateScore(int s) const override {
            s++;
        }
};

class Diamond : public Collectible {
    public:
        int updateScore(int s) const override {
            s+=5;
        }
}

// Unit pigeon = {{7, 88, 155, 103}, {30, 40, 50, 50}};
// Unit butterfly = {{257, 24, 173, 134}, {30, 40, 50, 50}};


// vector<Unit> pigeons;
// vector<Unit> butterflies;
// vector<Unit> bees;

// void drawObjects(SDL_Renderer* gRenderer, SDL_Texture* assets) {

//     // Draw pigeons
//     for (Unit& p : pigeons) {
//         SDL_RenderCopy(gRenderer, assets, &p.srcRect, &p.moverRect);
//         p.moverRect.x += 2; // Move the pigeon two pixels to the right

//         if (p.moverRect.x  + p.moverRect.w >= 1000) { //When object hits the rightmost corner of the screen
//             p.moverRect.x = 0; // Reappear from the lftmost corner
//         }

//         int pAnimate[3][4] = {{7, 88, 155, 103}, {0, 237, 153, 84}, {2, 361, 159, 124}}; // Different states of the object

//             for (int i{0}; i < 3; i++) { //Iterate over the different states
//                 p.srcRect.x = pAnimate[i][0];
//                 p.srcRect.y = pAnimate[i][1];
//                 p.srcRect.w = pAnimate[i][2];
//                 p.srcRect.h = pAnimate[i][3];
//         }

//     }

//     // Draw butterflies
//     for (Unit& f : butterflies) {
//         SDL_RenderCopy(gRenderer, assets, &f.srcRect, &f.moverRect);
//         f.moverRect.x+=2;
        
//         if (f.moverRect.x  + f.moverRect.w >= 1000) {
//             f.moverRect.x = 0;
//         }

//         int fAnimate[3][4] = {{257, 24, 173, 134}, {257, 182, 192, 214}, {248, 432, 248, 179}}; // Different states of the object

//         for (int i{0}; i < 3; i++) { //Iterate over the different states
//                 f.srcRect.x = fAnimate[i][0];
//                 f.srcRect.y = fAnimate[i][1];
//                 f.srcRect.w = fAnimate[i][2];
//                 f.srcRect.h = fAnimate[i][3];
//         }
//     }

//     // Draw bees
//     for (Unit& b : bees) {
//         SDL_RenderCopy(gRenderer, assets, &b.srcRect, &b.moverRect);
//         b.moverRect.x+=2;

//         if (b.moverRect.x + b.moverRect.w >= 1000) {
//             b.moverRect.x = 0;
//         }

  
//         int bAnimate[3][4] = {{527, 138, 194, 115}, {540, 370, 193, 115}, {527, 254, 194, 115}}; // Different states of the object

//         for (int i{0}; i < 3; i++) { //Iterate over the different states
//                 b.srcRect.x = bAnimate[i][0];
//                 b.srcRect.y = bAnimate[i][1];
//                 b.srcRect.w = bAnimate[i][2];
//                 b.srcRect.h = bAnimate[i][3];
//         }
//     }
// };


// void createObject(int x, int y) {

//     // Randomly generate an object
//     int objectType = rand() % 3;

//     // Create object based on the randomly generated number
//     Unit newObject;
//     switch(objectType) {
//         case 0: //If number is 0
//             newObject = pigeon; //Create a pigeon
//             break;
//         case 1: //If number is 1
//             newObject = butterfly; //Create a butterfly
//             break;
//         case 2: //If number is 2
//             newObject = bee; //Create a bee
//             break;
//     }

//     // Set the position of the new object
//     newObject.moverRect.x = x;
//     newObject.moverRect.y = y;

//     // Push the new object into the corresponding vector
//     if (objectType == 0) {
//         pigeons.push_back(newObject);
//     } else if (objectType == 1) {
//         butterflies.push_back(newObject);
//     } else {
//         bees.push_back(newObject);
//     }

//     std::cout<<"Mouse clicked at: "<<x<<" -- "<<y<<std::endl; // Print mouse coorddinates
// }
