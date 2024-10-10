#pragma once
#include "Prerequisites.h"
class Device;
class DeviceContext;

class Rasterizer
{
public:
  /*
   * @brief Constructor y destructor por defecto de la clase Rasterizer.
   */
  Rasterizer() = default;
  ~Rasterizer() = default;

  /*
  * @brief Inicializa el estado de rasterizaci�n.
  * @param device Puntero al dispositivo que se usar� para crear el estado de rasterizaci�n.
  */
  void
    init(ID3D11Device* device);

  /*
   * @brief Actualiza los par�metros del rasterizador.
   */
  void
    update();

  /*
  * @brief Renderiza utilizando la rasterizaci�n actual.
  * @param deviceContext Contexto del dispositivo para realizar las operaciones de renderizado.
  */
  void
    render(ID3D11DeviceContext* deviceContext);

  // Libera recursos y destruye al rasterizador
  void
    destroy();

private:
  ID3D11RasterizerState* m_rasterizerState = nullptr; // Estado de rasterizaci�n
};