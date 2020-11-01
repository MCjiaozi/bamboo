// GT_HelloWorldWin32.cpp
// compile with: /D_UNICODE /DUNICODE /DWIN32 /D_WINDOWS /c
// ����һ����򵥵�Win32���������Ϊ��������Ӧ�ó����ģ��

#define IDB_1     3301  
#define IDB_2     3302  
#define IDB_3   3303 
#define IDB_4   3304
#define IDB_5   3305
#define IDB_6   3306
#define IDB_7   3307
#define IDB_8   3308
#define IDB_9   3309
#define IDB_10   3310
#define IDB_11   3311
#define IDB_12   3312
#define IDB_13   3313
#define IDB_14   3314
#define IDB_15   3315
#define IDB_16   3316
#define IDB_17   3317
#define IDB_18   3318
#define IDB_19   3319
#define IDB_20   3320
#define IDB_21   3321
#define IDB_22   3322
#define IDB_23   3323
#define IDB_24   3324
#define IDB_25   3325
#define IDB_26   3326
#define IDB_27   3327
#define IDB_28   3328
#define IDB_29   3329
#define IDB_30   3330
#include <windows.h>
#include <stdlib.h>
#include <string.h>
#include <tchar.h>
#include <WinInet.h>//DeleteUrlCacheEntry
#include <iostream>//URLDownloadToFile
#include <UrlMon.h>//URLDownloadToFile
#include "resource.h"
#pragma comment(lib, "wininet.lib")//DeleteUrlCacheEntry
#pragma comment(lib, "urlmon.lib")//URLDownloadToFile
using namespace std;//URLDownloadToFile

// ------------------------Global variables---------------------------------
// ����������
static TCHAR szWindowClass[] = _T("��������");
// Ӧ�ó�������������ֵ��ַ���
static TCHAR szTitle[] = _T("��������");

//HINSTANCE ��Windows���һ���������ͣ������ڱ�ʾ����¼��һ�������ʵ����
//����HMODULE��һ���ģ�ͨ�õģ��������������վ���32λ�޷��ų����Σ���
//HINSTANCE���ֿ������� HANDLE(���) + INSTANCE��ʵ����
//ʵ������һ��������qq������������Կ�ͬʱ��2��qq�ţ�������������qq���ֻ��һ�ݡ�
//��2��qq�ž���qq��2��ʵ��
HINSTANCE hInst;

// -------------------------��ҪԤ����ĺ��������ڴ˴������:----------------------------


//ÿ�� Windows ����Ӧ�ó���������һ�����ڹ��̺���
//�˺�������Ӧ�ó���Ӳ���ϵͳ�н��յĴ�����Ϣ�� 
//���磬���Ӧ�ó���ĶԻ������С�ȷ������ť����ô�û������ð�ťʱ��
//����ϵͳ����Ӧ�ó�����һ����Ϣ��֪ͨ��ť�ѱ�������WndProc ����Ը��¼�������Ӧ��
//�ڱ����У���Ӧ����Ӧ�����ǹرնԻ���
LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);
//-------------------------------------��ʽ����-----------------------------------------

//�����庯��(��ڹ���)
//ÿ������ Win32 ��Ӧ�ó���ĺ���������� WinMain ����
//����ÿ�� C Ӧ�ó���� C++ ����̨Ӧ�ó�������ʼ�������� main ����
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {
	//���� WNDCLASSEX ���͵Ĵ�����ṹ�� �˽ṹ�������ڴ��ڵ���Ϣ
	//����Ӧ�ó���ͼ�ꡢ���ڱ���ɫ������������ʾ�����ơ����ڹ��̺��������Ƶȡ�
	WNDCLASSEX wcex;
	wcex.cbSize = sizeof(WNDCLASSEX);
	wcex.style = CS_HREDRAW | CS_VREDRAW;
	wcex.lpfnWndProc = WndProc;
	wcex.cbClsExtra = 0;
	wcex.cbWndExtra = 0;
	wcex.hInstance = hInstance;
	wcex.hIcon = LoadIcon(hInstance, (LPCTSTR)IDI_ICON1);
	wcex.hCursor = LoadCursor(NULL, IDC_ARROW);
	wcex.hbrBackground = (HBRUSH)CreateSolidBrush(RGB(240, 240, 240));
	wcex.lpszMenuName = NULL;
	wcex.lpszClassName = szWindowClass;
	wcex.hIconSm = LoadIcon(wcex.hInstance, (LPCTSTR)IDI_ICON1);

	//���Ѵ����Ĵ��������ע�ᡣ ʹ�� RegisterClassEx ����������������ṹ��Ϊ�������ݡ�
	if (!RegisterClassEx(&wcex)) {
		MessageBox(NULL, _T("Call to RegisterClassEx failed!"), _T("����"), NULL);
		return 1;
	}

	// Store instance handle in our global variable 
	// �����ʵ���洢��ȫ�ֱ�����
	hInst = hInstance;


	/*��������
	HWND CreateWindow(
	LPCTSTR lpClassName,  //��������
	LPCTSTR lpWindowName, //���ڱ���
	DWORD dwStyle,        //���ڷ��WS��ͷ
	int x,                //�������Ͻ�x����
	int y,                //�������Ͻ�y����
	int nWidth,           //���ڿ��
	int nHeight,          //���ڸ߶�
	HWND hWndParent,      //�����ھ��
	HMENU hMenu,          //�˵����
	HANDLE hlnstance,     //���ھ��
	LPVOID lpParam);      //��ֵ�ᴫ�ݸ�����WM_CREATE��Ϣ��һ������
	*/
	HWND hWnd = CreateWindow(szWindowClass, szTitle, WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, NULL, NULL, hInstance, NULL);
	if (!hWnd) {
		MessageBox(NULL, _T("Call to CreateWindow failed!"), _T("����"), NULL);
		return 1;
	}
	// ShowWindow �����Ĳ�������: 
	// hWnd: CreateWindow�������صĴ��ھ�� 
	// nCmdShow: the fourth parameter from WinMain 
	ShowWindow(hWnd, nCmdShow);
	// UpdateWindow�������ڸ��´���ָ��������
	// ������ڸ��µ�����Ϊ�գ�UpdateWindow�����ͷ���һ��WM_PAINT��Ϣ������ָ�����ڵĿͻ�����
	// �����ƹ�Ӧ�ó������Ϣ���У�ֱ�ӷ���WM_PAINT��Ϣ��ָ�����ڵĴ��ڹ���
	// �����������Ϊ�գ��򲻷�����Ϣ��
	UpdateWindow(hWnd);
	// Main message loop: 
	// ���������������ϵͳ��������Ϣ����Ϣѭ���� 
	// ��Ӧ�ó����յ�һ����Ϣʱ����ѭ��������Ϣ���ȵ� WndProc �����Խ��д��� 
	MSG msg;
	while (GetMessage(&msg, NULL, 0, 0)) {
		TranslateMessage(&msg); //������Ϣ
		DispatchMessage(&msg);  //��ǲ��Ϣ
	}
	return (int)msg.wParam;
}

//������
void update() {
	DeleteUrlCacheEntry(_T("https://www.mcjiaozi.icu/update/bamboo/version.txt"));
	if (S_OK != URLDownloadToFile(NULL, _T("https://www.mcjiaozi.icu/update/bamboo/version.txt"), _T("version.txt"), 0, 0)) {
		MessageBox(NULL, _T("������ʧ�ܣ�\n��ǰ�����߸�����վ��"), _T("����"), MB_OK | MB_ICONERROR);
	}
	FILE* fp = fopen("version.txt", "r");//�ӻ����ȡ�汾��
	ShellExecute(NULL, NULL, _T("cmd"), _T("/c del version.txt"), NULL, SW_SHOW);
	if (fp == NULL)MessageBox(NULL, _T("������ʧ�ܣ��޷���ȡ���߰汾�ţ�\n��ǰ�����߸�����վ��"), _T("����"), MB_OK | MB_ICONERROR);//�����ȡ�İ汾��ΪNULL���򱨴�
	char ch;
	ch = getc(fp);
	int newestversion = ch;
	if (ch > 52) {
		int updateaa = MessageBox(NULL, _T("���°汾���ã�Ҫ������\n���ȷ�����ؽ���ʼ��"), _T("������"), MB_OKCANCEL | MB_ICONQUESTION);
		if (updateaa == IDOK) {
			DeleteUrlCacheEntry(_T("https://www.mcjiaozi.icu/download/software/bamboo/bamboo_installer.exe"));
			if (S_OK != URLDownloadToFile(NULL, _T("https://www.mcjiaozi.icu/download/software/bamboo/bamboo_installer.exe"), _T("bamboo_installer.exe"), 0, 0)) {
				MessageBox(NULL, _T("���ظ���ʧ�ܣ�\n��ǰ�����߸�����վ��"), _T("����"), MB_OK | MB_ICONERROR);
				return;
			}
			ShellExecute(NULL, NULL, _T("cmd"), _T("/c copy bamboo_installer.exe %temp%\\bamboo\\bamboo_installer.exe&&del bamboo_installer.exe&&start %temp%\\bamboo\\bamboo_installer.exe"), NULL, SW_SHOW);
			return;
		}
		else if (updateaa == 0) {
			MessageBox(NULL, _T("�ڴ治��!"), _T("����"), MB_OK | MB_ICONERROR);
			return;
		}
		else return;

	}
	else if (ch == 52) {
		MessageBox(NULL, _T("���Ŀͻ��������°汾��"), _T("������"), NULL);
		return;
	}
	else if (ch < 52) {
		MessageBox(NULL, _T("������ʧ�ܣ�\nδ֪����"), _T("����"), MB_OK | MB_ICONERROR);
		return;
	}
	else return;
	return;
}
// //  ����: WndProc(HWND, UINT, WPARAM, LPARAM) 
// //  Ŀ��:  �����������������Ϣ
// //  WM_PAINT��Ϣ������������� 
// //  WM_DESTROY��Ϣ����Ͷ��һ���˳���Ϣ������ 
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam) {
	PAINTSTRUCT ps;
	RECT rect;
	HDC hdc;
	HFONT h;
	int shutdown;
	switch (message) {
	case WM_CREATE:
		CreateWindow(_T("Button"), _T("�鿴ϵͳ��Ϣ"), WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON, 0, 182, 300, 30, hWnd, (HMENU)IDB_1, NULL, NULL);
		CreateWindow(_T("Button"), _T("�����ҵ���վ"), WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON, 0, 212, 300, 30, hWnd, (HMENU)IDB_2, NULL, NULL);
		CreateWindow(_T("Button"), _T("����Github"), WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON, 0, 242, 300, 30, hWnd, (HMENU)IDB_3, NULL, NULL);
		CreateWindow(_T("Button"), _T("��������ʾ��"), WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON, 0, 272, 300, 30, hWnd, (HMENU)IDB_4, NULL, NULL);
		CreateWindow(_T("Button"), _T("��PowerShell"), WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON, 0, 302, 300, 30, hWnd, (HMENU)IDB_5, NULL, NULL);
		CreateWindow(_T("Button"), _T("�رռ����(��������)��������"), WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON, 0, 382, 300, 30, hWnd, (HMENU)IDB_6, NULL, NULL);
		CreateWindow(_T("Button"), _T("�رռ����(��������)��1���Ӻ�"), WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON, 0, 412, 300, 30, hWnd, (HMENU)IDB_7, NULL, NULL);
		CreateWindow(_T("Button"), _T("�رռ����(��������)��5���Ӻ�"), WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON, 0, 442, 300, 30, hWnd, (HMENU)IDB_8, NULL, NULL);
		CreateWindow(_T("Button"), _T("�رռ����(��������)��10���Ӻ�"), WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON, 0, 472, 300, 30, hWnd, (HMENU)IDB_9, NULL, NULL);
		CreateWindow(_T("Button"), _T("�رռ����(��������)��30���Ӻ�"), WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON, 0, 502, 300, 30, hWnd, (HMENU)IDB_10, NULL, NULL);
		CreateWindow(_T("Button"), _T("�رռ����(��������)��1Сʱ��"), WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON, 0, 532, 300, 30, hWnd, (HMENU)IDB_11, NULL, NULL);
		CreateWindow(_T("Button"), _T("��Զ�̹ػ��Ի��� / ��ʾͼ���û�����(GUI)"), WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON, 0, 562, 900, 30, hWnd, (HMENU)IDB_12, NULL, NULL);
		CreateWindow(_T("Button"), _T("��ֹϵͳ�ر�"), WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON, 0, 592, 900, 30, hWnd, (HMENU)IDB_13, NULL, NULL);
		CreateWindow(_T("Button"), _T("��ȫ�رղ������������������"), WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON, 300, 382, 300, 30, hWnd, (HMENU)IDB_14, NULL, NULL);
		CreateWindow(_T("Button"), _T("��ȫ�رղ������������1���Ӻ�"), WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON, 300, 412, 300, 30, hWnd, (HMENU)IDB_15, NULL, NULL);
		CreateWindow(_T("Button"), _T("��ȫ�رղ������������5���Ӻ�"), WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON, 300, 442, 300, 30, hWnd, (HMENU)IDB_16, NULL, NULL);
		CreateWindow(_T("Button"), _T("��ȫ�رղ������������10���Ӻ�"), WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON, 300, 472, 300, 30, hWnd, (HMENU)IDB_17, NULL, NULL);
		CreateWindow(_T("Button"), _T("��ȫ�رղ������������30���Ӻ�"), WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON, 300, 502, 300, 30, hWnd, (HMENU)IDB_18, NULL, NULL);
		CreateWindow(_T("Button"), _T("��ȫ�رղ������������1Сʱ��"), WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON, 300, 532, 300, 30, hWnd, (HMENU)IDB_19, NULL, NULL);
		CreateWindow(_T("Button"), _T("������"), WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON, 300, 182, 300, 30, hWnd, (HMENU)IDB_20, NULL, NULL);
		CreateWindow(_T("Button"), _T("��ȫ�رռ������������"), WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON, 600, 382, 300, 30, hWnd, (HMENU)IDB_21, NULL, NULL);
		CreateWindow(_T("Button"), _T("��ȫ�رռ������1���Ӻ�"), WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON, 600, 412, 300, 30, hWnd, (HMENU)IDB_22, NULL, NULL);
		CreateWindow(_T("Button"), _T("��ȫ�رռ������5���Ӻ�"), WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON, 600, 442, 300, 30, hWnd, (HMENU)IDB_23, NULL, NULL);
		CreateWindow(_T("Button"), _T("��ȫ�رռ������10���Ӻ�"), WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON, 600, 472, 300, 30, hWnd, (HMENU)IDB_24, NULL, NULL);
		CreateWindow(_T("Button"), _T("��ȫ�رռ������30���Ӻ�"), WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON, 600, 502, 300, 30, hWnd, (HMENU)IDB_25, NULL, NULL);
		CreateWindow(_T("Button"), _T("��ȫ�رռ������1Сʱ��"), WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON, 600, 532, 300, 30, hWnd, (HMENU)IDB_26, NULL, NULL);
		CreateWindow(_T("Button"), _T("�鿴������־"), WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON, 300, 212, 300, 30, hWnd, (HMENU)IDB_27, NULL, NULL);
		CreateWindow(_T("Button"), _T("�������߸�����վ"), WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON, 300, 242, 300, 30, hWnd, (HMENU)IDB_28, NULL, NULL);
		CreateWindow(_T("Button"), _T("ˢ�� DNS ��������"), WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON, 300, 272, 300, 30, hWnd, (HMENU)IDB_29, NULL, NULL);
		CreateWindow(_T("Button"), _T("��Դ���֤"), WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON, 300, 302, 300, 30, hWnd, (HMENU)IDB_30, NULL, NULL);
		break;
	case WM_PAINT:
		//Ҫ���� WM_PAINT ��Ϣ������Ӧ���� BeginPaint
		//Ȼ�������е��߼��Լ��ڴ����в����ı�����ť�������ؼ���
		//Ȼ����� EndPaint�� 
		// -----------------����δ����Ӧ�ó�����в���------------------------ 
		// ���ڴ�Ӧ�ó��򣬿�ʼ���úͽ�������֮����߼����ڴ�������ʾ�ַ��� ��Hello��World!����
		// ��ע�� TextOut ����������ʾ�ַ�����
		hdc = BeginPaint(hWnd, &ps);
		SetBkMode(hdc, TRANSPARENT);
		h = CreateFont(
			36,                          //����߶ȵ��߼��߶�
			0,                           //�߼�ƽ���ַ����
			0,                           //��ת�Ƕ�
			0,                           //���߷����
			FW_BLACK,                    //����Ȩ��
			FALSE,                       //б�����Ա�־
			FALSE,                       //�»������Ա�־
			FALSE,                       //ɾ�������Ա�־
			GB2312_CHARSET,              //�ַ�����ʶ��
			OUT_DEFAULT_PRECIS,          //�������
			CLIP_DEFAULT_PRECIS,         //���þ���
			DEFAULT_QUALITY,             //�������
			FIXED_PITCH | FF_MODERN,     //���ߺ�ϵ��
			_T("΢���ź�")               //ָ�����������ַ�����ָ��
		);
		SelectObject(hdc, h);
		SetRect(&rect, 0, 0, 0, 0);
		SetTextColor(hdc, RGB(255, 0, 0));
		DrawText(hdc, _T("��������"), -1, &rect, DT_NOCLIP);

		h = CreateFont(
			36,                          //����߶ȵ��߼��߶�
			0,                           //�߼�ƽ���ַ����
			200,                         //��ת�Ƕ�
			0,                           //���߷����
			FW_BLACK,                    //����Ȩ��
			TRUE,                        //б�����Ա�־
			TRUE,                        //�»������Ա�־
			FALSE,                       //ɾ�������Ա�־
			GB2312_CHARSET,              //�ַ�����ʶ��
			OUT_DEFAULT_PRECIS,          //�������
			CLIP_DEFAULT_PRECIS,         //���þ���
			DEFAULT_QUALITY,             //�������
			FIXED_PITCH | FF_MODERN,     //���ߺ�ϵ��
			_T("΢���ź�")               //ָ�����������ַ�����ָ��
		);
		SelectObject(hdc, h);
		SetRect(&rect, 150, 50, 0, 0);
		SetTextColor(hdc, RGB(255, 0, 0));
		DrawText(hdc, _T("Warm Home"), -1, &rect, DT_NOCLIP);

		h = CreateFont(
			24,                          //����߶ȵ��߼��߶�
			0,                           //�߼�ƽ���ַ����
			0,                           //��ת�Ƕ�
			0,                           //���߷����
			FW_BLACK,                    //����Ȩ��
			FALSE,                       //б�����Ա�־
			FALSE,                       //�»������Ա�־
			FALSE,                       //ɾ�������Ա�־
			GB2312_CHARSET,              //�ַ�����ʶ��
			OUT_DEFAULT_PRECIS,          //�������
			CLIP_DEFAULT_PRECIS,         //���þ���
			DEFAULT_QUALITY,             //�������
			FIXED_PITCH | FF_MODERN,     //���ߺ�ϵ��
			_T("΢���ź�")               //ָ�����������ַ�����ָ��
		);
		SelectObject(hdc, h);
		SetRect(&rect, 0, 58, 0, 0);
		SetTextColor(hdc, RGB(0, 0, 0));
		DrawText(hdc, _T("\n�汾:V5.3.1"), -1, &rect, DT_NOCLIP);

		h = CreateFont(
			32,                          //����߶ȵ��߼��߶�
			0,                           //�߼�ƽ���ַ����
			0,                           //��ת�Ƕ�
			0,                           //���߷����
			FW_BLACK,                    //����Ȩ��
			FALSE,                       //б�����Ա�־
			FALSE,                       //�»������Ա�־
			FALSE,                       //ɾ�������Ա�־
			GB2312_CHARSET,              //�ַ�����ʶ��
			OUT_DEFAULT_PRECIS,          //�������
			CLIP_DEFAULT_PRECIS,         //���þ���
			DEFAULT_QUALITY,             //�������
			FIXED_PITCH | FF_MODERN,     //���ߺ�ϵ��
			_T("΢���ź�")               //ָ�����������ַ�����ָ��
		);
		SelectObject(hdc, h);
		SetRect(&rect, 0, 150, 0, 0);
		SetTextColor(hdc, RGB(0, 0, 0));
		DrawText(hdc, _T("�˵�"), -1, &rect, DT_NOCLIP);

		h = CreateFont(
			32,                          //����߶ȵ��߼��߶�
			0,                           //�߼�ƽ���ַ����
			0,                           //��ת�Ƕ�
			0,                           //���߷����
			FW_BLACK,                    //����Ȩ��
			FALSE,                       //б�����Ա�־
			FALSE,                       //�»������Ա�־
			FALSE,                       //ɾ�������Ա�־
			GB2312_CHARSET,              //�ַ�����ʶ��
			OUT_DEFAULT_PRECIS,          //�������
			CLIP_DEFAULT_PRECIS,         //���þ���
			DEFAULT_QUALITY,             //�������
			FIXED_PITCH | FF_MODERN,     //���ߺ�ϵ��
			_T("΢���ź�")               //ָ�����������ַ�����ָ��
		);
		SelectObject(hdc, h);
		SetRect(&rect, 0, 350, 0, 0);
		SetTextColor(hdc, RGB(0, 0, 0));
		DrawText(hdc, _T("�ƻ��ػ� / ����"), -1, &rect, DT_NOCLIP);

		DeleteObject(h);
		EndPaint(hWnd, &ps);
		break;
	case WM_COMMAND:
	{
		switch (LOWORD(wParam))
		{
		case IDB_1:
			ShellExecute(NULL, NULL, _T("cmd"), _T("/k systeminfo"), NULL, SW_SHOW);
			break;
		case IDB_2:
			ShellExecute(NULL, NULL, _T("https://www.mcjiaozi.icu/"), NULL, NULL, SW_SHOW);
			break;
		case IDB_3:
			ShellExecute(NULL, NULL, _T("https://www.mcjiaozi.icu/github/"), NULL, NULL, SW_SHOW);
			break;
		case IDB_4:
			ShellExecute(NULL, NULL, _T("cmd"), NULL, NULL, SW_SHOW);
			break;
		case IDB_5:
			ShellExecute(NULL, NULL, _T("powershell"), NULL, NULL, SW_SHOW);
			break;
		case IDB_6:
			shutdown = MessageBox(NULL, _T("��ȷʵҪ�ػ���\n���ȷ���������ػ���\n�뱣���������ݣ�"), _T("����"), MB_OKCANCEL | MB_ICONWARNING);
			if (shutdown == 0) {
				MessageBox(NULL, _T("�ڴ治��!"), _T("����"), MB_OK | MB_ICONERROR);
			}
			else if (shutdown == IDOK) {
				ShellExecute(NULL, NULL, _T("shutdown"), _T("-s -t 0 -hybrid"), NULL, SW_SHOW);
			}
			break;
		case IDB_7:
			shutdown = MessageBox(NULL, _T("��ȷʵҪ�ػ���\n���ȷ������1���Ӻ�ػ���\n�뱣���������ݣ�"), _T("����"), MB_OKCANCEL | MB_ICONWARNING);
			if (shutdown == 0) {
				MessageBox(NULL, _T("�ڴ治��!"), _T("����"), MB_OK | MB_ICONERROR);
			}
			else if (shutdown == IDOK) {
				ShellExecute(NULL, NULL, _T("shutdown"), _T("-s -t 60 -hybrid"), NULL, SW_SHOW);
			}
			break;
		case IDB_8:
			shutdown = MessageBox(NULL, _T("��ȷʵҪ�ػ���\n���ȷ������5���Ӻ�ػ���\n�뱣���������ݣ�"), _T("����"), MB_OKCANCEL | MB_ICONWARNING);
			if (shutdown == 0) {
				MessageBox(NULL, _T("�ڴ治��!"), _T("����"), MB_OK | MB_ICONERROR);
			}
			else if (shutdown == IDOK) {
				ShellExecute(NULL, NULL, _T("shutdown"), _T("-s -t 300 -hybrid"), NULL, SW_SHOW);
			}
			break;
		case IDB_9:
			shutdown = MessageBox(NULL, _T("��ȷʵҪ�ػ���\n���ȷ������10���Ӻ�ػ���\n�뱣���������ݣ�"), _T("����"), MB_OKCANCEL | MB_ICONWARNING);
			if (shutdown == 0) {
				MessageBox(NULL, _T("�ڴ治��!"), _T("����"), MB_OK | MB_ICONERROR);
			}
			else if (shutdown == IDOK) {
				ShellExecute(NULL, NULL, _T("shutdown"), _T("-s -t 600 -hybrid"), NULL, SW_SHOW);
			}
			break;
		case IDB_10:
			shutdown = MessageBox(NULL, _T("��ȷʵҪ�ػ���\n���ȷ������30���Ӻ�ػ���\n�뱣���������ݣ�"), _T("����"), MB_OKCANCEL | MB_ICONWARNING);
			if (shutdown == 0) {
				MessageBox(NULL, _T("�ڴ治��!"), _T("����"), MB_OK | MB_ICONERROR);
			}
			else if (shutdown == IDOK) {
				ShellExecute(NULL, NULL, _T("shutdown"), _T("-s -t 1800 -hybrid"), NULL, SW_SHOW);
			}
			break;
		case IDB_11:
			shutdown = MessageBox(NULL, _T("��ȷʵҪ�ػ���\n���ȷ������1Сʱ��ػ���\n�뱣���������ݣ�"), _T("����"), MB_OKCANCEL | MB_ICONWARNING);
			if (shutdown == 0) {
				MessageBox(NULL, _T("�ڴ治��!"), _T("����"), MB_OK | MB_ICONERROR);
			}
			else if (shutdown == IDOK) {
				ShellExecute(NULL, NULL, _T("shutdown"), _T("-s -t 3600 -hybrid"), NULL, SW_SHOW);
			}
			break;
		case IDB_12:
				ShellExecute(NULL, NULL, _T("shutdown"), _T("/i"), NULL, SW_SHOW);
			break;
		case IDB_13:
			ShellExecute(NULL, NULL, _T("shutdown"), _T("/a"), NULL, SW_SHOW);
			break;
		case IDB_14:
			shutdown = MessageBox(NULL, _T("��ȷʵҪ������\n���ȷ��������������\n�뱣���������ݣ�"), _T("����"), MB_OKCANCEL | MB_ICONWARNING);
			if (shutdown == 0) {
				MessageBox(NULL, _T("�ڴ治��!"), _T("����"), MB_OK | MB_ICONERROR);
			}
			else if (shutdown == IDOK) {
				ShellExecute(NULL, NULL, _T("shutdown"), _T("-r -t 0"), NULL, SW_SHOW);
			}
			break;
		case IDB_15:
			shutdown = MessageBox(NULL, _T("��ȷʵҪ������\n���ȷ������1���Ӻ�������\n�뱣���������ݣ�"), _T("����"), MB_OKCANCEL | MB_ICONWARNING);
			if (shutdown == 0) {
				MessageBox(NULL, _T("�ڴ治��!"), _T("����"), MB_OK | MB_ICONERROR);
			}
			else if (shutdown == IDOK) {
				ShellExecute(NULL, NULL, _T("shutdown"), _T("-r -t 60"), NULL, SW_SHOW);
			}
			break;
		case IDB_16:
			shutdown = MessageBox(NULL, _T("��ȷʵҪ������\n���ȷ������5���Ӻ�������\n�뱣���������ݣ�"), _T("����"), MB_OKCANCEL | MB_ICONWARNING);
			if (shutdown == 0) {
				MessageBox(NULL, _T("�ڴ治��!"), _T("����"), MB_OK | MB_ICONERROR);
			}
			else if (shutdown == IDOK) {
				ShellExecute(NULL, NULL, _T("shutdown"), _T("-r -t 300"), NULL, SW_SHOW);
			}
			break;
		case IDB_17:
			shutdown = MessageBox(NULL, _T("��ȷʵҪ������\n���ȷ������10���Ӻ�������\n�뱣���������ݣ�"), _T("����"), MB_OKCANCEL | MB_ICONWARNING);
			if (shutdown == 0) {
				MessageBox(NULL, _T("�ڴ治��!"), _T("����"), MB_OK | MB_ICONERROR);
			}
			else if (shutdown == IDOK) {
				ShellExecute(NULL, NULL, _T("shutdown"), _T("-r -t 600"), NULL, SW_SHOW);
			}
			break;
		case IDB_18:
			shutdown = MessageBox(NULL, _T("��ȷʵҪ������\n���ȷ������30���Ӻ�������\n�뱣���������ݣ�"), _T("����"), MB_OKCANCEL | MB_ICONWARNING);
			if (shutdown == 0) {
				MessageBox(NULL, _T("�ڴ治��!"), _T("����"), MB_OK | MB_ICONERROR);
			}
			else if (shutdown == IDOK) {
				ShellExecute(NULL, NULL, _T("shutdown"), _T("-r -t 1800"), NULL, SW_SHOW);
			}
			break;
		case IDB_19:
			shutdown = MessageBox(NULL, _T("��ȷʵҪ������\n���ȷ������1Сʱ��������\n�뱣���������ݣ�"), _T("����"), MB_OKCANCEL | MB_ICONWARNING);
			if (shutdown == 0) {
				MessageBox(NULL, _T("�ڴ治��!"), _T("����"), MB_OK | MB_ICONERROR);
			}
			else if (shutdown == IDOK) {
				ShellExecute(NULL, NULL, _T("shutdown"), _T("-r -t 3600"), NULL, SW_SHOW);
			}
			break;
		case IDB_21:
			shutdown = MessageBox(NULL, _T("��ȷʵҪ�ػ���\n���ȷ���������ػ���\n�뱣���������ݣ�"), _T("����"), MB_OKCANCEL | MB_ICONWARNING);
			if (shutdown == 0) {
				MessageBox(NULL, _T("�ڴ治��!"), _T("����"), MB_OK | MB_ICONERROR);
			}
			else if (shutdown == IDOK) {
				ShellExecute(NULL, NULL, _T("shutdown"), _T("-s -t 0"), NULL, SW_SHOW);
			}
			break;
		case IDB_22:
			shutdown = MessageBox(NULL, _T("��ȷʵҪ�ػ���\n���ȷ������1���Ӻ�ػ���\n�뱣���������ݣ�"), _T("����"), MB_OKCANCEL | MB_ICONWARNING);
			if (shutdown == 0) {
				MessageBox(NULL, _T("�ڴ治��!"), _T("����"), MB_OK | MB_ICONERROR);
			}
			else if (shutdown == IDOK) {
				ShellExecute(NULL, NULL, _T("shutdown"), _T("-s -t 60"), NULL, SW_SHOW);
			}
			break;
		case IDB_23:
			shutdown = MessageBox(NULL, _T("��ȷʵҪ�ػ���\n���ȷ������5���Ӻ�ػ���\n�뱣���������ݣ�"), _T("����"), MB_OKCANCEL | MB_ICONWARNING);
			if (shutdown == 0) {
				MessageBox(NULL, _T("�ڴ治��!"), _T("����"), MB_OK | MB_ICONERROR);
			}
			else if (shutdown == IDOK) {
				ShellExecute(NULL, NULL, _T("shutdown"), _T("-s -t 300"), NULL, SW_SHOW);
			}
			break;
		case IDB_24:
			shutdown = MessageBox(NULL, _T("��ȷʵҪ�ػ���\n���ȷ������10���Ӻ�ػ���\n�뱣���������ݣ�"), _T("����"), MB_OKCANCEL | MB_ICONWARNING);
			if (shutdown == 0) {
				MessageBox(NULL, _T("�ڴ治��!"), _T("����"), MB_OK | MB_ICONERROR);
			}
			else if (shutdown == IDOK) {
				ShellExecute(NULL, NULL, _T("shutdown"), _T("-s -t 600"), NULL, SW_SHOW);
			}
			break;
		case IDB_25:
			shutdown = MessageBox(NULL, _T("��ȷʵҪ�ػ���\n���ȷ������30���Ӻ�ػ���\n�뱣���������ݣ�"), _T("����"), MB_OKCANCEL | MB_ICONWARNING);
			if (shutdown == 0) {
				MessageBox(NULL, _T("�ڴ治��!"), _T("����"), MB_OK | MB_ICONERROR);
			}
			else if (shutdown == IDOK) {
				ShellExecute(NULL, NULL, _T("shutdown"), _T("-s -t 1800"), NULL, SW_SHOW);
			}
			break;
		case IDB_26:
			shutdown = MessageBox(NULL, _T("��ȷʵҪ�ػ���\n���ȷ������1Сʱ��ػ���\n�뱣���������ݣ�"), _T("����"), MB_OKCANCEL | MB_ICONWARNING);
			if (shutdown == 0) {
				MessageBox(NULL, _T("�ڴ治��!"), _T("����"), MB_OK | MB_ICONERROR);
			}
			else if (shutdown == IDOK) {
				ShellExecute(NULL, NULL, _T("shutdown"), _T("-s -t 3600"), NULL, SW_SHOW);
			}
			break;
		case IDB_27:
			DeleteUrlCacheEntry(_T("https://www.mcjiaozi.icu/download/software/bamboo/changelog.txt"));
			ShellExecute(NULL, NULL, _T("cmd"), _T("/c md %temp%\\bamboo"), NULL, SW_SHOW);
			if (S_OK != URLDownloadToFile(NULL, _T("https://www.mcjiaozi.icu/download/software/bamboo/changelog.txt"), _T("changelog.txt"), 0, 0)) {
				MessageBox(NULL, _T("�ӷ�������ȡ������־ʧ�ܣ�\n��ǰ���ҵ���վ��ȡ������־��\n������־λ�ã�https://www.mcjiaozi.icu/download/software/bamboo/changelog.txt��"), _T("����"), MB_OK | MB_ICONERROR);
			}
			ShellExecute(NULL, NULL, _T("cmd"), _T("/c copy changelog.txt %temp%\\bamboo\\changelog.txt&&del changelog.txt&&start %temp%\\bamboo\\changelog.txt"), NULL, SW_SHOW);
			break;
		case IDB_28:
			ShellExecute(NULL, NULL, _T("https://www.mcjiaozi.icu/download/"), NULL, NULL, SW_SHOW);
			break;
		case IDB_29:
				ShellExecute(NULL, NULL, _T("ipconfig"), _T("-flushdns"), NULL, SW_SHOW);
			break;
		case IDB_20:
			update();
			break;
		case IDB_30:
			ShellExecute(NULL, NULL, _T("https://www.mcjiaozi.icu/download/software/bamboo/LICENSE"), NULL, NULL, SW_SHOW);
			break;
		default:
			break;
		}
	}
	break;
	case WM_CLOSE:
		DestroyWindow(hWnd);
		break;
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	default:
		//DefWindowProcȱʡ���ڴ�����
		//���������Ĭ�ϵĴ��ڴ����������ǿ��԰Ѳ����ĵ���Ϣ��������������
		return DefWindowProc(hWnd, message, wParam, lParam);
		break;
	}
	return 0;
}