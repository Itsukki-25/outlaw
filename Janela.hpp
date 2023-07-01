/*
 * janela.hpp
 *
 *  Created on: 30 de jun. de 2023
 *      Author: guima
 */

#ifndef JANELA_HPP_
#define JANELA_HPP_

class Janela {
public:
    sf::VideoMode desktopMode;
    sf::RenderWindow window;
    sf::Image icon;

    Janela()
        : desktopMode(sf::VideoMode::getDesktopMode()),
          window(sf::VideoMode(1333, 750), "Jogo", sf::Style::Close | sf::Style::Titlebar)
    {

        if (!icon.loadFromFile("assets/icon.png")) {

        }


        icon.createMaskFromColor(sf::Color::Black, 0);


        window.setIcon(icon.getSize().x, icon.getSize().y, icon.getPixelsPtr());
    }

    sf::Vector2u screenSize = window.getSize();
    sf::Event event;

    ~Janela() {}
};

#endif /* JANELA_HPP_ */
