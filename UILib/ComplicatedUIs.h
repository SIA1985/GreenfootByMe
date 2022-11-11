#pragma once

#include "UI.h"


class Menubar : public UI
{
public:
    Menubar(sf::RenderWindow* __ownerWindow);

};

class SceneAndControlPanel : public UI
{
public:
    SceneAndControlPanel(sf::RenderWindow* __ownnerWindow);
};


class MainWindowsUI : public UI
{
public:
    MainWindowsUI(sf::RenderWindow* __ownnerWindow);

    void drawElements() override;

    void OnClickedUI() override;

    void OnResolutionChanged(const sf::Vector2f& __sizeCoeficent) override;

private:
    std::vector<std::shared_ptr<UI>> elements;
};


class HelpWindowsUI : public UI
{
public:
    HelpWindowsUI(sf::RenderWindow* __ownnerWindow);
    
    void OnClickedUI() override;
};

class ClassTree : public UI
{
public:
    ClassTree(sf::RenderWindow* __ownnerWindow);

    void OnClickedUI() override;
};