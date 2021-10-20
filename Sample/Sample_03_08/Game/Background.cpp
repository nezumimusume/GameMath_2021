#include "stdafx.h"
#include "Background.h"


bool Background::Start()
{
	m_modelRender.Init("Assets/modelData/bg/bg.tkm");
	return true;
}
void Background::Update()
{
	m_modelRender.Update();
}
void Background::Render(RenderContext& rc)
{
	m_modelRender.Draw(rc);
}