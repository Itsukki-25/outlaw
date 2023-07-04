/*
 * fase.hpp
 *
 *  Created on: 1 de jul. de 2023
 *      Author: Davi
 */

#ifndef FASE_HPP_
#define FASE_HPP_

#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include <vector>
#include <chrono>

#include "map.hpp"
#include "player.hpp"
#include "Bala.hpp"

class Fase{
public:

	vector<string> mapaString;
	vector<Bala> balas;
	bool jogoAcabou = false;

	void desenharBala(sf::RenderWindow& window, Mapa mapa, Player& jogador){

		if(balas.size())
		for(int i = 0; i <= balas.size()-1 ; i++){

			window.draw(balas[i].getCorpo());

			if(!balas[i].getVida())
				balas.erase(balas.begin() + i);

			if(!balas[i].movimentos(jogador, mapa.getCasa(), 20, 40))
				break;
		}
	};

	int iniciarFase(sf::RenderWindow& window, vector<string>& mapa){

		const int linhas = 20;
		const int colunas = 40;
		int SQUARE_SIZE = 32;

		bool jogador1Tecl1 = false, jogador1Tecl2 = false;
		bool jogador2Tecl1 = false, jogador2Tecl2 = false;

		Mapa fase1(colunas, linhas, SQUARE_SIZE);

		sf::Texture jogador1Texture;
		if (!jogador1Texture.loadFromFile("img/jogador1.png"))
		    return -1;
		sf::Texture jogador2Texture;
		if (!jogador2Texture.loadFromFile("img/jogador2.png"))
		    return -1;
		sf::Texture areiaTexture;
		if (!areiaTexture.loadFromFile("img/areia.png"))
		    return -1;
		sf::Texture cactoTexture;
		if (!cactoTexture.loadFromFile("img/areia.png"))
		    return -1;

		Player jogador1;
		jogador1.iniciarPlayer();
		jogador1.setCodigo(1);
		jogador1.setTexture(&jogador1Texture);
		Player jogador2;
		jogador2.iniciarPlayer();
		jogador2.setCodigo(2);
		jogador2.setTexture(&jogador2Texture);

		fase1.definirValorCasas(mapa, jogador1, jogador2, &areiaTexture);
		std::cout << "criei mapa!" << std::endl;

		auto tempoInicio = std::chrono::steady_clock::now();

		while (!jogoAcabou){

				auto tempoAtual = std::chrono::steady_clock::now();
				float tempo = std::chrono::duration<float>(tempoAtual - tempoInicio).count();
				int tempoFinal = static_cast<int>(tempo);

				sf::Event event;
			    while (window.pollEvent(event)){

			    	if (event.type == sf::Event::Closed){
			    		std::cout << "Programa finalizado manualmente!" << std::endl;
			    		window.close();
			    		return 0;
			        }

				    if(sf::Keyboard::isKeyPressed(sf::Keyboard::RShift)){
				    	jogador1Tecl1 = true;
				    	jogador1Tecl2 = false;
				    }else{
				    	jogador1Tecl2= true;
				    }
				    if(event.type == sf::Event::KeyReleased && event.key.code == sf::Keyboard::Up){
				    	jogador1Tecl2= true;
				    }
				    if(event.type == sf::Event::KeyReleased && event.key.code == sf::Keyboard::Down){
				    	jogador1Tecl2= true;
				    }
				    if(sf::Keyboard::isKeyPressed(sf::Keyboard::LShift)){
				    	jogador2Tecl1 = true;
				    	jogador2Tecl2 = false;
				    }else{
				    	jogador2Tecl2= true;
				    }
				    if(event.type == sf::Event::KeyReleased && event.key.code == sf::Keyboard::W){
				    	jogador2Tecl2= true;
				    }
				    if(event.type == sf::Event::KeyReleased && event.key.code == sf::Keyboard::S){
				    	jogador2Tecl2= true;
				    }

			    }//Fim evonto

			    jogador1.setTextureRect(tempoFinal);
			    jogador2.setTextureRect(tempoFinal);
			    if(tempoFinal == 4)
			    	tempoInicio = std::chrono::steady_clock::now();

			    if(jogador1Tecl1 == true && jogador1Tecl2 == true && jogador1.getBalas() > 0){
			    	std::cout << "Jogador 1 atirou" <<std::endl;
			    	balas.push_back(Bala(-5, jogador1.getVelY(), jogador1));
			    	jogador1Tecl1 = false;
			    	jogador1Tecl2 = false;
			    	jogador1.getBalas()--;
			    }
			    if(jogador2Tecl1 == true && jogador2Tecl2 == true && jogador2.getBalas() > 0){
			    	std::cout << "Jogador 2 atirou" <<std::endl;
			    	balas.push_back(Bala(5, jogador2.getVelY(), jogador2));
			    	jogador2Tecl1 = false;
			    	jogador2Tecl2 = false;
			    	jogador2.getBalas()--;
			    }
			    if(jogador2.getBalas() == 0 && jogador1.getBalas() == 0){
			    	jogador1.getBalas() = 5;
					jogador2.getBalas() = 5;
			    	jogador2Tecl1 = false;
			    	jogador2Tecl2 = false;
			    	jogador1Tecl1 = false;
			    	jogador1Tecl2 = false;
			    }

		    	if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up)){
		    		jogador1.setVelY(-2);
		    	}else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down)){
		    		jogador1.setVelY(2);
		    	}
		    	if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left)){
		    		jogador1.setVelX(-2);
		    	}else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right)){
		    		jogador1.setVelX(2);
		    	}
		    	if(sf::Keyboard::isKeyPressed(sf::Keyboard::W)){
		    		jogador2.setVelY(-2);
		    	}else if(sf::Keyboard::isKeyPressed(sf::Keyboard::S)){
		    		jogador2.setVelY(2);
		    	}
		    	if(sf::Keyboard::isKeyPressed(sf::Keyboard::A)){
		    		jogador2.setVelX(-2);
		    	}else if(sf::Keyboard::isKeyPressed(sf::Keyboard::D)){
		    		jogador2.setVelX(2);
		    	}

			    window.clear();
			    fase1.desenharMapa(window);
			    desenharBala(window, fase1, jogador1);
			    desenharBala(window, fase1, jogador2);
			    if(!sf::Keyboard::isKeyPressed(sf::Keyboard::RShift))
			    	jogador1.movePlayer(fase1.getCasa(), linhas, colunas);
			    if(!sf::Keyboard::isKeyPressed(sf::Keyboard::LShift))
			    	jogador2.movePlayer(fase1.getCasa(), linhas, colunas);
			    jogador1.desenharPlayer(window);
			    jogador2.desenharPlayer(window);
			    window.display();

			    if(jogador1.getVida() == 0 || jogador2.getVida() == 0){
			    	jogoAcabou = true;
			    }
			}
		std::cout << "Jogo acaboou!!" << std::endl;
		return 1;
	}
};



#endif /* FASE_HPP_ */
