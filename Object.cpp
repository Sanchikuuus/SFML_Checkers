//
// Created by Sashko Shel on 19.01.2021.
//
#include "Object.h"

Object::Object(std::string name, std::string path, float x, float y, sf::Vector2<float> scale) :    m_texturePath(path),
                                                        m_x(x),
                                                        m_y(y),
                                                        m_texture(),
                                                        m_sprite(),
                                                        m_scale(scale),
                                                        m_name(name)
{
    if (m_texturePath != "") {
        m_texture.loadFromFile(m_texturePath);
        m_sprite.setTexture(m_texture);
        m_sprite.setPosition(x, y);
    }
    SetScale(m_scale);
}

Object::~Object() {

}

sf::Sprite &Object::GetSprite() {
    return m_sprite;
}

void Object::SetScale(sf::Vector2<float> scale) {
    m_scale = scale;
    m_sprite.scale(m_scale);
}

sf::Vector2<float> Object::GetScale() {
    return m_scale;
}

std::string Object::GetName(){
    return m_name;
}
 void Object::SetColor(sf::Color color) {
    this->GetSprite().setColor(color);
}