#pragma once
#include "Room.h"
#include "Player.h"
#include "Level.h"
#include <vector>



class Game
{
public:
	void Init();
	bool Play();

	//Game() : level{}, room{ Room{RoomType::Void,0,0,false, true, true, false} }, player{ room, 10 } {std::cout << "Game Constructed" << std::endl; }
	Game() : level{}, player{ level.StartingRoom(), 10 }, last_room{ player.GetCoordinates() } {std::cout << "Game Constructed" << std::endl; }
private:
	bool InputAction(std::string action);

#pragma region Dungeon
	void Loot();
	void Attack();
	void Flee();
#pragma endregion

	void Move(Direction dir);
	void Move(Coordinates coor);
	void Turn();

	const int hor{ 10 }, ver{ 10 };
	Level level;
	Player player;
	Coordinates last_room;
};

