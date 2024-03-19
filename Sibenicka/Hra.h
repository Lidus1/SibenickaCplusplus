
#ifndef ZAPNI_H      // pro použití classy ve více headrech
#define ZAPNI_H

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>


class Zapni // nadefinované audio a vizuály
{
private:
    sf::RenderWindow window;
    sf::Font font;
    sf::Font klaves;
    sf::Texture lehka;
    sf::Texture stredni;
    sf::Texture tezka;
    sf::Texture west;
    sf::Texture Ziv1;
    sf::Texture Ziv2;
    sf::Texture Ziv3;
    sf::Texture Ziv4;
    sf::Texture Ziv5;
    sf::Texture Ziv6;
    sf::Texture Ziv7;
    sf::Texture Ziv8;
    sf::Texture Ziv9;
    sf::Texture Ziv10;
    sf::Music vsude;
    sf::Texture over;

public:
    Zapni() {} //konstruktor

    void Otevri()
    {
        window.create(sf::VideoMode(800, 800), "Hangman");
    }

    void Nacti()  // odtud se naèítají vizuály a audio
    {
        font.loadFromFile("Hovna/CURLZ.ttf");
        lehka.loadFromFile("Hovna/easy.png");
        stredni.loadFromFile("Hovna/medium.png");
        tezka.loadFromFile("Hovna/hard.png");
        klaves.loadFromFile("Hovna/Arialn.ttf");
        west.loadFromFile("Hovna/west.png");
        Ziv1.loadFromFile("Hovna/Ziv1.png");
        Ziv2.loadFromFile("Hovna/Ziv2.png");
        Ziv3.loadFromFile("Hovna/Ziv3.png");
        Ziv4.loadFromFile("Hovna/Ziv4.png");
        Ziv5.loadFromFile("Hovna/Ziv5.png");
        Ziv6.loadFromFile("Hovna/Ziv6.png");
        Ziv7.loadFromFile("Hovna/Ziv7.png");
        Ziv8.loadFromFile("Hovna/Ziv8.png");
        Ziv9.loadFromFile("Hovna/Ziv9.png");
        Ziv10.loadFromFile("Hovna/Ziv10.png");
        vsude.openFromFile("Hovna/vsude.mp3");
        over.loadFromFile("Hovna/over.jpg");


    }

    sf::RenderWindow& getOkno() 
    {
        return window;
    }

    sf::Font& getFont()
    {
        return font;
    }

    sf::Texture& getLehka()
    {
        return lehka;
    }

    sf::Texture& getStredni()
    {
        return stredni;
    }

    sf::Texture& getTezka()
    {
        return tezka;
    }

    sf::Font& getKlaves()
    {
        return klaves;
    }

    sf::Texture& getwest()
    {
        return west;
    }

    sf::Texture& getZiv1()
    {
        return Ziv1;
    }

    sf::Texture& getZiv2()
    {
        return Ziv2;
    }

    sf::Texture& getZiv3()
    {
        return Ziv3;
    }

    sf::Texture& getZiv4()
    {
        return Ziv4;
    }

    sf::Texture& getZiv5()
    {
        return Ziv5;
    }

    sf::Texture& getZiv6()
    {
        return Ziv6;
    }

    sf::Texture& getZiv7()
    {
        return Ziv7;
    }

    sf::Texture& getZiv8()
    {
        return Ziv8;
    }

    sf::Texture& getZiv9()
    {
        return Ziv9;
    }

    sf::Texture& getZiv10()
    {
        return Ziv10;
    }

    sf::Music& getvsude()
    {
        return vsude;
    }

    sf::Texture& getover()
    {
        return over;
    }
};

#endif // ZAPNI_H




