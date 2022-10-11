#include "../includes/drawable.h"

Drawable::Drawable() {
    this->next = nullptr;
    this->child = nullptr;
    distanceFromCamera = -1;
}

void Drawable::insert(Drawable *item) {
    item->next = this->next;
    this->next = item;
}