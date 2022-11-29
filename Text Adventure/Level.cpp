#include "Level.h"

Room* Level::GetRoom(Coordinates coordinates)
{
	return &grid[coordinates.x][coordinates.y];
}

Coordinates Level::StartingRoom()
{
	return grid[0][0].GetCoordinates();
}

