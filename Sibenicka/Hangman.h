#pragma once

#include <SFML/Graphics.hpp>
#include "HangmanF.h"
#include "Hra.h"
#include <SFML/Audio.hpp>



int vyberObtiznost(sf::RenderWindow& okno)
{
    int volba = 0;
    Zapni Zap;
    Zap.Nacti();

    sf::Texture lehka;
    sf::Texture stredni;
    sf::Texture tezka;
    sf::Texture west;


    sf::Sprite lehkaSprite(Zap.getLehka());
    sf::Sprite stredniSprite(Zap.getStredni());
    sf::Sprite tezkaSprite(Zap.getTezka());
    sf::Sprite western(Zap.getwest());

    int xsour = 50;  // poèáteèní souøadnice
    int ysour = 50;

    lehkaSprite.setPosition(xsour + 10.0f, ysour + 100.0f);    // umístìní obrázkù obtížností
    stredniSprite.setPosition(xsour + 260.0f, ysour + 100.0f);
    tezkaSprite.setPosition(xsour + 510.0f, ysour + 100.0f);

    sf::RectangleShape ukazatel(sf::Vector2f(200.0f, 200.0f));
    ukazatel.setFillColor(sf::Color(0, 0, 0, 0)); // transparentní
    ukazatel.setOutlineThickness(5.0f);
    ukazatel.setOutlineColor(sf::Color::Red); // èervený okraj


    while (okno.isOpen())
    {
        sf::Event event;
        while (okno.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                okno.close();
                return 0;
            }

            if (event.type == sf::Event::KeyPressed) // pohyb mezi obtížnostmi
            {
                if (event.key.code == sf::Keyboard::Left)
                {
                    volba = (volba - 1 + 3) % 3;
                }
                else if (event.key.code == sf::Keyboard::Right)
                {
                    volba = (volba + 1) % 3;
                }
                else if (event.key.code == sf::Keyboard::Enter) // volba
                {
                    return volba;
                }
            }
        }


        okno.clear(sf::Color::Black);
        okno.draw(western);

        okno.draw(lehkaSprite);
        okno.draw(stredniSprite);
        okno.draw(tezkaSprite);
        float ukazatelXPozice = xsour + 10.0f + volba * 250.0f;   // pohyb ukazatele
        float ukazatelYPozice = ysour + 100.0f;


        ukazatel.setPosition(ukazatelXPozice, ukazatelYPozice);

        okno.draw(ukazatel); // vykreslení ukazatele

        okno.display();


    }
    return volba; // vrací obtížnost

}


void Hangman(sf::RenderWindow& okno)  // pomocná pøechodová funkce
{
	

	Zapni Zapi;
	Zapi.Nacti();
	int obtiznost = vyberObtiznost(okno);
    Hra(okno, obtiznost);
	
}




