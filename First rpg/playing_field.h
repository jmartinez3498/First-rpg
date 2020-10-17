#pragma once

class map_tiles;
class map_object;
class character;
class weapon;

class playing_field {

public:
	playing_field();
	int get_x_dim() { return x_dim; }
	int get_y_dim() { return y_dim; }
	std::vector<int> get_starting_location() { return starting_location; }
	std::vector<int> get_current_location() { return current_location; }
	void print_playing_field();
	void update_win_location();
	void update_current_location(character* _map_object);
	void update_previous_location(character* _map_object);
	void move(character* _character, std::string& _direction);
	bool collision_check(std::string& _direction, std::vector<int>& _map_coords);
	bool win_game();
	void place_map_object(map_object* _map_object);
	void place_weapon(weapon* _weapon);

private:
	const int x_dim;
	const int y_dim;
	std::vector<int> starting_location;
	std::vector<int> current_location;
	std::vector<std::vector<map_tiles*>> game_tiles;
	std::vector<int> win_location;
	//std::vector<map_object*> _map_objects; maybe??
};