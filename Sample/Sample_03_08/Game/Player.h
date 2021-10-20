#pragma once
class Player : public IGameObject
{
public:
	bool Start() override;
	void Update() override;
	void Render(RenderContext& rc) override;
	const Vector3& GetPosition() const
	{
		return m_position;
	}
private:
	ModelRender m_modelRender;
	Vector3 m_position;		// 座標
	Vector3 m_moveVec;		// 移動ベクトル
};

