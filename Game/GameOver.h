#pragma once
#include "sound/SoundSource.h"

class GameOver:public IGameObject
{
public:
	GameOver();
	~GameOver();
	bool Start();
	void Update();
	void Render(RenderContext& rc);

	SpriteRender m_spriteRender;
	FontRender m_continuefontRender;
	FontRender   m_titleTransferFontRender;
	SoundSource* m_gameOverBGM;
};

