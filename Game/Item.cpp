#include "stdafx.h"
#include "Item.h"
#include "Player.h"
#include "SoundManager.h"

Item::Item()
{
	
}

Item::~Item()
{

}

bool Item::Start()
{
	m_modelRender.Init("Assets/modelData/Item.tkm");

    m_player = FindGO<Player>("BattleCharacter");

    //g_soundEngine->ResistWaveFileBank(0, "Assets/sound/AS_799513_キラキラ④（星・輝き・完成・変身・魔法）.wav");

	return true;
}

void Item::Update()
{
	Move();

    Rotation();

	m_modelRender.Update();

    Vector3 diff = m_player->m_position - m_position;
    if (diff.Length() <= 120.0f)
    {
        SoundManager* sound = FindGO<SoundManager>("soundManager");
        m_itemGetSE = sound->PlayingSound(Sound::enSound_ItemGetSE,false);
        m_player->m_starCount += 1;
       
        DeleteGO(this);
    }
}

void Item::Move()
{
    //moveStateが0の時。
    if (m_moveState == 0)
    {
       m_position.y += 1.0f;
    }

    //moveStateが1の時。
    else if (m_moveState == 1)
    {
        m_position.y -= 1.0f;
    }

    //y座標が100.0fを超えたら。
    if (m_position.y >= m_firstPosition.y+20.0f)
    {
        m_moveState = 1;
    }

    //y座標が-100.0fより下になったら。
    else if (m_position.y <= m_firstPosition.y -20.0f)
    {
        m_moveState = 0;
    }

	m_modelRender.SetPosition(m_position);
}

void Item::Rotation()
{
    m_rotation.AddRotationDegY(2.0f);
    m_modelRender.SetRotation(m_rotation);
}

void Item::Render(RenderContext& rc)
{
	m_modelRender.Draw(rc);
}