#include <vector>
#include <string>
#include <iostream>
#include "map_tiles.h"
#include "player_movement.h"
#include "map_object.h"
#include "playing_field.h"


int main() {

	

	player_hero Jon("Jon", 10, 15, 20, { 1,1 });
	enemy_npc Strider("Strider", 20, 30, 40, { 3,3 });
	friendly_npc Shop_keeper("Shop Keeper", {2,1});
	weapon long_sword(true, "long sword", { 1,2 }, 10);
	win_object w("winner", "X", {8,8}, true);
	playing_field first_area;
	first_area.update_game_tiles(&Jon);
	first_area.update_game_tiles(&Strider);
	first_area.update_game_tiles(&Shop_keeper);
	first_area.update_game_tiles(&long_sword);
	first_area.update_game_tiles(&w);

	first_area.print_playing_field(true);

	bool run_game_flag = true;
	bool collision;
	std::string s;

	while (run_game_flag) {
		Jon.print_stats();
		std::getline(std::cin, s);
		if (s == "stop")
			run_game_flag = false;
		else if (s == "a" || s == "s" || s == "d" || s == "w"){
			first_area.update_map(&Jon, s);

		}

		else {
			first_area.print_playing_field(false);
		}
		if (first_area.get_win_game_flag() == true) {
			std::cout << "You won";
			run_game_flag = false;
		}
		
		//Have enemy randomly move
		//print player stats?

	}
	return 0;
}