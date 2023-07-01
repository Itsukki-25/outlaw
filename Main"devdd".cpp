

#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>

#include "Menu.hpp"
#include "ModoDeJogo.hpp"
#include "efeitos.hpp"
#include "janela.hpp"
#include "config.hpp"

int main() {
	Janela* janela = new Janela();
	int controlPanel = 0;

	menu meun;
	meun.janela = janela;
	meun.controlPanel = &controlPanel;


	Modo modo;
	modo.janela = janela;
	modo.controlPanel = &controlPanel;


	while(janela->window.isOpen()) {
		sf::Event ev;
		while(janela->window.pollEvent(ev)) {
			if (ev.type == sf::Event::Closed)
				janela->window.close();
		}

		janela->window.clear(sf::Color::Black);
		switch(controlPanel){
		case 0:
			meun.Coisa();
			break;
		case 1:
			modo.escolha();
			break;
		}
		janela->window.display();
	}

	delete janela;

	return 0;
}

