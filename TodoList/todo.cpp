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
	char name[50];	//待办名称
	char time_s[30];	//开始时间
	char time_f[30];	//结束时间
	int starttime;
};
//创建待办结构体数组
struct task t[30];
struct task tc[30];
//当前待办个数
int numt = 0;
struct encourage
{
	char sentence[100];
	int number;
};
struct encourage e[20];

//定义按钮的大小数组
int r1[] = { 100, 190, 300, 240 };
int r2[] = { 100, 260, 300, 310 };
int r3[] = { 100, 330, 300, 380 };
int r4[] = { 100, 400, 300, 450 };
int r5[] = { 100, 470, 300, 520 };
int r8[] = { 100, 70, 300, 130 };
int r9[] = { 100, 180, 300, 240 };
int r10[] = { 100, 290, 300, 350 };

void menu();		//主界面
void Inputtodo();	//录入代办
void Savetodo();	//保存待办
void Showinit();	//显示待办列表前的准备工作
void Showtodo();	//显示待办列表
void Readtodo();	//读取文件中的待办信息
void Change();		//待办改动
void Moditodo();	//修改待办
int Find();			//查找待办
void Savemoditodo();	//保存修改后的待办
void Deletodo();	//删除待办
void Encourage();	//今日鼓励
void bubble_sort(struct task tc[30]);	//冒泡排序
void Originsort();	//录入顺序

int main()
{
	//主界面
	menu();
	return 0;
}

void menu()
{
	//绘图窗口初始化
	initgraph(Width, Height);
	//窗口标题
	HWND hwnd = GetHWnd();
	SetWindowText(hwnd, _T("今日待办"));

	//进入程序就读取数据，获取当前numt
	Readtodo();

	//背景图
	loadimage(&bk[0], "..\\TodoList\\bk1.jpeg", Width, Height);
	putimage(0, 0, &bk[0]);

	//标题图
	loadimage(&title[0], "..\\TodoList\\title1.png", 360, 80);
	loadimage(&title[1], "..\\TodoList\\title1_1.png", 360, 80);
	loadimage(&title[2], "..\\TodoList\\title2.png", 250, 35);
	loadimage(&title[3], "..\\TodoList\\title2_1.png", 250, 35);
	putimage(20, 25, &title[1], SRCAND);	//掩码图
	putimage(20, 25, &title[0], SRCPAINT);	//原图
	putimage(75, 125, &title[3], SRCAND);
	putimage(75, 125, &title[2], SRCPAINT);

	//加载其余图片
	loadimage(&bk[1], "..\\TodoList\\bk4.jpeg", 690, 480);
	loadimage(&bk[2], "..\\TodoList\\bk2.jpeg", Width, Height);
	loadimage(&bk[3], "..\\TodoList\\bk3.jpeg", 700, 400);

	//绘制按键矩形
	setbkmode(TRANSPARENT);
	setfillcolor(WHITE);
	fillroundrect(r1[0], r1[1], r1[2], r1[3], 20, 20);
	fillroundrect(r2[0], r2[1], r2[2], r2[3], 20, 20);
	fillroundrect(r3[0], r3[1], r3[2], r3[3], 20, 20);
	fillroundrect(r4[0], r4[1], r4[2], r4[3], 20, 20);
	fillroundrect(r5[0], r5[1], r5[2], r5[3], 20, 20);

	//矩形指针，方便后面在里面写字
	RECT R1 = { r1[0], r1[1], r1[2], r1[3] };
	RECT R2 = { r2[0], r2[1], r2[2], r2[3] };
	RECT R3 = { r3[0], r3[1], r3[2], r3[3] };
	RECT R4 = { r4[0], r4[1], r4[2], r4[3] };
	RECT R5 = { r5[0], r5[1], r5[2], r5[3] };

	//按键名称
	settextcolor(BLACK);
	settextstyle(35, 0, _T("黑体"));
	setbkmode(TRANSPARENT);
	//在矩形中央输出字符串
	drawtext(_T("待办录入"), &R1, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
	drawtext(_T("待办列表"), &R2, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
	drawtext(_T("待办改动"), &R3, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
	drawtext(_T("今日鼓励"), &R4, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
	drawtext(_T("退出界面"), &R5, DT_CENTER | DT_VCENTER | DT_SINGLELINE);

	//循环开始
	while (true)
	{
		//获取鼠标信息
		ExMessage m1;
		if (peekmessage(&m1, EX_MOUSE))
		{
			if (m1.x > r1[0] && m1.x < r1[2] && m1.y>r1[1] && m1.y < r1[3])
			{
				setlinecolor(RED);
				roundrect(r1[0], r1[1], r1[2], r1[3], 20, 20);
				if (m1.message == WM_LBUTTONDOWN)
				{
					Inputtodo();	//录入
				}
			}
			else if (m1.x >= r2[0] && m1.x <= r2[2] && m1.y >= r2[1] && m1.y <= r2[3])
			{
				setlinecolor(RED);
				roundrect(r2[0], r2[1], r2[2], r2[3], 20, 20);
				if (m1.message == WM_LBUTTONDOWN)
				{
					Showtodo();		//显示
				}
			}
			else if (m1.x >= r3[0] && m1.x <= r3[2] && m1.y >= r3[1] && m1.y <= r3[3])
			{
				setlinecolor(RED);
				roundrect(r3[0], r3[1], r3[2], r3[3], 20, 20);
				if (m1.message == WM_LBUTTONDOWN)
				{
					Change();		//改动
				}
			}
			else if (m1.x >= r4[0] && m1.x <= r4[2] && m1.y >= r4[1] && m1.y <= r4[3])
			{
				setlinecolor(RED);
				roundrect(r4[0], r4[1], r4[2], r4[3], 20, 20);
				if (m1.message == WM_LBUTTONDOWN)
				{
					Encourage();	//鼓励
				}
			}
			else if (m1.x >= r5[0] && m1.x <= r5[2] && m1.y >= r5[1] && m1.y <= r5[3])
			{
				setlinecolor(RED);
				roundrect(r5[0], r5[1], r5[2], r5[3], 20, 20);
				if (m1.message == WM_LBUTTONDOWN)
				{
					closegraph();	//退出
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

void Inputtodo()	//录入代办
{
	//运用循环检查是否重复
	while (true)
	{
		InputBox(t[numt].name, 40, "请输入待办任务");

		if (true)
		{
			//判断是否输入重复
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
				int isok = MessageBox(hwndInput1, "该任务已存在，请重新输入", "提示", MB_OK);
			}
			if (flag1 == 0)
			{
				break;
			}
		}
	}
	InputBox(t[numt].time_s, 15, "请输入任务开始时间（格式如xx:xx）");
	InputBox(t[numt].time_f, 15, "请输入任务结束时间（格式如xx:xx）");
	Savetodo();
}

void Savetodo()	//保存待办
{
	//计算输入的字符串长度
	int len = strlen(t[numt].name);
	//如果任务名称不为空保存
	if (len != 0)
	{
		FILE* fp = fopen("todolist.txt", "a");	//在文件中追加
		if (fp == NULL)
		{
			return;
		}
		//保持时间输出时对齐
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

void Showinit()	//显示待办列表前的准备工作
{
	initgraph(690, 480);
	putimage(0, 0, &bk[1]);

	//返回按键矩形绘制
	setbkmode(TRANSPARENT);
	setfillcolor(WHITE);
	fillroundrect(500, 430, 550, 460, 20, 20);
	RECT R7 = { 500, 430, 550, 460 };
	fillroundrect(260, 430, 390, 460, 20, 20);
	RECT R11 = { 260, 430, 390, 460 };
	fillroundrect(50, 430, 180, 460, 20, 20);
	RECT R12 = { 50, 430, 180, 460 };

	settextcolor(BLACK);
	settextstyle(15, 0, "黑体");
	setbkmode(TRANSPARENT);
	drawtext("返回", &R7, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
	drawtext("按开始时间排序", &R11, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
	drawtext("按录入时间排序", &R12, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
	settextstyle(20, 0, "黑体");
	outtextxy(40, 20, "待办任务");
	outtextxy(290, 20, "起始时间");
	outtextxy(470, 20, "结束时间");
}

void Showtodo() //显示待办列表
{
	Showinit();

	//显示各项待办及时间
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
					menu();	//返回主菜单
				}
			}
			else if (m3.x > 260 && m3.x < 390 && m3.y > 430 && m3.y < 460)
			{
				setlinecolor(RED);
				roundrect(260, 430, 390, 460, 20, 20);
				if (m3.message == WM_LBUTTONDOWN)
				{
					bubble_sort(tc);	//排序
				}
			}
			else if (m3.x > 50 && m3.x < 180 && m3.y > 430 && m3.y < 460)
			{
				setlinecolor(RED);
				roundrect(50, 430, 180, 460, 20, 20);
				if (m3.message == WM_LBUTTONDOWN)
				{
					Originsort();		//录入顺序
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

void bubble_sort(struct task tc[30])	//按开始时间排序
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

void Originsort()	//按录入时间排序
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

void Readtodo()	//读取文件中的待办信息
{
	FILE* fp = fopen("todolist.txt", "r");
	if (fp == NULL)
	{
		return;
	}

	//将待办信息读取到待办任务结构体中
	int i = 0;
	for (i = 0; i < 15; i++)
	{
		char xiahua[10] = { 0 };
		fscanf(fp, "%s\t%s\t%s\t%s\n", t[i].name, t[i].time_s, xiahua, t[i].time_f);
	}

	//读取目前任务个数
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

void Change()	//待办改动
{
	cleardevice();
	initgraph(Width, Height);
	//背景图
	putimage(0, 0, &bk[2]);

	//按钮
	setfillcolor(RGB(240, 255, 255));	//绘制性别选择
	setlinecolor(RGB(240, 255, 255));
	fillroundrect(r8[0], r8[1], r8[2], r8[3], 20, 20);
	fillroundrect(r9[0], r9[1], r9[2], r9[3], 20, 20);
	fillroundrect(r10[0], r10[1], r10[2], r10[3], 20, 20);
	//文字
	RECT R8 = { r8[0], r8[1], r8[2], r8[3] };
	RECT R9 = { r9[0], r9[1], r9[2], r9[3] };
	RECT R10 = { r10[0], r10[1], r10[2], r10[3] };
	settextcolor(BLACK);
	settextstyle(35, 0, _T("黑体"));
	setbkmode(TRANSPARENT);
	drawtext("待办修改", &R8, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
	drawtext("待办删除", &R9, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
	drawtext("返回", &R10, DT_CENTER | DT_VCENTER | DT_SINGLELINE);

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
					Moditodo();		//修改
				}
			}
			else if (m2.x >= r9[0] && m2.x <= r9[2] && m2.y >= r9[1] && m2.y <= r9[3])
			{
				setlinecolor(RGB(187, 255, 255));
				roundrect(r9[0], r9[1], r9[2], r9[3], 20, 20);
				if (m2.message == WM_LBUTTONDOWN)
				{
					Deletodo();		//删除
				}
			}
			else if (m2.x >= r10[0] && m2.x <= r10[2] && m2.y >= r10[1] && m2.y <= r10[3])
			{
				setlinecolor(RGB(187, 255, 255));
				roundrect(r10[0], r10[1], r10[2], r10[3], 20, 20);
				if (m2.message == WM_LBUTTONDOWN)
				{
					menu();		//返回
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

int Find()	//查找待办
{
	char Input[50];
	InputBox(Input, 40, "请输入要修改或删除的待办名称");
	for (int m = 0; m < numt; m++)
	{
		if (strcmp(t[m].name, Input) == 0)	//待办名称相等
		{
			return m;
		}
	}
	return -1;
}

void Moditodo()	//修改待办
{
	int find = Find();
	if (find == -1)	//没有此项待办
	{
		HWND hndtipsM = GetHWnd();
		int isok = MessageBox(hndtipsM, "没有此项待办", "提示", MB_OK);
	}
	else //有此项待办
	{
		InputBox(t[find].name, 40, "请输入待办任务");
		InputBox(t[find].time_s, 15, "请输入任务开始时间");
		InputBox(t[find].time_f, 15, "请输入任务结束时间");
	}

	Savemoditodo();
}

void Savemoditodo()
{
	remove("todolist.txt");	//删除原先文件
	FILE* fp = fopen("todolist.txt", "a");
	if (fp == NULL)
	{
		return;
	}
	int i = 0;
	for (i = 0; i < numt; i++)	//重新写入
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
	if (shan == -1)	//没有此项待办
	{
		HWND hndtipsD = GetHWnd();
		int isok = MessageBox(hndtipsD, "没有此项待办", "提示", MB_OK);
	}
	else
	{
		HWND hndtipsDS = GetHWnd();
		int isok = MessageBox(hndtipsDS, "确定删除？", "提示", MB_OKCANCEL);
		if (isok == IDOK)	//确定删除
		{
			//将此项待办之后的依次提前
			int n;
			for (n = shan; n < numt; n++)
			{
				t[n] = t[n + 1];
			}
			numt--;

			Savemoditodo();	//对文件进行更新
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

	//鼓励语句录入
	for (int i = 0; i < 10; i++)
	{
		e[i].number = i;
	}
	strcpy(e[0].sentence, "在逆风里把握方向，");
	strcpy(e[1].sentence, "如果你因错过太阳而流泪，");
	strcpy(e[2].sentence, "大鹏一日同风起");
	strcpy(e[3].sentence, "如果想征服生命中的焦虑，");
	strcpy(e[4].sentence, "机会稍纵即逝，");
	strcpy(e[5].sentence, "万人都要将火熄灭，");
	strcpy(e[6].sentence, "只有用水将心上的雾气淘洗干净，");
	strcpy(e[7].sentence, "唯其艰难，才更显勇毅");
	strcpy(e[8].sentence, "我走得很慢，");
	strcpy(e[9].sentence, "且视他人之凝目如盏盏鬼火，");
	strcpy(e[10].sentence, "做暴风雨中的海燕，做不改颜色的孤星");
	strcpy(e[11].sentence, "那么你也将错过繁星");
	strcpy(e[12].sentence, "扶摇直上九万里");
	strcpy(e[13].sentence, "活在当下，活在每一个呼吸里");
	strcpy(e[14].sentence, "要用每一滴汗水去争取");
	strcpy(e[15].sentence, "我一人独将此火高高举起");
	strcpy(e[16].sentence, "荣光才会照亮最初的梦想");
	strcpy(e[17].sentence, "唯其笃行，才弥足珍贵");
	strcpy(e[18].sentence, "但我从不后退");
	strcpy(e[19].sentence, "大胆去走你的夜路");

	//按键绘制
	setbkmode(TRANSPARENT);
	setfillcolor(WHITE);
	fillroundrect(310, 350, 370, 380, 20, 20);
	RECT R7 = { 310, 350, 370, 380 };
	settextcolor(BLACK);
	settextstyle(15, 0, "黑体");
	setbkmode(TRANSPARENT);
	drawtext("返回", &R7, DT_CENTER | DT_VCENTER | DT_SINGLELINE);

	//鼓励语句随机显示
	srand((unsigned int)time(NULL));
	int pick = rand() % 10;
	settextcolor(RGB(105, 105, 105));
	settextstyle(35, 0, "楷体");
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
				menu();//返回主菜单
			}
		}
	}
}