#pragma once

#include "./header.h"
#include "./point.h"

class Solver {
private:
    std::vector<Point*> vPoints;

public:
    Solver();
    ~Solver();

    friend std::ostream& operator<< (std::ostream&, Solver&);

    void update();
    void render(sf::RenderTarget&);
};