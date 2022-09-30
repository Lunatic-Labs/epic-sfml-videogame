#include <SFML/Graphics.hpp>
#include <iostream>

int main(int argc, char *argv[]) {
  sf::RenderWindow window(sf::VideoMode(1120, 800),
                          "Animation works! In concept");
  sf::Font font;
  font.loadFromFile("Roman SD.ttf");
  sf::Text text("SFML works!", font);
  text.setCharacterSize(40);
  text.setFillColor(sf::Color::White);
  text.setStyle(sf::Text::Bold);
  text.setPosition(0, 0);
  // sf::Texture texture;
  // texture.loadFromFile("images/download.jpg");  //Alex's dog image
  // sf::Sprite sprite;
  // sprite.setTexture(texture);
  // sprite.setPosition(100,100);

  //  sf::Texture dog2;
  // dog2.loadFromFile("images/dogWIP2.jpg");  //Justin's dog sprite
  // sf::Sprite sprit;
  // sprit.setTexture(dog2);
  // sprit.setPosition(10,200);

  // Below: Code from
  // https://gamefromscratch.com/sfml-c-tutorial-spritesheets-and-animation/
  sf::Event event;
  sf::Texture test, num;
  test.loadFromFile("images/dogTestSpritesheet.jpg");
  num.loadFromFile("images/NumbersSpritesheet.jpg");
  // Read spritesheet and iterate it on a clock
  sf::IntRect sourceSprite(0, 0, 64, 64);
  sf::IntRect numSourceSprite(0, 0, 32, 36);
  sf::Sprite dogTest(test, sourceSprite);
  sf::Sprite numbers(num, numSourceSprite);
  dogTest.setPosition(10, 200);
  numbers.setPosition(200, 200);
  sf::Clock dogClock, numClock;
  // End imported code. Below: regular SFML window
  while (window.isOpen()) {

    sf::Event event;

    while (window.pollEvent(event)) {
      if (event.type == sf::Event::Closed)
        window.close();
    }
    // Below: Clock functionality imported alongside spritesheet code
    if (dogClock.getElapsedTime().asSeconds() > 1.0f) {
      if (sourceSprite.left == 64) // left edge of rect in last sprite
        sourceSprite.left = 0;     // set back to first sprite
      else
        sourceSprite.left += 64; // move over width of 1 sprite

      dogTest.setTextureRect(sourceSprite);
      dogClock.restart();
    } // Above: Dog clock, Below: Numbers clock
    if (numClock.getElapsedTime().asSeconds() > 1.0f) {
      if (numSourceSprite.left >= 287) //displaying 9
        numSourceSprite.left = 0;     // set back to 0
      else
        numSourceSprite.left += 32; // move over width of 1 sprite

      numbers.setTextureRect(numSourceSprite);
      numClock.restart();
    }
    // End imported code. Below: Regular window rendering
    window.clear();
    window.draw(text);
    window.draw(dogTest);
    window.draw(numbers);
    // window.draw(sprite); //Alex's dog
    // window.draw(sprit);  //Justin's dog
    window.display();
  }

  return 0;
}