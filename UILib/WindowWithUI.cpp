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
     ui->drawElements(*this);
}


MainWindow::MainWindow(sf::VideoMode __videoMode, sf::String __title) 
               : WindowWithUI(__videoMode, __title) 
{
     ui = new MainWindowsUI();

     if(ui == nullptr)
          EXIT(ExitCodes::CantCreateUI);
}