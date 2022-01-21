#include <vector>
#include <string>
#include <iostream>
#include "map_object.h"

void map_object::set_map_coordinates(std::vector<int> _map_coordinates) {
	map_coordinates = _map_coordinates;
}

void map_object::move(std::string& _direction){
	std::vector<int> map_coords;
	map_coords = this->get_map_coordinates();
	//quick fix for directions. keep for now
	if (_direction == "a")
		map_coords[1] = map_coords[1] - 1;
	else if (_direction == "d")
		map_coords[1] = map_coords[1] + 1;
	else if (_direction == "s")
		map_coords[0] = map_coords[0] + 1;
	else if (_direction == "w")
		map_coords[0] = map_coords[0] - 1;

	this->set_map_coordinates(map_coords);

}

void map_object::print_stats() {
	std::cout<<this->get_object_name();
}

void map_object::attack(map_object* object){

}

void map_object::defend(map_object* object){

}

int map_object::get_life(){
	return -1;
}

void map_object::set_life(int _life){

}

bool map_object::is_dead(){
	return false;
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

/*
for future reference:
we pass the map_object instead of a weapon because that allows the function
to work with the map objects passed onto the playing field object since the game tiles
contain a vector of map objects. Then we convert to a weapon which allows us to 
use the weapon functions.
Note: there is no splicing because we are pointing to a weapon object with a map object
pointer.
An alternative approach is using pure virtual functions in my map_object class
*/
void character::equip_weapon(map_object* object){
	equiped_weapon = (weapon*) object;
	strength = strength + equiped_weapon->get_item_power();
}

//lets use the pure virtual functions here just to see how they work
void character::attack(map_object* object){
	int x = object->get_life() - this->get_strength();
	object->set_life(x);
	object->print_stats();
}

void character::defend(map_object* object){
	std::cout << object->get_life();
}

bool character::is_dead(){
	if (this->get_life() <= 0){
		std::cout << this->get_object_name() << " was defeated \n";
		return true;
	}
	else{
		return false;
	}
}