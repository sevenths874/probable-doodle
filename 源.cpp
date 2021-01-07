#include<stdio.h>
#include<conio.h>
#include<time.h>
#include<stdlib.h>
#include<graphics.h>
#include<process.h>
#include<mmsystem.h>
#include<windows.h>
#pragma comment(lib,"Winmm.lib")     // ���� Windows Multimedia API

//����ͼƬ����
IMAGE begin;           //��ʼ����
IMAGE background;      //����
IMAGE bird[2];         //��
IMAGE down[2];         //���µ�����(�ϱߵ�����)
IMAGE up[2];           //���ϵ�����(�±ߵ�����)
IMAGE end[2];          //��������

//����Pillar�ṹ��
struct Pillar
{
	float x;
	float y;               //������ʼ����
	float height;          //����������ʾ�ĸ߶�
}pillar[3];
struct Pillar *n;        //����ָ��pillar[3]��ָ��

//����Bird�ṹ��
struct Bird
{
	float x;
	float y;               //������ʼ����
	int speed;           //�����½��ٶ�
}flybird={124,304,80};  
struct Bird *p;          //����ָ��flybird��ָ��

//���岥�ű������ֺ���
void play_bgm()
{
	PlaySound(TEXT("background.wav"),NULL,SND_FILENAME|SND_ASYNC|SND_LOOP);
}

//�������ͼƬ����
void load_image()
{
	loadimage(&begin,_T("begin.bmp"));                 //��ʼ����

	loadimage(&background,_T("background.bmp"));       //����ͼƬ������background���ǵ�д��_T

	loadimage(bird,_T("bird_1.bmp"),48,48);         
	loadimage(bird+1,_T("bird_2.bmp"),48,48);          //��Ĳ���

	loadimage(down,_T("down_1.bmp"),52,320);
	loadimage(down+1,_T("down_2.bmp"),52,320);        //���µ�����

	loadimage(up,_T("up_1.bmp"),52,320);
	loadimage(up+1,_T("up_2.bmp"),52,320);            //���ϵ�����

	loadimage(end,_T("end_1.bmp"),204,54);
	loadimage(end+1,_T("end_2.bmp"),204,54);          //��������
}

//����һ�����ӵ�����
int i;
//�����ʼ�����ӵĺ���
void init_pillar(struct Pillar pillar[],int i)
{
	pillar[i].height=rand()%100+170;       //����������Ӹ߶ȷ�ΧΪ170��269

//�ж����Ӹ߶��Ƿ���ͬ����ͬ���ٴ�������ɸ߶�(ѭ������)
	while(pillar[i].height==pillar[(i+1)%3].height || pillar[i].height==pillar[(i+2)%3].height)       
	{
		pillar[i].height=rand()%100+160;
	}
	pillar[i].x=288;
	pillar[i].y=0;      //��ʼλ��
}

//����������ӵĺ���
void put_pillar(struct Pillar pillar[],int i)
{
	for(i=0;i<3;i++)
	{
		//pillar.x,0 ���ڴ��ڵ��Ǹ�λ�ÿ�ʼ��ʾ(��������(x,y))
		//52,pillar.height ����ʾͼƬ�ĳߴ��С
		//0,(320-pillar.height) ����ͼƬ���Ǹ�λ�ÿ�ʼ��ʾ(ͼƬ����ϵ��ͼƬ�����Ͻ�)
		//���µ�����(�ϱߵ�����)
		putimage(pillar[i].x,0,52,pillar[i].height,down+1,0,(320-pillar[i].height),SRCAND);        //����ͼ��SRCAND��ʽ
		putimage(pillar[i].x,0,52,pillar[i].height,down,0,(320-pillar[i].height),SRCPAINT);        //����ͼ��SRCPAINT��ʽ

		//���ϵ�����(�±ߵ�����)
		putimage(pillar[i].x,(192+pillar[i].height),52,(320-pillar[i].height),up+1,0,0,SRCAND);    //����ͼ��SRCAND��ʽ   512-(320-pillar[i].h)=192+pillar[i].h
		putimage(pillar[i].x,(192+pillar[i].height),52,(320-pillar[i].height),up,0,0,SRCPAINT);    //����ͼ��SRCPAINT��ʽ
	}
}

//���������ƶ��ĺ���
void move_pillar(struct Pillar pillar[],int i)
{
	for(i=0;i<3;i++)
	{
		BeginBatchDraw();
		pillar[i].x-=5;
		//�߽紦��
		if(pillar[i].x<-162)
		{
			init_pillar(pillar,i);
		}
		EndBatchDraw();
	}
}

//���������ĺ���
void put_bird(int x,int y)
{
	BeginBatchDraw();
	putimage(x,y,bird+1,SRCAND);     //����ͼ��SRCAND��ʽ
	putimage(x,y,bird,SRCPAINT);     //����ͼ��SRCPAINT��ʽ
	EndBatchDraw();
}

//���尴����������"w"����"space"������϶�
void key_down()
{
	char userkey=getch();            //���岻�ɼ��ַ��ļ�������
	switch(userkey)
	{
		case 32:                   //�ո��
			(p->y)-=p->speed;
			break;
		case 119:                  //w��
			(p->y)-=p->speed;
		default:
			break;
	}
}

//����ײ���жϺ����������ײ����������(y����Ϊ0)���߱���ͼ�еĵ���(y����Ϊ512)������Ϸ����
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

//����ײ���жϺ����������ײ�����ӣ�����Ϸ����
int strike_pillar(struct Pillar pillar[])
{
	for(i=0;i<3;i++)
	{
		 if( pillar[i].x>=((p->x)-38) && pillar[i].x<=((p->x)+34) )    //�ж��Ƿ����ϱ�������ײ
			{
				if( pillar[i].height>=((p->y)+24) )
				{
					return 1;                                         //������������ӷ�����ײ���򷵻�1
				}
			}

		if( pillar[i].x>=((p->x)-38) && pillar[i].x<=((p->x)+34) )    //�ж��Ƿ����±�������ײ
			{
				if( (192+pillar[i].height)<=((p->y)+33) )
				{
					return 2;                                         //������������ӷ�����ײ���򷵻�2
				}
			}
		/* else 
		 {
			 return 0;            // ע�⣬(return 0)һ��Ҫд��forѭ�����棡����
			                      //(return 0)д��forѭ�������������ȫ��һ������д��forѭ������ʱ�����û�����һ�����ӷ�����ײ�Ļ����򷵻�һ��0ֵ����������ڶ�
									�����ӷ�����ײ�Ļ�������������������ж�if( strike_floor() || strike_pillar(pillar) )�Ͳ���ִ�У�����
								    
		 }*/
	}
		 return 0;               //��(return 0)д��forѭ�����棬������������Ӷ�û����ײ���򷵻�0
}

//������ʾ��Ϸ��������
void gameover()
{
	int x=50;
	int y=608;
	while(y>=200)
	{
		BeginBatchDraw();
		putimage(0,0,&background);        //ˢ�±���
		putimage(x,y,end+1,SRCAND);
		putimage(x,y,end,SRCPAINT);       //�����������
		y-=50;
		Sleep(50);
		EndBatchDraw();
	}
	system("gameover.vbs");               //�����Ƶ
	Sleep(5000);
	exit(0);
}

int main()
{
	srand((unsigned int)time(NULL));
	p=&flybird;                           //��ָ��ָ��flybird
	//n=pillar;                           //��ָ��ָ��pillar[3]
	play_bgm();                           //���ű�������
	load_image();                         //����ͼƬ
	for(i=0;i<3;i++)
	{
		init_pillar(pillar,i);            //��ʼ������
		pillar[i].x=288+i*150;            //ÿ�������������150
	}
	system("title Flybird beta version 1.0");
	initgraph(288,608);                   //���崰�ڴ�С,��������ϵ�ڴ��ڵ����Ͻ� 
	BeginBatchDraw();
	putimage(0,0,&begin);                 //�����ʼ����
	Sleep(3000);                         
	EndBatchDraw(); 
	while(1)
	{
		BeginBatchDraw();                 //ͼƬ˫����
		putimage(0,0,&background);        //������ͼƬ���������  
		put_pillar(pillar,i);             //������ӵ�����
		move_pillar(pillar,i);            //�ƶ�����
		put_bird(p->x,p->y);              //����񵽴���
		FlushBatchDraw();
		(p->y)+=12;                       //ÿ���½�12
		if(kbhit())                       //�ж��Ƿ��а������оͷ���һ������ֵ
		{
			key_down();
		}
		if( strike_floor() || strike_pillar(pillar) )
		{
			//char userkey=getch();
			gameover();                   //��Ϸ����
		}
		Sleep(90);                       //����90ms    
		EndBatchDraw();
	}
	getchar();
	closegraph();
	return 0;
}
