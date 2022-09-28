#include "stdafx.h"
#include "system/system.h"



///////////////////////////////////////////////////////////////////
// �E�B���h�E�v���O�����̃��C���֐��B
///////////////////////////////////////////////////////////////////
int WINAPI wWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPWSTR lpCmdLine, int nCmdShow)
{
	//�Q�[���̏������B
	InitGame(hInstance, hPrevInstance, lpCmdLine, nCmdShow, TEXT("Game"));
	g_camera3D->SetPosition(0.0f, 0.0f, -1000.0f);
	g_camera3D->SetTarget(0.0f, 0.0f, 0.0f);
	g_camera3D->SetUpdateProjMatrixFunc(Camera::EnUpdateProjMatrixFunc::enUpdateProjMatrixFunc_Ortho);
	g_camera3D->SetWidth(1500.0f);
	g_camera3D->SetHeight(1500.0f);

	auto& renderContext = g_graphicsEngine->GetRenderContext();
	// ���C�g��^�ォ��ݒ�B
	g_sceneLight->SetDirectionLight(0, { 0.0f, -1.0f, 0.0f }, { 0.8f, 0.8f, 0.8f });
	g_renderingEngine->SetCascadeNearAreaRates(0.1f, 0.4f, 0.2f);
	

	// step-1 �x�N�g�����`����B
	Vector3 testVector;
	testVector.x = 100.0f;
	testVector.y = 500.0f;
	testVector.z = 0.0f;

	int frameCounter = 60;
	float moveDirection = 1.0f;
	// ��������Q�[�����[�v�B
	while (DispatchWindowMessage())
	{
		frameCounter++;
		if (frameCounter > 120) {
			moveDirection *= -1.0f;
			frameCounter = 0;
		}
		testVector.x += 10.0f * moveDirection;
		// step-2 �x�N�g����\������B
		g_k2Engine->DrawVector(
			testVector,			// �������͕\���������x�N�g���B
			g_vec3Zero			// �������̓x�N�g���̊�_�B
		);
	
		K2Engine::GetInstance()->Execute();
	
	}
	K2Engine::DeleteInstance();

#ifdef _DEBUG
	ReportLiveObjects();
#endif // _DEBUG
	return 0;
}

