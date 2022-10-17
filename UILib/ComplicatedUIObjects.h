#pragma once

#include "UIObjects.h"
#include "SFML/Graphics.hpp"

#include <vector>
#include <memory>


class FileButton : public TwoPositionButton
{
public:
    FileButton(sf::Vector2f __leftBottomCorner, sf::Vector2f __size,
            sf::Color __backgroundColor, sf::Text& __text, 
            sf::Color __textColor, sf::RenderWindow* __ownerWindow);

    void draw() override;

private:
    std::shared_ptr<ButtonList> buttonListPtr;
};