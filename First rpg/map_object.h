#pragma once


class map_object {

public:
	map_object(std::string _object_name, std::string _object_type) : object_name(_object_name), object_type(_object_type) {}
	std::string get_object_name() { return object_name; }
	std::string get_object_type() { return object_type; }
private:
	const std::string object_name;
	const std::string object_type;
};

class character : map_object {

public:
	character(std::string _character_name, int _life, int _strength, int _defense) : character_name(_character_name), 
		life(_life), strength(_strength), defense(_defense),
		map_object(_character_name, "character") {}
	character(std::string _character_name) : character_name(_character_name), life(NULL), strength(NULL), defense(NULL),
		map_object(_character_name, "character") {}
	std::string get_character_name() { return character_name; }
	int get_life() {return life; }
	int get_strength() { return strength; }
	int get_defense() { return defense; }
private:
	const std::string character_name;
	const int life;
	const int strength;
	const int defense;
};
class player_hero : character {

public:
	player_hero(std::string _character_name, int _life, int _strength, int _defense) : playable(true),
	character(_character_name, _life, _strength, _defense) {}
private:
	bool playable;
};

class enemy_npc : character {

public:
	enemy_npc(std::string _character_name, int _life, int _strength, int _defense) : playable(false), hostile(true),
	character(_character_name, _life, _strength, _defense) {}
private:
	bool playable;
	bool hostile;
};

class friendly_npc : character {

public:
	friendly_npc(std::string _character_name) : playable(false), hostile(false),
	character(_character_name) {}
private:
	bool playable;
	bool hostile;

};

