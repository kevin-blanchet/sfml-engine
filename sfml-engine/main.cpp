#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <iostream>
#include "GameManager.h"
#include "SceneManager.h"
#include "DisplayManager.h"
#include "LogManager.h"
#include "Vector2.h"
#include "TestObject.h"

int main()
{
    /*bool test = DM.initialize();
    if (!test) return -1;
    DM.drawString(ae::Vector2(0.f, 0.f), "Hello World !", ae::Justification::Left, sf::Color::Black);
    DM.display();
    sf::sleep(sf::seconds(2));
    DM.terminate();*/
    GM.initialize();

    TestObject* test = new TestObject();
    SM.insertGameObject(test);

    GM.run();
    /*
    sf::RenderWindow window(sf::VideoMode(200, 200), "SFML works!");
    //window.setFramerateLimit(60);
    sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Green);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        window.draw(shape);
        window.display();
    }

    */
    return 0;
}