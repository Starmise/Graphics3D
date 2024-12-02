#pragma once
#include "Prerequisites.h"
#include "Component.h"
#include "Window.h"

class
Transform : public Component {
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
  setPosition(const Vector2& _position) {
    position = _position;
  }

  /**
   * @brief Establece la rotación del objeto.
   * @param _rotation Vector que contiene la nueva rotación.
   */
  void
  setRotation(const Vector2& _rotation) {
    rotation = _rotation;
  }

  /**
  * @brief Establece la escala del objeto.
  * @param _scale Vector que contiene la nueva escala.
  */
  void
  setScale(const Vector2& _scale) {
    scale = _scale;
  }

  /**
   * @brief Obtiene la posición del objeto.
   */
  Vector2
  getPosition() {
    return position;
  }

  float*
  getPosData() {
    return &position.x;
  }

  /**
   * @brief Obtiene la rotación del objeto.
   */
  Vector2
  getRotation() {
    return rotation;
  }

  float*
  getRotData() {
    return &rotation.x;
  }

  /**
   * @brief Obtiene la escala del objeto.
   */
  Vector2
  getScale() {
    return scale;
  }

  float*
    getSclData() {
    return &scale.x;
  }

  void 
    setTransform(const Vector2& pos, const Vector2& rot, const Vector2& scl) {
    position = pos;
    rotation = rot;
    scale = scl;
  }


  /**
   * @brief Método que usa punta menos cola para seguir al cursor
   */
  void
  Seek(const Vector2& targetPosition,
      float speed,
      float deltaTime,
      float range) {
    Vector2 direction = (targetPosition) - position;
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
  Vector2 position; // Posición del objeto
  Vector2 rotation; // Rotación del objeto
  Vector2 scale;	// Escala del objeto
};