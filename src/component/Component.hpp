#pragma once

#include <SDL.h>
#include "entity/EntityManager.hpp"

class Component
{
 public:
	 virtual ~Component() = default;

	virtual void ProcessEvents(SDL_Event &p_Event, Entity &p_Entity);

	virtual void ProcessUpdate(float p_DeltaTime, Entity &p_Entity);

	virtual void ProcessRender(SDL_Renderer *p_Renderer, Entity &p_Entity);
};
