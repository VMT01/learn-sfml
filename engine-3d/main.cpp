#include "./includes/header.h"
#include "./includes/drawable.h"

void predraw(Drawable *start, Quaternion cameraPos, Quaternion cameraRotation) {
    Drawable *iter = start;
    int length = 0;

    while (iter != nullptr) {
        iter->predraw(cameraPos, cameraRotation);
        iter = iter->next;
        length++;
    }

    //merge sort?
}

void draw(Drawable *start, sf::RenderWindow &window) {
    Drawable *iter = start;
    while (iter != nullptr) {
        iter->draw(window);
        iter = iter->next;
    }
}

int main() {
    srand(static_cast<unsigned>(time(NULL)));

    sf::ContextSettings settings;
    settings.antialiasingLevel = ANTI_ALIASING_LEVEL;

    sf::RenderWindow window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), WINDOW_TITLE, sf::Style::Default, settings);
    window.setMouseCursorVisible(false);

    Drawable *objects = new Drawable;
    sf::Event event;

    Quaternion cameraPos(0, 0, 0, 0);
    Quaternion cameraRotation(Quaternion(1, 0, 0, 0).normalized());
    Quaternion temporation(0, 0, 0, 0);

    int oldMouseX = WINDOW_WIDTH / 2, oldMouseY = WINDOW_HEIGHT / 2;
    int dMouseX, dMouseY;

    while (window.isOpen()) {
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) window.close();
            if (event.type == sf::Event::KeyPressed) {}
            if (event.type == sf::Event::MouseMoved) {
                dMouseX = event.mouseMove.x - oldMouseX;
                dMouseY = event.mouseMove.y - oldMouseY;

                if (dMouseX != 0 || dMouseY != 0) {
                    temporation = Quaternion(1, 0.001*dMouseY, -0.001*dMouseX, 0).normalized();
                    cameraRotation = temporation * cameraRotation;

                    sf::Mouse::setPosition(sf::Vector2i(WINDOW_WIDTH / 2, WINDOW_HEIGHT / 2), window);

                    oldMouseX = WINDOW_WIDTH / 2;
                    oldMouseY = WINDOW_HEIGHT / 2;
                }
            }
        }

        window.clear(sf::Color::Black);
        predraw(objects, cameraPos, cameraRotation);
        draw(objects, window);

        window.display();
    }

    delete objects;
    return 0;
}