#pragma once

#include "./header.h"
#include "./utils.h"

class Point {
private:
    float x;
    float y;
    float z;
    float alpha;

public:
    Point();
    Point(float _x, float _y, float _z);

    friend std::ostream& operator<< (std::ostream&, const Point&);

    bool insideField();
    void update();
    void render(sf::RenderTarget&);
};