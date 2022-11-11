#pragma once

#include "WindowWithUI.h"


class MainWindow : public WindowWithUI
{
public:
    MainWindow(sf::VideoMode __videoMode, short __fps, sf::String __title);

protected:
    void EventHandler() override;
};


class HelpWindow : public WindowWithUI
{
public:
    HelpWindow(sf::VideoMode __videoMode, short __fps, sf::String __title);

protected:
    void EventHandler() override;
};