#include "EntityManager.hpp"

Entity EntityManager::CreateEntity()
{
	entt::entity f_Id = m_Registry.create();

	return Entity(m_Registry, f_Id);
}

