

#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>

#include "Menu.hpp"
#include "ModoDeJogo.hpp"
#include "Efeito.hpp"
#include "janela.hpp"
#include "configuracao.hpp"
#include "TelaFinal.hpp"
#include "fase.hpp"

int main() {
	efeitos musica;
	Janela* janela = new Janela();
	int controlPanel = 0;


	Fase fase;
	fase.janela =janela;
	fase.controlPanel = &controlPanel;

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
		fase.iniciarjogo();
			break;
		case 2:
			modo.escolha();
			break;
		case 3:
			final.UltimaTela();
			break;
		case 4:
			con.config(2);
		}

		janela->window.display();
	}

	delete janela;

	return 0;
}

