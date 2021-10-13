#include <vector>
#include <string>
#include <iostream>
#include "map_tiles.h"
#include "player_movement.h"
#include "map_object.h"
#include "playing_field.h"


int main() {

	


	std::cout<<"test"<<std::endl;
	player_hero Jon("Jon", 10, 15, 20, { 1,1 });
	enemy_npc Strider("Strider", 20, 30, 40, { 3,3 });
	friendly_npc Shop_keeper("Shop Keeper", {2,1});
	weapon long_sword(true, "long sword", { 1,2 }, 10);
	playing_field first_area;
	first_area.place_map_object(&Jon);
	first_area.place_map_object(&Strider);
	first_area.place_map_object(&Shop_keeper);
	first_area.place_weapon(&long_sword);

	first_area.update_win_location();
	first_area.print_playing_field();

	bool run_game_flag = true;
	std::string s;

	while (run_game_flag) {
		Jon.print_stats();
		std::getline(std::cin, s);
		if (s == "stop")
			run_game_flag = false;
		else if (s == "a" || s == "s" || s == "d" || s == "w")
			first_area.move(&Jon, s);
		else {
			std::cout << "not a valid movement\n";
			first_area.print_playing_field();
		}
		if (first_area.win_game()) {
			std::cout << "You won";
			run_game_flag = false;
		}
		
		//Have enemy randomly move
		//print player stats?

	}
	return 0;
}