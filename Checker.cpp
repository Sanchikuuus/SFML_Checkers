//
// Created by Sashko Shel on 19.01.2021.
//

#include "Checker.h"

Checker::Checker(std::string name, std::string player, int row, int column, float x, float y, sf::Vector2<float> scale) :
                    Object(name, "textures/checker"+player+".png", x, y, scale),
                    m_column(column),
                    m_row(row)
{
    sf::Sprite sprite = GetSprite();
    sprite.setOrigin(158/2, 158/2);
}
