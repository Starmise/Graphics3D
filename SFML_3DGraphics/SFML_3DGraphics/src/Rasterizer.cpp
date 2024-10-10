#include "Rasterizer.h"

/*
 * @brief Inicializa el estado de rasterizaci�n en el dispositivo Direct3D 11.
 */
void
Rasterizer::init(ID3D11Device* device) {
  // Descripci�n del estado de rasterizaci�n.
  D3D11_RASTERIZER_DESC rasterizerDesc = {};
  rasterizerDesc.FillMode = D3D11_FILL_SOLID;
  rasterizerDesc.CullMode = D3D11_CULL_BACK;
  rasterizerDesc.FrontCounterClockwise = false;
  rasterizerDesc.DepthBias = 0;
  rasterizerDesc.SlopeScaledDepthBias = 0.0f;
  rasterizerDesc.DepthClipEnable = true;
  rasterizerDesc.ScissorEnable = false;
  rasterizerDesc.MultisampleEnable = false;
  rasterizerDesc.AntialiasedLineEnable = false;

  HRESULT hr = S_OK;


  // Crear el estado de rasterizaci�n con la descripci�n y la variable dada.
  hr = device->CreateRasterizerState(&rasterizerDesc, &m_rasterizerState);
  if (FAILED(hr)) {
    std::cout << "Error creating the Rasterizer State" << std::endl;
  }
}

void
Rasterizer::render(ID3D11DeviceContext* deviceContext) {
  deviceContext->RSSetState(m_rasterizerState);
}

void
Rasterizer::destroy() {
  if (m_rasterizerState) m_rasterizerState->Release();
}
