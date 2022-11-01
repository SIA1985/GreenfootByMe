#include "WindowWithUI.h"
#include "UI.h"
#include "ExitCodes.h"

#include <thread>


WindowWithUI::WindowWithUI(sf::VideoMode __videoMode, sf::String __title) 
               : sf::RenderWindow(__videoMode, __title)
{
     auto icon = sf::Image();
     if(!icon.loadFromFile("res/RedfootIcon.png"))
          EXIT(ExitCodes::CantCreateWindow);

     this->setIcon(256, 256, icon.getPixelsPtr());
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

void WindowWithUI::EventHandler()
{

}