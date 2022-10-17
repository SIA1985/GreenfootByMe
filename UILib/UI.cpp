#include "UI.h"
#include "UIObjects.h"


UI::UI(sf::RenderWindow* __ownnerWindow)
{
    ownnerWindow = __ownnerWindow;
}

void UI::drawElements()
{
    for(auto it = uiElements.begin(); it < uiElements.end(); it++)
        (*it)->draw();  
}

void UI::OnClickedUI()
{
    for(auto it = uiElements.begin(); it < uiElements.end(); it++)
        (*it)->OnClicked();   
}