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

class Sombra : public sf::Drawable {
public:
    sf::RectangleShape sombra;

    void Comportamento(float width, float height, float posX, float posY,sf::Color cor) {
        sombra.setSize(sf::Vector2f(width, height));
        sombra.setPosition(posX, posY);
        sombra.setFillColor(cor); // Define a cor e a transparência da sombra
    }
    void animacao(float posx,float posy){
       	sombra.setPosition(posx -5, posy-5);
       }


    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const {
        target.draw(sombra, states);
    }


};




#endif /* SOMBRAS_HPP_ */
