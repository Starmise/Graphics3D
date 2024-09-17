#pragma once
#include <SFML/Graphics.hpp>
#include "Window.h"
#include "ShapeFactory.h"

class BaseApp
{
public:
	BaseApp() = default;
	~BaseApp() = default;

  //Función encargada de correr la aplicación en main
  int 
    run();

  //Función de inicialización
  bool 
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
  sf::CircleShape* shape;
  ShapeFactory m_shapeFactory;
  sf::Shape* Triangulo;
};
