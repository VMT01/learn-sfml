#include "../includes/painter.hpp"
#include "../includes/sphere.hpp"

Painter::Painter() {
    for (int i = 0; i < MAX_SPHERE; i++) {
        objects.push_back(new Sphere(Quaternion(std::rand() % 100, std::rand() % 100, std::rand() % 100), 500, sf::Color(std::rand() % 255, std::rand() % 255, std::rand() % 255)));
    }
}

Painter::~Painter() {
    for (int i = 0; i < MAX_SPHERE; i++) {
        delete objects[i];
    }
}

void Painter::predraw(Quaternion &cameraPos, Quaternion &cameraRotation) {
    for (Object *o: objects) {
        o->predraw(cameraPos, cameraRotation);
    }
}

void Painter::draw(sf::RenderWindow &window) {
    for (Object *o: objects) {
        o->draw(window);
    }
}