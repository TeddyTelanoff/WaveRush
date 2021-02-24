#include "PlayScene.hpp"

#include "system/PlayerMovementSystem.hpp"
#include "system/RenderRectShapeSystem.hpp"
#include "system/BasicEnemyMovementSystem.hpp"
#include "system/SmartEnemyMovementSystem.hpp"
#include "system/ParticleSystem.hpp"

PlayScene::PlayScene()
{
	// Add entities
	GetEntityManager().SpawnPlayer(1);
	GetEntityManager().SpawnSmartEnemy(10);
	GetEntityManager().SpawnBasicEnemy(10);
	
	SDL_Color f_ParticleColor = {255, 0, 0, 255};
	SDL_Color f_ParticleColor2 = {0, 0, 255, 0};
	GetEntityManager().SpawnParticleSystem(500, 3, 0.1, f_ParticleColor, f_ParticleColor2);

	// Register systems
	GetSystemManager().RegisterSystem(new PlayerMovementSystem());
	GetSystemManager().RegisterSystem(new RenderRectShapeSystem());
	GetSystemManager().RegisterSystem(new BasicEnemyMovementSystem());
	GetSystemManager().RegisterSystem(new SmartEnemyMovementSystem());
	GetSystemManager().RegisterSystem(new ParticleSystem());
}
