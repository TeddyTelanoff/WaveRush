#pragma once

#include <vector>
#include "system/System.hpp"

class SystemManager
{
 private:
	std::vector<System*> m_Systems;

 public:
	~SystemManager();

	void ProcessEvents(SDL_Event &p_Event, EntityManager &p_Manager);

	void ProcessUpdate(float p_DeltaTime, EntityManager &p_Manager);

	void ProcessRender(SDL_Renderer *p_Renderer, EntityManager &p_Manager);

	void RegisterSystem(System *p_System);
};