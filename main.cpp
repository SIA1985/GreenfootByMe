#include "UILib/ComplicatedWindowsWithUI.h"
#include "UILib/Config.h"


int main()
{
    MainWindow MainWindowObj(sf::VideoMode(WINDOW_MIN_WIDTH, WINDOW_MIN_HEIGHT), FPS, "Redfoot");

    MainWindowObj();
}