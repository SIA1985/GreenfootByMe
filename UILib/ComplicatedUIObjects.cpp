#include "ComplicatedUIObjects.h"
#include "Config.h"
#include "ComplicatedWindowsWithUI.h"
#include "ExitCodes.h"

#include <future>
#include <iostream>


void TwoPositionButtonv2::OnClicked()
{
    const auto mousePosition = sf::Mouse::getPosition(*ownerWindow);

    const auto buttonPosition = leftBottomCorner;

    if(mousePosition.x >= buttonPosition.x + shapeInitSize.x || mousePosition.x <= buttonPosition.x 
        ||
        mousePosition.y >= buttonPosition.y + shapeInitSize.y  || mousePosition.y <= buttonPosition.y || Clicked)
    {
        MouseClickFunction();
        Clicked = false;
    }
    else   
        Clicked = true;
}

void TwoPositionButtonv2::MouseClickFunction()
{

}

FileButton::FileButton(sf::Vector2f __leftBottomCorner, sf::Vector2f __size,
            sf::String __name, sf::RenderWindow* __ownerWindow)
: TwoPositionButtonv2(__leftBottomCorner, __size, __name, __ownerWindow)
{
    buttonListPtr = std::make_shared<ButtonList>(ButtonList({"Open", "Save", "Quit"}, {[](){std::cout << "Open\n";}, [](){std::cout << "Save\n";}, [](){EXIT(ExitCodes::NormalProgramTermination);},},
                         sf::Vector2f(__leftBottomCorner.x, __leftBottomCorner.y + BUTTON_HEIGHT), __ownerWindow));
}

void FileButton::draw()
{
    Button::draw();

    if(Clicked)
        buttonListPtr->draw();
}

void FileButton::MouseClickFunction()
{
    if(!Clicked)
        return;

    buttonListPtr->OnClicked();
}

EditButton::EditButton(sf::Vector2f __leftBottomCorner, sf::Vector2f __size,
            sf::String __name, sf::RenderWindow* __ownerWindow)
: TwoPositionButtonv2(__leftBottomCorner, __size, __name, __ownerWindow)
{
    buttonListPtr = std::make_shared<ButtonList>(ButtonList({"Stop", "Start"}, { [](){std::cout << "Stop\n";}, [](){std::cout << "Start\n";} }, sf::Vector2f(__leftBottomCorner.x, __leftBottomCorner.y + BUTTON_HEIGHT), __ownerWindow));
}

void EditButton::draw()
{
    Button::draw();

    if(Clicked)
        buttonListPtr->draw();
}

void EditButton::MouseClickFunction()
{
    if(!Clicked)
        return;

    buttonListPtr->OnClicked();
}

void HelpButton::MouseClickFunction()
{
    if(helpWindow.get() != nullptr)
        return;

    std::thread thread(&HelpButton::CreateHelpWindow, this);
    thread.detach();

    // if(!future.get())
    //     EXIT(ExitCodes::CantCreateWindow);  
}

bool HelpButton::CreateHelpWindow()
{
    helpWindow = std::make_shared<HelpWindow>(sf::VideoMode(400, 300), 30, "Help");

    if(helpWindow.get() == nullptr)
        return false;

    (*helpWindow)();

    helpWindow.reset();  

    return true;
}