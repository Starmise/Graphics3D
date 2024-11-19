#pragma once
#include <SFML/Graphics.hpp>
#include "Window.h"
#include "ShapeFactory.h"
#include "Actor.h"
#include "UserInterface.h"
#include "Services/NotificationService.h"
#include "Services/ResourceManager.h"

class
  BaseApp {
public:
  /**
   * @brief Constructor por defecto
   */
  BaseApp() = default;

  /**
   * @brief Destructor de la clase BaseApp
   */
  ~BaseApp();

  /**
   * @brief Funci�n encargada de correr la aplicaci�n en el main
   * @return C�digo de salida de la aplicaci�n
   */
  int
  run();

  /**
   * @brief Funci�n de inicializaci�n de la aplicaci�n, configura los recursos necesarios
   * @return Verdadero si la inicializaci�n fue exitosa, falso si hubo un error
   */
  bool
  initialize();

  /**
   * @brief Funci�n que se actualiza por cada frame, procesando la l�gica del juego
   */
  void
  update();

  /**
   * @brief Funci�n de renderizado, dibuja los elementos en la ventana
   */
  void
  render();

  /**
   * @brief Limpia los recursos y elementos de la aplicaci�n antes de salir
   */
  void
  cleanup();

  /**
   * @brief Actualiza el movimiento de los actores (por ejemplo, el c�rculo)
   * @param deltaTime El tiempo transcurrido entre un frame y el siguiente
   * @param circle Puntero compartido al actor que representa el c�rculo
   */
  void
  updateMovement(float deltaTime, EngineUtilities::TSharedPointer<Actor> circle);

private:
  sf::Clock clock;
  sf::Time deltaTime;

  Window* m_window; // Puntero a la ventana donde se dibujan los elementos
  EngineUtilities::TSharedPointer<Actor> Triangle;
  EngineUtilities::TSharedPointer<Actor> Circle;
  EngineUtilities::TSharedPointer<Actor> Track;

  // Lista de actores en la escena
  std::vector< EngineUtilities::TSharedPointer<Actor>> m_actors;

  //Array para la actividad de los puntos
  sf::Vector2f points[9];
  int m_currentPoint = 0;
  int m_currentActor = 0;

  // Texturas para los elementos en escena
  sf::Texture texture;
  sf::Texture Rob;

  // Interfaz gr�fica de usuario
  UserInterface m_GUI;
};
