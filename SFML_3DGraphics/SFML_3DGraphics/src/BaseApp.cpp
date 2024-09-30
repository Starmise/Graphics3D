#include "BaseApp.h"

int
BaseApp::run() {
	if (!initialize()) {
		ERROR("BaseApp", "run", "Initializes result on a false statemente, check method validations");
	}
	while (m_window->isOpen()) {
		m_window->handleEvents();
		deltaTime = clock.restart();
		update();
		render();
	}

	cleanup();
	return 0;
}

bool
BaseApp::initialize() {
	m_window = new Window(800, 600, "Starmise Engine");
	if (!m_window) {
		ERROR("BaseApp", "initialize", "Error on window creation, var is null");
		return false;
	}

	// Al iniciar el programa, establecer los 4 puntos de destino
	points[0] = sf::Vector2f(100.0f, 100.0f);
	points[1] = sf::Vector2f(600.0f, 200.0f);
	points[2] = sf::Vector2f(100.0f, 400.0f);
	points[3] = sf::Vector2f(600.0f, 500.0f);
	/*shape = new sf::CircleShape(10.0f);

	if (!shape) {
		ERROR("BaseApp", "initialize", "Error on shape creation, var is null");
		return false;
	}*/

	//Circle Actor
	Circle = EngineUtilities::MakeShared<Actor>("Circle");
	if (!Circle.isNull()) {
		Circle->getComponent<ShapeFactory>()->createShape(ShapeType::CIRCLE); 
		Circle->getComponent<ShapeFactory>()->setPosition(208.0f, 200.0f); 
		Circle->getComponent<ShapeFactory>()->setFillColor(sf::Color::Magenta);
	}

	// Triangle Actor
	Triangle = EngineUtilities::MakeShared<Actor>("Triangle");
	if (!Triangle.isNull()) {
		Triangle->getComponent<ShapeFactory>()->createShape(ShapeType::TRIANGLE);
	}

	return true;
}

void
BaseApp::update() {
	sf::Vector2i mousePosition = sf::Mouse::getPosition(*m_window->getWindow());
	sf::Vector2f mousePosF(static_cast<float>(mousePosition.x), 
												 static_cast<float>(mousePosition.y));

	if (!Circle.isNull()) {
		// Hacer que el círculo siga al mouse
		// Circle->getComponent<ShapeFactory>()->Seek(mousePosF, 200.0f, deltaTime.asSeconds(), 20.0f);
	
		// Obtener el punto actual al que debe ir el círculo
		sf::Vector2f targetPoint = points[m_currentPoint];

		// Usar Seek para mover el círculo hacia el punto actual
		Circle->getComponent<ShapeFactory>()->Seek(targetPoint, 200.0f, deltaTime.asSeconds(), 10.0f);

		// Comprobar si el círculo ha alcanzado el punto actual
		sf::Vector2f circlePosition = Circle->getComponent<ShapeFactory>()->getShape()->getPosition();

		// Calcular distancia entre el actor y el punto actual
		float distance = std::sqrt(std::pow(circlePosition.x - targetPoint.x, 2) + std::pow(circlePosition.y - targetPoint.y, 2));

		// Pasar al siguiente punto si está suficientemente cerca
		if (distance < 10.0f) {  
			m_currentPoint = (m_currentPoint + 1);
			if (m_currentPoint > 3) {
				m_currentPoint = 0;
			}
		}
	}
}

void
BaseApp::render() {
	m_window->clear();
	Circle->render(*m_window);
	Triangle->render(*m_window);
	m_window->display();
}

void
BaseApp::cleanup() {
	m_window->destroy();
	delete m_window;
}