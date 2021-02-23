#pragma once

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
    T& AddComponent(Args&&... args);

    template<typename T>
    T& GetComponent();
};