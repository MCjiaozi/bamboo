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
		MessageBox(NULL, _T("������ʧ�ܣ�\n��ǰ�����߸�����վ��"), _T("����"), MB_OK | MB_ICONERROR);
	}
	FILE* fp = fopen("version.txt", "r");//�ӻ����ȡ�汾��
	if (fp == NULL) {
		MessageBox(NULL, _T("������ʧ�ܣ��޷���ȡ���߰汾�ţ�\n��ǰ�����߸�����վ��"), _T("����"), MB_OK | MB_ICONERROR);
		return;
	}//�����ȡ�İ汾��ΪNULL���򱨴�
	char ch;
	ch = getc(fp);
	fclose(fp);
	ShellExecute(NULL, NULL, _T("cmd"), _T("/c del version.txt"), NULL, SW_SHOW);
	int newestversion = ch;
	if (ch > 53) {
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
	else if (ch == 53) {
		MessageBox(NULL, _T("���Ŀͻ��������°汾��"), _T("������"), NULL);
		return;
	}
	else if (ch < 53) {
		MessageBox(NULL, _T("������ʧ�ܣ�\nδ֪����"), _T("����"), MB_OK | MB_ICONERROR);
		return;
	}
	else return;
	return;
}

int r[5][4] = { {30,110,120,150},{130,110,220,150},{230,110,320,150},{30,60,120,100},{130,60,220,100} };//������ť�Ķ�ά����

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
	short win_width, win_height;//���崰�ڵĿ�Ⱥ͸߶�
	win_width = 720; win_height = 560;
	initgraph(win_width, win_height);//��ʼ�����ڣ�������
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
	LOGFONT f;
	gettextstyle(&f);					//��ȡ������ʽ
	_tcscpy(f.lfFaceName, _T("����"));	//��������Ϊ����
	f.lfQuality = ANTIALIASED_QUALITY;    // �������Ч��Ϊ�����  
	settextstyle(&f);                     // ����������ʽ
	settextcolor(BLACK);				//BLACK��graphic.hͷ�ļ����汻����Ϊ��ɫ����ɫ����
	drawtext("��Դ���֤", &R1, DT_CENTER | DT_VCENTER | DT_SINGLELINE);//�ھ�������R1���������֣�ˮƽ���У���ֱ���У�������ʾ
	drawtext("��Դ��վ", &R2, DT_CENTER | DT_VCENTER | DT_SINGLELINE);//�ھ�������R2���������֣�ˮƽ���У���ֱ���У�������ʾ
	drawtext("�˳�", &R3, DT_CENTER | DT_VCENTER | DT_SINGLELINE);//�ھ�������R3���������֣�ˮƽ���У���ֱ���У�������ʾ
	drawtext("������", &R4, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
	drawtext("������־", &R5, DT_CENTER | DT_VCENTER | DT_SINGLELINE);

	settextstyle(50, 0, _T("����"), NULL, NULL, 300, false, false, false);
	outtextxy(0, 0, _T("��������"));

	setlinecolor(BLACK);
	rectangle(r[0][0], r[0][1], r[0][2], r[0][3]);
	rectangle(r[1][0], r[1][1], r[1][2], r[1][3]);
	rectangle(r[2][0], r[2][1], r[2][2], r[2][3]);
	rectangle(r[3][0], r[3][1], r[3][2], r[3][3]);
	rectangle(r[4][0], r[4][1], r[4][2], r[4][3]);
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
				ShellExecute(NULL, NULL, _T("cmd"), _T("/c md %temp%\\bamboo"), NULL, SW_SHOW);
				if (S_OK != URLDownloadToFile(NULL, _T("https://www.mcjiaozi.icu/download/software/bamboo/LICENSE"), _T("LICENSE"), 0, 0)) {
					MessageBox(NULL, _T("�ӷ�������ȡ��Դ���֤ʧ�ܣ�\n��ǰ���ҵ���վ��ȡ��Դ���֤��\n��Դ���֤λ�ã�https://www.mcjiaozi.icu/download/software/bamboo/LICENSE��"), _T("����"), MB_OK | MB_ICONERROR);
				}
				ShellExecute(NULL, NULL, _T("cmd"), _T("/c copy LICENSE %temp%\\bamboo\\LICENSE&&del LICENSE&&notepad %temp%\\bamboo\\LICENSE"), NULL, SW_SHOW);
				break;
			case 2:
				ShellExecute(NULL, NULL, _T("https://www.mcjiaozi.icu/github/"), NULL, NULL, SW_SHOW);
				break;
			case 3:
				closegraph();//�رջ�ͼ����
				exit(0);//�����˳�
			case 4:
				update();
				break;
			case 5:
				DeleteUrlCacheEntry(_T("https://www.mcjiaozi.icu/download/software/bamboo/changelog.txt"));
				ShellExecute(NULL, NULL, _T("cmd"), _T("/c md %temp%\\bamboo"), NULL, SW_SHOW);
				if (S_OK != URLDownloadToFile(NULL, _T("https://www.mcjiaozi.icu/download/software/bamboo/changelog.txt"), _T("changelog.txt"), 0, 0)) {
					MessageBox(NULL, _T("�ӷ�������ȡ������־ʧ�ܣ�\n��ǰ���ҵ���վ��ȡ������־��\n������־λ�ã�https://www.mcjiaozi.icu/download/software/bamboo/changelog.txt��"), _T("����"), MB_OK | MB_ICONERROR);
				}
				ShellExecute(NULL, NULL, _T("cmd"), _T("/c copy changelog.txt %temp%\\bamboo\\changelog.txt&&del changelog.txt&&start %temp%\\bamboo\\changelog.txt"), NULL, SW_SHOW);
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
	system("pause");//��ͣ��Ϊ����ʾ
	return 0;
}

