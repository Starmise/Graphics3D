#include "BaseApp.h"

int 
BaseApp::run() {
  if (!initialize) {
    ERROR("BaseApp", "run", "initializes result on a false statement");
  }
  initialize();
  while (m_window->isOpen()) {
    m_window->handleEvents();
    update();
    render();
  }

  cleanup();
}

bool 
BaseApp::initialize() {
  m_window = new Window(800, 600, "Starmise Engine");
  if (!m_window) {
    ERROR("BaseApp", "initialize", "Error on window creation, var is null");
    return false;
  }

  shape = new sf::CircleShape(10.0f);
  if (!shape) {
    ERROR("BaseApp", "initialize", "Error on window creation, var is null");
    return false;
  }
  shape->setFillColor(sf::Color::Cyan);
  shape->setPosition(300.0f, 200.0f);

  Triangulo = new sf::CircleShape(30.0f, 3);
  if (!shape) {
    ERROR("BaseApp", "initialize", "Error on window creation, var is null");
    return false;
  }
  Triangulo->setFillColor(sf::Color::Cyan);
  Triangulo->setPosition(300.0f, 200.0f);

  return true;
}

void 
BaseApp::update() {
}

void 
BaseApp::render() {
  m_window->clear();
  m_window->draw(*shape);
  m_window->display();
}

void 
BaseApp::cleanup() {
  m_window->destroy();
  delete m_window;
  delete shape;
}
