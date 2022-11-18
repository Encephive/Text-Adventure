#include "Game.h"
#include <iostream>
#include <string>
#include "Room.h"

void Game::Init()
{
	//GenerateGrid(hor, ver);
	system("CLS");

	std::cout << "Hello and welcome in this adventure, enter the name of your mighty hero : " << std::endl;
	std::string name{};
	std::cin.clear();
	getline(std::cin, name);
	player.SetName(name);
	std::cout << "Great ! Your name is " << player.GetName() << ", you have " << player.GetHealth() << " health points, and have a score of " << player.GetScore() << " points." << std::endl;
	
	system("pause");
}


bool Game::Play()
{
	current_room = &player.Turn();
	if (player.GetHealth() > 0)
	{
		return current_room->IsEndRoom();
	}
	else
	{
		return true;
	}
}

void Game::GenerateGrid(int horizontal, int vertical)
{
	//for (int h{ 0 }; h < horizontal; ++h)
	//{
	//	std::vector<Room> column{};
	//	for (int v{ 0 }; v < vertical; ++v)
	//	{
	//		Room room{RoomType::Monster, h, v};
	//		column.push_back(room);
	//	}
	//	level.grid.push_back(column);
	//}
	std::vector<Room> row_one{};			// Up    Down  Left  Right
	row_one.push_back(Room(RoomType::Void,0,0,false, true, true, false));
	row_one.push_back(Room(RoomType::Treasure,0,1,false, false, true, false));
	row_one.push_back(Room(RoomType::Monster,0,2,true, false, true, false));

	std::vector<Room> row_two{};
	row_two.push_back(Room(RoomType::Treasure, 1, 0, false, true, false, false));
	row_two.push_back(Room(RoomType::Monster, 1, 1, false, false, false, false));
	row_two.push_back(Room(RoomType::Treasure, 1, 2, true, false, false, false));

	std::vector<Room> row_three{};
	row_three.push_back(Room(RoomType::Monster, 2, 0, false, true, false, true));
	row_three.push_back(Room(RoomType::Treasure, 2, 1, false, false, false, true));
	row_three.push_back(Room(RoomType::Void, 2, 2, true, false, false, true, true));


	level.grid.push_back(row_one);
	level.grid.push_back(row_two);
	level.grid.push_back(row_three);
}
