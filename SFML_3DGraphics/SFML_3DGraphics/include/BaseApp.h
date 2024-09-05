#pragma once
#include <SFML/Graphics.hpp>

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

  //Funci�n de manejo de datos
  void 
    handleEvents();

  //Funci�n que se actualiza por frame 
  void 
    update();

  //Funci�n de renderizado
  void 
    render();

  void 
    cleanup();

private:
  sf::RenderWindow* window;
  sf::CircleShape* shape;
};
