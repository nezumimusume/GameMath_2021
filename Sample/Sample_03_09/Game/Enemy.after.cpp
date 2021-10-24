#include "stdafx.h"
#include "Enemy.h"
#include "Player.h"

void Enemy::Init(Vector3 initPos)
{
	m_position = initPos;
	m_rotation.SetRotationY(Math::PI);
	// step-1 プレイヤーのインスタンスのアドレスを検索する。
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
	// step-2 エネミーからプレイヤーに向かって伸びるベクトルを計算する。
	Vector3 toPlayer = m_player->m_position - m_position;
	
	// step-3 エネミーからプレイヤーに向かって伸びるベクトルを表示する。
	g_k2Engine->DrawVector(toPlayer, m_position);

	// step-4 プレイヤーとの距離を計算する。
	float distToPlayer = toPlayer.Length();

	// step-5 プレイヤーとの距離が200以下になったら、プレイヤーを発見したというメッセージを表示する。
	if (distToPlayer < 200) {
		MessageBoxA(nullptr, "プレイヤーを見つけた。", "通知", MB_OK);
	}
	m_modelRender.SetPosition(m_position);
	m_modelRender.Update();
}
void Enemy::Render(RenderContext& rc)
{
	m_modelRender.Draw(rc);
}