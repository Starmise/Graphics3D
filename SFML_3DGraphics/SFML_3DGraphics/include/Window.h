#pragma once
#include "Prerequisites.h"

class Window
{
public:
	Window() = default;
  Window(int width, int height, const std::string& title);
	~Window();

  void
    initialize();

  void
    handleEvents();

  void
    update();

  void
    render();

  void
    cleanup();

  void
    clear();

  void
    display();

  bool
    isOpen() const;

  void
    draw(const sf::Drawable& drawable);

  sf::RenderWindow*
    getWindow();

  void
    destroy();

private:
  sf::RenderWindow* m_window;
};