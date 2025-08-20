#include "stdafx.h"
#include "Loading.h"

namespace
{
	const Vector3 INDISCALE = Vector3(2.0f, 2.0f, 2.0f);
	const Vector3 INDIPOSITION = Vector3(240.0f, 200.0f, 0.0f);
}

Loading::Loading()
{

}

Loading::~Loading()
{

}

bool Loading::Start()
{
	m_loadingRender.Init("Assets/sprite/nowLoading.DDS", 1920, 1080);

	/*m_indicatorRender.Init("Assets/sprite/Indicator.DDS", 1024, 512);
	m_indicatorRender.SetScale(INDISCALE);
	m_indicatorRender.SetPosition(INDIPOSITION);*/
	m_loadingRender.Update();
	return true;
}

void Loading::Update()
{
	switch (m_state) {
	case enState_FadeIn:
		m_currentAlpha -= 2.0f * g_gameTime->GetFrameDeltaTime();
		if (m_currentAlpha <= 0.0f) {
			m_currentAlpha = 0.0f;
			m_state = enState_Idle;
		}
		break;
	case enState_FadeOut:
		m_currentAlpha += 2.0f * g_gameTime->GetFrameDeltaTime();
		if (m_currentAlpha >= 1.0f) {
			m_currentAlpha = 1.0f;
			m_state = enState_Idle;
		}
		break;
	case enState_Idle:
		break;
	}
	//m_indicatorRender.Update();
}

void Loading::Render(RenderContext& rc)
{
	if (m_currentAlpha > 0.0f) {
		m_loadingRender.Draw(rc);
		//m_indicatorRender.Draw(rc);
	}
}
