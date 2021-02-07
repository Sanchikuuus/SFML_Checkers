//
// Created by Sashko Shel on 19.01.2021.
//

#include "PlayField.h"

#include <utility>

PlayField::PlayField() : Object("PlayField", "textures/board.jpg"){

}

PlayField::PlayField(std::string name) : Object(std::move(name), "") {

}

PlayField::~PlayField() {

    for(const auto& ch : m_checkers) {
        delete ch.second;
    }
}

void PlayField::Shuffle() {

    std::array<std::string, 15> names;
    for (int i = 1; i < 16; ++i )
        names[i-1] = std::to_string(i);

    std::random_device rd; // https://en.cppreference.com/w/cpp/algorithm/random_shuffle
    std::mt19937 g(rd());
    std::shuffle(names.begin(), names.end(), g);

    for (int i = 0; i < 4; ++i)
    {
        for (int k = 0; k < 4; ++k)
        {
            if( (i * 4 + k) > 14)
            {
                m_field[i][k] = "";
                break;
            }
            m_field[i][k] = names[i * 4 + k];
        }
    }
}

void PlayField::Fill() {

    sf::Vector2<float> scaleVector = this->GetScale();
    const int squareSize = 200;
    int scale = scaleVector.x;

    Shuffle();

    for(int i = 0; i < 4; ++i)
    {
        for(int k = 0; k < 4; ++k)
        {
            if( (i * 4 + k) > 14)
                break;
            auto *ch = new Checker( m_field[i][k], k, i,
                                        (squareSize * (k)) * scale , (squareSize * i) * scale,
                                        scaleVector );
            m_checkers.insert({m_field[k][i] , ch});
        }
    }
}

void PlayField::DrawAt(sf::RenderWindow &target) {
    for(const auto& ch : m_checkers)
        target.draw(ch.second->GetSprite());
}

Checker *PlayField::GetObjectWithName(const std::string& name) {
    return m_checkers[name];
}

void PlayField::SetColor(sf::Color color) {
    this->GetSprite().setColor(color);
    for(const auto& ch : m_checkers)
        ch.second->SetColor(color);
}

void PlayField::Update(sf::RenderWindow &target) {

    target.clear();
    target.draw(GetSprite());

    DrawAt(target);

    target.display();
}

void PlayField::OnMouseDown(sf::RenderWindow &target) {
    for(const auto& ch : m_checkers)
    {
        sf::Vector2<int> mousePos = sf::Mouse::getPosition(target);

        if (ch.second->GetSprite().getGlobalBounds().contains(mousePos.x, mousePos.y))
        {
            sf::Vector2<int> pos = ch.second->GetPosition();

            if ( IsCellEmpty(-1, 0, pos)) // look left
            {
                MoveChecker(ch.second, -1, 0, pos);
            } else if ( IsCellEmpty(1, 0, pos)) // look right
            {
                MoveChecker(ch.second, 1, 0, pos);
            } else if (IsCellEmpty(0, -1, pos))  // look up
            {
                MoveChecker(ch.second, 0, -1, pos);
            } else if (IsCellEmpty(0, 1, pos))  // look down
            {
                MoveChecker(ch.second, 0, 1, pos);
            } else {

            }
        }
    }
}

bool PlayField::IsCellEmpty(int x, int y, sf::Vector2<int> pos) {
    if ( ((pos.x+x) < 0) || ((pos.x+x) > 3) || ((pos.y+y) < 0) || ((pos.y+y) > 3) )
        return false;
    return m_field[pos.x+x][pos.y+y].empty();
}

void PlayField::MoveChecker(Checker *ch, int x, int y, sf::Vector2<int> pos) {
    ch->SetPosition(pos.x+x, pos.y+y);
    m_field[pos.x][pos.y] = "";
    m_field[pos.x+x][pos.y+y] = ch->GetName();
}


