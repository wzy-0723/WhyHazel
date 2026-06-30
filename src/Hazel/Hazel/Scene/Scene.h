#pragma once

#include <entt/entt.hpp>


#include "Timestep.h"

namespace Hazel 
{
	class Entity;
	class Scene
	{
	public:
		Scene();
		~Scene();
		// TEMP
		Entity CreateEntity(const std::string& name = std::string());

		void OnUpdate(Timestep ts);
	private:
		entt::registry m_Registry;
		friend class Entity;
	};

}