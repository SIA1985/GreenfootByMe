#include "UI.h"
#include "ExitCodes.h"
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

void UI::OnResolutionChanged(const sf::Vector2f& __sizeCoeficent)
{
    for(auto it = uiElements.begin(); it < uiElements.end(); it++)
        (*it)->OnResolutionChanged(__sizeCoeficent);
}

void UI::checkElementsForNull()
{
        for(auto it = uiElements.begin(); it < uiElements.end(); it++)
            if(it->get() == nullptr)
                EXITWITHCODE(ExitCodes::CantCreateUIObject);
}