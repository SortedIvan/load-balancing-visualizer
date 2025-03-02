#pragma once
#include "SFML/Graphics.hpp"
#include <string>

class Packet {
private:
	std::string data;
public:
	Packet();
	void draw(sf::RenderWindow& window);
	void move(sf::Vector2f displacement);
};