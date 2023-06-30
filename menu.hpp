
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <iostream>
#include "Bot.hpp"
#include "ModoDeJogo.hpp"
int menu(){
	Botao start;
	Botao Sair;
	Janela janela;
	efeitos efeito;



	start.setTexto(Text("Começar", efeito.fonte, 24), efeito.fonte);
	start.estrutura.setPosition(40, 50);

	Sair.setTexto(Text("Sair", efeito.fonte, 24), efeito.fonte);
	Sair.estrutura.setPosition(start.posX, start.posY - 10);

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
						if (start.contemPonto(mousePos))
						{
							janela.window.clear();
							modo();


						}
						if (Sair.contemPonto(mousePos))
						{

							janela.window.close();
						}
					}
				}
			}
		}
	}
	janela.window.clear();
	janela.window.draw(start);
	janela.window.draw(Sair);
	janela.window.display();

	return  0;
}

