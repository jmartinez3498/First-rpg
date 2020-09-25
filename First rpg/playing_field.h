#pragma once


//Playing field is a map containing the x & y dimensions
//Do I even need to have all this mumbo jumbo if I create the playing_field size myself???
//I wanted to create a separate play movement class except I couldn't figure out how to make pointers to a vector value if that value is changing

class playing_field {

public:
	playing_field() : x_dim(10), y_dim(10), game_tiles(10, std::vector<std::string>(10, ".")), starting_location({ 0,0 }),
		current_location({ 0,0 }), win_location({ 9,9 }) {}
	playing_field(const int _x_dim) : x_dim(_x_dim), y_dim(10), game_tiles(_x_dim, std::vector<std::string> (10, ".")),
		starting_location({ 0,0 }), current_location({ 0,0 }), win_location({ 9,9 }) {}
	playing_field(const int _x_dim, const int _y_dim) : x_dim(_x_dim), y_dim(_y_dim),
		game_tiles(_x_dim,std::vector<std::string> (_y_dim, ".")), starting_location({ 0,0 }), current_location({ 0,0 }),
		win_location({ 9,9 }) {}
	int get_x_dim() { return x_dim; }
	int get_y_dim() { return y_dim; }
	std::vector<int> get_starting_location() { return starting_location; }
	std::vector<int> get_current_location() { return current_location; }
	void print_playing_field();
	void update_win_location();
	void update_current_location();
	void update_previous_location();
	void move_right();
	void move_left();
	void move_up();
	void move_down();
	bool win_game();

protected:

private:
	const int x_dim;
	const int y_dim;
	std::vector<int> starting_location;
	std::vector<int> current_location;
	std::vector<std::vector<std::string>> game_tiles;
	std::vector<int> win_location;


};

/*
class player_movement {

public:
	//player_movement() : current_location(get_starting_location()) {}
	void move_right() { current_location[0] = current_location[0] + 1; };
	void move_left() { current_location[0] = current_location[0] - 1; }
	void move_up() { current_location[1] = current_location[1] + 1; }
	void move_down() { current_location[1] = current_location[1] - 1; }


private:
	std::vector<int> previous_location;
};
*/