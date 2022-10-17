#pragma once

#include "SFML/Graphics.hpp"
#include <memory>
#include <initializer_list>
#include <vector>

#include "Config.h"


class UIBaseObject
{
public:
    UIBaseObject(sf::Vector2f __leftBottomCorner, sf::Vector2f __size,
            sf::Color __backgroundColor = SYSTEM_COLOR, sf::RenderWindow* __ownerWindow = nullptr);
    
    virtual ~UIBaseObject() {}

    virtual void draw() {};
    //virtual void OnChangeResolution(int __width, int __height) = 0;

    virtual void OnClicked(){}

protected:
    sf::RenderWindow* ownerWindow = nullptr;
    
    sf::RectangleShape shape; 
    sf::Vector2f leftBottomCorner;
    sf::Vector2f size;
};


class Button : public UIBaseObject
{
public:
    Button(sf::Vector2f __leftBottomCorner, sf::Vector2f __size,
            sf::Color __backgroundColor, sf::Texture* __image, sf::RenderWindow* __ownerWindow);

    Button(sf::Vector2f __leftBottomCorner, sf::Vector2f __size,
            sf::Color __backgroundColor, sf::Text& __text, 
            sf::Color __textColor, sf::RenderWindow* __ownerWindow);

    virtual void draw() override;

    void OnClicked() override;

protected:
    virtual void MouseClickFunction();

private:
    sf::Text text;
    sf::Font font;
};

class TwoPositionButton : public Button
{
public:
    TwoPositionButton(sf::Vector2f __leftBottomCorner, sf::Vector2f __size,
            sf::Color __backgroundColor, sf::Texture* __image, sf::RenderWindow* __ownerWindow) 
            : Button(__leftBottomCorner, __size, __backgroundColor, __image, __ownerWindow) {}

    TwoPositionButton(sf::Vector2f __leftBottomCorner, sf::Vector2f __size,
            sf::Color __backgroundColor, sf::Text& __text, 
            sf::Color __textColor, sf::RenderWindow* __ownerWindow) 
            : Button(__leftBottomCorner, __size, __backgroundColor, __text, __textColor, __ownerWindow) {}

protected:
    void MouseClickFunction() override;

protected:
    bool Pressed = false;
};

class Image : public UIBaseObject
{
public:
    Image(sf::Vector2f __leftBottomCorner, sf::Vector2f __size,
            sf::Color __color, sf::Texture* __image, sf::RenderWindow* __ownerWindow);

    Image(sf::Vector2f __leftBottomCorner, sf::Vector2f __size,
            sf::Color __color, sf::RenderWindow* __ownerWindow);

    void draw() override;
};


class Textbar : public UIBaseObject
{
public:
    Textbar();

    void draw() override;

    void OnClicked() override;

    void OnKeyboardClick();

private:
    sf::Vector2i coursorPosition;
    sf::String text;
};


class ButtonList : public UIBaseObject
{
public:
    ButtonList(std::initializer_list<sf::String> __buttonsNames, sf::Vector2f __leftBottomCorner, sf::RenderWindow* __ownerWindow);

    void draw() override;

private:
    std::vector<std::shared_ptr<Button>> buttons;
};