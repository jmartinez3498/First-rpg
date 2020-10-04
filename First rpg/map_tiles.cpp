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
}

void map_tiles::update_tile() {
	if (_map_object != nullptr)
		tile_string_representation = _map_object->get_tile_string_representation();
	else if (map_object_present)
		tile_string_representation = "X";
	else if (win_location)
		tile_string_representation = "W";
	else
		tile_string_representation = ".";
}

void map_tiles::place_map_object(map_object* _map_object) {
	map_tiles::_map_object = _map_object;
}

void map_tiles::remove_map_object() {
	//_map_object = nullptr;
	map_object_present = false;
}