#pragma once

#include "./header.hpp"
#include "./quaternion.hpp"

typedef struct Position {
    float x;
    float y;

    Position();
    Position(float, float);
} Position;

typedef struct Keyboard {
    bool up;
    bool down;
    bool left;
    bool right;

    Keyboard();
} Keyboard;

class Input {
private:
    Position oldMouse;
    Position currentMouse;
    Keyboard keyboard; 
protected:
public:
    Input();

    friend std::ostream& operator<< (std::ostream &, Input &);

    void calCurrentMouse(sf::Event&);
    bool inBound();
    void resetPosition();
    Position getCurrentMouse();

    void handleKeyPressed(sf::Event &);
    void handleKeyReleased(sf::Event &);
    bool isMoving();

    Quaternion calCurrentCameraVel(Quaternion &, Quaternion &);
};