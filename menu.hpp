/*
 * Menu.cpp
 *
 *  Created on: 8 de jun. de 2023
 *      Author: guima
 */

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <iostream>
#include "Bot.hpp"
#include "ModoDeJogo.hpp"
#include "janela.hpp"
#include "efeitos.hpp"
#include "Textos.hpp"
#include "config.hpp"

class menu {
public:
	Botao start;
	Botao Sair;
	Janela *janela;
	efeitos efeito;
	int *controlPanel;
	Textos titulo;
	void Coisa() {


		titulo.adicionarTexto("Outlaw", 150, 330, 100);


		start.setTexture(efeito.Tbotao);
		start.setTexto(Text("Play", efeito.fonte, 60), efeito.fonte,200,480);
		start.estrutura.setPosition(150, 490);

		Sair.setTexture(efeito.Tbotao);
		Sair.setTexto(Text("Sair", efeito.fonte, 60), efeito.fonte,100,590);
		Sair.estrutura.setPosition(50, 600);


		sf::Vector2i mousePos = sf::Mouse::getPosition(janela->window);

		if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
			if (start.contemPonto(mousePos)) {
				std::cout << "Clicou no start\n";
				*controlPanel = 1;
			}
			if (Sair.contemPonto(mousePos)) {
				std::cout << "Clicou no sair\n";
				janela ->window.close();
			}
		}

		janela->window.draw(efeito.fundoImage);

		titulo.desenharTextos(janela->window);
		janela->window.draw(start);
		janela->window.draw(Sair);
			// Desenha backgroud
	}

};
