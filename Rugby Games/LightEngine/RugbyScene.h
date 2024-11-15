#pragma once

#include "GameManager.h"

#include <list>

class Entity;
class Player;

class RugbyScene : public Scene
{
	Entity* pEntitySelected;

	Player* pPlayer;

public:
	void OnInitialize() override;
	void OnEvent(const sf::Event& event) override;
	void TrySetSelectedEntity(Entity* pEntity, int x, int y);
	void OnUpdate() override;
};

