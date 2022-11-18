#include "Player.h"


Room& Player::Turn()
{
	system("CLS");

	std::cout << "Name : " << player_name << " || Health Points : " << health << " || Score : " << score << std::endl;
	std::cout << "You enter a room : Position[" << coordinates.x << "," << coordinates.y << "]." << std::endl << std::endl;

	for (Room* room : current_room->GetNeighbours())
	{
		std::cout << "Neighbour room at Position[" << room->GetCoordinates().x << "," << room->GetCoordinates().y << "]." << std::endl;
	}

	ComputeValidMoves();
	std::string player_action{ "" };

	if (current_room->MonsterCount() > 0)
	{
		std::cout << "You see : " << current_room->MonsterCount() << " monster(s)." << std::endl;
		player_action += "Flee ? \n";
		player_action += "Attack ? \n";
	}
	else 
	{
		player_action += "Do you move";
		if (up)
		{
			player_action += ", Up";
		}
		if (right)
		{
			player_action += ", Right";
		}
		if (down)
		{
			player_action += ", Down";
		}
		if (left)
		{
			player_action += ", Left";
		}
		player_action += " ?\n";
	}

	if (current_room->TreasureCount() > 0)
	{
		std::cout << "You see : " << current_room->TreasureCount() << " treasure(s)." << std::endl;
		if (current_room->MonsterCount() == 0)
		{
			player_action += "Loot ? \n";
		}
	}

	player_action += "\n\nWhat do you do ? \n";
	std::cout << player_action;
	std::string action{};
	do 
	{
		std::cin.clear();
		std::getline(std:: cin, action);
	} while (!InputAction(action));

	return *current_room;
}

void Player::ComputeValidMoves()
{
	up = current_room->ValidDirection(Direction::Up);
	down = current_room->ValidDirection(Direction::Down);
	left = current_room->ValidDirection(Direction::Left);
	right = current_room->ValidDirection(Direction::Right);
}

bool Player::InputAction(std::string action)
{
	std::cout << "Action : " << action << std::endl;
	bool valid_action{ false };
	if (current_room->MonsterCount() == 0)
	{
		if (action == "Left")
		{
			if (left)
			{
				valid_action = true;
				Move(Direction::Left);
			}
		}
		else if (action == "Right")
		{
			if (right)
			{
				valid_action = true;
				Move(Direction::Right);
			}
		}
		else if (action == "Up")
		{
			if (up)
			{
				valid_action = true;
				Move(Direction::Up);
			}
		}
		else if (action == "Down")
		{
			if (down)
			{
				valid_action = true;
				Move(Direction::Down);
			}
		}
		else if (action == "Loot")
		{
			if (current_room->TreasureCount() > 0)
			{
				valid_action = true;
				Loot(*current_room);
				std::cout << "You loot the treasure and your score is now : " << score << std::endl;
				system("pause");

			}
		}
	}
	else if (action == "Attack")
	{
		valid_action = true;
		std::cout << "You attack and kill a monster." << std::endl;
		Attack(*current_room);
		if (current_room->MonsterCount() > 0)
		{
			std::cout << "There are " << current_room->MonsterCount() << " remaining monster(s) deal damage. You now have " << health << " health points." << std::endl;
			if (health == 0)
			{
				std::cout << "You are dead." << std::endl;
			}
		}
		else
		{
			std::cout << "You've killed every monster in the room. You can now loot the treasure !" << std::endl;
		}
		system("pause");
	}
	else if (action == "Flee")
	{
		valid_action = true;
		Move(*last_room);
		std::cout << "You Flee back to the last room." << std::endl;
		system("pause");
	}

	if (!valid_action)
	{
		std::cout << "Action not valid. Enter a valid action please" << std::endl;
	}
	return valid_action;
}


void Player::Move(Direction dir)
{
	last_room = current_room;
	current_room = current_room->GetNeighbour(dir);
	coordinates = current_room->GetCoordinates();
	if (current_room->IsEndRoom())
	{
		std::cout << "Congratulations ! You reached the end room. Your final score is : " << score << std::endl;
	}
}

void Player::Move(Room& room)
{
	Room* temp_room{ current_room };
	current_room = last_room;
	last_room = temp_room;
	coordinates = current_room->GetCoordinates();
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

void Player::Attack(Room& room)
{
	TakeDamage(std::ceil(room.KillMonster(weapon.GetDamage()) / 2));
}

void Player::Loot(Room& room)
{
	score += room.LootTreasure();
}

Coordinates& Player::GetCoordinates()
{
	return coordinates;
}

void Player::TakeDamage(int damage)
{
	health = (damage > health ? 0 : health - damage);
}
