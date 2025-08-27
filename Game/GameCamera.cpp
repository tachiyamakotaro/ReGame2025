#include "stdafx.h"
#include "GameCamera.h"
#include "Player.h"

GameCamera::GameCamera()
{

}

GameCamera::~GameCamera()
{

}

bool GameCamera::Start()
{
	m_player = FindGO<Player>("BattleCharacter");
	m_toCameraPos.Set(0.0f, 125.0f, -250.0f);

	return true;
}

void GameCamera::Update()
{
	//Vector3 target;

	//target.x = m_player->m_position.x;
	//target.y = m_player->m_position.y + 100.0f; // プレイヤーの頭の位置
	//target.z = m_player->m_position.z;

	Vector3 target = m_player->m_position;
	target.y += 80.0f;

	//Vector3 toCameraPosOld = m_toCameraPos;
	////パッドの入力を使ってカメラを回す。
	//float x = g_pad[0]->GetRStickXF();
	//float y = g_pad[0]->GetRStickYF();
	////Y軸周りの回転
	//Quaternion qRot;
	//qRot.SetRotationDeg(Vector3::AxisY, 1.3f * x);
	//qRot.Apply(m_toCameraPos);
	////X軸周りの回転。
	//Vector3 axisX;
	//axisX.Cross(Vector3::AxisY, m_toCameraPos);
	//axisX.Normalize();
	//qRot.SetRotationDeg(axisX, 1.3f * y);
	//qRot.Apply(m_toCameraPos);

	//Vector3 toPosDir = m_toCameraPos;
	//toPosDir.Normalize();
	//if (toPosDir.y < -0.2f) 
	//{
	//	m_toCameraPos = toCameraPosOld;
	//}
	//else if (toPosDir.y > 0.9f) 
	//{
	//	m_toCameraPos = toCameraPosOld;
	//}

	Vector3 pos = target + m_toCameraPos;
	
	g_camera3D->SetTarget(target);
	g_camera3D->SetPosition(pos);

	g_camera3D->SetNear(1.0f);
	g_camera3D->SetFar(40000.0f);

	g_camera3D->Update();
}

void GameCamera::Render(RenderContext& rc)
{
	
}