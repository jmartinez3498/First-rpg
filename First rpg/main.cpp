#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include "map_tiles.h"
#include "player_movement.h"
#include "map_object.h"
#include "playing_field.h"


int main() {

	

	player_hero Jon("Jon", 10, 15, 20, { 1,3 });
	enemy_npc Strider("Strider", 20, 30, 40, { 3,5 });
	friendly_npc Shop_keeper("Shop Keeper", {3,1});
	weapon long_sword(true, "long sword", { 1,5 }, 10);
	win_object w("winner", "X", {8,10}, true);

	//this solution works for now
	std::ifstream map1("first_area.txt");
	std::string line;
	std::getline(map1,line);
	int x = stoi(line);
	std::getline(map1,line);
	int y = stoi(line);

	//here it passes the remander of the stream to the playing field object.
	playing_field first_area(x,y, map1);
	first_area.update_game_tiles(&Jon);
	first_area.update_game_tiles(&Strider);
	first_area.update_game_tiles(&Shop_keeper);
	first_area.update_game_tiles(&long_sword);
	first_area.update_game_tiles(&w);

	first_area.print_playing_field(true, false);

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
			first_area.print_playing_field(false, false);
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