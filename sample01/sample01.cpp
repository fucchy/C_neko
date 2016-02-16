// sample01.cpp

#include <Windows.h>

LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);
ATOM InitApp(HINSTANCE);
BOOL InitInstance(HINSTANCE, int);

TCHAR szClassName[] = TEXT("sample01"); // �E�B���h�E�N���X

// Windows�v���O�����̃G���g���[�|�C���g
int WINAPI WinMain(HINSTANCE hCurInst, HINSTANCE hPrevInst, LPSTR lpsCmdLine, int nCmdShow)
{
	MSG msg;
	BOOL bRet;

	if (!InitApp(hCurInst))
		return FALSE;
	if (!InitInstance(hCurInst, nCmdShow))
		return FALSE;

	// ���b�Z�[�W���擾
	while ((bRet = GetMessage(&msg, NULL, 0, 0)) != 0) {
		if (bRet == -1) {
			break;
		}
		else
		{
			TranslateMessage(&msg); // ���b�Z�[�W��ϊ�
			DispatchMessage(&msg); // ���b�Z�[�W�𑗏o
		}
	}
	return (int)msg.wParam;
}

// �E�B���h�E�N���X�̓o�^
ATOM InitApp(HINSTANCE hInst)
{
	WNDCLASSEX wc;
	wc.cbSize = sizeof(WNDCLASSEX); // �\���̂̃T�C�Y
	wc.style = CS_HREDRAW | CS_VREDRAW; // �N���X�̃X�^�C��
	wc.lpfnWndProc = WndProc; // �v���V�[�W����
	wc.cbClsExtra = 0; // �⏕������
	wc.cbWndExtra = 0; // �⏕������
	wc.hInstance = hInst; // �C���X�^���X
	wc.hIcon = (HICON)LoadImage( // �A�C�R��
		NULL, MAKEINTRESOURCE(IDI_APPLICATION),
		IMAGE_ICON, 0, 0, LR_DEFAULTSIZE | LR_SHARED);
	wc.hCursor = (HCURSOR)LoadImage( // �J�[�\��
		NULL, MAKEINTRESOURCE(IDC_ARROW),
		IMAGE_CURSOR, 0, 0, LR_DEFAULTSIZE | LR_SHARED);
	wc.hbrBackground = // �w�i�u���V
		(HBRUSH)GetStockObject(WHITE_BRUSH);
	wc.lpszMenuName = NULL; // ���j���[��
	wc.lpszClassName = szClassName; // �N���X��
	wc.hIconSm = (HICON)LoadImage( // �������A�C�R��
		NULL, MAKEINTRESOURCE(IDI_APPLICATION),
		IMAGE_ICON, 0, 0, LR_DEFAULTSIZE | LR_SHARED);
	return (RegisterClassEx(&wc));
}

// �E�B���h�E�̐���
BOOL InitInstance(HINSTANCE hInst, int nCmdShow)
{
	HWND hWnd;

	hWnd = CreateWindow(szClassName, // �N���X��
		TEXT("�L�ł��킩��Windows�v���O���~���O"), // �E�B���h�E��
		WS_OVERLAPPEDWINDOW, // �E�B���h�E�X�^�C��
		CW_USEDEFAULT, // x�ʒu
		CW_USEDEFAULT, // y�ʒu
		CW_USEDEFAULT, // �E�B���h�E��
		CW_USEDEFAULT, // �E�B���h�E����
		NULL, // �e�E�B���h�E�̃n���h���A�e�����Ƃ���NULL
		NULL, // ���j���[�n���h���A�N���X���j���[���g���Ƃ���NULL
		hInst, // �C���X�^���X�n���h��
		NULL // �E�B���h�E�쐬�f�[�^
		);
	if (!hWnd)
		return FALSE;
	ShowWindow(hWnd, nCmdShow); // �E�B���h�E�̕\����Ԃ�ݒ�
	UpdateWindow(hWnd); // �E�B���h�E���X�V
	return TRUE;
}

// �E�B���h�E�v���V�[�W��(�R�[���o�b�N�֐�)
LRESULT CALLBACK WndProc(HWND hWnd, UINT msg, WPARAM wp, LPARAM lp)
{
	switch (msg) {
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	default:
		return (DefWindowProc(hWnd, msg, wp, lp));
	}
	return 0;
}