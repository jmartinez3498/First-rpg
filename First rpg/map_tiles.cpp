#include <vector>
#include <string>
#include <iostream>
#include "map_tiles.h"
#include "map_object.h"

map_tiles::map_tiles(bool _boundary_tile) :boundary_tile(_boundary_tile), map_object_present(false), win_location(false) {
	if (boundary_tile == true) {
		tile_string_representation = "#";
		traversable = false;
	}
	else {
		tile_string_representation = ".";
		traversable = true;
	}
	_map_object = nullptr;
	_weapon = nullptr;
	map_object_present = false;
}

void map_tiles::update_tile() {
	if (_map_object != nullptr)
		tile_string_representation = _map_object->get_tile_string_representation();
	else if (_weapon != nullptr)
		tile_string_representation = _weapon->get_tile_string_representation();
	else if (win_location)
		tile_string_representation = "W";
	else
		tile_string_representation = ".";
}

void map_tiles::place_map_object(map_object* _map_object) {
	map_tiles::_map_object = _map_object;
	map_object_present = true;
}

void map_tiles::place_weapon(weapon* _weapon) {
	map_tiles::_weapon = _weapon;
	map_object_present = true;
}

void map_tiles::remove_map_object() {
	_map_object = nullptr;
	map_object_present = false;
}

std::string map_tiles::get_map_object_type() {
	return _map_object->get_object_type();
}

std::string map_tiles::get_weapon_type() {
	return _weapon->get_object_type();
}