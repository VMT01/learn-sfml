#include "../includes/sphere.hpp"

Sphere::Sphere() = default;

Sphere::Sphere(Quaternion _pos, float _radius, sf::Color _color) {
    pos = _pos;
    radius = _radius;
    color = _color;
}

void Sphere::predraw(Quaternion &cameraPos, Quaternion &cameraRotation) {
    drawPos = cameraRotation * (pos - cameraPos) * cameraRotation.inverse();
    distanceFromCamera = drawPos.getMagnitude();
    renderRadius = radius / distanceFromCamera;

    shape.setFillColor(color);
    if (drawPos.getZ() < 0) shape.setRadius(0);
    else shape.setRadius(renderRadius);

    shape.setPosition(drawPos.getScreenPos() + sf::Vector2f(-renderRadius, -renderRadius));
}

void Sphere::draw(sf::RenderWindow &window) {
    window.draw(shape);
}