#include "BaseApp.h"

int 
BaseApp::run() {
  initialize();
  while (window->isOpen())
  {
    handleEvents();
    update();
    render();
  }

  cleanup();
}

void 
BaseApp::initialize() {
  window = new sf::RenderWindow(sf::VideoMode(800, 600), "Starmise Engine");
  shape = new sf::CircleShape(100.0f);
  shape->setFillColor(sf::Color::Cyan);
}

void 
BaseApp::handleEvents() {
  sf::Event event;
  while (window->pollEvent(event))
  {
    if (event.type == sf::Event::Closed)
      window->close();
  }
}

void 
BaseApp::update() {
}

void 
BaseApp::render() {
  window->clear();
  window->draw(*shape);
  window->display();
}

void 
BaseApp::cleanup() {
  delete window;
  delete shape;
}
