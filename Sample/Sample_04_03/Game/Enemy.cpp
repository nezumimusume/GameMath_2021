#include "stdafx.h"
#include "Enemy.h"
#include "Player.h"

void Enemy::Init(Vector3 initPos)
{
	m_position = initPos;
	m_rotation.SetRotationY(Math::PI);
	// メンバ変数のm_playerにアドレスを記憶しておく。、
	m_player = FindGO<Player>("Player");
}
bool Enemy::Start()
{
	m_modelRender.Init("Assets/modelData/enemy/enemy.tkm");
	m_modelRender.SetRotation(m_rotation);
	m_modelRender.SetPosition(m_position);
	m_modelRender.SetScale({ 3.0f, 3.0f, 3.0f });
	return true;
}
void Enemy::Update()
{
	// step-1 視野角45度以内にプレイヤーが入ってきたら追いかける。
	
	// 敵の前方方向を使って、回転クォータニオンを計算する。
	m_rotation.SetRotationY(atan2(m_enemyFowrad.x, m_enemyFowrad.z));
	m_modelRender.SetPosition(m_position);
	m_modelRender.SetRotation(m_rotation);
	m_modelRender.Update();
}
void Enemy::Render(RenderContext& rc)
{
	m_modelRender.Draw(rc);
}