#pragma once

#include "./header.hpp"
#include "./object.hpp"
#include "./quaternion.hpp"

class Painter {
private:
    std::vector<Object *> objects;
    std::vector<Object *> drawableObjects;
public:
    Painter();
    ~Painter();

    void predraw(Quaternion &, Quaternion &);
    void draw(sf::RenderWindow &);
};