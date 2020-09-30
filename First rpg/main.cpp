#include <vector>
#include <string>
#include <iostream>
#include "map_tiles.h"
#include "player_movement.h"
#include "map_object.h"
#include "playing_field.h"

/*
void move_right(int* x_, int* y_, std::string tiles[10][10]){

	tiles[*y_][*x_] = ".";
	if (*x_ < 10)
		*x_ = *x_ + 1;
	tiles[*y_][*x_] = "X";

}

void print_game_tiles(const int x,const int y,std::string tiles[10][10]) {

	std::cout << "\n";
	for (int i = 0; i < x; ++i) {
		for (int j = 0; j < y; ++j) {
			std::cout << tiles[i][j];
		}
		std::cout << "\n";
	}
}
*/

int main() {

	playing_field first_area;
	first_area.update_current_location();
	first_area.update_win_location();
	first_area.print_playing_field();

	player_hero Jon("Jon", 10, 15, 20, { (0,0) });
	

	bool run_game_flag = true;
	std::string s;

	while (run_game_flag) {
		std::getline(std::cin, s);
		if (s == "a")
			first_area.move_left();
		else if (s == "d")
			first_area.move_right();
		else if (s == "s")
			first_area.move_down();
		else if (s == "w")
			first_area.move_up();
		else if (s == "stop")
			run_game_flag = false;
		if (first_area.win_game()) {
			std::cout << "You won";
			run_game_flag = false;
		}
	}
	



}