#pragma once
#include "Prerequisites.h"
#include "Component.h"
#include "Window.h"

class Transform : public Component {
public:
  /**
   * @brief Constructor que inicializa posición, rotación y escala por defecto.
   */
  Transform() : position(0.0f, 0.0f),
    rotation(0.0f, 0.0f),
    scale(1.0f, 1.0f),
    Component(ComponentType::TRANSFORM) {}

  /**
   * @brief Destructor por defecto.
   */
  virtual
    ~Transform() = default;

  /**
   * @brief Actualiza al objeto Transform conforme al tiempo que haya pasado.
   * @param deltaTime Tiempo transcurrido desde la última actualización.
   */
  void
    update(float deltaTime) override {}

  /**
   * @brief Renderiza el objeto Transform.
   * @param window Ventana donde se renderizará el objeto.
   */
  void
    render(Window window) override {}

  /**
   * @brief Establece la posición del objeto.
   * @param _position Vector que contiene la nueva posición.
   */
  void
    setPosition(const sf::Vector2f& _position) {
    position = _position;
  }

  /**
   * @brief Establece la rotación del objeto.
   * @param _rotation Vector que contiene la nueva rotación.
   */
  void
    setRotation(const sf::Vector2f& _rotation) {
    rotation = _rotation;
  }

  /**
  * @brief Establece la escala del objeto.
  * @param _scale Vector que contiene la nueva escala.
  */
  void
    setScale(const sf::Vector2f& _scale) {
    scale = _scale;
  }

  /**
   * @brief Obtiene la posición del objeto.
   */
  sf::Vector2f&
    getPosition() {
    return position;
  }

  /**
   * @brief Obtiene la rotación del objeto.
   */
  sf::Vector2f&
    getRotation() {
    return rotation;
  }

  /**
   * @brief Obtiene la escala del objeto.
   */
  sf::Vector2f&
    getScale() {
    return scale;
  }

  void
    Seek(const sf::Vector2f& targetPosition,
      float speed,
      float deltaTime,
      float range) {
    sf::Vector2f direction = targetPosition - position;
    float length = std::sqrt(direction.x * direction.x + direction.y * direction.y);

    if (length > range) {
      direction /= length;  // Normaliza el vector
      position += direction * speed * deltaTime;
    }
  }

  /**
   * @brief Libera recursos y destruye al Transform.
   */
  void
    destroy();

private:
  sf::Vector2f position; // Posición del objeto
  sf::Vector2f rotation; // Rotacioón del objeto
  sf::Vector2f scale;	// Escala del objeto
};