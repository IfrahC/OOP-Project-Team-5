Game::Game(int size):mazeSize{size}{}
bool Game::init()
{
	// Initialization flag
	std::cout<<"init";
	bool success = true;

	// Initialize SDL
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
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
		gWindow = SDL_CreateWindow("MazeSolver", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
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
	// Loading success flag
	bool success = true;

	

    this->titleTexture = loadTexture("Start Page 2.png");
    if (this->titleTexture == nullptr) {
    printf ("Failed to create texture from title image! SDL Error: " , SDL_GetError());
    success=false;
    }
	this->mazebgTexture = loadTexture("soil.png");
    if (this->mazebgTexture == nullptr) {
    printf ("Failed to create texture from title image! SDL Error: " , SDL_GetError());
    success=false;
    }

	return success;
}

void Game::close()
{
	delete generator;

    SDL_DestroyTexture(this->titleTexture);
	SDL_DestroyTexture(this->mazebgTexture);

	// Destroy window
	SDL_DestroyRenderer(gRenderer);
	SDL_DestroyWindow(gWindow);
	gWindow = NULL;
	gRenderer = NULL;
	// Quit SDL subsystems
    IMG_Quit();
	SDL_Quit();
}

SDL_Texture *Game::loadTexture(std::string path)
{
	// The final texture
	SDL_Texture *newTexture = NULL;

	// Load image at specified path
	SDL_Surface *loadedSurface = IMG_Load(path.c_str());
	if (loadedSurface == NULL)
	{
		printf("Unable to load image %s! SDL_image Error: %s\n", path.c_str(), IMG_GetError());
	}
	else
	{
		// Create texture from surface pixels
		newTexture = SDL_CreateTextureFromSurface(gRenderer, loadedSurface);
		if (newTexture == NULL)
		{
			printf("Unable to create texture from %s! SDL Error: %s\n", path.c_str(), SDL_GetError());
		}

		// Get rid of old loaded surface
		SDL_FreeSurface(loadedSurface);
	}

	return newTexture;
}
void Game::run() {
    bool quit = false;
    SDL_Event e;

    // Load title screen image
    if (!loadMedia()) {
        std::cerr << "Failed to load media. Exiting." << std::endl;
        return;
    }

    // Display title screen
	
    SDL_RenderCopy(gRenderer, titleTexture, nullptr, nullptr);
    SDL_RenderPresent(gRenderer);
    SDL_Delay(2000);  // Display title screen for 2 seconds

    // Generate and display maze
   
	SDL_SetRenderDrawColor(gRenderer, 0, 0, 0, 0);
    SDL_RenderClear(gRenderer);
    SDL_RenderPresent(gRenderer);

	SDL_RenderCopy(gRenderer, mazebgTexture, nullptr, nullptr);
    SDL_RenderPresent(gRenderer);
    generator = new Maze(mazeSize, SCREEN_WIDTH, SCREEN_HEIGHT, gRenderer);
    generator->generate_maze();
	SDL_RenderPresent(gRenderer);

    // Event loop
    while (!quit) {
        while (SDL_PollEvent(&e) != 0) {
            if (e.type == SDL_KEYDOWN && e.key.keysym.sym == SDLK_ESCAPE) {
                quit = true;
            } else if (e.type == SDL_QUIT) {
                quit = true;
            }
        }

        // Clear the renderer
        
    }
}
