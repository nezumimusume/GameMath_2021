#include "stdafx.h"
#include "Player.h"

bool Player::Start()
{
	m_modelRender.Init("Assets/modelData/unityChan.tkm");
	m_modelRender.SetShadowCasterFlag(true);
	
	return true;
}
void Player::Update()
{	
	// プレイヤーの移動ベクトルを計算する。
	m_moveVec.x = g_pad[0]->GetLStickXF();
	m_moveVec.z = g_pad[0]->GetLStickYF();
	m_moveVec *= 5.0f;

	// 移動ベクトルと座標を足し算する  
	m_position += m_moveVec;
	m_modelRender.SetPosition(m_position);
	m_modelRender.Update();

}
void Player::Render(RenderContext& rc)
{
	m_modelRender.Draw(rc);
	
}