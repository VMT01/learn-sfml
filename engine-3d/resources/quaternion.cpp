#include "../includes/quaternion.hpp"

Quaternion::Quaternion() = default;

Quaternion::Quaternion(float _x, float _y, float _z) {
    w = 0;
    x = _x;
    y = _y;
    z = _z;
}

Quaternion::Quaternion(float _w, float _x, float _y, float _z) {
    w = _w;
    x = _x;
    y = _y;
    z = _z;
}

std::ostream& operator<< (std::ostream &os, Quaternion &q) {
    os << '[' << q.w << ',' << q.x << ',' << q.y << ',' << q.z << ']';
    return os;
}

Quaternion Quaternion::operator+ (Quaternion q) {
    return Quaternion(w + q.w, x + q.x, y + q.y, z + q.z);
}

Quaternion Quaternion::operator- (Quaternion q) {
    return Quaternion(w - q.w, x - q.x, y - q.y, z - q.z);
}

Quaternion Quaternion::operator* (Quaternion q) {
    return Quaternion(
        w*q.w - x*q.x - y*q.y - z*q.z,
        w*q.x + x*q.w + y*q.z - z*q.y,
        w*q.y - x*q.z + y*q.w + z*q.x,
        w*q.z + x*q.y - y*q.x + z*q.w
    );
}

Quaternion Quaternion::operator/ (float q) {
    return Quaternion(w/q, x/q, y/q, z/q);
}

float Quaternion::getMagnitude() {
    return sqrt(w*w + x*x + y*y + z*z);
}

void Quaternion::setMagnitude(float newMag) {
    float factor = newMag / getMagnitude();
    w *= factor;
    x *= factor;
    y *= factor;
    z *= factor;
}

Quaternion Quaternion::inverse() {
    return Quaternion(w, -x, -y, -z) / getMagnitude();
}

void Quaternion::normalize() {
    setMagnitude(1.0f);
}

Quaternion Quaternion::normalized() {
    Quaternion Q(w, x, y, z);
    Q.normalize();
    return Q;
}

sf::Vector2f Quaternion::getScreenPos() {
    if (z == 0) return sf::Vector2f(-INFINITE, -INFINITE);
    return sf::Vector2f(
        RATIO * (WINDOW_WIDTH/2.0f) * (x/z) + (WINDOW_WIDTH/2.0f),
        RATIO * (WINDOW_HEIGHT/2.0f) * (y/z) + (WINDOW_HEIGHT/2.0f)
    );
}

float Quaternion::getZ() {
    return z;
}