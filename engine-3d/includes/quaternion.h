#pragma once

#include "./header.h"

class Quaternion {
private:
    float x;
    float y;
    float z;
    float w;
public:
    Quaternion();
    Quaternion(float, float, float);
    Quaternion(float, float, float, float);

    Quaternion operator+ (Quaternion);
    Quaternion operator- (Quaternion);
    Quaternion operator* (float);
    Quaternion operator* (Quaternion);
    Quaternion operator/ (float);
    bool operator< (float);

    Quaternion inverse();
    float getMagnitude();
    void setMagnitude(float);
    void normalize();
    Quaternion normalized();
    sf::Vector2f getScreenPos();
};