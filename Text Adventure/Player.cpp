#include "Player.h"

void Player::Move(Coordinates coor)
{
	coordinates = coor;
}

void Player::SetName(std::string name)
{
	player_name = name;
}
const std::string& const Player::GetName() const
{
	return player_name;
}

const int Player::GetScore() const
{
	return score;
}

const int Player::GetHealth() const
{
	return health;
}

const int Player::GetDamage() const
{
	return weapon.GetDamage();
}

void Player::Loot(int loot)
{
	score += loot;
}

const Coordinates Player::GetCoordinates() const
{
	return coordinates;
}

void Player::TakeDamage(int damage)
{
	health = (damage > health ? 0 : health - damage);
}
