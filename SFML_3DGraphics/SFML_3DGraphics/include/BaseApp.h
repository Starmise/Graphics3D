#pragma once
#include <SFML/Graphics.hpp>
#include "Window.h"

class BaseApp
{
public:
	BaseApp() = default;
	~BaseApp() = default;

  //Función encargada de correr la aplicación en main
  int 
    run();

  //Función de inicialización
  void 
    initialize();

  //Función que se actualiza por frame 
  void 
    update();

  //Función de renderizado
  void 
    render();

  void 
    cleanup();

private:
  Window* m_window;
  //sf::RenderWindow* window;
  sf::CircleShape* shape;
};
