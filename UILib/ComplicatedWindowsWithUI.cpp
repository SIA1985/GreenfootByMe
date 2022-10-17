#include "ComplicatedWindowsWithUI.h"
#include "ComplicatedUIs.h"
#include "ExitCodes.h"


MainWindow::MainWindow(sf::VideoMode __videoMode, sf::String __title) 
               : WindowWithUI(__videoMode, __title) 
{
     ui = new MainWindowsUI(this);

     if(ui == nullptr)
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
}