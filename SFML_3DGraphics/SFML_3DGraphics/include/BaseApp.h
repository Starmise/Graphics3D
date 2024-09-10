#pragma once
#include <SFML/Graphics.hpp>
#include "Window.h"

class BaseApp
{
public:
	BaseApp() = default;
	~BaseApp() = default;

  //Funci�n encargada de correr la aplicaci�n en main
  int 
    run();

  //Funci�n de inicializaci�n
  void 
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
  Window* m_window;
  //sf::RenderWindow* window;
  sf::CircleShape* shape;
};
