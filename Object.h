//
// Created by Sashko Shel on 19.01.2021.
//

#ifndef SFML_CHECKERS_OBJECT_H
#define SFML_CHECKERS_OBJECT_H

#include <SFML/Graphics.hpp>
#include "string"

class Object {

private:
    sf::Texture m_texture;
    sf::Sprite m_sprite;
    std::string m_texturePath;
    float m_x, m_y;

public:
    Object(std::string path, float x = 0, float y = 0, sf::Vector2<float> scale = sf::Vector2<float>(1, 1));
    ~Object();
    sf::Sprite&  GetSprite();
    void SetScale(sf::Vector2<float>);
    sf::Vector2<float> GetScele();
};


#endif //SFML_CHECKERS_OBJECT_H
