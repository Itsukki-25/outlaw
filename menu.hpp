/*
 * Menu.cpp
 *
 *  Created on: 8 de jun. de 2023
 *      Author: guima
 */



#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <iostream>
#include "Bot.hpp"


/*
        janela.window.clear();


        janela.window.draw(start);
        janela.window.draw(Sair);


        janela.window.display();
*/

int menu(){
	 Botao start;
		    Botao Sair;
		    Janela janela;
		    fonte.loadFromFile("C:/Users/guima/eclipse-workspace/Assets.flavor-sans.otp");


		    start.setTexto(Text("Começar", fonte, 24), fonte);
		    start.estrutura.setPosition(40, 50);

		    Sair.setTexto(Text("Sair", fonte, 24), fonte);
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
		    	        	                        // Ação ao clicar no botão

		    	        	                    }
		    	        	                    if (Sair.contemPonto(mousePos))
		    	        	                    {
		    	        	                        	        	                        // Ação ao clicar no botão

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
int main() {
	}
/*
 *   int estadoAtual = 0;
    Janela janela;


    do {
        switch (estadoAtual) {
            case 0: {
                estadoAtual = menu();
                break;
            }
            case 1: {
                // Lógica para a opção "Começar"

                break;
            }
            case 2: {
                // Lógica para a opção "Sair"
            	janela.window.close();
                break;
            }
            default: {

                break;
            }
        }
    } while (estadoAtual != 2);

    return 0;
    janela.window.display();
    */

