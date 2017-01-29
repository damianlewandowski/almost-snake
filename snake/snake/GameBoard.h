#include <SDL.h>

class GameBoard {
private:
	const int SCREEN_WIDTH;
	const int SCREEN_HEIGHT;
	SDL_Window *game_window;
	SDL_Renderer *game_screen_renderer;

	int apple_size;
	SDL_Rect *apples = NULL;					
public:
	GameBoard(int width, int height);
	~GameBoard();
	bool init();
	void close();

	/* Generates apples */
	void generate_apple();

	/* Getters */
	int get_screen_width();
	int get_screen_height();
	int get_apple_size();
	SDL_Renderer *get_game_screen_renderer();
	SDL_Window *get_game_window();
	SDL_Surface *get_image();

	/* Setters */
	void set_game_screen_renderer();
	void set_game_window();
	void set_image();
	void set_apple_size(int s);
};