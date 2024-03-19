#pragma once 

#include <SFML/Graphics.hpp>
#include <vector>

void drawWordTiles(sf::RenderWindow& window) {
    const std::string word = "american";
    const float tileSize = 60.0f;
    const float spacing = 10.0f;

    // Constants for regulating x and y size
    const float xSize = 40.0f;
    const float ySize = 10.0f;

    // Calculate total width of the word tiles
    int totalWidth = word.size() * xSize + (word.size() - 1) * spacing;

    // Center the word tiles horizontally
    const float offsetX = (window.getSize().x - totalWidth) / 2.0f;
    const float offsetY = 500.0f;

    for (std::size_t i = 0; i < word.size(); ++i) {
        sf::RectangleShape tile(sf::Vector2f(xSize, ySize));
        tile.setFillColor(sf::Color(150, 150, 150));  // Grey color for word tiles

        float xPos = offsetX + i * (xSize + spacing);
        float yPos = offsetY;

        tile.setPosition(xPos, yPos);
        window.draw(tile);
    }
}



void drawKeyboard(sf::RenderWindow& window, const std::vector<char>& row1, const std::vector<char>& row2, const std::vector<char>& row3) {
    float tileSize = 60.0f;
    float spacing = 10.0f;
    int offsetY = 50;

    // Calculate total width of each row
    int row1Width = row1.size() * tileSize + (row1.size() - 1) * spacing;
    int row2Width = row2.size() * tileSize + (row2.size() - 1) * spacing;
    int row3Width = row3.size() * tileSize + (row3.size() - 1) * spacing;

    // Calculate total width of the keyboard
    int totalWidth = std::max({ row1Width, row2Width, row3Width });

    // Center the keyboard vertically
    int offsetX = (window.getSize().x - totalWidth) / 2;

    for (int row = 0; row < 3; ++row) {
        const std::vector<char>& currentRow = (row == 0) ? row1 : ((row == 1) ? row2 : row3);

        // Calculate total width of the current row
        int currentRowWidth = currentRow.size() * tileSize + (currentRow.size() - 1) * spacing;

        // Adjust offsetX to center the current row horizontally
        int rowOffsetX = offsetX + (totalWidth - currentRowWidth) / 2;

        for (int col = 0; col < currentRow.size(); ++col) {
            sf::RectangleShape tile(sf::Vector2f(tileSize, tileSize));

            switch (currentRow[col]) {
            case ' ':
                tile.setFillColor(sf::Color(200, 200, 200));  // Default color for space
                break;
            case '#':
                tile.setFillColor(sf::Color::Black);  // Black color for #
                break;
            default:
                tile.setFillColor(sf::Color(150, 150, 150));  // Grey color for other characters
            }

            tile.setPosition(rowOffsetX + col * (tileSize + spacing), offsetY + row * (tileSize + spacing));
            window.draw(tile);
        }
    }
}

char choose(sf::RenderWindow& window, std::vector<char>& row1, std::vector<char>& row2, std::vector<char>& row3) {
    char chosenChar = ' ';

    sf::Event event;
    if (window.pollEvent(event)) {
        if (event.type == sf::Event::Closed) {
            window.close();
        }
        else if (event.type == sf::Event::KeyPressed) {
            char pressedKey = ' ';

            if (event.key.code >= sf::Keyboard::A && event.key.code <= sf::Keyboard::Z) {
                pressedKey = static_cast<char>('A' + (event.key.code - sf::Keyboard::A));
                chosenChar = pressedKey;

                // Modify the vectors based on the chosenChar
                auto it1 = std::find(row1.begin(), row1.end(), chosenChar);
                auto it2 = std::find(row2.begin(), row2.end(), chosenChar);
                auto it3 = std::find(row3.begin(), row3.end(), chosenChar);

                if (it1 != row1.end()) {
                    *it1 = '#';
                }
                else if (it2 != row2.end()) {
                    *it2 = '#';
                }
                else if (it3 != row3.end()) {
                    *it3 = '#';
                }
            }
            else if (event.key.code == sf::Keyboard::Space) {
                return chosenChar;  // Return immediately when space is pressed
            }
        }
    }

    return chosenChar;
}

if (event.key.code >= sf::Keyboard::A && event.key.code <= sf::Keyboard::Z) {
    pressedKey = static_cast<char>('A' + (event.key.code - sf::Keyboard::A));
    chosenChar = pressedKey;

    // Modify the vectors based on the chosenChar
    auto it1 = std::find(row1.begin(), row1.end(), chosenChar);
    auto it2 = std::find(row2.begin(), row2.end(), chosenChar);
    auto it3 = std::find(row3.begin(), row3.end(), chosenChar);

    if (it1 != row1.end()) {
        *it1 = '#';
    }
    else if (it2 != row2.end()) {
        *it2 = '#';
    }
    else if (it3 != row3.end()) {
        *it3 = '#';
    }
}
int main() {
    sf::RenderWindow window(sf::VideoMode(800, 800), "SFML Window");

    std::vector<char> row1 = { 'Q', 'W', 'E', 'R', 'T', 'Y', 'U', 'I', 'O', 'P' };
    std::vector<char> row2 = { 'A', 'S', 'D', 'F', 'G', 'H', 'J', 'K', 'L' };
    std::vector<char> row3 = { 'Z', 'X', 'C', 'V', 'B', 'N', 'M' };

    // Draw the initial keyboard
    window.clear();
    drawKeyboard(window, row1, row2, row3);

    // Draw the word tiles
    drawWordTiles(window);

    window.display();

    while (window.isOpen()) {
        // Handle events and update the keyboard display
        char chosenChar = choose(window, row1, row2, row3);

        // Update the vectors only if a key is pressed
        

            // Clear the window and redraw the updated keyboard and word tiles
            window.clear();
            drawKeyboard(window, row1, row2, row3);
            drawWordTiles(window);
            window.display();
    }

    return 0;
}
