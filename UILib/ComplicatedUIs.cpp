#include "ComplicatedUIs.h"
#include "UIObjects.h"
#include "ExitCodes.h"
#include "Config.h"
#include "ComplicatedUIObjects.h"

#include "SFML/Graphics.hpp"


Menubar::Menubar(sf::RenderWindow* __ownerWindow) 
: UI(__ownerWindow) 
{
    auto ownerWindowSize = ownnerWindow->getSize();

    auto background = new Image(sf::Vector2f(0, 0), sf::Vector2f(ownerWindowSize.x, BUTTON_HEIGHT),
                                SYSTEM_COLOR, __ownerWindow);
    
    uiElements.emplace_back(background);

    sf::Text text;
    text.setString("File");

    FileButton* fileButton = new FileButton(sf::Vector2f(0, 0), 
                                            sf::Vector2f(BUTTON_WIDTH, BUTTON_HEIGHT), 
                                            SYSTEM_COLOR, text,
                                            sf::Color::Black, __ownerWindow);

    uiElements.emplace_back(fileButton);

    int previuosButtonCount = 1; 

    std::vector<sf::String> buttonsNames{"Edit", "Help"};

    for(size_t i = 0; i < buttonsNames.size(); i++)
    {
        sf::Text fileText;
        fileText.setString(buttonsNames[i]);

        auto newButton = new Button(sf::Vector2f(BUTTON_WIDTH * previuosButtonCount, 0),
                                sf::Vector2f(BUTTON_WIDTH, BUTTON_HEIGHT), 
                                SYSTEM_COLOR, fileText,
                                sf::Color::Black, __ownerWindow);

        previuosButtonCount++;

        uiElements.emplace_back(newButton);
    }


    for(auto it = uiElements.begin(); it < uiElements.end(); it++)
        if(it->get() == nullptr)
            EXIT(ExitCodes::CantCreateUIObject);
}


MainWindowsUI::MainWindowsUI(sf::RenderWindow* __ownnerWindow) : UI(__ownnerWindow)
{
    auto ownerWindowSize = ownnerWindow->getSize();


    auto background = new Image(sf::Vector2f(0, 0), 
                            sf::Vector2f(ownerWindowSize), sf::Color::White, ownnerWindow);

    auto menu = new Menubar(__ownnerWindow);

    auto okButton = new Button(sf::Vector2f(400, 300), sf::Vector2f(50, 25), 
                        sf::Color::Red, nullptr, ownnerWindow); 


    uiElements.emplace_back(background);
    elements.emplace_back(menu);
    uiElements.emplace_back(okButton);

    for(auto it = uiElements.begin(); it < uiElements.end(); it++)
        if(it->get() == nullptr)
            EXIT(ExitCodes::CantCreateUIObject);
    
    for(auto it = elements.begin(); it < elements.end(); it++)
        if(it->get() == nullptr)
            EXIT(ExitCodes::CantCreateUIObject);
}

void MainWindowsUI::drawElements()
{
    for(auto it = uiElements.begin(); it < uiElements.end(); it++)
        (*it)->draw();

    for(auto it = elements.begin(); it < elements.end(); it++)
        (*it)->drawElements();
}

void MainWindowsUI::OnClickedUI()
{
    for(auto it = uiElements.begin(); it < uiElements.end(); it++)
        (*it)->OnClicked();
    
    for(auto it = elements.begin(); it < elements.end(); it++)
        (*it)->OnClickedUI();
}