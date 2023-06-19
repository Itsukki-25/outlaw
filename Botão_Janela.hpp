/*
 * Declaracoes.hpp
 *
 *  Created on: 8 de jun. de 2023
 *      Author: guima
 */








#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <stdlib.h>
Expand All
	@@ -6,38 +20,46 @@
#include <iostream>

using namespace sf;
#ifndef DECLARACOES_HPP_
#define DECLARACOES_HPP_

sf::Font fonte;


class Janela {


public:
    sf::VideoMode desktopMode;
    sf::RenderWindow window;

    Janela()
        : desktopMode(sf::VideoMode::getDesktopMode()),
          window(desktopMode, "Jogo", sf::Style::Fullscreen)
    {
    }

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


Expand All
	@@ -47,33 +69,37 @@ class Botao : public Drawable {
    Text texto;
    float posX,posY;

    Botao(float largura = 50, float comprimento = 50, Color cor = Color::White,float posx=0,float posY=0,bool clique=false)

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
