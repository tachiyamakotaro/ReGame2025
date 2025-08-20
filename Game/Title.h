#pragma once
#include "sound/SoundSource.h"

class Loading;
class Title:public IGameObject
{
public:
	Title();
	~Title();
	bool Start();
	void Update();
	void Load();
	void Render(RenderContext& rc);

	
private:
	enum EnState
	{
		enState_FadeIn,
		enState_FadeOut,
	};
	/*int m_alphaState;*/
	SpriteRender m_spriteRender;
	FontRender   m_titleFontRender;
	FontRender   m_gameStartFontRender;
	EnState      m_state = enState_FadeIn;
	float		 m_blinkState = 0.0f;
	float		 m_blinkAlpha = 0.0f;
	float        m_currentAlpha = 1.0f;
	SoundSource* m_titleBGM;
	Loading* m_loading = nullptr;
	bool	 m_isWaitFadeOut = false;
};

