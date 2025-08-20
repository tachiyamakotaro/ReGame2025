#include "stdafx.h"
#include "Player.h"
#include "Game.h"

Player::Player()
{

}

Player::~Player()
{

}

bool Player::Start()
{
	animationClips[enAnimationClip_Idle].Load("Assets/animData/idle.tka");
	animationClips[enAnimationClip_Idle].SetLoopFlag(true);
	animationClips[enAnimationClip_Walk].Load("Assets/animData/walk.tka");
	animationClips[enAnimationClip_Walk].SetLoopFlag(true);
	animationClips[enAnimationClip_Run].Load("Assets/animData/run.tka");
	animationClips[enAnimationClip_Run].SetLoopFlag(true);
	animationClips[enAnimationClip_Jump].Load("Assets/animData/jump.tka");
	animationClips[enAnimationClip_Jump].SetLoopFlag(false);

	m_modelRender.Init("Assets/modelData/unityChan.tkm",animationClips,
		enAnimationClip_Num,enModelUpAxisY);

	m_characterController.Init(25.0f, 75.0f, m_position);
	return true;
}

void Player:: Update()
{
	/*if (g_pad[0]->IsTrigger(enButtonSelect))
	{
		if (m_pause == 0)
		{
			m_pause = 1;
		}
		if (m_pause == 1)
		{
			m_pause = 0;
		}
	}*/

	if (m_pause == 0)
	{
		Move();

		Rotation();

		AnimationState();

		m_modelRender.Update();
	}
	/*else if(m_pause==1)
	{
		m_modelRender.Update();
	}*/


}

void Player::Move()
{
	////移動速度にスティックの入力量を加算する。
	////地面に着いていてかつ、条件を満たすと移動速度が変わる
	//if (m_characterController.IsOnGround()) 
	//{
	//	if (g_pad[0]->IsPress(enButtonB)) 
	//	{
	//		m_setMoveSpeed.x =  500.0f;
	//		m_setMoveSpeed.z = 500.0f;
	//	}
	//	else 
	//	{
	//		m_setMoveSpeed.x =  250.0f;
	//		m_setMoveSpeed.z =  250.0f;
	//	}
	//}
	////上に書いているsetMoveSpeedが代入される
	////ジャンプするとsetMoveSpeedが固定される
	////ダッシュ中にジャンプすると500.0fに固定される
	////入力を取得
	
	//xzの移動速度を0.0fにする
		m_moveSpeed.x = 0.0f;
		m_moveSpeed.z = 0.0f;

	Vector3 stickL;
	stickL.x = g_pad[0]->GetLStickXF();
	stickL.y = g_pad[0]->GetLStickYF();

	Vector3 forward = g_camera3D->GetForward();
	Vector3 right = g_camera3D->GetRight();

	forward.y = 0.0f;
	right.y = 0.0f;

	/*float m_speedPower = 0.0f;*/

	right *= stickL.x * 250.0f;
	forward *= stickL.y * 250.0f;
	/*m_moveSpeed.x =stickL.x* m_setMoveSpeed.x;
	m_moveSpeed.z = stickL.y*m_setMoveSpeed.z;*/
	m_moveSpeed += right + forward;
	
	//移動速度にスティックの入力量を加算する。
	//地面に着いていてかつ、条件を満たすと移動速度が変わる
	if (m_characterController.IsOnGround())
	{
		if (g_pad[0]->IsPress(enButtonB))
		{
			m_moveSpeed.x *= 2;
			m_moveSpeed.z *= 2;
			m_dashState = 1;
		}
		else
		{
			m_dashState = 0;
		}
	}
	else if(m_dashState==1)
	{
		m_moveSpeed.x *= 2;
		m_moveSpeed.z *= 2;
	}
	
	//上に書いているsetMoveSpeedが代入される
	//ジャンプするとsetMoveSpeedが固定される
	//ダッシュ中にジャンプすると500.0fに固定される
	

	m_position = m_characterController.Execute(m_moveSpeed, 1.0f / 60.0f);
	m_moveSpeed.y -= 20.0f;
	
	if (m_characterController.IsOnGround() == true)
	{
		if (g_pad[0]->IsTrigger(enButtonA))
		{
					m_moveSpeed.y = 700.0f; // ジャンプ力
					m_playerState = 1; // ジャンプ状態にする
		}
	}
	else if(m_playerState==0)
	{
			m_playerState = 1; // ジャンプ状態にする
	}
	if (m_playerState == 1  or m_playerState==2)
	{
		if (m_characterController.IsOnGround() == true)
		{
			m_playerState = 0;
		}
	}

	if (m_playerState==1) 
	{
		//m_modelRender.PlayAnimation(enAnimationClip_Jump);
		if (g_pad[0]->IsTrigger(enButtonA))
		{
			m_moveSpeed.y = 700.0f; // ジャンプ力
			m_playerState=2; // ジャンプ状態にする
			
			//m_modelRender.PlayAnimation(enAnimationClip_Jump);
		}
	}
	
	

	//絵描きさんに座標を教える。
	m_modelRender.SetPosition(m_position);
}

void Player::Rotation()
{
	if (fabsf(m_moveSpeed.x) >= 0.001f || fabsf(m_moveSpeed.z) >= 0.001f)
	{
		m_rotation.SetRotationYFromDirectionXZ(m_moveSpeed);
		m_modelRender.SetRotation(m_rotation);
	}
}

void Player::AnimationState()
{
	if (m_characterController.IsOnGround() == false)
	{
		m_modelRender.PlayAnimation(enAnimationClip_Jump);
	}
	else if (fabsf(m_moveSpeed.x) >= 0.001f || fabsf(m_moveSpeed.z) >= 0.001f)
	{
		if (m_playerState == 0) 
		{
			if (g_pad[0]->IsPress(enButtonB))
			{
				m_modelRender.PlayAnimation(enAnimationClip_Run);
			}
			else
			{
				m_modelRender.PlayAnimation(enAnimationClip_Walk);
			}
		}
	}
	else
	{
		m_modelRender.PlayAnimation(enAnimationClip_Idle);
	}
}

void Player::PlayAnimation()
{
}

void Player::Render(RenderContext& rc)
{
	m_modelRender.Draw(rc);
}

