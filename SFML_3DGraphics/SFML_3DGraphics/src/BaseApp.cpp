#include "BaseApp.h"
#include "Services/NotificationService.h"

BaseApp::~BaseApp()
{
  NotificationService& notifier = NotificationService::getInstance();
  notifier.saveMessagesToFile("LogData.txt");
}

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

bool
BaseApp::initialize() {
  NotificationService& notifier = NotificationService::getInstance();

  m_window = new Window(800, 600, "Starmise Engine");
  if (!m_window) {
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

  //Circle Actor
  Circle = EngineUtilities::MakeShared<Actor>("Circle");
  if (!Circle.isNull()) {
    Circle->getComponent<ShapeFactory>()->createShape(ShapeType::CIRCLE);

    Circle->getComponent<Transform>()->setPosition(sf::Vector2(650.0f, 560.0f));
    Circle->getComponent<Transform>()->setRotation(sf::Vector2(0.0f, 0.0f));
    Circle->getComponent<Transform>()->setScale(sf::Vector2(1.0f, 1.0f));

    if (!Rob.loadFromFile("tile011.png")) {
      std::cout << "Error de carga de textura" << std::endl;
      return -1;
    }
    Circle->getComponent<ShapeFactory>()->getShape()->setTexture(&Rob);
  }

  // Triangle Actor
  Triangle = EngineUtilities::MakeShared<Actor>("Triangle");
  if (!Triangle.isNull()) {
    Triangle->getComponent<ShapeFactory>()->createShape(ShapeType::TRIANGLE);
    Triangle->getComponent<Transform>()->setPosition(sf::Vector2(150.0f, 200.0f));
    Triangle->getComponent<Transform>()->setRotation(sf::Vector2(0.0f, 0.0f));
    Triangle->getComponent<Transform>()->setScale(sf::Vector2(1.0f, 1.0f));
  }

  // Track Actor
  Track = EngineUtilities::MakeShared<Actor>("Track");
  if (!Track.isNull()) {
    notifier.addMessage(ConsolErrorType::ERROR, "Error - Nullpointer Reference");
    notifier.addMessage(ConsolErrorType::WARNING, "Warning - Missing Texture from source bin");

    Track->getComponent<ShapeFactory>()->createShape(ShapeType::RECTANGLE);

    // Establecer posición, rotación y escala desde Transform
    Track->getComponent<Transform>()->setPosition(sf::Vector2f(0.0f, 0.0f));
    Track->getComponent<Transform>()->setRotation(sf::Vector2f(0.0f, 0.0f));
    Track->getComponent<Transform>()->setScale(sf::Vector2f(40.0f, 60.0f));

    if (!texture.loadFromFile("KartMap.png")) {
      std::cout << "Error de carga de textura" << std::endl;
      return -1;
    }
    Track->getComponent<ShapeFactory>()->getShape()->setTexture(&texture);
  }

  return true;
}

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
      if (actor->getName() == "Circle") {
        updateMovement(m_window->deltaTime.asSeconds(), actor);
      }
    }
  }

  /*if (!Triangle.isNull()) {
    Triangle->update(m_window->deltaTime.asSeconds());
  }
  if (!Circle.isNull()) {
    Circle->update(m_window->deltaTime.asSeconds());
    updateMovement(m_window->deltaTime.asSeconds(), Circle);
  }
  if (!Track.isNull()) {
    Track->update(m_window->deltaTime.asSeconds());
  }*/
}

void
BaseApp::render() {
  NotificationService& notifier = NotificationService::getInstance();

  m_window->clear();
  for (auto& actor : m_actors) {
    if (!actor.isNull()) {
      actor->render(*m_window);
    }
  }

  /*m_window->clear();
  if (!Track.isNull()) {
    Track->render(*m_window);
  }
  if (!Circle.isNull()) {
    Circle->render(*m_window);
  }
  if (!Triangle.isNull()) {
    Triangle->render(*m_window);
  }*/

  // Arreglo temporal de Transforms para los objetos en la jerarquía
  static Transform transforms[4]; // Supongamos que hay 5 objetos en la jerarquía

  // **ImGui: Cyberpunk Panel**
  ImGui::SetNextWindowPos(ImVec2(10, 10), ImGuiCond_FirstUseEver);
  ImGui::SetNextWindowSize(ImVec2(300, 400), ImGuiCond_FirstUseEver);
  ImGui::Begin("Cyberpunk Panel");
  ImGui::Text("Welcome World!");

  // **Hierarchy Window**
  ImGui::Begin("Hierarchy");

  // List of objects in the hierarchy (Camera, Light, Player, etc.)
  static const char* items[] = { "Camera", "Light", "Player", "Enemy" };
  static int selected = -1; // Index of the selected item

  // Display the list of objects
  for (int i = 0; i < IM_ARRAYSIZE(items); i++) {
    // Create a unique identifier for each item
    char label[128];
    sprintf(label, "%s##%d", items[i], i);

    // Show the item as selectable
    if (ImGui::Selectable(label, selected == i)) {
      selected = i; // Update the selected item
    }
  }

  ImGui::End(); // End of the Hierarchy window

  // **Inspector Window**
  ImGui::Begin("Inspector");

  if (selected != -1) {
    // Access the Transform for the selected object
    Transform& transform = transforms[selected];

    // Display and allow editing of the Transform properties
    sf::Vector2f& position = transform.getPosition();
    ImGui::DragFloat2("Position", &position.x, 0.1f); // Edit position

    sf::Vector2f& rotation = transform.getRotation();
    ImGui::DragFloat2("Rotation", &rotation.x, 0.1f); // Edit rotation

    sf::Vector2f& scale = transform.getScale();
    ImGui::DragFloat2("Scale", &scale.x, 0.1f); // Edit scale
  }
  else {
    ImGui::Text("Select an item from the hierarchy.");
  }

  ImGui::End(); // End of the Inspector window

  // Accept button
  if (ImGui::Button("Accept")) {
    // Action on button press
  }

  // Mostrar el render en ImGui
  m_window->renderToTexture();  // Finaliza el render a la textura
  m_window->showInImGui();      // Muestra la textura en ImGui

  ImGui::End(); // End of the Cyberpunk Panel

  m_GUI.console(notifier.getNotifications());
  m_window->render();
  m_window->display();
}

void
BaseApp::cleanup() {
  m_window->destroy();
  delete m_window;
}

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