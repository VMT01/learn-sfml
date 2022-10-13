#pragma once

#include "./header.hpp"

class Quaternion {
private:
    float w, x, y, z;
public:
    Quaternion();
    Quaternion(float, float, float);
    Quaternion(float, float, float, float);
 
    friend std::ostream& operator<< (std::ostream&, Quaternion&);

    Quaternion operator+ (Quaternion);
    Quaternion operator- (Quaternion);
    Quaternion operator* (Quaternion);
    Quaternion operator/ (float);

    float getMagnitude();
    void setMagnitude(float);
    Quaternion inverse();
    void normalize();
    Quaternion normalized();
    sf::Vector2f getScreenPos();

    float getZ();
};