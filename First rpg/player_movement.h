#pragma once


class player_movement {

public:
	player_movement() : _current_location() {}
	void move_right();
	void move_left();
	void move_up();
	void move_down();
	void update_current_location();
	void update_previous_location();


private:
	std::vector<int*> _current_location;
};
