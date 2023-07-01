#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include <vector>

#include "map.hpp"
#include "player.hpp"
#include "Bala.hpp"


using namespace std;

vector<Bala> balas;

void desenharBala(sf::RenderWindow& window, Mapa mapa, Player& jogador){

	if(balas.size())
	for(int i = 0; i <= balas.size()-1 ; i++){

		window.draw(balas[i].getCorpo());

		if(!balas[i].getVida())
			balas.erase(balas.begin() + i);

		if(!balas[i].movimentos(jogador, mapa.getCasa(), 20, 40))
			break;
	}

};

int main(){

	vector<string> mapa1{"########################################",
			 	 	 	 "#                                      #",
						 "#                      #               #",
						 "#    2          *      #               #",
						 "#               *      #               #",
						 "#                      #        #      #",
						 "#                      #         #     #",
						 "#                      #          #    #",
						 "#                     *                #",
						 "#                     *          *     #",
						 "#     *     ######    *          *     #",
						 "#     *                                #",
						 "#                               1      #",
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

	bool jogador1Tecl1 = false, jogador1Tecl2 = false;
	bool jogador2Tecl1 = false, jogador2Tecl2 = false;

	sf::RenderWindow window(sf::VideoMode(WIDTH, HEIGHT), "Outlaw");
	window.setFramerateLimit(60);

	Mapa fase1(colunas, linhas, SQUARE_SIZE);

	Player jogador1;
	jogador1.iniciarPlayer();
	jogador1.setCodigo(1);
	Player jogador2;
	jogador2.iniciarPlayer();
	jogador2.setCodigo(2);

	fase1.definirValorCasas(mapa1, jogador1, jogador2);

	while (window.isOpen()){

		sf::Event event;
	    while (window.pollEvent(event)){

	    	if (event.type == sf::Event::Closed){
	    		std::cout << "Programa finalizado manualmente!" << std::endl;
	    		window.close();
	        }

		    if(sf::Keyboard::isKeyPressed(sf::Keyboard::RShift)){
		    	jogador1Tecl1 = true;
		    	jogador1Tecl2 = false;
		    }else{
		    	jogador1Tecl2= true;
		    }
		    if(event.type == sf::Event::KeyReleased && event.key.code == sf::Keyboard::Up){
		    	jogador1Tecl2= true;
		    }
		    if(event.type == sf::Event::KeyReleased && event.key.code == sf::Keyboard::Down){
		    	jogador1Tecl2= true;
		    }
		    if(sf::Keyboard::isKeyPressed(sf::Keyboard::LShift)){
		    	jogador2Tecl1 = true;
		    	jogador2Tecl2 = false;
		    }else{
		    	jogador2Tecl2= true;
		    }
		    if(event.type == sf::Event::KeyReleased && event.key.code == sf::Keyboard::W){
		    	jogador2Tecl2= true;
		    }
		    if(event.type == sf::Event::KeyReleased && event.key.code == sf::Keyboard::S){
		    	jogador2Tecl2= true;
		    }

	    }

	    if(jogador1Tecl1 == true && jogador1Tecl2 == true){
	    	std::cout << "Jogador 1 atirou" <<std::endl;
	    	balas.push_back(Bala(-1, jogador1.getVelY(), jogador1));
	    	jogador1Tecl1 = false;
	    	jogador1Tecl2 = false;

	    }
	    if(jogador2Tecl1 == true && jogador2Tecl2 == true){
	    	std::cout << "Jogador 2 atirou" <<std::endl;
	    	balas.push_back(Bala(1, jogador2.getVelY(), jogador2));
	    	jogador2Tecl1 = false;
	    	jogador2Tecl2 = false;

	    }

    	if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up)){
    		jogador1.setVelY(-2);
    	}else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down)){
    		jogador1.setVelY(2);
    	}
    	if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left)){
    		jogador1.setVelX(-2);
    	}else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right)){
    		jogador1.setVelX(2);
    	}
    	if(sf::Keyboard::isKeyPressed(sf::Keyboard::W)){
    		jogador2.setVelY(-2);
    	}else if(sf::Keyboard::isKeyPressed(sf::Keyboard::S)){
    		jogador2.setVelY(2);
    	}
    	if(sf::Keyboard::isKeyPressed(sf::Keyboard::A)){
    		jogador2.setVelX(-2);
    	}else if(sf::Keyboard::isKeyPressed(sf::Keyboard::D)){
    		jogador2.setVelX(2);
    	}

	    window.clear();
	    fase1.desenharMapa(window);
	    desenharBala(window, fase1, jogador1);
	    desenharBala(window, fase1, jogador2);
	    if(!sf::Keyboard::isKeyPressed(sf::Keyboard::RShift))
	    	jogador1.movePlayer(fase1.getCasa(), linhas, colunas);
	    if(!sf::Keyboard::isKeyPressed(sf::Keyboard::LShift))
	    	jogador2.movePlayer(fase1.getCasa(), linhas, colunas);
	    jogador1.desenharPlayer(window);
	    jogador2.desenharPlayer(window);
	    window.display();
	}

	return 0;
}
