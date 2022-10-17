#include "UIObjects.h"
#include "ExitCodes.h"
#include "Config.h"

 UIBaseObject::UIBaseObject(sf::Vector2f __leftBottomCorner, sf::Vector2f __size,
            sf::Color __backgroundColor, sf::RenderWindow* __ownerWindow)
 {
    ownerWindow = __ownerWindow;

    leftBottomCorner = __leftBottomCorner; 
    size = __size;

    shape.setPosition(leftBottomCorner.x, leftBottomCorner.y);
    shape.setSize(__size);

    shape.setFillColor(__backgroundColor);
 }


Button::Button(sf::Vector2f __leftBottomCorner, sf::Vector2f __size,
            sf::Color __backgroundColor, sf::Texture* __image, sf::RenderWindow* __ownerWindow)
: UIBaseObject(__leftBottomCorner, __size, __backgroundColor, __ownerWindow)
{
    if(__image == nullptr)
        return;

    shape.setTexture(__image);
}

Button::Button(sf::Vector2f __leftBottomCorner, sf::Vector2f __size,
            sf::Color __backgroundColor, sf::Text& __text, 
            sf::Color __textColor, sf::RenderWindow* __ownerWindow)
: UIBaseObject(__leftBottomCorner, __size, __backgroundColor, __ownerWindow)
{
    text = __text;
    
    text.setColor(__textColor);

    if(!font.loadFromFile("TimesNewRomanRegular.ttf"))
        EXIT(ExitCodes::CantLoadFont);
    
    text.setFont(font);
    text.setCharacterSize(18);
    text.setPosition(sf::Vector2f(leftBottomCorner.x  + size.x / 2 - 18, 
                                    __leftBottomCorner.y + size.y / 2 - 8));

}


void Button::draw()
{
    ownerWindow->draw(shape);

    ownerWindow->draw(text);
}

void Button::OnClicked()
{
    auto mousePosition = sf::Mouse::getPosition(*ownerWindow);

    auto buttonPosition = leftBottomCorner;

    if(mousePosition.x >= buttonPosition.x + size.x || mousePosition.x <= buttonPosition.x 
        ||
        mousePosition.y >= buttonPosition.y + size.y  || mousePosition.y <= buttonPosition.y)

        return;

    MouseClickFunction();
}

void Button::MouseClickFunction()
{

}

void TwoPositionButton::MouseClickFunction()
{
    Pressed = !Pressed;
}

Image::Image(sf::Vector2f __leftBottomCorner, sf::Vector2f __size,
            sf::Color __color, sf::Texture* __image, sf::RenderWindow* __ownerWindow)
: UIBaseObject(__leftBottomCorner, __size, __color, __ownerWindow)
{
    if(__image == nullptr)
        return;

    shape.setTexture(__image);
}

Image::Image(sf::Vector2f __leftBottomCorner, sf::Vector2f __size,
            sf::Color __color, sf::RenderWindow* __ownerWindow)
: UIBaseObject(__leftBottomCorner, __size, __color, __ownerWindow)
{
}

void Image::draw()
{
    ownerWindow->draw(shape);
}


ButtonList::ButtonList(std::initializer_list<sf::String> __buttonsNames, sf::Vector2f __leftBottomCorner, sf::RenderWindow* __ownerWindow) 
: UIBaseObject(__leftBottomCorner, sf::Vector2f(0, 0), SYSTEM_COLOR, __ownerWindow)
{
    shape.setSize(sf::Vector2f(BUTTON_WIDTH, BUTTON_HEIGHT * __buttonsNames.size()));
    shape.setPosition(__leftBottomCorner);

    for(size_t i = 0; i < __buttonsNames.size(); i++)
    {
        sf::Text text;
        text.setString(*(__buttonsNames.begin() + i));

        auto newButton = new Button(sf::Vector2f(__leftBottomCorner.x, BUTTON_HEIGHT * i + __leftBottomCorner.y), //??
                                sf::Vector2f(BUTTON_WIDTH, BUTTON_HEIGHT), 
                                SYSTEM_COLOR, text,
                                sf::Color::Black, __ownerWindow);

        buttons.emplace_back(newButton);
    }

    for(auto it = buttons.begin(); it < buttons.end(); it++)
        if((*it).get() == nullptr)
            EXIT(ExitCodes::CantCreateUIObject);
}

void ButtonList::draw()
{
    ownerWindow->draw(shape);

    for(auto it = buttons.begin(); it < buttons.end(); it++)
        (*it)->draw();
}