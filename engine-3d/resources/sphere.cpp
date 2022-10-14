#include "../includes/sphere.hpp"

Sphere::Sphere() = default;

Sphere::Sphere(Quaternion _pos, float _radius, sf::Color _color) {
    pos = _pos;
    radius = _radius;
    color = _color;
}

bool Sphere::isVisable() {
    if (drawPos.getScreenPos().x < -renderRadius) return false;
    if (drawPos.getScreenPos().x > WINDOW_WIDTH + renderRadius) return false;

    if (drawPos.getScreenPos().y < -renderRadius) return false;
    if (drawPos.getScreenPos().y > WINDOW_HEIGHT + renderRadius) return false;

    return true;
}

bool Sphere::predraw(Quaternion &cameraPos, Quaternion &cameraRotation) {
    drawPos = cameraRotation * (pos - cameraPos) * cameraRotation.inverse();
    distanceFromCamera = drawPos.getMagnitude();
    renderRadius = radius / distanceFromCamera;

    // check for drawable
    if (drawPos.getZ() < 0 || !isVisable()) {
        return false;
    }

    shape.setFillColor(color);
    shape.setRadius(renderRadius);
    shape.setPosition(drawPos.getScreenPos() + sf::Vector2f(-renderRadius, -renderRadius));
    return true;
}

void Sphere::draw(sf::RenderWindow &window) {
    window.draw(shape);
}

float Sphere::getDistanceFromCamera() {
    return distanceFromCamera;
}