/*
 * config.cpp
 *
 *  Created on: 17 de jun. de 2023
 *      Author: guima
 */

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <iostream>
#include "Bot.hpp"
using namespace sf;
using namespace std;

class controle : Botao{
public:
	sf::RectangleShape Base;
	Botao salvar,sair,som,musica;
private:
	Janela janela;
	void config(){

		float x =janela.window.getSize() -50;
		float y = janela.window.getSize()- 50;
		Base.setScale(x,y);
		salvar.setTexto(Text("salvar", fonte, 24), fonte);
		salvar.estrutura.setPosition(x + 20, y + 5);

		sair.setTexto(Text("Começar", fonte, 24), fonte);
		sair.estrutura.setPosition( salvar.posX + 20, y + 5);

		som.setTexto(Text("Som", fonte, 24), fonte);
		som.estrutura.setPosition(salvar.posX, y + 70);

		musica.setTexto(Text("Musica", fonte, 24), fonte);
		musica.estrutura.setPosition(salvar.posX, som.posY -20);

				janela.window.draw(Base);
		janela.window.draw(salvar);
		janela.window.draw(sair);
		janela.window.draw(som);
		janela.window.draw(musica);
	}

	void padrao(){
		//musica on -> 100%
		//som on -> 100%

	}
	void teste(){
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
									if (som.contemPonto(mousePos))
									{
										// Ação ao clicar no botão

									}
									if (musica.contemPonto(mousePos))
									{
										// Ação ao clicar no botão

									}
									if (salvar.contemPonto(mousePos))
									{
										// Ação ao clicar no botão

									}
									if (sair.contemPonto(mousePos))
									{
										// Ação ao clicar no botão

									}

								}
							}
						}
					}
				}

	}



};
