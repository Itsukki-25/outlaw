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




int menu(){
	Botao Solo;
	Botao dois;
	Janela janela;
	fonte.loadFromFile("C:/Users/guima/eclipse-workspace/Assets.flavor-sans.otp");


	Solo.setTexto(Text("1 VS IA", fonte, 24), fonte);
	Solo.estrutura.setPosition(40, 50);

	dois.setTexto(Text("1 VS 1", fonte, 24), fonte);
	dois.estrutura.setPosition(Solo.posX -20, Solo.posY);

	janela.executar();
	{
		while (janela.window.isOpen()) {
			sf::Event event;
			while (janela.window.pollEvent(event)) {

				if (event.type == sf::Event::MouseButtonPressed)
				{
					if (event.mouseButton.button == sf::Mouse::Left)
					{
						sf::Vector2f mousePos(event.mouseButton.x, event.mouseButton.y);
						if (Solo.contemPonto(mousePos))
						{
							// Ação ao clicar no botão

						}
						if (dois.contemPonto(mousePos))
						{
							// Ação ao clicar no botão

						}
					}
				}
			}
		}
	}
	janela.window.clear();
	janela.window.draw(Solo);
	janela.window.draw(dois);
	janela.window.display();

	return  0;
}



#endif /* MODODEJOGO_HPP_ */
