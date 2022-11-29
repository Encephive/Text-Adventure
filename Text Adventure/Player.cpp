#include "Player.h"

void Player::Move(Coordinates coor)
{
	coordinates = coor;
}

void Player::SetName(std::string name)
{
	player_name = name;
}
std::string& const Player::GetName()
{
	return player_name;
}

int Player::GetScore()
{
	return score;
}
int Player::GetHealth()
{
	return health;
}

int Player::GetDamage()
{
	return weapon.GetDamage();
}

void Player::Loot(int loot)
{
	score += loot;
}

Coordinates& Player::GetCoordinates()
{
	return coordinates;
}

void Player::TakeDamage(int damage)
{
	health = (damage > health ? 0 : health - damage);
}
