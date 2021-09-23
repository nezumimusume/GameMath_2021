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

	// step-1 ModelRenderクラスのオブジェクトを５つ定義する。
	ModelRender starRender[5];

	// step-2 星のモデルをロードする。
	for (int i = 0; i < 5; i++) {
		starRender[i].Init("Assets/modelData/star.tkm");
	}

	// step-3 デカルト座標系での座標を指定する。
	starRender[0].SetPosition( -400.0f,   0.0f, 0.0f );
	starRender[1].SetPosition( -200.0f, 100.0f, 0.0f );
	starRender[2].SetPosition(    0.0f, 200.0f, 0.0f );
	starRender[3].SetPosition(  200.0f, 100.0f, 0.0f );
	starRender[4].SetPosition(  400.0f,   0.0f, 0.0f );


	// ここからゲームループ。
	while (DispatchWindowMessage())
	{
		// step-4 星のあれやこれやを更新する。
		for (int i = 0; i < 5; i++) {
			starRender[i].Update();
		}
		// step-5 星を描画する。
		for (int i = 0; i < 5; i++) {
			starRender[i].Draw(renderContext);
		}

		K2Engine::GetInstance()->Execute();
	
	}
	K2Engine::DeleteInstance();

#ifdef _DEBUG
	ReportLiveObjects();
#endif // _DEBUG
	return 0;
}

