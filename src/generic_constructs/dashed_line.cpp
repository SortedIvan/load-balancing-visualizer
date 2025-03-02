#include "dashed_line.hpp"

DashedLine::DashedLine(sf::Vector2f pointA, sf::Vector2f pointB, float linesLength, sf::Color lineColor) {
	initializeLinesArray(pointA, pointB, linesLength, lineColor);
}

// Lines will always be drawn from pointA -> pointB and not the other way around
void DashedLine::initializeLinesArray(sf::Vector2f pointA, sf::Vector2f pointB, float linesLength, sf::Color lineColor) {
	// 1) Calculate the amount of lines that we will need
	sf::Vector2f displacement = pointB - pointA;
	float displacementLen = VecMath::len(displacement);
	int numOfLines = displacementLen / linesLength;

	// 2) Calculate normalized direction vector
	sf::Vector2f dirVec = VecMath::normalize(displacement);

	// 3) Populate lines array
	// first, check whether the last line touches the point within some constant of error (2px)
	sf::Vector2f lastLinePoint = linesLength * numOfLines * dirVec;

	float difference;
	if (lastLinePoint.x > pointB.x) {
		// point overshoots lastLine by at least 2px
		difference = -(lastLinePoint.x - pointB.x);
	}
	else if (lastLinePoint.x < pointB.x) {
		// point undershoots lastLine by at least 2x
		difference = pointB.x - lastLinePoint.x;
	}
	else {
		difference = 0.f;
	}

	for (int i = 0; i < numOfLines; ++i) {
		if (i % 2 == 0) {
			sf::Vector2f subStartPoint = (dirVec * (float)i * linesLength) + pointA;
			sf::Vector2f subEndPoint = (dirVec * (float)(i + 1) * linesLength) + pointA;
			Line line(subStartPoint, subEndPoint, lineColor);
			lines.push_back(line);
		}
	}

	lines[lines.size() - 1].move(sf::Vector2f(difference, 0.f));
}

void DashedLine::draw(sf::RenderWindow& window) {
	for (int i = 0; i < lines.size(); ++i) {
		lines[i].draw(window);
	}
}