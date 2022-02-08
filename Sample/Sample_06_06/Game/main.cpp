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
	
	// ベクトルを定義する。
	Vector3 v;
	v.x = 0.0f;
	v.y = 100.0f;
	v.z = 0.0f;

	// step-1 ベクトルの座標を表す変数を定義する。

	// ここからゲームループ。
	while (DispatchWindowMessage())
	{
		// step-2 コントローラーの入力でベクトルをX方向に2平行移動させる。
		
		// step-3 コントローラーの入力でベクトルをY方向に2平行移動させる。

		// step-4 コントローラーの入力でベクトルをZ方向に2平行移動させる。

		// step-5 確認のためベクトルを表示する。
		

		K2Engine::GetInstance()->Execute();
	
	}
	// DeleteGO(bg);
	K2Engine::DeleteInstance();

	return 0;
}

