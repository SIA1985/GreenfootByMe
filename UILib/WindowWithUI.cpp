#include "WindowWithUI.h"
#include "UI.h"
#include "ExitCodes.h"


WindowWithUI::WindowWithUI(sf::VideoMode __videoMode, sf::String __title) 
               : sf::RenderWindow(__videoMode, __title)
{

}

WindowWithUI::~WindowWithUI()
{
     delete ui;
}

void WindowWithUI::drawUI()
{
     ui->drawElements();
}

void WindowWithUI::work()
{
     while(this->isOpen())
    {

          while(this->pollEvent(event))
          {
               EventHandler();
          }

          this->clear();

          this->drawUI();

          this->display();
    }
}

void WindowWithUI::EventHandler()
{

}