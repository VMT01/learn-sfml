#pragma once

#include "./header.hpp"
#include "./quaternion.hpp"

class Object {
protected:
    float distanceFromCamera;
public:
    Object();

    virtual bool predraw(Quaternion &, Quaternion &) = 0;
    virtual void draw(sf::RenderWindow &) {}
    virtual float getDistanceFromCamera() = 0;
};