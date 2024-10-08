#pragma once
#include "Prerequisites.h"
#include "Component.h"
#include "Window.h"

class Transform : public Component {
public:
  // Constructor que inicializa posición, rotación y escala por defecto
  Transform() : position(0.0f, 0.0f),
    rotation(0.0f, 0.0f),
    scale(1.0f, 1.0f),
    Component(ComponentType::TRANSFORM) {}

  virtual
    ~Transform() = default;

  // Actualiza al objeto Transform conforme al tiempo que haya pasado
  // @param deltaTime: Tiempo transcurrido desde la última actualización
  void
    update(float deltaTime) override {}

  // Renderiza el objeto de Transform
  // @param deviceContext: Contexto del dispositivo de renderizado
  void
    render(Window window) override {}

  // Libera recursos y destruye al Transform
  void
    destroy();

private:
  sf::Vector2f position; // Posición del objeto
  sf::Vector2f rotation; // Rotacioón del objeto
  sf::Vector2f scale;	// Escala del objeto
};