#include <iostream>
#include <SFML/Graphics.hpp>

int main() {
  sf::RenderWindow window(sf::VideoMode(1920, 1080), "Dog Dash!");
  sf::CircleShape shape(100.f);

  // //Justin's code start
  // sf::Sprite dog;  
  // sf::Texture texture;
  // sf::Image image;
  // image.loadFromFile("https://replit.com/@sfml-epic-gamers/"
  //                    "SFML-Epic-Game-v2#Dog%20WIP%201%20500.png");
  // texture.loadFromImage(image, const IntRect& area = IntRect());
  // dog.setTexture(texture);
  // shape.setFillColor(sf::Color(0xFF0000FF));  
  // //Justin's code end

  
  while (window.isOpen()) {
    sf::Event event;
    while (window.pollEvent(event)) {
      if (event.type == sf::Event::Closed)
        window.close();
    }

    window.clear();
    window.draw(shape);
    //window.draw(dog);  //Drawing Justin's dog
    window.display();
  }

  return 0;
}