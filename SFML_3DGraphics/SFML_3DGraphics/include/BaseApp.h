#pragma once
#include <SFML/Graphics.hpp>
#include "Window.h"
#include "ShapeFactory.h"
#include "Actor.h"

class 
  BaseApp {
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
  sf::Clock clock;
  sf::Time deltaTime;

  Window* m_window;
  EngineUtilities::TSharedPointer<Actor> Triangle;
  EngineUtilities::TSharedPointer<Actor> Circle;
};
