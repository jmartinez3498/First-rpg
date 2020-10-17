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
	void place_weapon(weapon* _weapon);
	void remove_map_object();
	void place_win_location() { win_location = true; }
	void update_tile();
	std::string get_map_object_type();
	std::string get_weapon_type();
	map_object* get_map_object() {return _map_object; }
	weapon* get_weapon() { return _weapon; }
	
	
private:
	bool boundary_tile;
	bool traversable;
	bool map_object_present;
	bool win_location;
	std::string tile_string_representation;
	map_object* _map_object;
	weapon* _weapon;

};