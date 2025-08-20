#include "stdafx.h"
#include "GameClear.h"
#include "Title.h"
#include "sound/SoundEngine.h"
#include "SoundManager.h"




GameClear::GameClear()
{

}

GameClear::~GameClear()
{

}

bool GameClear::Start()
{
	m_spriteRender.Init("Assets/sprite/GameClear02.DDS", 1920.0f, 1080.0f);

	SoundManager* sound = FindGO<SoundManager>("soundManager");
	m_clearBGM = sound->PlayingSound(Sound::enSound_GameClearBGM);
	/*m_fontRender.SetText(L"GAME CLEAR!!");
	m_fontRender.SetPosition({ -400.0f,200.0f,0.0f });
	m_fontRender.SetScale(3.0f);
	m_fontRender.SetColor(g_vec4Black);*/

	m_titleTransferFontRender.SetText(L"     EXIT     \nPRESS SELECT BUTTON");
	m_titleTransferFontRender.SetPosition({ -300.0f,-200.0f,0.0f });
	m_titleTransferFontRender.SetScale(1.5f);
	m_titleTransferFontRender.SetColor(g_vec4Black);

	return true;
}

void GameClear::Update()
{
	if (g_pad[0]->IsTrigger(enButtonSelect))
	{
		NewGO<Title>(0, "title");
		DeleteGO(m_clearBGM);
		DeleteGO(this);
	}
	switch (m_state)
	{
	case enState_FadeIn:
		m_currentAlpha -= 0.5f * g_gameTime->GetFrameDeltaTime();
		if (m_currentAlpha <= 0.0f)
		{
			m_currentAlpha = 0.0f;
			m_state = enState_FadeOut;
		}
		break;
	case enState_FadeOut:
		m_currentAlpha += 0.5f * g_gameTime->GetFrameDeltaTime();
		if (m_currentAlpha >= 1.0f)
		{
			m_currentAlpha = 1.0f;
			m_state = enState_FadeIn;
		}
		break;
	}
}

void GameClear:: Render(RenderContext& rc)
{
	m_spriteRender.Draw(rc);
	//m_fontRender.Draw(rc);
	if (m_currentAlpha > 0.0f)
	{
		m_titleTransferFontRender.SetColor({ 0.0f,0.0f,0.0f,m_currentAlpha });
		m_titleTransferFontRender.Draw(rc);
	}
}