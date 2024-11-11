#pragma once
#include "Prerequisites.h"
#include "Actor.h"
#include "Services/NotificationService.h"

class Window;

class
UserInterface {
public:

  /**
   * @brief Constructor por defecto de UserInterface.
   */
  UserInterface() = default;

  /**
   * @brief Destructor por defecto de UserInterface.
   */
  ~UserInterface() = default;

  /**
   * @brief Inicializa los elementos de la interfaz de usuario.
   */
  void
  init();

  /**
   * @brief Actualiza el estado de la interfaz de usuario.
   */
  void
  update();

  /**
   * @brief Renderiza la interfaz de usuario en la ventana.
   */
  void
  render();

  /**
   * @brief Libera los recursos utilizados por la interfaz de usuario.
   */
  void
  destroy();

  /**
   * @brief Configura el estilo visual de la interfaz de usuario.
   */
  void
  setupGUIStyle();

  /**
   * @brief Muestra mensajes en la consola de la interfaz.
   * @param programMessages Mapa de errores del programa con sus respectivos mensajes.
   */
  void
  console(std::map<ConsolErrorType, std::string> programMessages);

  /**
   * @brief Muestra los actores que hay en escena, dentro de la interfaz
   * @param actors Vector de actores para almacenar la jerarquía de actores en la escena
   */
  void
  hierarchy(std::vector<EngineUtilities::TSharedPointer<Actor>>& actors);

  /**
   * @brief Muestra el isnepctor del actor seleccionado
   */
  void
  inspector();

private:
  EngineUtilities::TSharedPointer<Actor> selectedActor;
};