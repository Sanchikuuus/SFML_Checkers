//
// Created by Sashko Shel on 19.01.2021.
//
#include "Object.h"

Object::Object(std::string path, float x, float y, sf::Vector2<float> scale) :    m_texturePath(path),
                                                        m_x(x),
                                                        m_y(y),
                                                        m_texture(),
                                                        m_sprite()
{
    m_texture.loadFromFile(m_texturePath);
    m_sprite.setTexture(m_texture);
    m_sprite.setPosition(x, y);
    SetScale(scale);
}

Object::~Object() {

}

sf::Sprite &Object::GetSprite() {
    return m_sprite;
}

void Object::SetScale(sf::Vector2<float> scale) {
    m_sprite.scale(scale);
}

sf::Vector2<float> Object::GetScele() {
    return m_sprite.getScale();
}
