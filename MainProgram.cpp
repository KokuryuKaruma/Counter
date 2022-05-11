// miniWinGame1.cpp : �A�v���P�[�V�����̃G���g�� �|�C���g���`���܂��B
//


/*
* Project -> Property -> �S�� -> �����Z�b�g -> �}���`�o�C�g�����Z�b�g���g�p����
*
*
*
*
*
*
*/
#include "stdafx.h"
#include "DxLib.h"
#include "MainProgram.h"
#include "ProgramMode.h" /*���[�h�ݒ�*/
#include "ProgramInput.h" /*���̓y���t�F����*/

#define MAX_LOADSTRING 100

// �O���[�o���ϐ�:
HINSTANCE hInst;                                // ���݂̃C���^�[�t�F�C�X
WCHAR szTitle[MAX_LOADSTRING];                  // �^�C�g�� �o�[�̃e�L�X�g
WCHAR szWindowClass[MAX_LOADSTRING];            // ���C�� �E�B���h�E �N���X��

// ���̃R�[�h ���W���[���Ɋ܂܂��֐��̐錾��]�����܂�:
ATOM                MyRegisterClass(HINSTANCE hInstance);
BOOL                InitInstance(HINSTANCE, int);
LRESULT CALLBACK    WndProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK    About(HWND, UINT, WPARAM, LPARAM);


int count = 0;
int mouseX = 0;//�}�E�X���W
int mouseY = 0;//�}�E�X���W

int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
	_In_opt_ HINSTANCE hPrevInstance,
	_In_ LPWSTR    lpCmdLine,
	_In_ int       nCmdShow) {
	UNREFERENCED_PARAMETER(hPrevInstance);
	UNREFERENCED_PARAMETER(lpCmdLine);


	// TODO: �����ɃR�[�h��}�����Ă��������B
	SetGraphMode(ScreenWidth, ScreenHeight, 32);//��ʃT�C�Y�w��
	SetOutApplicationLogValidFlag(FALSE);//Log.txt�𐶐����Ȃ��悤�ɐݒ�
	SetBackgroundColor(255, 255, 255);//�w�i�F�𔒂ɐݒ�
	ChangeWindowMode(TRUE);//��S��ʂɃZ�b�g

	SetUseCharCodeFormat(DX_CHARCODEFORMAT_UTF8);
	if (DxLib_Init() == 1) { return -1; }//�������Ɏ��s���ɃG���[��f�����ďI��


	// �O���[�o�������������������
	//LoadStringW(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
	//LoadStringW(hInstance, IDC_MINIWINGAME1, szWindowClass, MAX_LOADSTRING);
	//MyRegisterClass(hInstance);

	modeInit();
	// ���C�� ���[�v:
	int ext;
	while (ProcessMessage() == 0) {
		ClearDrawScreen();//����ʏ���
		SetDrawScreen(DX_SCREEN_BACK);//�`���𗠉�ʂ�
		inputPeripheralUpdate();
		//
		//�����ɖ��t���[���Ăԏ���������
		//

		ext = modeCtrl(0);

		ScreenFlip();//����ʂ�\��ʂɃR�s�[    
		if (ext) { break; }
	}

	DxLib_End();
	return (int)FALSE;
}



//
//  �֐�: WndProc(HWND, UINT, WPARAM, LPARAM)
//
//  �ړI: ���C�� �E�B���h�E�̃��b�Z�[�W���������܂��B
//
//  WM_COMMAND  - �A�v���P�[�V���� ���j���[�̏���
//  WM_PAINT    - ���C�� �E�B���h�E��`�悷��
//  WM_DESTROY  - ���~���b�Z�[�W��\�����Ė߂�
//
//
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam) {
	switch (message) {
	case WM_COMMAND:
	{
	}
	break;
	case WM_PAINT:
	{
	}
	break;
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	default:
		return DefWindowProc(hWnd, message, wParam, lParam);
	}
	return 0;
}

