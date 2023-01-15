#pragma once
#include <string>
class Weapon
{
public:
	Weapon(std::string n, int d) : name{ n }, damage{ d } {};

	const int GetDamage() const;

private:
	std::string name{};
	int damage{};
};

