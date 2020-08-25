#include <vector>
#include <string>
#include <iostream>

void move_right(int* x_, int y_, std::string tiles[10][10]){

	tiles[y_][*x_] = ".";
	if (*x_ < 10)
		*x_ = *x_ + 1;
	tiles[y_][*x_] = "X";

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

int main() {
	std::cout << "Welcome to first RPG\n";


	const int x_length = 10;
	const int y_length = 10;

	std::string game_tiles[x_length][y_length];
	for (int i = 0; i < x_length; ++i) {
		for (int j = 0; j < y_length; ++j) {
			game_tiles[i][j] = ".";
		}
	}

	game_tiles[0][8] = "X";
	int current_x = 8;
	int current_y = 0;
	
	int* current_loc = &current_x;
	std::cout << "your current location is marked by 'X'\n";

	print_game_tiles(x_length, y_length, game_tiles);

	bool play = true;
	std::string cont;

	while (play) {
		if (*current_loc == 10) {
			std::cout << "you win";
			play = false;
		}
		std::cout << "move right (y/n)";
		std::getline(std::cin, cont);
		if (cont == "y")
			move_right(current_loc, current_y, game_tiles);
		print_game_tiles(x_length, y_length, game_tiles);

		std::cout << "continue(y/n)";
		std::getline(std::cin, cont);
		if (cont == "n")
			play = false;

	}
	std::cout << "Thank you for playing";
//test cases
	if (game_tiles[5][7] == ".")
		std::cout << "passed\n";
	else
		std::cout << "failed\n";



}