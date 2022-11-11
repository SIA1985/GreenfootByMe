#pragma once

#include <vector>
#include <memory>

#include "SFML/System.hpp"

namespace sf
{
    class RenderWindow;
}

class UIBaseObject;


class UI
{
public:
    virtual ~UI(){}

    virtual void drawElements();

    virtual void OnClickedUI();

    virtual void OnResolutionChanged(const sf::Vector2f& __sizeCoeficent);

protected:
    UI(sf::RenderWindow* __ownnerWindow);

    sf::RenderWindow* ownnerWindow = nullptr;

    std::vector<std::shared_ptr<UIBaseObject>> uiElements;

    void checkElementsForNull();
};