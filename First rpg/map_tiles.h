#pragma once

class map_object;
class weapon;

//stuff
class map_tiles {

public:
	map_tiles(bool _boundary_tile);
	std::string get_tile_string_representation() { return tile_string_representation; }
	bool is_traversable() { return traversable; }
	bool has_map_object() { return map_object_present; }
	void place_map_object() { map_object_present = true; }
	void place_map_object(map_object* _map_object);
	void remove_map_object();
	void update_tile();
	std::string get_map_object_type();
	map_object* get_map_object() {return object; }
	
	
private:
	bool boundary_tile;
	bool traversable;
	bool map_object_present;
	std::string tile_string_representation;
	map_object* object;

};