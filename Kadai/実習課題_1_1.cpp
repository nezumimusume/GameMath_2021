#include "stdafx.h"
#include "system/system.h"


///////////////////////////////////////////////////////////////////
// �E�B���h�E�v���O�����̃��C���֐��B
///////////////////////////////////////////////////////////////////
int WINAPI wWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPWSTR lpCmdLine, int nCmdShow)
{
	//�Q�[���̏������B
	InitGame(hInstance, hPrevInstance, lpCmdLine, nCmdShow, TEXT("Game"));
	g_camera3D->SetPosition(0.0f, 0.0f, -1500.0f);
	g_camera3D->SetTarget(0.0f, 0.0f, 0.0f);

	auto& renderContext = g_graphicsEngine->GetRenderContext();
	auto& sceneLit = g_sceneLight->GetSceneLight();
	sceneLit.ambinetLight.Set(1.2f, 1.2f, 1.2f);

	// step-1 ModelRender�N���X�̃I�u�W�F�N�g���T��`����B
	ModelRender starRender[5];

	// step-2 ���̃��f�������[�h����B
	for (int i = 0; i < 5; i++) {
		starRender[i].Init("Assets/modelData/star.tkm");
	}

	// step-3 �f�J���g���W�n�ł̍��W���w�肷��B
	Vector3 starPosition[5];
	starPosition[0].Set(-400.0f, -300.0f, 0.0f);
	starPosition[1].Set(-200.0f, -200.0f, 0.0f);
	starPosition[2].Set(0.0f, -100.0f, 0.0f);
	starPosition[3].Set(200.0f, -200.0f, 0.0f);
	starPosition[4].Set(400.0f, -300.0f, 0.0f);

	for (int i = 0; i < 5; i++) {
		starRender[i].SetPosition(starPosition[i]);
	}

	float moveDirection = 1.0f;
	int frameCounter = 0;
	// ��������Q�[�����[�v�B
	while (DispatchWindowMessage())
	{
		frameCounter++;
		if (frameCounter == 120) {
			// �ړ������𔽓]������B
			moveDirection *= -1.0f;
			frameCounter = 0.0f;
			
		}
		for (int i = 0; i < 5; i++) {
			starPosition[i].y += 5.0f * moveDirection;
			starRender[i].SetPosition(starPosition[i]);
		}
		
		// step-4 ���̂���₱�����X�V����B
		for (int i = 0; i < 5; i++) {
			starRender[i].Update();
		}
		// step-5 ����`�悷��B
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

