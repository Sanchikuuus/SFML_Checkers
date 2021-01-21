//
// Created by Sashko Shel on 19.01.2021.
//

#include "PlayField.h"

PlayField::PlayField() : Object("PlayField", "textures/board.jpg"){

}

PlayField::~PlayField() {

    for(const auto& ch : m_checkers) {
        delete ch.second;
    }
}

void PlayField::Fill() {

    sf::Vector2<float> scaleVector = this->GetScale();
    float scale = scaleVector.x;

    int redCounter = 0;
    int whiteCounter = 0;
    for(auto & i : field) {
        for(auto & k : i) {
            std::string player;
            int counter = 0;
            if(k == "1") {
                player = "Red";
                redCounter++;
                counter = redCounter;
            } else if (k == "2") {
                player = "White";
                whiteCounter++;
                counter = whiteCounter;
            } else
                continue;
            auto *ch = new Checker( player + "_" + std::to_string(counter), player,
                                    scale * 100 * counter / 2 , scale * 100 * counter / 2, scaleVector );
            k = ch->GetName();
            m_checkers.insert({k, ch});
        }
    }
}


void PlayField::DrawAt(sf::RenderWindow &target) {

    for(const auto& ch : m_checkers) {
        target.draw(ch.second->GetSprite());
    }
}

Checker *PlayField::GetObjectWithName(const std::string& name) {
    return m_checkers["name"];
}

