#include <vector>
#include <string>
#include <iostream>
#include "playing_field.h"
#include "map_tiles.h"
#include "map_object.h"


playing_field::playing_field(): x_dim(10), y_dim(10), starting_location({ 0,0 }), current_location({ 0,0 }), win_location({ 9,9 }) {

	for (int i = 1; i <= 10; ++i) {
		std::vector<map_tiles*> _tile;
		for (int j = 1; j <= 10; ++j) {
			_tile.push_back(new map_tiles(false));
		}
		game_tiles.push_back(_tile);
	}
}



void playing_field::print_playing_field() {
	for (int i = 0; i < 10; ++i) {
		std::cout << "\n";
	}

	for (int j = 0; j < y_dim; ++j) {
		for (int i = 0; i < x_dim; ++i) {
			std::cout << game_tiles[i][j]->get_tile_string_representation();
		}
		std::cout << "\n";
	}

}

void playing_field::update_win_location() {
	game_tiles[win_location[0]][win_location[1]]->place_win_location();
	game_tiles[win_location[0]][win_location[1]]->update_tile();
}

void playing_field::update_current_location() {
	game_tiles[current_location[0]][current_location[1]]->place_map_object();
	game_tiles[current_location[0]][current_location[1]]->update_tile();
}

void playing_field::update_previous_location() {
	game_tiles[current_location[0]][current_location[1]]->remove_map_object();
	game_tiles[current_location[0]][current_location[1]]->update_tile();
}

void playing_field::move_right() {
	this->update_previous_location();
	current_location[0] = current_location[0] + 1; 
	this->update_current_location();
	this->print_playing_field();
}

void playing_field::move_left() {
	this->update_previous_location();
	current_location[0] = current_location[0] - 1;
	this->update_current_location();
	this->print_playing_field();
}

void playing_field::move_up() {
	this->update_previous_location();
	current_location[1] = current_location[1] - 1;
	this->update_current_location();
	this->print_playing_field();
}

void playing_field::move_down() {
	this->update_previous_location();
	current_location[1] = current_location[1] + 1;
	this->update_current_location();
	this->print_playing_field();
}

bool playing_field::win_game() {
	if (current_location == win_location)
		return true;
	else
		return false;
}

void playing_field::place_map_object(map_object* _map_object) {
	std::vector<int> map_coords;
	map_coords = _map_object->get_map_coordinates();
	game_tiles[map_coords[0]][map_coords[1]]->place_map_object(_map_object);
	//game_tiles[map_coords[0]][map_coords[1]]->update_tile();
}

