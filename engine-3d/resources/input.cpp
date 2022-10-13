#include "../includes/input.hpp"

position::position() = default;

position::position(float _x, float _y) {
    x = _x;
    y = _y;
}
 
Input::Input() {
    oldMouse = { WINDOW_WIDTH / 2.0f, WINDOW_HEIGHT / 2.0f };
    currentMouse = oldMouse;
}

std::ostream& operator<< (std::ostream &os, Input &input) {
    os << "Old: [" << input.oldMouse.x << ',' << input.oldMouse.y 
    << "]\tNew: [" << input.currentMouse.x << ',' << input.currentMouse.y << ']';

    return os;
}

void Input::calCurrentMouse(sf::Event &event) {
    currentMouse.x = event.mouseMove.x - oldMouse.x;
    currentMouse.y = event.mouseMove.y - oldMouse.y;
}

bool Input::inBound() {
    return ((currentMouse.x != 0) || (currentMouse.y != 0));
}

void Input::resetPosition() {
    oldMouse = { WINDOW_WIDTH / 2.0f, WINDOW_HEIGHT / 2.0f };
}

position Input::getCurrentMouse() {
    return currentMouse;
}

Quaternion Input::calCurrentCameraVel(Quaternion &cameraRotation) {
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {  // forward
        return cameraRotation.inverse() * (Quaternion(0, 0, 0, 0.1)) * cameraRotation;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {  // backward
        return cameraRotation.inverse() * (Quaternion(0, 0, 0, -0.1)) * cameraRotation;
    }
    return Quaternion(0, 0, 0, 0);
}