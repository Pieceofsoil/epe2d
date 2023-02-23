#include <SFML/Graphics.hpp>
#include <EPE2D/Physics.h>

#include <iostream>

const int WIN_WIDTH = 800;
const int WIN_HEIGHT = 600;

int main()
{
    sf::RenderWindow window(sf::VideoMode(WIN_WIDTH, WIN_HEIGHT), "demo - EasyPhysicsEngine2D");
    
    epe::World world = epe::World();

    //Setting up the static body (floor)
    epe::StaticBody floor(epe::Vec2(WIN_WIDTH / 2 - 128, WIN_HEIGHT / 3 * 2), world);
    epe::BoxCollider floorCollider(epe::Vec2(256, 32));
    floor.attachCollider(floorCollider);

    //Graphics for the floor
    sf::RectangleShape floorShape(sf::Vector2f(floorCollider.getSize().x, floorCollider.getSize().y));
    floorShape.setPosition(sf::Vector2f(floor.getPosition().x, floor.getPosition().y));
    floorShape.setFillColor(sf::Color::Color(128, 128, 128));

    //Setting up the dynamic body (box)
    epe::DynamicBody box(epe::Vec2(WIN_WIDTH / 2 - 8, WIN_HEIGHT / 2), world);
    epe::BoxCollider boxCollider(epe::Vec2(16, 16));
    box.attachCollider(boxCollider);

    //Graphics for the box
    sf::RectangleShape boxShape(sf::Vector2f(boxCollider.getSize().x, boxCollider.getSize().y));
    boxShape.setFillColor(sf::Color::Green);

    box.addImpulse(epe::Vec2(0.5, -2) * 5);

    int iteration = 0;
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        { 
            if (event.type == sf::Event::Closed)
                window.close();
        }

        //Print log information
        //std::cout << box.velocity.x << " " << box.velocity.y << '\n';

        //Calculate physics

        box.update();

        //Calculate graphics

        boxShape.setPosition(sf::Vector2f(box.getPosition().x, box.getPosition().y));

        //Draw graphics

        window.clear();

        window.draw(floorShape);
        window.draw(boxShape);

        window.display();
    }

    return 0;
}