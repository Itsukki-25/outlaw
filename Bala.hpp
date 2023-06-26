#include "player.hpp"
#include "Movel.hpp"
#include <SFML/Graphics.hpp>

class bala: protected movel {

public:
	sf::RectangleShape corpo;
	int coli = 0;
	int vida = 0;


	int movimentos(Player jogador, sf::RectangleShape (*mapa)[40], int alt, int larg) {
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
			while (coli == 0) {
				movimento();
				corpo.setPosition(pos[0], pos[1]); // Definir a posiÃ§Ã£o corretamente

				// if (corpo.getGlobalBounds().intersects(jogador.getCorpo())) {
				//     vida = 1;#include <SFML/Graphics.hpp>
				//     break;
				// }

				for (int i = 0; i < alt; i++) {
					for (int j = 0; j < larg; j++) {
						if (mapa[i][j].getFillColor() == sf::Color::Blue) {
							if (corpo.getGlobalBounds().intersects(
									mapa[i][j].getGlobalBounds())) {
								vida = 1;
								break;
							}

							if (corpo.getGlobalBounds().intersects(mapa[i][j].getGlobalBounds())){
								coli = 1;

								while (coli == 1) {
									if (corpo.getGlobalBounds().intersects(jogador.getCorpo().getGlobalBounds())) {
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
				}
			}
		}

		return vida;
	}
};
