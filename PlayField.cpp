//
// Created by Sashko Shel on 19.01.2021.
//

#include "PlayField.h"

PlayField::PlayField() : Object("textures/board.jpg"){

}

PlayField::~PlayField() {

}

void PlayField::Fill() {

//    for(int k = 1; k < 2; ++k) {
//        for(int i = 1; i < 2; ++i) {
//    Checker ch = Checker("Red", 200 , 100 , GetScele() );
//    m_checkers_red.push_back(&ch);
//            m_checkers_white.push_back(Checker("White", 200 * i, 500 + k * 150, GetScele() ));
//        }
//    }
}

std::list<Checker> PlayField::GetList(std::string player) {
    if(player == "Red")
        return m_checkers_red;
    else
        return m_checkers_white;
}

