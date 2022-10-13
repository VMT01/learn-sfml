#include "./includes/header.hpp"
#include "./includes/input.hpp"
#include "./includes/quaternion.hpp"
#include "./includes/painter.hpp"

int main() {
    srand(static_cast<unsigned>(time(NULL)));

    sf::ContextSettings settings;
    settings.antialiasingLevel = ANTI_ALIASING_LEVEL;

    sf::RenderWindow window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), WINDOW_TITLE, sf::Style::Default, settings);
    window.setMouseCursorVisible(false);

    sf::Event event;
    Input input;
    Painter painter;

    Quaternion cameraPos(0, 0, 0, 0);
    Quaternion cameraRotation(1, 0, 0, 0);
    
    while (window.isOpen()) {
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) window.close();

            if (event.type == sf::Event::KeyPressed) {
                cameraPos = cameraPos + input.calCurrentCameraVel(cameraRotation);
            }

            if (event.type == sf::Event::MouseMoved) {
                input.calCurrentMouse(event);
                if (input.inBound()) {
                    cameraRotation = Quaternion(1, ROTATE_ANGLE * input.getCurrentMouse().y, -ROTATE_ANGLE * input.getCurrentMouse().x, 0).normalized() * cameraRotation;
                    sf::Mouse::setPosition(sf::Vector2i(WINDOW_WIDTH/2, WINDOW_HEIGHT/2), window);
                    input.resetPosition();
                }
            }
        }
        
        window.clear(sf::Color::Black);
        
        painter.predraw(cameraPos, cameraRotation);
        painter.draw(window);

        window.display();
    }
    

    return 0;
}