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
	// step-1 ベクトルの座標を定義する。
	Vector4 pos;
	pos.x = 0.0f;
	pos.y = 0.0f;
	pos.z = 0.0f;
	pos.w = 1.0f;

	// ここからゲームループ。
	while (DispatchWindowMessage())
	{
		// step-2 コントローラーの入力でベクトルをX方向に2平行移動させる。
		if (g_pad[0]->IsPress(enButtonA)) {
			// X方向に+4移動する平行移動行列を作成する。
			float m[4][4] = {
				{ 1, 0, 0, 0 },		// 1行目
				{ 0, 1, 0, 0 },		// 2行目
				{ 0, 0, 1, 0 },		// 3行目
				{ 2, 0, 0, 1 }		// 4行目
			};

			// ベクトルと行列の乗算を行う。
			Vector4 vSrc = pos;
			pos.x = vSrc.x * m[0][0] + vSrc.y * m[1][0] + vSrc.z * m[2][0] + vSrc.w * m[3][0];
			pos.y = vSrc.x * m[0][1] + vSrc.y * m[1][1] + vSrc.z * m[2][1] + vSrc.w * m[3][1];
			pos.z = vSrc.x * m[0][2] + vSrc.y * m[1][2] + vSrc.z * m[2][2] + vSrc.w * m[3][2];

		}
		
		Vector3 posTmp;
		posTmp.x = pos.x;
		posTmp.y = pos.y;
		posTmp.z = pos.z;
		//  確認のためにベクトルを表示する。
		g_k2Engine->DrawVector(
			v,			// 表示したいベクトル。
			posTmp			// 表示する座標。
		);

		K2Engine::GetInstance()->Execute();
	
	}
	// DeleteGO(bg);
	K2Engine::DeleteInstance();

	return 0;
}

