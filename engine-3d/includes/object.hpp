#pragma once

#include "./header.hpp"
#include "./quaternion.hpp"

class Object {
protected:
    float distanceFromCamera;
public:
    Object();

    virtual void predraw(Quaternion &, Quaternion &) {}
    virtual void draw(sf::RenderWindow &) {}
};