#include "Entity.hpp"

Entity::Entity(entt::registry& p_Registry, entt::entity p_ID)
    : m_Registry(p_Registry), m_EntityID(p_ID) {}

template<typename T, typename... Args>
T& Entity::AddComponent(Args&&... p_Args)
{
    return m_Registry.emplace<T>(m_EntityID, std::forward<Args>(p_Args)...);
}

template<typename T>
T& Entity::GetComponent()
{
    return m_Registry.get<T>(m_EntityID);
}