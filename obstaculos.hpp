
/* funções contrutoras inicializam valores em uma classe <- descobri agr, 28/06, 17:34
 */

#ifndef OBSTACULOS_HPP
#define OBSTACULOS_HPP

#include <SFML/Graphics.hpp>
#include <iostream>

#include "Movel.hpp"

class Obstaculo : public Movel{
protected:

	sf::Color cor = sf::Color::Red;
	sf::CircleShape corpoCircular;
	int raioCorpo;

public:

	Obstaculo(int PosicaoX, int PosicaoY) {

		this->posicao.x = PosicaoX;
		this->posicao.y = PosicaoY;
		this->raioCorpo = 25;
		this->corpoCircular.setRadius(raioCorpo);
		this->corpoCircular.setPosition(posicao.x, posicao.y);

	}

	bool testeColisaoMapa(Bloco (*mapa)[40], int numeroLinhas, int numeroColunas){

		bool colisao;

		 for (int i = 0; i < numeroLinhas; i++) {
			 for (int j = 0; j < numeroColunas; j++) {
				 if(mapa[i][j].solido){
					 if(corpoCircular.getGlobalBounds().intersects(mapa[i][j].corpo.getGlobalBounds())){
						 colisao = true;
					 }
				 }
			 }
		 }

		return colisao;
	};
	void testaLimiteMovimenta(Bloco (*mapa)[40], int numeroLinhas, int numeroColunas) {

		corpoCircular.move(0,velocidade.y);

		if(testeColisaoMapa( mapa, numeroLinhas, numeroColunas)){
			corpoCircular.move(0,-velocidade.y);
			velocidade.y = -velocidade.y;
		}

		corpoCircular.move(-32,velocidade.y*32);

		if(testeColisaoMapa( mapa, numeroLinhas, numeroColunas)){
			corpoCircular.move(33,-(velocidade.y*32));
			velocidade.y = -velocidade.y;
		}else
		corpoCircular.move(32,-(velocidade.y*32));
	}
	void Desenha(sf::RenderWindow& window) {

		window.clear();
		window.draw(corpoCircular);
	}
};

class BolaFeno: public Obstaculo {
public:

	BolaFeno(int PosicaoX, int PosicaoY, int VelocidadeY) : Obstaculo( PosicaoX, PosicaoY) {
		this->velocidade.y = VelocidadeY;
		std::cout << "Bola criada!" << std::endl;
	}

	void setConfigTexture(){
		this->corpoCircular.setTextureRect(sf::IntRect (0, 0, 32, 32));
		this->corpo.setScale(sf::Vector2f (2.0f, 2.0f));
	}

	sf::CircleShape& getBolaDeFeno(){
		return corpoCircular;
	}

	void changeFrameObstaculo(int Tempo){
		switch(Tempo){
		case 1:
			corpoCircular.setTextureRect(sf::IntRect (0, 0, 32, 32));
			break;
		case 2:
			corpoCircular.setTextureRect(sf::IntRect (32, 0, 32, 32));
			break;
		case 3:
			corpoCircular.setTextureRect(sf::IntRect (0, 32, 32, 32));
			break;
		case 4:
			corpoCircular.setTextureRect(sf::IntRect (32, 32, 32, 32));
			break;
		}
	}
};

//class Trem: public Obstaculo {
//public:
//	using Obstaculo::Obstaculo;
//	void Movimenta() {
//		//	posx = posx + velx * 1;
//		posy = posy + vely * 1;
//		shape.setPosition(posx, posy);
//		sf::sleep(sf::seconds(0.03));
//	}
//};

/*
no main: 
antes do loop : BolaFeno bolinha(window); (para a bola de feno )
dentro do loop do jogo: 
        bolinha.TestaLimite(window);
		bolinha.Movimenta();
		bolinha.Desenha(window);
*/
#endif
