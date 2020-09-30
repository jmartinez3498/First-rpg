#pragma once

class map_object;

//stuff
class map_tiles {

public:
	map_tiles(bool _boundary_tile);
	//Notice that I cannot cout << map_tile
	//I can either overload or create a get_tile_string_representation();
	std::string get_tile_string_representation() { return tile_string_representation; }
	bool is_traversable() { return traversable; }
	bool has_map_object() { return map_object_present; }
	void place_map_object() { map_object_present = true; }
	void remove_map_object() { map_object_present = false; }
	void place_win_location() { win_location = true; }
	void update_tile();
	

private:
	bool boundary_tile;
	bool traversable;
	bool map_object_present;
	bool win_location;
	std::string tile_string_representation;
	map_object* _map_object;

};