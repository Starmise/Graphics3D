#include "Window.h"

/*
 * @brief Constructor de la clase Window
 * @param width Ancho de la ventana
 * @param height Alto de la ventana
 * @param title T�tulo de la ventana
 */
Window::Window(int width, int height, const std::string& title) {
  m_window = new sf::RenderWindow(sf::VideoMode(width, height), title);

  if (!m_window) {
    ERROR("Window", "Window", "CHECK CONSTRUCTOR");
  }
  else {
    MESSAGE("Window", "Window", "OK");
  }
}

Window::~Window() {
  delete m_window;
}

/*
 * @brief Maneja los eventos de la ventana, como el cierre de la misma
 */
void
Window::handleEvents() {
  sf::Event event;
  while (m_window->pollEvent(event))
  {
    if (event.type == sf::Event::Closed)
      m_window->close();
  }
}

/*
 * @brief Limpia la ventana, prepar�ndola para el siguiente ciclo de renderizado
 */
void
Window::clear() {
  if (m_window != nullptr) {
    m_window->clear();
  }
  else {
    ERROR("Window", "clear", "CHECK FOR WINDOW POINTER DATA");
  }
}

void
Window::display() {
  if (m_window != nullptr) {
    m_window->display();
  }
  else {
    ERROR("Window", "display", "CHECK FOR WINDOW POINTER DATA");
  }
}

/*
 * @brief Verifica si la ventana est� abierta
 * @return true si la ventana est� abierta, false de lo contrario
 */
bool
Window::isOpen() const {
  if (m_window != nullptr) {
    return m_window->isOpen();
  }
  else {
    ERROR("Window", "isOpen", "CHECK FOR WINDOW POINTER DATA");
    return false;
  }
}

/*
 * @brief Dibuja un objeto en la ventana
 * @param drawable Objeto SFML que se va a dibujar en la ventana
 */
void
Window::draw(const sf::Drawable& drawable) {
  if (m_window != nullptr) {
    m_window->draw(drawable);
  }
  else {
    ERROR("Window", "draw", "CHECK FOR WINDOW POINTER DATA");
  }
}

sf::RenderWindow*
Window::getWindow() {
  if (m_window != nullptr) {
    return m_window;
  }
  else {
    ERROR("Window", "getWindow", "CHECK FOR WINDOW POINTER DATA");
    return nullptr;
  }
}

/*
 * @brief Libera los recursos de la ventana
 */
void
Window::destroy() {
  SAFE_PTR_RELEASE(m_window);
}