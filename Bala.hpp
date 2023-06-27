#ifndef BALA_HPP_
#define BALA_HPP_

#include <SFML/Graphics.hpp>
#include <iostream>
#include "player.hpp"
#include "Movel.hpp"

class Bala : protected movel {
public:
    sf::RectangleShape corpo;
    int coli = 0;
    int vida = 0;

    void Movimento(int direcaoY, int direcaoX) {
        switch (direcaoY) {
            case -1:
                switch (direcaoX) {
                    case 0:
                        dir[1] = -1;
                        break;
                    case -1:
                        dir[0] = -1;
                        dir[1] = -1;
                        break;
                    case 1:
                        dir[0] = 1;
                        dir[1] = -1;
                        break;
                }
                break;
            case 0:
                switch (direcaoX) {
                    case -1:
                        dir[0] = -1;
                        break;
                    case 1:
                        dir[0] = 1;
                        break;
                }
                break;
            case 1:

                break;
        }
    }

    void Atirar(int direcaoY, int direcaoX, int jogador, int posiX, int posY) {
        if (jogador == 1) {
            Movimento(direcaoY, direcaoX);
        } else if (jogador == 2) {

        }

        corpo.setPosition(posiX, posY);
    }

    int Movimentos(Player jogador, sf::RectangleShape (*mapa)[40]) {
        while (coli == 0) {
            movimento(pos);
            corpo.setPosition(pos[0], pos[1]);

            if (corpo.getGlobalBounds().intersects(jogador.getCorpo())) {
                vida = 1;
                break;
            }

            for (int i = 0; i < alt; i++) {
                for (int j = 0; j < larg; j++) {
                    if (mapa[i][j].getFillColor() == sf::Color::Blue) {
                        if (corpo.getGlobalBounds().intersects(mapa[i][j].getGlobalBounds())) {
                            vida = 1;
                            break;
                        }
                    }
                }
            }

            if (corpo.getPosition().x < 0 || corpo.getPosition().x > largura_do_mapa) {
                vida = 1;
                break;
            }
        }

        return vida;
    }
};

#endif /* BALA_HPP_ */
