#include "ComplicatedWindowsWithUI.h"
#include "ComplicatedUIs.h"
#include "ExitCodes.h"

#include <iostream>


MainWindow::MainWindow(sf::VideoMode __videoMode, sf::String __title) 
               : WindowWithUI(__videoMode, __title) 
{
     ui = std::make_shared<MainWindowsUI>(MainWindowsUI(this));

     if(ui.get() == nullptr)
          EXIT(ExitCodes::CantCreateUI);
}

void MainWindow::EventHandler()
{ 
     if(event.type == sf::Event::Closed)
     {
          this->close();
          EXIT(ExitCodes::NormalProgramTermination);
     }

     if(event.type == sf::Event::MouseButtonPressed)
     {
          ui->OnClickedUI();
     }

     // if(event.type == sf::Event::LostFocus)
     //      std::cout << "Lost focus\n";

     // if(event.type = sf::Event::GainedFocus)
     //      std::cout << "Gained focus\n";
}


HelpWindow::HelpWindow(sf::VideoMode __videoMode, sf::String __title) 
               : WindowWithUI(__videoMode, __title) 
{
     ui = std::make_shared<HelpWindowsUI>(HelpWindowsUI(this));

     if(ui.get() == nullptr)
          EXIT(ExitCodes::CantCreateUI);
}

void HelpWindow::EventHandler()
{
     if(event.type == sf::Event::Closed)
     {
          this->close();
     }

     if(event.type == sf::Event::MouseButtonPressed)
     {
          ui->OnClickedUI();
     }
}