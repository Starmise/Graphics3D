#include "UserInterface.h"
#include "Window.h"

/**
 * @brief Configura el estilo y la apariencia de la interfaz gráfica.
 */
void
UserInterface::init() {
  // Setup GUI Style
  setupGUIStyle();
}

/**
 * @brief Actualiza la interfaz de usuario.
 */
void
UserInterface::update() {
}

/**
 * @brief Renderiza los elementos visuales de la UI en pantalla.
 */
void
UserInterface::render() {
}

/**
 * @brief Libera los recursos de la interfaz de usuario.
 */
void
UserInterface::destroy() {
}

/**
 * @brief Configura el estilo y los colores de la GUI mediante ImGUI
 */
void UserInterface::setupGUIStyle() {
  ImGuiStyle& style = ImGui::GetStyle();

  // Ajuste de bordes
  style.WindowBorderSize = 2.0f;
  style.FrameBorderSize = 2.0f;
  style.WindowRounding = 4.0f;
  style.FrameRounding = 4.0f;
  style.ScrollbarRounding = 3.0f;
  style.GrabRounding = 3.0f;

  // Colores con mayor contraste
  ImVec4 yellow = ImVec4(0.95f, 0.75f, 0.05f, 1.00f);       // Amarillo principal con más brillo
  ImVec4 yellowHover = ImVec4(1.00f, 0.7f, 0.15f, 1.00f);   // Amarillo más oscuro al hacer hover
  ImVec4 yellowActive = ImVec4(1.00f, 0.5f, 0.1f, 1.00f);   // Amarillo tirando a naranja al hacer clic

  ImVec4 darkBlue = ImVec4(0.05f, 0.05f, 0.2f, 1.00f);        // Azul oscuro más profundo para el título
  ImVec4 darkBlueActive = ImVec4(0.1f, 0.1f, 0.3f, 1.00f);    // Azul más brillante al estar activo

  ImVec4* colors = style.Colors;

  // Fondo de la ventana más oscuro
  colors[ImGuiCol_WindowBg] = ImVec4(0.05f, 0.08f, 0.08f, 1.00f);

  // Títulos con azul oscuro
  colors[ImGuiCol_TitleBg] = darkBlue;
  colors[ImGuiCol_TitleBgActive] = darkBlueActive;
  colors[ImGuiCol_TitleBgCollapsed] = ImVec4(0.04f, 0.04f, 0.2f, 1.00f);

  // Bordes con amarillo más brillante
  colors[ImGuiCol_Border] = yellow;

  // Elementos interactivos con mayor contraste
  colors[ImGuiCol_FrameBg] = ImVec4(0.12f, 0.12f, 0.15f, 1.00f);
  colors[ImGuiCol_FrameBgHovered] = yellowHover;
  colors[ImGuiCol_FrameBgActive] = yellowActive;

  // Botones
  colors[ImGuiCol_Button] = ImVec4(0.2f, 0.2f, 0.2f, 1.00f);  // Fondo más oscuro para resaltar el amarillo al pasar hover
  colors[ImGuiCol_ButtonHovered] = yellowHover;
  colors[ImGuiCol_ButtonActive] = yellowActive;

  // Checkboxes y sliders
  colors[ImGuiCol_CheckMark] = yellow;
  colors[ImGuiCol_SliderGrab] = yellow;
  colors[ImGuiCol_SliderGrabActive] = yellowHover;

  // Headers
  colors[ImGuiCol_Header] = darkBlue;
  colors[ImGuiCol_HeaderHovered] = ImVec4(0.0f, 0.45f, 0.65f, 1.0f); // Azul más claro
  colors[ImGuiCol_HeaderActive] = darkBlueActive;

  // Líneas de gráficos
  colors[ImGuiCol_PlotLines] = yellow;
  colors[ImGuiCol_PlotHistogram] = yellow;

  // Textos
  colors[ImGuiCol_Text] = ImVec4(0.95f, 0.95f, 0.95f, 1.00f);  // Texto más claro para mejor visibilidad
}

/**
 * @brief Muestra una consola en la interfaz de usuario.
 * @param programMessages Mapa que asocia códigos de error con sus mensajes
 */
void
UserInterface::console(std::map<ConsolErrorType, std::string> programMessages) {
  ImGui::Begin("Console");
  for (const auto& pair : programMessages) {
    ImGui::Text("Code: %d - Message: %s", pair.first, pair.second.c_str());
  }
  ImGui::End();

}

void
UserInterface::hierarchy(std::vector<EngineUtilities::TSharedPointer<Actor>> actors) {
  ImGui::Begin("Hierarchy");

  for (auto& actor : actors) {
    if (actor.isNull()) continue;

    // Muestra el nombre del actor y permite seleccionarlo
    if (ImGui::Selectable(actor->getName().c_str(), selectedActor == actor)) {
      selectedActor = actor; // Al hacer clic, se selecciona el actor para el inspector
    }
  }

  ImGui::Separator();
  ImGui::Spacing();

  // Botón 1
  if (ImGui::Button("Create Circle")) {
    // Lógica a implementar si el botón 1 es seleccionado
  }

  // Botón 2
  if (ImGui::Button("Create Rectangle")) {
    // Lógica a implementar si el botón 2 es seleccionado
  }

  // Botón 3
  if (ImGui::Button("Create Triangle")) {
    // Lógica a implementar si el botón 3 es seleccionado
  }

  ImGui::End();

  // Llama al inspector para mostrar las propiedades del actor seleccionado
  inspector();
}

/**
   * @brief Verifica si hay un actor seleccionado y, muestra las propiedades de transform
   */
void
UserInterface::inspector() {
  if (selectedActor.isNull()) {
    return;
  }

  ImGui::Begin("Inspector");

  // Obtiene el componente Transform del actor
  auto transform = selectedActor->getComponent<Transform>();
  if (!transform.isNull()) {
    sf::Vector2f position = transform->getPosition();
    sf::Vector2f rotation = transform->getRotation();
    sf::Vector2f scale = transform->getScale();

    // Posición
    if (ImGui::DragFloat2("Position", &position.x, 0.1f)) {
      transform->setPosition(position);
    }

    // Rotación
    if (ImGui::DragFloat2("Rotation", &rotation.x, 0.1f)) {
      transform->setRotation(rotation);
    }

    // Escala
    if (ImGui::DragFloat2("Scale", &scale.x, 0.1f)) {
      transform->setScale(scale);
    }
  }

  ImGui::End();
}
