#pragma once

#include <SDL.h>
#include <entt/entt.hpp>

class Entity
{
private:
    entt::registry& m_Registry;
    entt::entity m_EntityID;

    Entity(entt::registry&, entt::entity p_ID);

    friend class EntityManager;
public:
    template<typename T, typename... Args>
    T& AddComponent(Args&&... p_Args)
    { return m_Registry.emplace<T>(m_EntityID, std::forward<Args>(p_Args)...); }

    template<typename T>
    T& GetComponent()
    { return m_Registry.get<T>(m_EntityID); }
};