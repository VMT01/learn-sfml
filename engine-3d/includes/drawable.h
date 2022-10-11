#pragma once

#include "./quaternion.h"

class Drawable {
public:
    Drawable *next;
    Drawable *child;
    float distanceFromCamera;
    bool shouldDraw;

    Drawable();

    virtual void predraw(Quaternion, Quaternion);
    virtual void draw(sf::RenderWindow &window);
    virtual void insert(Drawable *);
};