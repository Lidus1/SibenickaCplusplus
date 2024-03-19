#pragma once

#include "Hra.h"
#include "Menu.h"

void start()  // naèítá vizuální a audio prvky
{
    Zapni Zap; 
    Zap.Nacti();
    Zap.Otevri();  // otevøe okno
    
    sf::RenderWindow& window = Zap.getOkno(); 
    sf::Font& font = Zap.getFont();

    Menu(window, font); 
}
