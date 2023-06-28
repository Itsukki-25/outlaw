#include <SFML/Graphics.hpp>
#include <iostream>
/*
 * funções contrutoras inicializam valores em uma classe <- descobri agr, 28/06, 17:34
 */
class Movel {
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
	void Desenha(sf::RenderWindow& window){
		window.clear();
		window.draw(shape);
		window.display();
	}

};

int main() {
	sf::RenderWindow window(sf::VideoMode(640, 480), "SFML POOL!");
//	int tempo = 1;

//	float tamanho = 10;
//	int posx = window.getSize().x / 2;
//	int posy = window.getSize().y / 2;
//	int velx = -5, vely = 5;
//	sf::Color cor = sf::Color::Green;
//	sf::CircleShape shape(tamanho);
//	shape.setFillColor(cor);
//	shape.setOrigin(tamanho / 2, tamanho / 2);
//	shape.setPosition(posx, posy);

	while (window.isOpen()) {
		sf::Event event;
		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed)
				window.close();
		}
		Movel bolinha;
//		bolinha.Desenha();
		bolinha.InicializaValores(window);
		bolinha.TestaLimite( window);
		bolinha.Movimenta();
		bolinha.Desenha( window);

//		{ //Teste Limites e inverte a velocidade se preciso
//			vely = posy < window.getSize().y ? vely : -vely;
//			velx = posx < window.getSize().x ? velx : -velx;

//			vely = posy > 0 ? vely : -vely;
//			velx = posx > 0 ? velx : -velx;
//		}

		//std::cout <<"px="<< posx <<";vx="<<velx;
		//std::cout <<";py="<< posy <<";vy="<<vely<< std::endl;

//		posx = posx + velx * tempo;
//		posy = posy + vely * tempo;
//		shape.setPosition(posx, posy);
//		sf::sleep(sf::seconds(0.05));

//		window.clear();
//		window.draw(shape);
//		window.display();
	}

	return 0;
}
