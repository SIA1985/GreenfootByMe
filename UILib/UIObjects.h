#pragma once

#include "SFML/Graphics.hpp"

#include <memory>
#include <initializer_list>
#include <vector>
#include <functional>

#include "Config.h"


class UIBaseObject
{
public:
    UIBaseObject(sf::RenderWindow* __ownerWindow); //change nullptr

    UIBaseObject(sf::Vector2f __leftBottomCorner, sf::Vector2f __size,
                sf::RenderWindow* __ownerWindow = nullptr);
    
    virtual ~UIBaseObject() {}

    virtual void draw();

    virtual void OnClicked(){}

    virtual void OnResolutionChanged(const sf::Vector2f& __sizeCoeficent);

protected:
    sf::RenderWindow* ownerWindow = nullptr;
    
    sf::RectangleShape shape; 
    sf::Vector2f leftBottomCorner;

    sf::Vector2f shapeInitSize;
    sf::Vector2f shapeInitPosition;
};


class Button : public UIBaseObject
{
public:
    Button(sf::Vector2f __leftBottomCorner, sf::Vector2f __size,
            sf::Texture* __image, 
            const std::function<void(void)> __mouseFunction, sf::RenderWindow* __ownerWindow);

    Button(sf::Vector2f __leftBottomCorner, sf::Vector2f __size,
            sf::String __name, 
            const std::function<void(void)> __mouseFunction, 
            sf::RenderWindow* __ownerWindow);

    virtual void draw() override;

    void OnClicked() override;

    void OnResolutionChanged(const sf::Vector2f& __sizeCoeficent) override;

protected:
    virtual void MouseClickFunction();

private:
    sf::Text text;
    sf::Font font;

    std::function<void(void)> mouseFunction;

    sf::Vector2f textInitPosition;
};

class TwoPositionButton : public Button
{
public:
    TwoPositionButton(sf::Vector2f __leftBottomCorner, sf::Vector2f __size,
            sf::Texture* __image, sf::RenderWindow* __ownerWindow) 
            : Button(__leftBottomCorner, __size, __image, [](){}, __ownerWindow) {}

    TwoPositionButton(sf::Vector2f __leftBottomCorner, sf::Vector2f __size,
            sf::String __name, 
            sf::RenderWindow* __ownerWindow) 
            : Button(__leftBottomCorner, __size, __name, [](){}, __ownerWindow) {}

protected:
    void MouseClickFunction() override;

protected:
    bool Clicked = false;
};

class Image : public UIBaseObject
{
public:
    Image(sf::Vector2f __leftBottomCorner, sf::Vector2f __size,
            sf::Color __color, sf::Texture* __image, sf::RenderWindow* __ownerWindow);

    Image(sf::Vector2f __leftBottomCorner, sf::Vector2f __size,
            sf::Color __color, sf::RenderWindow* __ownerWindow);

    void draw() override;

    void OnResolutionChanged(const sf::Vector2f& __sizeCoeficent) override;
};

class ButtonList : public UIBaseObject
{
public:
    ButtonList(std::initializer_list<sf::String> __buttonsNames,
     std::initializer_list< std::function<void(void)>> __mouseFunctions,
     sf::Vector2f __leftBottomCorner,
     sf::RenderWindow* __ownerWindow);

    void draw() override;

    void OnClicked() override; 
    
    void OnResolutionChanged(const sf::Vector2f& __sizeCoeficent) override;

private:
    std::vector<std::shared_ptr<Button>> buttons;
};

class Textbox : public UIBaseObject //нужен?
{
public:
    Textbox(sf::String __textString, sf::RenderWindow* __ownerWindow);

    void draw() override;

private:
    sf::Text text;
    sf::Font font;
};

class Textbar : public UIBaseObject
{
public:
    Textbar(sf::Vector2f __leftBottomCorner, sf::Vector2f __size,
            sf::RenderWindow* __ownerWindow);

    void draw() override;

    void OnClicked() override;

    void OnKeyboardClick();

private:
    //Textbox ?
    bool Clicked = false;
    sf::Text activitySign; 
    
    sf::Vector2f textLeftBottomCorner;
    sf::Vector2i coursorPosition; //long long
    sf::Font font;
    sf::String text;
    int lineCount = 1; //!!!!!!!!!!!!!!
};