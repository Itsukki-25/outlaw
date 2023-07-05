/*
 * Jogo.hpp
 *
 *  Created on: 5 de jul. de 2023
 *      Author: user
 */

#ifndef JOGO_HPP_
#define JOGO_HPP_
#include "fase.hpp"
#include "Botao.hpp"
#include"Sombras.hpp"
#include"Texto.hpp"
#include "Efeito.hpp"
#include <sstream>

bool Ganhador(int ID_ganhador, sf::RenderWindow& window){

	int *controlPanel;
	sf::Vector2i mousePos = sf::Mouse::getPosition(window);
	efeitos efeitos;
	Botao ProximaFase;
	Texto Ganhador;
	Sombra SombraProximaFase;

	if (ID_ganhador==1){
		Ganhador.adicionarTexto("O jogador 1 ganhou!",50,400,150);
	} else if (ID_ganhador==2){
		Ganhador.adicionarTexto("O jogador 2 ganhou!",50,400,150);
	}

	ProximaFase.estrutura.setPosition(700, 510);
	SombraProximaFase.Comportamento(300, 80, 705, 520,sf::Color::Black);
	ProximaFase.setTexture(efeitos.TexturaBotao);
	ProximaFase.setTexto(Text("Proxima", efeitos.fonte, 60), efeitos.fonte, 740, 510);

	bool loop = true;
	while(loop){

		window.clear();
		window.draw(ProximaFase);
		window.draw(SombraProximaFase);
		Ganhador.desenharTextos(window);
		window.display();

		if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
			mousePos = sf::Mouse::getPosition(window);
			if (ProximaFase.contemPonto(mousePos)) {
				std::cout << "Clicou no Voltar\n";
				efeitos.Sons(true);
				loop = false;
			}
		}
	}

	return false;
}

int rodarJogo(sf::RenderWindow& window,int contador){
	Fase fase1;
	Fase fase2;
	Fase fase3;

	vector<string> mapa1
		{"########################################",
		"#                                      #",
		"#                      #               #",
		"#    2                 #         @     #",
		"#               *      #               #",
		"#                                      #",
		"#                                      #",
		"#   *        *          *              #",
		"#                                      #",
		"#           @                          #",
		"#                     *          *     #",
		"#     *                                #",
		"#                               1      #",
		"#                   ########           #",
		"#                           #          #",
		"#        #     #            #          #",
		"#         #    #            #          #",
		"#              #            #          #",
		"#              #      *     #          #",
		"########################################"};

	vector<string> mapa2
		{"########################################",
		"#                  ##                  #",
		"#    *             ##                  #",
		"#        @                 *    @      #",
		"#                  *                   #",
		"#  *          *    ##                  #",
		"#                  ##                  #",
		"#        2                 *    1      #",
		"#                                      #",
		"#                  ##                  #",
		"#      *       **  ##             *    #",
		"#                        *             #",
		"#   *                                  #",
		"#                  ##                  #",
		"#           *      ##   *      *    *  #",
		"#                                      #",
		"#   *                                  #",
		"#           *      ##        *         #",
		"#                  ##                  #",
		"########################################"};

	vector<string> mapa3
		{"########################################",
		"#                  ##                  #",
		"#             @    ##            *     #",
		"#                                      #",
		"# *             *                      #",
		"#                            #         #",
		"#                  ##        #         #",
		"#        2                      1      #",
		"#                     *                #",
		"#                  ##            *     #",
		"#                  ## *                #",
		"#     *                                #",
		"#                                      #",
		"#                  ##             *    #",
		"#                  ##                  #",
		"#                                      #",
		"#     *                                #",
		"#                  ##    @             #",
		"#                  ## *                #",
		"########################################"};

	int retorno;
	retorno = fase1.iniciarJogo(window, mapa1);
	if(!retorno|| Ganhador(retorno,window))
		return 0;
	retorno = fase2.iniciarJogo(window, mapa2);
	if(!retorno|| Ganhador(retorno,window))
		return 0;
	retorno = fase3.iniciarJogo(window, mapa3);
	if(!retorno || Ganhador(retorno,window))
		return 0;

	return 1;

};




#endif /* JOGO_HPP_ */
