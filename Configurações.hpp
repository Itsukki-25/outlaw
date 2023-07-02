
#ifndef config_HPP_
#define config_HPP_

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "Bot.hpp"
#include "janela.hpp"
#include "efeitos.hpp"

using namespace sf;
using namespace std;

class Controle {

public:
	Janela *janela;
	int *controlPanel;
	void config(int caso){


		Botao Voltar,Salvar,Musica,Sons,base;
		Textos Config;

		//fazer a base com uma textura
		//colocar os botoes de uma forma boa
		//fazer as funções na classe efeito sobre mudar o volume das coisas
		//escrever os textos na tela


	}



};

#endif
