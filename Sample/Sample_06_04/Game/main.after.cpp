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
	v.x = 8.0f;
	v.y = 8.0f;
	v.z = 8.0f;

	// ここからゲームループ。
	while (DispatchWindowMessage())
	{
		// step-1 コントローラーの入力でX軸法にへの拡大行列を作成して拡大させる。
		if (g_pad[0]->IsPress(enButtonA)) {
			Matrix m;
			// X軸方向に1.01拡大する行列を作成する。
			m.MakeScaling( 1.01f, 1.0f, 1.0f );
			// ベクトルと行列の乗算を行う。
			m.Apply(v);
		}
		// step-2 コントローラーの入力でY軸方向への拡大行列を作成して拡大させる。
		if (g_pad[0]->IsPress(enButtonB)) {
			Matrix m;
			// Y軸方向に1.01拡大する行列を作成する。
			m.MakeScaling( 1.0f, 1.01f, 1.0f );
			// ベクトルと行列の乗算を行う。
			m.Apply(v);
		}

		// step-3 コントローラーの入力でZ軸方向への拡大行列を作成して拡大させる。
		if (g_pad[0]->IsPress(enButtonX)) {
			Matrix m;
			// Z軸方向に1.01拡大する行列を作成する。
			m.MakeScaling( 1.0f, 1.0f, 1.01f );
			// ベクトルと行列の乗算を行う。
			m.Apply(v);
		}

		//  確認のためにベクトルを表示する。
		g_k2Engine->DrawVector(
			v,			// 表示したいベクトル。
			g_vec3Zero	// 表示する座標。
		);

		K2Engine::GetInstance()->Execute();
	
	}
	// DeleteGO(bg);
	K2Engine::DeleteInstance();

	return 0;
}

