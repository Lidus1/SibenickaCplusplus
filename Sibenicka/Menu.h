#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include "Hangman.h"

void Pomoc(sf::RenderWindow& window, sf::Font & font)

{
	Zapni zap;
	zap.Nacti();

	sf::Text radek1("   Save your life!",font, 50);
	sf::Text radek2(" Guess the letters in the words!", font, 30);
	sf::Text radek3("Use letter keys to select letters", font, 30);
	
	sf::Texture west = zap.getwest();
	sf::Sprite western(west);

	 

	radek1.setPosition(200, 150); 
	radek2.setPosition(200, 250);   
	radek3.setPosition(200, 320);
	 

	while (window.isOpen())  // okno je otevøené
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
			else if (event.type == sf::Event::KeyPressed) // do stisknutí klávey
			{

				if (event.key.code == sf::Keyboard::Enter) // Enter
				
				{
					return;
				}

			}

		

		}
		window.clear(sf::Color::Black);
		window.draw(western);

		window.draw(radek1);
		window.draw(radek2);
		window.draw(radek3);
		

		window.display();
	}
	


}


	void Menu(sf::RenderWindow & window, sf::Font & font) 
	{
		Zapni zap;
		zap.Nacti();


		sf::Text moznost1("PLAY", font, 30);
		sf::Text moznost2("HELP", font, 30);
		sf::Text moznost3("EXIT", font, 30);
		sf::Texture west = zap.getwest(); 
		sf::Sprite western(west);

		zap.getvsude().setLoop(true);   // hudba

		zap.getvsude().play(); 
		
		
		//800, 800, 
		moznost1.setPosition(350, 300);
		moznost2.setPosition(350, 400);
		moznost3.setPosition(350, 500);

		int moznost = 0;

		while (window.isOpen()) // pohyb v menu
		{
			sf::Event event;

			while (window.pollEvent(event))
			{
				if (event.type == sf::Event::Closed)
					window.close();
				else if (event.type == sf::Event::KeyPressed)
				{
					if (event.key.code == sf::Keyboard::Up)
					{
						moznost--;
						if (moznost < 0)
							moznost = 2;
					}

					else if (event.key.code == sf::Keyboard::Down)
					{
						moznost++;
						if (moznost > 2)
							moznost = 0;
					}

					else if (event.key.code == sf::Keyboard::Enter) // volba možnosti
					{
						switch (moznost)
						{
						case 0:
							Hangman(window);
								break;
						case 1:
							Pomoc(window,font);
							break;
						case 2:
							window.close();
							break;


						}
					}



				}


			}


			window.clear(sf::Color::Black);
			window.draw(western);

			window.draw(moznost1);
			window.draw(moznost2);
			window.draw(moznost3);

			moznost1.setFillColor(sf::Color::White);
			moznost2.setFillColor(sf::Color::White);
			moznost3.setFillColor(sf::Color::White);

			switch (moznost) // grafický ukazatel zvolené možnosti
			{
			case 0:
				moznost1.setFillColor(sf::Color::Red);
				break;
			case 1:
				moznost2.setFillColor(sf::Color::Red);
				break;
			case 2:
				moznost3.setFillColor(sf::Color::Red);


			}
		
			window.display();
		}

	}
