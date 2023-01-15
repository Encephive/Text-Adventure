#pragma once
#include "Room.h"
#include "GameStructs.h"
#include "Weapon.h"



class Player
{
public:

	void SetName(std::string name);
	const std::string& const GetName() const;
	const int GetHealth() const;
	const int GetScore() const;
	const int GetDamage() const;
	const Coordinates GetCoordinates() const;

	void Move(Coordinates coor);
	void Loot(int loot);
	void TakeDamage(int damage);

	Player(Coordinates coor, int h) 
		: coordinates{ coor }, health{ h }, score{ 0 }, weapon{ "Basic Sword", 1 }
	{
		std::cout << "Player Constructed" << std::endl;
	}

private:

	Weapon weapon;
	int health;
	int score;
	Coordinates coordinates;
	std::string player_name;
};