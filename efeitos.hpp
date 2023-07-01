/*
 * efeitos.hpp
 *
 *  Created on: 30 de jun. de 2023
 *      Author: guima
 */

#ifndef EFEITOS_HPP_
#define EFEITOS_HPP_
class efeitos {
public:
    sf::Font fonte;
    sf::SoundBuffer tiro;
    sf::Sound tiros;
    sf::Music musica;
    sf::SoundBuffer clik;
    sf::Sound clique;
    sf::Texture textureFundo;
    sf::Sprite fundoImage;
    sf::Texture Tbotao;
    sf::Texture Mododejogo;
    sf::Sprite Modo;

    	efeitos()
    {
    	Mododejogo.loadFromFile("assets/Modo.jpg");
    	Modo.setTexture(Mododejogo);
    	Tbotao.loadFromFile("assets/Tbotao.jpg");
    	textureFundo.loadFromFile("assets/cowboy.jpg");
		fundoImage.setTexture(textureFundo);
        fonte.loadFromFile("assets/fonte.TTF");
        tiro.loadFromFile("assets/tiro.ogg");
        tiros.setBuffer(tiro);
        clik.loadFromFile("assets/clique.ogg");
        clique.setBuffer(clik);

    }
};
#endif /* EFEITOS_HPP_ */
