#include "UILib/ComplicatedWindowsWithUI.h"
#include <thread>


int main()
{
    MainWindow MainWindowObj(sf::VideoMode(800, 600), "Redfoot");

    MainWindowObj.setFramerateLimit(60);

    MainWindowObj();
}