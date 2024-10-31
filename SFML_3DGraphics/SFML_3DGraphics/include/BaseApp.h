#pragma once
#include <SFML/Graphics.hpp>
#include "Window.h"
#include "ShapeFactory.h"
#include "Actor.h"
#include "UserInterface.h"

class
  BaseApp {
public:
  BaseApp() = default;
  ~BaseApp();

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

  void
    updateMovement(float deltaTime, EngineUtilities::TSharedPointer<Actor> circle);

private:
  sf::Clock clock;
  sf::Time deltaTime;

  Window* m_window;
  EngineUtilities::TSharedPointer<Actor> Triangle;
  EngineUtilities::TSharedPointer<Actor> Circle;
  EngineUtilities::TSharedPointer<Actor> Track;

  std::vector< EngineUtilities::TSharedPointer<Actor>> m_actors;

  //Array para la actividad de los 4 puntos
  sf::Vector2f points[9];
  int m_currentPoint = 0;

  sf::Texture texture;
  sf::Texture Rob;

  UserInterface m_GUI;
};
