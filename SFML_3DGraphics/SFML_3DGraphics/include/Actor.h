#pragma once
#include "Prerequisites.h"
#include "Entity.h"
#include "ShapeFactory.h"
#include "Transform.h"

class
  Actor : Entity {
public:
  Actor() = default;

  Actor(std::string actorName);

  virtual
    ~Actor() = default;

  /*
  * @brief Actualiza al actor
  * @param deltaTime El tiempo transcurrrido desde la �ltima actualizaci�n
  */
  void
  update(float deltaTime) override;

  /*
  * @brief Renderiza al actor
  * @param window Contexto del dispositivo para operaciones gr�ficas
  */
  void
  render(Window& window) override;

  /**
   * @brief Destruye el actor y libera los recursos asociados.
   */
  void
  destroy();

  /**
   * @brief Funci�n para obtener �nicamente el nombre del actor
   */
  std::string
  getName() const;

  /*
  * @brief Obtiene un componente espec�fico del actor
  * @tparam T Tipo de componente que se va a obtener
  * @return Puntero compartido al componente, o nullptr si no se encuentra
  */
  template <typename T>
  EngineUtilities::TSharedPointer<T>
  getComponent();

private:
  std::string m_name = "Actor";
};

/*
  * El prop�sito de esta funci�n es buscar y devolver yn componente espec�fico de un
  * actor utilizando el tipo de componente espec�fico como argumentos de la plantilla.
  * Si el componente no se encuentra, la funci�n devuelve nullptr.
  */
template<typename T>
inline EngineUtilities::TSharedPointer<T>
Actor::getComponent() {
  for (auto& component : components) {
    EngineUtilities::TSharedPointer<T> specificComponent = component.template dynamic_pointer_cast<T>();
    if (specificComponent) {
      return specificComponent;
    }
  }
  // Devuelve un TSharedPointer vac�o si no se encuentra el componente
  return EngineUtilities::TSharedPointer<T>();
}