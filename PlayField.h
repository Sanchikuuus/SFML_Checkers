//
// Created by Sashko Shel on 19.01.2021.
//

#ifndef SFML_CHECKERS_PLAYFIELD_H
#define SFML_CHECKERS_PLAYFIELD_H

#include "Checker.h"
#include "Object.h"
#include "map"
#include "array"
#include <random>
#include "iostream"

//class Checker();

class PlayField : public Object {


    std::map<std::string, Checker*> m_checkers;
    sf::Vector2<float> m_scale;
//    std::string m_turn = "White";

    std::string m_field[4][4];

public:
    PlayField();
    PlayField(std::string name);
    ~PlayField();

    void Fill();
    void Shuffle();
//    std::list<Checker*> GetList(std::string player) ;
    void DrawAt(sf::RenderWindow &target);
    void Update(sf::RenderWindow &target);
    void OnMouseDown(sf::RenderWindow &target);

    Checker* GetObjectWithName(const std::string& name);
    void SetColor(sf::Color color);
    bool IsCellEmpty(int x, int y, sf::Vector2<int> pos);
    void MoveChecker(Checker *ch, int x, int y, sf::Vector2<int> pos);
};


#endif //SFML_CHECKERS_PLAYFIELD_H
