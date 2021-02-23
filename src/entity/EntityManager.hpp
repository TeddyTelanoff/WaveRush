#pragma once

#include <entt/entt.hpp>

#include "Entity.hpp"

class EntityManager
{
 private:
	entt::registry m_Registry;

 public:
	Entity CreateEntity();
};