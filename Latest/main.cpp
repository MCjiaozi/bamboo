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
		MessageBox(NULL, _T("������ʧ�ܣ�\n��ǰ�����߸�����վ��"), _T("����"), MB_OK | MB_ICONERROR);
		return;
	}
	FILE* fp = fopen("\\bambooDownload\\version.txt", "r");//�ӻ����ȡ�汾��
	if (fp == NULL) {
		MessageBox(NULL, _T("������ʧ�ܣ��޷���ȡ���߰汾�ţ�\n��ǰ�����߸�����վ��"), _T("����"), MB_OK | MB_ICONERROR);
		return;
	}//�����ȡ�İ汾��ΪNULL���򱨴�
	char ch;
	ch = getc(fp);
	fclose(fp);
	int newestversion = ch;
	if (ch > 53) {
		int updateaa = MessageBox(NULL, _T("���°汾���ã�Ҫ������\n���ȷ�����ؽ���ʼ��"), _T("������"), MB_OKCANCEL | MB_ICONQUESTION);
		if (updateaa == IDOK) {
			DeleteUrlCacheEntry(_T("https://www.mcjiaozi.icu/download/software/bamboo/preview/bamboo_installer_pre.exe"));
			if (S_OK != URLDownloadToFile(NULL, _T("https://www.mcjiaozi.icu/download/software/bamboo/preview/bamboo_installer_pre.exe"), _T("\\bambooDownload\\bamboo_installer_pre.exe"), 0, 0)) {
				MessageBox(NULL, _T("���ظ���ʧ�ܣ�\n��ǰ�����߸�����վ��"), _T("����"), MB_OK | MB_ICONERROR);
				return;
			}
			ShellExecute(NULL, NULL, _T("cmd"), _T("/c start \\bambooDownload\\bamboo_installer_pre.exe"), NULL, SW_HIDE);
			return;
		}
		else if (updateaa == 0) {
			MessageBox(NULL, _T("�ڴ治��!"), _T("����"), MB_OK | MB_ICONERROR);
			return;
		}
		else return;

	}
	else if (ch == 53) {
		MessageBox(NULL, _T("���Ŀͻ��������°汾��"), _T("������"), MB_OK | MB_ICONASTERISK);
		return;
	}
	else if (ch < 53) {
		MessageBox(NULL, _T("������ʧ�ܣ�\n���߰汾�Ų�Ӧ���ڱ��ذ汾�ţ�"), _T("����"), MB_OK | MB_ICONERROR);
		return;
	}
	else return;
	return;
}
int r[12][4] = { {30,110,120,150},{130,110,220,150},{230,110,320,150},{30,60,120,100},{130,60,220,100},{230,60,320,100},{30,200,150,240},{160,200,290,240},{300,200,430,240},{440,200,570,240},{330,60,420,100},{580,200,710,240} };//������ť�Ķ�ά����
int rd[22][4] = { {30,100,200,140},{30,150,200,190},{30,200,200,240},{230,10,320,50},{330,10,420,50},{30,290,120,330},{130,290,220,330},{230,290,320,330},{330,290,420,330},{430,290,520,330},{530,290,620,330},{630,290,720,330},{30,340,120,380},{130,340,220,380},{230,340,320,380},{330,340,420,380},{430,340,520,380},{530,340,620,380},{630,340,720,380},{30,430,200,470},{210,430,380,470},{210,100,600,140} };//������ť�Ķ�ά����
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
	short win_width, win_height;//���崰�ڵĿ�Ⱥ͸߶�
	win_width = 740; win_height = 560;
	initgraph(win_width, win_height);//��ʼ�����ڣ�������
	HWND hWnd = GetHWnd();
	SetWindowText(hWnd, "�������� - ��ʱ�ػ�");
	setbkcolor(RGB(255, 255, 255));//���ñ���ɫ��ԭ��Ĭ�Ϻ�ɫ
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
	gettextstyle(&f);					//��ȡ������ʽ
	_tcscpy(f.lfFaceName, _T("����"));	//��������Ϊ����
	f.lfQuality = ANTIALIASED_QUALITY;    // �������Ч��Ϊ�����  
	settextstyle(&f);                     // ����������ʽ
	settextcolor(BLACK);				//BLACK��graphic.hͷ�ļ����汻����Ϊ��ɫ����ɫ����
	drawtext("�رռ����(��������)", &R1, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
	drawtext("��ȫ�رղ����������", &R2, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
	drawtext("��ȫ�رռ����", &R3, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
	drawtext("����", &R4, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
	drawtext("����", &R5, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
	drawtext("5��", &R6, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
	drawtext("1����", &R7, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
	drawtext("5����", &R8, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
	drawtext("10����", &R9, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
	drawtext("15����", &R10, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
	drawtext("20����", &R11, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
	drawtext("25����", &R12, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
	drawtext("30����", &R13, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
	drawtext("35����", &R14, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
	drawtext("40����", &R15, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
	drawtext("45����", &R16, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
	drawtext("50����", &R17, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
	drawtext("55����", &R18, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
	drawtext("60����", &R19, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
	drawtext("��ֹϵͳ�ر�", &R20, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
	drawtext("��ʾͼ���û�����(GUI)", &R21, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
	drawtext("ת���߼�����ѡ��˵����������������", &R22, DT_CENTER | DT_VCENTER | DT_SINGLELINE);

	settextstyle(50, 0, _T("����"), NULL, NULL, 300, false, false, false);
	outtextxy(0, 0, _T("��ʱ�ػ�"));
	settextstyle(30, 0, _T("����"), NULL, NULL, 300, false, false, false);
	outtextxy(0, 60, _T("ѡ�����ͣ���ѡ��"));
	outtextxy(0, 250, _T("��ʱʱ�䣺��ѡ��"));
	outtextxy(0, 390, _T("�߼�ѡ��"));
	settextstyle(16, 0, _T("����"), NULL, NULL, 300, true, false, false);
	outtextxy(0, 500, _T("*ĳЩѡ�����        �п���"));
	outtextxy(0, 516, _T("*�߼�ѡ������    ����"));
	settextcolor(RGB(255, 0, 0));
	outtextxy(105, 500, _T("�ض�ϵͳ"));
	outtextxy(120, 516, _T("ֱ��"));
	settextstyle(30, 0, _T("����"), NULL, NULL, 300, false, false, false);
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
	MOUSEMSG m;//���ָ��

	while (true)
	{
		m = GetMouseMsg();//��ȡһ�������Ϣ

		switch (m.uMsg)
		{
		case WM_MOUSEMOVE:
			setrop2(R2_XORPEN);
			setlinecolor(LIGHTCYAN);//������ɫΪ����ɫ
			setlinestyle(PS_SOLID, 3);//���û�����ʽΪʵ�֣�10��
			setfillcolor(WHITE);//�����ɫΪ��ɫ
			if (button_judger(m.x, m.y) != 0)
			{
				if (event != button_judger(m.x, m.y))
				{
					event = button_judger(m.x, m.y);//��¼��һ�δ����İ�ť
					fillrectangle(rd[event - 1][0], rd[event - 1][1], rd[event - 1][2], rd[event - 1][3]);//�п������Σ�X1,Y1,X2,Y2��
				}
			}
			else
			{
				if (event != 0)//�ϴδ����İ�ťδ������Ϊԭ������ɫ
				{
					fillrectangle(rd[event - 1][0], rd[event - 1][1], rd[event - 1][2], rd[event - 1][3]);//����ͬ��Ϊԭ����ɫ
					event = 0;
				}
			}
			break;
		case WM_LBUTTONDOWN:
			setrop2(R2_NOTXORPEN);//��Ԫ��դ����NOT(��Ļ��ɫ XOR ��ǰ��ɫ)
			for (i = 0; i <= 10; i++)
			{
				setlinecolor(RGB(25 * i, 25 * i, 25 * i));//����Բ��ɫ
				circle(m.x, m.y, 2 * i);
				Sleep(20);//ͣ��30ms
				circle(m.x, m.y, 2 * i);//Ĩȥ�ոջ���Բ
			}
			//���հ�ť�ж����������Ĳ���
			switch (button_judger(m.x, m.y))
			{
				//��ԭ��ťԭ��
			case 1:
				outtextxy(150, 60, _T("�رռ����(��������)                "));
				form = 1;
				break;
			case 2:
				outtextxy(150, 60, _T("��ȫ�رղ����������                "));
				form = 2;
				break;
			case 3:
				outtextxy(150, 60, _T("��ȫ�رռ����                      "));
				form = 3;
				break;
			case 4:
				if (form == 0) {
					MessageBox(NULL, _T("��ѡ�����ͣ�"), _T("����"), MB_OK | MB_ICONERROR);
				}
				else if (time == 0) {
					MessageBox(NULL, _T("��ѡ��ʱʱ�䣡"), _T("����"), MB_OK | MB_ICONERROR);
				}
				else {
					real = MessageBox(NULL, _T("��ȷʵҪִ�д˲�����"), _T("����"), MB_OKCANCEL | MB_ICONWARNING);
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
						MessageBox(NULL, _T("ִ�гɹ���"), _T("ִ�гɹ�"), MB_OK | MB_ICONASTERISK);
					}
				}
				break;
			case 5:
				return;
				break;
			case 6:
				outtextxy(150, 250, _T("5��                   "));
				time = 1;
				break;
			case 7:
				outtextxy(150, 250, _T("1����                  "));
				time = 2;
				break;
			case 8:
				outtextxy(150, 250, _T("5����                  "));
				time = 3;
				break;
			case 9:
				outtextxy(150, 250, _T("10����                 "));
				time = 4;
				break;
			case 10:
				outtextxy(150, 250, _T("15����                 "));
				time = 5;
				break;
			case 11:
				outtextxy(150, 250, _T("20����                 "));
				time = 6;
				break;
			case 12:
				outtextxy(150, 250, _T("25����                 "));
				time = 7;
				break;
			case 13:
				outtextxy(150, 250, _T("30����                 "));
				time = 8;
				break;
			case 14:
				outtextxy(150, 250, _T("35����                 "));
				time = 9;
				break;
			case 15:
				outtextxy(150, 250, _T("40����                 "));
				time = 10;
				break;
			case 16:
				outtextxy(150, 250, _T("45����                 "));
				time = 11;
				break;
			case 17:
				outtextxy(150, 250, _T("50����                 "));
				time = 12;
				break;
			case 18:
				outtextxy(150, 250, _T("55����                 "));
				time = 13;
				break;
			case 19:
				outtextxy(150, 250, _T("60����                 "));
				time = 14;
				break;
			case 20:
				ShellExecute(NULL, NULL, _T("shutdown"), _T("-a"), NULL, SW_HIDE);
				MessageBox(NULL, _T("ִ�гɹ���"), _T("ִ�гɹ�"), MB_OK | MB_ICONASTERISK);
				break;
			case 21:
				ShellExecute(NULL, NULL, _T("shutdown"), _T("-i"), NULL, SW_SHOW);
				break;
			case 22:
				outtextxy(150, 60, _T("ת���߼�����ѡ��˵����������������"));
				form = 4;
				break;
			default:
				FlushMouseMsgBuffer();//�����¼�����������Ϣ
				//printf("\r\n(%d,%d)",m.x,m.y);//��ӡ������꣬�������ʱȷ������
				break;
			}
			break;
			FlushMouseMsgBuffer();//��������Ϣ������
		}
	}
	return;
}
int start() {
	printf("��������\nMCjiaozi Copyright (C) 2020\n\n������������. . .");
	FILE* fp = fopen("license", "r");//�ӻ����ȡ�汾��
	if (fp == NULL) {
		ShellExecute(NULL, NULL, _T("cmd"), _T("/c echo F>license"), NULL, SW_HIDE);
		printf("\n\n�����Ҳ���������ļ���");
		int cad = MessageBox(NULL, _T("����ʧ�ܣ�\n�Ҳ���������ļ���\n�����ѳ������´������ļ����뵥�������ԡ������¼��س������������δ����������°�װ����"), _T("����"), MB_RETRYCANCEL | MB_ICONERROR);
		if (cad == IDRETRY) {
			system("cls");
			return 1;
		}
		exit(0);
	}//�����ȡ�İ汾��ΪNULL���򱨴�
	char ch;
	ch = getc(fp);
	fclose(fp);
	int newestversion = ch;
	if (ch == 84) {
		printf("\n�����ɹ���\n\n");
		return 0;
	}
	else if (ch != 84) {
		int cat = MessageBox(NULL, _T("����δͬ�⡶��Դ���֤����\nҪʹ�ñ������������Ķ���ͬ�⡶��Դ���֤����\nҪ�Ķ�����Դ���֤��������ʣ�https://www.mcjiaozi.icu/download/software/bamboo/LICENSE��\n��ͬ�⡶��Դ���֤����"), _T("ͬ�⡶��Դ���֤��"), MB_YESNO | MB_ICONASTERISK);
		if (cat == IDYES) {
			ShellExecute(NULL, NULL, _T("cmd"), _T("/c echo T>license"), NULL, SW_HIDE);
			int car = MessageBox(NULL, _T("����ͬ�⡶��Դ���֤����\nһ������£�����ͬ����´��������ᵯ����ѯ�ʿ򡣵�������ڱ���ͬ����´������Ե���ͬ����ѯ�ʿ��뵥����ȷ������Ȼ���ڼ��±�������������֣����ļ����ݸ�Ϊ��T�����������ţ��������ļ������������Ϊ�뱣������װĿ¼�������δ���ִ������⣬�뵥����ȡ������"), _T("лл��"), MB_OKCANCEL | MB_ICONWARNING);
			if (car == IDOK) {
				ShellExecute(NULL, NULL, _T("cmd"), _T("/c notepad LICENSE"), NULL, SW_HIDE);
			}
			return 0;
		}
		else if (cat == IDNO) {
			printf("\n\n����Ҫʹ�ñ������������Ķ���ͬ�⡶��Դ���֤����");
			int cad = MessageBox(NULL, _T("Ҫʹ�ñ������������Ķ���ͬ�⡶��Դ���֤����"), _T("����"), MB_OK | MB_ICONERROR);
			exit(0);
		}
	}
}
int main()
{
	if (start() == 1)main();
	int i, event = 0;
	short win_width, win_height;//���崰�ڵĿ�Ⱥ͸߶�
	win_width = 720; win_height = 560;
	initgraph(win_width, win_height);//��ʼ�����ڣ�������
	HWND hWnd = GetHWnd();
	SetWindowText(hWnd, "��������");
	for (i = 0; i < 256; i += 5)
	{
		setbkcolor(RGB(i, i, i));//���ñ���ɫ��ԭ��Ĭ�Ϻ�ɫ
		cleardevice();//������ȡ���ڱ���ɫ��
		Sleep(15);//��ʱ15ms
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
	gettextstyle(&f);					//��ȡ������ʽ
	_tcscpy(f.lfFaceName, _T("����"));	//��������Ϊ����
	f.lfQuality = ANTIALIASED_QUALITY;    // �������Ч��Ϊ�����  
	settextstyle(&f);                     // ����������ʽ
	settextcolor(BLACK);				//BLACK��graphic.hͷ�ļ����汻����Ϊ��ɫ����ɫ����
	drawtext("��Դ���֤", &R1, DT_CENTER | DT_VCENTER | DT_SINGLELINE);//�ھ�������R1���������֣�ˮƽ���У���ֱ���У�������ʾ
	drawtext("Github��Դ", &R2, DT_CENTER | DT_VCENTER | DT_SINGLELINE);//�ھ�������R2���������֣�ˮƽ���У���ֱ���У�������ʾ
	drawtext("�˳�", &R3, DT_CENTER | DT_VCENTER | DT_SINGLELINE);//�ھ�������R3���������֣�ˮƽ���У���ֱ���У�������ʾ
	drawtext("������", &R4, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
	drawtext("������־", &R5, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
	drawtext("���ʹ���", &R6, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
	drawtext("�鿴ϵͳ��Ϣ", &R7, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
	drawtext("��������ʾ��", &R8, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
	drawtext("��PowerShell", &R9, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
	drawtext("ˢ��DNS��������", &R10, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
	drawtext("�����Ϣ", &R11, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
	drawtext("��ʱ�ػ�. . . ", &R12, DT_CENTER | DT_VCENTER | DT_SINGLELINE);

	settextstyle(50, 0, _T("����"), NULL, NULL, 300, false, false, false);
	outtextxy(0, 0, _T("��������"));
	settextstyle(30, 0, _T("����"), NULL, NULL, 300, false, false, false);
	outtextxy(0, 160, _T("����"));

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
	MOUSEMSG m;//���ָ��

	while (true)
	{
		m = GetMouseMsg();//��ȡһ�������Ϣ

		switch (m.uMsg)
		{
		case WM_MOUSEMOVE:
			setrop2(R2_XORPEN);
			setlinecolor(LIGHTCYAN);//������ɫΪ����ɫ
			setlinestyle(PS_SOLID, 3);//���û�����ʽΪʵ�֣�10��
			setfillcolor(WHITE);//�����ɫΪ��ɫ
			if (button_judge(m.x, m.y) != 0)
			{
				if (event != button_judge(m.x, m.y))
				{
					event = button_judge(m.x, m.y);//��¼��һ�δ����İ�ť
					fillrectangle(r[event - 1][0], r[event - 1][1], r[event - 1][2], r[event - 1][3]);//�п������Σ�X1,Y1,X2,Y2��
				}
			}
			else
			{
				if (event != 0)//�ϴδ����İ�ťδ������Ϊԭ������ɫ
				{
					fillrectangle(r[event - 1][0], r[event - 1][1], r[event - 1][2], r[event - 1][3]);//����ͬ��Ϊԭ����ɫ
					event = 0;
				}
			}
			break;
		case WM_LBUTTONDOWN:
			setrop2(R2_NOTXORPEN);//��Ԫ��դ����NOT(��Ļ��ɫ XOR ��ǰ��ɫ)
			for (i = 0; i <= 10; i++)
			{
				setlinecolor(RGB(25 * i, 25 * i, 25 * i));//����Բ��ɫ
				circle(m.x, m.y, 2 * i);
				Sleep(20);//ͣ��30ms
				circle(m.x, m.y, 2 * i);//Ĩȥ�ոջ���Բ
			}
			//���հ�ť�ж����������Ĳ���
			switch (button_judge(m.x, m.y))
			{
				//��ԭ��ťԭ��
			case 1:
				DeleteUrlCacheEntry(_T("https://www.mcjiaozi.icu/download/software/bamboo/LICENSE"));
				ShellExecute(NULL, NULL, _T("cmd"), _T("/c md \\bambooDownload"), NULL, SW_HIDE);
				if (S_OK != URLDownloadToFile(NULL, _T("https://www.mcjiaozi.icu/download/software/bamboo/LICENSE"), _T("\\bambooDownload\\LICENSE"), 0, 0)) {
					MessageBox(NULL, _T("�ӷ�������ȡ��Դ���֤ʧ�ܣ�\n��ǰ���ҵ���վ��ȡ��Դ���֤��\n��Դ���֤λ�ã�https://www.mcjiaozi.icu/download/software/bamboo/LICENSE��"), _T("����"), MB_OK | MB_ICONERROR);
				}
				ShellExecute(NULL, NULL, _T("cmd"), _T("/c notepad \\bambooDownload\\LICENSE"), NULL, SW_HIDE);
				break;
			case 2:
				ShellExecute(NULL, NULL, _T("https://www.mcjiaozi.icu/github/"), NULL, NULL, SW_HIDE);
				break;
			case 3:
				//closegraph();�رջ�ͼ����
				exit(0);//�����˳�
			case 4:
				update();
				break;
			case 5:
				DeleteUrlCacheEntry(_T("https://www.mcjiaozi.icu/download/software/bamboo/changelog.txt"));
				ShellExecute(NULL, NULL, _T("cmd"), _T("/c md \\bambooDownload"), NULL, SW_HIDE);
				if (S_OK != URLDownloadToFile(NULL, _T("https://www.mcjiaozi.icu/download/software/bamboo/changelog.txt"), _T("\\bambooDownload\\changelog.txt"), 0, 0)) {
					MessageBox(NULL, _T("�ӷ�������ȡ������־ʧ�ܣ�\n��ǰ���ҵ���վ��ȡ������־��\n������־λ�ã�https://www.mcjiaozi.icu/download/software/bamboo/changelog.txt��"), _T("����"), MB_OK | MB_ICONERROR);
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
				MessageBox(NULL, _T("�ѳɹ�ˢ�� DNS �������档"), _T("Windows IP ����"), MB_OK | MB_ICONASTERISK);
				break;
			case 11:
				MessageBox(NULL, _T("���������������\n�汾��V5.4.1.1\n�ٷ���վ��https://www.mcjiaozi.icu\n�ٷ��������ҳ����Ψһ����https://www.mcjiaozi.icu/download/software/bamboo/\n����Դ���֤����https://www.mcjiaozi.icu/download/software/bamboo/LICENSE\n��ϵ�ң�https://www.mcjiaozi.icu/connect/\nMCjiaozi Copyright (C) 2020"), _T("�����Ϣ"), MB_OK | MB_ICONASTERISK);
				break;
			case 12:
				shutdown();
				main();
				break;
			default:
				FlushMouseMsgBuffer();//�����¼�����������Ϣ
				//printf("\r\n(%d,%d)",m.x,m.y);//��ӡ������꣬�������ʱȷ������
				break;
			}
			break;
			FlushMouseMsgBuffer();//��������Ϣ������
		}
	}
	return 0;
}
