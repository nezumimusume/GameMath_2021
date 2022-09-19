#include "stdafx.h"
#include "system/system.h"



///////////////////////////////////////////////////////////////////
// �E�B���h�E�v���O�����̃��C���֐��B
///////////////////////////////////////////////////////////////////
int WINAPI wWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPWSTR lpCmdLine, int nCmdShow)
{
	//�Q�[���̏������B
	InitGame(hInstance, hPrevInstance, lpCmdLine, nCmdShow, TEXT("Game"));
	g_camera3D->SetPosition(0.0f, 500.0f, -1000.0f);
	g_camera3D->SetTarget(0.0f, 0.0f, 0.0f);

	auto& renderContext = g_graphicsEngine->GetRenderContext();
	// ���C�g��^�ォ��ݒ�B
	g_sceneLight->SetDirectionLight(0, { 0.0f, -1.0f, 0.0f }, { 0.8f, 0.8f, 0.8f });
	g_renderingEngine->SetCascadeNearAreaRates(0.1f, 0.4f, 0.2f);
	// �w�i���f�������[�h
	ModelRender bgModelRender;
	bgModelRender.Init("Assets/modelData/bg/bg.tkm");

	// ModelRender�N���X�̃I�u�W�F�N�g���T��`����B
	ModelRender starRender[5];

	// ���̃��f�������[�h����B
	for (int i = 0; i < 5; i++) {
		starRender[i].Init("Assets/modelData/star.tkm");
	}

	// step-1 3D��ԂŐ��̍��W���w�肷��B

	// ��������Q�[�����[�v�B
	while (DispatchWindowMessage())
	{
		// �J�������񂷁B
		Quaternion qRot;
		qRot.SetRotationDegY(0.3f);
		g_camera3D->RotateOriginTarget(qRot);
		// ���̂���₱�����X�V����B
		for (int i = 0; i < 5; i++) {
			starRender[i].Update();
		}
		// ����`�悷��B
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

