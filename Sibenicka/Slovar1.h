#pragma once
#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <fstream>


class Slovar
{
private:


	std::vector<std::string> words;



public:

	Slovar(int difficulty) {

		std::string text;

		switch (difficulty)     // výbìr souboru se slovy podle obtížnosti
		{
		case 0:
			text = "words1.txt";
			std::cout << "word1";
			break;
		case 1:
			text = "words2.txt";
			std::cout << "word2";
			break;
		case 2:
			text = "words2.txt";
			std::cout << "word2";
			break;
		}
		std::ifstream file(text);
		if (file.is_open())
		{
			std::string word;
			while (std::getline(file, word))
			{
				for (char& c : word)
				{
					c = std::toupper(c);
				}
				words.push_back(word);
			}
			file.close();
		}
		else      // pokud se nepodaøí otevøít soubor
		{
			std::cout << "failed";
			std::vector<std::string> words= { "JAZZ", "BUZZ", "QUIZ", "FUZZY", "JIGSAW", "PUZZLE", "JUKEBOX", "ZIGZAG", "WHIZ", "BLITZ",
"VIXEN", "GIZMO", "GLITZ", "HIJACK", "KNAPSACK", "SQUAWK", "BUZZER", "QUARTZ", "JAWBONE", "KNUCKLES",
"SKYBOX", "WHISKY", "FOXGLOVE", "ZIPPER", "JINX", "QUASAR", "KAYAK", "JOCKEY", "LYRICS", "PYGMY",
"WHISKY", "JUNGLE", "RAZZMATAZZ", "PUZZLE", "JIGSAW", "BUZZ", "QUIZ", "WHIZ", "JUKEBOX", "GIZMO",
"QUARTZ", "JAWBONE", "SQUAWK", "ZIGZAG", "BUZZER", "BLITZ", "JAZZ", "VIXEN", "KNUCKLES", "KNAPSACK",
"HIJACK", "LYRICS", "WHISKY", "SKYBOX", "JINX", "ZIPPER", "QUASAR", "PYGMY", "KAYAK", "GIZMO",
"JAZZ", "BUZZ", "QUIZ", "JIGSAW", "JUKEBOX", "WHIZ", "PUZZLE", "ZIGZAG", "BUZZER", "QUARTZ",
"JAWBONE", "BLITZ", "GIZMO", "SQUAWK", "VIXEN", "KNUCKLES", "WHISKY", "HIJACK", "LYRICS", "SKYBOX",
"KNAPSACK", "FOXGLOVE", "JINX", "ZIPPER", "QUASAR", "PYGMY", "KAYAK", "JOCKEY", "WHISKY", "JUNGLE",
"RAZZMATAZZ", "BUZZ", "JAZZ", "QUIZ", "WHIZ", "JUKEBOX", "JIGSAW", "ZIGZAG", "BUZZER", "QUARTZ",
"GIZMO", "JAWBONE", "BLITZ", "SQUAWK", "KNUCKLES", "VIXEN", "LYRICS", "SKYBOX", "HIJACK", "WHISKY",
"KNAPSACK", "JINX", "ZIPPER", "QUASAR", "PYGMY", "KAYAK", "JUNGLE", "FOXGLOVE", "RAZZMATAZZ",
"WHISKY", "JOCKEY" };
		}


	}

	void getfinalword(std::vector<char>& wordCharacters, std::vector<char>& playerguess, int difficulty)  
	{
	
		std::string vyberslovo;

		vyberslovo = words[std::rand() % words.size()];
		

		wordCharacters.clear();  // vyèistí vektor od #
		for (char letter : vyberslovo) // rozdìlí slovo na jednotlivá písmena
		{
			
			wordCharacters.push_back(letter); // pošle písmena do vektoru
		}
		playerguess.clear();
		playerguess.assign(wordCharacters.size(), '#'); 

	}






};
