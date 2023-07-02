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
#include "Botao.hpp"
#include "janela.hpp"
#include "efeitos.hpp"
#include "Textos.hpp"
#include "Sombras.hpp"
class Modo {
public:
	Botao Solo;
	Botao dois;
	Sombra SombraUm;
	Sombra SombraDois;
	Janela *janela;
	efeitos efeito;
	Textos Mododejogo;
	bool	sontocando=true;
		bool	musicaTocando =true;
	int *controlPanel;

	void escolha() {
		Mododejogo.adicionarTexto("Modo de jogo", 100, 200, 100);
		Solo.setTexture(efeito.TexturaBotao);
		Solo.setTexto(Text("1 VS IA", efeito.fonte, 52), efeito.fonte,750,300);
		Solo.estrutura.setPosition(700, 300);
		SombraUm.Comportamento(300,80,710,310,sf::Color::Black);


		dois.setTexture(efeito.TexturaBotao);
		dois.setTexto(Text("1 VS 1", efeito.fonte, 52), efeito.fonte,350,300);
		dois.estrutura.setPosition(300,300);
		SombraDois.Comportamento(300,80,310,310,sf::Color::Black);
		sf::Vector2i mousePos = sf::Mouse::getPosition(janela->window);

		if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
			if (Solo.contemPonto(mousePos)) {
				efeito.Sons(sontocando);
				std::cout << "TELA DIFERENTE1\n";
				*controlPanel =3;
			}
			if (dois.contemPonto(mousePos)) {
				efeito.Sons(sontocando);
				*controlPanel =3;
				std::cout << "TELA DIFETENTE2\n";
			}
		}
		janela->window.draw(efeito.FundoModo);
		Mododejogo.desenharTextos(janela->window);
		janela->window.draw(SombraUm);
		janela->window.draw(SombraDois);
		janela->window.draw(Solo);
		janela->window.draw(dois);
	}

};

#endif /* MODODEJOGO_HPP_ */
