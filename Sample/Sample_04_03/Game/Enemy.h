#pragma once

class Player;

class Enemy : public IGameObject
{
public:
	void Init(Vector3 initPos);
	bool Start();
	void Update() ;
	void Render(RenderContext& rc) ;

	ModelRender m_modelRender;		// モデルレンダラー。
	Vector3 m_position;				// 座標。
	Quaternion m_rotation;			// 回転。
	Vector3 m_enemyFowrad = {0.0f, 0.0f, -1.0f};	// 敵の前方ベクトル
	Player* m_player = nullptr;		// プレイヤーのアドレスを記憶する変数。
};

