#include "../includes/painter.hpp"
#include "../includes/sphere.hpp"

Painter::Painter() {
    for (int i = 0; i < MAX_SPHERE; i++) {
        objects.push_back(new Sphere(Quaternion(std::rand() % 100, std::rand() % 100, std::rand() % 100), std::rand() % 1000, sf::Color(std::rand() % 255, std::rand() % 255, std::rand() % 255)));
    }
}

Painter::~Painter() {
    for (int i = 0; i < MAX_SPHERE; i++) {
        delete objects[i];
    }
}

void Painter::predraw(Quaternion &cameraPos, Quaternion &cameraRotation) {
    drawableObjects.clear();
    for (Object *o: objects) {
        if (o->predraw(cameraPos, cameraRotation)) {
            drawableObjects.push_back(o);
        }
    }
    
    std::sort(drawableObjects.begin(), drawableObjects.end(), [](Object *a, Object *b) {
        return a->getDistanceFromCamera() >= b->getDistanceFromCamera();
    });
}

void Painter::draw(sf::RenderWindow &window) {
    for (Object *o: drawableObjects) {
        o->draw(window);
    }
}