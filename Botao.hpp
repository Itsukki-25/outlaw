/*
 * Declaracoes.hpp
 *
 *  Created on: 8 de jun. de 2023
 *      Author: guima
 */

#include <SFML/Graphics.hpp>
#include <SFML/audio.hpp>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <iostream>
#include "efeitos.hpp"
using namespace sf;

#ifndef DECLARACOES_HPP_
#define DECLARACOES_HPP_




class Botao : public Drawable {
public:

    RectangleShape estrutura,sombras;

    Text texto;
    float posX,posY;


    Botao(float largura = 300, float comprimento = 80, Color cor = Color::White,float posx=0,float posY=0,bool clique=false)

        : estrutura(Vector2f(largura, comprimento)), texto()

    {
         this-> posX=posx;
        this-> posY=posY;

        estrutura.setFillColor(cor);
        estrutura.setPosition(posx,posY);
    }


    void setTexture(const sf::Texture& textura)
       {
           estrutura.setTexture(&textura);
       }

    void setTexto(const Text& novoTexto, const Font& fonte, float posx,float posy) {

        texto = novoTexto;
        texto.setFont(fonte);
        texto.setPosition(posx,posy);
    }
    void draw(RenderTarget& target, RenderStates states) const override {

    	target.draw(estrutura, states);

        target.draw(texto, states);
    }


    bool contemPonto(const sf::Vector2i& ponto) {

        return estrutura.getGlobalBounds().contains(sf::Vector2f(ponto.x, ponto.y));
    }
};
#endif /* DECLARACOES_HPP_ *///

