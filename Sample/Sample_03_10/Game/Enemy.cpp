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
	// エネミーからプレイヤーに向かって伸びるベクトルを計算する。
	Vector3 toPlayer = m_player->m_position - m_position;
	
	// エネミーからプレイヤーに向かって伸びるベクトルを表示する。
	g_k2Engine->DrawVector(toPlayer, m_position);

	// プレイヤーとの距離を計算する。
	float distToPlayer = toPlayer.Length();

	// プレイヤーとの距離が400以下だったら追いかける。
	if (distToPlayer < 400) {
		// step-1 プレイヤーに向かって伸びるベクトルを正規化する。

		// step-2 step-1で求めたベクトルを利用して、エネミーの座標を動かす。
		
	}
	m_modelRender.SetPosition(m_position);
	m_modelRender.Update();
}
void Enemy::Render(RenderContext& rc)
{
	m_modelRender.Draw(rc);
}