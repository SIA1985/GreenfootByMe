#include "ComplicatedWindowsWithUI.h"
#include "ComplicatedUIs.h"
#include "ExitCodes.h"

#include <iostream>


MainWindow::MainWindow(sf::VideoMode __videoMode, short __fps, sf::String __title) 
               : WindowWithUI(__videoMode, __fps, __title) 
{
     ui = std::make_shared<MainWindowsUI>(MainWindowsUI(this));

     if(ui.get() == nullptr)
          EXITWITHCODE(ExitCodes::CantCreateUI);
}

void MainWindow::EventHandler()
{ 
     WindowWithUI::EventHandler();

     // if(event.type == sf::Event::LostFocus)
     //      std::cout << "Lost focus\n";

     // if(event.type = sf::Event::GainedFocus)
     //      std::cout << "Gained focus\n";
}


HelpWindow::HelpWindow(sf::VideoMode __videoMode, short __fps, sf::String __title) 
               : WindowWithUI(__videoMode, __fps, __title) 
{
     ui = std::make_shared<HelpWindowsUI>(HelpWindowsUI(this));

     if(ui.get() == nullptr)
          EXITWITHCODE(ExitCodes::CantCreateUI);
}

void HelpWindow::EventHandler()
{
     WindowWithUI::EventHandler();
}