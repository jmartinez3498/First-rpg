#include <vector>
#include <string>
#include <iostream>
#include "playing_field.h"

void playing_field::print_playing_field() {
	for (int i = 0; i < 10; ++i) {
		std::cout << "\n";
	}

	for (int j = 0; j < y_dim; ++j) {
		for (int i = 0; i < x_dim; ++i) {
			std::cout << game_tiles[i][j];
		}
		std::cout << "\n";
	}

}

void playing_field::update_win_location() {
	game_tiles[win_location[0]][win_location[1]] = "W";
}

void playing_field::update_current_location() {
	game_tiles[current_location[0]][current_location[1]] = "X";
}

void playing_field::update_previous_location() {
	game_tiles[current_location[0]][current_location[1]] = ".";
}

void playing_field::move_right() {
	this->update_previous_location();
	current_location[0] = current_location[0] + 1; 
	this->update_current_location();
	this->print_playing_field();
}

void playing_field::move_left() {
	this->update_previous_location();
	current_location[0] = current_location[0] - 1;
	this->update_current_location();
	this->print_playing_field();
}

void playing_field::move_up() {
	this->update_previous_location();
	current_location[1] = current_location[1] - 1;
	this->update_current_location();
	this->print_playing_field();
}

void playing_field::move_down() {
	this->update_previous_location();
	current_location[1] = current_location[1] + 1;
	this->update_current_location();
	this->print_playing_field();
}

bool playing_field::win_game() {
	if (current_location == win_location)
		return true;
	else
		return false;
}

