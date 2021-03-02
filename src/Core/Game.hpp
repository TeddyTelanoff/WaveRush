#pragma once

#include "Core/PCH.hpp"
#include "Scene/SceneManager.hpp"

struct WindowSettings
{
	std::string Title = "WaveRush";
	uint32_t Width = 1280;
	uint32_t Height = 720;
};

class Game
{
 private:
	SDL_Window* m_Window;
	SDL_Renderer* m_Renderer;
	SceneManager m_SceneManager;
	WindowSettings m_Settings;
	bool m_Running;

 private:
	Game();

	~Game();

 public:
	static Game& Instance();

	void Run(Scene *p_Scene);

	WindowSettings& GetSettings();

	SceneManager& GetSceneManager();

 private:
	void ProcessEvents(SDL_Event& p_Event);

	void ProcessUpdate(float p_DeltaTime);

	void ProcessRender(SDL_Renderer* p_Renderer);

 public:
	// Copy construct
	Game(Game const&) = delete;

	// Move construct
	Game(Game&&) = delete;

	// Copy assign
	Game& operator=(Game const&) = delete;

	// Move assign
	Game& operator=(Game&&) = delete;
};
