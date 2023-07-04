#ifndef PLAYER_HPP
#define PLAYER_HPP
/*
 * player.hpp
 *
 *  Created on: 21 de mai. de 2023
 *      Author: Davi O
 */

#include <iostream>
#include <vector>
#include <string>
#include <iterator>
#include <SFML/Graphics.hpp>

#include "bloco.hpp"

class Player{

protected:

	sf::RectangleShape corpo;
	sf::Vector2i velocidade;
	sf::Vector2f posicao;
	sf::Vector2i tamanho;
	int numeroVida;
	int numeroBalas;
	int idPlayer = 0;

	bool testeColisaoMapa(Bloco (*mapa)[40], int numeroLinhas, int numeroColunas){

		bool colisao;

		 for (int i = 0; i < numeroLinhas; i++) {
			 for (int j = 0; j < numeroColunas; j++) {
				 if(mapa[i][j].solido){
					 if(corpo.getGlobalBounds().intersects(mapa[i][j].corpo.getGlobalBounds())){
						 colisao = true;
					 }
				 }
			 }
		 }

		return colisao;
	}

public:

	Player(){

		this->velocidade.x = 0;
		this->velocidade.y = 0;
		this->posicao.x = 100;
		this->posicao.y = 200;
		this->tamanho.x = 80;
		this->tamanho.y = 200;
		this->numeroVida = 5;
		this->numeroBalas = 8;
		this->corpo.setPosition(posicao.x, posicao.y);
		this->corpo.setSize(sf::Vector2f(tamanho.x, tamanho.y));

		std::cout << "Objeto 'Player' criado!" << std::endl;
	}

	Player(int VelocidadeX, int VelocidadeY, int PosicaoX, int PosicaoY, int AlturaPlayer, int LarguraPlayer, int NumeroVida, int NumeroBalas){

		this->velocidade.x = VelocidadeX;
		this->velocidade.y = VelocidadeY;
		this->posicao.x = PosicaoX;
		this->posicao.y = PosicaoY;
		this->tamanho.x = LarguraPlayer;
		this->tamanho.y = AlturaPlayer;
		this->numeroVida = NumeroVida;
		this->numeroBalas = NumeroBalas;
		this->corpo.setPosition(posicao.x, posicao.y);
		this->corpo.setSize(sf::Vector2f(tamanho.x, tamanho.y));

		std::cout << "Objeto 'Player' criado!" << std::endl;
	}

	void iniciarPlayer(){
		corpo.setPosition(posicao.x, posicao.y);
		corpo.setSize(sf::Vector2f(tamanho.x, tamanho.y));
	}

	void moverPlayer(Bloco (*mapa)[40], int numeroLinhas, int numeroColunas){

		corpo.move(0,velocidade.y);

		if(testeColisaoMapa( mapa , numeroLinhas, numeroColunas))
			corpo.move(0,-velocidade.y);

		velocidade.y = 0;

		corpo.move(velocidade.x,0);

		if(testeColisaoMapa( mapa , numeroLinhas, numeroColunas))
			corpo.move(-velocidade.x,0);

		velocidade.x = 0;

		posicao = corpo.getPosition();

	}

	void changeFrame(int Tempo){
		if(numeroVida > 0){
			if (Tempo % 2 != 0){
				corpo.setTextureRect(sf::IntRect (1, 1, 31, 64));
			}else{
				Tempo = (Tempo / 2) + 1;
				int x = 32*Tempo + 2 * Tempo;
				corpo.setTextureRect(sf::IntRect (x+1, 1, 32, 64));
			}
		}
	}

	void setTexture(sf::Texture* Texture){
		corpo.setTexture(Texture, true);
		corpo.setTextureRect(sf::IntRect (1, 1, 31, 64));
	}

	void setPosiX(int X){
		this->posicao.x = X;
	}

	void setPosiY(int Y){
		this->posicao.y = Y;
	}

	void setPosi(int PosicaoX, int PosicaoY){
		this->posicao.x = PosicaoX;
		this->posicao.y = PosicaoY;
		corpo.setPosition(PosicaoX,PosicaoY);
	}

	void setVelocidadeX(int Velocidade){
		this->velocidade.x = Velocidade;
	}

	void setVelocidadeY(int Velocidade){
		this->velocidade.y = Velocidade;
	}

	void setNumeroBalas(int Balas){
		this->numeroBalas = Balas;
	}

	void setIdPlayer(int numeroId){
		this->idPlayer = numeroId;
	}

	sf::RectangleShape getCorpo(){
		return corpo;
	}

	int getIdPlayer(){
		return idPlayer;
	}

	int& getNumeroVida(){
		return numeroVida;
	}

	int& getNumeroBalas(){
		return numeroBalas;
	}

	sf::Vector2f getPosicaoV2f(){
		return posicao;
	}

	int getVelocidadeX(){
		return velocidade.x;
	}

	int getVelocidadeY(){
		return velocidade.y;
	}

	void desenharPlayer(sf::RenderWindow& window){
		if(!numeroVida){
			if(idPlayer == 2){
			corpo.setTextureRect(sf::IntRect (2, 67, 26, 64));
			}else{
				corpo.setTextureRect(sf::IntRect (2, 67, 31, 64));
			}
		}
		window.draw(corpo);
		std::cout << "Player desenhado!" << std::endl;
	}
};
#endif // PLAYER_HPP
