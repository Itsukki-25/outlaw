/*
 * classe.hpp
 *
 *  Created on: 20 de jun de 2023
 *      Author: Isabela
 */
#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
//class Objeto{
//	int tempo = 1;
//	int windowx = 700 ;
//	int windowy = 540 ;
//	int tamanho = 10;
//
//	int posx;
//		int posy;
//		int velx, vely;
//};
class Objeto_Movel {
private:
	int tempo = 1;
	int windowx = 700 ;
	int windowy = 540 ;
	int tamanho = 10;
	sf::CircleShape shape;
	int posx;
	int posy;
	int velx, vely;
	sf::Color cor = sf::Color::Yellow;
	sf::Texture texture;
//	string nome_textura;
//	texture.loadFromFile(nome_textura);

//	sf::Sprite sprite;
//	sprite.setTexture(texture);

public:
	void DeclaraSFML(int tamanho,  int posy){
	//	this->posx ;
//		this->cor;
//		this->posy ;
//		this->tamanho ;
		this->shape;
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
		this->shape = shape;
		posy = posy + vely * tempo;
		shape.setPosition(posx, posy);
		sf::sleep(sf::seconds(0.02));
	}


};


