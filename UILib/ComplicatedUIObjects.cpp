#include "ComplicatedUIObjects.h"
#include "Config.h"


FileButton::FileButton(sf::Vector2f __leftBottomCorner, sf::Vector2f __size,
            sf::Color __backgroundColor, sf::Text& __text, 
            sf::Color __textColor, sf::RenderWindow* __ownerWindow)
: TwoPositionButton(__leftBottomCorner, __size, __backgroundColor, __text, __textColor, __ownerWindow)
{
    buttonListPtr = std::make_shared<ButtonList>(ButtonList({"Open", "Save", "Quit"}, sf::Vector2f(__leftBottomCorner.x, __leftBottomCorner.y + BUTTON_HEIGHT), __ownerWindow));
}

void FileButton::draw()
{
    Button::draw();

    if(Pressed)
        buttonListPtr->draw();
}