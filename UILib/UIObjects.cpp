#include "UIObjects.h"
#include "ExitCodes.h"
#include "Config.h"

#include <iostream>

 UIBaseObject::UIBaseObject(sf::RenderWindow* __ownerWindow)
 {
    if(__ownerWindow == nullptr)
        EXITWITHCODE(ExitCodes::NoObjectOwner);

    ownerWindow = __ownerWindow;
 }

 UIBaseObject::UIBaseObject(sf::Vector2f __leftBottomCorner, sf::Vector2f __size,
            sf::Color __backgroundColor, sf::RenderWindow* __ownerWindow)
 {
    if(__ownerWindow == nullptr)
        EXITWITHCODE(ExitCodes::NoObjectOwner);

    ownerWindow = __ownerWindow;

    leftBottomCorner = __leftBottomCorner; 
    size = __size;

    shape.setPosition(leftBottomCorner.x, leftBottomCorner.y);
    shape.setSize(__size);

    shape.setFillColor(__backgroundColor);
 }

void UIBaseObject::OnResolutionChanged(const sf::Vector2f& __sizeCoeficent)
{
    sf::Vector2f newSize(size.x * __sizeCoeficent.x, 
                         size.y * __sizeCoeficent.y);

    shape.setSize(newSize);
}

void UIBaseObject::draw()
{
    ownerWindow->draw(shape);
}

Button::Button(sf::Vector2f __leftBottomCorner, sf::Vector2f __size,
            sf::Color __backgroundColor, sf::Texture* __image, const std::function<void(void)> __mouseFunction, sf::RenderWindow* __ownerWindow)
: UIBaseObject(__leftBottomCorner, __size, __backgroundColor, __ownerWindow)
{
    mouseFunction = __mouseFunction;

    if(__image == nullptr)
        return;

    shape.setTexture(__image);
}

Button::Button(sf::Vector2f __leftBottomCorner, sf::Vector2f __size,
            sf::Color __backgroundColor, sf::String __name, 
            sf::Color __textColor, const std::function<void(void)> __mouseFunction, sf::RenderWindow* __ownerWindow)
: UIBaseObject(__leftBottomCorner, __size, __backgroundColor, __ownerWindow)
{
    if(!font.loadFromFile("res/TimesNewRomanRegular.ttf"))
        EXITWITHCODE(ExitCodes::CantLoadFont);

    text.setString(__name);
    
    text.setColor(__textColor);
    
    text.setFont(font);
    text.setCharacterSize(18);
    text.setPosition(sf::Vector2f(leftBottomCorner.x  + size.x / 2 - 18, 
                                    __leftBottomCorner.y + size.y / 2 - 8));
                        
    mouseFunction = __mouseFunction;

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

void Button::OnResolutionChanged(const sf::Vector2f& __sizeCoeficent)
{
    UIBaseObject::OnResolutionChanged(__sizeCoeficent);

    text.setScale(__sizeCoeficent);
}

void Button::MouseClickFunction()
{
    mouseFunction();
}

void TwoPositionButton::MouseClickFunction()
{
    Clicked = !Clicked;
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

void Image::OnResolutionChanged(const sf::Vector2f& __sizeCoeficent)
{
    UIBaseObject::OnResolutionChanged(__sizeCoeficent);
    shape.setScale(__sizeCoeficent);
    //std::cout << shape.getSize().x << '\n'; ///????????????????
}

ButtonList::ButtonList(std::initializer_list<sf::String> __buttonsNames,  std::initializer_list< std::function<void(void)>> __mouseFunctions,
                     sf::Vector2f __leftBottomCorner, sf::RenderWindow* __ownerWindow) 
: UIBaseObject(__leftBottomCorner, sf::Vector2f(0, 0), SYSTEM_COLOR, __ownerWindow)
{
    if(__buttonsNames.size() != __mouseFunctions.size())
        EXITWITHCODE(ExitCodes::CantCreateUIObject);

    shape.setSize(sf::Vector2f(BUTTON_WIDTH, BUTTON_HEIGHT * __buttonsNames.size()));
    shape.setPosition(__leftBottomCorner);

    for(size_t i = 0; i < __buttonsNames.size(); i++)
    {
        auto name = *(__buttonsNames.begin() + i);
        auto function = *(__mouseFunctions.begin() + i);

        auto newButton = new Button(sf::Vector2f(__leftBottomCorner.x, BUTTON_HEIGHT * i + __leftBottomCorner.y), //??
                                sf::Vector2f(BUTTON_WIDTH, BUTTON_HEIGHT), 
                                SYSTEM_COLOR, name,
                                sf::Color::Black, function, __ownerWindow);

        buttons.emplace_back(newButton);
    }

    for(auto it = buttons.begin(); it < buttons.end(); it++)
        if((*it).get() == nullptr)
            EXITWITHCODE(ExitCodes::CantCreateUIObject);
}

void ButtonList::draw()
{
    ownerWindow->draw(shape);

    for(auto it = buttons.begin(); it < buttons.end(); it++)
        (*it)->draw();
}

void ButtonList::OnClicked()
{
    auto mousePosition = sf::Mouse::getPosition(*ownerWindow);

    auto buttonPosition = leftBottomCorner;

    auto listSize = leftBottomCorner + sf::Vector2f(BUTTON_WIDTH * buttons.size(), 
                                                    BUTTON_HEIGHT * buttons.size());

    if(mousePosition.x >= buttonPosition.x + listSize.x || mousePosition.x <= buttonPosition.x 
        ||
        mousePosition.y >= buttonPosition.y + listSize.y  || mousePosition.y <= buttonPosition.y)

        return;

    for(auto it = buttons.begin(); it < buttons.end(); it++)
        (*it)->OnClicked();
}

void ButtonList::OnResolutionChanged(const sf::Vector2f& __sizeCoeficent)
{
    UIBaseObject::OnResolutionChanged(__sizeCoeficent);

    for(auto it = buttons.begin(); it < buttons.end(); it++)
        (*it)->OnResolutionChanged(__sizeCoeficent);
}

Textbox::Textbox(sf::String __textString, sf::Color __textColor ,sf::RenderWindow* __ownerWindow)
: UIBaseObject(__ownerWindow) 
{
    if(!font.loadFromFile("res/TimesNewRomanRegular.ttf"))
        EXITWITHCODE(ExitCodes::CantLoadFont);

    text.setString(__textString);

    text.setFont(font);

    text.setColor(__textColor);
}

void Textbox::draw()
{
    ownerWindow->draw(text);
}