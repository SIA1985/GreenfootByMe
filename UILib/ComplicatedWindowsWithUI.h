#pragma once

#include "WindowWithUI.h"


class MainWindow : public WindowWithUI
{
public:
    MainWindow(sf::VideoMode __videoMode, sf::String __title);

protected:
    void EventHandler() override;
};