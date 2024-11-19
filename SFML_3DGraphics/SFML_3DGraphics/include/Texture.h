#pragma once
#include "Prerequisites.h"
#include "Component.h"

class 
Texture : public Component {
public:
  /**
   * @brief Constructor por defecto de Texture.
   */
  Texture() = default;

  /**
    *@brief Constructor que carga una textura desde un archivo.
    * @param textureName Nombre del archivo de la textura
    * @param extension Extensi�n del archivo de la texturaa
   */
  Texture(std::string textureName, std::string extension) : m_textureName(textureName),
    m_extension(extension),
    Component(ComponentType::TEXTURE) {
    if (!m_texture.loadFromFile(m_textureName + "." + m_extension)) {
      std::cout << "Error de carga de textura" << std::endl;
    /*}
    else {
      m_textureName = "Default";
      m_extension = "png";
      if (!m_texture.loadFromFile(m_textureName + "." + m_extension)) {
        std::cout << "Error de carga de textura" << std::endl;
      }*/
    }
  }

  /**
   * @brief Destructor por defecto de Texture.
   */
  virtual
  ~Texture() = default;

  /**
   * @brief M�todo para obtener la textura de Texture.
   */
  sf::Texture& 
  getTexture() {
    return m_texture;
  }

  /*
  * @brief M�todo puro para actualizar la textura
  * @param deltaTime Tiempo transcurrido desde la �ltima actualizaci�n
  */
  void 
  update(float deltaTime) override {
  }

  /*
  * @brief M�todo puro para renderizar la textura
  * @param Window Contexto del dispositivo para operaciones gr�ficas
  */
  void 
  render(Window window) override {
  }

private:
  std::string m_textureName; // Nombre del archivo de la textura
  std::string m_extension; // Extensi�n del archivo de la texturaa
  sf::Texture m_texture; // La textura mediante SFML
};