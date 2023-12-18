// game.hpp

#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include "Level.hpp"
#include "Cell.hpp"
#include "Maze.hpp"
#include "Music.hpp"
// #include "Texture.hpp"
#include "Stopwatch.hpp"
#include <stdio.h>
#include <iostream>
#include <string>
#include <stdlib.h>
#include <time.h>
#include "Player.hpp"
#include "Score.hpp"
#include "GameManager.hpp"

class Game
{

  const int SCREEN_WIDTH = 800; // screen dimensions
  const int SCREEN_HEIGHT = 800;

  Score points; // score of the game
  Level level_;// level of game
  Stopwatch stopwatch; // stopwatch

  // The window we'll be rendering to
  SDL_Window *gWindow = NULL;
  // The window renderer
  SDL_Renderer *gRenderer = NULL;

  GameManager manager;
  
  Maze *generator{nullptr}; // the maze
  // music
  /*Music backgroundMusic;
  Music collectiblemusic;*/
  Music music;
  Player gameplayer;

  Texture titleTexture; // textures required to draw the maze and players etc
  Texture mazebgTexture;
  Texture selectplayer;
  Texture selectlevel;
  Texture scoredisplay;
  Texture vwall;
  Texture hwall;
  Texture tboy;
  Texture tgirl;
  Texture gamerules;

  void renderScore(SDL_Renderer *renderer, const Score &score, std::string text);
  void levelselection(SDL_Event &e, bool &quit, Texture &mazebgTexture, Texture &selectlevel, SDL_Renderer *gRenderer, bool &Clicked, int &level);

public:
  bool init();
  bool loadMedia();
  void close();
  void run();
  ~Game();
};
