#pragma once

namespace sf
{
    class RenderWindow;
}

class UI
{
public:
    UI(){}

    virtual ~UI(){};

    virtual void drawElements(sf::RenderWindow& __renderWindow) {};
};


class Button;

class MainWindowsUI : public UI
{
public:
    MainWindowsUI();

    void drawElements(sf::RenderWindow& __renderWindow) override;

private:
    Button* okButton = nullptr;
};