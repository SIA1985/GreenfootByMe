#pragma once

#include "SFML/Graphics.hpp"


class UI;

class WindowWithUI : public sf::RenderWindow
{
public:
   virtual ~WindowWithUI();

    void work(); //multithreading with own loop

    void drawUI(); 

protected:
    WindowWithUI(sf::VideoMode __videoMode, sf::String __title);

    UI* ui = nullptr;

    sf::Event event;

    virtual void EventHandler(); 
};