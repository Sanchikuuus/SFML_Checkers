//
// Created by Sashko Shel on 19.01.2021.
//

#ifndef SFML_CHECKERS_CHECKER_H
#define SFML_CHECKERS_CHECKER_H

#include "Object.h"
#include "string"

class Checker: public Object {
    int m_row;
    int m_column;
public:
    Checker(std::string name, std::string player, int row, int column, float x = 0, float y = 0, sf::Vector2<float> scale = sf::Vector2<float>(1, 1));
};


#endif //SFML_CHECKERS_CHECKER_H
