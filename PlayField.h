//
// Created by Sashko Shel on 19.01.2021.
//

#ifndef SFML_CHECKERS_PLAYFIELD_H
#define SFML_CHECKERS_PLAYFIELD_H

#include "Checker.h"
#include "Object.h"
#include "list"

//class Checker();

class PlayField : public Object {

    std::list<Checker> m_checkers_red;
    std::list<Checker> m_checkers_white;

public:
    PlayField();
    ~PlayField();

    void Fill();
    std::list<Checker> GetList(std::string player) ;
};


#endif //SFML_CHECKERS_PLAYFIELD_H
