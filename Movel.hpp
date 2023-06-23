using namespace std;
using namespace sf;


class movel{
protected:
	float pos[1],dir[1],vel;
	bool colisao;
	RectangleShape corpo;
private:
		bool tcolisao(bool coli,RectangleShape corpo){
			this->colisao=coli;
			this->corpo=corpo;
			return coli;
		}
		float Direção(float dir[1]){
			this-> dir[1]=dir[1];

			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)){

				dir[1]=1;
			}

			if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down)){

				dir[1]=-1;
			}
			return dir[1];
		}

		float movimento(float pos[0]){
				this-> pos[0]=pos[0];

				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)){
					pos[1]=pos[1] +(dir[1]* vel);
				}

				if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down)){
					pos[1]=pos[1] +(dir[1]* vel);
				}
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)){
					pos[0]=pos[0] + (vel*1);
				}

				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)){
					pos[0]=pos[0] + (vel*-1);
							}
				return pos[1] and pos[0];
			}

};
