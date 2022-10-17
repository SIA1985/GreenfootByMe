#pragma once

#include "UI.h"

class Menubar : public UI
{
public:
    Menubar(sf::RenderWindow* __ownerWindow);

};


class MainWindowsUI : public UI
{
public:
    MainWindowsUI(sf::RenderWindow* __ownnerWindow);

    void drawElements() override;

    void OnClickedUI() override;

private:
    std::vector<std::shared_ptr<UI>> elements;
};