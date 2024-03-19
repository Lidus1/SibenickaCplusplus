#pragma once

#include <SFML/Graphics.hpp>
#include "Hra.h"
#include <vector>
#include <iostream>
#include "Slovar1.h"
#include <fstream>


void drawtext(sf::RenderWindow& window, const std::vector<char>& playerword, sf::Font font)   // vykresluje obsah vektoru playerguess - vektor #
{
    sf::Text text;
    text.setFont(font);
    text.setCharacterSize(static_cast<unsigned int>(50));
    text.setFillColor(sf::Color::White);

    
    std::string displayText(playerword.begin(), playerword.end());  // pøevedení obsahu vektoru na string
    text.setString(displayText);

    
    text.setPosition(450, 100);

    
    window.draw(text);
}
void drawzivot(sf::RenderWindow& window, int life)   // podle životù se zmmìní pozadí 
{
    Zapni zap;
    zap.Nacti();

    sf::Texture texture;

    switch (life)
    {
    case 0:
        texture = zap.getwest();
        break;

    case 1:
        texture = zap.getZiv1();
        break;
    case 2:
        texture = zap.getZiv2();
        break;
    case 3:
        texture = zap.getZiv3();
        break;
    case 4:
        texture = zap.getZiv4();
        break;
    case 5:
        texture = zap.getZiv5();
        break;
    case 6:
        texture = zap.getZiv6();
        break;
    case 7:
        texture = zap.getZiv7();
        break;
    case 8:
        texture = zap.getZiv8();
        break;
    case 9:
        texture = zap.getZiv9();
        break;
    case 10:
        texture = zap.getZiv10();
        break;

    default:
        texture = zap.getwest();
        break;
    }

    sf::Sprite sprite(texture);
    
    window.draw(sprite);
    
}


int guessedword(std::vector<char>& playerword, std::vector<char>& wordcharacters, const std::vector<char>& guess, int life)
{
    bool matchFound = false;

    
    for (int i = 0; i < wordcharacters.size(); ++i)    // hledá ve vektoru slova schodu se stisknutým písmenem
    {
        
        for (char c : guess)
        {
            if (wordcharacters[i] == c)          // pokud ji najde, tak ve vektoru slova zamìní toto písmeno za # a zároveò zamìní ve vektoru z # # za písmeno
            {
                
                playerword[i] = c;
                wordcharacters[i] = '#';
                matchFound = true;
            }
        }
    }

    
    if (!matchFound)    // pokud shodu nenajde,, ubere se život 
    {
        life++;
    }

    return life;
}

void drawKeys(sf::RenderWindow& window, sf::Font font)  // vykreslení písmen na klávesnici
{
    sf::Text text;
    float tileSize = 60.0f;
    text.setFont(font);
    text.setCharacterSize(static_cast<unsigned int>(tileSize * 0.4f)); // velikost textu
    text.setFillColor(sf::Color::Black);

    std::vector<char> row1 = { 'Q', 'W', 'E', 'R', 'T', 'Z', 'U', 'I', 'O', 'P' };
    std::vector<char> row2 = { 'A', 'S', 'D', 'F', 'G', 'H', 'J', 'K', 'L' };
    std::vector<char> row3 = { 'Y', 'X', 'C', 'V', 'B', 'N', 'M' };

    float startX = (800.0f - (row1.size() * tileSize)) / 2.0f; 
    float startY = 515.0f; // zarovnání
    float spacing = 10.0f; // mezery mezi písmeny

    float currentX = startX;
    float currentY = startY;

    
    for (char c : row1) {
        text.setString(std::string(1, c)); // pøevedení char na string
        text.setPosition(currentX-25, currentY);
        window.draw(text);
        currentX += tileSize + spacing;
    }


    currentX = startX;
    currentY += tileSize + spacing;

    
    startX = (800.0f - (row2.size() * tileSize)) / 2.0f; // zarovnání písmen 2. øádek
    for (char c : row2) {
        text.setString(std::string(1, c)); // pøevedení char na string
        text.setPosition(currentX+10, currentY);
        window.draw(text);
        currentX += tileSize + spacing;
    }

    currentX = startX;
    currentY += tileSize + spacing;

    
    startX = (800.0f - (row3.size() * tileSize)) / 2.0f; // zarovnání písmen 3. øádek
    for (char c : row3) {
        text.setString(std::string(1, c)); // pøevedení na string
        text.setPosition(currentX+50, currentY);
        window.draw(text);
        currentX += tileSize + spacing;
    }
}

void drawKeyboard(sf::RenderWindow& window, std::vector<char>& row1, std::vector<char>& row2, std::vector<char>& row3) 
{
    float tileSize = 60.0f;     // velikost kláves
    float spacing = 10.0f;      // velikost mezer
    int offsetY = 500;          // pozice klávesnice

    
    int row1Width = row1.size() * tileSize + (row1.size() - 1) * spacing;    // šíøky øádkù
    int row2Width = row2.size() * tileSize + (row2.size() - 1) * spacing;
    int row3Width = row3.size() * tileSize + (row3.size() - 1) * spacing;

   
    int totalWidth = std::max({ row1Width, row2Width, row3Width });  // podle nejdelšího øádku najde koneèné zarovnání na støed

    int offsetX = (window.getSize().x - totalWidth) / 2;    // zarovnání na støed

    for (int row = 0; row < 3; row++)   // urèuje, který øádek klávesnice se vykresluje
    {
        const std::vector<char>& currentRow = (row == 0) ? row1 : ((row == 1) ? row2 : row3);

        
        int currentRowWidth = currentRow.size() * tileSize + (currentRow.size() - 1) * spacing;

        
        int rowOffsetX = offsetX + (totalWidth - currentRowWidth) / 2;

        for (int col = 0; col < currentRow.size(); ++col) //vykresluje jednotlivé klávesy
        {
            sf::RectangleShape tile(sf::Vector2f(tileSize, tileSize));

            switch (currentRow[col]) {
            case ' ':
                tile.setFillColor(sf::Color(200, 200, 200)); 
                break;
            case '#':
                tile.setFillColor(sf::Color::Black);  // pokud je ve vektoru # (stisknutá) tak se klávesa vykreslí èernì
                break;
            default:
                tile.setFillColor(sf::Color(150, 150, 150));  // pokud klávesa není stisknutá, je šedá
            }

            // øeší umístìní jednotlivých kláves
            tile.setPosition(rowOffsetX + col * (tileSize + spacing), offsetY + row * (tileSize + spacing));
            window.draw(tile);
        }
    }
}
int scoretracker(std::vector<char>& guess, std::vector<char>& wordcharacters, std::vector<int>& streak, int score)
{

    bool matchFound = false;    
    
    
    for (int i = 0; i < wordcharacters.size(); ++i)   // hledá ve vektoru slova schodu se stisknutým písmenem
    {
        
        for (char c : guess)
        {
            if (wordcharacters[i] == c)
            {
                
               
                matchFound = true;
            }
        }
    }

    
    if (!matchFound)    // pokud se shoda nenajde, násobiè skóre se vynuluje a vrátí se nezmìnìné skóre
    {
        streak.clear();
        streak.push_back(0);
        
        return score;

    }
    
    streak[0]++;          // pokud se shoda najde, zvýší se násobiè o 1 a skóre se zvýší o násobiè      
    score += streak[0];
  
    
    return score;
}

std::vector<int> gettop(int score)
{
    
    std::ifstream inputFile("score.txt");  // soubor pro ukládání skóre
    std::vector<int> scores;                // vektor pro ukládání skóre

    if (inputFile) 
    {
        
        int value;
        for (int i = 0; i < 2 && inputFile >> value; ++i) {
            scores.push_back(value);        //pøidat skore do vektoru
        }

        
        inputFile.close();
    }
    else {
        std::cerr << "Failed to open score.txt for reading" << std::endl;
        return {}; 
    }
    scores.push_back(score);        // pøidá momentílné skore do vektoru

    std::sort(scores.rbegin(), scores.rend());  // sežadí skóre

    scores.resize(std::max(3, static_cast<int>(scores.size())));  // ukládat pouze 3 nejvìtší skore

    std::ofstream clearFile("score.txt", std::ios::trunc);   
    clearFile.close();

    
    std::ofstream writeFile("score.txt", std::ios::app);  // otevøe soubor se skore a obnoví skore
    if (writeFile) {
        
        for (int value : scores) {
            writeFile << value << std::endl;
        }

        
        writeFile.close();
    }
    else {
        std::cerr << "Failed to open score.txt for writing" << std::endl;
        return {};
    }

    
   
    return scores;
}




void Hra(sf::RenderWindow& window, int difficulty) 
{
    Zapni zap;
    zap.Nacti();

    sf::Font font = zap.getFont();
    std::vector<char> row1 = { 'Q', 'W', 'E', 'R', 'T', 'Z', 'U', 'I', 'O', 'P' };    // klávesnice
    std::vector<char> row2 = { 'A', 'S', 'D', 'F', 'G', 'H', 'J', 'K', 'L' };
    std::vector<char> row3 = { 'Y', 'X', 'C', 'V', 'B', 'N', 'M' };
    std::vector<char> wordCharacters(3, '#');  // souvisí s logikou hry
    std::vector<char> playerGuess(3, '#');
    std::vector<char> guess = { '#' };
    std::vector <int> streak = { 0 }; //násobiè skóre
    char chosenChar;
    Slovar slov(difficulty);
    int life = 0;
    int score = 0;

    switch (difficulty) // podle obtížnosti se zvolí poèáteèní životy
    {
    case 0:
        life = 0;
        break;
    case 1:
    case 2:
        life = 4;
        break;
    default:
        
        break;
    }

    while (window.isOpen()) {
        bool keyPressed = false;    // definice 
        sf::Event event;
        if (std::count(wordCharacters.begin(), wordCharacters.end(), '#') == wordCharacters.size()) { // pokud se poèet # rovná délce vektoru hádaného slova 
            
            slov.getfinalword(wordCharacters, playerGuess, difficulty); // vyvolaná fce z Slovar1.h
            row1.clear();    // obnovení klávesnice po uhádnutí slova 
            row2.clear();
            row3.clear();
            std::vector<char>rrow1 = { 'Q', 'W', 'E', 'R', 'T', 'Z', 'U', 'I', 'O', 'P' };
            std::vector<char>rrow2 = { 'A', 'S', 'D', 'F', 'G', 'H', 'J', 'K', 'L' };
            std::vector<char>rrow3 = { 'Y', 'X', 'C', 'V', 'B', 'N', 'M' };
            row1 = rrow1;
            row2 = rrow2;
            row3 = rrow3;
            
        }
        
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
            else if (event.type == sf::Event::KeyPressed) {  // po stisknutí klávesy se zaznamená stisknutá klávesa do pressedKey
                char pressedKey = ' ';

                if (event.key.code >= sf::Keyboard::A && event.key.code <= sf::Keyboard::Z) {   // pokud je stisknutá klávesa v rozmezí od A do Z, zapíše se do chosenChar 
                    pressedKey = static_cast<char>('A' + (event.key.code - sf::Keyboard::A));
                    chosenChar = pressedKey;

                    
                    auto radek1 = std::find(row1.begin(), row1.end(), chosenChar);    // hledání, ve kterém vektoru vektoru se nachází chosenChar a na jaké pozici
                    auto radek2 = std::find(row2.begin(), row2.end(), chosenChar);
                    auto radek3 = std::find(row3.begin(), row3.end(), chosenChar);

                    if (radek1 != row1.end()) {         // pokud se ve vektoru nachází, pøepíše se na #
                        *radek1 = '#';
                    }
                    else if (radek2 != row2.end()) {
                        *radek2 = '#';
                    }
                    else if (radek3 != row3.end()) {
                        *radek3 = '#';
                    }

                    guess.clear(); // hádané písmenko
                    guess.push_back(chosenChar); 
                    keyPressed = true;  
                }
            }
        }

        
        window.clear();

        if (keyPressed) {
            
            score = scoretracker(guess, wordCharacters, streak, score);     // kontrola správnosti hádaného písmena a úprava skóre a životù
            life = guessedword( playerGuess, wordCharacters, guess, life);
            
       
            keyPressed = false;  // ukonèení cyklu
        }
        std::string scoreString = "Your score: " + std::to_string(score);   // vypsání skóre na obrazovku
        sf::Text scoreText;
        scoreText.setFont(font);
        scoreText.setCharacterSize(30);
        scoreText.setFillColor(sf::Color::Red);
        scoreText.setString(scoreString);

        sf::FloatRect textRect = scoreText.getLocalBounds();   // pozice skóre
        scoreText.setOrigin(textRect.left + textRect.width / 2.0f, textRect.top + textRect.height / 2.0f);
        scoreText.setPosition(650, 30);
        
        drawzivot(window, life); // urèuje pozadí
        drawtext(window, playerGuess, font); // zobrazuje proces hádání slova
        drawKeyboard(window, row1, row2, row3); // zobrazuje klávesnici
        drawKeys(window, font);
        window.draw(scoreText); // zobrazuje skóre

        window.display();

        

        
        if (life >= 10)  // pokud dojdou životy, vykreslí se závìreèná obrazovka
        {

            std::vector<int> super = gettop(score);

            sf::Texture over = zap.getover();
            sf::Sprite ovr(over);
            window.clear();
            window.draw(ovr);
        
            int yPos = 100; 

            for (size_t i = 0; i < super.size(); ++i) {
                sf::Text scoreText;
                scoreText.setFont(font);
                scoreText.setCharacterSize(30);
                scoreText.setFillColor(sf::Color::White);
                scoreText.setString(std::to_string(i+1) + ". Top Score " + std::to_string(super[i]));

                sf::FloatRect textRect = scoreText.getLocalBounds();
                scoreText.setOrigin(textRect.left + textRect.width / 2.0f, textRect.top + textRect.height / 2.0f);
                scoreText.setPosition(window.getSize().x / 2.0f, yPos);

                window.draw(scoreText);

                yPos += 50; 
            }

            std::string sscoreString = "Your score: " + std::to_string(score);   // vypsání skóre na koneènou obrazovku
            sf::Text sscoreText;
            sscoreText.setFont(font);
            sscoreText.setCharacterSize(30);
            sscoreText.setFillColor(sf::Color::Red);
            sscoreText.setString(sscoreString);

            sf::FloatRect textRect = sscoreText.getLocalBounds();   // umístìní skóre na koneèné obrazovce
            sscoreText.setOrigin(textRect.left + textRect.width / 2.0f, textRect.top + textRect.height / 2.0f);
            sscoreText.setPosition(600, 400);

            window.draw(sscoreText);
            window.display();

            sf::Event event;   // po stisknutí jakékoliv klávesy se hra ukonèí
            while (window.waitEvent(event)) {
                
                if (event.type == sf::Event::KeyPressed) {
                    
                    
                    window.close();
                    break; 
                }
            }
        }

    }
}
