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

	// step-2 ���̃��f�������[�h����B

	// step-3 �f�J���g���W�n�ł̍��W���w�肷��B

	// ��������Q�[�����[�v�B
	while (DispatchWindowMessage())
	{
		// step-4 ���̂���₱�����X�V����B
	
		// step-5 ����`�悷��B

		K2Engine::GetInstance()->Execute();
	
	}
	K2Engine::DeleteInstance();

#ifdef _DEBUG
	ReportLiveObjects();
#endif // _DEBUG
	return 0;
}

