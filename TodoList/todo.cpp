#define _CRT_SECURE_NO_WARNINGS 1
#pragma warning(disable:6031)
#include <easyx.h>
#include <conio.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>
#include <string.h>
#include <iostream>
using namespace std;

#define Width 400
#define Height 650

IMAGE bk[4], title[4];

struct task
{
	char name[50];	//��������
	char time_s[30];	//��ʼʱ��
	char time_f[30];	//����ʱ��
	int starttime;
};
//��������ṹ������
struct task t[30];
struct task tc[30];
//��ǰ�������
int numt = 0;
struct encourage
{
	char sentence[100];
	int number;
};
struct encourage e[20];

//���尴ť�Ĵ�С����
int r1[] = { 100, 190, 300, 240 };
int r2[] = { 100, 260, 300, 310 };
int r3[] = { 100, 330, 300, 380 };
int r4[] = { 100, 400, 300, 450 };
int r5[] = { 100, 470, 300, 520 };
int r8[] = { 100, 70, 300, 130 };
int r9[] = { 100, 180, 300, 240 };
int r10[] = { 100, 290, 300, 350 };

void menu();		//������
void Inputtodo();	//¼�����
void Savetodo();	//�������
void Showinit();	//��ʾ�����б�ǰ��׼������
void Showtodo();	//��ʾ�����б�
void Readtodo();	//��ȡ�ļ��еĴ�����Ϣ
void Change();		//����Ķ�
void Moditodo();	//�޸Ĵ���
int Find();			//���Ҵ���
void Savemoditodo();	//�����޸ĺ�Ĵ���
void Deletodo();	//ɾ������
void Encourage();	//���չ���
void bubble_sort(struct task tc[30]);	//ð������
void Originsort();	//¼��˳��

int main()
{
	//������
	menu();
	return 0;
}

void menu()
{
	//��ͼ���ڳ�ʼ��
	initgraph(Width, Height);
	//���ڱ���
	HWND hwnd = GetHWnd();
	SetWindowText(hwnd, _T("���մ���"));

	//�������Ͷ�ȡ���ݣ���ȡ��ǰnumt
	Readtodo();

	//����ͼ
	loadimage(&bk[0], "..\\TodoList\\bk1.jpeg", Width, Height);
	putimage(0, 0, &bk[0]);

	//����ͼ
	loadimage(&title[0], "..\\TodoList\\title1.png", 360, 80);
	loadimage(&title[1], "..\\TodoList\\title1_1.png", 360, 80);
	loadimage(&title[2], "..\\TodoList\\title2.png", 250, 35);
	loadimage(&title[3], "..\\TodoList\\title2_1.png", 250, 35);
	putimage(20, 25, &title[1], SRCAND);	//����ͼ
	putimage(20, 25, &title[0], SRCPAINT);	//ԭͼ
	putimage(75, 125, &title[3], SRCAND);
	putimage(75, 125, &title[2], SRCPAINT);

	//��������ͼƬ
	loadimage(&bk[1], "..\\TodoList\\bk4.jpeg", 690, 480);
	loadimage(&bk[2], "..\\TodoList\\bk2.jpeg", Width, Height);
	loadimage(&bk[3], "..\\TodoList\\bk3.jpeg", 700, 400);

	//���ư�������
	setbkmode(TRANSPARENT);
	setfillcolor(WHITE);
	fillroundrect(r1[0], r1[1], r1[2], r1[3], 20, 20);
	fillroundrect(r2[0], r2[1], r2[2], r2[3], 20, 20);
	fillroundrect(r3[0], r3[1], r3[2], r3[3], 20, 20);
	fillroundrect(r4[0], r4[1], r4[2], r4[3], 20, 20);
	fillroundrect(r5[0], r5[1], r5[2], r5[3], 20, 20);

	//����ָ�룬�������������д��
	RECT R1 = { r1[0], r1[1], r1[2], r1[3] };
	RECT R2 = { r2[0], r2[1], r2[2], r2[3] };
	RECT R3 = { r3[0], r3[1], r3[2], r3[3] };
	RECT R4 = { r4[0], r4[1], r4[2], r4[3] };
	RECT R5 = { r5[0], r5[1], r5[2], r5[3] };

	//��������
	settextcolor(BLACK);
	settextstyle(35, 0, _T("����"));
	setbkmode(TRANSPARENT);
	//�ھ�����������ַ���
	drawtext(_T("����¼��"), &R1, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
	drawtext(_T("�����б�"), &R2, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
	drawtext(_T("����Ķ�"), &R3, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
	drawtext(_T("���չ���"), &R4, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
	drawtext(_T("�˳�����"), &R5, DT_CENTER | DT_VCENTER | DT_SINGLELINE);

	//ѭ����ʼ
	while (true)
	{
		//��ȡ�����Ϣ
		ExMessage m1;
		if (peekmessage(&m1, EX_MOUSE))
		{
			if (m1.x > r1[0] && m1.x < r1[2] && m1.y>r1[1] && m1.y < r1[3])
			{
				setlinecolor(RED);
				roundrect(r1[0], r1[1], r1[2], r1[3], 20, 20);
				if (m1.message == WM_LBUTTONDOWN)
				{
					Inputtodo();	//¼��
				}
			}
			else if (m1.x >= r2[0] && m1.x <= r2[2] && m1.y >= r2[1] && m1.y <= r2[3])
			{
				setlinecolor(RED);
				roundrect(r2[0], r2[1], r2[2], r2[3], 20, 20);
				if (m1.message == WM_LBUTTONDOWN)
				{
					Showtodo();		//��ʾ
				}
			}
			else if (m1.x >= r3[0] && m1.x <= r3[2] && m1.y >= r3[1] && m1.y <= r3[3])
			{
				setlinecolor(RED);
				roundrect(r3[0], r3[1], r3[2], r3[3], 20, 20);
				if (m1.message == WM_LBUTTONDOWN)
				{
					Change();		//�Ķ�
				}
			}
			else if (m1.x >= r4[0] && m1.x <= r4[2] && m1.y >= r4[1] && m1.y <= r4[3])
			{
				setlinecolor(RED);
				roundrect(r4[0], r4[1], r4[2], r4[3], 20, 20);
				if (m1.message == WM_LBUTTONDOWN)
				{
					Encourage();	//����
				}
			}
			else if (m1.x >= r5[0] && m1.x <= r5[2] && m1.y >= r5[1] && m1.y <= r5[3])
			{
				setlinecolor(RED);
				roundrect(r5[0], r5[1], r5[2], r5[3], 20, 20);
				if (m1.message == WM_LBUTTONDOWN)
				{
					closegraph();	//�˳�
				}
			}
			else
			{
				setlinecolor(WHITE);
				roundrect(r1[0], r1[1], r1[2], r1[3], 20, 20);
				roundrect(r2[0], r2[1], r2[2], r2[3], 20, 20);
				roundrect(r3[0], r3[1], r3[2], r3[3], 20, 20);
				roundrect(r4[0], r4[1], r4[2], r4[3], 20, 20);
				roundrect(r5[0], r5[1], r5[2], r5[3], 20, 20);
			}
		}
	}
}

void Inputtodo()	//¼�����
{
	//����ѭ������Ƿ��ظ�
	while (true)
	{
		InputBox(t[numt].name, 40, "�������������");

		if (true)
		{
			//�ж��Ƿ������ظ�
			int flag1 = 0, i = 0;
			for (i = 0; i < numt; i++)
			{
				if (strcmp(t[numt].name, t[i].name) == 0)
				{
					flag1 = 1;
				}
			}
			if (flag1 == 1)
			{
				HWND hwndInput1 = GetHWnd();
				int isok = MessageBox(hwndInput1, "�������Ѵ��ڣ�����������", "��ʾ", MB_OK);
			}
			if (flag1 == 0)
			{
				break;
			}
		}
	}
	InputBox(t[numt].time_s, 15, "����������ʼʱ�䣨��ʽ��xx:xx��");
	InputBox(t[numt].time_f, 15, "�������������ʱ�䣨��ʽ��xx:xx��");
	Savetodo();
}

void Savetodo()	//�������
{
	//����������ַ�������
	int len = strlen(t[numt].name);
	//����������Ʋ�Ϊ�ձ���
	if (len != 0)
	{
		FILE* fp = fopen("todolist.txt", "a");	//���ļ���׷��
		if (fp == NULL)
		{
			return;
		}
		//����ʱ�����ʱ����
		if (len <= 8)
		{
			fprintf(fp, "%s\t\t\t%s\t--\t%s\n", t[numt].name, t[numt].time_s, t[numt].time_f);
		}
		else if (len <= 18)
		{
			fprintf(fp, "%s\t\t%s\t--\t%s\n", t[numt].name, t[numt].time_s, t[numt].time_f);
		}
		else
		{
			fprintf(fp, "%s\t%s\t--\t%s\n", t[numt].name, t[numt].time_s, t[numt].time_f);
		}
		fclose(fp);
		numt++;
	}
}

void Showinit()	//��ʾ�����б�ǰ��׼������
{
	initgraph(690, 480);
	putimage(0, 0, &bk[1]);

	//���ذ������λ���
	setbkmode(TRANSPARENT);
	setfillcolor(WHITE);
	fillroundrect(500, 430, 550, 460, 20, 20);
	RECT R7 = { 500, 430, 550, 460 };
	fillroundrect(260, 430, 390, 460, 20, 20);
	RECT R11 = { 260, 430, 390, 460 };
	fillroundrect(50, 430, 180, 460, 20, 20);
	RECT R12 = { 50, 430, 180, 460 };

	settextcolor(BLACK);
	settextstyle(15, 0, "����");
	setbkmode(TRANSPARENT);
	drawtext("����", &R7, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
	drawtext("����ʼʱ������", &R11, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
	drawtext("��¼��ʱ������", &R12, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
	settextstyle(20, 0, "����");
	outtextxy(40, 20, "��������");
	outtextxy(290, 20, "��ʼʱ��");
	outtextxy(470, 20, "����ʱ��");
}

void Showtodo() //��ʾ�����б�
{
	Showinit();

	//��ʾ������켰ʱ��
	int q = 0;
	for (q = 0; q < numt; q++)
	{
		outtextxy(40, 60 + q * 20, t[q].name);
		outtextxy(290, 60 + q * 20, t[q].time_s);
		outtextxy(400, 60 + q * 20, "--");
		outtextxy(470, 60 + q * 20, t[q].time_f);
		t[q].starttime = t[q].time_s[0] * 600 + t[q].time_s[1] * 60 + t[q].time_s[3] * 10 + t[q].time_s[4];
		tc[q] = t[q];
	}

	ExMessage m3;
	while (true)
	{
		if (peekmessage(&m3, EX_MOUSE))
		{
			if (m3.x > 500 && m3.x < 550 && m3.y > 430 && m3.y < 460)
			{
				setlinecolor(RED);
				roundrect(500, 430, 550, 460, 20, 20);
				if (m3.message == WM_LBUTTONDOWN)
				{
					menu();	//�������˵�
				}
			}
			else if (m3.x > 260 && m3.x < 390 && m3.y > 430 && m3.y < 460)
			{
				setlinecolor(RED);
				roundrect(260, 430, 390, 460, 20, 20);
				if (m3.message == WM_LBUTTONDOWN)
				{
					bubble_sort(tc);	//����
				}
			}
			else if (m3.x > 50 && m3.x < 180 && m3.y > 430 && m3.y < 460)
			{
				setlinecolor(RED);
				roundrect(50, 430, 180, 460, 20, 20);
				if (m3.message == WM_LBUTTONDOWN)
				{
					Originsort();		//¼��˳��
				}
			}
			else
			{
				setlinecolor(WHITE);
				roundrect(500, 430, 550, 460, 20, 20);
				roundrect(260, 430, 390, 460, 20, 20);
				roundrect(50, 430, 180, 460, 20, 20);
			}
		}
	}
}

void bubble_sort(struct task tc[30])	//����ʼʱ������
{
	Showinit();
	int i = 0;
	for (i = 0; i < numt - 1; i++)
	{
		int j = 0;
		for (j = 0; j < numt - i - 1; j++)
		{
			if (tc[j].starttime > tc[j + 1].starttime)
			{
				struct task tmp = tc[j];
				tc[j] = tc[j + 1];
				tc[j + 1] = tmp;
			}
		}
	}
	int k = 0;
	for (k = 0; k < numt; k++)
	{
		outtextxy(40, 60 + k * 20, tc[k].name);
		outtextxy(290, 60 + k * 20, tc[k].time_s);
		outtextxy(400, 60 + k * 20, "--");
		outtextxy(470, 60 + k * 20, tc[k].time_f);
	}
}

void Originsort()	//��¼��ʱ������
{
	Showinit();
	int n = 0;
	for (n = 0; n < numt; n++)
	{
		outtextxy(40, 60 + n * 20, t[n].name);
		outtextxy(290, 60 + n * 20, t[n].time_s);
		outtextxy(400, 60 + n * 20, "--");
		outtextxy(470, 60 + n * 20, t[n].time_f);
	}
}

void Readtodo()	//��ȡ�ļ��еĴ�����Ϣ
{
	FILE* fp = fopen("todolist.txt", "r");
	if (fp == NULL)
	{
		return;
	}

	//��������Ϣ��ȡ����������ṹ����
	int i = 0;
	for (i = 0; i < 15; i++)
	{
		char xiahua[10] = { 0 };
		fscanf(fp, "%s\t%s\t%s\t%s\n", t[i].name, t[i].time_s, xiahua, t[i].time_f);
	}

	//��ȡĿǰ�������
	int num = 0, j = 0;
	for (j = 0; j < 30; j++)
	{
		if (strlen(t[j].name) != 0)
		{
			numt = ++num;
		}
	}
	fclose(fp);
}

void Change()	//����Ķ�
{
	cleardevice();
	initgraph(Width, Height);
	//����ͼ
	putimage(0, 0, &bk[2]);

	//��ť
	setfillcolor(RGB(240, 255, 255));	//�����Ա�ѡ��
	setlinecolor(RGB(240, 255, 255));
	fillroundrect(r8[0], r8[1], r8[2], r8[3], 20, 20);
	fillroundrect(r9[0], r9[1], r9[2], r9[3], 20, 20);
	fillroundrect(r10[0], r10[1], r10[2], r10[3], 20, 20);
	//����
	RECT R8 = { r8[0], r8[1], r8[2], r8[3] };
	RECT R9 = { r9[0], r9[1], r9[2], r9[3] };
	RECT R10 = { r10[0], r10[1], r10[2], r10[3] };
	settextcolor(BLACK);
	settextstyle(35, 0, _T("����"));
	setbkmode(TRANSPARENT);
	drawtext("�����޸�", &R8, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
	drawtext("����ɾ��", &R9, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
	drawtext("����", &R10, DT_CENTER | DT_VCENTER | DT_SINGLELINE);

	ExMessage m2;
	while (true)
	{
		if (peekmessage(&m2, EX_MOUSE))
		{
			if (m2.x >= r8[0] && m2.x <= r8[2] && m2.y >= r8[1] && m2.y <= r8[3])
			{
				setlinecolor(RGB(187, 255, 255));
				roundrect(r8[0], r8[1], r8[2], r8[3], 20, 20);
				if (m2.message == WM_LBUTTONDOWN)
				{
					Moditodo();		//�޸�
				}
			}
			else if (m2.x >= r9[0] && m2.x <= r9[2] && m2.y >= r9[1] && m2.y <= r9[3])
			{
				setlinecolor(RGB(187, 255, 255));
				roundrect(r9[0], r9[1], r9[2], r9[3], 20, 20);
				if (m2.message == WM_LBUTTONDOWN)
				{
					Deletodo();		//ɾ��
				}
			}
			else if (m2.x >= r10[0] && m2.x <= r10[2] && m2.y >= r10[1] && m2.y <= r10[3])
			{
				setlinecolor(RGB(187, 255, 255));
				roundrect(r10[0], r10[1], r10[2], r10[3], 20, 20);
				if (m2.message == WM_LBUTTONDOWN)
				{
					menu();		//����
				}
			}
			else
			{
				setlinecolor(RGB(240, 255, 255));
				roundrect(r8[0], r8[1], r8[2], r8[3], 20, 20);
				roundrect(r9[0], r9[1], r9[2], r9[3], 20, 20);
				roundrect(r10[0], r10[1], r10[2], r10[3], 20, 20);
			}
		}
	}
}

int Find()	//���Ҵ���
{
	char Input[50];
	InputBox(Input, 40, "������Ҫ�޸Ļ�ɾ���Ĵ�������");
	for (int m = 0; m < numt; m++)
	{
		if (strcmp(t[m].name, Input) == 0)	//�����������
		{
			return m;
		}
	}
	return -1;
}

void Moditodo()	//�޸Ĵ���
{
	int find = Find();
	if (find == -1)	//û�д������
	{
		HWND hndtipsM = GetHWnd();
		int isok = MessageBox(hndtipsM, "û�д������", "��ʾ", MB_OK);
	}
	else //�д������
	{
		InputBox(t[find].name, 40, "�������������");
		InputBox(t[find].time_s, 15, "����������ʼʱ��");
		InputBox(t[find].time_f, 15, "�������������ʱ��");
	}

	Savemoditodo();
}

void Savemoditodo()
{
	remove("todolist.txt");	//ɾ��ԭ���ļ�
	FILE* fp = fopen("todolist.txt", "a");
	if (fp == NULL)
	{
		return;
	}
	int i = 0;
	for (i = 0; i < numt; i++)	//����д��
	{
		int len = strlen(t[i].name);
		if (len != 0)
		{
			if (len <= 8)
			{
				fprintf(fp, "%s\t\t\t%s\t--\t%s\n", t[i].name, t[i].time_s, t[i].time_f);
			}
			else if (len <= 18)
			{
				fprintf(fp, "%s\t\t%s\t--\t%s\n", t[i].name, t[i].time_s, t[i].time_f);
			}
			else
			{
				fprintf(fp, "%s\t%s\t--\t%s\n", t[i].name, t[i].time_s, t[i].time_f);
			}
		}
	}
	fclose(fp);
}

void Deletodo()
{
	int shan = Find();
	if (shan == -1)	//û�д������
	{
		HWND hndtipsD = GetHWnd();
		int isok = MessageBox(hndtipsD, "û�д������", "��ʾ", MB_OK);
	}
	else
	{
		HWND hndtipsDS = GetHWnd();
		int isok = MessageBox(hndtipsDS, "ȷ��ɾ����", "��ʾ", MB_OKCANCEL);
		if (isok == IDOK)	//ȷ��ɾ��
		{
			//���������֮���������ǰ
			int n;
			for (n = shan; n < numt; n++)
			{
				t[n] = t[n + 1];
			}
			numt--;

			Savemoditodo();	//���ļ����и���
		}
		else if (isok == IDCANCEL)
		{

		}
	}
}

void Encourage()
{
	cleardevice();
	initgraph(700, 400);
	putimage(0, 0, &bk[3]);

	//�������¼��
	for (int i = 0; i < 10; i++)
	{
		e[i].number = i;
	}
	strcpy(e[0].sentence, "���������շ���");
	strcpy(e[1].sentence, "���������̫�������ᣬ");
	strcpy(e[2].sentence, "����һ��ͬ����");
	strcpy(e[3].sentence, "��������������еĽ��ǣ�");
	strcpy(e[4].sentence, "�������ݼ��ţ�");
	strcpy(e[5].sentence, "���˶�Ҫ����Ϩ��");
	strcpy(e[6].sentence, "ֻ����ˮ�����ϵ�������ϴ�ɾ���");
	strcpy(e[7].sentence, "Ψ����ѣ��Ÿ�������");
	strcpy(e[8].sentence, "���ߵú�����");
	strcpy(e[9].sentence, "��������֮��Ŀ��յյ���");
	strcpy(e[10].sentence, "���������еĺ��࣬��������ɫ�Ĺ���");
	strcpy(e[11].sentence, "��ô��Ҳ���������");
	strcpy(e[12].sentence, "��ҡֱ�Ͼ�����");
	strcpy(e[13].sentence, "���ڵ��£�����ÿһ��������");
	strcpy(e[14].sentence, "Ҫ��ÿһ�κ�ˮȥ��ȡ");
	strcpy(e[15].sentence, "��һ�˶����˻�߸߾���");
	strcpy(e[16].sentence, "�ٹ�Ż��������������");
	strcpy(e[17].sentence, "Ψ�����У����������");
	strcpy(e[18].sentence, "���ҴӲ�����");
	strcpy(e[19].sentence, "��ȥ�����ҹ·");

	//��������
	setbkmode(TRANSPARENT);
	setfillcolor(WHITE);
	fillroundrect(310, 350, 370, 380, 20, 20);
	RECT R7 = { 310, 350, 370, 380 };
	settextcolor(BLACK);
	settextstyle(15, 0, "����");
	setbkmode(TRANSPARENT);
	drawtext("����", &R7, DT_CENTER | DT_VCENTER | DT_SINGLELINE);

	//������������ʾ
	srand((unsigned int)time(NULL));
	int pick = rand() % 10;
	settextcolor(RGB(105, 105, 105));
	settextstyle(35, 0, "����");
	setbkmode(TRANSPARENT);
	outtextxy(40, 50, e[pick].sentence);
	outtextxy(40, 120, e[10 + pick].sentence);

	ExMessage m4;
	while (true)
	{
		if (peekmessage(&m4, EX_MOUSE))
		{
			if (m4.x > 310 && m4.x < 370 && m4.y > 350 && m4.y < 380)
			{
				setlinecolor(RED);
				roundrect(310, 350, 370, 380, 20, 20);
			}
			else
			{
				setlinecolor(WHITE);
				roundrect(310, 350, 370, 380, 20, 20);
			}
			if (m4.message == WM_LBUTTONDOWN)
			{
				menu();//�������˵�
			}
		}
	}
}