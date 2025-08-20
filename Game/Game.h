#pragma once
#include "sound/SoundSource.h"

#include "Level3DRender/LevelRender.h"

class Player;
class BackGround;
class GameCamera;
class Item;
class GameClear;

class Game : public IGameObject
{
public:
	Game();
	~Game();
	bool Start();
	void Update();
	void Render(RenderContext& rc);
	void MakeItem(Vector3 pos);

	
private:
	Player* m_player = nullptr;
	BackGround* m_backGround = nullptr;
	GameCamera* m_gameCamera = nullptr;
	Item* m_Item = nullptr;
	Vector3 m_pos;
	ModelRender m_modelRender;
	SkyCube* m_skyCube;
	int m_skyCubeType;
	SoundSource* m_gameBGM;
	
};

