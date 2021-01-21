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

    const int squareSize = 203;

    int redCounter = 0;
    int whiteCounter = 0;
    for(int i = 0; i < 8; ++i) {
        for(int k = 0; k < 8; ++k) {
            std::string player;
            int counter = 0;
            if(field[i][k] == "1") {
                player = "Red";
                redCounter++;
                counter = redCounter;
            } else if (field[i][k]  == "2") {
                player = "White";
                whiteCounter++;
                counter = whiteCounter;
            } else
                continue;
            auto *ch = new Checker( player + "_" + std::to_string(counter), player, k, i,
                                    (squareSize * (k+1) - 95 ) * scale , (squareSize * (i+1) - 95 ) * scale,
                                    scaleVector );
            field[i][k]  = ch->GetName();
            m_checkers.insert({field[i][k] , ch});
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

void PlayField::SetColor(sf::Color color) {
    this->GetSprite().setColor(color);
    for(const auto& ch : m_checkers) {
        ch.second->SetColor(color);
    }
}

void PlayField::Update(sf::RenderWindow &target) {

    if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
    {
        for(const auto& ch : m_checkers)
        {
            sf::Vector2<int> mousePos = sf::Mouse::getPosition(target);
            if (ch.second->GetSprite().getGlobalBounds().contains(mousePos.x, mousePos.y))
            {
//                ch.second->GetSprite().setPosition(mousePos.x, mousePos.y);
//                ch.second->GetSprite().move;
            }
        }
    }

    target.clear();
    target.draw(GetSprite());

    DrawAt(target);

    target.display();
}



