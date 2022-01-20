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
			float m[3][3];
			// 1行目
			m[0][0] = 1.02f;	// 1.02倍する
			m[0][1] = 0.0f;
			m[0][2] = 0.0f;
			// 2行目
			m[1][0] = 0.0f;
			m[1][1] = 1.0f;
			m[1][2] = 0.0f;
			// 3行目
			m[2][0] = 0.0f;
			m[2][1] = 0.0f;
			m[2][2] = 1.0f;

			// ベクトルと行列の乗算を行う。
			Vector3 vSrc = v;
			v.x = vSrc.x * m[0][0] + vSrc.y * m[1][0] + v.z * m[2][0];
			v.y = vSrc.x * m[0][1] + vSrc.y * m[1][1] + v.z * m[2][1];
			v.z = vSrc.x * m[0][2] + vSrc.y * m[1][2] + v.z * m[2][2];
		}
		// step-2 コントローラーの入力でY軸方向への拡大行列を作成して拡大させる。
		if (g_pad[0]->IsPress(enButtonB)) {
			float m[3][3];
			// 1行目
			m[0][0] = 1.0f;	
			m[0][1] = 0.0f;
			m[0][2] = 0.0f;
			// 2行目
			m[1][0] = 0.0f;
			m[1][1] = 1.02f; // 1.02倍する
			m[1][2] = 0.0f;
			// 3行目
			m[2][0] = 0.0f;
			m[2][1] = 0.0f;
			m[2][2] = 1.0f;

			// ベクトルと行列の乗算を行う。
			Vector3 vSrc = v;
			v.x = vSrc.x * m[0][0] + vSrc.y * m[1][0] + v.z * m[2][0];
			v.y = vSrc.x * m[0][1] + vSrc.y * m[1][1] + v.z * m[2][1];
			v.z = vSrc.x * m[0][2] + vSrc.y * m[1][2] + v.z * m[2][2];
		}

		// step-3 コントローラーの入力でZ軸方向への拡大行列を作成して拡大させる。
		if (g_pad[0]->IsPress(enButtonY)) {
			float m[3][3];
			// 1行目
			m[0][0] = 1.0f;
			m[0][1] = 0.0f;
			m[0][2] = 0.0f;
			// 2行目
			m[1][0] = 0.0f;
			m[1][1] = 1.0f;
			m[1][2] = 0.0f;
			// 3行目
			m[2][0] = 0.0f;
			m[2][1] = 0.0f;
			m[2][2] = 1.02f; // 1.02倍する

			// ベクトルと行列の乗算を行う。
			Vector3 vSrc = v;
			v.x = vSrc.x * m[0][0] + vSrc.y * m[1][0] + v.z * m[2][0];
			v.y = vSrc.x * m[0][1] + vSrc.y * m[1][1] + v.z * m[2][1];
			v.z = vSrc.x * m[0][2] + vSrc.y * m[1][2] + v.z * m[2][2];
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

