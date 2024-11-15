#include "RugbyScene.h"
#include "Debug.h"
#include "Player.h"
#include "Entity.h"

void RugbyScene::OnInitialize()
{
	pPlayer = CreateEntity<Player>(20, sf::Color::Blue);
	pPlayer->SetPosition(50, 100);
}

void RugbyScene::OnEvent(const sf::Event& event)
{
	if (event.type != sf::Event::EventType::MouseButtonPressed)
		return;

	if (event.mouseButton.button == sf::Mouse::Button::Right)
	{
		TrySetSelectedEntity(pPlayer, event.mouseButton.x, event.mouseButton.y);
		/*TrySetSelectedEntity(pEntity2, event.mouseButton.x, event.mouseButton.y);*/
	}

	if (event.mouseButton.button == sf::Mouse::Button::Left)
	{
		if (pEntitySelected != nullptr)
		{
			pEntitySelected->GoToPosition(event.mouseButton.x, event.mouseButton.y, 100.f);
		}
	}
}

void RugbyScene::TrySetSelectedEntity(Entity* pEntity, int x, int y)
{
	if (pEntity->IsInside(x, y) == false)
		return;

	pEntitySelected = pEntity;
}

void RugbyScene::OnUpdate()
{
	for (int i = 0; i < 3; i++)
	{
		Debug::Get()->DrawRectangle(1, (GetWindowHeight() / 3) * i, GetWindowWidth() - 1, GetWindowHeight(), sf::Color::Blue);
	}

	Debug::Get()->DrawRectangle(1, 1, GetWindowWidth() / 10, GetWindowHeight() - 2, sf::Color::White);
	Debug::Get()->DrawRectangle(GetWindowWidth() - (GetWindowWidth() / 10), 1, GetWindowWidth() / 10, GetWindowHeight() - 2, sf::Color::White);
}
