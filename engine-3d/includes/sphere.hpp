#pragma once

#include "./header.hpp"
#include "./object.hpp"
#include "./quaternion.hpp"

class Sphere: public Object {
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

    bool isVisable();
    bool predraw(Quaternion &, Quaternion &);
    void draw(sf::RenderWindow &);
    float getDistanceFromCamera();
};