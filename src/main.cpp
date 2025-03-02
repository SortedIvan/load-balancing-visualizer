#include <iostream>
#include "SFML/Graphics.hpp"
#include "generic_constructs/dashed_line.hpp"
#include "generic_constructs/point.hpp"
#include "lb_elements/connector.hpp"

int main()
{
    sf::RenderWindow window(
        sf::VideoMode(1500, 900),
        "Loadbalancing visualizer");

    sf::Event e;

    Connector connector(sf::Vector2f(100, 100), sf::Vector2f(600, 600), { sf::Vector2f(200, 200), sf::Vector2f(150, 275) });

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
        connector.draw(window);
        // display
        window.display();
    }
}