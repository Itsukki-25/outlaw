#include "player.hpp"
//Nos teste de colisão eu não consegui entender os codigos de player e do mapa, mas é só trocar as palavras 'Player' e 'mapa' pelas respectivas coisas lá
class bala : protected movel {
public:
    sf::RectangleShape corpo;
    int coli = 0;
    int vida = 0;

    int movimentos(player jogador, ) {
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
            while (coli == 0) {
                movimento(pos);
                corpo.setPosition(pos[0], pos[1]);  // Definir a posição corretamente

                if (corpo.getGlobalBounds().intersects(jogador.getCorpo())) {
                    vida = 1;
                    break;
                }

                if (corpo.getGlobalBounds().intersects(mapa)) {
                    coli = 1;

                    while (coli == 1) {
                        if (corpo.getGlobalBounds().intersects(jogador.getCorpo())) {
                            vida = 1;
                            break;
                        }

                        corpo.setPosition(pos[0], pos[1] * -1);

                        if (coli == 2) {
                            coli = 3;
                        }
                    }
                }
            }
        }

        return vida;
    }
};
