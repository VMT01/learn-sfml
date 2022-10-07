#include "./includes/solver.h"

int main() {
    srand(static_cast<unsigned>(time(NULL)));

    sf::ContextSettings settings;
    settings.antialiasingLevel = ANTI_ALIASING_LEVEL;

    sf::View view(sf::Vector2f(0.0f, 0.0f), sf::Vector2f(WINDOW_WIDTH, WINDOW_HEIGHT));

    sf::RenderWindow window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), WINDOW_TITLE, sf::Style::Default, settings);
    window.setFramerateLimit(60);
    window.setView(view);

    Solver solver;

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) window.close();
        }

        solver.update();
        window.clear(sf::Color::Black);
        solver.render(window);
        window.display();
    }

    return 0;
}     