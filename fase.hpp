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
#include <unistd.h>

#include "map.hpp"
#include "player.hpp"
#include "Bala.hpp"
#include "obstaculos.hpp"
#include "Janela.hpp"

class Fase{
private:

	vector<string> mapaString;
	vector<Bala> balas;
	vector<BolaFeno> bolasDeFeno;
	Player player2;
	Player player1;
	sf::Vector2u player1TeclaPressionada;
	sf::Vector2u player2TeclaPressionada;
	int jogoAcabou = false;
	int linhas = 20;
	int colunas = 40;
	int SQUARE_SIZE = 32;
	Janela janela;
	int* controlPanel;

	void desenharObjetosMoveis(sf::RenderWindow& window, Mapa mapa, Player& jogador, int tempo){
		if(balas.size())
		for(int i = 0; i <= balas.size()-1 ; i++){
			window.draw(balas[i].getCorpo());

			if(!balas[i].getVidaBala())
				balas.erase(balas.begin() + i);

			if(bolasDeFeno.size())
			for(int j = 0; j <= bolasDeFeno.size()-1 ; j++){
				if(balas[i].getCorpo().getGlobalBounds().intersects(bolasDeFeno[j].getBolaDeFeno().getGlobalBounds())){
					balas[i].getVidaBala() = false;
				}
			}

			if(!balas[i].movimentos(jogador, mapa.getCasa(), 20, 40))
				break;
		}

		if(bolasDeFeno.size())
		for(int i = 0; i <= bolasDeFeno.size()-1 ; i++){
		    if(tempo % 2 || tempo % 3){
		    	bolasDeFeno[i].getBolaDeFeno().setRotation(bolasDeFeno[i].getBolaDeFeno().getRotation()-1);
		    }
			window.draw(bolasDeFeno[i].getBolaDeFeno());
			bolasDeFeno[i].testaLimiteMovimenta(mapa.getCasa(), 20, 40);
			//bolasDeFeno[i].changeFrameObstaculo(tempo);
		}

	};

	void atirarAtualizarBalas(){

	    if(player1TeclaPressionada.x == true && player1TeclaPressionada.y == true && player1.getNumeroBalas() > 0){
	    	std::cout << "Jogador 1 atirou" <<std::endl;
	    	balas.push_back(Bala(-5, player1.getVelocidadeY(), player1));
	    	player1TeclaPressionada.x = false;
	    	player1TeclaPressionada.y = false;
	    	player1.getNumeroBalas()--;
	    }
	    if(player2TeclaPressionada.x == true && player2TeclaPressionada.y == true && player2.getNumeroBalas() > 0){
	    	std::cout << "Jogador 1 atirou" <<std::endl;
	    	balas.push_back(Bala(5, player2.getVelocidadeY(), player2));
	    	player2TeclaPressionada.x = false;
	    	player2TeclaPressionada.y = false;
	    	player2.getNumeroBalas()--;
	    }
	    if(player2.getNumeroBalas() == 0 && player1.getNumeroBalas() == 0){
	    	player2.getNumeroBalas() = 5;
	    	player1.getNumeroBalas() = 5;
	    	player1TeclaPressionada.x = false;
	    	player1TeclaPressionada.y = false;
	    	player2TeclaPressionada.x = false;
	    	player2TeclaPressionada.y = false;
	    }
	};


public:

	int iniciarJogo(sf::RenderWindow& window, vector<string>& mapaString){

		auto tempoInicio = std::chrono::steady_clock::now();

		// Carrega as texturas
		sf::Texture player1Texture;
		if (!player1Texture.loadFromFile("img/jogador1.png"))
		    return -1;
		sf::Texture player2Texture;
		if (!player2Texture.loadFromFile("img/jogador2.png"))
		    return -1;
		sf::Texture areiaTexture;
		if (!areiaTexture.loadFromFile("img/areia.png"))
		    return -1;
		sf::Texture cactoTexture;
		if (!cactoTexture.loadFromFile("img/cacto.png"))
		    return -1;
		sf::Texture textureFundo;
		if (!textureFundo.loadFromFile("img/fundoJogo.png"))
		    return -1;
		sf::Texture texturaBolaDeFeno;
		if (!texturaBolaDeFeno.loadFromFile("img/bolaDeFeno.png"))
				    return -1;

	    sf::Sprite fundoImage;

		// Configura os players
		player1.setIdPlayer(1);
		player1.setTexture(&player1Texture);
		player2.setIdPlayer(2);
		player2.setTexture(&player2Texture);

		fundoImage.setTexture(textureFundo);

		Mapa mapa(colunas, linhas, SQUARE_SIZE);
		mapa.definirValorCasas(mapaString, player1, player2, &areiaTexture, &cactoTexture, &texturaBolaDeFeno, bolasDeFeno);
		std::cout << "criei mapa!" << std::endl;

		while (!jogoAcabou){

				auto tempoAtual = std::chrono::steady_clock::now();
				float tempoFinalFloat = std::chrono::duration<float>(tempoAtual - tempoInicio).count();
				int tempoFinalInt = static_cast<int>(tempoFinalFloat);

				sf::Event event;
			    while (window.pollEvent(event)){

			    	if (event.type == sf::Event::Closed){
			    		std::cout << "Programa finalizado manualmente!" << std::endl;
			    		window.close();
			    		return 0;
			        }

				    if(sf::Keyboard::isKeyPressed(sf::Keyboard::RShift)){
				    	player1TeclaPressionada.x = true;
				    	player1TeclaPressionada.y = false;
				    }else{
				    	player1TeclaPressionada.y = true;}

				    if((event.type == sf::Event::KeyReleased && event.key.code == sf::Keyboard::Up)
				    		|| (event.type == sf::Event::KeyReleased && event.key.code == sf::Keyboard::Down))
				    	player1TeclaPressionada.y = true;

				    if(sf::Keyboard::isKeyPressed(sf::Keyboard::LShift)){
				    	player2TeclaPressionada.x = true;
				    	player2TeclaPressionada.y = false;
				    }else{
				    	player2TeclaPressionada.y = true;}

				    if((event.type == sf::Event::KeyReleased && event.key.code == sf::Keyboard::W)
				    		|| (event.type == sf::Event::KeyReleased && event.key.code == sf::Keyboard::S))
				    	player2TeclaPressionada.y = true;

			    }//Fim evonto

			    // Atualizar os frames da textura do personagem
			    player1.changeFrame(tempoFinalInt);
			    player2.changeFrame(tempoFinalInt);

			    // Reinicia a contagem de frames
			    if(tempoFinalInt == 4)
			    	tempoInicio = std::chrono::steady_clock::now();

			    atirarAtualizarBalas();

		    	if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
		    		player1.setVelocidadeY(-2);
		    	else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
		    		player1.setVelocidadeY(2);

		    	if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
		    		player1.setVelocidadeX(-2);
		    	else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
		    		player1.setVelocidadeX(2);

		    	if(sf::Keyboard::isKeyPressed(sf::Keyboard::W))
		    		player2.setVelocidadeY(-2);
		    	else if(sf::Keyboard::isKeyPressed(sf::Keyboard::S))
		    		player2.setVelocidadeY(2);

		    	if(sf::Keyboard::isKeyPressed(sf::Keyboard::A))
		    		player2.setVelocidadeX(-2);
		    	else if(sf::Keyboard::isKeyPressed(sf::Keyboard::D))
		    		player2.setVelocidadeX(2);

			    if(player1.getNumeroVida() == 0 && player2.getNumeroVida() != 0){
			    	jogoAcabou = 2;
			    }else	if(player1.getNumeroVida() != 0 && player2.getNumeroVida() == 0){
			    	jogoAcabou = 1;
			    }else	if(player1.getNumeroVida() == 0 && player2.getNumeroVida() == 0){
			    	jogoAcabou = 3;
			    }

			    window.clear();
			    window.draw(fundoImage);
			    mapa.desenharMapa(window);
			    desenharObjetosMoveis(window, mapa, player1, tempoFinalInt);
			    desenharObjetosMoveis(window, mapa, player2, tempoFinalInt);
			    if(!sf::Keyboard::isKeyPressed(sf::Keyboard::RShift))
			    	player1.moverPlayer(mapa.getCasa(), linhas, colunas);
			    if(!sf::Keyboard::isKeyPressed(sf::Keyboard::LShift))
			    	player2.moverPlayer(mapa.getCasa(), linhas, colunas);
			    player1.desenharPlayer(window);
			    player2.desenharPlayer(window);
			    window.display();
			}

		std::cout << "Jogo acaboou!!" << std::endl;
		sleep(2);
		return jogoAcabou;
	}
};



#endif /* FASE_HPP_ */
