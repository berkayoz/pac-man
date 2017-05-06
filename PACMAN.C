#include<stdio.h>
#include<dos.h>
#include<math.h>
#include<graphics.h>
#include<conio.h>
void duvar_ciz();
void nokta_ciz();
void menu_ciz();
void oyun_bitir();
void pacman_ciz(int fx, int fy, int state, int yon);

int eskix,eskiy;
int x=301,y=301;
int yem=1;
char yems[50];

int main()
{
	union REGS i,o;
	int gd=DETECT, gm,x1,y1,dugme;
	int yon=3;
	int state=3;
	char button,ch;
	initgraph(&gd,&gm," ");
	menu_ciz();
	i.x.ax=1;
	int86(0x33,&i,&o);
	i.x.ax=3;
	x1=i.x.cx;
	y1=i.x.dx;
	while(1)
	{
		x1=o.x.cx;
		y1=o.x.dx;
		int86(0x33,&i,&o);
		if(kbhit())
		{
			ch=getch();
			if(ch==27)
				break;
		}
			
		if ((x1>=270 && x1<=330) && (y1>=205 && y1<=235))
		{
		   dugme=o.x.bx&7;
		   if (dugme==1)
			{
				cleardevice();
				i.x.ax=1;
				duvar_ciz();
				nokta_ciz();
				pacman_ciz(x,y,state,yon);
				setcolor(BLUE);
				setfillstyle(SOLID_FILL, 1);
				bar(0,0,600,40);
				while(1)
				{
					if(kbhit())
					{
						button = getch();
						if(button == 'w' || button == 'W')
						{
							if(!(getpixel(x-17,y-21) ==1 || getpixel(x+17,y-21) ==1))
							{
								yon = 1;
							}
							
						}
						else if(button == 's' || button == 'S')
						{
							if(!(getpixel(x-17,y+19) ==1 || getpixel(x+17,y+19) ==1))
							{
								yon = 2;
							}
						}
						else if(button == 'a' || button == 'A')
						{
							if(!(getpixel(x-21,y-17) ==1 || getpixel(x-21,y+17) ==1))
							{
								yon = 3;
							}
						}
						else if(button == 'd' || button == 'D')
						{
							if(!(getpixel(x+19,y-17) ==1 || getpixel(x+19,y+17) ==1))
							{
								yon = 4;
							}

						}
						else if(button == 27)
						{
							break;
						}
					}
					switch(yon) {
						case 1:
						if(yem != 72)
						{
							if(!(getpixel(x-17,y-21) ==1 || getpixel(x+17,y-21) ==1))
							{
								if(getpixel(x,y-22) == WHITE)
								{
									yem++;
									setfillstyle(SOLID_FILL, 1);
									bar(0,0,50,30);
									sprintf(yems, "%d", yem);
									setcolor(RED);
									outtextxy(10,10,yems);
								}
								y-=10;
								if(state == 1)
								{
									state++;
								}
								else if(state == 2)
								{
									state++;
								}
								else if(state ==3)
								{
									state=1;
								}
								pacman_ciz(x,y,state,1);
							}
						}
						else
						{
							oyun_bitir();
						}
						break;
						case 2:
						if(yem != 72)
						{
							if(!(getpixel(x-17,y+19) ==1 || getpixel(x+17,y+19) ==1))
							{
								if(getpixel(x,y+20) == WHITE)
								{
									yem++;
									setfillstyle(SOLID_FILL, 1);
									bar(0,0,50,30);
									sprintf(yems, "%d", yem);
									setcolor(RED);
									outtextxy(10,10,yems);
								}
								y+=10;
								if(state == 1)
								{
									state++;
								}
								else if(state == 2)
								{
									state++;
								}
								else if(state ==3)
								{
									state=1;
								}
								pacman_ciz(x,y,state,2);

							}
						}
						else
						{
							oyun_bitir();
						}
						break;
						case 3:
						if(yem != 72)
						{
							if(!(getpixel(x-21,y-17) ==1 || getpixel(x-21,y+17) ==1))
							{
								if(getpixel(x-22,y) == WHITE)
								{
									yem++;
									setfillstyle(SOLID_FILL, 1);
									bar(0,0,50,30);
									sprintf(yems, "%d", yem);
									setcolor(RED);
									outtextxy(10,10,yems);
								}
								x-=10;
								if(state == 1)
								{
									state++;
								}
								else if(state == 2)
								{
									state++;
								}
								else if(state ==3)
								{
									state=1;
								}
								pacman_ciz(x,y,state,3);
							}
						}
						else
						{
							oyun_bitir();
						}
						break;
						case 4:
						if(yem != 72)
						{
							if(!(getpixel(x+19,y-17) ==1 || getpixel(x+19,y+17) ==1))
							{
								if(getpixel(x+20,y) == WHITE)
								{
									yem++;
									setfillstyle(SOLID_FILL, 1);
									bar(0,0,50,30);
									sprintf(yems, "%d", yem);
									setcolor(RED);
									outtextxy(10,10,yems);
								}
								x+=10;
								if(state == 1)
								{
									state++;
								}
								else if(state == 2)
								{
									state++;
								}
								else if(state ==3)
								{
									state=1;
								}
								pacman_ciz(x,y,state,4);
									
							}
						}
						else
						{
							oyun_bitir();
						}
						break;
					}
					delay(100);
				}
			}
		}
		else if ((x1>=270 && x1<=330) && (y1>=245 && y1<=275))
		{
		   dugme=o.x.bx&7;
		   if (dugme==1)
			{
				return 0;
			}
		}
	}
	closegraph();
}

void duvar_ciz()
{
	int mx=600;
	int my=440;
	setbkcolor(BLACK);
	setcolor(BLUE);
	setfillstyle(SOLID_FILL, 1);
	bar(0,0,mx,40);
	bar(0,my-40,mx,my);
	bar(0,0,40,my);
	bar(mx-40,0,mx,my);
	bar(160,40,200,120);
	bar(400,40,440,120);
	bar(160,320,200,400);
	bar(400,320,440,400);
	bar(240,80,360,120);
	bar(240,320,360,360);
	bar(80,80,120,160);
	bar(80,160,160,200);
	bar(80,240,160,280);
	bar(80,280,120,360);
	bar(480,80,520,160);
	bar(440,160,520,200);
	bar(480,280,520,360);
	bar(440,240,520,280);
	bar(200,160,240,280);
	bar(360,160,400,280);
	bar(240,240,360,280);
	bar(240,160,280,200);
	bar(320,160,360,200);
}

void menu_ciz()
{
	setfillstyle(SOLID_FILL, YELLOW);
	setcolor(YELLOW);
	pieslice(305, 100, 45, 315, 50);
	setfillstyle(SOLID_FILL, 0);
	setcolor(0);
	fillellipse(318, 60, 2, 2);
	setcolor(DARKGRAY);
	setfillstyle(SOLID_FILL, RED);
	bar(270, 205, 330, 235);
	rectangle(270, 205, 330, 235);
	setcolor(LIGHTGRAY);
	outtextxy(279,215,"Baslat");
	setcolor(DARKGRAY);
	bar(270, 245, 330, 275);
	rectangle(270, 245, 330, 275);
	setcolor(LIGHTGRAY);
	outtextxy(280,255,"Cikis");
}

void nokta_ciz()
{
	int mx=600;
	int my=440;
	setfillstyle(SOLID_FILL, WHITE);
	setcolor(WHITE);
	fillellipse(61, 61, 2, 2);
	fillellipse(101, 61, 2, 2);
	fillellipse(141, 61, 2, 2);
	fillellipse(141, 101, 2, 2);
	fillellipse(141, 141, 2, 2);
	fillellipse(181, 141, 2, 2);
	fillellipse(181, 181, 2, 2);
	fillellipse(181, 221, 2, 2);
	fillellipse(181, 261, 2, 2);
	fillellipse(181, 301, 2, 2);
	fillellipse(141, 301, 2, 2);
	fillellipse(141, 341, 2, 2);
	fillellipse(141, 381, 2, 2);
	fillellipse(101, 381, 2, 2);
	fillellipse(61, 381, 2, 2);
	fillellipse(61, 341, 2, 2);
	fillellipse(61, 301, 2, 2);
	fillellipse(61, 261, 2, 2);
	fillellipse(61, 221, 2, 2);
	fillellipse(61, 181, 2, 2);
	fillellipse(61, 141, 2, 2);
	fillellipse(61, 101, 2, 2);
	fillellipse(101, 221, 2, 2);
	fillellipse(141, 221, 2, 2);
	fillellipse(221, 141, 2, 2);
	fillellipse(261, 141, 2, 2);
	fillellipse(301, 141, 2, 2);
	fillellipse(341, 141, 2, 2);
	fillellipse(381, 141, 2, 2);
	fillellipse(221, 61, 2, 2);
	fillellipse(261, 61, 2, 2);
	fillellipse(301, 61, 2, 2);
	fillellipse(341, 61, 2, 2);
	fillellipse(381, 61, 2, 2);
	fillellipse(221, 101, 2, 2);
	fillellipse(381, 101, 2, 2);
	fillellipse(221, 301, 2, 2);
	fillellipse(261, 301, 2, 2);
	fillellipse(301, 301, 2, 2);
	fillellipse(341, 301, 2, 2);
	fillellipse(381, 301, 2, 2);
	fillellipse(221, 341, 2, 2);
	fillellipse(381, 341, 2, 2);
	fillellipse(221, 381, 2, 2);
	fillellipse(261, 381, 2, 2);
	fillellipse(301, 381, 2, 2);
	fillellipse(341, 381, 2, 2);
	fillellipse(381, 381, 2, 2);
	fillellipse(421, 141, 2, 2);
	fillellipse(421, 181, 2, 2);
	fillellipse(421, 221, 2, 2);
	fillellipse(421, 261, 2, 2);
	fillellipse(421, 301, 2, 2);
	fillellipse(461, 61, 2, 2);
	fillellipse(461, 101, 2, 2);
	fillellipse(461, 141, 2, 2);
	fillellipse(461, 221, 2, 2);
	fillellipse(461, 301, 2, 2);
	fillellipse(461, 341, 2, 2);
	fillellipse(461, 381, 2, 2);
	fillellipse(501, 61, 2, 2);
	fillellipse(501, 221, 2, 2);
	fillellipse(501, 381, 2, 2);
	fillellipse(541, 61, 2, 2);
	fillellipse(541, 101, 2, 2);
	fillellipse(541, 141, 2, 2);
	fillellipse(541, 181, 2, 2);
	fillellipse(541, 221, 2, 2);
	fillellipse(541, 261, 2, 2);
	fillellipse(541, 301, 2, 2);
	fillellipse(541, 341, 2, 2);
	fillellipse(541, 381, 2, 2);
	
}
void pacman_ciz(int fx, int fy, int state,int yon)
{

	setfillstyle(SOLID_FILL, BLACK);
	setcolor(BLACK);
	pieslice(eskix, eskiy, 0, 360, 17);
	setfillstyle(SOLID_FILL, YELLOW);
	setcolor(YELLOW);
	if(state == 1)
	{
		switch(yon) {
			case 1:
				pieslice(fx, fy, 0, 360, 17);
				setfillstyle(SOLID_FILL, BLACK);
				setcolor(BLACK);
				pieslice(fx, fy, 45, 135, 17);
			break;
			case 2:
				pieslice(fx, fy, 0, 360, 17);
				setfillstyle(SOLID_FILL, BLACK);
				setcolor(BLACK);
				pieslice(fx, fy, 225, 315, 17);
			break;
			case 3:
				pieslice(fx, fy, 0, 360, 17);
				setfillstyle(SOLID_FILL, BLACK);
				setcolor(BLACK);
				pieslice(fx, fy, 135, 225, 17);
			break;
			case 4:
			pieslice(fx, fy, 45, 315, 17);
			break;
		}
		
	}
	else if(state == 2)
	{
			switch(yon) {
			case 1:
				pieslice(fx, fy, 0, 360, 17);
				setfillstyle(SOLID_FILL, BLACK);
				setcolor(BLACK);
				pieslice(fx, fy, 68, 112, 17);
			break;
			case 2:
				pieslice(fx, fy, 0, 360, 17);
				setfillstyle(SOLID_FILL, BLACK);
				setcolor(BLACK);
				pieslice(fx, fy, 248, 292, 17);
			break;
			case 3:
				pieslice(fx, fy, 0, 360, 17);
				setfillstyle(SOLID_FILL, BLACK);
				setcolor(BLACK);
				pieslice(fx, fy, 158, 202, 17);
			break;
			case 4:
			pieslice(fx, fy, 22, 338, 17);
			break;
		}
	}
	else if(state == 3)
	{
		pieslice(fx, fy, 0, 360, 17);
	}
	eskix=fx;
	eskiy=fy;
	
}

void oyun_bitir()
{
	int u;
	for(u=0;u<4;u++)
	{
		cleardevice();
		duvar_ciz();
		delay(50);
	}
	setcolor(RED);
	outtextxy(240,215,"Tebrikler, oyun bitti!");
}