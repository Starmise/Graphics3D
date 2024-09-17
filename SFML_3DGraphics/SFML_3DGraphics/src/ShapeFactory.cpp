#include "ShapeFactory.h"

sf::Shape* 
ShapeFactory::createShape(ShapeType shapeType)
{
	switch (shapeType)
	{
	case Circle: {
		sf::CircleShape* circle = new sf::CircleShape(20.0f);
		circle->setFillColor(sf::Color::Red);
		return circle;
	}
	case Rectangle: {
		sf::RectangleShape* rectangle = new sf::RectangleShape(sf::Vector2(20.0f, 10.0f));
		rectangle->setFillColor(sf::Color::Green);
		return rectangle;
	}
	case Triangle: {
		sf::CircleShape* triangle = new sf::CircleShape(25.0f, 3);
		triangle->setFillColor(sf::Color::Blue);
		return triangle;
	}
	default:
		return nullptr;
	}
}
