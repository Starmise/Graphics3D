#pragma once
#include "Prerequisites.h"

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
  void init();

  /**
   * @brief Actualiza el estado de la interfaz de usuario.
   */
  void update();

  /**
   * @brief Renderiza la interfaz de usuario en la ventana.
   */
  void render();

  /**
   * @brief Libera los recursos utilizados por la interfaz de usuario.
   */
  void destroy();

  /**
   * @brief Configura el estilo visual de la interfaz de usuario.
   */
  void setupGUIStyle();

  /**
   * @brief Muestra mensajes en la consola de la interfaz.
   * @param programMessages Mapa de errores del programa con sus respectivos mensajes.
   */
  void console(std::map<ConsolErrorType, std::string> programMessages);

private:

};