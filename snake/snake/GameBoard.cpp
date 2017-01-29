#include <stdio.h>
#include "GameBoard.h"


bool GameBoard::init() {
	bool success = true;
	//Initialize SDL
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
		success = false;
	} else {
		//Set texture filtering to linear
		if (!SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "1")) {
			printf("Warning: Linear texture filtering not enabled!");
		}

		//Create window
		game_window = SDL_CreateWindow("SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
		if (game_window == NULL)
		{
			printf("Window could not be created! SDL_Error: %s\n", SDL_GetError());
			success = false;
		} else {
			//Get window surface
			game_screen_renderer = SDL_CreateRenderer(game_window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
			if (game_screen_renderer == NULL)
			{
				printf("Renderer could not be created! SDL Error: %s\n", SDL_GetError());
				success = false;
			} else {
				//Initialize renderer color
				SDL_SetRenderDrawColor(game_screen_renderer, 0xFF, 0xFF, 0xFF, 0xFF);
			}
		}
	}

	return success;
}

void GameBoard::close() {
	//Destroy window
	SDL_DestroyWindow(game_window);
	game_window = NULL;

	//Quit SDL subsystems
	SDL_Quit();
}

/*
void GameBoard::generate_apple() {
	SDL_Rect fillRect = { , snake.get_y(), snake.get_square_size(), snake.get_square_size() };
	SDL_SetRenderDrawColor(game_board.get_game_screen_renderer(), 0xFF, 0xFF, 0x132, 0x132);
	SDL_RenderFillRect(game_board.get_game_screen_renderer(), &fillRect);
}
*/
/* Getters */
SDL_Renderer *GameBoard::get_game_screen_renderer() {
	return this->game_screen_renderer;
}

SDL_Window *GameBoard::get_game_window() {
	return this->game_window;
}


int GameBoard::get_screen_width() {
	return this->SCREEN_WIDTH;
}

int GameBoard::get_screen_height() {
	return this->SCREEN_HEIGHT;
}

/* Setters */
void GameBoard::set_game_screen_renderer() {}
void GameBoard::set_game_window() {}

void GameBoard::set_apple_size(int s) {
	this->apple_size = s;
}

GameBoard::GameBoard(int width, int height) : SCREEN_WIDTH(width), SCREEN_HEIGHT(height) {
	this->init();
}

GameBoard::~GameBoard() {
	this->close();
}
