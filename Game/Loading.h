#pragma once
class Loading:public IGameObject
{
public:
	Loading();
	~Loading();
	bool Start()override;
	void Update()override;
	void Render(RenderContext& rc) override;
	void StartFadeIn()
	{
		m_state = enState_FadeIn;
	}
	void StartFadeOut()
	{
		m_state = enState_FadeOut;
	}

	bool IsFade() const
	{
		return m_state != enState_Idle;
	}
	float GetCurrentAlpha() const
	{
		return m_currentAlpha;
	}

private:
	enum EnState {
		enState_FadeIn,
		enState_FadeOut,
		enState_Idle
	};
	SpriteRender	m_loadingRender;
	SpriteRender	m_indicatorRender;
	EnState			m_state = enState_Idle;
	float			m_currentAlpha = 1.0f;
};

