#include "ShapeFactory.h"

/**
 * @brief Crea una figura seg�n el tipo especificado
 * @param shapeType Tipo de figura a crear (CIRCLE, RECTANGLE, TRIANGLE, etc.)
 * @return Puntero a la figura creada
 */
sf::Shape*
ShapeFactory::createShape(ShapeType shapeType) {
  m_ShapeType = shapeType;
  switch (shapeType)
  {
  case NONE: {
    return nullptr;
  }
  case CIRCLE: {
    sf::CircleShape* circle = new sf::CircleShape(20.0f);
    m_shape = circle;
    return circle;
  }
  case RECTANGLE: {
    sf::RectangleShape* rectangle = new sf::RectangleShape(sf::Vector2(20.0f, 10.0f));
    m_shape = rectangle;
    return rectangle;
  }
  case TRIANGLE: {
    sf::CircleShape* triangle = new sf::CircleShape(25.0f, 3);
    //triangle->setFillColor(sf::Color::White);
    m_shape = triangle;
    return triangle;
  }
  default:
    return nullptr;
  }
}

void
ShapeFactory::setPosition(float x, float y) {
  if (m_shape) {
    m_shape->setPosition(x, y);
  }
}

/**
 * @brief Establece la posici�n de la figura
 * @param position Vector que contiene la nueva posici�n de la figura
 */
void
ShapeFactory::setPosition(const Vector2& position) {
  if (m_shape) {
    m_shape->setPosition(position.x, position.y);
  }
}

/**
 * @brief Establece la rotaci�n de la figura
 * @param angle �ngulo en grados para la rotaci�n de la figura
 */
void
ShapeFactory::setRotation(float angle) {
  if (m_shape) {
    m_shape->setRotation(angle);
  }
}

/**
 * @brief Establece la escala de la figura
 * @param scl Vector que contiene la escala en los ejes X e Y
 */
void
ShapeFactory::setScale(const Vector2& scl) {
  if (m_shape) {
    m_shape->setScale(scl.x, scl.y);
  }
}

/**
 * @brief Establece el color de relleno de la figura
 * @param color Color de relleno a aplicar a la figura
 */
void
ShapeFactory::setFillColor(const sf::Color& color) {
  m_shape->setFillColor(color);
}