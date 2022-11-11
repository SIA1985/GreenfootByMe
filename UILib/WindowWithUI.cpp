#include "WindowWithUI.h"
#include "UI.h"
#include "ExitCodes.h"
#include "Config.h"

#include <iostream>

WindowWithUI::WindowWithUI(sf::VideoMode __videoMode, short __fps, sf::String __title) 
               : sf::RenderWindow(__videoMode, __title)
{
     auto icon = sf::Image();
     if(!icon.loadFromFile("res/RedfootIcon.png"))
          EXITWITHCODE(ExitCodes::CantCreateWindow);

     this->setIcon(256, 256, icon.getPixelsPtr());

     initWidth = __videoMode.width;
     initHeight = __videoMode.height;

     this->setFramerateLimit(__fps);

}

void WindowWithUI::drawUI()
{
     ui->drawElements();
}

void WindowWithUI::operator()()
{
     while(this->isOpen())
     {
          EventLoop();

          this->clear();

          this->drawUI();

          this->display();
     }
}

void WindowWithUI::EventLoop()
{
     while(this->pollEvent(event))
     {
          EventHandler();
     }
}

void WindowWithUI::onResize()
{
     auto windowSize = this->getSize();
     sf::Vector2u newSize(windowSize);

     if(windowSize.x < WINDOW_MIN_WIDTH)
          newSize.x = WINDOW_MIN_WIDTH;

     if(windowSize.x > WINDOW_MAX_WIDTH)
          newSize.x = WINDOW_MAX_WIDTH;

     if(windowSize.y < WINDOW_MIN_HEIGHT)
          newSize.y = WINDOW_MIN_HEIGHT;

     if(windowSize.y > WINDOW_MAX_HEIGHT)
          newSize.y = WINDOW_MAX_HEIGHT;

     if(newSize != windowSize)
          this->setSize(newSize);

     sf::Vector2f newSizeCoeficient(newSize.x / float(initWidth), newSize.y / float(initHeight)); 

     ui->OnResolutionChanged(newSizeCoeficient);

}

void WindowWithUI::EventHandler()
{
     if(event.type == sf::Event::Closed)
          this->close();

     if(event.type == sf::Event::MouseButtonPressed)
          ui->OnClickedUI();
}