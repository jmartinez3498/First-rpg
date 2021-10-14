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
	void print_playing_field(bool valid_move);
	void update_game_tiles(map_object* _map_object, std::vector<int>& _map_coords);
	void update_game_tiles(map_object* _map_object);
	void update_map(map_object* _character, std::string& _direction);
	bool collision_check(std::vector<int>& _map_coords);
	void set_win_game(bool flag);
	bool get_win_game_flag();

private:
	const int x_dim;
	const int y_dim;
	std::vector<std::vector<map_tiles*>> game_tiles;
	bool win_game_flag;

};