#include "stdafx.h"
#include "system/system.h"



///////////////////////////////////////////////////////////////////
// ウィンドウプログラムのメイン関数。
///////////////////////////////////////////////////////////////////
int WINAPI wWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPWSTR lpCmdLine, int nCmdShow)
{
	//ゲームの初期化。
	InitGame(hInstance, hPrevInstance, lpCmdLine, nCmdShow, TEXT("Game"));
	g_camera3D->SetPosition(0.0f, 200.0f, -1000.0f);
	g_camera3D->SetTarget(0.0f, 200.0f, 0.0f);

	auto& renderContext = g_graphicsEngine->GetRenderContext();
	// ライトを真上から設定。
	g_sceneLight->SetDirectionLight(0, { 0.0f, -1.0f, 0.0f }, { 0.8f, 0.8f, 0.8f });
	g_renderingEngine->SetCascadeNearAreaRates(0.1f, 0.4f, 0.2f);
	

	// ベクトルを定義する。
	Vector3 testVector;
	testVector.x = 100.0f;
	testVector.y = 100.0f;
	testVector.z = 0.0f;

	// ここからゲームループ。
	while (DispatchWindowMessage())
	{
		g_k2Engine->DrawVector(testVector, g_vec3Zero);

		// step-1 コントローラーのAボタンの入力でベクトルを倍にする。
		if (g_pad[0]->IsTrigger(enButtonA)) {
			testVector *= 2.0f;
		}

		// step-2 コントローラーのBボタンの入力でベクトルを1/2にする。
		if (g_pad[0]->IsTrigger(enButtonB)) {
			testVector /= 2.0f;
		}
		
		K2Engine::GetInstance()->Execute();
	
	}
	K2Engine::DeleteInstance();

#ifdef _DEBUG
	ReportLiveObjects();
#endif // _DEBUG
	return 0;
}

