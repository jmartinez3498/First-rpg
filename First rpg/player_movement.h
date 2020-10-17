#pragma once


class player_movement {

public:
	player_movement(std::vector<int*> _character_location) : character_location(_character_location) {}
	void move_right();
	void move_left();
	void move_up();
	void move_down();
	void update_current_location();
	void update_previous_location();


private:
	std::vector<int*> character_location;
};
