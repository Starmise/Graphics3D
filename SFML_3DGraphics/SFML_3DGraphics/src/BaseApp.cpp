#include "BaseApp.h"

BaseApp::~BaseApp()
{
  NotificationService::getInstance().saveMessagesToFile("LogData.txt");
}

/**
 * @brief  Método principal queinicializa el programa, gestiona eventos y renderiza actores.
 */
int
BaseApp::run() {
  NotificationService& notifier = NotificationService::getInstance();

  if (!initialize()) {
    notifier.addMessage(ConsolErrorType::ERROR, "Initializes result on a false statemente, check method validations");
    notifier.saveMessagesToFile("LogData.txt");
    ERROR("BaseApp", "run", "Initializes result on a false statemente, check method validations");
  }
  else {
    notifier.addMessage(ConsolErrorType::NORMAL, "All programs were initialized correctly");
  }
  m_GUI.init();

  while (m_window->isOpen()) {
    m_window->handleEvents();
    deltaTime = clock.restart();
    update();
    render();
  }

  cleanup();
  return 0;
}

/**
 * @brief Inicializa la ventana principal y configura los actores de la aplicación.
 */
bool
BaseApp::initialize() {
  NotificationService& notifier = NotificationService::getInstance();

  m_window = new Window(1280, 720, "Starmise Engine");
  if (!m_window) {
    notifier.addMessage(ConsolErrorType::ERROR, "Error on window creation, pointer is null");
    ERROR("BaseApp", "initialize", "Error on window creation, var is null");
    return false;
  }

  // Al iniciar el programa, establecer los 4 puntos de destino
  points[0] = sf::Vector2f(25.0f, 560.0f);
  points[1] = sf::Vector2f(25.0f, 20.0f);
  points[2] = sf::Vector2f(700.0f, 20.0f);
  points[3] = sf::Vector2f(700.0f, 200.0f);
  points[4] = sf::Vector2f(500.0f, 200.0f);
  points[5] = sf::Vector2f(500.0f, 120.0f);
  points[6] = sf::Vector2f(350.0f, 120.0f);
  points[7] = sf::Vector2f(350.0f, 340.0f);
  points[8] = sf::Vector2f(700.0f, 340.0f);
  /*shape = new sf::CircleShape(10.0f);

  if (!shape) {
    ERROR("BaseApp", "initialize", "Error on shape creation, var is null");
    return false;
  }*/

  // Track Actor
  Track = EngineUtilities::MakeShared<Actor>("Track");
  if (!Track.isNull()) {
    Track->getComponent<ShapeFactory>()->createShape(ShapeType::RECTANGLE);

    // Establecer posición, rotación y escala desde Transform
    Track->getComponent<Transform>()->setPosition(sf::Vector2f(0.0f, 0.0f));
    Track->getComponent<Transform>()->setRotation(sf::Vector2f(0.0f, 0.0f));
    Track->getComponent<Transform>()->setScale(sf::Vector2f(40.0f, 60.0f));

    if (!texture.loadFromFile("KartMap.png")) {
      notifier.addMessage(ConsolErrorType::WARNING, "Warning - Missing Texture from source bin");
      return -1;
    }
    Track->getComponent<ShapeFactory>()->getShape()->setTexture(&texture);
    m_actors.push_back(Track);
  }
  else {
    notifier.addMessage(ConsolErrorType::ERROR, "Error - Nullpointer Reference");
    notifier.addMessage(ConsolErrorType::WARNING, "Warning - Missing Texture from source bin");
  }

  //Circle Actor
  Circle = EngineUtilities::MakeShared<Actor>("Player");
  if (!Circle.isNull()) {
    Circle->getComponent<ShapeFactory>()->createShape(ShapeType::CIRCLE);

    Circle->getComponent<Transform>()->setPosition(sf::Vector2(650.0f, 560.0f));
    Circle->getComponent<Transform>()->setRotation(sf::Vector2(0.0f, 0.0f));
    Circle->getComponent<Transform>()->setScale(sf::Vector2(1.0f, 1.0f));

    if (!Rob.loadFromFile("tile011.png")) {
      notifier.addMessage(ConsolErrorType::WARNING, "Warning - Missing Texture from source bin");
      return -1;
    }
    Circle->getComponent<ShapeFactory>()->getShape()->setTexture(&Rob);
    m_actors.push_back(Circle);
  }

  // Triangle Actor
  Triangle = EngineUtilities::MakeShared<Actor>("Triangle");
  if (!Triangle.isNull()) {
    Triangle->getComponent<ShapeFactory>()->createShape(ShapeType::TRIANGLE);
    Triangle->getComponent<Transform>()->setPosition(sf::Vector2(150.0f, 200.0f));
    Triangle->getComponent<Transform>()->setRotation(sf::Vector2(0.0f, 0.0f));
    Triangle->getComponent<Transform>()->setScale(sf::Vector2(1.0f, 1.0f));
    m_actors.push_back(Triangle);
  }
  
  return true;
}

/**
 * @brief Actualiza el estado de la ventana y los actores en cada frame.
 */
void
BaseApp::update() {
  m_window->update();

  // Mouse Position
  sf::Vector2i mousePosition = sf::Mouse::getPosition(*m_window->getWindow());
  sf::Vector2f mousePosF(static_cast<float>(mousePosition.x),
    static_cast<float>(mousePosition.y));

  for (auto& actor : m_actors) {
    if (!actor.isNull()) {
      actor->update(m_window->deltaTime.asSeconds());
      if (actor->getName() == "Player") {
        updateMovement(m_window->deltaTime.asSeconds(), actor);
      }
    }
  }

  /*if (!triangle.isnull()) {
    triangle->update(m_window->deltatime.asseconds());
  }
  if (!circle.isnull()) {
    circle->update(m_window->deltatime.asseconds());
    updatemovement(m_window->deltatime.asseconds(), circle);
  }
  if (!track.isnull()) {
    track->update(m_window->deltatime.asseconds());
  }*/
}

/**
 * @brief Renderiza la ventana principal, los actores y la interfaz ImGui.
 */
void
BaseApp::render() {
  NotificationService& notifier = NotificationService::getInstance();

  m_window->clear();
  for (auto& actor : m_actors) {
    if (!actor.isNull()) {
      actor->render(*m_window);
    }
  }

  /*
  if (!Track.isNull()) {
    Track->render(*m_window);
  }
  if (!Circle.isNull()) {
    Circle->render(*m_window);
  }
  if (!Triangle.isNull()) {
    Triangle->render(*m_window);
  }
  }*/


  // Mostrar el render en ImGui
  m_window->renderToTexture();  // Finaliza el render a la textura
  m_window->showInImGui();      // Muestra la textura en ImGui

  // Configuramos la consola y le pasamos los mensajes
  m_GUI.console(notifier.getNotifications());

  // Mostramos la jerarquía de actorees
  m_GUI.hierarchy(m_actors);

  m_window->render();
  m_window->display();
}

/**
 * @brief  Libera recursos y cierra la ventana.
 */
void
BaseApp::cleanup() {
  m_window->destroy();
  delete m_window;
}

/**
 * @brief Actualiza el movimiento de un actor siguiendo los puntos de recorrido definidos.
 * @param deltaTime: Tiempo de delta para sincronizar el movimiento.
 * @param circle: Puntero compartido al actor "Circle".
 */
void
BaseApp::updateMovement(float deltaTime, EngineUtilities::TSharedPointer<Actor> circle) {
  // Verificar si el Circle es nulo
  if (!circle || circle.isNull()) return;

  // Obtener el componente Transform
  auto transform = circle->getComponent<Transform>();
  if (transform.isNull()) return;

  // Posición actual del destino (punto de recorrido)
  sf::Vector2f targetPos = points[m_currentPoint];

  // Llamar al Seek del Transform
  transform->Seek(targetPos, 200.0f, deltaTime, 10.0f);

  // Obtener la posición actual del actor desde Transform
  sf::Vector2f currentPos = transform->getPosition();

  // Comprobar si el actor ha alcanzado el destino (o está cerca)
  float distanceToTarget = std::sqrt(std::pow(targetPos.x - currentPos.x, 2) + std::pow(targetPos.y - currentPos.y, 2));

  if (distanceToTarget < 10.0f) { // Umbral para considerar que ha llegado
    m_currentPoint = (m_currentPoint + 1);
    if (m_currentPoint > 8) {
      m_currentPoint = 0;
    }
  }
}