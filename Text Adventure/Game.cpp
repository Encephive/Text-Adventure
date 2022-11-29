#include "Game.h"

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

	Turn();
	if (player.GetHealth() > 0)
	{
		return level.GetRoom(player.GetCoordinates())->IsEndRoom();
	}
	else
	{
		return true;
	}
}

void Game::Turn()
{
	system("CLS");

	std::cout << "Name : " << player.GetName() << " || Health Points : " << player.GetHealth() << " || Score : " << player.GetScore() << std::endl;
	std::cout << "You enter a room : Position[" << level.GetRoom(player.GetCoordinates())->GetCoordinates().x << "," << level.GetRoom(player.GetCoordinates())->GetCoordinates().y << "]." << std::endl << std::endl;
	std::cout << "Last coordinates : Position[" << last_room.x << "," << last_room.y << "]." << std::endl;
	for (Room* room : level.GetRoom(player.GetCoordinates())->GetNeighbours())
	{
		std::cout << "Neighbour room at Position[" << room->GetCoordinates().x << "," << room->GetCoordinates().y << "]." << std::endl;
	}

	std::string player_action{ "" };

	if (level.GetRoom(player.GetCoordinates())->MonsterCount() > 0)
	{
		std::cout << "You see : " << level.GetRoom(player.GetCoordinates())->MonsterCount() << " monster(s)." << std::endl;
		player_action += "Flee ? \n";
		player_action += "Attack ? \n";
	}
	else
	{
		player_action += "Do you move";
		if (level.GetRoom(player.GetCoordinates())->ValidDirection(Direction::Up))
		{
			player_action += ", Up";
		}
		if (level.GetRoom(player.GetCoordinates())->ValidDirection(Direction::Right))
		{
			player_action += ", Right";
		}
		if (level.GetRoom(player.GetCoordinates())->ValidDirection(Direction::Down))
		{
			player_action += ", Down";
		}
		if (level.GetRoom(player.GetCoordinates())->ValidDirection(Direction::Left))
		{
			player_action += ", Left";
		}
		player_action += " ?\n";
	}

	if (level.GetRoom(player.GetCoordinates())->TreasureCount() > 0)
	{
		std::cout << "You see : " << level.GetRoom(player.GetCoordinates())->TreasureCount() << " treasure(s)." << std::endl;
		if (level.GetRoom(player.GetCoordinates())->MonsterCount() == 0)
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
		std::getline(std::cin, action);
	} while (!InputAction(action));
}

bool Game::InputAction(std::string action)
{
	std::cout << "Action : " << action << std::endl;
	bool valid_action{ false };
	if (level.GetRoom(player.GetCoordinates())->MonsterCount() == 0)
	{
		if (action == "Left")
		{
			if (level.GetRoom(player.GetCoordinates())->ValidDirection(Direction::Left))
			{
				valid_action = true;
				Move(Direction::Left);
			}
		}
		else if (action == "Right")
		{
			if (level.GetRoom(player.GetCoordinates())->ValidDirection(Direction::Right))
			{
				valid_action = true;
				Move(Direction::Right);
			}
		}
		else if (action == "Up")
		{
			if (level.GetRoom(player.GetCoordinates())->ValidDirection(Direction::Up))
			{
				valid_action = true;
				Move(Direction::Up);
			}
		}
		else if (action == "Down")
		{
			if (level.GetRoom(player.GetCoordinates())->ValidDirection(Direction::Down))
			{
				valid_action = true;
				Move(Direction::Down);
			}
		}
		else if (action == "Loot")
		{
			if (level.GetRoom(player.GetCoordinates())->TreasureCount() > 0)
			{
				valid_action = true;
				Loot();
				std::cout << "You loot the treasure and your score is now : " << player.GetScore()<< std::endl;
				system("pause");

			}
		}
	}
	else if (action == "Attack")
	{
		valid_action = true;
		std::cout << "You attack and kill a monster." << std::endl;
		Attack();
		if (level.GetRoom(player.GetCoordinates())->MonsterCount() > 0)
		{
			std::cout << "There are " << level.GetRoom(player.GetCoordinates())->MonsterCount() << " remaining monster(s) deal damage. You now have " << player.GetHealth() << " health points." << std::endl;
			if (player.GetHealth() == 0)
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
		Flee();
		std::cout << "You Flee back to the last room." << std::endl;
		system("pause");
	}

	if (!valid_action)
	{
		std::cout << "Action not valid. Enter a valid action please" << std::endl;
	}
	return valid_action;
}

void Game::Move(Direction dir)
{
	last_room = player.GetCoordinates();
	player.Move(level.GetRoom(player.GetCoordinates())->GetNeighbour(dir));
	if (level.GetRoom(player.GetCoordinates())->IsEndRoom())
	{
		std::cout << "Congratulations ! You reached the end room. Your final score is : " << player.GetScore() << std::endl;
	}
}

void Game::Move(Coordinates coor)
{
	Coordinates temp_room{ player.GetCoordinates() };
	player.Move(last_room);
	last_room = temp_room;
}

void Game::Loot()
{
	player.Loot(level.GetRoom(player.GetCoordinates())->LootTreasure());
}

void Game::Attack()
{
	float damage_back{ std::ceil(level.GetRoom(player.GetCoordinates())->KillMonster(player.GetDamage()) / 2) };
	player.TakeDamage(damage_back);
}

void Game::Flee()
{
	Move(last_room);
}

