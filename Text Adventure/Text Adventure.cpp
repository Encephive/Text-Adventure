// Text Adventure.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "TextAdventure.h"

uint8_t first{ 0 };
uint8_t second{ 0 };
uint8_t* first_ptr{ &first };
uint8_t* second_ptr{ &second };

int main()
{
	Game game;
	game.Init();

	while (!game.Play()) {};

    //game.Play();
}
