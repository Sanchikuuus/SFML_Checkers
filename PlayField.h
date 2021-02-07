//
// Created by Sashko Shel on 19.01.2021.
//

#ifndef SFML_CHECKERS_PLAYFIELD_H
#define SFML_CHECKERS_PLAYFIELD_H

#include "Checker.h"
#include "Object.h"
#include "map"
#include "iostream"

//class Checker();

class PlayField : public Object {

    std::map<std::string, Checker*> m_checkers;
    sf::Vector2<float> m_scale;
    std::string m_turn = "White";

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
    void Update(sf::RenderWindow &target);
    void OnMouseDown(sf::RenderWindow &target);

    Checker* GetObjectWithName(const std::string& name);
    void SetColor(sf::Color color);
};


#endif //SFML_CHECKERS_PLAYFIELD_H
