#include "stdafx.h"
#include "system/system.h"
#include "Background.h"

///////////////////////////////////////////////////////////////////
// �E�B���h�E�v���O�����̃��C���֐��B
///////////////////////////////////////////////////////////////////
int WINAPI wWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPWSTR lpCmdLine, int nCmdShow)
{
	//�Q�[���̏������B
	InitGame(hInstance, hPrevInstance, lpCmdLine, nCmdShow, TEXT("Game"));
	Background* bg = NewGO< Background>(0);

	g_camera3D->SetTarget(g_vec3Zero);
	g_camera3D->SetPosition({ 0.0f, 0.0f, -200.0f });
	
	g_sceneLight->SetDirectionLight(1, { 0.0f, 0.0f, 1.0f }, { 1.2f, 1.2f, 1.2f });
	
	// �x�N�g�����`����B
	Vector3 v;
	v.x = 0.0f;
	v.y = 100.0f;
	v.z = 0.0f;
	// step-1 �x�N�g���̍��W������w�X�ϐ����`����B
	Vector4 pos;
	pos.x = 0.0f;
	pos.y = 0.0f;
	pos.z = 0.0f;
	pos.w = 1.0f;

	// ��������Q�[�����[�v�B
	while (DispatchWindowMessage())
	{
		// step-2 �R���g���[���[�̓��͂Ńx�N�g����X������2���s�ړ�������B
		if (g_pad[0]->IsPress(enButtonA)) {
			// X������+4�ړ����镽�s�ړ��s����쐬����B
			float m[4][4] = {
				{ 1, 0, 0, 0 },		// 1�s��
				{ 0, 1, 0, 0 },		// 2�s��
				{ 0, 0, 1, 0 },		// 3�s��
				{ 2, 0, 0, 1 }		// 4�s��
			};

			// �x�N�g���ƍs��̏�Z���s���B
			Vector4 vSrc = pos;
			pos.x = vSrc.x * m[0][0] + vSrc.y * m[1][0] + vSrc.z * m[2][0] + vSrc.w * m[3][0];
			pos.y = vSrc.x * m[0][1] + vSrc.y * m[1][1] + vSrc.z * m[2][1] + vSrc.w * m[3][1];
			pos.z = vSrc.x * m[0][2] + vSrc.y * m[1][2] + vSrc.z * m[2][2] + vSrc.w * m[3][2];
		}
		
		// step-3 �R���g���[���[�̓��͂Ńx�N�g����Y������2���s�ړ�������B
		if (g_pad[0]->IsPress(enButtonB)) {
			// X������+4�ړ����镽�s�ړ��s����쐬����B
			float m[4][4] = {
				{ 1, 0, 0, 0 },		// 1�s��
				{ 0, 1, 0, 0 },		// 2�s��
				{ 0, 0, 1, 0 },		// 3�s��
				{ 0, 2, 0, 1 }		// 4�s��
			};

			// �x�N�g���ƍs��̏�Z���s���B
			Vector4 vSrc = pos;
			pos.x = vSrc.x * m[0][0] + vSrc.y * m[1][0] + vSrc.z * m[2][0] + vSrc.w * m[3][0];
			pos.y = vSrc.x * m[0][1] + vSrc.y * m[1][1] + vSrc.z * m[2][1] + vSrc.w * m[3][1];
			pos.z = vSrc.x * m[0][2] + vSrc.y * m[1][2] + vSrc.z * m[2][2] + vSrc.w * m[3][2];

		}

		// step-4 �R���g���[���[�̓��͂Ńx�N�g����Z������2���s�ړ�������B
		if (g_pad[0]->IsPress(enButtonX)) {
			// X������+4�ړ����镽�s�ړ��s����쐬����B
			float m[4][4] = {
				{ 1, 0, 0, 0 },		// 1�s��
				{ 0, 1, 0, 0 },		// 2�s��
				{ 0, 0, 1, 0 },		// 3�s��
				{ 0, 0, 2, 1 }		// 4�s��
			};

			// �x�N�g���ƍs��̏�Z���s���B
			Vector4 vSrc = pos;
			pos.x = vSrc.x * m[0][0] + vSrc.y * m[1][0] + vSrc.z * m[2][0] + vSrc.w * m[3][0];
			pos.y = vSrc.x * m[0][1] + vSrc.y * m[1][1] + vSrc.z * m[2][1] + vSrc.w * m[3][1];
			pos.z = vSrc.x * m[0][2] + vSrc.y * m[1][2] + vSrc.z * m[2][2] + vSrc.w * m[3][2];

		}

		// step-5 �m�F�̂��߃x�N�g����\������B
		// �x�N�g���̍��W��ݒ�B
		// ���W�͂R������ԂȂ̂ŁA�R�����x�N�g���ɕϊ�����B
		Vector3 posTmp;
		posTmp.x = pos.x;
		posTmp.y = pos.y;
		posTmp.z = pos.z;
		//  �m�F�̂��߂Ƀx�N�g����\������B
		g_k2Engine->DrawVector(
			v,			// �\���������x�N�g���B
			posTmp		// �\��������W�B
		);

		K2Engine::GetInstance()->Execute();
	
	}
	// DeleteGO(bg);
	K2Engine::DeleteInstance();

	return 0;
}

