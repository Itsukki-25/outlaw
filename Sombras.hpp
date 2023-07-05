/*
 * Sombras.hpp
 *
 *  Created on: 5 de jul. de 2023
 *      Author: user
 */
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#ifndef SOMBRAS_HPP_
#define SOMBRAS_HPP_

class Sombra{

public:
	sf::RectangleShape sombra;
	void Comportamento(float tamanhox,float tamanhoy,float posx,float posy, sf::Color cor){

		sombra.setScale(tamanhox,tamanhoy);
		sombra.setPosition(posx,posy);
		sombra.setFillColor(cor);
	}

	 void draw(RenderTarget& target, RenderStates states){

	    	target.draw(sombra, states);


	    }


};



#endif /* SOMBRAS_HPP_ */
