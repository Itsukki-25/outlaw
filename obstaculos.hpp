
/* funções contrutoras inicializam valores em uma classe <- descobri agr, 28/06, 17:34
 */

#include <SFML/Graphics.hpp>
#include <iostream>

class Obstaculo {
protected:
	float tamanho = 32;
	int posx;
	int posy;
	int velx = -5;
	int vely = 5;
	sf::Color cor = sf::Color::Red;
	sf::RectangleShape shape;

public:
	Obstaculo(sf::RenderWindow& window) {
		posx = window.getSize().x / 2;
		posy = window.getSize().y / 2;
		shape.setSize(sf::Vector2f(tamanho, tamanho));
		shape.setFillColor(cor);
		shape.setOrigin(tamanho / 2, tamanho / 2);
		shape.setPosition(posx, posy);

	}
	void TestaLimite(sf::RenderWindow& window) {
		vely = posy < window.getSize().y ? vely : -vely;
		velx = posx < window.getSize().x ? velx : -velx;
		// inverte se necessário
		vely = posy > 0 ? vely : -vely;
		velx = posx > 0 ? velx : -velx;
	}
	void Movimenta() {
		posx = posx + velx * 1;
		posy = posy + vely * 1;
		shape.setPosition(posx, posy);
		sf::sleep(sf::seconds(0.05));
	}
	void Desenha(sf::RenderWindow& window) {
		window.clear();
		window.draw(shape);
		window.display();
	}
};

class BolaFeno: public Obstaculo {
private:
	sf::Texture texturaBolaDeFeno;
	sf::Sprite spriteBolaDeFeno;

public:
	using Obstaculo::Obstaculo;

	BolaFeno(sf::RenderWindow& window) :
			Obstaculo(window) {
		// Carregar a textura da bola de feno
		texturaBolaDeFeno.loadFromFile("texturaBolaDeFeno.png");

		// Definir a textura para o sprite da bola de feno
		spriteBolaDeFeno.setTexture(texturaBolaDeFeno);
		spriteBolaDeFeno.setTextureRect(sf::IntRect (0, 0, 32, 32));
		spriteBolaDeFeno.setScale(sf::Vector2f (2.0f, 2.0f));
	}

	void Movimenta() {
		posy = posy + vely * 1;
		spriteBolaDeFeno.setPosition(posx, posy);
		sf::sleep(sf::seconds(0.05));
	}

	void Desenha(sf::RenderWindow& window) {
		window.clear();
		window.draw(spriteBolaDeFeno);
		window.display();
	}
};

class Trem: public Obstaculo {
public:
	using Obstaculo::Obstaculo;
	void Movimenta() {
		//	posx = posx + velx * 1;
		posy = posy + vely * 1;
		shape.setPosition(posx, posy);
		sf::sleep(sf::seconds(0.03));
	}
};

/*
no main: 
antes do loop : BolaFeno bolinha(window); (para a bola de feno )
dentro do loop do jogo: 
        bolinha.TestaLimite(window);
		bolinha.Movimenta();
		bolinha.Desenha(window);
*/
