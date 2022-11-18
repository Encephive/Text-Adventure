#pragma once
#include "Room.h"
#include "GameStructs.h"
#include "Weapon.h"
#include <vector>



class Player
{
public:
	Room& Turn();

	void TakeDamage(int damage);
	void SetName(std::string name);
	std::string& const GetName();
	int GetHealth();
	int GetScore();


	Player(Room& room, int h) 
		: current_room{ &room }, last_room{ current_room }, coordinates{ current_room->GetCoordinates() }, health{ h }, score{ 0 }, weapon{ "Basic Sword", 1 },
		  up {current_room->ValidDirection(Direction::Up)}, down {current_room->ValidDirection(Direction::Down)},
		  left {current_room->ValidDirection(Direction::Left)}, right {current_room->ValidDirection(Direction::Right)}
	{
		std::cout << "Player Constructed" << std::endl;
	}

private:
	void ComputeValidMoves();
	void Move(Direction dir);
	void Move(Room& room);
	void Attack(Room& room);
	void Loot(Room& room);
	bool InputAction(std::string action);

	Room* current_room;
	Room* last_room;
	Weapon weapon;
	Coordinates& GetCoordinates();
	int health;
	int score;
	Coordinates coordinates;
	bool up, down, left, right;
	std::string player_name;
};