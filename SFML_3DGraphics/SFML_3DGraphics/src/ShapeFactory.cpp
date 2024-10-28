#include "ShapeFactory.h"

/**
 * @brief Crea una figura según el tipo especificado
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
 * @brief Establece la posición de la figura
 * @param position Vector que contiene la nueva posición de la figura
 */
void
ShapeFactory::setPosition(const sf::Vector2f& position) {
  if (m_shape) {
    m_shape->setPosition(position);
  }
}

/**
 * @brief Establece la rotación de la figura
 * @param angle Ángulo en grados para la rotación de la figura
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
ShapeFactory::setScale(const sf::Vector2f& scl) {
  if (m_shape) {
    m_shape->setScale(scl);
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

//void
//ShapeFactory::Seek(const sf::Vector2f& targetPosition,
//  float speed, float deltaTime, float range) {
//  // Obtener posición actual de mi shape
//  sf::Vector2f shapePosition = m_shape->getPosition();
//
//  // Calcular la dirección desde el circulo hacia el objetivo 
//  sf::Vector2f direction = targetPosition - shapePosition;
//
//  // Calcular la distancia al objetivo 
//  float lenght = std::sqrt(direction.x * direction.x + direction.y * direction.y);
//
//  // Si la distancia es mayor que el rango, mover shape hacia el objetivo
//  if (lenght > range) {
//    direction /= lenght;
//    m_shape->move(direction * speed * deltaTime);
//  }
//}