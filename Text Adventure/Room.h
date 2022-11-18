#pragma once
#include "Tools.h"
#include "GameStructs.h"
#include <iostream>
#include <vector>

enum class RoomType {Monster, Treasure, Void};
enum class Direction { Up, Down, Left, Right };

class Room
{
public:

	int MonsterCount();
	int TreasureCount();

	float KillMonster(int damage);
	int LootTreasure();

	bool ValidDirection(Direction dir);
	bool IsEndRoom();

	void SetNeighbours(Room &room);

	std::vector<Room*> GetNeighbours();
	Room* GetNeighbour(Direction dir);

	Coordinates& const GetCoordinates();



	Room(RoomType t, int x, int y, bool end = false, bool up = false, bool down = false, bool left = false, bool right = false)
		:type{ t }, coordinates { x, y }, is_end_room{ end }, wall_up{ up }, wall_down{ down }, wall_left{ left }, wall_right{ right }, 
		room_up{nullptr}, room_down{ nullptr }, room_left{ nullptr }, room_right{ nullptr }, monsters_count{ 0 }, treasures_count{ 0 }
	{
		switch (type)
		{
		case RoomType::Monster:
			monsters_count = tool::RandomInt(3,5);
			treasures_count = monsters_count * tool::RandomInt(1, 3);
			break;

		case RoomType::Treasure:
			treasures_count = tool::RandomInt(1, 5);
			break;

		case RoomType::Void:
			break;

		default:
			std::cerr << "Unknown Room Type" << std::endl;
			break;
		}
		std::cout << "Room Constructed" << std::endl;

	}

private:
	RoomType type;
	Coordinates coordinates;
	uint8_t monsters_count;
	uint8_t treasures_count;
	Room* room_up; 
	Room* room_down;
	Room* room_left;
	Room *room_right;
	bool is_end_room, wall_up, wall_down, wall_left, wall_right;
};

