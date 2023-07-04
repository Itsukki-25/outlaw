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
						 "#    2          *      #               #",
						 "#               *      #               #",
						 "#                               #      #",
						 "#                                #     #",
						 "#                                 #    #",
						 "#                     *                #",
						 "#                     *          *     #",
						 "#     *               *          *     #",
						 "#     *                                #",
						 "#                               1      #",
						 "#                   ########           #",
						 "#                           #          #",
						 "#        #     #            #          #",
						 "#         #    #      *     #          #",
						 "#              #      *     #          #",
						 "#              #      *     #          #",
						 "########################################"};

	vector<string> mapa2{"########################################",
			 	 	 	 "#                  ##                  #",
						 "#                  ##                  #",
						 "#               *                      #",
						 "#               *                      #",
						 "#                  ##                  #",
						 "#                  ##                  #",
						 "#        2                      1      #",
						 "#                     *                #",
						 "#                  ## *          *     #",
						 "#     *            ## *          *     #",
						 "#     *                                #",
						 "#                                      #",
						 "#                  ##                  #",
						 "#                  ##                  #",
						 "#                                      #",
						 "#                     *                #",
						 "#                  ## *                #",
						 "#                  ## *                #",
						 "########################################"};

	vector<string> mapa3{"########################################",
			 	 	 	 "#                  ##                  #",
						 "#                  ##                  #",
						 "#               *                      #",
						 "#               *                      #",
						 "#                            #         #",
						 "#                  ##        #         #",
						 "#        2                      1      #",
						 "#                     *                #",
						 "#                  ## *          *     #",
						 "#     *            ## *          *     #",
						 "#     *                                #",
						 "#                                      #",
						 "#                  ##                  #",
						 "#                  ##                  #",
						 "#                                      #",
						 "#                     *                #",
						 "#                  ## *                #",
						 "#                  ## *                #",
						 "########################################"};

	Fase fase1;
	Fase fase2;
	Fase fase3;

	const int WIDTH = 1280;
	const int HEIGHT = 640;

	sf::RenderWindow window(sf::VideoMode(WIDTH, HEIGHT), "Outlaw");
	window.setFramerateLimit(60);

	if(!fase1.iniciarFase(window, mapa1))
		return 0;
	if(!fase2.iniciarFase(window, mapa2))
		return 0;
	if(!fase3.iniciarFase(window, mapa3))
		return 0;

	return 0;
}
