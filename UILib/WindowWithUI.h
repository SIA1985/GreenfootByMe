#pragma once

#include "SFML/Graphics.hpp"

#include <memory>


class UI;

class WindowWithUI : public sf::RenderWindow
{
public:
   virtual ~WindowWithUI() {}

    void operator ()(); //multithreading with own loop

    void drawUI(); 

protected:
    WindowWithUI(sf::VideoMode __videoMode, sf::String __title);

    std::shared_ptr<UI> ui;

    sf::Event event;

    virtual void EventHandler(); 

    void EventLoop();

private:
    void mainLoop();
};