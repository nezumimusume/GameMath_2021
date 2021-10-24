#include "stdafx.h"
#include "system/system.h"
#include "Background.h"
#include "Player.h"
#include "GameCamera.h"
#include "Enemy.h"

///////////////////////////////////////////////////////////////////
// ウィンドウプログラムのメイン関数。
///////////////////////////////////////////////////////////////////
int WINAPI wWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPWSTR lpCmdLine, int nCmdShow)
{
	//ゲームの初期化。
	InitGame(hInstance, hPrevInstance, lpCmdLine, nCmdShow, TEXT("Game"));

	g_sceneLight->SetDirectionLight(0, { 0.0f, -1.0f, 0.0f }, { 0.8f, 0.8f, 0.8f });
	g_renderingEngine->SetCascadeNearAreaRates(0.1f, 0.4f, 0.2f);

	auto& renderContext = g_graphicsEngine->GetRenderContext();
	
	auto bg = NewGO<Background>(0);
	auto pl = NewGO<Player>(0,"Player");
	auto cam = NewGO<GameCamera>(0);
	Vector3 enemyPositionArray[] = {
		{200.0f, 0.0f, 1000.0f},
		{-400.0f, 0.0f, 500.0f},
		{600.0f, 0.0f, 800.0f},
	};
	for (auto& pos : enemyPositionArray)
	{
		auto enemy = NewGO<Enemy>(0);
		enemy->Init(pos);
	}
	

	// ここからゲームループ。
	while (DispatchWindowMessage())
	{
		K2Engine::GetInstance()->Execute();
	
	}
	K2Engine::DeleteInstance();

#ifdef _DEBUG
	ReportLiveObjects();
#endif // _DEBUG
	return 0;
}

