/*Developer: Justin T. Alexander
Project: Dog Dash SFML
This file should include all functions relevant to animation/spritesheets.*/

#include <iostream>
#include <sfml/Graphics.hpp>

/*Handles scrolling through a given sprite sheet based on Clock functionality and given sprite dimensions
Function structure imported from https://gamefromscratch.com/sfml-c-tutorial-spritesheets-and-animation/*/
void iterateSprite(sf::Clock clock, sf::Sprite sprite, sf::IntRect rect, double lastSpriteLeft, double firstSpriteLeft, double spriteWidth) {
    if (clock.getElapsedTime().asSeconds() > 1.0f) {
        if (rect.left >= lastSpriteLeft)
            rect.left = firstSpriteLeft;
        else 
            rect.left += spriteWidth;

        sprite.setTextureRect(rect);
        clock.restart();
    }
}