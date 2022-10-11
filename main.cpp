#include "SFML/Graphics.hpp"

#include "UILib/WindowWithUI.h"
#include "UILib/UI.h"

int main()
{
    MainWindow MainWindow(sf::VideoMode(800, 600), "Leha loh");
    //*MainWindow2 = new  sf::RenderWindow(sf::VideoMode(800, 600), "Leha loh");

    MainWindow.setFramerateLimit(60);

    while(MainWindow.isOpen())
    {
        sf::Event event;
        while(MainWindow.pollEvent(event))
        {
            if(event.type == sf::Event::Closed)
                MainWindow.close();

            if(event.type == sf::Event::MouseButtonPressed)
                break;
        }
        
        MainWindow.clear();

        MainWindow.drawUI();

        MainWindow.display();
    }
    
}