
#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include <vector>
#include <chrono>

#include "fase.hpp"

using namespace std;

int main(){

	vector<string> mapa1{"########################################",
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

	vector<string> mapa2{"########################################",
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

	vector<string> mapa3{"########################################",
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

	Fase fase1;
	Fase fase2;
	Fase fase3;

	const int WIDTH = 1280;
	const int HEIGHT = 640;

	sf::RenderWindow window(sf::VideoMode(WIDTH, HEIGHT), "Outlaw");
	window.setFramerateLimit(60);

	int retorno;

	retorno = fase1.iniciarJogo(window, mapa1);
	if(!retorno)
		return 0;
	retorno = fase2.iniciarJogo(window, mapa2);
	if(!retorno)
		return 0;
	retorno = fase3.iniciarJogo(window, mapa3);
	if(!retorno)
		return 0;

	return 0;
}
