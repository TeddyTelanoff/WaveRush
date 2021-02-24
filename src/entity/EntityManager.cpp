#include "EntityManager.hpp"

#include <SDL.h>
#include "core/Game.hpp"
#include "core/Utils.hpp"
#include "component/VelocityLevelComponent.hpp"
#include "component/TagComponent.hpp"
#include "component/RectangleShapeComponent.hpp"
#include "component/PositionComponent.hpp"
#include "component/VelocityComponent.hpp"
#include "component/ParticleSystemComponent.hpp"

entt::registry& EntityManager::GetRegistry()
{
	return m_Registry;
}

entt::entity EntityManager::CreateEntity()
{
	return m_Registry.create();
}

void EntityManager::SpawnPlayer(int32_t p_Amount)
{
	if (p_Amount <= 0)
		return;
	for (size_t i = 0; i < p_Amount; ++i)
	{
		auto f_Player = CreateEntity();

		// This make sure the entity we are creating is going to be a f_Player
		m_Registry.emplace<TagComponent>(f_Player, TagType::Player);

		// This make sure it gets displayed on the screen
		SDL_Color f_Color = { 0, 255, 0, 255 };
		glm::vec2 f_Size = { 50, 50 };
		SDL_Color f_OutlineColor = { 0, 0, 0, 255 };
		int32_t f_OutlineThickness = 5;
		m_Registry.emplace<RectangleShapeComponent>(f_Player, f_Color, f_Size, f_OutlineColor, f_OutlineThickness);

		// This allows us to know where the f_Player is
		m_Registry.emplace<PositionComponent>(f_Player, glm::vec2((float)(Game::Instance().GetSettings().Width / 2.0f), (float)(
			Game::Instance().GetSettings().Height / 2.0f)));

		// This allows us to determine how fast the will move
		m_Registry.emplace<VelocityComponent>(f_Player, glm::vec2(600, 600));

		// Give it a velocity level
		m_Registry.emplace<VelocityLevelComponent>(f_Player, 1);
	}
}

void EntityManager::SpawnBasicEnemy(int32_t p_Amount)
{
	if (p_Amount <= 0)
		return;
	for (size_t i = 0; i < p_Amount; ++i)
	{
		auto f_BasicEnemy = CreateEntity();

		// Basic identification
		m_Registry.emplace<TagComponent>(f_BasicEnemy, TagType::BasicEnemy);

		// Make it render-able
		SDL_Color f_Color = { 255, 0, 0, 255 };
		glm::vec2 f_Size = { 25, 25 };
		SDL_Color f_OutlineColor = { 0, 0, 0, 255 };
		int32_t f_OutlineThickness = 3;
		m_Registry.emplace<RectangleShapeComponent>(f_BasicEnemy, f_Color, f_Size, f_OutlineColor, f_OutlineThickness);

		// Give it position
		float f_X_Position = RandomF(0.0f, Game::Instance().GetSettings().Width);
		float f_Y_Position = RandomF(0.0f, Game::Instance().GetSettings().Height);
		m_Registry.emplace<PositionComponent>(f_BasicEnemy, glm::vec2(f_X_Position, f_Y_Position));

		// Give it velocity
		m_Registry.emplace<VelocityComponent>(f_BasicEnemy, glm::vec2(700, 700));
	}
}

void EntityManager::SpawnSmartEnemy(int32_t p_Amount)
{
	if (p_Amount <= 0)
		return;
	for (size_t i = 0; i < p_Amount; ++i)
	{
		auto f_SmartEnemy = CreateEntity();

		// Basic identification
		m_Registry.emplace<TagComponent>(f_SmartEnemy, TagType::SmartEnemy);

		// Make it render-able
		SDL_Color f_Color = { 25, 25, 100, 255 };
		glm::vec2 f_Size = { 25, 25 };
		SDL_Color f_OutlineColor = { 0, 0, 0, 255 };
		int32_t f_OutlineThickness = 3;
		m_Registry.emplace<RectangleShapeComponent>(f_SmartEnemy, f_Color, f_Size, f_OutlineColor, f_OutlineThickness);

		// Give it position
		float f_X_Position = RandomF(0.0f, Game::Instance().GetSettings().Width);
		float f_Y_Position = RandomF(0.0f, Game::Instance().GetSettings().Height);
		m_Registry.emplace<PositionComponent>(f_SmartEnemy, glm::vec2(f_X_Position, f_Y_Position));
	}
}

void EntityManager::SpawnParticleSystem(uint32_t p_MaxParticles, float p_MaxLifetime, float p_Velocity, SDL_Color p_Color)
{
	auto f_ParticleSystem = CreateEntity();

	// Identification
	m_Registry.emplace<TagComponent>(f_ParticleSystem, TagType::ParticleSystem);

	// Initialize Particles
	Particle *f_Particles = new Particle[p_MaxParticles];

	// Initialize with random delay for variation
	for (uint32_t i = 0; i < p_MaxParticles; ++i)
	{
		f_Particles[i].Delay = RandomF(0.0f, p_MaxLifetime);
	}

		/* Properties of the reference particle */
	glm::vec2 size = glm::vec2(10, 10);
	RectangleShapeComponent f_RefShape = {p_Color, size, p_Color, 0};
	m_Registry.emplace<ParticleSystemComponent>(f_ParticleSystem, p_MaxParticles, p_MaxLifetime, p_Velocity, f_RefShape, f_Particles);


	// Set Position
	m_Registry.emplace<PositionComponent>(f_ParticleSystem, glm::vec2(100.0f, 100.0f));

}
