#include "stdafx.h"
#include "system/system.h"



///////////////////////////////////////////////////////////////////
// ウィンドウプログラムのメイン関数。
///////////////////////////////////////////////////////////////////
int WINAPI wWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPWSTR lpCmdLine, int nCmdShow)
{
	//ゲームの初期化。
	InitGame(hInstance, hPrevInstance, lpCmdLine, nCmdShow, TEXT("Game"));
	g_camera3D->SetPosition(0.0f, 500.0f, -1000.0f);
	g_camera3D->SetTarget(0.0f, 0.0f, 0.0f);

	auto& renderContext = g_graphicsEngine->GetRenderContext();
	// ライトを真上から設定。
	g_sceneLight->SetDirectionLight(0, { 0.0f, -1.0f, 0.0f }, { 0.8f, 0.8f, 0.8f });
	g_renderingEngine->SetCascadeNearAreaRates(0.1f, 0.4f, 0.2f);
	// 背景モデルをロード
	ModelRender bgModelRender;
	bgModelRender.Init("Assets/modelData/bg/bg.tkm");

	// ModelRenderクラスのオブジェクトを５つ定義する。
	ModelRender starRender[5];

	// 星のモデルをロードする。
	for (int i = 0; i < 5; i++) {
		starRender[i].Init("Assets/modelData/star.tkm");
	}

	// step-1 3D空間で星の座標を指定する。
	starRender[0].SetPosition( -400.0f, 100.0f, -200.0f );
	starRender[1].SetPosition( -200.0f, 200.0f,  200.0f );
	starRender[2].SetPosition(    0.0f, 300.0f, -200.0f );
	starRender[3].SetPosition(  200.0f, 200.0f,  200.0f );
	starRender[4].SetPosition(  400.0f, 100.0f, -200.0f );

	// ここからゲームループ。
	while (DispatchWindowMessage())
	{
		// カメラを回す。
		Quaternion qRot;
		qRot.SetRotationDegY(0.3f);
		g_camera3D->RotateOriginTarget(qRot);
		// 星のあれやこれやを更新する。
		for (int i = 0; i < 5; i++) {
			starRender[i].Update();
		}
		// 星を描画する。
		for (int i = 0; i < 5; i++) {
			starRender[i].Draw(renderContext);
		}
		
		bgModelRender.Draw(renderContext);
		K2Engine::GetInstance()->Execute();
	
	}
	K2Engine::DeleteInstance();

#ifdef _DEBUG
	ReportLiveObjects();
#endif // _DEBUG
	return 0;
}

