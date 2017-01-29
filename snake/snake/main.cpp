#include <SDL.h>					
#include <SDL_ttf.h>
#include <stdio.h>					/* I/O stuff */
#include <ctime>					/* time() */
#include <cstdlib>					/* srand() */

#include "GameBoard.h"
#include "Snake.h"


int main(int argc, char **argv) {
	srand(time(NULL));
	const int square_size = 25;
	int score = 0;

	GameBoard game_board(1200, 800);

	Snake snake((game_board.get_screen_width() / 2) - square_size, (game_board.get_screen_height() / 2) - square_size, square_size, 1);
	snake.set_screen_size_x(game_board.get_screen_width());
	snake.set_screen_size_y(game_board.get_screen_height());

	/* Initial momentum */
	snake.set_x_dir(5);
	snake.set_y_dir(0);

	/* Event handler */
	SDL_Event e;

	/* Quit flag */
	bool quit = false;

	/* Apple's coordinates and flag */
	int rand_x;
	int rand_y;
	bool apple_present = false;

	/* Main game loop*/
	while (!quit) {

		/* Check if there are any events in queue */
		while (SDL_PollEvent(&e) != 0) {
			//User requests quit
			if (e.type == SDL_QUIT) {
				quit = true;
			}
			else if (e.type == SDL_KEYDOWN) {
				switch (e.key.keysym.sym) {
				case SDLK_UP:
					snake.set_y_dir(-snake.get_speed() * 5);
					snake.set_x_dir(0);
					break;

				case SDLK_DOWN:
					snake.set_y_dir(snake.get_speed() * 5);
					snake.set_x_dir(0);
					break;

				case SDLK_LEFT:
					snake.set_x_dir(-snake.get_speed() * 5);
					snake.set_y_dir(0);
					break;

				case SDLK_RIGHT:
					snake.set_x_dir(snake.get_speed() * 5);
					snake.set_y_dir(0);
					break;
				}
			}
		}

			//Clear screen, get_game_screen_renderer returns SDL_Renderer* */
			SDL_SetRenderDrawColor(game_board.get_game_screen_renderer(), 0x000000, 0x255, 0x132, 0xFF);
			SDL_RenderClear(game_board.get_game_screen_renderer());

			snake.set_y(snake.get_y() + snake.get_y_dir());
			snake.set_x(snake.get_x() + snake.get_x_dir());

			//Render red filled quad
			SDL_Rect fillRect = { snake.get_x(), snake.get_y(), snake.get_square_size(), snake.get_square_size() };
			SDL_SetRenderDrawColor(game_board.get_game_screen_renderer(), 0xFF, 0xFF, 0x132, 0x132);
			SDL_RenderFillRect(game_board.get_game_screen_renderer(), &fillRect);

			/* Apples are the same size as snake's head */
			if (!apple_present) {
				rand_x = rand() % (game_board.get_screen_width() - snake.get_square_size());
				rand_y = rand() % (game_board.get_screen_height() - snake.get_square_size());

				apple_present = true;
			}

			SDL_Rect apple = { rand_x, rand_y, snake.get_square_size(), snake.get_square_size() };
			SDL_SetRenderDrawColor(game_board.get_game_screen_renderer(), 0x255, 0x00, 0x00, 0x00);
			SDL_RenderFillRect(game_board.get_game_screen_renderer(), &apple);

			/* Was the apple eaten? */
			if (snake.get_x() + snake.get_square_size() >= rand_x && snake.get_x() <= rand_x + snake.get_square_size() && 
				snake.get_y() + snake.get_square_size() >= rand_y && snake.get_y() <= rand_y + snake.get_square_size()) {
				apple_present = false;
				++score;
			}


			// Update screen
			SDL_RenderPresent(game_board.get_game_screen_renderer());
		
	}
	return 0;
}