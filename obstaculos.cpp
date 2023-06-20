#include <SFML/Graphics.hpp>
#include <iostream>

int main() {
	sf::RenderWindow window(sf::VideoMode(640, 480), "SFML É MELHOR QUE SDL!");
	int tempo = 1;

	float tamanho = 10;

	int posx = 320;
	int posy = window.getSize().y;
	int velx = -5, vely = 5;
	sf::Color cor = sf::Color::Green;
	sf::CircleShape shape(tamanho);
	shape.setFillColor(cor);
	shape.setOrigin(tamanho / 2, tamanho);
	shape.setPosition(posx, posy);

	while (window.isOpen()) {
		sf::Event event;
		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed)
				window.close();
		}

		{ //Teste Limites e inverte a velocidade se preciso
			vely = posy < window.getSize().y ? vely : -vely;
			//velx = posx < window.getSize().x? velx: -velx;

			vely = posy > 0 ? vely : -vely;
			// velx = posx > 0? velx: -velx;
		}

		std::cout << "px=" << posx << ";vx=" << velx;
		std::cout << ";py=" << posy << ";vy=" << vely << std::endl;

		//posx = window.getSize().x / 1.55;
		posx = 320;
		//posx = tamanho / 2;
		posy = posy + vely * tempo;
		shape.setPosition(posx, posy);

		window.clear();
		window.draw(shape);
		window.display();
		sf::sleep(sf::seconds(0.02));
	}

	return 0;
}
