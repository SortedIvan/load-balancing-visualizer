#include "connector.hpp"

Connector::Connector(sf::Vector2f startPoint, sf::Vector2f endPoint, std::vector<sf::Vector2f> intermediateConnectionPoints) {
	this->startPoint = startPoint;
	this->endPoint = endPoint;
	this->intermediateConnectionPoints = intermediateConnectionPoints;

	// Create all of the lines that compose the connector
	initializeConnectorLines();
}

void Connector::draw(sf::RenderWindow& window) {
	for (DashedLine& line : connectorLines) {
		line.draw(window);
	}
}

void Connector::moveSpecificPoint(int pointIndex, sf::Vector2f displacement) {
	if (pointIndex < 0 || pointIndex >= connectorLines.size()) {
		return;
	}
}

void Connector::moveAllPoints(sf::Vector2f displacement) {

}

void Connector::initializeConnectorLines() {
	// We need to initialize the lines to go from A -> [intermediate1, intermediate2 .. intermediateN] -> B
	
	// go straight from A to B, single dashed line
	if (intermediateConnectionPoints.empty()) {
		connectorLines.push_back(
			DashedLine(startPoint, endPoint, 5.f, sf::Color::White));
		return;
	}

	// Initialize starting line
	connectorLines.push_back(DashedLine(startPoint, intermediateConnectionPoints[0], 5.f, sf::Color::White));
	
	// Intermediate line components
	for (int i = 0; i < intermediateConnectionPoints.size() - 1; ++i) {
		connectorLines.push_back(DashedLine(
			intermediateConnectionPoints[i], intermediateConnectionPoints[i + 1], 5.f, sf::Color::White));
	}
	
	// Final line
	connectorLines.push_back(DashedLine(intermediateConnectionPoints[intermediateConnectionPoints.size() - 1], endPoint, 5.f, sf::Color::White));
}