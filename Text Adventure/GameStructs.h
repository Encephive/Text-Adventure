#pragma once

struct Coordinates
{
	int x;
	int y;

	Coordinates() : x{ 0 }, y{ 0 } {};
	Coordinates(int x_coor, int y_coor) : x{ x_coor }, y{ y_coor } {}
};
