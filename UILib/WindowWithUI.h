#pragma once

#include "SFML/Graphics.hpp"

#include <memory>


class UI;

class WindowWithUI : public sf::RenderWindow
{
public:
   virtual ~WindowWithUI() {}

    void operator ()(); 

    void drawUI(); 

protected:
    WindowWithUI(sf::VideoMode __videoMode, short __fps, sf::String __title);

    std::shared_ptr<UI> ui;

    sf::Event event;

    int initWidth, initHeight;

    virtual void EventHandler(); 

    void EventLoop();

    void onResize() override;

private:
    void mainLoop();
};