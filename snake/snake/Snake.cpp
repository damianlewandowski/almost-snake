#include "Snake.h"

Snake::Snake(int x, int y, int square_size, int speed) {
	this->x = x;
	this->y = y;
	this->square_size = square_size;
	this->speed = speed;
}

Snake::~Snake() {}

int Snake::get_x() {
	return this->x;
}

int Snake::get_y() {
	return this->y;
}

int Snake::get_x_dir() {
	return this->x_dir;
}

int Snake::get_y_dir() {
	return this->y_dir;
}

int Snake::get_square_size() {
	return this->square_size;
}

int Snake::get_speed() {
	return this->speed;
}

int Snake::get_screen_size_x() {
	return this->screen_size_x;
}

int Snake::get_screen_size_y() {
	return this->screen_size_y;
}

void Snake::set_x(int x) {
	if (this->x <= (this->screen_size_x - this->get_square_size()) && this->x >= 0) {
		this->x = x;
	}
}

void Snake::set_y(int y) {
	if (this->y <= (this->screen_size_y - this->get_square_size()) && this->y >= 0) {
		this->y = y;
	}
}

void Snake::set_x_dir(int x) {
	this->x_dir = x;
}

void Snake::set_y_dir(int y) {
	this->y_dir = y;
}

void Snake::set_square_size(int size) {
	this->square_size;
}

void Snake::set_speed(int speed) {
	this->speed = speed;
}

void Snake::set_screen_size_x(int x) {
	this->screen_size_x = x;
}

void Snake::set_screen_size_y(int y) {
	this->screen_size_y = y;
}
