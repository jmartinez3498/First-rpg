#include <vector>
#include <string>
#include <iostream>
#include "playing_field.h"
#include "player_movement.h"

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
	//player_movement jon;
	first_area.update_current_location();
	first_area.print_playing_field();
	for (int i = 0; i < 5; ++i) {
		first_area.move_right();
		first_area.move_down();
	}




}