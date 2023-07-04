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
#include "bloco.hpp"

class Mapa{
private:

	int largura;
	int altura;
	int tamanhoCasa;
	Bloco casas[40][40];

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

	void definirValorCasas(std::vector<std::string>& mapa, Player& jogador1, Player& jogador2, sf::Texture* areiaTextura){

		int t = 0;
		std::cout << "mapa 1!" << std::endl;
	        for (int i = 0; i < altura; i++) {
	            for (int j = 0; j < largura; j++) {
	            	std::cout << "mapa 2!" << std::endl;
	                casas[i][j].corpo = sf::RectangleShape(sf::Vector2f(tamanhoCasa, tamanhoCasa));
	                casas[i][j].corpo.setPosition(j * tamanhoCasa, i * tamanhoCasa);
	                t++;
	                std::cout << t << std::endl;
	                std::cout << i << std::endl;
	                std::cout << j  << std::endl;
	                if (mapa[i][j] == '#'){
	                	std::cout << "mapa 3!" << std::endl;
	                    casas[i][j].corpo.setTexture(areiaTextura);
		                casas[i][j].solido = true;
	                }else if(mapa[i][j] == '*'){
	                	std::cout << "mapa 4!" << std::endl;
	                	casas[i][j].solido = false;
	                }else if(mapa[i][j] == '1'){
	                	std::cout << "mapa 5!" << std::endl;
	                    jogador1.setPosi(j * tamanhoCasa, i * tamanhoCasa);
	                    casas[i][j].solido = false;
	                }else if(mapa[i][j] == '2'){
	                	std::cout << "mapa 6!" << std::endl;
	                    jogador2.setPosi(j * tamanhoCasa, i * tamanhoCasa);
	                    casas[i][j].solido = false;
	                }else{
	                	std::cout << "mapa 7!" << std::endl;
	                	casas[i][j].solido = false;
	                }
	            }
	        }
	        std::cout << "Mapa definido!" << std::endl;
	    }

//	sf::RectangleShape (*getCasa())[40]{
//		return casas;
//	}

	Bloco  (*getCasa())[40]{
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
				if(casas[i][j].solido)
				window.draw(casas[i][j].corpo);
		    }
		}
		std::cout << "Mapa desenhado!" << std::endl;
	}
};
