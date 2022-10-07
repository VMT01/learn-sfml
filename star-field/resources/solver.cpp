#include "../includes/solver.h"

Solver::Solver() {
    for (int _ = 0; _ < MAX_POINT_NUMBER; _++) {
        this->vPoints.push_back(new Point());
    }
};

Solver::~Solver() {
    for (Point* _p: this->vPoints) {
        delete(_p);
    }
}

std::ostream& operator<< (std::ostream& os, Solver& solver) {
    for (Point* _p: solver.vPoints) {
        os << *_p << '\n';
    }
    return os;
}

void Solver::update() {
    for (Point* _p: this->vPoints) {
        _p->update();
    }
}

void Solver::render(sf::RenderTarget& renderTarget) {
    for (Point* _p: this->vPoints) {
        _p->render(renderTarget);
    }
}