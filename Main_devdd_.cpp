

#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>

#include "Menu.hpp"
#include "ModoDeJogo.hpp"
#include "Efeito.hpp"
#include "Janela.hpp"
#include "configuracao.hpp"
#include "fase.hpp"
#include "Jogo.hpp"

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
		efeitos musica;
		musica.Musica(true,100);
		switch(controlPanel){

		case 0:
			musica.Musica(true,100);
			meun.OMenu();
			break;
		case 1:
			rodarJogo(janela->window,0);
			controlPanel = 0;
			break;
		case 2:
			modo.escolha();
			break;
		case 3:
			con.config(2);
			break;
		}

		janela->window.display();
	}

	delete janela;

	return 0;
}

