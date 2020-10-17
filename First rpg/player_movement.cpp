#include <vector>
#include <string>
#include <iostream>
#include "player_movement.h"

void player_movement::move_right() {
	character_location[0] = character_location[0] + 1;
}

void player_movement::move_left() {
	character_location[0] = character_location[0] - 1;
}

void player_movement::move_up() {
	character_location[1] = character_location[1] - 1;
}

void player_movement::move_down() {
	character_location[1] = character_location[1] + 1;
}


