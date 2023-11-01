// Main.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <SFML/Main.hpp>
#include <SFML/Graphics.hpp>

int main()
{

	sf::Vector2<float> Vitesse;
	sf::Vector2f JumpFocre;

	sf::RenderWindow window(sf::VideoMode(1200, 600), "Window");

	sf::RectangleShape PlayerBox(sf::Vector2f(15, 15));
	PlayerBox.setFillColor(sf::Color(46, 46, 255));
	PlayerBox.setOutlineThickness(3);
	PlayerBox.setOutlineColor(sf::Color(23, 23, 255));

	window.setFramerateLimit(60);

	PlayerBox.setPosition(10, 0);

	while (window.isOpen())
	{

		window.clear();

		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				window.close();
			}

			if (event.type == sf::Event::KeyPressed)
			{

			}

		}

		JumpFocre = sf::Vector2f(0.0f, 0.0f);

		bool IsGrounded = false;
		IsGrounded = PlayerBox.getPosition().y >= (window.getSize().y - PlayerBox.getSize().y) - 10;

		if ( sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
		{
			if(IsGrounded)
			{
				JumpFocre = sf::Vector2f(0.0f, -9.0f);
			}
		}

		if (!IsGrounded)
		{
			float force = 0.91f;
			Vitesse += sf::Vector2f(0, force);
		}
		else
		{
			Vitesse = sf::Vector2f(0, 0);

		}

		Vitesse += JumpFocre;

		std::cout << "Pos : " << PlayerBox.getPosition().x << " : " << PlayerBox.getPosition().y << std::endl;
		std::cout << "Speed : " << Vitesse.y << std::endl;
		PlayerBox.setPosition(PlayerBox.getPosition() + Vitesse);

		window.draw(PlayerBox);

		window.display();
	}
}
