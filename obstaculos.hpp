/*
 * classe.hpp
 *
 *  Created on: 20 de jun de 2023
 *      Author: Isabela
 */
#include <SFML/Graphics.hpp>
#include <iostream>

class Objeto {
private:
	int tempo = 1;
	int windowx = 700 ;
	int windowy = 540 ;
	int tamanho = 10;

	int posx;
	int posy;
	int velx, vely;
	sf::Color cor = sf::Color::Green;


public:
	void DeclaraSFML(int tamanho,  int posy){
//		this->posx = posx;
//		this->posy = posy;
//		this->tamanho = tamanho;
		sf::CircleShape shape(tamanho);
		shape.setFillColor(cor);
		shape.setOrigin(tamanho / 2, tamanho);
		shape.setPosition(posx, posy);

	}
	void TestaLimites(){ //Teste Limites e inverte a velocidade se preciso

				vely = posy < windowy ? vely : -vely;
				//velx = posx < window.getSize().x? velx: -velx;

				vely = posy > 0 ? vely : -vely;
				// velx = posx > 0? velx: -velx;
			}
	void MudaPosicao(){
		posy = posy + vely * tempo;
		sf::shape.setPosition(posx, posy);
		sf::sleep(sf::seconds(0.02));
	}


};
