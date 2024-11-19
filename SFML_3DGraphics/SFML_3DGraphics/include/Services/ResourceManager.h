#pragma once
#include "Prerequisites.h"
#include "Texture.h"
#include "Services/NotificationService.h"

class 
ResourceManager {
private:
	ResourceManager() = default;
	~ResourceManager() = default;

	// Deshabilitar el copiado y la asignación
	ResourceManager(const ResourceManager&) = delete; // Copiado
	ResourceManager& operator=(const ResourceManager&) = delete; // Asignación

public:
	static ResourceManager& getInstance() {
		static ResourceManager instance;
		return instance;
	}

	bool
	loadTexture(const std::string& fileName, const std::string& extension) {
		// Verificar que la textura haya cargado
		if (m_textures.find(fileName) != m_textures.end()) {
			return true;
		}
		EngineUtilities::TSharedPointer<Texture> texture = EngineUtilities::MakeShared<Texture>(fileName, extension);
		m_textures[fileName] = texture;
	}

	EngineUtilities::TSharedPointer<Texture>
	getTexture(const std::string& fileName) {
		NotificationService& notifier = NotificationService::getInstance();

		// Verificar que haya una textura xon ese nombre
		auto it = m_textures.find(fileName);
		if (it != m_textures.end()) {
			return it->second; 
		}

		std::cout << "Texture not found: " << fileName << std::endl;
		notifier.addMessage(ConsolErrorType::WARNING, "Texture not found: " + fileName);
		EngineUtilities::TSharedPointer<Texture> texture = EngineUtilities::MakeShared<Texture>("Default", "png");
		m_textures["Default"] = texture;
		return texture;
	}

private:
	std::unordered_map<std::string, EngineUtilities::TSharedPointer<Texture>> m_textures;
};