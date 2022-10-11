#include "UIObjects.h"
#include <iostream>

void Button::initShape(sf::Vector2i& __center, sf::Vector2f& __size,
                              sf::Color& __backgroundColor)
{
    center = __center; //Need them?
    size = __size;

    shape.setPosition(center.x - size.x / 2, center.y - size.y / 2);
    shape.setSize(__size);

    shape.setFillColor(__backgroundColor);
}

Button::Button(sf::Vector2i __center, sf::Vector2f __size,
            sf::Color __backgroundColor, sf::Texture* __image)
{
    initShape(__center, __size, __backgroundColor);

    if(texture == nullptr)
        return;

    shape.setTexture(texture);
}

Button::Button(sf::Vector2i __center, sf::Vector2f __size,
            sf::Color __backgroundColor, sf::Text* __text, 
            sf::Font& __font, sf::Color __textColor)
{
    initShape(__center, __size, __backgroundColor);

    text = __text;

    text->setFont(__font);
    text->setColor(__textColor);
}

Button::~Button()
{
    delete text;
    delete texture;
}

void Button::drawTo(sf::RenderWindow& __renderWindow)
{
    __renderWindow.draw(shape);
    
    if(text == nullptr)
        return;

    __renderWindow.draw(*text);
}