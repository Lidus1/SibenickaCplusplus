#pragma once

#include "Hra.h"
#include "Menu.h"

void start()  // na��t� vizu�ln� a audio prvky
{
    Zapni Zap; 
    Zap.Nacti();
    Zap.Otevri();  // otev�e okno
    
    sf::RenderWindow& window = Zap.getOkno(); 
    sf::Font& font = Zap.getFont();

    Menu(window, font); 
}
