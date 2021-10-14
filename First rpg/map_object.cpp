#include <vector>
#include <string>
#include <iostream>
#include "map_object.h"

void map_object::change_map_coordinates(std::vector<int> _map_coordinates) {
	map_coordinates = _map_coordinates;
}

void map_object::move(std::string& _direction){
	std::vector<int> map_coords;
	map_coords = this->get_map_coordinates();
	if (_direction == "a")
		map_coords[0] = map_coords[0] - 1;
	else if (_direction == "d")
		map_coords[0] = map_coords[0] + 1;
	else if (_direction == "s")
		map_coords[1] = map_coords[1] + 1;
	else if (_direction == "w")
		map_coords[1] = map_coords[1] - 1;

	this->change_map_coordinates(map_coords);

}

void map_object::print_stats() {
	std::cout<<this->get_object_name();
}

void item::print_stats() {
	std::cout << this->get_object_name() << ": ";
}

void weapon::print_stats() {
	item::print_stats();
	std::cout << this->get_item_power() << " strength";
}

void shield::print_stats() {
	item::print_stats();
	std::cout << this->get_shield_rating();
}

void character::print_stats() {
	map_object::print_stats();
	std::cout << " ";
	std::cout << "Life: " << this->get_life() << " ";
	std::cout << "Strength: "<<this->get_strength() << " ";
	std::cout << "Defense: "<<this->get_defense() << "\n";
	if (this->equiped_weapon != nullptr){
		std::cout << "Equiped weapon: ";
		this->get_weapon()->print_stats();
		std::cout << "\n";
	}
}

void character::equip_weapon(map_object* object){
	equiped_weapon = (weapon*) object;
	strength = strength + equiped_weapon->get_item_power();
}