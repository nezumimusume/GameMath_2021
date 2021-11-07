#pragma once
class Player : public IGameObject
{
public:
	bool Start() override;
	void Update() override;
	void Render(RenderContext& rc) override;

	struct DirectionLight {
		Vector3 ligDir;
		float pad;
		Vector4 ligColor;
	};
	DirectionLight m_light[4];
	ModelRender m_modelRender;
	Vector3 m_position;		// 座標
	Vector3 m_moveVec;		// 移動ベクトル
};

