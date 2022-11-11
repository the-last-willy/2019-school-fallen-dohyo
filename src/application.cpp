#include"application.hpp"

Application::Application(unsigned width, unsigned height, int framerate)
    : _framerate{framerate}
    , _window{sf::VideoMode{width, height}, "Fallen Dohyo"}

    , _stateMachine{_context}
{
    _context.canvas(_window);
    _context.entities(_entities);
    _context.framerate(_framerate);
    _context.music(_music);
    _context.textures(_textures);
    _context.window(_window);

    _stateMachine.push<TitleState>();
}

int Application::framerate() const {
    return _framerate;
}

bool Application::running() const {
    return not _stateMachine.empty() and _window.isOpen();
}

void Application::handleEvents() {
    for(sf::Event event; _window.pollEvent(event);) {
        if(sf::Event::Closed == event.type)
            _window.close();
        else
            _stateMachine.handle(event);
    }
}

void Application::update() {
    _stateMachine.update();
}

void Application::draw() {
    _window.clear();
    _stateMachine.draw();
    _window.display();
}

void run(Application& app) {
    auto clock = sf::Clock{};
    auto const timePerFrame = sf::seconds(1. / app.framerate());
    auto timeSinceUpdate = sf::Time::Zero;

    while(app.running()) {
        timeSinceUpdate += clock.restart();
        if(timeSinceUpdate >= timePerFrame) {
            app.update();
            app.draw();
            app.handleEvents();

            // skip accumulated frames
            timeSinceUpdate %= timePerFrame;
        }
    }
}
