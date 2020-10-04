#include <vector>
#include <string>
#include <iostream>
#include "map_tiles.h"
#include "player_movement.h"
#include "map_object.h"
#include "playing_field.h"


int main() {

	playing_field first_area;
	first_area.update_current_location();
	first_area.update_win_location();
	first_area.print_playing_field();

	player_hero Jon("Jon", 10, 15, 20, { 0,0 });
	enemy_npc Strider("Striker", 20, 30, 40, { 3,3 });
	//Jon.get_map_coordinates(); vector containing (0,0)
	//first_area;
	first_area.place_map_object(&Jon);
	first_area.place_map_object(&Strider);

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