#ifndef BALA_HPP_
#define BALA_HPP_

#include <SFML/Graphics.hpp>
#include <iostream>
#include "Player.hpp"
#include "Movel.hpp"

class Bala : public Player {
public:
    sf::RectangleShape corpos;
    int coli = 0;
    int vida = 0;
    Movel mov;

    void Movimento(int direcaoY, int direcaoX) {
        switch (direcaoY) {
            case -1:
                switch (direcaoX) {
                    case 0:
                        mov.dir[1] = -1;
                        break;
                    case -1:
                        mov.dir[0] = -1;
                        mov.dir[1] = -1;
                        break;
                    case 1:
                        mov.dir[0] = 1;
                        mov.dir[1] = -1;
                        break;
                }
                break;
            case 0:
                switch (direcaoX) {
                    case -1:
                        mov.dir[0] = -1;
                        break;
                    case 1:
                        mov.dir[0] = 1;
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
            // Lógica para jogador 2
        }

        corpos.setPosition(posiX, posY);
    }

    int Movimentos(Player jogador, sf::RectangleShape (*mapa)[40]) {
        while (coli == 0) {
            mov.movimento();
            corpos.setPosition(mov.pos[0], mov.pos[1]);

            if (corpos.getGlobalBounds().intersects(jogador.getCorpo().getGlobalBounds())) {
                vida = 1;
                break;
            }

            for (int i = 0; i < alt; i++) {
                for (int j = 0; j < larg; j++) {
                    if (mapa[i][j].getFillColor() == sf::Color::Blue) {
                        if (corpos.getGlobalBounds().intersects(mapa[i][j].getGlobalBounds())) {
                            vida = 1;
                            break;
                        }
                    }
                }
            }

            if (corpos.getPosition().x < 0 || corpos.getPosition().x > larg) {
                vida = 1;
                break;
            }
        }

        return vida;
    }
};

#endif /* BALA_HPP_ */
