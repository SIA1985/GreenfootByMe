#include "ComplicatedUIs.h"
#include "UIObjects.h"
#include "ExitCodes.h"
#include "Config.h"
#include "ComplicatedUIObjects.h"

#include "SFML/Graphics.hpp"

#include <fstream>
#include <string>


Menubar::Menubar(sf::RenderWindow* __ownerWindow) 
: UI(__ownerWindow) 
{
    auto ownerWindowSize = ownnerWindow->getSize();

    auto background = new Image(sf::Vector2f(0, 0), sf::Vector2f(ownerWindowSize.x, BUTTON_HEIGHT),
                                SYSTEM_COLOR, __ownerWindow);
    
    uiElements.emplace_back(background);


    FileButton* fileButton = new FileButton(sf::Vector2f(0, 0), 
                                            sf::Vector2f(BUTTON_WIDTH, BUTTON_HEIGHT), 
                                            SYSTEM_COLOR, "File",
                                            sf::Color::Black, __ownerWindow);

    uiElements.emplace_back(fileButton);

    EditButton* editButton = new EditButton(sf::Vector2f(BUTTON_WIDTH, 0), 
                                            sf::Vector2f(BUTTON_WIDTH, BUTTON_HEIGHT), 
                                            SYSTEM_COLOR, "Edit",
                                            sf::Color::Black, __ownerWindow);

    uiElements.emplace_back(editButton);

    HelpButton* helpButton = new HelpButton(sf::Vector2f(BUTTON_WIDTH * 2, 0), 
                                            sf::Vector2f(BUTTON_WIDTH, BUTTON_HEIGHT), 
                                            SYSTEM_COLOR, "Help",
                                            sf::Color::Black, __ownerWindow);

    uiElements.emplace_back(helpButton);

    CheckElementsForNull();
}


MainWindowsUI::MainWindowsUI(sf::RenderWindow* __ownnerWindow) 
: UI(__ownnerWindow)
{
    auto ownerWindowSize = ownnerWindow->getSize();


    auto background = new Image(sf::Vector2f(0, 0), 
                            sf::Vector2f(ownerWindowSize), sf::Color::White, ownnerWindow);

    auto menu = new Menubar(__ownnerWindow);

    auto okButton = new Button(sf::Vector2f(400, 300), sf::Vector2f(50, 25), 
                        sf::Color::Red, nullptr, [](){}, ownnerWindow); 


    uiElements.emplace_back(background);
    elements.emplace_back(menu);
    uiElements.emplace_back(okButton);

    CheckElementsForNull();
    
    for(auto it = elements.begin(); it < elements.end(); it++)
        if(it->get() == nullptr)
            EXIT(ExitCodes::CantCreateUIObject);
}

void MainWindowsUI::drawElements()
{
    UI::drawElements();

    for(auto it = elements.begin(); it < elements.end(); it++)
        (*it)->drawElements();
}

void MainWindowsUI::OnClickedUI()
{
    UI::OnClickedUI();
    
    for(auto it = elements.begin(); it < elements.end(); it++)
        (*it)->OnClickedUI();
}


HelpWindowsUI::HelpWindowsUI(sf::RenderWindow* __ownnerWindow) 
: UI(__ownnerWindow)
{
    auto ownerWindowSize = ownnerWindow->getSize();


    auto background = new Image(sf::Vector2f(0, 0), 
                            sf::Vector2f(ownerWindowSize), sf::Color::White, ownnerWindow);

    uiElements.emplace_back(background);

    std::string buf, inputString;

    std::fstream file("res/help.txt");

    if(file.is_open())
    {
            while(std::getline(file, buf))
            {
                inputString.append(buf);
            }
    }

    auto text = new Textbox(inputString, sf::Color::Black,  ownnerWindow);

    uiElements.emplace_back(text);


    CheckElementsForNull();
}

void HelpWindowsUI::OnClickedUI()
{

}