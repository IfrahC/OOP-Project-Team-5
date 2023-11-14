#include<SDL2/SDL.h>
#include <SDL2/SDL_image.h>


void drawObjects(SDL_Renderer* gRnderer, SDL_Texture* assets);
void createObject(int x, int y);

struct Unit{
SDL_Rect srcRect, moverRect;

};