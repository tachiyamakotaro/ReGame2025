#pragma once
//#include"sound/SoundSource.h"

class Player;

class Item:public IGameObject
{
public:
	Item();
	~Item();
	bool Start();
	void Update();
	void Render(RenderContext& rc);
	void Move();
	void Rotation();

	ModelRender m_modelRender;
	Vector3 m_position;
	int m_moveState = 0;
	Vector3 m_firstPosition;
	Quaternion m_rotation;
	Player* m_player;
	SoundSource* m_itemGetSE;
};

