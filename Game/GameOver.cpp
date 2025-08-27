#include "stdafx.h"
#include "GameOver.h"
#include "Title.h"
#include "Game.h"
#include "sound/SoundEngine.h"
#include "SoundManager.h"



GameOver::GameOver()
{

}

GameOver::~GameOver()
{

}

bool GameOver::Start()
{
	m_spriteRender.Init("Assets/sprite/GAMEOVER.DDS",1920.0f,1080.0f);

	/*g_soundEngine->ResistWaveFileBank(1, "Assets/sound/AS_133054_切ないオルゴール_回想_ゲームオーバー.wav");
	m_gameOverBGM = NewGO<SoundSource>(0, "gameOverBGM");
	m_gameOverBGM->Init(1);
	m_gameOverBGM->Play(true);*/

	SoundManager* sound = FindGO<SoundManager>("soundManager");
	m_gameOverBGM = sound->PlayingSound(Sound::enSound_GameOverBGM);

	/*m_continuefontRender.SetText(L"    CONTINUE     \nPRESS START BUTTON");
	m_continuefontRender.SetPosition({ -270.0f,100.0f,0.0f });
	m_continuefontRender.SetColor(g_vec4Black);
	m_continuefontRender.SetScale(1.5f);*/

	m_titleTransferFontRender.SetText(L"      EXIT      \nPRESS SELECT BUTTON");
	m_titleTransferFontRender.SetPosition({ -300.0f,-200.0f,0.0f });
	m_titleTransferFontRender.SetScale(1.5f);
	m_titleTransferFontRender.SetColor(g_vec4Black);

	return true;
}

void GameOver::Update()
{
	/*if (g_pad[0]->IsTrigger(enButtonStart))
	{
		NewGO<Game>(0, "game");
		DeleteGO(m_gameOverBGM);
		DeleteGO(this);
	}*/
	if (g_pad[0]->IsTrigger(enButtonSelect))
	{
		NewGO<Title>(0, "title");
		DeleteGO(m_gameOverBGM);
		DeleteGO(this);
	}
}

void GameOver::Render(RenderContext& rc)
{
	m_spriteRender.Draw(rc);
	m_continuefontRender.Draw(rc);
	m_titleTransferFontRender.Draw(rc);
}