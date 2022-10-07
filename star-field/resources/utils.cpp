#include "../includes/utils.h"

/*
* This will generate a number from low to high
* @param low
* @param high
*/
float genRandom(float low, float high) {
    return static_cast<float> (rand()) / static_cast<float>(RAND_MAX / (high - low));
}