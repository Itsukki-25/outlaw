#include <SFML/Graphics.hpp>
#include <iostream>
/*
 * funções contrutoras inicializam valores em uma classe <- descobri agr, 28/06, 17:34
 */
class Obstaculo {
protected:
	float tamanho = 10;
	int posx;
	int posy;
	int velx = -5;
	int vely = 5;
	sf::Color cor = sf::Color::Green;
	sf::CircleShape shape;

public:
	InicializaValores(sf::RenderWindow& window) {
		posx = window.getSize().x / 2;
		posy = window.getSize().y / 2;
		shape.setRadius(tamanho);
		shape.setFillColor(cor);
		shape.setOrigin(tamanho / 2, tamanho / 2);
		shape.setPosition(posx, posy);
	}
	void TestaLimite(sf::RenderWindow& window) {
		vely = posy < window.getSize().y ? vely : -vely;
		velx = posx < window.getSize().x ? velx : -velx;
		//inverte se necessário
		vely = posy > 0 ? vely : -vely;
		velx = posx > 0 ? velx : -velx;
	}
	void Movimenta() {
		posx = posx + velx * 1;
		posy = posy + vely * 1;
		shape.setPosition(posx, posy);
		sf::sleep(sf::seconds(0.05));
	}
	void Desenha(sf::RenderWindow& window) {
		window.clear();
		window.draw(shape);
		window.display();
	}

};
class BolaFeno:Obstaculo{
	void Movimenta() {
		//	posx = posx + velx * 1;
			posy = posy + vely * 1;
			shape.setPosition(posx, posy);
			sf::sleep(sf::seconds(0.05));
		}
};

int main() {
	sf::RenderWindow window(sf::VideoMode(640, 480), "SFML POOL!");
	BolaFeno bolinha;
	bolinha.InicializaValores(window);


	while (window.isOpen()) {
		sf::Event event;
		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed)
				window.close();
		}

		bolinha.TestaLimite(window);
		bolinha.Movimenta();
		bolinha.Desenha(window);

	}

	return 0;
}
