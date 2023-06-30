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

using namespace sf;
#ifndef DECLARACOES_HPP_
#define DECLARACOES_HPP_

class efeitos {
public:
    sf::Font fonte;
    sf::SoundBuffer tiro;
    sf::Sound tiros;
    sf::Music musica;
    sf::SoundBuffer clik;
    sf::Sound clique;

    efeitos()
    {
        fonte.loadFromFile("assets/fonte.ttf");
        tiro.loadFromFile("assets/tiro.ogg");
        tiros.setBuffer(tiro);
        clik.loadFromFile("assets/clique.ogg");
        clique.setBuffer(clik);

    }
};


class Janela {
public:
    sf::VideoMode desktopMode;
    sf::RenderWindow window;

    Janela()

        : desktopMode(sf::VideoMode::getDesktopMode()),
          window(desktopMode, "Jogo", sf::Style::Fullscreen)

    {
    }
    sf::Vector2u screenSize = window.getSize();
    virtual void executar()
    {

        while (window.isOpen())
        {

            sf::Event event;

            while (window.pollEvent(event))
            {
                if (event.type == sf::Event::Closed)
                    window.close();
            }

            window.clear();

            window.display();
        }

    }
    virtual ~Janela() {}
};


class Botao : public Drawable {
public:
	efeitos fonte;
    RectangleShape estrutura;
    Text texto;
    float posX,posY;

    Botao(float largura = 50, float comprimento = 40, Color cor = Color::White,float posx=0,float posY=0,bool clique=false)

        : estrutura(Vector2f(largura, comprimento)), texto()
    {
         this-> posX=posx;
        this-> posY=posY;
        estrutura.setFillColor(cor);
        estrutura.setPosition(posx,posY);
    }

    void setTexto(const Text& novoTexto, const Font& fonte) {

        texto = novoTexto;
        texto.setFont(fonte);
    }
    void draw(RenderTarget& target, RenderStates states) const override {
        target.draw(estrutura, states);
        target.draw(texto, states);
    }
    bool contemPonto(const sf::Vector2f& ponto) {

        return estrutura.getGlobalBounds().contains(ponto);
    }

};
#endif /* DECLARACOES_HPP_ */
