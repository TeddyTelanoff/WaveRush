#include "Entity.hpp"

#include "component/Component.hpp"

Entity::Entity(entt::registry& p_Registry, entt::entity p_ID)
    : m_Registry(p_Registry), m_EntityID(p_ID) {}