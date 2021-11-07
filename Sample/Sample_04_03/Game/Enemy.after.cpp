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
	// エネミーからプレイヤーに向かって伸びるベクトルを計算する。
	Vector3 toPlayer = m_player->m_position - m_position;

	// プレイヤーとの距離を計算する。
	float distToPlayer = toPlayer.Length();

	// プレイヤーとの距離が400以下だったら追いかける。
	if (distToPlayer < 400) {
		// ここから視野角判定
		// プレイヤーに向かって伸びるベクトルを正規化する。
		Vector3 toPlayerDir = toPlayer;
		toPlayerDir.Normalize();
		// エネミーの前方方向とtoPlayerDirとの内積を計算する。
		float t = toPlayerDir.Dot(m_enemyFowrad);
		// 内積の結果をacos関数に渡して、m_enemyFowradとtoPlayerDirのなす角度を求める。
		float angle = acos(t);

		// 視野角判定
		// fabsfは絶対値を求める関数！
		// 角度はマイナスが存在するから、絶対値で判定する。
		if (fabsf(angle) < Math::DegToRad(45.0f)) {
			// プレイヤーを発見したので、追いかける。
			// エネミーの座標を動かす。
			m_position += toPlayerDir * 2.0f;
			
			// 敵キャラの前方方向を更新する。
			m_enemyFowrad = toPlayerDir;
		}
	}
	
	
	m_rotation.SetRotationY(atan2(m_enemyFowrad.x, m_enemyFowrad.z));
	m_modelRender.SetPosition(m_position);
	m_modelRender.SetRotation(m_rotation);
	m_modelRender.Update();
}
void Enemy::Render(RenderContext& rc)
{
	m_modelRender.Draw(rc);
}