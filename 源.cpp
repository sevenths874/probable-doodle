#include<stdio.h>
#include<conio.h>
#include<time.h>
#include<stdlib.h>
#include<graphics.h>
#include<process.h>
#include<mmsystem.h>
#include<windows.h>
#pragma comment(lib,"Winmm.lib")     // 引用 Windows Multimedia API

//声明图片变量
IMAGE begin;           //开始界面
IMAGE background;      //背景
IMAGE bird[2];         //鸟
IMAGE down[2];         //往下的柱子(上边的柱子)
IMAGE up[2];           //往上的柱子(下边的柱子)
IMAGE end[2];          //结束界面

//定义Pillar结构体
struct Pillar
{
	float x;
	float y;               //定义起始坐标
	float height;          //定义柱子显示的高度
}pillar[3];
struct Pillar *n;        //定义指向pillar[3]的指针

//定义Bird结构体
struct Bird
{
	float x;
	float y;               //定义起始坐标
	int speed;           //定义下降速度
}flybird={124,304,80};  
struct Bird *p;          //定义指向flybird的指针

//定义播放背景音乐函数
void play_bgm()
{
	PlaySound(TEXT("background.wav"),NULL,SND_FILENAME|SND_ASYNC|SND_LOOP);
}

//定义加载图片函数
void load_image()
{
	loadimage(&begin,_T("begin.bmp"));                 //开始界面

	loadimage(&background,_T("background.bmp"));       //加载图片到变量background，记得写上_T

	loadimage(bird,_T("bird_1.bmp"),48,48);         
	loadimage(bird+1,_T("bird_2.bmp"),48,48);          //鸟的部分

	loadimage(down,_T("down_1.bmp"),52,320);
	loadimage(down+1,_T("down_2.bmp"),52,320);        //往下的柱子

	loadimage(up,_T("up_1.bmp"),52,320);
	loadimage(up+1,_T("up_2.bmp"),52,320);            //往上的柱子

	loadimage(end,_T("end_1.bmp"),204,54);
	loadimage(end+1,_T("end_2.bmp"),204,54);          //结束界面
}

//定义一组柱子的数量
int i;
//定义初始化柱子的函数
void init_pillar(struct Pillar pillar[],int i)
{
	pillar[i].height=rand()%100+170;       //随机生成柱子高度范围为170～269

//判断柱子高度是否相同，相同则再次随机生成高度(循环队列)
	while(pillar[i].height==pillar[(i+1)%3].height || pillar[i].height==pillar[(i+2)%3].height)       
	{
		pillar[i].height=rand()%100+160;
	}
	pillar[i].x=288;
	pillar[i].y=0;      //起始位置
}

//定义输出柱子的函数
void put_pillar(struct Pillar pillar[],int i)
{
	for(i=0;i<3;i++)
	{
		//pillar.x,0 ：在窗口的那个位置开始显示(窗口坐标(x,y))
		//52,pillar.height ：显示图片的尺寸大小
		//0,(320-pillar.height) ：在图片的那个位置开始显示(图片坐标系在图片的左上角)
		//往下的柱子(上边的柱子)
		putimage(pillar[i].x,0,52,pillar[i].height,down+1,0,(320-pillar[i].height),SRCAND);        //掩码图用SRCAND方式
		putimage(pillar[i].x,0,52,pillar[i].height,down,0,(320-pillar[i].height),SRCPAINT);        //背景图用SRCPAINT方式

		//往上的柱子(下边的柱子)
		putimage(pillar[i].x,(192+pillar[i].height),52,(320-pillar[i].height),up+1,0,0,SRCAND);    //掩码图用SRCAND方式   512-(320-pillar[i].h)=192+pillar[i].h
		putimage(pillar[i].x,(192+pillar[i].height),52,(320-pillar[i].height),up,0,0,SRCPAINT);    //背景图用SRCPAINT方式
	}
}

//定义柱子移动的函数
void move_pillar(struct Pillar pillar[],int i)
{
	for(i=0;i<3;i++)
	{
		BeginBatchDraw();
		pillar[i].x-=5;
		//边界处理
		if(pillar[i].x<-162)
		{
			init_pillar(pillar,i);
		}
		EndBatchDraw();
	}
}

//定义输出鸟的函数
void put_bird(int x,int y)
{
	BeginBatchDraw();
	putimage(x,y,bird+1,SRCAND);     //掩码图用SRCAND方式
	putimage(x,y,bird,SRCPAINT);     //背景图用SRCPAINT方式
	EndBatchDraw();
}

//定义按键函数，按"w"或者"space"鸟就往上动
void key_down()
{
	char userkey=getch();            //定义不可见字符的键盘输入
	switch(userkey)
	{
		case 32:                   //空格键
			(p->y)-=p->speed;
			break;
		case 119:                  //w键
			(p->y)-=p->speed;
		default:
			break;
	}
}

//定义撞击判断函数，如果鸟撞到窗口上沿(y坐标为0)或者背景图中的地面(y坐标为512)，则游戏结束
int strike_floor()
{
	if((p->y)>=484)           //484=512-48+24    ((p->y)>=484 || (p->y)<=-24)
	{
		return 1;
	}
	else 
	{
		return 0;
	}
}

//定义撞击判断函数，如果鸟撞到柱子，则游戏结束
int strike_pillar(struct Pillar pillar[])
{
	for(i=0;i<3;i++)
	{
		 if( pillar[i].x>=((p->x)-38) && pillar[i].x<=((p->x)+34) )    //判断是否与上边柱子相撞
			{
				if( pillar[i].height>=((p->y)+24) )
				{
					return 1;                                         //如果与任意柱子发生碰撞，则返回1
				}
			}

		if( pillar[i].x>=((p->x)-38) && pillar[i].x<=((p->x)+34) )    //判断是否与下边柱子相撞
			{
				if( (192+pillar[i].height)<=((p->y)+33) )
				{
					return 2;                                         //如果与任意柱子发生碰撞，则返回2
				}
			}
		/* else 
		 {
			 return 0;            // 注意，(return 0)一定要写在for循环外面！！！
			                      //(return 0)写在for循环里面和外面完全不一样。当写在for循环里面时，如果没有与第一个柱子发生碰撞的话，则返回一个0值，这是再与第二
									个柱子发生碰撞的话，在主函数里的条件判断if( strike_floor() || strike_pillar(pillar) )就不会执行！！！
								    
		 }*/
	}
		 return 0;               //将(return 0)写在for循环外面，如果与三个柱子都没有碰撞，则返回0
}

//定义显示游戏结束函数
void gameover()
{
	int x=50;
	int y=608;
	while(y>=200)
	{
		BeginBatchDraw();
		putimage(0,0,&background);        //刷新背景
		putimage(x,y,end+1,SRCAND);
		putimage(x,y,end,SRCPAINT);       //输出结束界面
		y-=50;
		Sleep(50);
		EndBatchDraw();
	}
	system("gameover.vbs");               //输出音频
	Sleep(5000);
	exit(0);
}

int main()
{
	srand((unsigned int)time(NULL));
	p=&flybird;                           //将指针指向flybird
	//n=pillar;                           //将指针指向pillar[3]
	play_bgm();                           //播放背景音乐
	load_image();                         //加载图片
	for(i=0;i<3;i++)
	{
		init_pillar(pillar,i);            //初始化柱子
		pillar[i].x=288+i*150;            //每根柱子坐标相距150
	}
	system("title Flybird beta version 1.0");
	initgraph(288,608);                   //定义窗口大小,窗口坐标系在窗口的左上角 
	BeginBatchDraw();
	putimage(0,0,&begin);                 //输出开始界面
	Sleep(3000);                         
	EndBatchDraw(); 
	while(1)
	{
		BeginBatchDraw();                 //图片双缓冲
		putimage(0,0,&background);        //将背景图片输出到窗口  
		put_pillar(pillar,i);             //输出柱子到窗口
		move_pillar(pillar,i);            //移动柱子
		put_bird(p->x,p->y);              //输出鸟到窗口
		FlushBatchDraw();
		(p->y)+=12;                       //每次下降12
		if(kbhit())                       //判断是否有按键，有就返回一个非零值
		{
			key_down();
		}
		if( strike_floor() || strike_pillar(pillar) )
		{
			//char userkey=getch();
			gameover();                   //游戏结束
		}
		Sleep(90);                       //休眠90ms    
		EndBatchDraw();
	}
	getchar();
	closegraph();
	return 0;
}
