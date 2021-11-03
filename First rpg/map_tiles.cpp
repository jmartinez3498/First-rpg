#include <vector>
#include <string>
#include <iostream>
#include "map_tiles.h"
#include "map_object.h"

map_tiles::map_tiles(bool _boundary_tile, char c): boundary_tile(_boundary_tile), map_object_present(false) {
	tile_string_representation = c;
	if (tile_string_representation == "#"){
		traversable = false;
	}
	else{
		traversable = true;
	}
	object = nullptr;

}

void map_tiles::update_tile() {
	if (object != nullptr)
		tile_string_representation = object->get_tile_string_representation();
	else
		tile_string_representation = ".";
}

void map_tiles::place_map_object(map_object* _map_object) {
	object = _map_object;
	map_object_present = true;
}


void map_tiles::remove_map_object() {
	object = nullptr;
	map_object_present = false;
}

std::string map_tiles::get_map_object_type() {
	return object->get_object_type();
}
