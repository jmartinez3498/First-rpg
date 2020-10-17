#include <vector>
#include <string>
#include <iostream>
#include "playing_field.h"
#include "map_tiles.h"
#include "map_object.h"

playing_field::playing_field(): x_dim(10), y_dim(10), starting_location({ 0,0 }), current_location({ 0,0 }), win_location({ 9,9 }) {

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

void playing_field::update_win_location() {
	game_tiles[win_location[0]][win_location[1]]->place_win_location();
	game_tiles[win_location[0]][win_location[1]]->update_tile();
}

void playing_field::update_current_location(character* _map_object) {
	game_tiles[_map_object->get_map_coordinates()[0]][_map_object->get_map_coordinates()[1]]->place_map_object(_map_object);
	game_tiles[_map_object->get_map_coordinates()[0]][_map_object->get_map_coordinates()[1]]->update_tile();
}

void playing_field::update_previous_location(character* _map_object) {
	game_tiles[_map_object->get_map_coordinates()[0]][_map_object->get_map_coordinates()[1]]->remove_map_object();
	game_tiles[_map_object->get_map_coordinates()[0]][_map_object->get_map_coordinates()[1]]->update_tile();
}

void playing_field::move(character* _character, std::string& _direction) {
	std::vector<int> map_coords;
	map_coords = _character->get_map_coordinates();
	if (_direction == "a")
		map_coords[0] = map_coords[0] - 1;
	else if (_direction == "d")
		map_coords[0] = map_coords[0] + 1;
	else if (_direction == "s")
		map_coords[1] = map_coords[1] + 1;
	else if (_direction == "w")
		map_coords[1] = map_coords[1] - 1;
	bool collision_flag = false;
	collision_flag = this->collision_check(_direction, map_coords);
	if (collision_flag) {
		if (game_tiles[map_coords[0]][map_coords[1]]->get_weapon_type() == "item") {
			_character->equip_weapon(game_tiles[map_coords[0]][map_coords[1]]->get_weapon());
			this->update_previous_location(_character);
			_character->change_map_coordinates(map_coords);
			this->update_current_location(_character);
		}
		else
			std::cout << "cant move here\n";
	}
	else {
		this->update_previous_location(_character);
		_character->change_map_coordinates(map_coords);
		this->update_current_location(_character);
	}
	this->print_playing_field();

	true;
}

bool playing_field::collision_check(std::string& _direction, std::vector<int>& _map_coords) {
	return game_tiles[_map_coords[0]][_map_coords[1]]->has_map_object();
}


bool playing_field::win_game() {
	if (current_location == win_location)
		return true;
	else
		return false;
}

void playing_field::place_map_object(map_object* _map_object) {
	game_tiles[_map_object->get_map_coordinates()[0]][_map_object->get_map_coordinates()[1]]->place_map_object(_map_object);
	game_tiles[_map_object->get_map_coordinates()[0]][_map_object->get_map_coordinates()[1]]->update_tile();
}

void playing_field::place_weapon(weapon* _weapon) {
	game_tiles[_weapon->get_map_coordinates()[0]][_weapon->get_map_coordinates()[1]]->place_weapon(_weapon);
	game_tiles[_weapon->get_map_coordinates()[0]][_weapon->get_map_coordinates()[1]]->update_tile();
}
