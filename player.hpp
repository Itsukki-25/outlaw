#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <iostream>
#include <vector>
#include <string>
#include <iterator>
#include <SFML/Graphics.hpp>

#include "bloco.hpp"
#include "Movel.hpp"

class Player : public Movel{
private:

	int numeroBalas;
	int idPlayer = 0;

public:

	Player(){

		this->velocidade.x = 0;
		this->velocidade.y = 0;
		this->posicao.x = 100;
		this->posicao.y = 200;
		this->tamanho.x = 64;
		this->tamanho.y = 128;
		this->numeroVida = 5;
		this->numeroBalas = 8;
		this->corpo.setPosition(posicao.x, posicao.y);
		this->corpo.setSize(sf::Vector2f(tamanho.x, tamanho.y));

		std::cout << "Objeto 'Player' criado!" << std::endl;
	};

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
	};

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

	void setNumeroBalas(int Balas){
		this->numeroBalas = Balas;
	}

	void setIdPlayer(int numeroId){
		this->idPlayer = numeroId;
	}

	int getIdPlayer(){
		return idPlayer;
	}

	int& getNumeroBalas(){
		return numeroBalas;
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
#endif
