#pragma once

#include "SFML/Graphics.hpp"


class UIBaseObject
{
public:
    UIBaseObject() {}
    
    virtual ~UIBaseObject() {}

    virtual void drawTo(sf::RenderWindow& __renderWindow) {};
    //virtual void OnChangeResolution(int __width, int __height) = 0;
};


class Button : public UIBaseObject
{
public:
    Button(sf::Vector2i __center, sf::Vector2f __size,
            sf::Color backgroundColor, sf::Texture* __image);

    Button(sf::Vector2i __center, sf::Vector2f __size,
            sf::Color __backgroundColor, sf::Text* __text, 
            sf::Font& __font, sf::Color __textColor);

    ~Button();

    virtual void drawTo(sf::RenderWindow& __renderWindow) override;

    void OnClicked();

private:
    sf::RectangleShape shape; 

    sf::Text* text = nullptr;
    sf::Texture* texture = nullptr;

    sf::Vector2i center;
    sf::Vector2f size;

    void initShape(sf::Vector2i& __center, sf::Vector2f& __size,
                   sf::Color& backgroundColor);
};