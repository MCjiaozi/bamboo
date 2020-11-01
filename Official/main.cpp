// GT_HelloWorldWin32.cpp
// compile with: /D_UNICODE /DUNICODE /DWIN32 /D_WINDOWS /c
// 这是一个最简单的Win32程序，亦可作为开发桌面应用程序的模板

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
// 主窗体类名
static TCHAR szWindowClass[] = _T("遇见竹子");
// 应用程序标题栏处出现的字符串
static TCHAR szTitle[] = _T("遇见竹子");

//HINSTANCE 是Windows里的一中数据类型，是用于标示（记录）一个程序的实例。
//它与HMODULE是一样的（通用的，这两种类型最终就是32位无符号长整形）。
//HINSTANCE，分开看就是 HANDLE(句柄) + INSTANCE（实例）
//实例就是一个程序。用qq来举例：你可以开同时开2个qq号，但是你电脑里的qq软件只有一份。
//这2个qq号就是qq的2个实例
HINSTANCE hInst;

// -------------------------需要预定义的函数放置在此代码块种:----------------------------


//每个 Windows 桌面应用程序必须具有一个窗口过程函数
//此函数处理应用程序从操作系统中接收的大量消息。 
//例如，如果应用程序的对话框中有“确定”按钮，那么用户单击该按钮时，
//操作系统会向应用程序发送一条消息，通知按钮已被单击。WndProc 负责对该事件作出响应。
//在本例中，相应的响应可能是关闭对话框。
LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);
//-------------------------------------正式内容-----------------------------------------

//主窗体函数(入口过程)
//每个基于 Win32 的应用程序的函数必须具有 WinMain 函数
//正如每个 C 应用程序和 C++ 控制台应用程序在起始点必须具有 main 函数
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {
	//创建 WNDCLASSEX 类型的窗口类结构。 此结构包含关于窗口的信息
	//例如应用程序图标、窗口背景色、标题栏中显示的名称、窗口过程函数的名称等。
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

	//对已创建的窗口类进行注册。 使用 RegisterClassEx 函数，并将窗口类结构作为参数传递。
	if (!RegisterClassEx(&wcex)) {
		MessageBox(NULL, _T("Call to RegisterClassEx failed!"), _T("错误"), NULL);
		return 1;
	}

	// Store instance handle in our global variable 
	// 将句柄实例存储于全局变量中
	hInst = hInstance;


	/*创建窗口
	HWND CreateWindow(
	LPCTSTR lpClassName,  //窗口类名
	LPCTSTR lpWindowName, //窗口标题
	DWORD dwStyle,        //窗口风格，WS开头
	int x,                //窗口左上角x坐标
	int y,                //窗口左上角y坐标
	int nWidth,           //窗口宽度
	int nHeight,          //窗口高度
	HWND hWndParent,      //父窗口句柄
	HMENU hMenu,          //菜单句柄
	HANDLE hlnstance,     //窗口句柄
	LPVOID lpParam);      //改值会传递给窗口WM_CREATE消息的一个参数
	*/
	HWND hWnd = CreateWindow(szWindowClass, szTitle, WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, NULL, NULL, hInstance, NULL);
	if (!hWnd) {
		MessageBox(NULL, _T("Call to CreateWindow failed!"), _T("错误"), NULL);
		return 1;
	}
	// ShowWindow 函数的参数解释: 
	// hWnd: CreateWindow函数返回的窗口句柄 
	// nCmdShow: the fourth parameter from WinMain 
	ShowWindow(hWnd, nCmdShow);
	// UpdateWindow函数用于更新窗口指定的区域
	// 如果窗口更新的区域不为空，UpdateWindow函数就发送一个WM_PAINT消息来更新指定窗口的客户区。
	// 函数绕过应用程序的消息队列，直接发送WM_PAINT消息给指定窗口的窗口过程
	// 如果更新区域为空，则不发送消息。
	UpdateWindow(hWnd);
	// Main message loop: 
	// 添加用于侦听操作系统所发送消息的消息循环。 
	// 当应用程序收到一条消息时，此循环将该消息调度到 WndProc 函数以进行处理。 
	MSG msg;
	while (GetMessage(&msg, NULL, 0, 0)) {
		TranslateMessage(&msg); //翻译消息
		DispatchMessage(&msg);  //派遣消息
	}
	return (int)msg.wParam;
}

//检查更新
void update() {
	DeleteUrlCacheEntry(_T("https://www.mcjiaozi.icu/update/bamboo/version.txt"));
	if (S_OK != URLDownloadToFile(NULL, _T("https://www.mcjiaozi.icu/update/bamboo/version.txt"), _T("version.txt"), 0, 0)) {
		MessageBox(NULL, _T("检查更新失败！\n请前往在线更新网站！"), _T("错误"), MB_OK | MB_ICONERROR);
	}
	FILE* fp = fopen("version.txt", "r");//从缓存读取版本号
	ShellExecute(NULL, NULL, _T("cmd"), _T("/c del version.txt"), NULL, SW_SHOW);
	if (fp == NULL)MessageBox(NULL, _T("检查更新失败！无法读取在线版本号！\n请前往在线更新网站！"), _T("错误"), MB_OK | MB_ICONERROR);//如果读取的版本号为NULL，则报错
	char ch;
	ch = getc(fp);
	int newestversion = ch;
	if (ch > 52) {
		int updateaa = MessageBox(NULL, _T("有新版本可用，要更新吗？\n点击确定下载将开始。"), _T("检查更新"), MB_OKCANCEL | MB_ICONQUESTION);
		if (updateaa == IDOK) {
			DeleteUrlCacheEntry(_T("https://www.mcjiaozi.icu/download/software/bamboo/bamboo_installer.exe"));
			if (S_OK != URLDownloadToFile(NULL, _T("https://www.mcjiaozi.icu/download/software/bamboo/bamboo_installer.exe"), _T("bamboo_installer.exe"), 0, 0)) {
				MessageBox(NULL, _T("下载更新失败！\n请前往在线更新网站！"), _T("错误"), MB_OK | MB_ICONERROR);
				return;
			}
			ShellExecute(NULL, NULL, _T("cmd"), _T("/c copy bamboo_installer.exe %temp%\\bamboo\\bamboo_installer.exe&&del bamboo_installer.exe&&start %temp%\\bamboo\\bamboo_installer.exe"), NULL, SW_SHOW);
			return;
		}
		else if (updateaa == 0) {
			MessageBox(NULL, _T("内存不足!"), _T("错误"), MB_OK | MB_ICONERROR);
			return;
		}
		else return;

	}
	else if (ch == 52) {
		MessageBox(NULL, _T("您的客户端是最新版本！"), _T("检查更新"), NULL);
		return;
	}
	else if (ch < 52) {
		MessageBox(NULL, _T("检查更新失败！\n未知错误！"), _T("错误"), MB_OK | MB_ICONERROR);
		return;
	}
	else return;
	return;
}
// //  函数: WndProc(HWND, UINT, WPARAM, LPARAM) 
// //  目标:  处理主窗体产生的信息
// //  WM_PAINT消息代表绘制主窗体 
// //  WM_DESTROY消息代表投递一个退出消息并返回 
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam) {
	PAINTSTRUCT ps;
	RECT rect;
	HDC hdc;
	HFONT h;
	int shutdown;
	switch (message) {
	case WM_CREATE:
		CreateWindow(_T("Button"), _T("查看系统信息"), WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON, 0, 182, 300, 30, hWnd, (HMENU)IDB_1, NULL, NULL);
		CreateWindow(_T("Button"), _T("访问我的网站"), WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON, 0, 212, 300, 30, hWnd, (HMENU)IDB_2, NULL, NULL);
		CreateWindow(_T("Button"), _T("访问Github"), WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON, 0, 242, 300, 30, hWnd, (HMENU)IDB_3, NULL, NULL);
		CreateWindow(_T("Button"), _T("打开命令提示符"), WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON, 0, 272, 300, 30, hWnd, (HMENU)IDB_4, NULL, NULL);
		CreateWindow(_T("Button"), _T("打开PowerShell"), WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON, 0, 302, 300, 30, hWnd, (HMENU)IDB_5, NULL, NULL);
		CreateWindow(_T("Button"), _T("关闭计算机(快速启动)（立即）"), WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON, 0, 382, 300, 30, hWnd, (HMENU)IDB_6, NULL, NULL);
		CreateWindow(_T("Button"), _T("关闭计算机(快速启动)（1分钟后）"), WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON, 0, 412, 300, 30, hWnd, (HMENU)IDB_7, NULL, NULL);
		CreateWindow(_T("Button"), _T("关闭计算机(快速启动)（5分钟后）"), WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON, 0, 442, 300, 30, hWnd, (HMENU)IDB_8, NULL, NULL);
		CreateWindow(_T("Button"), _T("关闭计算机(快速启动)（10分钟后）"), WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON, 0, 472, 300, 30, hWnd, (HMENU)IDB_9, NULL, NULL);
		CreateWindow(_T("Button"), _T("关闭计算机(快速启动)（30分钟后）"), WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON, 0, 502, 300, 30, hWnd, (HMENU)IDB_10, NULL, NULL);
		CreateWindow(_T("Button"), _T("关闭计算机(快速启动)（1小时后）"), WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON, 0, 532, 300, 30, hWnd, (HMENU)IDB_11, NULL, NULL);
		CreateWindow(_T("Button"), _T("打开远程关机对话框 / 显示图形用户界面(GUI)"), WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON, 0, 562, 900, 30, hWnd, (HMENU)IDB_12, NULL, NULL);
		CreateWindow(_T("Button"), _T("中止系统关闭"), WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON, 0, 592, 900, 30, hWnd, (HMENU)IDB_13, NULL, NULL);
		CreateWindow(_T("Button"), _T("完全关闭并重启计算机（立即）"), WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON, 300, 382, 300, 30, hWnd, (HMENU)IDB_14, NULL, NULL);
		CreateWindow(_T("Button"), _T("完全关闭并重启计算机（1分钟后）"), WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON, 300, 412, 300, 30, hWnd, (HMENU)IDB_15, NULL, NULL);
		CreateWindow(_T("Button"), _T("完全关闭并重启计算机（5分钟后）"), WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON, 300, 442, 300, 30, hWnd, (HMENU)IDB_16, NULL, NULL);
		CreateWindow(_T("Button"), _T("完全关闭并重启计算机（10分钟后）"), WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON, 300, 472, 300, 30, hWnd, (HMENU)IDB_17, NULL, NULL);
		CreateWindow(_T("Button"), _T("完全关闭并重启计算机（30分钟后）"), WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON, 300, 502, 300, 30, hWnd, (HMENU)IDB_18, NULL, NULL);
		CreateWindow(_T("Button"), _T("完全关闭并重启计算机（1小时后）"), WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON, 300, 532, 300, 30, hWnd, (HMENU)IDB_19, NULL, NULL);
		CreateWindow(_T("Button"), _T("检查更新"), WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON, 300, 182, 300, 30, hWnd, (HMENU)IDB_20, NULL, NULL);
		CreateWindow(_T("Button"), _T("完全关闭计算机（立即）"), WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON, 600, 382, 300, 30, hWnd, (HMENU)IDB_21, NULL, NULL);
		CreateWindow(_T("Button"), _T("完全关闭计算机（1分钟后）"), WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON, 600, 412, 300, 30, hWnd, (HMENU)IDB_22, NULL, NULL);
		CreateWindow(_T("Button"), _T("完全关闭计算机（5分钟后）"), WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON, 600, 442, 300, 30, hWnd, (HMENU)IDB_23, NULL, NULL);
		CreateWindow(_T("Button"), _T("完全关闭计算机（10分钟后）"), WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON, 600, 472, 300, 30, hWnd, (HMENU)IDB_24, NULL, NULL);
		CreateWindow(_T("Button"), _T("完全关闭计算机（30分钟后）"), WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON, 600, 502, 300, 30, hWnd, (HMENU)IDB_25, NULL, NULL);
		CreateWindow(_T("Button"), _T("完全关闭计算机（1小时后）"), WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON, 600, 532, 300, 30, hWnd, (HMENU)IDB_26, NULL, NULL);
		CreateWindow(_T("Button"), _T("查看更新日志"), WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON, 300, 212, 300, 30, hWnd, (HMENU)IDB_27, NULL, NULL);
		CreateWindow(_T("Button"), _T("访问在线更新网站"), WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON, 300, 242, 300, 30, hWnd, (HMENU)IDB_28, NULL, NULL);
		CreateWindow(_T("Button"), _T("刷新 DNS 解析缓存"), WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON, 300, 272, 300, 30, hWnd, (HMENU)IDB_29, NULL, NULL);
		CreateWindow(_T("Button"), _T("开源许可证"), WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON, 300, 302, 300, 30, hWnd, (HMENU)IDB_30, NULL, NULL);
		break;
	case WM_PAINT:
		//要处理 WM_PAINT 消息，首先应调用 BeginPaint
		//然后处理所有的逻辑以及在窗口中布局文本、按钮和其他控件等
		//然后调用 EndPaint。 
		// -----------------在这段代码对应用程序进行布局------------------------ 
		// 对于此应用程序，开始调用和结束调用之间的逻辑是在窗口中显示字符串 “Hello，World!”。
		// 请注意 TextOut 函数用于显示字符串。
		hdc = BeginPaint(hWnd, &ps);
		SetBkMode(hdc, TRANSPARENT);
		h = CreateFont(
			36,                          //字体高度的逻辑高度
			0,                           //逻辑平均字符宽度
			0,                           //旋转角度
			0,                           //基线方向角
			FW_BLACK,                    //字体权重
			FALSE,                       //斜体属性标志
			FALSE,                       //下划线属性标志
			FALSE,                       //删除线属性标志
			GB2312_CHARSET,              //字符集标识符
			OUT_DEFAULT_PRECIS,          //输出精度
			CLIP_DEFAULT_PRECIS,         //剪裁精度
			DEFAULT_QUALITY,             //输出质量
			FIXED_PITCH | FF_MODERN,     //音高和系列
			_T("微软雅黑")               //指向字体名称字符串的指针
		);
		SelectObject(hdc, h);
		SetRect(&rect, 0, 0, 0, 0);
		SetTextColor(hdc, RGB(255, 0, 0));
		DrawText(hdc, _T("遇见竹子"), -1, &rect, DT_NOCLIP);

		h = CreateFont(
			36,                          //字体高度的逻辑高度
			0,                           //逻辑平均字符宽度
			200,                         //旋转角度
			0,                           //基线方向角
			FW_BLACK,                    //字体权重
			TRUE,                        //斜体属性标志
			TRUE,                        //下划线属性标志
			FALSE,                       //删除线属性标志
			GB2312_CHARSET,              //字符集标识符
			OUT_DEFAULT_PRECIS,          //输出精度
			CLIP_DEFAULT_PRECIS,         //剪裁精度
			DEFAULT_QUALITY,             //输出质量
			FIXED_PITCH | FF_MODERN,     //音高和系列
			_T("微软雅黑")               //指向字体名称字符串的指针
		);
		SelectObject(hdc, h);
		SetRect(&rect, 150, 50, 0, 0);
		SetTextColor(hdc, RGB(255, 0, 0));
		DrawText(hdc, _T("Warm Home"), -1, &rect, DT_NOCLIP);

		h = CreateFont(
			24,                          //字体高度的逻辑高度
			0,                           //逻辑平均字符宽度
			0,                           //旋转角度
			0,                           //基线方向角
			FW_BLACK,                    //字体权重
			FALSE,                       //斜体属性标志
			FALSE,                       //下划线属性标志
			FALSE,                       //删除线属性标志
			GB2312_CHARSET,              //字符集标识符
			OUT_DEFAULT_PRECIS,          //输出精度
			CLIP_DEFAULT_PRECIS,         //剪裁精度
			DEFAULT_QUALITY,             //输出质量
			FIXED_PITCH | FF_MODERN,     //音高和系列
			_T("微软雅黑")               //指向字体名称字符串的指针
		);
		SelectObject(hdc, h);
		SetRect(&rect, 0, 58, 0, 0);
		SetTextColor(hdc, RGB(0, 0, 0));
		DrawText(hdc, _T("\n版本:V5.3.1"), -1, &rect, DT_NOCLIP);

		h = CreateFont(
			32,                          //字体高度的逻辑高度
			0,                           //逻辑平均字符宽度
			0,                           //旋转角度
			0,                           //基线方向角
			FW_BLACK,                    //字体权重
			FALSE,                       //斜体属性标志
			FALSE,                       //下划线属性标志
			FALSE,                       //删除线属性标志
			GB2312_CHARSET,              //字符集标识符
			OUT_DEFAULT_PRECIS,          //输出精度
			CLIP_DEFAULT_PRECIS,         //剪裁精度
			DEFAULT_QUALITY,             //输出质量
			FIXED_PITCH | FF_MODERN,     //音高和系列
			_T("微软雅黑")               //指向字体名称字符串的指针
		);
		SelectObject(hdc, h);
		SetRect(&rect, 0, 150, 0, 0);
		SetTextColor(hdc, RGB(0, 0, 0));
		DrawText(hdc, _T("菜单"), -1, &rect, DT_NOCLIP);

		h = CreateFont(
			32,                          //字体高度的逻辑高度
			0,                           //逻辑平均字符宽度
			0,                           //旋转角度
			0,                           //基线方向角
			FW_BLACK,                    //字体权重
			FALSE,                       //斜体属性标志
			FALSE,                       //下划线属性标志
			FALSE,                       //删除线属性标志
			GB2312_CHARSET,              //字符集标识符
			OUT_DEFAULT_PRECIS,          //输出精度
			CLIP_DEFAULT_PRECIS,         //剪裁精度
			DEFAULT_QUALITY,             //输出质量
			FIXED_PITCH | FF_MODERN,     //音高和系列
			_T("微软雅黑")               //指向字体名称字符串的指针
		);
		SelectObject(hdc, h);
		SetRect(&rect, 0, 350, 0, 0);
		SetTextColor(hdc, RGB(0, 0, 0));
		DrawText(hdc, _T("计划关机 / 重启"), -1, &rect, DT_NOCLIP);

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
			shutdown = MessageBox(NULL, _T("你确实要关机吗？\n点击确定将立即关机！\n请保存好你的数据！"), _T("警告"), MB_OKCANCEL | MB_ICONWARNING);
			if (shutdown == 0) {
				MessageBox(NULL, _T("内存不足!"), _T("错误"), MB_OK | MB_ICONERROR);
			}
			else if (shutdown == IDOK) {
				ShellExecute(NULL, NULL, _T("shutdown"), _T("-s -t 0 -hybrid"), NULL, SW_SHOW);
			}
			break;
		case IDB_7:
			shutdown = MessageBox(NULL, _T("你确实要关机吗？\n点击确定将在1分钟后关机！\n请保存好你的数据！"), _T("警告"), MB_OKCANCEL | MB_ICONWARNING);
			if (shutdown == 0) {
				MessageBox(NULL, _T("内存不足!"), _T("错误"), MB_OK | MB_ICONERROR);
			}
			else if (shutdown == IDOK) {
				ShellExecute(NULL, NULL, _T("shutdown"), _T("-s -t 60 -hybrid"), NULL, SW_SHOW);
			}
			break;
		case IDB_8:
			shutdown = MessageBox(NULL, _T("你确实要关机吗？\n点击确定将在5分钟后关机！\n请保存好你的数据！"), _T("警告"), MB_OKCANCEL | MB_ICONWARNING);
			if (shutdown == 0) {
				MessageBox(NULL, _T("内存不足!"), _T("错误"), MB_OK | MB_ICONERROR);
			}
			else if (shutdown == IDOK) {
				ShellExecute(NULL, NULL, _T("shutdown"), _T("-s -t 300 -hybrid"), NULL, SW_SHOW);
			}
			break;
		case IDB_9:
			shutdown = MessageBox(NULL, _T("你确实要关机吗？\n点击确定将在10分钟后关机！\n请保存好你的数据！"), _T("警告"), MB_OKCANCEL | MB_ICONWARNING);
			if (shutdown == 0) {
				MessageBox(NULL, _T("内存不足!"), _T("错误"), MB_OK | MB_ICONERROR);
			}
			else if (shutdown == IDOK) {
				ShellExecute(NULL, NULL, _T("shutdown"), _T("-s -t 600 -hybrid"), NULL, SW_SHOW);
			}
			break;
		case IDB_10:
			shutdown = MessageBox(NULL, _T("你确实要关机吗？\n点击确定将在30分钟后关机！\n请保存好你的数据！"), _T("警告"), MB_OKCANCEL | MB_ICONWARNING);
			if (shutdown == 0) {
				MessageBox(NULL, _T("内存不足!"), _T("错误"), MB_OK | MB_ICONERROR);
			}
			else if (shutdown == IDOK) {
				ShellExecute(NULL, NULL, _T("shutdown"), _T("-s -t 1800 -hybrid"), NULL, SW_SHOW);
			}
			break;
		case IDB_11:
			shutdown = MessageBox(NULL, _T("你确实要关机吗？\n点击确定将在1小时后关机！\n请保存好你的数据！"), _T("警告"), MB_OKCANCEL | MB_ICONWARNING);
			if (shutdown == 0) {
				MessageBox(NULL, _T("内存不足!"), _T("错误"), MB_OK | MB_ICONERROR);
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
			shutdown = MessageBox(NULL, _T("你确实要重启吗？\n点击确定将立即重启！\n请保存好你的数据！"), _T("警告"), MB_OKCANCEL | MB_ICONWARNING);
			if (shutdown == 0) {
				MessageBox(NULL, _T("内存不足!"), _T("错误"), MB_OK | MB_ICONERROR);
			}
			else if (shutdown == IDOK) {
				ShellExecute(NULL, NULL, _T("shutdown"), _T("-r -t 0"), NULL, SW_SHOW);
			}
			break;
		case IDB_15:
			shutdown = MessageBox(NULL, _T("你确实要重启吗？\n点击确定将在1分钟后重启！\n请保存好你的数据！"), _T("警告"), MB_OKCANCEL | MB_ICONWARNING);
			if (shutdown == 0) {
				MessageBox(NULL, _T("内存不足!"), _T("错误"), MB_OK | MB_ICONERROR);
			}
			else if (shutdown == IDOK) {
				ShellExecute(NULL, NULL, _T("shutdown"), _T("-r -t 60"), NULL, SW_SHOW);
			}
			break;
		case IDB_16:
			shutdown = MessageBox(NULL, _T("你确实要重启吗？\n点击确定将在5分钟后重启！\n请保存好你的数据！"), _T("警告"), MB_OKCANCEL | MB_ICONWARNING);
			if (shutdown == 0) {
				MessageBox(NULL, _T("内存不足!"), _T("错误"), MB_OK | MB_ICONERROR);
			}
			else if (shutdown == IDOK) {
				ShellExecute(NULL, NULL, _T("shutdown"), _T("-r -t 300"), NULL, SW_SHOW);
			}
			break;
		case IDB_17:
			shutdown = MessageBox(NULL, _T("你确实要重启吗？\n点击确定将在10分钟后重启！\n请保存好你的数据！"), _T("警告"), MB_OKCANCEL | MB_ICONWARNING);
			if (shutdown == 0) {
				MessageBox(NULL, _T("内存不足!"), _T("错误"), MB_OK | MB_ICONERROR);
			}
			else if (shutdown == IDOK) {
				ShellExecute(NULL, NULL, _T("shutdown"), _T("-r -t 600"), NULL, SW_SHOW);
			}
			break;
		case IDB_18:
			shutdown = MessageBox(NULL, _T("你确实要重启吗？\n点击确定将在30分钟后重启！\n请保存好你的数据！"), _T("警告"), MB_OKCANCEL | MB_ICONWARNING);
			if (shutdown == 0) {
				MessageBox(NULL, _T("内存不足!"), _T("错误"), MB_OK | MB_ICONERROR);
			}
			else if (shutdown == IDOK) {
				ShellExecute(NULL, NULL, _T("shutdown"), _T("-r -t 1800"), NULL, SW_SHOW);
			}
			break;
		case IDB_19:
			shutdown = MessageBox(NULL, _T("你确实要重启吗？\n点击确定将在1小时后重启！\n请保存好你的数据！"), _T("警告"), MB_OKCANCEL | MB_ICONWARNING);
			if (shutdown == 0) {
				MessageBox(NULL, _T("内存不足!"), _T("错误"), MB_OK | MB_ICONERROR);
			}
			else if (shutdown == IDOK) {
				ShellExecute(NULL, NULL, _T("shutdown"), _T("-r -t 3600"), NULL, SW_SHOW);
			}
			break;
		case IDB_21:
			shutdown = MessageBox(NULL, _T("你确实要关机吗？\n点击确定将立即关机！\n请保存好你的数据！"), _T("警告"), MB_OKCANCEL | MB_ICONWARNING);
			if (shutdown == 0) {
				MessageBox(NULL, _T("内存不足!"), _T("错误"), MB_OK | MB_ICONERROR);
			}
			else if (shutdown == IDOK) {
				ShellExecute(NULL, NULL, _T("shutdown"), _T("-s -t 0"), NULL, SW_SHOW);
			}
			break;
		case IDB_22:
			shutdown = MessageBox(NULL, _T("你确实要关机吗？\n点击确定将在1分钟后关机！\n请保存好你的数据！"), _T("警告"), MB_OKCANCEL | MB_ICONWARNING);
			if (shutdown == 0) {
				MessageBox(NULL, _T("内存不足!"), _T("错误"), MB_OK | MB_ICONERROR);
			}
			else if (shutdown == IDOK) {
				ShellExecute(NULL, NULL, _T("shutdown"), _T("-s -t 60"), NULL, SW_SHOW);
			}
			break;
		case IDB_23:
			shutdown = MessageBox(NULL, _T("你确实要关机吗？\n点击确定将在5分钟后关机！\n请保存好你的数据！"), _T("警告"), MB_OKCANCEL | MB_ICONWARNING);
			if (shutdown == 0) {
				MessageBox(NULL, _T("内存不足!"), _T("错误"), MB_OK | MB_ICONERROR);
			}
			else if (shutdown == IDOK) {
				ShellExecute(NULL, NULL, _T("shutdown"), _T("-s -t 300"), NULL, SW_SHOW);
			}
			break;
		case IDB_24:
			shutdown = MessageBox(NULL, _T("你确实要关机吗？\n点击确定将在10分钟后关机！\n请保存好你的数据！"), _T("警告"), MB_OKCANCEL | MB_ICONWARNING);
			if (shutdown == 0) {
				MessageBox(NULL, _T("内存不足!"), _T("错误"), MB_OK | MB_ICONERROR);
			}
			else if (shutdown == IDOK) {
				ShellExecute(NULL, NULL, _T("shutdown"), _T("-s -t 600"), NULL, SW_SHOW);
			}
			break;
		case IDB_25:
			shutdown = MessageBox(NULL, _T("你确实要关机吗？\n点击确定将在30分钟后关机！\n请保存好你的数据！"), _T("警告"), MB_OKCANCEL | MB_ICONWARNING);
			if (shutdown == 0) {
				MessageBox(NULL, _T("内存不足!"), _T("错误"), MB_OK | MB_ICONERROR);
			}
			else if (shutdown == IDOK) {
				ShellExecute(NULL, NULL, _T("shutdown"), _T("-s -t 1800"), NULL, SW_SHOW);
			}
			break;
		case IDB_26:
			shutdown = MessageBox(NULL, _T("你确实要关机吗？\n点击确定将在1小时后关机！\n请保存好你的数据！"), _T("警告"), MB_OKCANCEL | MB_ICONWARNING);
			if (shutdown == 0) {
				MessageBox(NULL, _T("内存不足!"), _T("错误"), MB_OK | MB_ICONERROR);
			}
			else if (shutdown == IDOK) {
				ShellExecute(NULL, NULL, _T("shutdown"), _T("-s -t 3600"), NULL, SW_SHOW);
			}
			break;
		case IDB_27:
			DeleteUrlCacheEntry(_T("https://www.mcjiaozi.icu/download/software/bamboo/changelog.txt"));
			ShellExecute(NULL, NULL, _T("cmd"), _T("/c md %temp%\\bamboo"), NULL, SW_SHOW);
			if (S_OK != URLDownloadToFile(NULL, _T("https://www.mcjiaozi.icu/download/software/bamboo/changelog.txt"), _T("changelog.txt"), 0, 0)) {
				MessageBox(NULL, _T("从服务器获取更新日志失败！\n请前往我的网站获取更新日志！\n更新日志位置：https://www.mcjiaozi.icu/download/software/bamboo/changelog.txt。"), _T("错误"), MB_OK | MB_ICONERROR);
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
		//DefWindowProc缺省窗口处理函数
		//这个函数是默认的窗口处理函数，我们可以把不关心的消息都丢给它来处理
		return DefWindowProc(hWnd, message, wParam, lParam);
		break;
	}
	return 0;
}