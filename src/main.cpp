#include <iostream>
#include "SFML/Graphics.hpp"
#include "generic_constructs/dashed_line.hpp"

int main()
{
    sf::RenderWindow window(
        sf::VideoMode(1500, 900),
        "Loadbalancing visualizer");

    sf::Event e;
    DashedLine dashedLine(sf::Vector2f(100, 100), sf::Vector2f(300, 300), 5.f, sf::Color::White);

    // Main loop
    while (window.isOpen())
    {

        while (window.pollEvent(e))
        {
            if (e.type == sf::Event::Closed)
            {
                window.close();
            }

            if (e.type == sf::Event::TextEntered)
            {

            }
        }

        // Run updates


        // Clear the window
        window.clear(sf::Color::Black);

        // draw
        dashedLine.draw(window);

        // display
        window.display();
    }
}