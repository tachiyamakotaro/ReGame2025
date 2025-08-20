#include "stdafx.h"
#include "Game.h"
#include "Player.h"
#include "BackGround.h"
#include "GameCamera.h"
#include "Item.h"
#include "GameClear.h"
#include "GameOver.h"
#include "sound/soundEngine.h"
#include "SoundManager.h"

Game::Game()
{

}

void Game::MakeItem(const Vector3 pos)
{
	Item* item = NewGO<Item>(0, "Item");
	item->m_position = pos;
	item->m_firstPosition = pos;
}

Game::~Game()
{
	DeleteGO(m_player);
	DeleteGO(m_backGround);
	DeleteGO(m_gameCamera);
	auto totalItem = FindGOs<Item>("Item");
	for (auto Items : totalItem)
	{
		DeleteGO(Items);
	}
}

bool Game::Start()
{
	m_player = NewGO<Player>(0, "BattleCharacter");
	
	m_backGround = NewGO<BackGround>(0, "BackGround");

	m_gameCamera = NewGO<GameCamera>(0, "GameCamera");

	SoundManager* sound = FindGO<SoundManager>("soundManager");
	m_gameBGM = sound->PlayingSound(Sound::enSound_InGameBGM);

	//ƒAƒCƒeƒ€‚ðì‚é
	MakeItem({ 0.0f,25.0f,1100.0f });
	MakeItem({ 0.0f,420.0f,2460.0f });
	MakeItem({ 0.0f,740.0f,3950.0f });
	MakeItem({ 0.0f,-870.0f,4100.0f });
	MakeItem({ 0.0f,-380.0f,6500.0f });

	//PhysicsWorld::GetInstance()

	return true;
}



void Game::Update()
{
	
	if (m_player->m_starCount == 5)
	{
		NewGO<GameClear>(0, "gameClear");
		DeleteGO(m_gameBGM);
		DeleteGO(this);
	}
	if (m_player->m_position.y <= -1200.0f)
	{
		NewGO<GameOver>(0, "gameOver");
		DeleteGO(m_gameBGM);
		DeleteGO(this);
	}

	m_modelRender.Update();
}

void Game::Render(RenderContext& rc)
{
	
}