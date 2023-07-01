/*
 * ModoDeJogo.hpp
 *
 *  Created on: 19 de jun. de 2023
 *      Author: guima
 */

#ifndef MODODEJOGO_HPP_
#define MODODEJOGO_HPP_

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <iostream>
#include "Bot.hpp"
#include "janela.hpp"
#include "efeitos.hpp"
#include "Textos.hpp"

class Modo {
public:
	Botao Solo;
	Botao dois;
	Janela *janela;
	efeitos efeito;
	Textos Mododejogo;
	int *controlPanel;

	void escolha() {
		Mododejogo.adicionarTexto("Modo de jogo", 100, 200, 100);
		Solo.setTexture(efeito.Tbotao);
		Solo.setTexto(Text("1 VS IA", efeito.fonte, 52), efeito.fonte,750,300);
		Solo.estrutura.setPosition(700, 300);


		dois.setTexture(efeito.Tbotao);
		dois.setTexto(Text("1 VS 1", efeito.fonte, 52), efeito.fonte,350,300);
		dois.estrutura.setPosition(300,300);

		sf::Vector2i mousePos = sf::Mouse::getPosition(janela->window);

		if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
			if (Solo.contemPonto(mousePos)) {
				std::cout << "TELA DIFERENTE1\n";
			}
			if (dois.contemPonto(mousePos)) {
				std::cout << "TELA DIFETENTE2\n";
			}
		}
		janela->window.draw(efeito.Modo);
		Mododejogo.desenharTextos(janela->window);
		janela->window.draw(Solo);
		janela->window.draw(dois);
	}

};

#endif /* MODODEJOGO_HPP_ */
