#ifndef BALA_HPP_
#define BALA_HPP_

#include <SFML/Graphics.hpp>
#include <iostream>
#include "player.hpp"
#include "Movel.hpp"

class Bala : public Movel {
private:

    bool vida = true;
    int codigoJogador;

public:

    Bala( int VelocidadeX, int VelocidadeY, Player player ){

    	this->codigoJogador = player.getIdPlayer();
		this->posicao.x = player.getPosicaoV2f().x;
		this->posicao.y = player.getPosicaoV2f().y - 20;
		this->velocidade.x = VelocidadeX;
		this->velocidade.y = VelocidadeY;
		this->tamanho.x = 5;
		this->tamanho.y = 5;
		this->numeroVida = 2;

		if(player.getIdPlayer() == 1)
			this->corpo.setPosition(player.getPosicaoV2f().x, player.getPosicaoV2f().y + 50);
		if(player.getIdPlayer() == 2)
			this->corpo.setPosition(player.getPosicaoV2f().x + 55, player.getPosicaoV2f().y + 50);

		this->corpo.setFillColor(sf::Color::Yellow);
		corpo.setSize(sf::Vector2f(tamanho.x, tamanho.y));
    }

	bool& getVidaBala(){
		return vida;
	}

    int movimentos(Player& player, Bloco (*mapa)[40], int numeroLinhas, int numeroColunas) {

    	corpo.move(0,velocidade.y);

    	bool colisaEixoY = false;

		if(testeColisaoMapa( mapa, numeroLinhas, numeroColunas)){

			colisaEixoY = true;

			corpo.move(0,-velocidade.y);
			numeroVida--;
			if(velocidade.y != 0)
				velocidade.y = -velocidade.y;

			if(numeroVida<0)
				vida = false;

		}

    	corpo.move(velocidade.x,0);

		if(testeColisaoMapa( mapa, numeroLinhas, numeroColunas)){
			corpo.move(-velocidade.x,0);
			numeroVida--;

			if(velocidade.y == 0 || !colisaEixoY)
				velocidade.x = -velocidade.x;

			if(velocidade.y == 0)
				numeroVida--;

			if(numeroVida<0)
				vida = false;

		}

    	if ((corpo.getGlobalBounds().intersects(player.getCorpo().getGlobalBounds())) && (player.getIdPlayer() != codigoJogador)) {
    		vida = false;
    		player.getNumeroVida()--;
    	}

        return vida;
    }
};

#endif /* BALA_HPP_ */
