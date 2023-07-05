
#ifndef configuracao_HPP_
#define configuracao_HPP_

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "Botao.hpp"
#include "janela.hpp"
#include "Efeito.hpp"
#include "Sombras.hpp"

using namespace sf;
using namespace std;

class Controle {

public:
	Janela *janela;
	int *controlPanel;
	efeitos efeito;
	void config(int caso){
		bool musicaTocando,sontocando;
		sontocando=true;
		musicaTocando = false;

		Botao Voltar,Salvar,Musica,Sons;

		Texto Config;
		Sombra SombraVoltar,SombraSalvar,SombraMusica,SombraSons;


		sf::Vector2i mousePos = sf::Mouse::getPosition(janela->window);




		Config.adicionarTexto("Configuracoes", 50, 400, 150);
		Voltar.estrutura.setPosition(750, 510);
		SombraVoltar.Comportamento(300, 80, 760, 520,sf::Color::Black);
		Voltar.setTexture(efeito.TexturaBotao);
		Voltar.setTexto(Text("Voltar", efeito.fonte, 60), efeito.fonte, 790, 510);


		Salvar.setTexture(efeito.TexturaBotao);
		Salvar.setTexto(Text("Salvar", efeito.fonte, 60), efeito.fonte, 310, 510);
		Salvar.estrutura.setPosition(300, 510);
		SombraSalvar.Comportamento(300, 80, 310, 520,sf::Color::Black);


		Musica.estrutura.setPosition(300, 380);
		SombraMusica.Comportamento(300, 80, 310, 390,sf::Color::Black);
		Musica.setTexture(efeito.TexturaBotao);
		Musica.setTexto(Text("Musica", efeito.fonte, 60), efeito.fonte, 300, 380);


		Sons.estrutura.setPosition(300, 280);
		SombraSons.Comportamento(300, 80, 310, 290,sf::Color::Black);
		Sons.setTexture(efeito.TexturaBotao);
		Sons.setTexto(Text("Sons", efeito.fonte, 60), efeito.fonte, 300, 280);




		if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
			if (Voltar.contemPonto(mousePos)) {
				std::cout << "Clicou no Voltar\n";
				efeito.Sons(sontocando);
				*controlPanel = 0;
			}
			if (Salvar.contemPonto(mousePos)) {
				std::cout << "Clicou no Salvar\n";
				efeito.Sons(sontocando);

			}

			if (Sons.contemPonto(mousePos)) {
			    std::cout << "Clicou no Salvar\n";
			    sontocando = !sontocando;
			    efeito.DesligarSom(sontocando, 100);
			    efeito.Sons(sontocando);
			}

			if (Musica.contemPonto(mousePos)) {
				std::cout << "Clicou no Salvar\n";
				efeito.Sons(sontocando);
				  musicaTocando = !musicaTocando;
				  efeito.Musica(musicaTocando,100);

			}
		}


		// Atualizar a posição do mouse
		mousePos = sf::Mouse::getPosition(janela->window);

		// Atualizar a animação do botão "start" com base na posição do mouse

		janela->window.draw(efeito.FundoParaAsConfig);
		Config.desenharTextos(janela->window);
		janela->window.draw(SombraVoltar);
		janela->window.draw(SombraSalvar);
		janela->window.draw(SombraSons);
		janela->window.draw(SombraMusica);
		janela->window.draw(Salvar);
		janela->window.draw(Sons);
		janela->window.draw(Musica);
		janela->window.draw(Voltar);
	}



};

#endif
