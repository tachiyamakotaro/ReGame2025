#include "stdafx.h"
#include "Title.h"
#include "Game.h"
#include "sound/SoundEngine.h"
#include "SoundManager.h"
#include "Loading.h"



Title::Title()
{

}

Title::~Title()
{

}

bool Title::Start()
{
	m_spriteRender.Init("Assets/sprite/Title.DDS", 1920.0f, 1080.0f);

	//PlayingSound()を使用するため、SoundManagerのインスタンスを取得。
	SoundManager* sound = FindGO<SoundManager>("soundManager");
	//BGMの再生。
	m_titleBGM = sound->PlayingSound(Sound::enSound_TitleBGM);

	/*m_titleFontRender.SetText(L"ユニティちゃんのアイテム集め");
	m_titleFontRender.SetPosition({ -800.0f,300.0f,0.0f });
	m_titleFontRender.SetScale(2.5f);
	m_titleFontRender.SetColor(g_vec4Black);*/

	m_gameStartFontRender.SetText(L"   GAME START  \n PRESS X BUTTON");
	m_gameStartFontRender.SetPosition({ -300.0f,-100.0f,0.0f });
	m_gameStartFontRender.SetScale(1.8f);
	//m_gameStartFontRender.SetColor({1.0f,1.0f,0.0f,m_currentAlpha });
	return true;
}

void Title::Update()
{
	if (g_pad[0]->IsTrigger(enButtonX))
	{
		NewGO<Game>(0, "game");
		DeleteGO(m_titleBGM);
		DeleteGO(this);
	}

	switch (m_state)
	{ 
	case enState_FadeIn:
		m_currentAlpha -= 0.6f * g_gameTime->GetFrameDeltaTime();
		if (m_currentAlpha <= 0.0f)
		{
			m_currentAlpha = 0.0f;
			m_state = enState_FadeOut;
		}
		break;
	case enState_FadeOut:
		m_currentAlpha += 0.6f * g_gameTime->GetFrameDeltaTime();
		if (m_currentAlpha >= 1.0f)
		{
			m_currentAlpha = 1.0f;
			m_state = enState_FadeIn;
		}
		break;

	}
}

void Title::Load()
{
	if (m_isWaitFadeOut) {
		if (!m_loading->IsFade()) {
			NewGO<Game>(0, "game");
			DeleteGO(this);
		}
	}
	else {
		if (g_pad[0]->IsTrigger(enButtonX)) {
			m_isWaitFadeOut = true;
			m_loading->StartFadeOut();
			
		}
	}

	m_spriteRender.Update();
}

void Title::Render(RenderContext& rc)
{
	m_spriteRender.Draw(rc);
	//m_titleFontRender.Draw(rc);
	if (m_currentAlpha > 0.0f) {
		m_gameStartFontRender.SetColor({ 0.0f,m_currentAlpha,m_currentAlpha,m_currentAlpha });
		m_gameStartFontRender.Draw(rc);
	}
}