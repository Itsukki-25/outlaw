#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include <chrono>
#include <random>
#include <thread>
#include "Bot.hpp"
#include "Movel.hpp"
#include "Bala.hpp"
#include "Player.hpp"

using namespace sf;
using namespace std;

class Bot : public Player {
public:
    sf::RectangleShape corpo;
    sf::ConvexShape olho;

private:
    void movimento() {
        int intervaloTempo = 1;

        bool vivo = true;
        bool andar = true;
        float X = corpo.getPosition().x;
        float Y = corpo.getPosition().y;
        olho.setPoint(0, sf::Vector2f(X, Y));
        olho.setPoint(1, sf::Vector2f(X + 100, Y - 50));
        olho.setPoint(2, sf::Vector2f(X + 100, Y));
        olho.setPoint(2, sf::Vector2f(X + 100, Y - 50));

        while (vivo) {
            auto tempoInicio = std::chrono::steady_clock::now();

            while (andar) {
                auto tempoAtual = std::chrono::steady_clock::now();
                auto duracao = std::chrono::duration_cast<std::chrono::seconds>(tempoAtual - tempoInicio).count();

                std::random_device rd;
                std::mt19937 gen(rd());
                std::uniform_int_distribution<> dis(-1, 1);
                int posX = dis(gen);
                int posY = dis(gen);

                int velX = posX * 10;
                int velY = posY * 10;
                corpo.move(velX, velY);

                if (duracao >= intervaloTempo) {
                    break;
                }

                olho.move(posX, posY);
                if (olho.getGlobalBounds().intersects(Player::getCorpo().getGlobalBounds())) {
                    // Ação ao colidir com o jogador
                }
            }

            std::this_thread::sleep_for(std::chrono::milliseconds(100));
        }
    }
};
