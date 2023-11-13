#include<SDL2/SDL.h>


void drawObjects(SDL_Renderer* gRnderer, SDL_Texture* assets);
void createObject(int x, int y);

struct Unit{
SDL_Rect srcRect, moverRect;

};