#include "UI.h"
#include "UIObjects.h"
#include "ExitCodes.h"

MainWindowsUI::MainWindowsUI()
{
    okButton = new Button(sf::Vector2i(400, 300), sf::Vector2f(150, 150),
                            sf::Color::Red, nullptr);

    if(okButton == nullptr)
        EXIT(ExitCodes::CantCreateUIObject);
}

void MainWindowsUI::drawElements(sf::RenderWindow& __renderWindow)
{
    okButton->drawTo(__renderWindow);
}
