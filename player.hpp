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

	int codigo = 0;
	int velX;
	int velY;
	sf::Vector2i velocidade;
	int posiX;
	int posiY;
	sf::Vector2f posicao;
	int altura;
	int largura;
	sf::Vector2i tamanho;
	int vida;
	int balas;
	sf::RectangleShape corpo;

public:

	Player(){

		this->velX = 0;
		this->velY = 0;
		this->posiX = 100;
		this->posiY = 200;
		this->posicao.x = 100;
		this->posicao.y = 200;
		this->altura = 200;
		this->largura = 80;
		this->vida = 5;
		this->balas = 999;

		std::cout << "Objeto 'Player' criado!" << std::endl;
	}

	Player(int VelX, int VelY, int PosiX, int PosiY, int Altura, int Largura, int Vida, int Balas){

		this->velX = VelX;
		this->velY = VelY;
		this->posiX = PosiX;
		this->posiY = PosiY;
		this->posicao.x = PosiX;
		this->posicao.y = PosiY;
		this->altura = Altura;
		this->largura = Largura;
		this->vida = Vida;
		this->balas = Balas;

		std::cout << "Objeto 'Player' criado!" << std::endl;
	}

	void iniciarPlayer(){
		//corpo.setFillColor(sf::Color::Cyan);
		corpo.setPosition(posiX, posiY);
		corpo.setSize(sf::Vector2f(largura, altura));
	}

	void movePlayer(Bloco (*objeto)[40], int alt, int larg){

		bool colidiu;

		corpo.move(0,velY);

		 for (int i = 0; i < alt; i++) {
			 for (int j = 0; j < larg; j++) {
				 if(objeto[i][j].solido){
					 if(corpo.getGlobalBounds().intersects(objeto[i][j].corpo.getGlobalBounds())){
						 colidiu = true;
					 }
				 }
			 }
		 }

		 if(colidiu == true){
			 std::cout << "Colisao detectada com um obstaculo!" << std::endl;
			 colidiu = false;

			 corpo.move(0,-velY);

		 }

		 velY = 0;

		 corpo.move(velX,0);

		 for (int i = 0; i < alt; i++) {
			 for (int j = 0; j < larg; j++) {
				 if(objeto[i][j].solido){
					 if(corpo.getGlobalBounds().intersects(objeto[i][j].corpo.getGlobalBounds())){
						 colidiu = true;
					 }
				 }
			 }
		 }

		 if(colidiu == true){
			 std::cout << "ColisÃ£o detectada com um obstaculo!" << std::endl;
			 colidiu = false;

			 corpo.move(-velX,0);

		 }

		 velX = 0;

		 posicao = corpo.getPosition();
		 posiX = posicao.x;
		 posiY = posicao.y;
	}

	void setPosiX(int X){
		this->posiX = X;
		this->posicao.x = X;
	}

	void setPosiY(int Y){
		this->posiY = Y;
		this->posicao.y = Y;
	}

	void setTexture(sf::Texture* Texture){
		corpo.setTexture(Texture, true);
		corpo.setTextureRect(sf::IntRect (1, 1, 31, 64));
	}

	void setTextureRect(int Tempo){

		if(vida > 0){

			if (Tempo % 2 != 0){
				corpo.setTextureRect(sf::IntRect (1, 1, 31, 64));
			}else{
				Tempo = (Tempo / 2) + 1;
				int x = 32*Tempo + 2 * Tempo;
				corpo.setTextureRect(sf::IntRect (x+1, 1, 32, 64));
			}
		}
	}

	void setPosi(int X, int Y){
		this->posiX = X;
		this->posiY = Y;
		this->posicao.x = X;
		this->posicao.y = Y;
		corpo.setPosition(posiX, posiY);
	}

	void setVelX(int X){
		this->velX = X;
	}

	void setBalas(int Balas){
		this->balas = Balas;
	}

	void setVelY(int Y){
		this->velY = Y;
	}

	void setCodigo(int Codigo){
		this->codigo = Codigo;
	}

	void setAltura(int alt,sf::RectangleShape (*objeto)[40], int altu, int larg){

		corpo.setSize(sf::Vector2f(largura, alt));

		bool colidiu;

		 for (int i = 0; i < altu; i++) {
			 for (int j = 0; j < larg; j++) {
				 if(objeto[i][j].getFillColor() == sf::Color::Blue){
					 if(corpo.getGlobalBounds().intersects(objeto[i][j].getGlobalBounds())){
						 colidiu = true;
					 }
				 }
			 }
		 }

		 if(colidiu == true){
			 std::cout << "Colisao detectada com um obstaculo!" << std::endl;
			 colidiu = false;

			 corpo.setSize(sf::Vector2f(largura, altura));

		 }else{
			 this->altura = alt;
		 }

	}

	sf::RectangleShape getCorpo(){
		return corpo;
	}

	int getCodigo(){
		return codigo;
	}

	int& getVida(){
		return vida;
	}

	int& getBalas(){
		return balas;
	}

	sf::Vector2f getPosicaoV2f(){
		return posicao;
	}

	int getVelX(){
		return velX;
	}

	int getVelY(){
		return velY;
	}

	void desenharPlayer(sf::RenderWindow& window){
		if(!vida){
			if(codigo == 2){
			corpo.setTextureRect(sf::IntRect (2, 67, 26, 64));
			}else{
				corpo.setTextureRect(sf::IntRect (2, 67, 31, 64));
			}
		}
		//corpo.update();
		window.draw(corpo);
		std::cout << "Player desenhado!" << std::endl;
	}
};
#endif // PLAYER_HPP
