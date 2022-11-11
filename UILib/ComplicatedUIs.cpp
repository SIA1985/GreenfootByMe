#include "ComplicatedUIs.h"
#include "UIObjects.h"
#include "ExitCodes.h"
#include "Config.h"
#include "ComplicatedUIObjects.h"

#include "SFML/Graphics.hpp"

#include <fstream>
#include <string>
#include <iostream>


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

    checkElementsForNull();
}


SceneAndControlPanel::SceneAndControlPanel(sf::RenderWindow* __ownnerWindow)
: UI(__ownnerWindow)
{

    auto ownerWindowSize = __ownnerWindow->getSize();


    auto sceneBackground = new Image(sf::Vector2f(0.07 * ownerWindowSize.x, ownerWindowSize.y * 0.1 + BUTTON_HEIGHT * 0.8), sf::Vector2f(0.7 * ownerWindowSize.x * 0.8, (ownerWindowSize.y - 2 * BUTTON_HEIGHT) * 0.8),
                                    SYSTEM_COLOR, ownnerWindow);

    uiElements.emplace_back(sceneBackground);

    sf::Texture* startButtonIcon = new sf::Texture;
    if(!startButtonIcon->loadFromFile("res/StartButton.png"))
        EXITWITHCODE(ExitCodes::CantLoadTexture);

    auto startButton = new Button(sf::Vector2f(ownerWindowSize.x * 0.7 / 4 - BUTTON_WIDTH / 2, ownerWindowSize.y - BUTTON_HEIGHT * 2), 
                                    sf::Vector2f(BUTTON_WIDTH, BUTTON_HEIGHT),
                                    SYSTEM_COLOR, startButtonIcon, [](){std::cout << "Start\n";}, ownnerWindow);

    uiElements.emplace_back(startButton);

    sf::Texture* pauseButtonIcon = new sf::Texture;
    if(!pauseButtonIcon->loadFromFile("res/PauseButton.png"))
        EXITWITHCODE(ExitCodes::CantLoadTexture);

    auto pauseButton = new Button(sf::Vector2f(ownerWindowSize.x * 0.7 * 2 / 4 - BUTTON_WIDTH / 2, ownerWindowSize.y - BUTTON_HEIGHT * 2), 
                                    sf::Vector2f(BUTTON_WIDTH, BUTTON_HEIGHT),
                                    SYSTEM_COLOR, pauseButtonIcon, [](){std::cout << "Pause\n";}, ownnerWindow);

    uiElements.emplace_back(pauseButton);

    sf::Texture* stopButtonIcon = new sf::Texture;
    if(!stopButtonIcon->loadFromFile("res/StopButton.png"))
        EXITWITHCODE(ExitCodes::CantLoadTexture);

    auto stopButton = new Button(sf::Vector2f(ownerWindowSize.x * 0.7 * 3 / 4 - BUTTON_WIDTH / 2, ownerWindowSize.y - BUTTON_HEIGHT * 2), 
                                    sf::Vector2f(BUTTON_WIDTH, BUTTON_HEIGHT),
                                    SYSTEM_COLOR, stopButtonIcon, [](){std::cout << "Stop\n";}, ownnerWindow);

    uiElements.emplace_back(stopButton);

    checkElementsForNull();
}

MainWindowsUI::MainWindowsUI(sf::RenderWindow* __ownnerWindow) 
: UI(__ownnerWindow)
{
    auto ownerWindowSize = ownnerWindow->getSize();


    auto sceneAndControlPanel = new SceneAndControlPanel(__ownnerWindow);

    elements.emplace_back(sceneAndControlPanel);

    auto background = new Image(sf::Vector2f(0, 0), 
                            sf::Vector2f(ownerWindowSize), sf::Color::White, ownnerWindow);

    uiElements.emplace_back(background);

    auto menu = new Menubar(__ownnerWindow);

    elements.emplace_back(menu);

    checkElementsForNull();
    
    for(auto it = elements.begin(); it < elements.end(); it++)
        if(it->get() == nullptr)
            EXITWITHCODE(ExitCodes::CantCreateUIObject);
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

void MainWindowsUI::OnResolutionChanged(const sf::Vector2f& __sizeCoeficent)
{
    UI::OnResolutionChanged(__sizeCoeficent);

    for(auto it = elements.begin(); it < elements.end(); it++)
        (*it)->OnResolutionChanged(__sizeCoeficent);
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


    checkElementsForNull();
}

void HelpWindowsUI::OnClickedUI()
{

}