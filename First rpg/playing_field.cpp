#include <vector>
#include <string>
#include <iostream>
#include "playing_field.h"
#include "map_tiles.h"
#include "map_object.h"

playing_field::playing_field(): x_dim(10), y_dim(10), win_game_flag(false) {

	for (int i = 1; i <= 10; ++i) {
		std::vector<map_tiles*> _tile;
		for (int j = 1; j <= 10; ++j) {
			_tile.push_back(new map_tiles(false));
		}
		game_tiles.push_back(_tile);
	}
}

void playing_field::print_playing_field() {
	for (int i = 0; i < 10; ++i) {
		std::cout << "\n";
	}

	for (int j = 0; j < y_dim; ++j) {
		for (int i = 0; i < x_dim; ++i) {
			std::cout << game_tiles[i][j]->get_tile_string_representation();
		}
		std::cout << "\n";
	}

}

void playing_field::print_playing_field(bool valid_move){
	for (int i = 0; i < 10; ++i) {
		std::cout << "\n";
	}

	if (valid_move == false){
		std::cout<<"cant move here: invalid move."<<std::endl;
	}
	for (int j = 0; j < y_dim; ++j) {
		for (int i = 0; i < x_dim; ++i) {
			std::cout << game_tiles[i][j]->get_tile_string_representation();
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

void playing_field::update(map_object* _map_object, std::string& _direction) {
	std::vector<int> prev_map_coords;
	std::vector<int> new_map_coords;
	prev_map_coords = _map_object->get_map_coordinates();
	_map_object->move(_direction);
	new_map_coords = _map_object->get_map_coordinates();

	bool collision_flag = false;
	collision_flag = this->collision_check(_direction, new_map_coords);
	if (collision_flag == true) {
		if (game_tiles[new_map_coords[0]][new_map_coords[1]]->get_map_object_type() == "item") {
			if (_map_object->get_object_type() == "character"){
				character* _character = (character*)_map_object;
				_character->equip_weapon(game_tiles[new_map_coords[0]][new_map_coords[1]]->get_map_object());
				this->update_game_tiles(_character, prev_map_coords);
				this->print_playing_field();
			}
			else{
				std::cout<<"invalid";
			}
		}
		else if (game_tiles[new_map_coords[0]][new_map_coords[1]]->get_map_object_type() == "win_object"){
			this->set_win_game(true);
			this->update_game_tiles(_map_object, prev_map_coords);
			this->print_playing_field();
		}
		else{
			_map_object->change_map_coordinates(prev_map_coords);
			this->print_playing_field(false);
		}
	}
	else {
		this->update_game_tiles(_map_object, prev_map_coords);
		this->print_playing_field();
	}

}

bool playing_field::collision_check(std::string& _direction, std::vector<int>& _map_coords) {
	return game_tiles[_map_coords[0]][_map_coords[1]]->has_map_object();
}


void playing_field::set_win_game(bool flag) {
	win_game_flag = flag;
}

bool playing_field::get_win_game_flag(){
	return win_game_flag;
}

