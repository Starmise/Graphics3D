#pragma once
#include "Prerequisites.h"
#include "Component.h"
#include "Window.h"

class
ShapeFactory : public Component {
public:
  /**
   * @brief Constructor por defecto de ShapeFactory.
   */
  ShapeFactory() = default;

  /**
   * @brief Destructor virtual por defecto
   */
  virtual
  ~ShapeFactory() = default;

  /**
   * @brief Constructor que inicializa ShapeFactory con su correspondiente tipo de figura.
   * @param shapeType Tipo de figura que se va a manejar.
   */
  ShapeFactory(ShapeType shapeType) :
  m_shape(nullptr), m_ShapeType(ShapeType::EMPTY), Component(ComponentType::SHAPE) {}

  /**
   * @brief Crea una figura seg�n el tipo especificado.
   */
  sf::Shape*
  createShape(ShapeType shapeType);

  /**
   * @brief Actualiza el componente de malla.
   * @param deltaTime El tiempo transcurrido desde la �ltima actualizaci�n.
   */
  void
  update(float deltaTime) override {};

  /**
   * @brief Renderiza el componente de malla.
   * @param deviceContext Contexto del dispositivo para operaciones gr�ficas.
   */
  void
  render(Window window) override {};

  /**
   * @brief Establece la posici�n del componente
   * @param x posici�n en x del componente
   * @param y posici�n en y del componente
   */
  void
  setPosition(float x, float y);

  /**
   * @brief Obtiene la posici�n del componente
   */
  void
  setPosition(const Vector2& position);

  /**
   * @brief Colorea al componente con alg�n color
   * @param color Color del componente
   */
  void
  setFillColor(const sf::Color& color);

  /**
   * @brief Establece la rotaci�n del componente
   * @param angle �ngulo del componente
   */
  void
  setRotation(float angle);

  /**
   * @brief Establece la escala del componente
   * @param scl escala del componente
   */
  void
  setScale(const Vector2& scl);

  /**
   * @brief Obtiene la figura que fue creada
   */
  sf::Shape*
  getShape() {
    return m_shape;
  }

private:
  sf::Shape* m_shape;
  ShapeType m_ShapeType;
};