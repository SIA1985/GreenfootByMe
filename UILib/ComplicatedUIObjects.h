#pragma once

#include "UIObjects.h"
#include "SFML/Graphics.hpp"

#include <memory>

class HelpWindow;


class TwoPositionButtonv2 : public TwoPositionButton
{
public:
    TwoPositionButtonv2(sf::Vector2f __leftBottomCorner, sf::Vector2f __size,
            sf::Color __backgroundColor, sf::String __name, 
            sf::Color __textColor, sf::RenderWindow* __ownerWindow)
    : TwoPositionButton(__leftBottomCorner, __size, __backgroundColor, __name,
                        __textColor, __ownerWindow) {}

    void OnClicked() override;

protected:
    void MouseClickFunction() override;
};


class FileButton : public TwoPositionButtonv2
{
public:
    FileButton(sf::Vector2f __leftBottomCorner, sf::Vector2f __size,
            sf::Color __backgroundColor, sf::String __name, 
            sf::Color __textColor, sf::RenderWindow* __ownerWindow);

    void draw() override;

protected:
    void MouseClickFunction() override;

private:
    std::shared_ptr<ButtonList> buttonListPtr;
};

class EditButton : public TwoPositionButtonv2
{
public:
    EditButton(sf::Vector2f __leftBottomCorner, sf::Vector2f __size,
            sf::Color __backgroundColor, sf::String __name, 
            sf::Color __textColor, sf::RenderWindow* __ownerWindow);

    void draw() override;

protected:
    void MouseClickFunction() override;
    
private:
    std::shared_ptr<ButtonList> buttonListPtr;
};


class HelpButton : public Button
{
public:
    HelpButton(sf::Vector2f __leftBottomCorner, sf::Vector2f __size,
            sf::Color __backgroundColor, sf::String __name, 
            sf::Color __textColor, sf::RenderWindow* __ownerWindow)
: Button(__leftBottomCorner, __size, __backgroundColor, __name,
                        __textColor, [](){}, __ownerWindow) {}
        
protected:
    void MouseClickFunction() override; 

private:
    std::shared_ptr<HelpWindow> helpWindow; 

    bool CreateHelpWindow();
};