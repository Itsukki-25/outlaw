#ifndef BALA_HPP_
#define BALA_HPP_

#include <SFML/Graphics.hpp>
#include <iostream>
#include "player.hpp"
#include "Movel.hpp"

class Bala : public movel {

private:

    bool coli = false;
    bool vida = true;
    int direcaoY = 0;
    int direcaoX = 0;
    sf::Vector2f posicao;
    int codigoJogador = 0;
    //sf::Vector2u ;


public:

    Bala( int VelX, int VelY, Player jogador ){

    	this->codigoJogador = jogador.getCodigo();
		this->posiX = jogador.getPosicaoV2f().x;
		this->posiY = jogador.getPosicaoV2f().y - 20;
		this->velX = VelX;
		this->velY = VelY;
		if(jogador.getCodigo() == 1)
			this->corpo.setPosition(jogador.getPosicaoV2f().x, jogador.getPosicaoV2f().y + 80);
		if(jogador.getCodigo() == 2)
			this->corpo.setPosition(jogador.getPosicaoV2f().x + 75, jogador.getPosicaoV2f().y + 78);
		this->corpo.setFillColor(sf::Color::Yellow);
		corpo.setSize(sf::Vector2f(largura, altura));
    }

	bool getVida(){
		return vida;
	}

    int movimentos(Player& jogador, Bloco (*mapa)[40], int altura, int largura) {

    	corpo.move(0,velY);

    	for (int i = 0; i < altura; i++) {
    		for (int j = 0; j < largura; j++) {
    			if (mapa[i][j].solido) {
    				if (corpo.getGlobalBounds().intersects(mapa[i][j].corpo.getGlobalBounds())) {
    					corpo.move(0,-velY);
    					if(velY != 0){
    						velY = -velY;
    					}else{
    						vida = false;
    					}
    				}
    			}
    		}
    	}

    	corpo.move(velX,0);

    	for (int i = 0; i < altura; i++) {
    		for (int j = 0; j < largura; j++) {
    			if (mapa[i][j].solido) {
    				if (corpo.getGlobalBounds().intersects(mapa[i][j].corpo.getGlobalBounds()))
    					vida = false;
    			}
    		}
    	}

    	if ((corpo.getGlobalBounds().intersects(jogador.getCorpo().getGlobalBounds())) && (jogador.getCodigo() != codigoJogador)) {
    		vida = false;
    		jogador.getVida()--;
    	}

        return vida;
    }
};

#endif /* BALA_HPP_ */
