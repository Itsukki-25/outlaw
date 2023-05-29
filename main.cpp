// Description : Hello World in C++, Ansi-style
//============================================================================


#include <iostream>
#include <vector>
#include <string>
#include <SFML/Graphics.hpp>
#include "map.hpp"
#include "player.hpp"

using namespace std;

int main() {
	//cout << "Olá Mundo!" << endl;

	vector<string> mapa1{"########################################",
			 	 	 	 "#      #                               #",
						 "#      #               #               #",
						 "#      #        *      #               #",
						 "#      #        *      #               #",
						 "#      #               #        #      #",
						 "#      #  #            #         #     #",
						 "#       ##             #          #    #",
						 "#                     *                #",
						 "#                     *           *    #",
						 "#     *               *           *    #",
						 "#     *                                #",
						 "#                                      #",
						 "#                   ########           #",
						 "#                           #          #",
						 "#        #     #            #     #    #",
						 "#         #    #      *     #     #    #",
						 "#              #      *     #     #    #",
						 "#              #      *     #     #    #",
						 "########################################"};



	const int WIDTH = 1280;
	const int HEIGHT = 640;

	const int linhas = 20;
	const int colunas = 40;
	int SQUARE_SIZE = 32;

	sf::RenderWindow window(sf::VideoMode(WIDTH, HEIGHT), "Outlaw");
	window.setFramerateLimit(60);

	Mapa fase1(colunas, linhas, SQUARE_SIZE);

	fase1.definirValorCasas(mapa1);

	Player jogador1;
	jogador1.iniciarPlayer();
	Player jogador2;
	jogador2.setPosi(400, 200);
	jogador2.iniciarPlayer();

	while (window.isOpen()){

		sf::Event event;
	    while (window.pollEvent(event)){

	    	if (event.type == sf::Event::Closed){
	    		std::cout << "Programa finalizado manualmente!" << std::endl;
	    		window.close();
	        }
	    }

	    if(sf::Keyboard::isKeyPressed(sf::Keyboard::RShift)){
	    	jogador1.setAltura(-62,fase1.getCasa(), linhas, colunas);
	    }else{
	    	jogador1.setAltura(-120,fase1.getCasa(), linhas, colunas);
	    }
	    if(sf::Keyboard::isKeyPressed(sf::Keyboard::LShift)){
	    	jogador2.setAltura(-60,fase1.getCasa(), linhas, colunas);
	    }else{
	    	jogador2.setAltura(-120,fase1.getCasa(), linhas, colunas);
	    }

    	if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up)){
    		jogador1.setVelX(-2);
    	}else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down)){
    		jogador1.setVelX(2);
    	}
    	if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left)){
    		jogador1.setVelY(-2);
    	}else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right)){
    		jogador1.setVelY(2);
    	}
    	if(sf::Keyboard::isKeyPressed(sf::Keyboard::W)){
    		jogador2.setVelX(-2);
    	}else if(sf::Keyboard::isKeyPressed(sf::Keyboard::S)){
    		jogador2.setVelX(2);
    	}
    	if(sf::Keyboard::isKeyPressed(sf::Keyboard::A)){
    		jogador2.setVelY(-2);
    	}else if(sf::Keyboard::isKeyPressed(sf::Keyboard::D)){
    		jogador2.setVelY(2);
    	}

	    window.clear();
	    fase1.desenharMapa(window);
	    jogador1.movePlayer(fase1.getCasa(), linhas, colunas);
	    jogador2.movePlayer(fase1.getCasa(), linhas, colunas);
	    jogador1.desenharPlayer(window);
	    jogador2.desenharPlayer(window);
	    window.display();
	}

	return 0;
}
