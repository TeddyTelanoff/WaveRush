#include "SystemManager.hpp"

SystemManager::~SystemManager()
{
	if (!m_Systems.empty())
	{
		for (System *f_System : m_Systems)
			delete f_System;
		m_Systems.clear();
	}
}

void SystemManager::RegisterSystem(System *p_System)
{
	m_Systems.emplace_back(p_System);
}

void SystemManager::ProcessEvents(SDL_Event &p_Event, EntityManager &p_Manager)
{
	if (m_Systems.empty())
		return;
	for (System *f_System : m_Systems)
		f_System->ProcessEvents(p_Event, p_Manager);
}

void SystemManager::ProcessUpdate(float p_DeltaTime, EntityManager &p_Manager)
{
	if (m_Systems.empty())
		return;
	for (System *f_System : m_Systems)
		f_System->ProcessUpdate(p_DeltaTime, p_Manager);
}

void SystemManager::ProcessRender(SDL_Renderer *p_Renderer, EntityManager &p_Manager)
{
	if (m_Systems.empty())
		return;
	for (System *f_System : m_Systems)
		f_System->ProcessRender(p_Renderer, p_Manager);
}