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

class Player{

private:
	int velX;
	int velY;
	int posiX;
	int posiY;
	int altura;
	int largura;
	int vida;
	sf::RectangleShape corpo;

public:

	Player(){

		this->velX = 1;
		this->velY = 0;
		this->posiX = 100;
		this->posiY = 200;
		this->altura = 120;
		this->largura = 60;
		this->vida = 100;

		std::cout << "Objeto 'Player' criado!" << std::endl;
	}

	Player(int VelX, int VelY, int PosiX, int PosiY, int Altura, int Largura, int Vida){

		this->velX = VelX;
		this->velY = VelY;
		this->posiX = PosiX;
		this->posiY = PosiY;
		this->altura = Altura;
		this->largura = Largura;
		this->vida = Vida;

		std::cout << "Objeto 'Player' criado!" << std::endl;
	}

	void iniciarPlayer(){
		corpo.setFillColor(sf::Color::Cyan);
		corpo.setPosition(posiX, posiY);
		corpo.setSize(sf::Vector2f(largura, altura));
	}

	void movePlayer(sf::RectangleShape (*objeto)[40], int alt, int larg){

		bool colidiu;

		corpo.move(0,velX);

		 for (int i = 0; i < alt; i++) {
			 for (int j = 0; j < larg; j++) {
				 if(objeto[i][j].getFillColor() == sf::Color::Blue){
					 if(corpo.getGlobalBounds().intersects(objeto[i][j].getGlobalBounds())){
						 colidiu = true;
					 }
				 }
			 }
		 }

		 if(colidiu == true){
			 std::cout << "Colisão detectada com um obstáculo!" << std::endl;
			 colidiu = false;

			 corpo.move(0,-velX);

		 }
		 velX = 0;

		 corpo.move(velY,0);

		 for (int i = 0; i < alt; i++) {
			 for (int j = 0; j < larg; j++) {
				 if(objeto[i][j].getFillColor() == sf::Color::Blue){
					 if(corpo.getGlobalBounds().intersects(objeto[i][j].getGlobalBounds())){
						 colidiu = true;
					 }
				 }
			 }
		 }

		 if(colidiu == true){
			 std::cout << "Colisão detectada com um obstáculo!" << std::endl;
			 colidiu = false;

			 corpo.move(-velY,0);

		 }
		 velY = 0;
	}

	void setPosiX(int X){
		this->posiX = X;
	}

	void setPosiY(int Y){
		this->posiY = Y;
	}

	void setPosi(int X, int Y){
		this->posiX = X;
		this->posiY = Y;
	}

	void setVelX(int X){
		this->velX = X;
	}

	void setVelY(int Y){
		this->velY = Y;
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
			 std::cout << "Colisão detectada com um obstáculo!" << std::endl;
			 colidiu = false;

			 corpo.setSize(sf::Vector2f(largura, altura));

		 }else{
			 this->altura = alt;
		 }

	}

	sf::RectangleShape getCorpo(){
		return corpo;
	}

	void desenharPlayer(sf::RenderWindow& window){
		window.draw(corpo);
		std::cout << "Player desenhado!" << std::endl;
	}
};
#endif // PLAYER_HPP
