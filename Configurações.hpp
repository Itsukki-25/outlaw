#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <iostream>

#include "Bot.hpp"

using namespace sf;
using namespace std;

class Controle : public Botao {
public:
	sf::RectangleShape Base,lin1,lin2;
	Botao salvar, sair, som, musica,linha1,linha2;

private:
	Janela janela;
	efeitos fonte;

	void config()
	{
		fonte.fonte.loadFromFile("assets/font.ttf");

		float x = janela.screenSize.x - 50;
		float y = janela.screenSize.y - 50;
		Base.setSize(Vector2f(x, y));

		salvar.setTexto(Text("Salvar", fonte.fonte, 24), fonte.fonte);
		salvar.estrutura.setPosition(x + 20, y + 5);

		sair.setTexto(Text("Começar", fonte.fonte, 24), fonte.fonte);
		sair.estrutura.setPosition(salvar.posX + 20, y + 5);

		som.setTexto(Text("Som", fonte.fonte, 24), fonte.fonte);
		som.estrutura.setPosition(salvar.posX, y + 70);

		musica.setTexto(Text("Musica", fonte.fonte, 24), fonte.fonte);
		musica.estrutura.setPosition(salvar.posX, som.posY - 20);

		janela.window.draw(Base);
		janela.window.draw(salvar);
		janela.window.draw(sair);
		janela.window.draw(som);
		janela.window.draw(musica);

	}

	void padraoMusica()
	{
		if (fonte.musica ==0){
			fonte.musica==75;
		}else{
			fonte.musica=0;
		}

	}
	void padraosom(){
		if (fonte.clique ==0){
			fonte.clique==75;
		}else{
			fonte.clique=0;
		}
	}


	void teste()
	{
		while (janela.window.isOpen())
		{
			bool Som,Musica;
			sf::Event event;
			while (janela.window.pollEvent(event))
			{
				if (event.type == sf::Event::MouseButtonPressed)
				{
					if (event.mouseButton.button == sf::Mouse::Left)
					{
						sf::Vector2f mousePos(event.mouseButton.x, event.mouseButton.y);


						if (som.contemPonto(mousePos))
						{
							// Ação ao clicar no botão "Som"
							padraosom();
							som=true;

						}
						if (musica.contemPonto(mousePos))
						{
							// Ação ao clicar no botão "Musica"
							padraoMusica();
							musica=true;

						}
						if (salvar.contemPonto(mousePos))
						{
							// Ação ao clicar no botão "Salvar"
							janela.window.close();

						}
						if (sair.contemPonto(mousePos))
						{
							// Ação ao clicar no botão "Começar"
							if (musica==true){
								padraoMusica();
							}
							if (som==true){
								padraosom();
							}
							janela.window.close();
						}
					}
				}
			}
		}
	}

public:
	void executar() override
	{
		config();
		teste();
	}
};

