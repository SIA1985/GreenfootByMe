#pragma once

#include <vector>
#include <memory>

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

protected:
    UI(sf::RenderWindow* __ownnerWindow);

    sf::RenderWindow* ownnerWindow = nullptr;

    std::vector<std::shared_ptr<UIBaseObject>> uiElements;
};