#include <vector>
#include <string>
#include <iostream>
#include "map_tiles.h"

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
	if (map_object_present)
		tile_string_representation = "X";
	else if (win_location)
		tile_string_representation = "W";
	else
		tile_string_representation = ".";
}