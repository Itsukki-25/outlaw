#ifndef MOVEL_HPP_
#define MOVEL_HPP_

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>

class Movel {
public:
    float pos[2], dir[2], vel;
    bool colisao;
    sf::RectangleShape corpos;
	int velX;
	int velY;
	int posiX;
	int posiY;
	sf::Vector2f posicao;
    int altura = 5;
    int largura = 5;
	sf::Vector2f tamanho;

	RectangleShape getCorpo(){
		return corpo;
	}

protected:
    bool tcolisao(bool coli, sf::RectangleShape corpo) {
        this->colisao = coli;
        this->corpos = corpo;
        return coli;
    }

    virtual float Direcao(float dir[1] = 0) {
        this->dir[1] = dir[1];

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
            dir[1] = 1;
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
            dir[1] = -1;
        }

        return dir[1];
    }

    virtual float movimento(float pos[0]) {
        this->pos[0] = pos[0];

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
            pos[1] = pos[1] + (dir[1] * vel);
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
            pos[1] = pos[1] + (dir[1] * vel);
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
            pos[0] = pos[0] + (vel * 1);
        }

        return pos[0];
    }

    virtual ~Movel() {}
};

#endif /* MOVEL_HPP_ */
