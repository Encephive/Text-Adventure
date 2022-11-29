#pragma once
#include "Room.h"
#include "GameStructs.h"
#include <stdio.h>
#include <vector>

class Level
{
public:
	Level()
	{
		std::cout << "Level Constructor" << std::endl;
		std::vector<Room> row_one{};
		row_one.push_back(Room(RoomType::Void, 0, 0));
		row_one.push_back(Room(RoomType::Treasure, 0, 1));
		row_one.push_back(Room(RoomType::Monster, 0, 2));

		std::vector<Room> row_two{};
		row_two.push_back(Room(RoomType::Treasure, 1, 0));
		row_two.push_back(Room(RoomType::Monster, 1, 1));
		row_two.push_back(Room(RoomType::Treasure, 1, 2));

		std::vector<Room> row_three{};
		row_three.push_back(Room(RoomType::Monster, 2, 0));
		row_three.push_back(Room(RoomType::Treasure, 2, 1));
		row_three.push_back(Room(RoomType::Void, 2, 2, true));


		grid.push_back(row_one);
		grid.push_back(row_two);
		grid.push_back(row_three);

		int vertical_limit{ 3 };
		int horizontal_limit{ 3 };

		std::cout << "Before linking neighbours" << std::endl;

		for (size_t horizontal{ 0 }; horizontal < horizontal_limit; ++horizontal)
		{
			for (size_t vertical{ 0 }; vertical < vertical_limit; ++vertical)
			{
				if ((horizontal + 1) < horizontal_limit)
				{
					grid[horizontal + 1][vertical].SetNeighbours(grid[horizontal][vertical]);
				}
				if ((horizontal) > 0)
				{
					grid[horizontal - 1][vertical].SetNeighbours(grid[horizontal][vertical]);
				}
				if ((vertical + 1) < vertical_limit)
				{
					grid[horizontal][vertical + 1].SetNeighbours(grid[horizontal][vertical]);
				}
				if ((vertical) > 0)
				{
					grid[horizontal][vertical - 1].SetNeighbours(grid[horizontal][vertical]);
				}
			}
		}

		std::cout << "After linking neighbours" << std::endl;
	}

	Room* GetRoom(Coordinates coordinates);
	Coordinates StartingRoom();


private : 
	std::vector<std::vector<Room>> grid{};
};