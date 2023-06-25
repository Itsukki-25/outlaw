

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <iostream>
#include <chrono>
#include <random>
#include <thread>
#include "Bot.hpp"
#include "Movel.hpp"
//#include "Bala.hpp"
using namespace sf;
using namespace std;
class bot {
public:
	sf::RectangleShape corpo;


private:
	void movimento(){
		int intervaloTempo = 1;


		while (true) {
			auto tempoInicio = std::chrono::steady_clock::now();


			while (true) {

				auto tempoAtual = std::chrono::steady_clock::now();
				auto duracao = std::chrono::duration_cast<std::chrono::seconds>(tempoAtual - tempoInicio).count();
				std::srand(std::time(nullptr));

				std::random_device rd;
				std::mt19937 gen(rd());
				std::uniform_int_distribution<> dis(0, 2);
				int posX = dis(gen) - 1;

				std::random_device rd;
				std::mt19937 gen(rd());
				std::uniform_int_distribution<> dis(0, 2);
				int posY = dis(gen) - 1;

				int velX=posX * 10;
				int velY=posY * 10;
				corpo.setPosition(velX, velY);
				if (duracao >= intervaloTempo) {
					break;
				}
			}


			std::cout << "Passaram-se 3 segundos!" << std::endl;

			std::this_thread::sleep_for(std::chrono::milliseconds(100));

		}



	}

};
