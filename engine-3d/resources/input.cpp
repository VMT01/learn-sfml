#include "../includes/input.hpp"

Position::Position() {
    x = 0.0f;
    y = 0.0f;
};

Position::Position(float _x, float _y) {
    x = _x;
    y = _y;
}

Keyboard::Keyboard() {
    up = false;
    down = false;
    left = false;
    right = false;
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

// mouse
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

Position Input::getCurrentMouse() {
    return currentMouse;
}

// keyboard
void Input::handleKeyPressed(sf::Event &event) {
    if (event.key.code == sf::Keyboard::W || event.key.code == sf::Keyboard::Up) keyboard.up = true;
    if (event.key.code == sf::Keyboard::S || event.key.code == sf::Keyboard::Down) keyboard.down = true;
    if (event.key.code == sf::Keyboard::A || event.key.code == sf::Keyboard::Left) keyboard.left = true;
    if (event.key.code == sf::Keyboard::D || event.key.code == sf::Keyboard::Right) keyboard.right = true;
}

void Input::handleKeyReleased(sf::Event &event) {
    if (event.key.code == sf::Keyboard::W || event.key.code == sf::Keyboard::Up) keyboard.up = false;
    if (event.key.code == sf::Keyboard::S || event.key.code == sf::Keyboard::Down) keyboard.down = false;
    if (event.key.code == sf::Keyboard::A || event.key.code == sf::Keyboard::Left) keyboard.left = false;
    if (event.key.code == sf::Keyboard::D || event.key.code == sf::Keyboard::Right) keyboard.right = false;
}

bool Input::isMoving() {
    return keyboard.up || keyboard.down || keyboard.left || keyboard.right;
}

// helper
Quaternion Input::calCurrentCameraVel(Quaternion &tempCameraPos, Quaternion &cameraRotation) {
    tempCameraPos = Quaternion(0, 0, 0, 0);
    if (keyboard.up) tempCameraPos = tempCameraPos + cameraRotation.inverse() * (Quaternion(0, 0, 0, MOVE_SPEED)) * cameraRotation;
    if (keyboard.down) tempCameraPos = tempCameraPos + cameraRotation.inverse() * (Quaternion(0, 0, 0, -MOVE_SPEED)) * cameraRotation;
    if (keyboard.left) tempCameraPos = tempCameraPos + cameraRotation.inverse() * (Quaternion(0, -MOVE_SPEED, 0, 0)) * cameraRotation;
    if (keyboard.right) tempCameraPos = tempCameraPos + cameraRotation.inverse() * (Quaternion(0, MOVE_SPEED, 0, 0)) * cameraRotation;
    
    return tempCameraPos;
}