#pragma once
class Game;

class Player:public IGameObject
{
public: 
	Player();
	~Player();
	bool Start() override;
	void Update() override;
	void Render(RenderContext& rc);
	void Move();
	void Rotation();
	void AnimationState();
	void PlayAnimation();

	ModelRender m_modelRender;
	Vector3 m_position;
	CharacterController m_characterController;
	Vector3 m_moveSpeed;
	Quaternion m_rotation;
	int m_playerState=0;
	Vector3 m_setMoveSpeed;
	int m_starCount = 0;
	int m_dashState = 0;
	int m_jumpCount = 0;
	int m_maxJumpCount = 2;
	int m_pause = 0;

private:
	enum EnAnimationClip {//アニメーション
		enAnimationClip_Idle,
		enAnimationClip_Walk,
		enAnimationClip_Jump,
		enAnimationClip_Run,
		enAnimationClip_Num,
	};
	AnimationClip animationClips[enAnimationClip_Num];
	Game* m_game;
};

