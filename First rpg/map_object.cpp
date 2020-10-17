#include <vector>
#include <string>
#include <iostream>
#include "map_object.h"

void map_object::change_map_coordinates(std::vector<int> _map_coordinates) {
	map_coordinates = _map_coordinates;
}

void map_object::print_stats() {
	std::cout<<this->get_object_name();
}

void item::print_stats() {
	std::cout << this->get_object_name();
}

void weapon::print_stats() {
	item::print_stats();
	std::cout << this->get_item_power();
}

void shield::print_stats() {
	item::print_stats();
	std::cout << this->get_shield_rating();
}

void character::print_stats() {
	std::cout << this->get_object_name() << " ";
	std::cout << "Life: " << this->get_life() << " ";
	std::cout << "Strength: "<<this->get_strength() << " ";
	std::cout << "Defense: "<<this->get_defense() << "\n";
}

void character::equip_weapon(weapon* _weapon) {
	equiped_weapon = _weapon;
	strength = strength + equiped_weapon->get_item_power();
}