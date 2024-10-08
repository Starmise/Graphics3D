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

  //Funci�n encargada de correr la aplicaci�n en main
  int 
    run();

  //Funci�n de inicializaci�n
  bool 
    initialize();

  //Funci�n que se actualiza por frame 
  void 
    update();

  //Funci�n de renderizado
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

  //Array para la actividad de los 4 puntos
  sf::Vector2f points[4];
  int m_currentPoint = 0;
};
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

  //Funci�n encargada de correr la aplicaci�n en main
  int 
    run();

  //Funci�n de inicializaci�n
  bool 
    initialize();

  //Funci�n que se actualiza por frame 
  void 
    update();

  //Funci�n de renderizado
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

  //Array para la actividad de los 4 puntos
  sf::Vector2f points[4];
  int m_currentPoint = 0;
};
