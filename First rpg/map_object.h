#pragma once


class map_object {

public:
	map_object(const std::string& _object_name, const std::string &_object_type, const std::string& _tile_string_representation, std::vector<int> _map_coordinates) : 
		object_name(_object_name), object_type(_object_type), tile_string_representation(_tile_string_representation),
		map_coordinates{ _map_coordinates }{}
	std::string get_object_name() { return object_name; }
	std::string get_object_type() { return object_type; }
	std::vector<int> get_map_coordinates() { return map_coordinates; }
	std::string get_tile_string_representation() { return tile_string_representation; }
	void change_map_coordinates(std::vector<int> _map_coordinates);
	virtual void print_stats();

private:
	const std::string object_name;
	const std::string object_type;
	std::string tile_string_representation;
	std::vector <int> map_coordinates;

};

class item : public map_object {

public:
	item(bool _equipable,const std::string& _item_name, const std::string& _tile_string_representation, std::vector<int> _map_coordinates):
		equipable(_equipable),
		map_object(_item_name, "item", _tile_string_representation, _map_coordinates) {}
	void print_stats();
private:
	bool equipable;
};

class weapon : public item {
public:
	weapon(bool _equipable, const std::string& _item_name, std::vector<int> _map_coordinates, int _item_power) :
		item_power(_item_power),
		item(_equipable, _item_name,"W", _map_coordinates) {}
	void print_stats();
	int get_item_power() { return item_power; }
private:
	int item_power;
};

class shield : public item {
public:
	shield(bool _equipable, const std::string& _item_name, std::vector<int> _map_coordinates, int _shield_rating) :
		equipable(_equipable), shield_rating(_shield_rating),
	item(_equipable, _item_name,"S", _map_coordinates){}
	void print_stats();
	int get_shield_rating() { return shield_rating; }
private:
	bool equipable;
	int shield_rating;
};

class character : public map_object{

public:
	character(const std::string& _character_name, int _life, int _strength, int _defense, const std::string& _tile_string_representation, std::vector<int> _map_coordinates) : life(_life), strength(_strength), defense(_defense), equiped_weapon(nullptr),
		map_object(_character_name, "character", _tile_string_representation, _map_coordinates) {}
	character(const std::string& _character_name, const std::string& _tile_string_representation, std::vector<int> _map_coordinates) : life(NULL), strength(NULL), defense(NULL), equiped_weapon(nullptr),
		map_object(_character_name, "character", _tile_string_representation, _map_coordinates) {}
	int get_life() {return life; }
	int get_strength() { return strength; }
	int get_defense() { return defense; }
	void print_stats();
	void equip_weapon(weapon* weapon);
private:
	const int life;
	int strength;
	const int defense;
	weapon* equiped_weapon;
};
class player_hero : public character {

public:
	player_hero(const std::string& _character_name, int _life, int _strength, int _defense, std::vector<int> _map_coordinates) : playable(true),
	character(_character_name, _life, _strength, _defense, "P", _map_coordinates) {}
private:
	bool playable;

};

class enemy_npc : public character {

public:
	enemy_npc(const std::string& _character_name, int _life, int _strength, int _defense, std::vector<int> _map_coordinates) : playable(false), hostile(true),
	character(_character_name, _life, _strength, _defense, "E", _map_coordinates) {}
private:
	bool playable;
	bool hostile;
};

class friendly_npc : public character {

public:
	friendly_npc(const std::string& _character_name, std::vector<int> _map_coordinates) : playable(false), hostile(false),
	character(_character_name, "N", _map_coordinates) {}
private:
	bool playable;
	bool hostile;

};

