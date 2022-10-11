#include "../includes/quaternion.h"

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

Quaternion Quaternion::operator+ (Quaternion q) {
    return Quaternion(w + q.w, x + q.x, y + q.y, z + q.z);
}

Quaternion Quaternion::operator- (Quaternion q) {
    return Quaternion(w + q.w, x + q.x, y + q.y, z + q.z);
}

Quaternion Quaternion::operator* (float q) {
    return Quaternion(w * q, x * q, y * q, z * q);
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
    return Quaternion(w / q, x / q, y / q, z / q);
}

bool Quaternion::operator< (float q) {
    return z < q;
}

Quaternion Quaternion::inverse() {
    return Quaternion(w, -x, -y, -z) / getMagnitude();
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

void Quaternion::normalize() {
    setMagnitude(1.0f);
}

Quaternion Quaternion::normalized() {
    Quaternion q(w, x, y, z);
    q.normalize();

    return q;
}

sf::Vector2f Quaternion::getScreenPos() {
    if (z == 0) return sf::Vector2f(-1000.0f, -1000.0f);
    return sf::Vector2f(
        RATIO * (WINDOW_WIDTH/2.0f) * (x/z) + (WINT_WIDTH/2.0f),
        RATIO * (WINDOW_HEIGHT/2.0f) * (y/z) + (WINDOW_HEIGHT/2.0f)
    );
}