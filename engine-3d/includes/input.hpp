#pragma once

#include "./header.hpp"
#include "./quaternion.hpp"

typedef struct position {
    float x;
    float y;

    position();
    position(float, float);
} position;

class Input {
private:
    position oldMouse;
    position currentMouse;
protected:
public:
    Input();

    friend std::ostream& operator<< (std::ostream &, Input &);

    void calCurrentMouse(sf::Event&);
    bool inBound();
    void resetPosition();
    position getCurrentMouse();

    Quaternion calCurrentCameraVel(Quaternion &);
};