// hey guys this is v2. I hope this works

#include <SFML/Graphics.hpp>

int main()
{
    sf::RenderWindow window(sf::VideoMode(1920, 1080), "Dog Dash!");
    sf::CircleShape shape(100.f);
    //shape.setFillColor(sf::Color::Blue);
    shape.setFillColor(sf::Color (0xFF0000FF));

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

    return 0;
}