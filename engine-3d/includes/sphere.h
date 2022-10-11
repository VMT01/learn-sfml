#pragma once

#include "./header.h"
#include "./quaternion.h"
#include "./drawable.h"

class Sphere: public Drawable {
private:
    float radius;
    float renderRadius;
    Quaternion pos;
    Quaternion drawPos;
    sf::Color color;
    sf::CircleShape shape;
public:
    Sphere();
    Sphere(Quaternion, float, sf::Color);

    void predraw(Quaternion, Quaternion);
    void draw(sf::RenderWindow&);
};