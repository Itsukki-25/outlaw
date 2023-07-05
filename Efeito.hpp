#ifndef EFEITO_HPP_
#define EFEITO_HPP_

#include <SFML/Audio.hpp>

class efeitos {
public:
	sf::Font fonte;
	sf::SoundBuffer SomDoTiro;
	sf::Sound tiros;
	sf::Music musica;
	sf::Music tiro;
	sf::SoundBuffer SomDoClique;
	sf::Sound clique;
	sf::Texture textureFundo;
	sf::Sprite fundoImage;
	sf::Texture TexturaBotao;
	sf::Texture FundoMododejogo;
	sf::Sprite FundoModo;
	sf::Texture FundoDasConfig;
	sf::Sprite FundoParaAsConfig;
	sf::SoundBuffer SomDePassos;
	sf::Sound Passos;
	int sons = 0;
	int musicas = 0;

	efeitos()
	{
		FundoDasConfig.loadFromFile("assets/Config.png");
		FundoParaAsConfig.setTexture(FundoDasConfig);
		FundoMododejogo.loadFromFile("assets/Modo.jpg");
		FundoModo.setTexture(FundoMododejogo);
		TexturaBotao.loadFromFile("assets/Tbotao.jpg");
		textureFundo.loadFromFile("assets/cowboy.jpg");
		fundoImage.setTexture(textureFundo);
		fonte.loadFromFile("assets/fonte.TTF");
		SomDoClique.loadFromFile("assets/clique.ogg");
		clique.setBuffer(SomDoClique);
		musica.openFromFile("assets/musica.ogg");
		SomDoTiro.loadFromFile("assets/Tiro.ogg");
		SomDePassos.loadFromFile("assets/Passos.ogg");
		Passos.setBuffer(SomDePassos);
		tiros.setBuffer(SomDoTiro);
		tiro.openFromFile("assets/Tiro.ogg");

	}


	bool DesligarSom(bool tocar, int volume)
	{
		if (tocar) {
			if (clique.getStatus() == sf::SoundSource::Playing) {
				clique.stop();
				return false;
			} else {
				clique.play();
				return true;
			}
		} else {
			clique.stop();
			return false;
		}
	}

	void Sons(bool tocar)
	{
	    if (tocar) {
	        clique.play();
	    }
	}


	void Musica(bool tocar, int volume)
	{
		if (tocar) {
			if (musica.getStatus() == sf::SoundSource::Playing) {
				musica.stop();
			} else {
				musica.play();
			}
		} else {
			musica.stop();
		}
	}
};

#endif /* EFEITO_HPP_ */
