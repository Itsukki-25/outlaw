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
#include "Botao.hpp"
#include "ModoDeJogo.hpp"
#include "janela.hpp"
#include "efeitos.hpp"
#include "Textos.hpp"
#include "config.hpp"
#include "Sombras.hpp"

class menu {
public:
	Botao start;
	Botao Sair;
	Botao configuracoes;
	Sombra SombraStart;
	Sombra SombraSair;
	Sombra SombraConfiguracoes;
	Janela *janela;
	int *controlPanel;
	efeitos efeito;
	Textos titulo;

	bool	sontocando=true;
	bool	musicaTocando = true;



	void OMenu() {

		// Resto do código do construtor...

		sf::Vector2i mousePos = sf::Mouse::getPosition(janela->window);

		titulo.adicionarTexto("Outlaw", 150, 330, 100);
		start.estrutura.setPosition(150, 490);
		SombraStart.Comportamento(300, 80, 160, 500,sf::Color::Black);
		start.setTexture(efeito.TexturaBotao);

		start.setTexto(Text("Play", efeito.fonte, 60), efeito.fonte, 210 , 480);
		//210

		Sair.setTexture(efeito.TexturaBotao);
		Sair.setTexto(Text("Sair", efeito.fonte, 60), efeito.fonte, 100, 590);
		Sair.estrutura.setPosition(50, 600);
		SombraSair.Comportamento(300, 80, 60, 610,sf::Color::Black);

		 sf::CircleShape BotaoConfig(40);
		 sf::Color cor(255, 128, 77, 255);
		 BotaoConfig.setFillColor(cor);
		 BotaoConfig.setPosition(1250,10);
		



		if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
			if (start.contemPonto(mousePos)) {

				efeito.Sons(sontocando);
				std::cout << "Clicou no start\n";
				*controlPanel = 1;

			}
			if (Sair.contemPonto(mousePos)) {
				std::cout << "Clicou no sair\n";
				janela->window.close();
			}

			if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
			    if (BotaoConfig.getGlobalBounds().contains(mousePos.x, mousePos.y)) {
				    efeito.Sons(sontocando);
			    		*controlPanel=4;
			    }
			}
		}

				// Atualizar a posição do mouse
		mousePos = sf::Mouse::getPosition(janela->window);

		// Atualizar a animação do botão "start" com base na posição do mouse

		janela->window.draw(efeito.fundoImage);
		titulo.desenharTextos(janela->window);
		janela->window.draw(SombraSair);
		janela->window.draw(SombraStart);
		janela->window.draw(start);
		janela->window.draw(Sair);
		janela->window.draw(BotaoConfig);
		
	}
};


