#include "UILib/ComplicatedWindowsWithUI.h"
#include <thread>


int main()
{
    MainWindow MainWindowObj(sf::VideoMode(800, 600), "Leha loh");
    //*MainWindow2 = new  sf::RenderWindow(sf::VideoMode(800, 600), "Leha loh");

    MainWindowObj.setFramerateLimit(60);

    MainWindowObj.work();

    
}