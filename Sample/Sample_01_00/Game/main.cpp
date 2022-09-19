#include "stdafx.h"
#include "system/system.h"


///////////////////////////////////////////////////////////////////
// ウィンドウプログラムのメイン関数。
///////////////////////////////////////////////////////////////////
int WINAPI wWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPWSTR lpCmdLine, int nCmdShow)
{
	//ゲームの初期化。
	InitGame(hInstance, hPrevInstance, lpCmdLine, nCmdShow, TEXT("Game"));
	g_camera3D->SetPosition(0.0f, 0.0f, -1500.0f);
	g_camera3D->SetTarget(0.0f, 0.0f, 0.0f);

	auto& renderContext = g_graphicsEngine->GetRenderContext();
	auto& sceneLit = g_sceneLight->GetSceneLight();
	sceneLit.ambinetLight.Set(1.2f, 1.2f, 1.2f);
	
	// step-1 ModelRenderクラスのオブジェクトを５つ定義する。

	// step-2 星のモデルをロードする。

	// step-3 デカルト座標系での座標を指定する。

	// ここからゲームループ。
	while (DispatchWindowMessage())
	{
		// step-4 星のあれやこれやを更新する。
	
		// step-5 星を描画する。

		K2Engine::GetInstance()->Execute();
	
	}
	K2Engine::DeleteInstance();

#ifdef _DEBUG
	ReportLiveObjects();
#endif // _DEBUG
	return 0;
}

