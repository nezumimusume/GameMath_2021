#include "stdafx.h"
#include "system/system.h"



///////////////////////////////////////////////////////////////////
// ウィンドウプログラムのメイン関数。
///////////////////////////////////////////////////////////////////
int WINAPI wWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPWSTR lpCmdLine, int nCmdShow)
{
	//ゲームの初期化。
	InitGame(hInstance, hPrevInstance, lpCmdLine, nCmdShow, TEXT("Game"));
	g_camera3D->SetPosition(0.0f, 2.0f, -10.0f);
	g_camera3D->SetTarget(0.0f, 2.0f, 0.0f);

	auto& renderContext = g_graphicsEngine->GetRenderContext();
	// ライトを真上から設定。
	g_sceneLight->SetDirectionLight(0, { 0.0f, -1.0f, 0.0f }, { 0.8f, 0.8f, 0.8f });
	g_renderingEngine->SetCascadeNearAreaRates(0.1f, 0.4f, 0.2f);
	
	// step-1 ベクトルを定義する。
	Vector3 testVector;
	testVector.x = 5.0f;
	testVector.y = 5.0f;
	testVector.z = 0.0f;

	// ここからゲームループ。
	while (DispatchWindowMessage())
	{
		// step-2 コントローラーのAボタンの入力でベクトルを正規化する。
		if (g_pad[0]->IsTrigger(enButtonA)) {
			// まずはベクトルの長さを求める。
			float len = testVector.Length();
			// 続いて、ベクトルの各要素を長さで割り算する。
			testVector.x /= len;
			testVector.y /= len;
			testVector.z /= len;
		}	
		// step-3 ベクトルを表示する。
		g_k2Engine->DrawVector(testVector, g_vec3Zero);

		K2Engine::GetInstance()->Execute();
	
	}
	K2Engine::DeleteInstance();

#ifdef _DEBUG
	ReportLiveObjects();
#endif // _DEBUG
	return 0;
}

