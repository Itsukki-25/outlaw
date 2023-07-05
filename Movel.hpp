#ifndef MOVEL_HPP_
#define MOVEL_HPP_

#include <SFML/Graphics.hpp>

#include "Efeito.hpp"

using namespace std;
using namespace sf;

class Movel{
protected:

	sf::RectangleShape corpo;
	sf::Vector2f posicao;
	sf::Vector2i tamanho;
	sf::Vector2i velocidade;
	//efeitos efeito;
	int numeroVida;

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
	};

public:

	int& getNumeroVida(){
		return numeroVida;
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

	RectangleShape getCorpo(){
		return corpo;
	}

	void setPoscaoX(int X){
		this->posicao.x = X;
	}

	void setColor(sf::Color cor){
		this->corpo.setFillColor(cor);
	}

	void setPosicaoY(int Y){
		this->posicao.y = Y;
	}

	void setPosicao(int PosicaoX, int PosicaoY){
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

};
#endif
