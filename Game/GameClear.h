#pragma once
#include "sound/SoundSource.h"
class GameClear:public IGameObject
{
public:
	GameClear();
	~GameClear();
	bool Start();
	void Update();
	void Render(RenderContext& rc);

private:
	enum EnState
	{
		enState_FadeIn,
		enState_FadeOut,
	};
	SpriteRender m_spriteRender;
	FontRender   m_fontRender;
	FontRender   m_titleTransferFontRender;
	EnState      m_state = enState_FadeIn;
	float        m_currentAlpha = 1.0f;
	SoundSource* m_clearBGM;
};

