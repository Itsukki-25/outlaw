#include "player.hpp"
//Nos teste de colisão eu não consegui entender os codigos de player e do mapa, mas é só trocar as palavras 'Player' e 'mapa' pelas respectivas coisas lá
class bala : protected movel {
public:
    sf::RectangleShape corpo;
    int coli = 0;
    int vida = 0;

    int movimentos(Player jogador, sf::RectangleShape) {
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
            while (coli == 0) {
                movimento(pos);
                corpo.setPosition(pos[0], pos[1]);  // Definir a posição corretamente

                // if (corpo.getGlobalBounds().intersects(jogador.getCorpo())) {
                //     vida = 1;
                //     break;
                // }

            for (int i = 0; i < alt; i++) {
			     for (int j = 0; j < larg; j++) {
				     if(mapa[i][j].getFillColor() == sf::Color::Blue){
					     if(jogador.getCorpo().getGlobalBounds().intersects(mapa[i][j].getGlobalBounds())){
						     colidiu = true;
					     }
				     }
			     }
		     }


                if (corpo.getGlobalBounds().intersects(mapa.getCasa)) {
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
