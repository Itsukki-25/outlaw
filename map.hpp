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
#include "obstaculos.hpp"
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

	void definirValorCasas(std::vector<std::string>& mapa, Player& jogador1, Player& jogador2, sf::Texture* areiaTextura,
			sf::Texture* cactoTextura,sf::Texture* bolaFenoTextura, std::vector<BolaFeno>& bolasDeFeno){

		srand((unsigned) time(NULL));

		std::cout << "mapa 1!" << std::endl;
	        for (int i = 0; i < altura; i++) {
	            for (int j = 0; j < largura; j++) {

	                casas[i][j].corpo = sf::RectangleShape(sf::Vector2f(tamanhoCasa, tamanhoCasa));
	                casas[i][j].corpo.setPosition(j * tamanhoCasa, i * tamanhoCasa);

	                if(mapa[i][j] == '#'){

	                    casas[i][j].corpo.setTexture(areiaTextura);
		                casas[i][j].solido = true;
		                casas[i][j].visivel = true;

	                }else if(mapa[i][j] == '*'){
	                	casas[i][j].corpo.setTexture(cactoTextura);
	                	casas[i][j].visivel = true;
	                	casas[i][j].solido = false;

	                	switch( 1+(rand() % 3)){
	                	case 1:
	                		casas[i][j].corpo.setTextureRect(sf::IntRect (3, 34, 30, 32));
	                		break;
	                	case 2:
	                		if((!casas[i-1][j].solido) && (!casas[i-1][j].visivel)){
	                		casas[i-1][j].corpo.setTexture(cactoTextura);
	                		casas[i-1][j].corpo.setTextureRect(sf::IntRect (39, 7, 26, 29));
	                		casas[i][j].corpo.setTextureRect(sf::IntRect (39, 36, 26, 29));
	                		casas[i-1][j].visivel = true;
	                		}else{
	                			casas[i][j].corpo.setTextureRect(sf::IntRect (39, 7, 26, 58));
	                		}
	                		break;
	                	case 3:
	                		if((!casas[i-1][j].solido) && (!casas[i-1][j].visivel)){
	                		casas[i-1][j].corpo.setTexture(cactoTextura);
	                		casas[i-1][j].corpo.setTextureRect(sf::IntRect (71, 7, 27, 23));
	                		casas[i][j].corpo.setTextureRect(sf::IntRect (71, 30, 27, 27));
	                		casas[i-1][j].visivel = true;
	                		}else{
	                			casas[i][j].corpo.setTextureRect(sf::IntRect (71, 12, 27, 53));
	                		}
	                		break;
	                	case 4:// o case 4 nao vai aparecer propositalmente *achei que não combinou*
	                		casas[i][j].corpo.setTextureRect(sf::IntRect (7, 117, 24, 14));
	                		break;
	                	}
	                }else if(mapa[i][j] == '1'){

	                    jogador1.setPosicao(j * tamanhoCasa, i * tamanhoCasa);
	                    casas[i][j].solido = false;
	                    casas[i][j].visivel = false;
	                }else if(mapa[i][j] == '2'){

	                    jogador2.setPosicao(j * tamanhoCasa, i * tamanhoCasa);
	                    casas[i][j].solido = false;
	                    casas[i][j].visivel = false;
	                }else if(mapa[i][j] == '@'){
	                	casas[i][j].solido = false;
	                	casas[i][j].visivel = false;
	                	bolasDeFeno.push_back(BolaFeno(j * tamanhoCasa, i * tamanhoCasa, 1));
	                	bolasDeFeno.back().getBolaDeFeno().setTexture(bolaFenoTextura);
	                	bolasDeFeno.back().setConfigTexture();
	                	std::cout << "criei feno!" << std::endl;
	                }else{
	                	casas[i][j].solido = false;
	                	casas[i][j].visivel = false;
	                }
	            }
	        }
	    }

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
				if(casas[i][j].visivel)
				window.draw(casas[i][j].corpo);
		    }
		}
		std::cout << "Mapa desenhado!" << std::endl;
	}
};
