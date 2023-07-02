

#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>

#include "Menu.hpp"
#include "ModoDeJogo.hpp"
#include "efeitos.hpp"
#include "janela.hpp"
#include "config.hpp"
#include "TelaFinal.hpp"

int main() {
	efeitos musica;
	Janela* janela = new Janela();
	int controlPanel = 0;

	Controle con;
	con.janela = janela;
	con.controlPanel =&controlPanel;

	menu meun;
	meun.janela = janela;
	meun.controlPanel = &controlPanel;

	Final final;
	final.janela =janela;
	final.controlPanel = &controlPanel;

	Modo modo;
	modo.janela = janela;
	modo.controlPanel = &controlPanel;

	musica.IniciarMusica(0);
	while(janela->window.isOpen()) {
		sf::Event ev;
		while(janela->window.pollEvent(ev)) {
			if (ev.type == sf::Event::Closed)
				janela->window.close();
		}

		janela->window.clear(sf::Color::Black);
		switch(controlPanel){
		case 0:
			meun.OMenu();
			break;
		case 1:
			con.config(3);
			break;
		case 2:

			break;
		}

		janela->window.display();
	}

	delete janela;

	return 0;
}

