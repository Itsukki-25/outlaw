#ifndef TEXTOS_HPP_
#define TEXTOS_HPP_

#include <SFML/Graphics.hpp>
#include <vector>
#include "Player.hpp"

class Texto {
public:
	Player jogador;
	std::vector<sf::Text> textos;

	void adicionarTexto(const sf::String& conteudo, unsigned int tamanho, float posX, float posY) {
		sf::Color cor1(255, 153, 153, 255);
		sf::Color cor2(255, 102, 0, 255);

		sf::Uint8 red = (cor1.r + cor2.r) / 2;
		sf::Uint8 green = (cor1.g + cor2.g) / 2;
		sf::Uint8 blue = (cor1.b + cor2.b) / 2;
		sf::Uint8 alpha = (cor1.a + cor2.a) / 2;

		sf::Color corMisturada(red, green, blue, alpha);
		sf::Text borda;
		borda.setFont(fonte.fonte);
		borda.setString(conteudo);
		borda.setCharacterSize(tamanho);
		borda.setFillColor(sf::Color::Black);
		borda.setPosition(posX + 5,posY + 5);
		sf::Text texto;
		texto.setFont(fonte.fonte);
		texto.setString(conteudo);
		texto.setCharacterSize(tamanho);
		texto.setPosition(posX, posY);
		texto.setFillColor(corMisturada);


		textos.push_back(borda);
		textos.push_back(texto);

	}

	void daVida(Player jogador,int qual,float tamanho,float posx,float posy){
		if (qual==1){
			char Avida=jogador.getVida();
			adicionarTexto(Avida,tamanho,posx,posy);

		} else {
			char ABala=jogador.getVida();//getbalas
			adicionarTexto(ABala,tamanho,posx,posy);
		}

	}


	void desenharTextos(sf::RenderWindow& window) {
		for (const auto& texto : textos) {
			window.draw(texto);

		}
	}

private:
	efeitos fonte;
};

#endif /* TEXTOS_HPP_ */
