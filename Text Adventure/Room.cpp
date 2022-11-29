#include "Room.h"
#include <iostream>

int Room::MonsterCount()
{
	return monsters_count;
}
int Room::TreasureCount()
{
	return treasures_count;
}

void Room::SetNeighbours(Room& room)
{
	if (room.GetCoordinates().y > coordinates.y)
	{
		room_up = &room;
	}
	else if (room.GetCoordinates().y < coordinates.y)
	{
		room_down = &room;
	}
	else if (room.GetCoordinates().x < coordinates.x)
	{
		room_left = &room;
	}
	else if (room.GetCoordinates().x > coordinates.x)
	{
		room_right = &room;
	}
}

std::vector<Room*> Room::GetNeighbours()
{
	std::vector<Room*> neighbours{};

	if (room_up)
	{
		neighbours.push_back(room_up);
	}
	if (room_down)
	{
		neighbours.push_back(room_down);
	}
	if (room_left)
	{
		neighbours.push_back(room_left);
	}
	if (room_right)
	{
		neighbours.push_back(room_right);
	}
	return neighbours;
}


bool Room::ValidDirection(Direction dir)
{
	switch (dir)
	{
	case Direction::Up:
		return room_up!=nullptr;
	case Direction::Down:
		return room_down != nullptr;
	case Direction::Left:
		return room_left != nullptr;
	case Direction::Right:
		return room_right != nullptr;
	default:
		std::cerr << "INVALID DIRECTION" << std::endl;
		return false;
	}
}

Coordinates Room::GetNeighbour(Direction dir)
{
	switch (dir)
	{
	case Direction::Up:
		if (room_up)
		{
			return room_up->GetCoordinates();
		}
		break;
	case Direction::Down:
		if (room_down)
		{
			return room_down->GetCoordinates();
		}
		break;
	case Direction::Left:
		if (room_left)
		{
			return room_left->GetCoordinates();
		}
		break;
	case Direction::Right:
		if (room_right)
		{
			return room_right->GetCoordinates();
		}
		break;
	default:
		std::cerr << "UNKNOWN DIRECTION" << std::endl;
		return this->GetCoordinates();
		break;
	}
	return this->GetCoordinates();
}

bool Room::IsEndRoom()
{
	return is_end_room;
}



Coordinates Room::GetCoordinates()
{
	return coordinates;
}


float Room::KillMonster(int damage)
{
	if (monsters_count <= 0)
	{
		std::cerr << "TRYING TO KILL MONSTERS BUT THERE IS NONE";
		return 0;
	}
	else 
	{
		monsters_count = (damage > monsters_count ? 0 : monsters_count - damage);
		return monsters_count;
	}
}
int Room::LootTreasure()
{
	uint8_t treasure{ treasures_count };
	treasures_count = 0;
	return treasure;
}