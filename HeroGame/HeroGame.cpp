#include <graphics.h>
#include <conio.h>
#include <stdlib.h>
#include <Windows.h>
#include <mmsystem.h>
#include <iostream>
#include <time.h>
#include <math.h>
#pragma comment(lib, "WINMM.LIB")

using namespace std;

#define Width 800 //窗口宽度
#define Height 600 //窗口高度
#define dv 20 //障碍物和云的移动速度

struct Hero
{
	int x;	//主角x坐标
	int y;	//主角y坐标
	bool live;	//是否存活
	int g;	// 主角重力
	int r;	// 主角半径    
	int v;	// 主角速度
	int score;	//主角分数
	int count; //按键次数
}player;

struct Cloud
{
	int cloud1_x; //云1的x坐标
	int cloud1_y; //云1的y坐标
	int cloud2_x;
	int cloud2_y;
	int cloud3_x;
	int cloud3_y;
}clouds;

struct Heart
{
	int x_; 
	int y_;//用于加血量的爱心的坐标
	int flag_;//用于判断加血爱心是否出现
	int live_;//判断加血爱心是否在屏幕中
	int x1; //心1的x坐标
	int x2; //心2的x坐标
	int x3; //心3的x坐标
	int y;  //三颗心具有同样的y坐标
	int live1;
	int live2;
	int live3;
}heart;

struct Enemy
{
	int x; //怪物的x坐标
	int y; //怪物的y坐标
	unsigned int a;
	int live;//live为0表明碰到主角，应该消失；live为1表明没有碰到
	int num;
	int score;
}enemy;

struct Goldcoin
{
	int x; //金币的x坐标
	int y; //金币的y坐标
	unsigned int b;
	int live;
	int score;
}coin;

//定义图片
IMAGE img_background, img_hero1, img_hero1_1, img_cloud1, img_cloud1_1,
img_cloud2, img_cloud2_2, img_cloud3, img_cloud3_3,
img_heart_red, img_heart_red_1, img_heart_blank, img_heart_blank_1,
img_enemy1, img_enemy1_1, img_enemy2, img_enemy2_2, img_enemy3, img_enemy3_3,
img_coin, img_coin_1, img_start, img_start_1,
img_hit, img_hit_1,
img_dead,img_dead_1;

void loadimage();	//载入所有需要用的图片
void drawinit();	//主界面绘制
void rule();		//规则界面绘制
void numberinit();	//各个变量初始化
void drawimage();	//绘制界面图片
void playermoveup();	//玩家移动过程逻辑实现
void cloudmove();	//云朵出现及移动
void enemymove();	//怪物出现及移动
void coin_occure();	//金币出现及移动
void heart_move();	//血量出现及移动

// 主函数
int main()
{
	//绘图窗口初始化
	initgraph(Width, Height);

	//窗口标题
	HWND hwnd = GetHWnd();
	SetWindowText(hwnd, _T("Keep Jumping!"));

	numberinit();
	//初始化界面
	mciSendString(L"open D:\\bgm.mp3 alias BGM", 0, 0, 0);
	mciSendString(L"play BGM repeat", 0, 0, 0);	//播放背景音乐

	drawinit();
	_getch();
	rule();
	_getch();

	//双缓冲，防止Hero闪烁
	BeginBatchDraw();

	srand((unsigned int)time(NULL));
	enemy.a = rand() % 3 + 1;
	coin.b = rand() % 5+1;

	//主角运动控制部分&云的移动&障碍物的移动
	while (1)  //使用死循环
	{
		drawimage();
		FlushBatchDraw();
		playermoveup();
		cloudmove();
		enemymove();
		coin_occure();
		heart_move();
		if (heart.live3 == 0)
		{
			mciSendString(L"stop BGM", 0, 0, 0);
			PlaySound(L"..\\big homework1\\gameover.wav", NULL, SND_FILENAME | SND_ASYNC);
			break;
		}
	}
	EndBatchDraw();

	BeginBatchDraw(); 
	drawimage();
	Sleep(500);
	while (1)
	{
		drawimage();
		FlushBatchDraw();
		player.y -= 3;
		if (player.y < -120)
		{
			break;
		}
	}
	Sleep(1000);
	putimage(0, 0, &img_dead/*, SRCPAINT*/);
	EndBatchDraw();
	
	// 按任意键退出
	_getch();
	closegraph();

	return 0;
}

void loadimage()			//加载图片
{

	loadimage(&img_background, _T("..\\big homework1\\background.png"), Width, Height);
	//背景图

	loadimage(&img_start, _T("..\\big homework1\\start.jpg"), 350, 100);
	loadimage(&img_start_1, _T("..\\big homework1\\start_1.jpg"), 350, 100);

	loadimage(&img_hero1_1, _T("..\\big homework1\\hero1_1.png"));
	loadimage(&img_hero1, _T("..\\big homework1\\hero1.png"));
	//主角

	loadimage(&img_cloud1_1, _T("..\\big homework1\\cloud1_1.png"));
	loadimage(&img_cloud1, _T("..\\big homework1\\cloud1.png"));
	loadimage(&img_cloud2, _T("..\\big homework1\\cloud2.png"));
	loadimage(&img_cloud2_2, _T("..\\big homework1\\cloud2_2.png"));
	loadimage(&img_cloud3, _T("..\\big homework1\\cloud3.png"));
	loadimage(&img_cloud3_3, _T("..\\big homework1\\cloud3_3.png"));
	//云

	loadimage(&img_heart_red, _T("..\\big homework1\\heart_red.png"));
	loadimage(&img_heart_red_1, _T("..\\big homework1\\heart_red_1.png"));
	loadimage(&img_heart_blank, _T("..\\big homework1\\heart_blank.png"));
	loadimage(&img_heart_blank_1, _T("..\\big homework1\\heart_blank_1.png"));
	//血量

	loadimage(&img_enemy1, _T("..\\big homework1\\enemy1.png"));
	loadimage(&img_enemy1_1, _T("..\\big homework1\\enemy1_1.png"));
	loadimage(&img_enemy2, _T("..\\big homework1\\enemy2.png"));
	loadimage(&img_enemy2_2, _T("..\\big homework1\\enemy2_2.png"));
	loadimage(&img_enemy3, _T("..\\big homework1\\enemy3.png"));
	loadimage(&img_enemy3_3, _T("..\\big homework1\\enemy3_3.png"));
	//怪物

	loadimage(&img_coin, _T("..\\big homework1\\goldcoin.png"));
	loadimage(&img_coin_1, _T("..\\big homework1\\goldcoin_1.png"));
	//金币

	loadimage(&img_hit, _T("..\\big homework1\\hit.png"));
	loadimage(&img_hit_1, _T("..\\big homework1\\hit_1.png"));
	//受伤形态

	loadimage(&img_dead, _T("..\\big homework1\\dead_.png"));
	//死亡
}

void drawinit()
{
	loadimage();
	putimage(0, 0, &img_background);
	//绘制背景

	putimage(clouds.cloud1_x, clouds.cloud1_y, &img_cloud1_1, SRCAND); //掩码图
	putimage(clouds.cloud1_x, clouds.cloud1_y, &img_cloud1, SRCPAINT); //源图
	//绘制云1

	putimage(clouds.cloud2_x, clouds.cloud2_y, &img_cloud2_2, SRCAND); //掩码图
	putimage(clouds.cloud2_x, clouds.cloud2_y, &img_cloud2, SRCPAINT); //源图
	//绘制云2

	putimage(clouds.cloud3_x, clouds.cloud3_y, &img_cloud3_3, SRCAND); //掩码图
	putimage(clouds.cloud3_x, clouds.cloud3_y, &img_cloud3, SRCPAINT); //源图
	//绘制云3

	putimage(390, 130, &img_start_1, SRCAND); //掩码图
	putimage(390, 130, &img_start, SRCPAINT); //源图
	//开始图标

	settextcolor(BLACK);
	settextstyle(40, 0, _T("黑体"));
	setbkmode(TRANSPARENT);	//数字透明化显示
	outtextxy(370, 290, _T("按任意键进入规则界面"));
	//主界面

	putimage(player.x, player.y, &img_hero1_1, SRCAND);	//掩码图
	putimage(player.x, player.y, &img_hero1, SRCPAINT);	//源图
	//绘制主角，并使其处于最上层
}

void rule()
{
	loadimage();
	putimage(0, 0, &img_background);
	//绘制背景

	putimage(clouds.cloud1_x, clouds.cloud1_y, &img_cloud1_1, SRCAND); //掩码图
	putimage(clouds.cloud1_x, clouds.cloud1_y, &img_cloud1, SRCPAINT); //源图
	//绘制云1

	putimage(clouds.cloud2_x, clouds.cloud2_y, &img_cloud2_2, SRCAND); //掩码图
	putimage(clouds.cloud2_x, clouds.cloud2_y, &img_cloud2, SRCPAINT); //源图
	//绘制云2

	putimage(clouds.cloud3_x, clouds.cloud3_y, &img_cloud3_3, SRCAND); //掩码图
	putimage(clouds.cloud3_x, clouds.cloud3_y, &img_cloud3, SRCPAINT); //源图
	//绘制云3

	settextcolor(BLACK);
	settextstyle(30, 0, _T("黑体"));
	setbkmode(TRANSPARENT);	//数字透明化显示
	outtextxy(50, 50, _T("很高兴您进入本游戏，下面是游戏规则："));
	outtextxy(50, 120, _T("按空格键操控小人向上跳跃"));
	outtextxy(50, 170, _T("越过一只怪物或吃到一枚金币均得5分"));
	outtextxy(50, 240, _T("每次初始化三次机会，即三颗红心，碰到怪物红心减一"));
	outtextxy(50, 290, _T("游戏过程中，随机掉落红心，可进行机会补充"));
	outtextxy(50, 360, _T("如果规则已悉知，请按任意键开始游戏"));
}

void numberinit()
{
	player.x = 80;
	player.y = 400;
	player.g = 6;
	player.v = 0;
	player.r = 60;
	player.score = 0;
	player.live = true;
	//初始化player数据

	clouds.cloud1_x = 40;
	clouds.cloud1_y = 30;
	clouds.cloud2_x = 600;
	clouds.cloud2_y = 120;
	clouds.cloud3_x = 300;
	clouds.cloud3_y = 200;
	//初始化三朵云的位置

	heart.x_ = 820;
	heart.y_ = 90;
	heart.flag_ = 0;
	heart.live_ = 0;
	heart.x1 = 650;
	heart.x2 = 700;
	heart.x3 = 750;
	heart.y = 30;
	heart.live1 = 1;
	heart.live2 = 1;
	heart.live3 = 1;
	//三点血量的位置

	enemy.x = 790;
	enemy.y = 400;
	enemy.live = 1;
	enemy.num = 0;
	enemy.score = 1;
	//怪物出现时的坐标

	coin.x = 790;
	coin.y = 300;
	coin.live = 1;
	coin.score = 1;
	//金币出现时的坐标

}

void drawimage()			//绘制图片
{
	putimage(0, 0, &img_background);
	//绘制背景

	//使用三光栅操作符实现贴图透明化
	putimage(clouds.cloud1_x, clouds.cloud1_y, &img_cloud1_1, SRCAND); //掩码图
	putimage(clouds.cloud1_x, clouds.cloud1_y, &img_cloud1, SRCPAINT); //源图
	//绘制云1

	putimage(clouds.cloud2_x, clouds.cloud2_y, &img_cloud2_2, SRCAND); //掩码图
	putimage(clouds.cloud2_x, clouds.cloud2_y, &img_cloud2, SRCPAINT); //源图
	//绘制云2

	putimage(clouds.cloud3_x, clouds.cloud3_y, &img_cloud3_3, SRCAND); //掩码图
	putimage(clouds.cloud3_x, clouds.cloud3_y, &img_cloud3, SRCPAINT); //源图
	//绘制云3

	//显示分数
	TCHAR scoretext[10000] = { '0' };	//定义显示分数的数组
	swprintf_s(scoretext, 10000, L"%d", player.score);
	settextcolor(RED);
	settextstyle(40, 0, _T("黑体"));
	setbkmode(TRANSPARENT);	//数字透明化显示
	outtextxy(heart.x1 - 110, heart.y, scoretext);

	if (heart.live1 == 1)
	{
		putimage(heart.x1, heart.y, &img_heart_red_1, SRCAND);//掩码图
		putimage(heart.x1, heart.y, &img_heart_red, SRCPAINT);//源图
	}
	else
	{
		putimage(heart.x1, heart.y + 3, &img_heart_blank_1, SRCAND);
		putimage(heart.x1, heart.y + 3, &img_heart_blank, SRCPAINT);
	}
	if (heart.live2 == 1)
	{
		putimage(heart.x2, heart.y, &img_heart_red_1, SRCAND);//掩码图
		putimage(heart.x2, heart.y, &img_heart_red, SRCPAINT);//源图
	}
	else
	{
		putimage(heart.x2, heart.y + 3, &img_heart_blank_1, SRCAND);
		putimage(heart.x2, heart.y + 3, &img_heart_blank, SRCPAINT);
	}
	if (heart.live3 == 1)
	{
		putimage(heart.x3, heart.y, &img_heart_red_1, SRCAND);//掩码图
		putimage(heart.x3, heart.y, &img_heart_red, SRCPAINT);//源图
	}
	else
	{
		putimage(heart.x3, heart.y + 3, &img_heart_blank_1, SRCAND);
		putimage(heart.x3, heart.y + 3, &img_heart_blank, SRCPAINT);
	}
	//显示三点血量

	if(heart.flag_>0&&heart.live_==1)
	{ 
		putimage(heart.x_, heart.y_, &img_heart_red_1, SRCAND);//掩码图
		putimage(heart.x_, heart.y_, &img_heart_red, SRCPAINT);//源图
	}
	//绘制加血爱心

	if (enemy.a == 1 && coin.b != 1 && enemy.live == 1)//出现怪物1而不出现金币，且怪物仍在界面中
	{
		putimage(enemy.x, enemy.y, &img_enemy1_1, SRCAND);//掩码图
		putimage(enemy.x, enemy.y, &img_enemy1, SRCPAINT);//源图
		enemy.num = 1;
	}
	else if (enemy.a == 2 && coin.b != 1 && enemy.live == 1)//出现怪物2
	{
		putimage(enemy.x, enemy.y, &img_enemy2_2, SRCAND);//掩码图
		putimage(enemy.x, enemy.y, &img_enemy2, SRCPAINT);//源图
		enemy.num = 1;
	}
	else if (enemy.a == 3 && coin.b != 1 && enemy.live == 1)//出现怪物3
	{
		putimage(enemy.x, enemy.y, &img_enemy3_3, SRCAND);//掩码图
		putimage(enemy.x, enemy.y, &img_enemy3, SRCPAINT);//源图
		enemy.num = 1;
	}
	else if (enemy.x<-90&&coin.b == 1)//怪物不在界面中，且将出现金币时，重置怪物位置
	{
		enemy.x = 790;
	}
	//生成怪物，且怪物不与金币同时出现

	if (coin.b == 1 && coin.live == 1)//本轮出现金币，且金币未被吃掉
	{
		putimage(coin.x, coin.y, &img_coin_1, SRCAND); //掩码图
		putimage(coin.x, coin.y, &img_coin, SRCPAINT); //源图
	}
	//生成金币

	
	if (enemy.live == 0 &&coin.b!=1)//在碰到怪物时绘制主角受伤形态，用coin.b限制使主角在没有吃到金币时不出现受伤的形态
	{
		putimage(player.x, player.y, &img_hit_1, SRCAND); //掩码图
		putimage(player.x, player.y, &img_hit, SRCPAINT);
		Sleep(5);
	}
	else 
	{
		putimage(player.x, player.y, &img_hero1_1, SRCAND);	//掩码图
		putimage(player.x, player.y, &img_hero1, SRCPAINT);	//源图
	}
	//绘制主角，并使其处于最上层
}

void playermoveup()			//player移动
{
	int up = 45;
	if (_kbhit() && player.count < 2)	//检测是否有键盘按下，并且最多连续跳两次
	{
		enemy.score = 1;	//怪物分数重置，便于下次加分
		coin.score = 1;		//金币分数重置，便于下次加分
		char key = _getch();
		if (key == ' ')
		{
			PlaySound(L"..\\big homework1\\jump.wav", NULL, SND_FILENAME | SND_ASYNC);
			player.v = up - player.g;
			player.y -= player.v;
			player.count++;
		}
	}
	else    //如果没有，逐渐按照重力降落
	{
		if (player.v > 0)	//在上升阶段
		{
			player.v -= 5;	//速度每次减小5
			player.y -= player.v;	//y坐标每次减小的距离
			Sleep(50);
		}
		else	//在下降阶段
		{
			player.v -= 5;
			if ((player.y - player.v) >= 400)	//落到地上
			{
				player.y = 400;
				player.count = 0;
			}
			else    //落到地上
			{
				player.y -= player.v;
			}
			Sleep(50);
		}
	}

	if ((player.x + player.r) >= enemy.x && 
		(player.y + player.r) >= enemy.y &&
		(enemy.x + player.r) >= player.x&&
		coin.b!=1)	//如果碰到怪物，怪物消失，并用coin.b限制使不在碰到金币时扣血
	{
		enemy.live = 0;//live置0，停止绘制怪物，表明怪物消失
		PlaySound(L"..\\big homework1\\Hit.wav", NULL, SND_FILENAME | SND_ASYNC);
		if (enemy.num == 1)
		{
			if (heart.live1 == 1 && heart.live2 == 1 && heart.live3 == 1)
			{
				heart.live1 = 0;
			}
			else if (heart.live1 == 0 && heart.live2 == 1 && heart.live3 == 1)
			{
				heart.live2 = 0;
			}
			else
			{
				heart.live3 = 0;
			}
		}
		enemy.num = 0;
		
	}
	else//未碰到怪物，判断是否越过，越过加分
	{
		if (player.x >= (enemy.x + player.r) && enemy.live == 1 && enemy.score == 1)	//一只怪物只加一次分数，用enemy.score进行限制
		{
			enemy.score = 0;
			player.score += 5;
			
		}
	}
	
	if (coin.b == 1 &&
		((player.x + player.r + 30) >= coin.x ||
		(coin.x - player.x) <= player.r) && 
		fabs((coin.y - player.y)) <= player.r)	//如果碰到金币，金币消失
	{
		if (coin.live == 1)
		{
			PlaySound(L"..\\big homework1\\eatcoin.wav", NULL, SND_FILENAME | SND_ASYNC);
		}
		coin.live = 0;	//使下次画图金币消失的限制条件
		
		if (coin.score == 1)	//一枚金币只加一次分数，用coin.score进行限制
		{
			coin.score = 0;
			player.score += 5;
			player.score -= 5;
		}
	}

	if (heart.flag_ >0 && 
		((player.x + player.r + 30) >= heart.x_ || 
		(heart.x_ - player.x) <= player.r) 
		&& fabs((heart.y_ - player.y)) <= player.r)
	{
		if (heart.live_== 1)
		{
			PlaySound(L"..\\big homework1\\eatcoin.wav", NULL, SND_FILENAME | SND_ASYNC);
		}
		heart.live_= 0;	//使下次画图加血爱心出现的限制条件
		heart.flag_ = 0;

		if (heart.live1 == 0 && heart.live2 == 1 && heart.live3 == 1)
		{
			heart.live1 = 1;
		}
		else if (heart.live1 == 0 && heart.live2 == 0 && heart.live3 == 1)
		{
			heart.live2 = 1;
		}
	}

}

void cloudmove()//云的运动
{
	clouds.cloud1_x -= dv;
	clouds.cloud2_x -= dv;
	clouds.cloud3_x -= dv;
	//云向左运动

	if (clouds.cloud1_x <= -135) //超出左边界
	{
		int tmp_y= rand() % 2;
		if (tmp_y == 0)
		{
			clouds.cloud1_y = 30+rand() % 30;
		}
		else
		{
			clouds.cloud1_y =30- rand() % 30;
		}
		//y随机浮动
		int tmp_x = rand() % 2;
		if (tmp_x == 0)
		{
			clouds.cloud1_x = 790 + rand() % 30;
		}
		else
		{
			clouds.cloud1_x = 790 - rand() % 30;
		}
		//在右边界重现，x随机浮动，使背景变化
	}

	if (clouds.cloud2_x <= -135) 
	{
		int tmp_y = rand() % 2;
		if (tmp_y == 0)
		{
			clouds.cloud2_y = 120 + rand() % 50;
		}
		else
		{
			clouds.cloud2_y = 120 - rand() % 50;
		}
		int tmp_x = rand() % 2;
		if (tmp_x == 0)
		{
			clouds.cloud2_x = 790 + rand() % 30;
		}
		else
		{
			clouds.cloud2_x = 790 - rand() % 30;
		}

	}

	if (clouds.cloud3_x <= -135) 
	{
		int tmp_y = rand() % 2;
		if (tmp_y == 0)
		{
			clouds.cloud3_y = 200 + rand() % 50;
		}
		else
		{
			clouds.cloud3_y =200 - rand() % 50;
		}
		int tmp_x = rand() % 2;
		if (tmp_x == 0)
		{
			clouds.cloud3_x = 790 + rand() % 30;
		}
		else
		{
			clouds.cloud3_x = 790 - rand() % 30;
		}

	}
}

void enemymove()//怪物的运动
{
	enemy.x -= dv;
	if (enemy.x < -90)
	{
		enemy.x = 790;
		enemy.a = rand() % 3 + 1;
		enemy.live = 1;
	}
}

void coin_occure()//金币的运动
{
	coin.x -= dv;
	if (coin.x < -90)
	{
		coin.x = 790;
		coin.b = rand() % 5+1;
		coin.live = 1;	//重置金币画图
	}
}

void heart_move()//加血爱心的移动
{
	int score_ = player.score;
	if (score_ %30== 0&&heart.live_==0)//分数每到达30分有4/5的概率出现一次加血爱心
	{
		score_ %=30;
		if(heart.live_ == 0&&heart.x_==820&&player.score>0)
		heart.flag_= rand() % 5;
	}

	if (heart.flag_>0)	//爱心绘制
	{
		heart.live_ = 1;
		heart.x_ -= dv;
	}
	if (heart.x_ <= 160)	//直到爱心的x坐标小于-90时重置为820
	{
		heart.x_ -= dv;
		if (heart.x_ < -90)
		{
			heart.flag_ = 0;
			heart.x_ = 820;
			heart.live_ = 0;
		}
	}
}