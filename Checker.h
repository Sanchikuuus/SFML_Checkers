//
// Created by Sashko Shel on 19.01.2021.
//

#ifndef SFML_CHECKERS_CHECKER_H
#define SFML_CHECKERS_CHECKER_H

#include "Object.h"
#include "string"

class Checker: public Object {

    int m_column;
    int m_row;
public:
    Checker(std::string name, std::string player, int row, int column, float x = 0, float y = 0, sf::Vector2<float> scale = sf::Vector2<float>(1, 1));
    Checker(std::string name, int row, int column, float x, float y, sf::Vector2<float> scale);

    sf::Vector2<int> GetPosition();
    void SetPosition(int x, int y);
};


#endif //SFML_CHECKERS_CHECKER_H
