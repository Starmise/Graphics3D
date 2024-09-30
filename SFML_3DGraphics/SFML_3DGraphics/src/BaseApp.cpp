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
		Circle->getComponent<ShapeFactory>()->Seek(mousePosF, 200.0f, deltaTime.asSeconds(), 20.0f);
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