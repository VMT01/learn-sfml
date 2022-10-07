#include "../includes/point.h"

Point::Point() {
    this->x = genRandom(0.0f, WINDOW_WIDTH) - WINDOW_WIDTH / 2.0f;
    this->y = genRandom(0.0f, WINDOW_HEIGHT) - WINDOW_HEIGHT / 2.0f;
    this->z = 0.0f;
    this->alpha = this->y / this->x;
}

Point::Point(float _x, float _y, float _z) {
    this->x = _x;
    this->y = _y;
    this->z = _z;
    this->alpha = _y /_x;
}

std::ostream& operator<< (std::ostream& os, const Point& p) {
    os << "[" << p.x << ", " << p.y << ", " << p.z << ", " << p.alpha << ", " << p.direction << "]";
    return os;
}

bool Point::insideField() {
    if (this->x < - WINDOW_WIDTH / 2.0f || this->x > WINDOW_WIDTH / 2.0f) return false;
    if (this->y < - WINDOW_HEIGHT / 2.0f || this->x > WINDOW_HEIGHT / 2.0f) return false;

    return true;
}

void Point::update() {
    this->z += ZOOM_STEP;

    if (this->alpha < -1 || this->alpha > 1) {
        if (this->y < 0) this->y -= Y_JUMP_STEP;
        else this->y += Y_JUMP_STEP;
        this->x = this->y / this->alpha;
    } else {
        if (this->x < 0) this->x -= X_JUMP_STEP;
        else this->x += X_JUMP_STEP;
        this->y = this->alpha * this->x;
    }
    
    if (this->insideField() == false) {
        this->x = genRandom(0.0f, WINDOW_WIDTH) - WINDOW_WIDTH / 2.0f;
        this->y = genRandom(0.0f, WINDOW_HEIGHT) - WINDOW_HEIGHT / 2.0f;
        this->z = 0.0f;
    }
}

void Point::render(sf::RenderTarget& renderTarget) {
    sf::CircleShape circleShape(this->z);
    circleShape.setPosition(this->x - this->z, this->y - this->z);
    circleShape.setFillColor(sf::Color::White);

    renderTarget.draw(circleShape);
}