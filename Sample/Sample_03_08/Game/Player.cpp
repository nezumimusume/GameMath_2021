#include "stdafx.h"
#include "Player.h"

bool Player::Start()
{
	m_modelRender.Init("Assets/modelData/unityChan.tkm");
	m_modelRender.SetShadowCasterFlag(true);
	
	// 前方方向に進むベクトル
	m_moveVec.z = 2.0f;
	return true;
}
void Player::Update()
{	
	// step-1 Aボタンの入力で右方向のベクトルを加える

	// step-2 Bボタンの入力で左方向のベクトルを加える。
	
	// step-3 Xボタンの入力で斜め右方向のベクトルを加える。
	
	// step-4 Yボタンの入力で斜め右方向のベクトルを加える。
	

	// 移動ベクトルと座標を足し算する  
	m_position += m_moveVec;

	m_modelRender.SetPosition(m_position);
	m_modelRender.Update();

	g_k2Engine->DrawVector(
		m_moveVec * 40.0f, // ベクトルが小さくて見えないので、10倍する
		{ m_position.x, m_position.y + 50.0f, m_position.z }
	);
}
void Player::Render(RenderContext& rc)
{
	m_modelRender.Draw(rc);
	
}