#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include "playing_field.h"
#include "map_tiles.h"
#include "map_object.h"

playing_field::playing_field(int _x_dim, int _y_dim, std::ifstream& _map): x_dim(_x_dim), y_dim(_y_dim), win_game_flag(false), lost_game_flag(false) {



	if (_map.is_open())
	{
		//parse each line in the map doc
		//i think it would be better to get the dimensions of the doc
		//so I don't have to change the logic below for out of bounds
		std::string line;

		while ( std::getline (_map,line)){
			//parse each character in the map doc
			//with this logic, it creates 10 vectors with 20 items each
			//i.e. 10 rows with 20 columns
			std::vector<map_tiles*> _tile;
			for(int i = 0; i < line.length(); ++i){
				//if not equal to . or # check map line[i]
				_tile.push_back(new map_tiles(false, line[i]));
			}

			game_tiles.push_back(_tile);
		}
		_map.close();
	}
	else{
		std::cout<< "Unable to open file";
	}
	
}

void playing_field::print_playing_field(bool valid_move, bool _bounds_flag){
	//empty lines to make command line look nicer
	for (int i = 0; i < 10; ++i) {
		std::cout << "\n";
	}

	if (valid_move == false){
		std::cout<<"cant move here: invalid move."<<std::endl;
	}
	if (_bounds_flag == true){
		std::cout<<"cant move here: out of bounds"<<std::endl;
	}
	//for printing, we have to iterate through each row y and print out
	//x columns because command line prints left to right, up to down
	for (int j = 0; j < y_dim; ++j) {
		for (int i = 0; i < x_dim; ++i) {
			std::cout << game_tiles[j][i]->get_tile_string_representation();
		}
		std::cout << "\n";
	}
}

void playing_field::update_game_tiles(map_object* _map_object, std::vector<int>& _prev_map_coords){
	//updates current location
	std::vector<int> map_coords = _map_object->get_map_coordinates();
	game_tiles[map_coords[0]][map_coords[1]]->place_map_object(_map_object);
	game_tiles[map_coords[0]][map_coords[1]]->update_tile();

	//updates previous location
	game_tiles[_prev_map_coords[0]][_prev_map_coords[1]]->remove_map_object();
	game_tiles[_prev_map_coords[0]][_prev_map_coords[1]]->update_tile();
}

void playing_field::update_game_tiles(map_object* _map_object){
	std::vector<int> map_coords = _map_object->get_map_coordinates();
	game_tiles[map_coords[0]][map_coords[1]]->place_map_object(_map_object);
	game_tiles[map_coords[0]][map_coords[1]]->update_tile();
}

void playing_field::update_map(map_object* _map_object, std::string& _direction) {
	std::vector<int> prev_map_coords;
	std::vector<int> new_map_coords;
	prev_map_coords = _map_object->get_map_coordinates();
	_map_object->move(_direction);
	new_map_coords = _map_object->get_map_coordinates();

	bool collision_flag = false;
	bool bounds_flag = false;
	bool wall_flag = false;
	bounds_flag = this->out_of_bounds(new_map_coords);
	wall_flag = game_tiles[new_map_coords[0]][new_map_coords[1]]->is_traversable();
	if (bounds_flag == true){
		_map_object->set_map_coordinates(prev_map_coords);
		this->print_playing_field(true, bounds_flag);
	}
	else if (wall_flag == false) {
		_map_object->set_map_coordinates(prev_map_coords);
		this->print_playing_field(false, bounds_flag);
	}
	else{
		collision_flag = this->collision_check(new_map_coords);
		if (collision_flag == true) {
			if (game_tiles[new_map_coords[0]][new_map_coords[1]]->get_map_object_type() == "weapon") {

				//checks if the map object is a character. Invalid if not a character
				//then equips the item
				if (_map_object->get_object_type() == "player_hero"){
					//another instance of using casting so we don't have to use virtual functions
					character* _character = (character*)_map_object;
					_character->equip_weapon(game_tiles[new_map_coords[0]][new_map_coords[1]]->get_map_object());
					this->update_game_tiles(_character, prev_map_coords);
					this->print_playing_field(true, bounds_flag);
				}
				else{
					std::cout<<"invalid: not a player hero";
				}
			}
			//checks if we ran into the win object
			else if (game_tiles[new_map_coords[0]][new_map_coords[1]]->get_map_object_type() == "win_object"){
				this->set_win_game(true);
				this->update_game_tiles(_map_object, prev_map_coords);
				this->print_playing_field(true, bounds_flag);
			}
			//else the item is either a friendly npc or enemy
			//need logic for when npc is friendly
			else if (game_tiles[new_map_coords[0]][new_map_coords[1]]->get_map_object_type() == "enemy_npc"){
				
				_map_object->attack(game_tiles[new_map_coords[0]][new_map_coords[1]]->get_map_object());
				//check if enemy died
				if (game_tiles[new_map_coords[0]][new_map_coords[1]]->get_map_object()->is_dead()){
					this->update_game_tiles(_map_object, prev_map_coords);
					this->print_playing_field(true, bounds_flag);
				}
				//enemy still alive and attacks back
				else{
					game_tiles[new_map_coords[0]][new_map_coords[1]]->get_map_object()->attack(_map_object);
					//need a check to see if hero is dead
					if (_map_object->is_dead()){
						//do nothing
					}
					else{
						_map_object->set_map_coordinates(prev_map_coords);
						this->print_playing_field(false, bounds_flag);
					}

				}

			}
		}
		else {
			this->update_game_tiles(_map_object, prev_map_coords);
			this->print_playing_field(true, bounds_flag);
		}
	}

}

bool playing_field::collision_check(std::vector<int>& _map_coords) {
	bool collision_flag = false;

	if (game_tiles[_map_coords[0]][_map_coords[1]]->has_map_object()){
		collision_flag = true;
	}

	return collision_flag;
}

void playing_field::set_win_game(bool flag) {
	win_game_flag = flag;
}

bool playing_field::out_of_bounds(std::vector<int>& _map_coords){
	bool bounds_flag = false;
	if (_map_coords[0] < 0 || _map_coords[0] >= x_dim || _map_coords[1] < 0 || _map_coords[1] >= y_dim){
		bounds_flag = true;
	}
	return bounds_flag;
}

