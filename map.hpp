/*
 * map.hpp
 *
 *  Created on: 21 de mai. de 2023
 *      Author: Davi O
 */
#include <iostream>
#include <vector>
#include <string>
#include <SFML/Graphics.hpp>

#include "player.hpp"

class Mapa{
private:

	int largura;
	int altura;
	int tamanhoCasa;
	sf::RectangleShape casas[40][40];

public:

	Mapa(){

		this-> largura = 40;
		this-> altura = 20;
		this-> tamanhoCasa = 32;

		std::cout << "Objeto 'mapa' criado!" << std::endl;
	}

	Mapa(int Largura, int Altura, int TamanhoCasa){

		this-> largura = Largura;
		this-> altura = Altura;
		this-> tamanhoCasa = TamanhoCasa;

		std::cout << "Objeto 'Mapa' criado!" << std::endl;
	}

	void definirValorCasas(std::vector<std::string>& mapa, Player& jogador1, Player& jogador2 ) {

	        for (int i = 0; i < altura; i++) {
	            for (int j = 0; j < largura; j++) {
	                casas[i][j] = sf::RectangleShape(sf::Vector2f(tamanhoCasa, tamanhoCasa));
	                casas[i][j].setPosition(j * tamanhoCasa, i * tamanhoCasa);
	                if (mapa[i][j] == '#') {
	                    casas[i][j].setFillColor(sf::Color::Blue);
		                casas[i][j].setOutlineThickness(1);
		                casas[i][j].setOutlineColor(sf::Color::Black);
	                }else if(mapa[i][j] == '*'){
	                    casas[i][j].setFillColor(sf::Color::Green);
	                }else if(mapa[i][j] == '1'){
	                    jogador1.setPosi(j * tamanhoCasa, i * tamanhoCasa);
	                    casas[i][j].setFillColor(sf::Color::Black);
	                }else if(mapa[i][j] == '2'){
	                    jogador2.setPosi(j * tamanhoCasa, i * tamanhoCasa);
	                    casas[i][j].setFillColor(sf::Color::Black);
	                }else{
	                    casas[i][j].setFillColor(sf::Color::Black);
	                }

	            }
	        }
	        std::cout << "Mapa definido!" << std::endl;
	    }

	sf::RectangleShape (*getCasa())[40]{
		return casas;
	}

	int getAltura(){
		return altura;
	}

	int getLargura(){
		return largura;
	}

	void desenharMapa(sf::RenderWindow& window){
		for (int i = 0; i < altura; i++) {
			for (int j = 0; j < largura; j++) {
				if(casas[i][j].getFillColor() != sf::Color::Black)
				window.draw(casas[i][j]);
		    }
		}
		std::cout << "Mapa desenhado!" << std::endl;
	}
};
