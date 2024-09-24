#pragma once
#include "Prerequisites.h"
#include "Component.h"
#include "Window.h"

class 
	ShapeFactory : public Component {
public:
	ShapeFactory() = default;

	virtual
	~ShapeFactory() = default;

	ShapeFactory(ShapeType shapeType) : 
		m_shape(nullptr), m_ShapeType(ShapeType::EMPTY), Component(ComponentType::SHAPE) {}
	
	sf::Shape*
		createShape(ShapeType shapeType);

	void
		update(float deltaTime) override {};

	void
		render(Window window) override {};

	void
		setPosition(float x, float y);

	void
		setPosition(const sf::Vector2f& position);

	void
		setFillColor(const sf::Color& color);

	void
		Seek(const sf::Vector2f& targetPosition, float speed, float deltaTime, float range);

	sf::Shape* 
		getShape() {
		return m_shape;
	}

private:
	sf::Shape* m_shape;
	ShapeType m_ShapeType;
};