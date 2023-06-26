//obstáculos(teste).cpp
/*
 * teste.cpp
 *
 *  Created on: 26 de mai. de 2023
 *      Author: Isabela
 */

/*
 * main.cpp
 *
 *  Created on: 26 de mai. de 2023
 *      Author: Isabela
 */
//#include <SFML/Graphics.hpp>
//#include <iostream>
#include"classe.hpp"
int main() {
	sf::RenderWindow window(sf::VideoMode(700, 540), "Bolinha ");
	//int tempo = 1;

//	float tamanho = 10;
//
//	int posx = 320;
//	int posy = window.getSize().y;
//	int velx = -5, vely = 5;
//	sf::Color cor = sf::Color::Green;
//	sf::CircleShape shape(tamanho);
//	shape.setFillColor(cor);
//	shape.setOrigin(tamanho / 2, tamanho);
//	shape.setPosition(posx, posy);

	while (window.isOpen()) {
		sf::Event event;
		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed)
				window.close();
		}
		std::string nome_txt = "boladefeno.jpeg";
		Objeto_Movel bolinha;

		//bolinha.Set_textura(nome_txt) ;

//		{ //Teste Limites e inverte a velocidade se preciso
//			vely = posy < window.getSize().y ? vely : -vely;
//			//velx = posx < window.getSize().x? velx: -velx;
//
//			vely = posy > 0 ? vely : -vely;
//			// velx = posx > 0? velx: -velx;
//		}

	//	std::cout << "px=" << posx << ";vx=" << velx;
	//	std::cout << ";py=" << posy << ";vy=" << vely << std::endl;

		//posx = window.getSize().x / 1.55;
		//posx = 320;
		//posx = tamanho / 2;
		//posy = posy + vely * tempo;
		//shape.setPosition(posx, posy);

		window.clear();
	//	window.draw( );
		window.draw(bolinha.shape);
		window.display();
		//sf::sleep(sf::seconds(0.02));
	}

	return 0;
}
