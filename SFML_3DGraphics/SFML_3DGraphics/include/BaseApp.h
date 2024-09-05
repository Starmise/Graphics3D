#pragma once
#include <SFML/Graphics.hpp>

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

  //Función de manejo de datos
  void 
    handleEvents();

  //Función que se actualiza por frame 
  void 
    update();

  //Función de renderizado
  void 
    render();

  void 
    cleanup();

private:
  sf::RenderWindow* window;
  sf::CircleShape* shape;
};
