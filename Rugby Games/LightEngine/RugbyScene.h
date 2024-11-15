#pragma once

#include "GameManager.h"

#include <list>

class Entity;

class RugbyScene : public Scene
{
	Entity* pEntitySelected;

public:
	void OnInitialize() override;
	void OnEvent(const sf::Event& event) override;
	void TrySetSelectedEntity(Entity* pEntity, int x, int y);
	void OnUpdate() override;
};

