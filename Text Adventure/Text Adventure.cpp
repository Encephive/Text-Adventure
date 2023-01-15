// Text Adventure.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <SFML/Graphics.hpp>
//#include "TextAdventure.h"

uint8_t first{ 0 };
uint8_t second{ 0 };
uint8_t* first_ptr{ &first };
uint8_t* second_ptr{ &second };

int main()
{
    sf::RenderWindow window(sf::VideoMode(800,800), "Test");
    sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Green);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        window.draw(shape);
        window.display();
    }

    return 0;
	//Game game;
	//game.Init();

	//while (!game.Play()) {};

    //game.Play();
}
