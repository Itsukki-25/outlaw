/*
 * bloco.hpp
 *
 *  Created on: 4 de jul. de 2023
 *      Author: user
 */

#ifndef BLOCO_HPP_
#define BLOCO_HPP_

#include <iostream>
#include <vector>
#include <string>
#include <SFML/Graphics.hpp>

class Bloco{
public:

	sf::RectangleShape corpo;
	bool solido;
	bool visivel;
	bool interageBala;

};

#endif /* BLOCO_HPP_ */
