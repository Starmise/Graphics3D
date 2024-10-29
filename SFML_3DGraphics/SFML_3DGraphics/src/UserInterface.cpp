#include "UserInterface.h"
#include "Window.h"

void
UserInterface::init() {
  // Setup GUI Style
  setupGUIStyle();
}

void
UserInterface::update() {
}

void
UserInterface::render() {
}

void
UserInterface::destroy() {
}

void
UserInterface::setupGUIStyle() {
  ImGuiStyle& style = ImGui::GetStyle();

  // Ajuste de bordes
  style.WindowBorderSize = 2.0f;
  style.FrameBorderSize = 2.0f;
  style.WindowRounding = 4.0f;
  style.FrameRounding = 4.0f;
  style.ScrollbarRounding = 3.0f;
  style.GrabRounding = 3.0f;

  // Color amarillo principal
  ImVec4 yellow = ImVec4(0.85f, 0.65f, 0.0f, 1.00f);       // Amarillo principal
  ImVec4 yellowHover = ImVec4(0.95f, 0.75f, 0.1f, 1.00f);  // Amarillo al hacer hover
  ImVec4 yellowActive = ImVec4(1.00f, 0.85f, 0.2f, 1.00f); // Amarillo al hacer clic

  // Color azul oscuro para el título
  ImVec4 darkBlue = ImVec4(0.1f, 0.1f, 0.3f, 1.00f);       // Azul oscuro para el título
  ImVec4 darkBlueActive = ImVec4(0.15f, 0.15f, 0.35f, 1.00f); // Azul oscuro activo

  ImVec4* colors = style.Colors;

  // Fondo oscuro
  colors[ImGuiCol_WindowBg] = ImVec4(0.08f, 0.12f, 0.1f, 1.00f);

  // Títulos con azul oscuro
  colors[ImGuiCol_TitleBg] = darkBlue;
  colors[ImGuiCol_TitleBgActive] = darkBlueActive;
  colors[ImGuiCol_TitleBgCollapsed] = ImVec4(0.07f, 0.07f, 0.25f, 1.00f); // Azul oscuro colapsado

  // Bordes amarillos
  colors[ImGuiCol_Border] = yellow;

  // Elementos interactivos
  colors[ImGuiCol_FrameBg] = ImVec4(0.15f, 0.15f, 0.2f, 1.00f);
  colors[ImGuiCol_FrameBgHovered] = yellowHover;
  colors[ImGuiCol_FrameBgActive] = yellowActive;

  // Botones
  colors[ImGuiCol_Button] = yellow;
  colors[ImGuiCol_ButtonHovered] = yellowHover;
  colors[ImGuiCol_ButtonActive] = yellowActive;

  // Checkboxes y sliders
  colors[ImGuiCol_CheckMark] = yellow;
  colors[ImGuiCol_SliderGrab] = yellow;
  colors[ImGuiCol_SliderGrabActive] = yellowHover;

  // Headers
  colors[ImGuiCol_Header] = yellow;
  colors[ImGuiCol_HeaderHovered] = yellowHover;
  colors[ImGuiCol_HeaderActive] = yellowActive;

  // Líneas de gráficos
  colors[ImGuiCol_PlotLines] = yellow;
  colors[ImGuiCol_PlotHistogram] = yellow;

  // Textos
  colors[ImGuiCol_Text] = ImVec4(0.90f, 0.90f, 0.90f, 1.00f); // Texto claro
}

void
UserInterface::console(std::map<ConsolErrorType, std::string> programMessages) {
  ImGui::Begin("Console");
  for (const auto& pair : programMessages) {
    ImGui::Text("Code: %d - Message: %s", pair.first, pair.second.c_str());
  }
  ImGui::End();

}