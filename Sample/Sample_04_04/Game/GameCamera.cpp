#include "stdafx.h"
#include "GameCamera.h"
#include "Player.h"

bool GameCamera::Start()
{
	g_camera3D->SetPosition(0.0f, 200.0f, -300.0f);
	g_camera3D->SetTarget(0.0f, 100.0f, 0.0f);

	m_player = FindGO<Player>("Player");
	return true;
}
void GameCamera::Update()
{
	auto toPosition = g_camera3D->GetPosition() - g_camera3D->GetTarget();
	auto camTarget = m_player->m_position;
	camTarget.y += 100.0f;
	auto camPos = camTarget + toPosition;
	g_camera3D->SetTarget(camTarget);
	g_camera3D->SetPosition(camPos);
}