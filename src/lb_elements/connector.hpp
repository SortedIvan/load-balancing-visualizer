#pragma once
#include "SFML/Graphics.hpp"
#include "../generic_constructs/dashed_line.hpp"
#include "packet.hpp"

#include <vector>

/* 
	A connector is a multi - line segment that can "transmit" packets
	For now, connectors only have dashed lines. This can later be switched with inheritance
*/
class Connector {
private:
	std::vector<DashedLine> connectorLines;
	sf::Vector2f startPoint;
	sf::Vector2f endPoint;
	std::vector<sf::Vector2f> intermediateConnectionPoints;
	
	// Packet logic
	
	void initializeConnectorLines();
public:
	Connector(sf::Vector2f startPoint, sf::Vector2f endPoint, std::vector<sf::Vector2f> intermediateConnectionPoints);
	void draw(sf::RenderWindow& window);
	void moveSpecificPoint(int pointIndex, sf::Vector2f displacement);
	void moveAllPoints(sf::Vector2f displacement);
};
