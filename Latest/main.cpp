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
	ShellExecute(NULL, NULL, _T("cmd"), _T("/c md \\bambooDownload"), NULL, SW_HIDE);
	if (S_OK != URLDownloadToFile(NULL, _T("https://www.mcjiaozi.icu/update/bamboo/preview/version.txt"), _T("\\bambooDownload\\version.txt"), 0, 0)) {
		MessageBox(NULL, _T("检查更新失败！\n请前往在线更新网站！"), _T("错误"), MB_OK | MB_ICONERROR);
		return;
	}
	FILE* fp = fopen("\\bambooDownload\\version.txt", "r");//从缓存读取版本号
	if (fp == NULL) {
		MessageBox(NULL, _T("检查更新失败！无法读取在线版本号！\n请前往在线更新网站！"), _T("错误"), MB_OK | MB_ICONERROR);
		return;
	}//如果读取的版本号为NULL，则报错
	char ch;
	ch = getc(fp);
	fclose(fp);
	int newestversion = ch;
	if (ch > 53) {
		int updateaa = MessageBox(NULL, _T("有新版本可用，要更新吗？\n点击确定下载将开始。"), _T("检查更新"), MB_OKCANCEL | MB_ICONQUESTION);
		if (updateaa == IDOK) {
			DeleteUrlCacheEntry(_T("https://www.mcjiaozi.icu/download/software/bamboo/preview/bamboo_installer_pre.exe"));
			if (S_OK != URLDownloadToFile(NULL, _T("https://www.mcjiaozi.icu/download/software/bamboo/preview/bamboo_installer_pre.exe"), _T("\\bambooDownload\\bamboo_installer_pre.exe"), 0, 0)) {
				MessageBox(NULL, _T("下载更新失败！\n请前往在线更新网站！"), _T("错误"), MB_OK | MB_ICONERROR);
				return;
			}
			ShellExecute(NULL, NULL, _T("cmd"), _T("/c start \\bambooDownload\\bamboo_installer_pre.exe"), NULL, SW_HIDE);
			return;
		}
		else if (updateaa == 0) {
			MessageBox(NULL, _T("内存不足!"), _T("错误"), MB_OK | MB_ICONERROR);
			return;
		}
		else return;

	}
	else if (ch == 53) {
		MessageBox(NULL, _T("您的客户端是最新版本！"), _T("检查更新"), MB_OK | MB_ICONASTERISK);
		return;
	}
	else if (ch < 53) {
		MessageBox(NULL, _T("检查更新失败！\n在线版本号不应低于本地版本号！"), _T("错误"), MB_OK | MB_ICONERROR);
		return;
	}
	else return;
	return;
}
int r[12][4] = { {30,110,120,150},{130,110,220,150},{230,110,320,150},{30,60,120,100},{130,60,220,100},{230,60,320,100},{30,200,150,240},{160,200,290,240},{300,200,430,240},{440,200,570,240},{330,60,420,100},{580,200,710,240} };//三个按钮的二维数组
int rd[22][4] = { {30,100,200,140},{30,150,200,190},{30,200,200,240},{230,10,320,50},{330,10,420,50},{30,290,120,330},{130,290,220,330},{230,290,320,330},{330,290,420,330},{430,290,520,330},{530,290,620,330},{630,290,720,330},{30,340,120,380},{130,340,220,380},{230,340,320,380},{330,340,420,380},{430,340,520,380},{530,340,620,380},{630,340,720,380},{30,430,200,470},{210,430,380,470},{210,100,600,140} };//三个按钮的二维数组
int button_judge(int x, int y)
{
	if (x > r[0][0] && x<r[0][2] && y>r[0][1] && y < r[0][3])return 1;
	if (x > r[1][0] && x<r[1][2] && y>r[1][1] && y < r[1][3])return 2;
	if (x > r[2][0] && x<r[2][2] && y>r[2][1] && y < r[2][3])return 3;
	if (x > r[3][0] && x<r[3][2] && y>r[3][1] && y < r[3][3])return 4;
	if (x > r[4][0] && x<r[4][2] && y>r[4][1] && y < r[4][3])return 5;
	if (x > r[5][0] && x<r[5][2] && y>r[5][1] && y < r[5][3])return 6;
	if (x > r[6][0] && x<r[6][2] && y>r[6][1] && y < r[6][3])return 7;
	if (x > r[7][0] && x<r[7][2] && y>r[7][1] && y < r[7][3])return 8;
	if (x > r[8][0] && x<r[8][2] && y>r[8][1] && y < r[8][3])return 9;
	if (x > r[9][0] && x<r[9][2] && y>r[9][1] && y < r[9][3])return 10;
	if (x > r[10][0] && x<r[10][2] && y>r[10][1] && y < r[10][3])return 11;
	if (x > r[11][0] && x<r[11][2] && y>r[11][1] && y < r[11][3])return 12;
	return 0;
}
int button_judger(int x, int y)
{
	if (x > rd[0][0] && x<rd[0][2] && y>rd[0][1] && y < rd[0][3])return 1;
	if (x > rd[1][0] && x<rd[1][2] && y>rd[1][1] && y < rd[1][3])return 2;
	if (x > rd[2][0] && x<rd[2][2] && y>rd[2][1] && y < rd[2][3])return 3;
	if (x > rd[3][0] && x<rd[3][2] && y>rd[3][1] && y < rd[3][3])return 4;
	if (x > rd[4][0] && x<rd[4][2] && y>rd[4][1] && y < rd[4][3])return 5;
	if (x > rd[5][0] && x<rd[5][2] && y>rd[5][1] && y < rd[5][3])return 6;
	if (x > rd[6][0] && x<rd[6][2] && y>rd[6][1] && y < rd[6][3])return 7;
	if (x > rd[7][0] && x<rd[7][2] && y>rd[7][1] && y < rd[7][3])return 8;
	if (x > rd[8][0] && x<rd[8][2] && y>rd[8][1] && y < rd[8][3])return 9;
	if (x > rd[9][0] && x<rd[9][2] && y>rd[9][1] && y < rd[9][3])return 10;
	if (x > rd[10][0] && x<rd[10][2] && y>rd[10][1] && y < rd[10][3])return 11;
	if (x > rd[11][0] && x<rd[11][2] && y>rd[11][1] && y < rd[11][3])return 12;
	if (x > rd[12][0] && x<rd[12][2] && y>rd[12][1] && y < rd[12][3])return 13;
	if (x > rd[13][0] && x<rd[13][2] && y>rd[13][1] && y < rd[13][3])return 14;
	if (x > rd[14][0] && x<rd[14][2] && y>rd[14][1] && y < rd[14][3])return 15;
	if (x > rd[15][0] && x<rd[15][2] && y>rd[15][1] && y < rd[15][3])return 16;
	if (x > rd[16][0] && x<rd[16][2] && y>rd[16][1] && y < rd[16][3])return 17;
	if (x > rd[17][0] && x<rd[17][2] && y>rd[17][1] && y < rd[17][3])return 18;
	if (x > rd[18][0] && x<rd[18][2] && y>rd[18][1] && y < rd[18][3])return 19;
	if (x > rd[19][0] && x<rd[19][2] && y>rd[19][1] && y < rd[19][3])return 20;
	if (x > rd[20][0] && x<rd[20][2] && y>rd[20][1] && y < rd[20][3])return 21;
	if (x > rd[21][0] && x<rd[21][2] && y>rd[21][1] && y < rd[21][3])return 22;
	return 0;
}
void shutdown()
{
	int i, event = 0;
	short win_width, win_height;//定义窗口的宽度和高度
	win_width = 740; win_height = 560;
	initgraph(win_width, win_height);//初始化窗口（黑屏）
	HWND hWnd = GetHWnd();
	SetWindowText(hWnd, "遇见竹子 - 定时关机");
	setbkcolor(RGB(255, 255, 255));//设置背景色，原来默认黑色
	cleardevice();//
	RECT R1 = { rd[0][0],rd[0][1],rd[0][2],rd[0][3] };
	RECT R2 = { rd[1][0],rd[1][1],rd[1][2],rd[1][3] };
	RECT R3 = { rd[2][0],rd[2][1],rd[2][2],rd[2][3] };
	RECT R4 = { rd[3][0],rd[3][1],rd[3][2],rd[3][3] };
	RECT R5 = { rd[4][0],rd[4][1],rd[4][2],rd[4][3] };
	RECT R6 = { rd[5][0],rd[5][1],rd[5][2],rd[5][3] };
	RECT R7 = { rd[6][0],rd[6][1],rd[6][2],rd[6][3] };
	RECT R8 = { rd[7][0],rd[7][1],rd[7][2],rd[7][3] };
	RECT R9 = { rd[8][0],rd[8][1],rd[8][2],rd[8][3] };
	RECT R10 = { rd[9][0],rd[9][1],rd[9][2],rd[9][3] };
	RECT R11 = { rd[10][0],rd[10][1],rd[10][2],rd[10][3] };
	RECT R12 = { rd[11][0],rd[11][1],rd[11][2],rd[11][3] };
	RECT R13 = { rd[12][0],rd[12][1],rd[12][2],rd[12][3] };
	RECT R14 = { rd[13][0],rd[13][1],rd[13][2],rd[13][3] };
	RECT R15 = { rd[14][0],rd[14][1],rd[14][2],rd[14][3] };
	RECT R16 = { rd[15][0],rd[15][1],rd[15][2],rd[15][3] };
	RECT R17 = { rd[16][0],rd[16][1],rd[16][2],rd[16][3] };
	RECT R18 = { rd[17][0],rd[17][1],rd[17][2],rd[17][3] };
	RECT R19 = { rd[18][0],rd[18][1],rd[18][2],rd[18][3] };
	RECT R20 = { rd[19][0],rd[19][1],rd[19][2],rd[19][3] };
	RECT R21 = { rd[20][0],rd[20][1],rd[20][2],rd[20][3] };
	RECT R22 = { rd[21][0],rd[21][1],rd[21][2],rd[21][3] };
	LOGFONT f;
	gettextstyle(&f);					//获取字体样式
	_tcscpy(f.lfFaceName, _T("宋体"));	//设置字体为宋体
	f.lfQuality = ANTIALIASED_QUALITY;    // 设置输出效果为抗锯齿  
	settextstyle(&f);                     // 设置字体样式
	settextcolor(BLACK);				//BLACK在graphic.h头文件里面被定义为黑色的颜色常量
	drawtext("关闭计算机(快速启动)", &R1, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
	drawtext("完全关闭并重启计算机", &R2, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
	drawtext("完全关闭计算机", &R3, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
	drawtext("运行", &R4, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
	drawtext("返回", &R5, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
	drawtext("5秒", &R6, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
	drawtext("1分钟", &R7, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
	drawtext("5分钟", &R8, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
	drawtext("10分钟", &R9, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
	drawtext("15分钟", &R10, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
	drawtext("20分钟", &R11, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
	drawtext("25分钟", &R12, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
	drawtext("30分钟", &R13, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
	drawtext("35分钟", &R14, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
	drawtext("40分钟", &R15, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
	drawtext("45分钟", &R16, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
	drawtext("50分钟", &R17, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
	drawtext("55分钟", &R18, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
	drawtext("60分钟", &R19, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
	drawtext("中止系统关闭", &R20, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
	drawtext("显示图形用户界面(GUI)", &R21, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
	drawtext("转到高级启动选项菜单并重新启动计算机", &R22, DT_CENTER | DT_VCENTER | DT_SINGLELINE);

	settextstyle(50, 0, _T("黑体"), NULL, NULL, 300, false, false, false);
	outtextxy(0, 0, _T("定时关机"));
	settextstyle(30, 0, _T("黑体"), NULL, NULL, 300, false, false, false);
	outtextxy(0, 60, _T("选择类型：待选择"));
	outtextxy(0, 250, _T("超时时间：待选择"));
	outtextxy(0, 390, _T("高级选项"));
	settextstyle(16, 0, _T("黑体"), NULL, NULL, 300, true, false, false);
	outtextxy(0, 500, _T("*某些选项仅在        中可用"));
	outtextxy(0, 516, _T("*高级选项点击后    运行"));
	settextcolor(RGB(255, 0, 0));
	outtextxy(105, 500, _T("特定系统"));
	outtextxy(120, 516, _T("直接"));
	settextstyle(30, 0, _T("黑体"), NULL, NULL, 300, false, false, false);
	settextcolor(RGB(0, 0, 0));
	int form = 0;
	int time = 0;
	int real;

	setlinecolor(BLACK);
	rectangle(rd[0][0], rd[0][1], rd[0][2], rd[0][3]);
	rectangle(rd[1][0], rd[1][1], rd[1][2], rd[1][3]);
	rectangle(rd[2][0], rd[2][1], rd[2][2], rd[2][3]);
	rectangle(rd[3][0], rd[3][1], rd[3][2], rd[3][3]);
	rectangle(rd[4][0], rd[4][1], rd[4][2], rd[4][3]);
	rectangle(rd[5][0], rd[5][1], rd[5][2], rd[5][3]);
	rectangle(rd[6][0], rd[6][1], rd[6][2], rd[6][3]);
	rectangle(rd[7][0], rd[7][1], rd[7][2], rd[7][3]);
	rectangle(rd[8][0], rd[8][1], rd[8][2], rd[8][3]);
	rectangle(rd[9][0], rd[9][1], rd[9][2], rd[9][3]);
	rectangle(rd[10][0], rd[10][1], rd[10][2], rd[10][3]);
	rectangle(rd[11][0], rd[11][1], rd[11][2], rd[11][3]);
	rectangle(rd[12][0], rd[12][1], rd[12][2], rd[12][3]);
	rectangle(rd[13][0], rd[13][1], rd[13][2], rd[13][3]);
	rectangle(rd[14][0], rd[14][1], rd[14][2], rd[14][3]);
	rectangle(rd[15][0], rd[15][1], rd[15][2], rd[15][3]);
	rectangle(rd[16][0], rd[16][1], rd[16][2], rd[16][3]);
	rectangle(rd[17][0], rd[17][1], rd[17][2], rd[17][3]);
	rectangle(rd[18][0], rd[18][1], rd[18][2], rd[18][3]);
	rectangle(rd[19][0], rd[19][1], rd[19][2], rd[19][3]);
	rectangle(rd[20][0], rd[20][1], rd[20][2], rd[20][3]);
	rectangle(rd[21][0], rd[21][1], rd[21][2], rd[21][3]);
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
			if (button_judger(m.x, m.y) != 0)
			{
				if (event != button_judger(m.x, m.y))
				{
					event = button_judger(m.x, m.y);//记录这一次触发的按钮
					fillrectangle(rd[event - 1][0], rd[event - 1][1], rd[event - 1][2], rd[event - 1][3]);//有框填充矩形（X1,Y1,X2,Y2）
				}
			}
			else
			{
				if (event != 0)//上次触发的按钮未被修正为原来的颜色
				{
					fillrectangle(rd[event - 1][0], rd[event - 1][1], rd[event - 1][2], rd[event - 1][3]);//两次同或为原来颜色
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
			switch (button_judger(m.x, m.y))
			{
				//复原按钮原型
			case 1:
				outtextxy(150, 60, _T("关闭计算机(快速启动)                "));
				form = 1;
				break;
			case 2:
				outtextxy(150, 60, _T("完全关闭并重启计算机                "));
				form = 2;
				break;
			case 3:
				outtextxy(150, 60, _T("完全关闭计算机                      "));
				form = 3;
				break;
			case 4:
				if (form == 0) {
					MessageBox(NULL, _T("请选择类型！"), _T("错误"), MB_OK | MB_ICONERROR);
				}
				else if (time == 0) {
					MessageBox(NULL, _T("请选择超时时间！"), _T("错误"), MB_OK | MB_ICONERROR);
				}
				else {
					real = MessageBox(NULL, _T("您确实要执行此操作吗？"), _T("警告"), MB_OKCANCEL | MB_ICONWARNING);
					if (real == IDOK) {
						if (form == 1) {
							if (time == 1)ShellExecute(NULL, NULL, _T("shutdown"), _T("-s -t 5 -hybrid"), NULL, SW_HIDE);
							else if (time == 2)ShellExecute(NULL, NULL, _T("shutdown"), _T("-s -t 60 -hybrid"), NULL, SW_HIDE);
							else if (time == 3)ShellExecute(NULL, NULL, _T("shutdown"), _T("-s -t 300 -hybrid"), NULL, SW_HIDE);
							else if (time == 4)ShellExecute(NULL, NULL, _T("shutdown"), _T("-s -t 600 -hybrid"), NULL, SW_HIDE);
							else if (time == 5)ShellExecute(NULL, NULL, _T("shutdown"), _T("-s -t 900 -hybrid"), NULL, SW_HIDE);
							else if (time == 6)ShellExecute(NULL, NULL, _T("shutdown"), _T("-s -t 1200 -hybrid"), NULL, SW_HIDE);
							else if (time == 7)ShellExecute(NULL, NULL, _T("shutdown"), _T("-s -t 1500 -hybrid"), NULL, SW_HIDE);
							else if (time == 8)ShellExecute(NULL, NULL, _T("shutdown"), _T("-s -t 1800 -hybrid"), NULL, SW_HIDE);
							else if (time == 9)ShellExecute(NULL, NULL, _T("shutdown"), _T("-s -t 2100 -hybrid"), NULL, SW_HIDE);
							else if (time == 10)ShellExecute(NULL, NULL, _T("shutdown"), _T("-s -t 2400 -hybrid"), NULL, SW_HIDE);
							else if (time == 11)ShellExecute(NULL, NULL, _T("shutdown"), _T("-s -t 2700 -hybrid"), NULL, SW_HIDE);
							else if (time == 12)ShellExecute(NULL, NULL, _T("shutdown"), _T("-s -t 3000 -hybrid"), NULL, SW_HIDE);
							else if (time == 13)ShellExecute(NULL, NULL, _T("shutdown"), _T("-s -t 3300 -hybrid"), NULL, SW_HIDE);
							else if (time == 14)ShellExecute(NULL, NULL, _T("shutdown"), _T("-s -t 3600 -hybrid"), NULL, SW_HIDE);
						}
						else if (form == 2) {
							if (time == 1)ShellExecute(NULL, NULL, _T("shutdown"), _T("-r -t 5"), NULL, SW_HIDE);
							else if (time == 2)ShellExecute(NULL, NULL, _T("shutdown"), _T("-r -t 60"), NULL, SW_HIDE);
							else if (time == 3)ShellExecute(NULL, NULL, _T("shutdown"), _T("-r -t 300"), NULL, SW_HIDE);
							else if (time == 4)ShellExecute(NULL, NULL, _T("shutdown"), _T("-r -t 600"), NULL, SW_HIDE);
							else if (time == 5)ShellExecute(NULL, NULL, _T("shutdown"), _T("-r -t 900"), NULL, SW_HIDE);
							else if (time == 6)ShellExecute(NULL, NULL, _T("shutdown"), _T("-r -t 1200"), NULL, SW_HIDE);
							else if (time == 7)ShellExecute(NULL, NULL, _T("shutdown"), _T("-r -t 1500"), NULL, SW_HIDE);
							else if (time == 8)ShellExecute(NULL, NULL, _T("shutdown"), _T("-r -t 1800"), NULL, SW_HIDE);
							else if (time == 9)ShellExecute(NULL, NULL, _T("shutdown"), _T("-r -t 2100"), NULL, SW_HIDE);
							else if (time == 10)ShellExecute(NULL, NULL, _T("shutdown"), _T("-r -t 2400"), NULL, SW_HIDE);
							else if (time == 11)ShellExecute(NULL, NULL, _T("shutdown"), _T("-r -t 2700"), NULL, SW_HIDE);
							else if (time == 12)ShellExecute(NULL, NULL, _T("shutdown"), _T("-r -t 3000"), NULL, SW_HIDE);
							else if (time == 13)ShellExecute(NULL, NULL, _T("shutdown"), _T("-r -t 3300"), NULL, SW_HIDE);
							else if (time == 14)ShellExecute(NULL, NULL, _T("shutdown"), _T("-r -t 3600"), NULL, SW_HIDE);
						}
						else if (form == 3) {
							if (time == 1)ShellExecute(NULL, NULL, _T("shutdown"), _T("-s -t 5"), NULL, SW_HIDE);
							else if (time == 2)ShellExecute(NULL, NULL, _T("shutdown"), _T("-s -t 60"), NULL, SW_HIDE);
							else if (time == 3)ShellExecute(NULL, NULL, _T("shutdown"), _T("-s -t 300"), NULL, SW_HIDE);
							else if (time == 4)ShellExecute(NULL, NULL, _T("shutdown"), _T("-s -t 600"), NULL, SW_HIDE);
							else if (time == 5)ShellExecute(NULL, NULL, _T("shutdown"), _T("-s -t 900"), NULL, SW_HIDE);
							else if (time == 6)ShellExecute(NULL, NULL, _T("shutdown"), _T("-s -t 1200"), NULL, SW_HIDE);
							else if (time == 7)ShellExecute(NULL, NULL, _T("shutdown"), _T("-s -t 1500"), NULL, SW_HIDE);
							else if (time == 8)ShellExecute(NULL, NULL, _T("shutdown"), _T("-s -t 1800"), NULL, SW_HIDE);
							else if (time == 9)ShellExecute(NULL, NULL, _T("shutdown"), _T("-s -t 2100"), NULL, SW_HIDE);
							else if (time == 10)ShellExecute(NULL, NULL, _T("shutdown"), _T("-s -t 2400"), NULL, SW_HIDE);
							else if (time == 11)ShellExecute(NULL, NULL, _T("shutdown"), _T("-s -t 2700"), NULL, SW_HIDE);
							else if (time == 12)ShellExecute(NULL, NULL, _T("shutdown"), _T("-s -t 3000"), NULL, SW_HIDE);
							else if (time == 13)ShellExecute(NULL, NULL, _T("shutdown"), _T("-s -t 3300"), NULL, SW_HIDE);
							else if (time == 14)ShellExecute(NULL, NULL, _T("shutdown"), _T("-s -t 3600"), NULL, SW_HIDE);
						}
						else if (form == 4) {
							if (time == 1)ShellExecute(NULL, NULL, _T("shutdown"), _T("-r -o -t 5"), NULL, SW_HIDE);
							else if (time == 2)ShellExecute(NULL, NULL, _T("shutdown"), _T("-r -o -t 60"), NULL, SW_HIDE);
							else if (time == 3)ShellExecute(NULL, NULL, _T("shutdown"), _T("-r -o -t 300"), NULL, SW_HIDE);
							else if (time == 4)ShellExecute(NULL, NULL, _T("shutdown"), _T("-r -o -t 600"), NULL, SW_HIDE);
							else if (time == 5)ShellExecute(NULL, NULL, _T("shutdown"), _T("-r -o -t 900"), NULL, SW_HIDE);
							else if (time == 6)ShellExecute(NULL, NULL, _T("shutdown"), _T("-r -o -t 1200"), NULL, SW_HIDE);
							else if (time == 7)ShellExecute(NULL, NULL, _T("shutdown"), _T("-r -o -t 1500"), NULL, SW_HIDE);
							else if (time == 8)ShellExecute(NULL, NULL, _T("shutdown"), _T("-r -o -t 1800"), NULL, SW_HIDE);
							else if (time == 9)ShellExecute(NULL, NULL, _T("shutdown"), _T("-r -o -t 2100"), NULL, SW_HIDE);
							else if (time == 10)ShellExecute(NULL, NULL, _T("shutdown"), _T("-r -o -t 2400"), NULL, SW_HIDE);
							else if (time == 11)ShellExecute(NULL, NULL, _T("shutdown"), _T("-r -o -t 2700"), NULL, SW_HIDE);
							else if (time == 12)ShellExecute(NULL, NULL, _T("shutdown"), _T("-r -o -t 3000"), NULL, SW_HIDE);
							else if (time == 13)ShellExecute(NULL, NULL, _T("shutdown"), _T("-r -o -t 3300"), NULL, SW_HIDE);
							else if (time == 14)ShellExecute(NULL, NULL, _T("shutdown"), _T("-r -o -t 3600"), NULL, SW_HIDE);
						}
						MessageBox(NULL, _T("执行成功！"), _T("执行成功"), MB_OK | MB_ICONASTERISK);
					}
				}
				break;
			case 5:
				return;
				break;
			case 6:
				outtextxy(150, 250, _T("5秒                   "));
				time = 1;
				break;
			case 7:
				outtextxy(150, 250, _T("1分钟                  "));
				time = 2;
				break;
			case 8:
				outtextxy(150, 250, _T("5分钟                  "));
				time = 3;
				break;
			case 9:
				outtextxy(150, 250, _T("10分钟                 "));
				time = 4;
				break;
			case 10:
				outtextxy(150, 250, _T("15分钟                 "));
				time = 5;
				break;
			case 11:
				outtextxy(150, 250, _T("20分钟                 "));
				time = 6;
				break;
			case 12:
				outtextxy(150, 250, _T("25分钟                 "));
				time = 7;
				break;
			case 13:
				outtextxy(150, 250, _T("30分钟                 "));
				time = 8;
				break;
			case 14:
				outtextxy(150, 250, _T("35分钟                 "));
				time = 9;
				break;
			case 15:
				outtextxy(150, 250, _T("40分钟                 "));
				time = 10;
				break;
			case 16:
				outtextxy(150, 250, _T("45分钟                 "));
				time = 11;
				break;
			case 17:
				outtextxy(150, 250, _T("50分钟                 "));
				time = 12;
				break;
			case 18:
				outtextxy(150, 250, _T("55分钟                 "));
				time = 13;
				break;
			case 19:
				outtextxy(150, 250, _T("60分钟                 "));
				time = 14;
				break;
			case 20:
				ShellExecute(NULL, NULL, _T("shutdown"), _T("-a"), NULL, SW_HIDE);
				MessageBox(NULL, _T("执行成功！"), _T("执行成功"), MB_OK | MB_ICONASTERISK);
				break;
			case 21:
				ShellExecute(NULL, NULL, _T("shutdown"), _T("-i"), NULL, SW_SHOW);
				break;
			case 22:
				outtextxy(150, 60, _T("转到高级启动选项菜单并重新启动计算机"));
				form = 4;
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
	return;
}
int start() {
	printf("遇见竹子\nMCjiaozi Copyright (C) 2020\n\n正在启动程序. . .");
	FILE* fp = fopen("license", "r");//从缓存读取版本号
	if (fp == NULL) {
		ShellExecute(NULL, NULL, _T("cmd"), _T("/c echo F>license"), NULL, SW_HIDE);
		printf("\n\n错误：找不到所需的文件！");
		int cad = MessageBox(NULL, _T("启动失败！\n找不到所需的文件！\n程序已尝试重新创建该文件，请单击“重试”以重新加载程序，如果问题仍未解决，请重新安装程序！"), _T("错误"), MB_RETRYCANCEL | MB_ICONERROR);
		if (cad == IDRETRY) {
			system("cls");
			return 1;
		}
		exit(0);
	}//如果读取的版本号为NULL，则报错
	char ch;
	ch = getc(fp);
	fclose(fp);
	int newestversion = ch;
	if (ch == 84) {
		printf("\n启动成功！\n\n");
		return 0;
	}
	else if (ch != 84) {
		int cat = MessageBox(NULL, _T("您尚未同意《开源许可证》。\n要使用本程序，您必须阅读并同意《开源许可证》。\n要阅读《开源许可证》，请访问：https://www.mcjiaozi.icu/download/software/bamboo/LICENSE。\n您同意《开源许可证》吗？"), _T("同意《开源许可证》"), MB_YESNO | MB_ICONASTERISK);
		if (cat == IDYES) {
			ShellExecute(NULL, NULL, _T("cmd"), _T("/c echo T>license"), NULL, SW_HIDE);
			int car = MessageBox(NULL, _T("您已同意《开源许可证》。\n一般情况下，本次同意后下次启动不会弹出该询问框。但如果您在本次同意后下次启动仍弹出同样的询问框，请单击“确定”，然后在记事本内清除所有文字，将文件内容改为“T”（不含引号）并保存文件（若弹出另存为请保存至安装目录）。如果未出现此类问题，请单击“取消”。"), _T("谢谢！"), MB_OKCANCEL | MB_ICONWARNING);
			if (car == IDOK) {
				ShellExecute(NULL, NULL, _T("cmd"), _T("/c notepad LICENSE"), NULL, SW_HIDE);
			}
			return 0;
		}
		else if (cat == IDNO) {
			printf("\n\n错误：要使用本程序，您必须阅读并同意《开源许可证》。");
			int cad = MessageBox(NULL, _T("要使用本程序，您必须阅读并同意《开源许可证》。"), _T("错误"), MB_OK | MB_ICONERROR);
			exit(0);
		}
	}
}
int main()
{
	if (start() == 1)main();
	int i, event = 0;
	short win_width, win_height;//定义窗口的宽度和高度
	win_width = 720; win_height = 560;
	initgraph(win_width, win_height);//初始化窗口（黑屏）
	HWND hWnd = GetHWnd();
	SetWindowText(hWnd, "遇见竹子");
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
	RECT R6 = { r[5][0],r[5][1],r[5][2],r[5][3] };
	RECT R7 = { r[6][0],r[6][1],r[6][2],r[6][3] };
	RECT R8 = { r[7][0],r[7][1],r[7][2],r[7][3] };
	RECT R9 = { r[8][0],r[8][1],r[8][2],r[8][3] };
	RECT R10 = { r[9][0],r[9][1],r[9][2],r[9][3] };
	RECT R11 = { r[10][0],r[10][1],r[10][2],r[10][3] };
	RECT R12 = { r[11][0],r[11][1],r[11][2],r[11][3] };
	LOGFONT f;
	gettextstyle(&f);					//获取字体样式
	_tcscpy(f.lfFaceName, _T("宋体"));	//设置字体为宋体
	f.lfQuality = ANTIALIASED_QUALITY;    // 设置输出效果为抗锯齿  
	settextstyle(&f);                     // 设置字体样式
	settextcolor(BLACK);				//BLACK在graphic.h头文件里面被定义为黑色的颜色常量
	drawtext("开源许可证", &R1, DT_CENTER | DT_VCENTER | DT_SINGLELINE);//在矩形区域R1内输入文字，水平居中，垂直居中，单行显示
	drawtext("Github开源", &R2, DT_CENTER | DT_VCENTER | DT_SINGLELINE);//在矩形区域R2内输入文字，水平居中，垂直居中，单行显示
	drawtext("退出", &R3, DT_CENTER | DT_VCENTER | DT_SINGLELINE);//在矩形区域R3内输入文字，水平居中，垂直居中，单行显示
	drawtext("检查更新", &R4, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
	drawtext("更新日志", &R5, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
	drawtext("访问官网", &R6, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
	drawtext("查看系统信息", &R7, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
	drawtext("打开命令提示符", &R8, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
	drawtext("打开PowerShell", &R9, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
	drawtext("刷新DNS解析缓存", &R10, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
	drawtext("软件信息", &R11, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
	drawtext("定时关机. . . ", &R12, DT_CENTER | DT_VCENTER | DT_SINGLELINE);

	settextstyle(50, 0, _T("黑体"), NULL, NULL, 300, false, false, false);
	outtextxy(0, 0, _T("遇见竹子"));
	settextstyle(30, 0, _T("黑体"), NULL, NULL, 300, false, false, false);
	outtextxy(0, 160, _T("工具"));

	setlinecolor(BLACK);
	rectangle(r[0][0], r[0][1], r[0][2], r[0][3]);
	rectangle(r[1][0], r[1][1], r[1][2], r[1][3]);
	rectangle(r[2][0], r[2][1], r[2][2], r[2][3]);
	rectangle(r[3][0], r[3][1], r[3][2], r[3][3]);
	rectangle(r[4][0], r[4][1], r[4][2], r[4][3]);
	rectangle(r[5][0], r[5][1], r[5][2], r[5][3]);
	rectangle(r[6][0], r[6][1], r[6][2], r[6][3]);
	rectangle(r[7][0], r[7][1], r[7][2], r[7][3]);
	rectangle(r[8][0], r[8][1], r[8][2], r[8][3]);
	rectangle(r[9][0], r[9][1], r[9][2], r[9][3]);
	rectangle(r[10][0], r[10][1], r[10][2], r[10][3]);
	rectangle(r[11][0], r[11][1], r[11][2], r[11][3]);
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
				ShellExecute(NULL, NULL, _T("cmd"), _T("/c md \\bambooDownload"), NULL, SW_HIDE);
				if (S_OK != URLDownloadToFile(NULL, _T("https://www.mcjiaozi.icu/download/software/bamboo/LICENSE"), _T("\\bambooDownload\\LICENSE"), 0, 0)) {
					MessageBox(NULL, _T("从服务器获取开源许可证失败！\n请前往我的网站获取开源许可证！\n开源许可证位置：https://www.mcjiaozi.icu/download/software/bamboo/LICENSE。"), _T("错误"), MB_OK | MB_ICONERROR);
				}
				ShellExecute(NULL, NULL, _T("cmd"), _T("/c notepad \\bambooDownload\\LICENSE"), NULL, SW_HIDE);
				break;
			case 2:
				ShellExecute(NULL, NULL, _T("https://www.mcjiaozi.icu/github/"), NULL, NULL, SW_HIDE);
				break;
			case 3:
				//closegraph();关闭绘图环境
				exit(0);//正常退出
			case 4:
				update();
				break;
			case 5:
				DeleteUrlCacheEntry(_T("https://www.mcjiaozi.icu/download/software/bamboo/changelog.txt"));
				ShellExecute(NULL, NULL, _T("cmd"), _T("/c md \\bambooDownload"), NULL, SW_HIDE);
				if (S_OK != URLDownloadToFile(NULL, _T("https://www.mcjiaozi.icu/download/software/bamboo/changelog.txt"), _T("\\bambooDownload\\changelog.txt"), 0, 0)) {
					MessageBox(NULL, _T("从服务器获取更新日志失败！\n请前往我的网站获取更新日志！\n更新日志位置：https://www.mcjiaozi.icu/download/software/bamboo/changelog.txt。"), _T("错误"), MB_OK | MB_ICONERROR);
				}
				ShellExecute(NULL, NULL, _T("cmd"), _T("/c start \\bambooDownload\\changelog.txt"), NULL, SW_HIDE);
				break;
			case 6:
				ShellExecute(NULL, NULL, _T("https://www.mcjiaozi.icu/"), NULL, NULL, SW_HIDE);
				break;
			case 7:
				ShellExecute(NULL, NULL, _T("cmd"), _T("/c systeminfo&&pause"), NULL, SW_SHOW);
				break;
			case 8:
				ShellExecute(NULL, NULL, _T("cmd"), NULL, NULL, SW_SHOW);
				break;
			case 9:
				ShellExecute(NULL, NULL, _T("powershell"), NULL, NULL, SW_SHOW);
				break;
			case 10:
				ShellExecute(NULL, NULL, _T("ipconfig"), _T("/flushdns"), NULL, SW_HIDE);
				MessageBox(NULL, _T("已成功刷新 DNS 解析缓存。"), _T("Windows IP 配置"), MB_OK | MB_ICONASTERISK);
				break;
			case 11:
				MessageBox(NULL, _T("软件名：遇见竹子\n版本：V5.4.1.1\n官方网站：https://www.mcjiaozi.icu\n官方软件发布页（非唯一）：https://www.mcjiaozi.icu/download/software/bamboo/\n《开源许可证》：https://www.mcjiaozi.icu/download/software/bamboo/LICENSE\n联系我：https://www.mcjiaozi.icu/connect/\nMCjiaozi Copyright (C) 2020"), _T("软件信息"), MB_OK | MB_ICONASTERISK);
				break;
			case 12:
				shutdown();
				main();
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
	return 0;
}
