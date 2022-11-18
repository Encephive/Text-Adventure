#pragma once
#include <string>
class Weapon
{
public:
	Weapon(std::string n, int d) : name{ n }, damage{ d } {};

	int GetDamage();

private:
	std::string name{};
	int damage{};
};

