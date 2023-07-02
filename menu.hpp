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
#include "Sombras.hpp"

class menu {
public:
	Botao start;
	Botao Sair;
	Sombra SombraStart;
	Sombra SombraSair;
	Janela *janela;
	int *controlPanel;
	efeitos efeito;
	Textos titulo;


	void OMenu() {
	    sf::Vector2i mousePos = sf::Mouse::getPosition(janela->window);

	    titulo.adicionarTexto("Outlaw", 150, 330, 100);
	    start.estrutura.setPosition(150, 490);
	   	SombraStart.Comportamento(300, 80, 160, 500);
	    start.setTexture(efeito.TexturaBotao);
	    start.setTexto(Text("Play", efeito.fonte, 60), efeito.fonte, 210, 480);


	    Sair.setTexture(efeito.TexturaBotao);
	    Sair.setTexto(Text("Sair", efeito.fonte, 60), efeito.fonte, 100, 590);
	    Sair.estrutura.setPosition(50, 600);
	    SombraSair.Comportamento(300, 80, 60, 610);

	    if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
	        if (start.contemPonto(mousePos)) {
	            efeito.cliqueBotao();
	            std::cout << "Clicou no start\n";
	            *controlPanel = 1;
	        }
	        if (Sair.contemPonto(mousePos)) {
	            std::cout << "Clicou no sair\n";
	            janela->window.close();
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
	}
};


