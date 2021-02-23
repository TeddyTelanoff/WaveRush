#pragma once

#include "system/System.hpp"

class PlayerMovementSystem : public System
{
 private:
	float m_DeltaTime;

 public:
	void ProcessEvents(SDL_Event *p_Event, entt::registry &p_Registry) override;

	void ProcessUpdate(float f_Tag, entt::registry& f_Position) override;
};