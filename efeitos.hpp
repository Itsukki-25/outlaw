/*
 * efeitos.hpp
 *
 *  Created on: 30 de jun. de 2023
 *      Author: guima
 */

#ifndef EFEITOS_HPP_
#define EFEITOS_HPP_
class efeitos {
public:
    sf::Font fonte;
    sf::SoundBuffer SomDoTiro;
    sf::Sound tiros;
    sf::Music musica;
    sf::SoundBuffer SomDoClique;
    sf::Sound clique;
    sf::Texture textureFundo;
    sf::Sprite fundoImage;
    sf::Texture TexturaBotao;
    sf::Texture FundoMododejogo;
    sf::Sprite FundoModo;

    	efeitos()
    {
    	FundoMododejogo.loadFromFile("assets/Modo.jpg");
    	FundoModo.setTexture(FundoMododejogo);
    	TexturaBotao.loadFromFile("assets/Tbotao.jpg");
    	textureFundo.loadFromFile("assets/cowboy.jpg");
		fundoImage.setTexture(textureFundo);
        fonte.loadFromFile("assets/fonte.TTF");
        SomDoClique.loadFromFile("assets/clique.ogg");
        clique.setBuffer(SomDoClique);
        musica.openFromFile("assets/musica.ogg");

    }

    	void cliqueBotao(){
    		clique.play();
    	}

    	void IniciarMusica(int tocar){
    		if (tocar==1){
    			musica.setLoop(true);
    			    		musica.play();
    		}
    		else{
    			musica.stop();
    		}

    	}


};

#endif /* EFEITOS_HPP_ */
