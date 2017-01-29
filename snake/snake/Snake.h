class Snake {
private:
	int x;
	int y;
	int x_dir;
	int y_dir;
	int square_size;
	int speed;
	int screen_size_x;
	int screen_size_y;
public:
	int get_x();
	int get_y();
	int get_x_dir();
	int get_y_dir();
	int get_square_size();
	int get_speed();
	int get_screen_size_x();
	int get_screen_size_y();

	void set_x(int x);
	void set_y(int y);
	void set_x_dir(int x);
	void set_y_dir(int y);
	void set_square_size(int size);
	void set_speed(int speed);
	void set_screen_size_x(int x);
	void set_screen_size_y(int y);

	Snake(int x, int y, int square_size, int speed=1);
	~Snake();
};