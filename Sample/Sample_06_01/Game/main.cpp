#include "stdafx.h"
#include "system/system.h"
#include "Background.h"

///////////////////////////////////////////////////////////////////
// ウィンドウプログラムのメイン関数。
///////////////////////////////////////////////////////////////////
int WINAPI wWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPWSTR lpCmdLine, int nCmdShow)
{
	//ゲームの初期化。
	InitGame(hInstance, hPrevInstance, lpCmdLine, nCmdShow, TEXT("Game"));
	Background* bg = NewGO< Background>(0);

	g_camera3D->SetTarget(g_vec3Zero);
	g_camera3D->SetPosition({ 0.0f, 0.0f, -200.0f });

	g_sceneLight->SetDirectionLight(1, { 0.0f, 0.0f, 1.0f }, { 1.2f, 1.2f, 1.2f });

	// step-1 ベクトルを定義する。

	// ここからゲームループ。
	while (DispatchWindowMessage())
	{
		// step-3 コントローラーの入力でZ軸周りの回転行列を作成して回転させる。
		
		// step-4 コントローラーの入力でX軸周りの回転行列を作成して回転させる。

		// step-5 コントローラーの入力でY軸周りの回転行列を作成して回転させる。

		// step-2 確認のためにベクトルを表示する。

		K2Engine::GetInstance()->Execute();

	}
	// DeleteGO(bg);
	K2Engine::DeleteInstance();

	return 0;
}

