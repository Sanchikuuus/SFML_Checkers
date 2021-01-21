//
// Created by Sashko Shel on 19.01.2021.
//

#ifndef SFML_CHECKERS_PLAYFIELD_H
#define SFML_CHECKERS_PLAYFIELD_H

#include "Checker.h"
#include "Object.h"
#include "map"

//class Checker();

class PlayField : public Object {

    std::map<std::string, Checker*> m_checkers;
    sf::Vector2<float> m_scale;

    std::string field[8][8] {
            {"", "1", "", "1", "", "1", "", "1"},
            {"1", "", "1", "", "1", "", "1", ""},
            {"", "1", "", "1", "", "1", "", "1"},
            {"", "", "", "", "", "", "", ""},
            {"", "", "", "", "", "", "", ""},
            {"2", "", "2", "", "2", "", "2", ""},
            {"", "2", "", "2", "", "2", "", "2"},
            {"2", "", "2", "", "2", "", "2", ""},
    };

public:
    PlayField();
    ~PlayField();

    void Fill();
//    std::list<Checker*> GetList(std::string player) ;
    void DrawAt(sf::RenderWindow &target);

    Checker* GetObjectWithName(const std::string& name);
};


#endif //SFML_CHECKERS_PLAYFIELD_H
