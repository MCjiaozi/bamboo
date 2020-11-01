#include <windows.h>
#include <stdlib.h>
#include <string.h>
#include <tchar.h>
#include <WinInet.h>//DeleteUrlCacheEntry
#include <iostream>//URLDownloadToFile
#include <UrlMon.h>//URLDownloadToFile
#include <easyx.h>
#include <graphics.h>
#include <conio.h>
#include <math.h>
#include "resource.h"
#pragma comment(lib, "wininet.lib")//DeleteUrlCacheEntry
#pragma comment(lib, "urlmon.lib")//URLDownloadToFile
using namespace std;//URLDownloadToFile

void update()
{
	DeleteUrlCacheEntry(_T("https://www.mcjiaozi.icu/update/bamboo/preview/version.txt"));
	if (S_OK != URLDownloadToFile(NULL, _T("https://www.mcjiaozi.icu/update/bamboo/version.txt"), _T("version.txt"), 0, 0)) {
		MessageBox(NULL, _T("检查更新失败！\n请前往在线更新网站！"), _T("错误"), MB_OK | MB_ICONERROR);
	}
	FILE* fp = fopen("version.txt", "r");//从缓存读取版本号
	if (fp == NULL) {
		MessageBox(NULL, _T("检查更新失败！无法读取在线版本号！\n请前往在线更新网站！"), _T("错误"), MB_OK | MB_ICONERROR);
		return;
	}//如果读取的版本号为NULL，则报错
	char ch;
	ch = getc(fp);
	fclose(fp);
	ShellExecute(NULL, NULL, _T("cmd"), _T("/c del version.txt"), NULL, SW_SHOW);
	int newestversion = ch;
	if (ch > 53) {
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
	else if (ch == 53) {
		MessageBox(NULL, _T("您的客户端是最新版本！"), _T("检查更新"), NULL);
		return;
	}
	else if (ch < 53) {
		MessageBox(NULL, _T("检查更新失败！\n未知错误！"), _T("错误"), MB_OK | MB_ICONERROR);
		return;
	}
	else return;
	return;
}

int r[5][4] = { {30,110,120,150},{130,110,220,150},{230,110,320,150},{30,60,120,100},{130,60,220,100} };//三个按钮的二维数组

int button_judge(int x, int y)
{
	if (x > r[0][0] && x<r[0][2] && y>r[0][1] && y < r[0][3])return 1;
	if (x > r[1][0] && x<r[1][2] && y>r[1][1] && y < r[1][3])return 2;
	if (x > r[2][0] && x<r[2][2] && y>r[2][1] && y < r[2][3])return 3;
	if (x > r[3][0] && x<r[3][2] && y>r[3][1] && y < r[3][3])return 4;
	if (x > r[4][0] && x<r[4][2] && y>r[4][1] && y < r[4][3])return 5;
	return 0;
}
int main()
{
	int i, event = 0;
	short win_width, win_height;//定义窗口的宽度和高度
	win_width = 720; win_height = 560;
	initgraph(win_width, win_height);//初始化窗口（黑屏）
	for (i = 0; i < 256; i += 5)
	{
		setbkcolor(RGB(i, i, i));//设置背景色，原来默认黑色
		cleardevice();//清屏（取决于背景色）
		Sleep(15);//延时15ms
	}
	RECT R1 = { r[0][0],r[0][1],r[0][2],r[0][3] };
	RECT R2 = { r[1][0],r[1][1],r[1][2],r[1][3] };
	RECT R3 = { r[2][0],r[2][1],r[2][2],r[2][3] };
	RECT R4 = { r[3][0],r[3][1],r[3][2],r[3][3] };
	RECT R5 = { r[4][0],r[4][1],r[4][2],r[4][3] };
	LOGFONT f;
	gettextstyle(&f);					//获取字体样式
	_tcscpy(f.lfFaceName, _T("宋体"));	//设置字体为宋体
	f.lfQuality = ANTIALIASED_QUALITY;    // 设置输出效果为抗锯齿  
	settextstyle(&f);                     // 设置字体样式
	settextcolor(BLACK);				//BLACK在graphic.h头文件里面被定义为黑色的颜色常量
	drawtext("开源许可证", &R1, DT_CENTER | DT_VCENTER | DT_SINGLELINE);//在矩形区域R1内输入文字，水平居中，垂直居中，单行显示
	drawtext("开源网站", &R2, DT_CENTER | DT_VCENTER | DT_SINGLELINE);//在矩形区域R2内输入文字，水平居中，垂直居中，单行显示
	drawtext("退出", &R3, DT_CENTER | DT_VCENTER | DT_SINGLELINE);//在矩形区域R3内输入文字，水平居中，垂直居中，单行显示
	drawtext("检查更新", &R4, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
	drawtext("更新日志", &R5, DT_CENTER | DT_VCENTER | DT_SINGLELINE);

	settextstyle(50, 0, _T("黑体"), NULL, NULL, 300, false, false, false);
	outtextxy(0, 0, _T("遇见竹子"));

	setlinecolor(BLACK);
	rectangle(r[0][0], r[0][1], r[0][2], r[0][3]);
	rectangle(r[1][0], r[1][1], r[1][2], r[1][3]);
	rectangle(r[2][0], r[2][1], r[2][2], r[2][3]);
	rectangle(r[3][0], r[3][1], r[3][2], r[3][3]);
	rectangle(r[4][0], r[4][1], r[4][2], r[4][3]);
	MOUSEMSG m;//鼠标指针

	while (true)
	{
		m = GetMouseMsg();//获取一条鼠标消息

		switch (m.uMsg)
		{
		case WM_MOUSEMOVE:
			setrop2(R2_XORPEN);
			setlinecolor(LIGHTCYAN);//线条颜色为亮青色
			setlinestyle(PS_SOLID, 3);//设置画线样式为实现，10磅
			setfillcolor(WHITE);//填充颜色为白色
			if (button_judge(m.x, m.y) != 0)
			{
				if (event != button_judge(m.x, m.y))
				{
					event = button_judge(m.x, m.y);//记录这一次触发的按钮
					fillrectangle(r[event - 1][0], r[event - 1][1], r[event - 1][2], r[event - 1][3]);//有框填充矩形（X1,Y1,X2,Y2）
				}
			}
			else
			{
				if (event != 0)//上次触发的按钮未被修正为原来的颜色
				{
					fillrectangle(r[event - 1][0], r[event - 1][1], r[event - 1][2], r[event - 1][3]);//两次同或为原来颜色
					event = 0;
				}
			}
			break;
		case WM_LBUTTONDOWN:
			setrop2(R2_NOTXORPEN);//二元光栅——NOT(屏幕颜色 XOR 当前颜色)
			for (i = 0; i <= 10; i++)
			{
				setlinecolor(RGB(25 * i, 25 * i, 25 * i));//设置圆颜色
				circle(m.x, m.y, 2 * i);
				Sleep(20);//停顿30ms
				circle(m.x, m.y, 2 * i);//抹去刚刚画的圆
			}
			//按照按钮判断左键单击后的操作
			switch (button_judge(m.x, m.y))
			{
				//复原按钮原型
			case 1:
				DeleteUrlCacheEntry(_T("https://www.mcjiaozi.icu/download/software/bamboo/LICENSE"));
				ShellExecute(NULL, NULL, _T("cmd"), _T("/c md %temp%\\bamboo"), NULL, SW_SHOW);
				if (S_OK != URLDownloadToFile(NULL, _T("https://www.mcjiaozi.icu/download/software/bamboo/LICENSE"), _T("LICENSE"), 0, 0)) {
					MessageBox(NULL, _T("从服务器获取开源许可证失败！\n请前往我的网站获取开源许可证！\n开源许可证位置：https://www.mcjiaozi.icu/download/software/bamboo/LICENSE。"), _T("错误"), MB_OK | MB_ICONERROR);
				}
				ShellExecute(NULL, NULL, _T("cmd"), _T("/c copy LICENSE %temp%\\bamboo\\LICENSE&&del LICENSE&&notepad %temp%\\bamboo\\LICENSE"), NULL, SW_SHOW);
				break;
			case 2:
				ShellExecute(NULL, NULL, _T("https://www.mcjiaozi.icu/github/"), NULL, NULL, SW_SHOW);
				break;
			case 3:
				closegraph();//关闭绘图环境
				exit(0);//正常退出
			case 4:
				update();
				break;
			case 5:
				DeleteUrlCacheEntry(_T("https://www.mcjiaozi.icu/download/software/bamboo/changelog.txt"));
				ShellExecute(NULL, NULL, _T("cmd"), _T("/c md %temp%\\bamboo"), NULL, SW_SHOW);
				if (S_OK != URLDownloadToFile(NULL, _T("https://www.mcjiaozi.icu/download/software/bamboo/changelog.txt"), _T("changelog.txt"), 0, 0)) {
					MessageBox(NULL, _T("从服务器获取更新日志失败！\n请前往我的网站获取更新日志！\n更新日志位置：https://www.mcjiaozi.icu/download/software/bamboo/changelog.txt。"), _T("错误"), MB_OK | MB_ICONERROR);
				}
				ShellExecute(NULL, NULL, _T("cmd"), _T("/c copy changelog.txt %temp%\\bamboo\\changelog.txt&&del changelog.txt&&start %temp%\\bamboo\\changelog.txt"), NULL, SW_SHOW);
				break;
			default:
				FlushMouseMsgBuffer();//单击事件后清空鼠标消息
				//printf("\r\n(%d,%d)",m.x,m.y);//打印鼠标坐标，方便调试时确定区域
				break;
			}
			break;
			FlushMouseMsgBuffer();//清空鼠标消息缓存区
		}
	}
	system("pause");//暂停，为了显示
	return 0;
}

