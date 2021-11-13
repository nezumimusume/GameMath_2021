#pragma once

class Player;

class GameCamera : public IGameObject
{
public:
	bool Start() override;
	void Update() override;
private:
	Player* m_player = nullptr;
};

