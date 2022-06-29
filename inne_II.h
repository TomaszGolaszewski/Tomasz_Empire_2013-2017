#include <stdio.h>
#include <math.h>
#include "winbgi2.h"
#include <stdlib.h>
#include <time.h>

//Inne

void frame(int x,int y,int r,int c)
{
	setcolor(c);
	bar(x*r+1,y*r+1,x*r+r-1,y*r+r/10);
	bar(x*r+1,y*r+1,x*r+r/10,y*r+r-1);
	bar(x*r+1,y*r+r-1,x*r+r-1,y*r+r-r/10);
	bar(x*r+r-r/10,y*r+1,x*r+r-1,y*r+r-1);
	//emptyArea(x,y,r);
}

void hpbar(int x,int y,int r,int hp)
{
	int s;

	if(hp>0)
	{
		if(hp>50) s=2;//GREEN
		else if(hp>20) s=63;//YELLOW
		else s=4;//RED

		setcolor(s);
		bar(x*r+1,y*r+9*r/10,x*r+hp*(r-2)/100+1,y*r+r-1);
	}
}

void rip(int x,int y,int r,int c)
{
	c=teamColor(c);
	int s;
	if(c==100)
	{
		s=55;
	}
	else
	{
		s=c;
	}
	setcolor(55);//GRAY
	bar(x*r+3*r/10,y*r+r/2,x*r+7*r/10,y*r+r/2+2*r/5);
	pieslice(x*r+r/2,y*r+r/2,0,180,r/5);
	setcolor(s);
	pieslice(x*r+r/2,y*r+r/2,180,-180,r/15);
	setcolor(BLACK);
	line(x*r+3*r/10,y*r+r/2-1,x*r+3*r/10,y*r+r/2+2*r/5);
	line(x*r+7*r/10-1,y*r+r/2,x*r+7*r/10-1,y*r+r/2+2*r/5);
	line(x*r+3*r/10,y*r+r/2+2*r/5,x*r+7*r/10,y*r+r/2+2*r/5);
	arc(x*r+r/2,y*r+r/2,0,180,r/5);	
}

void ifrip(int x, int y, int r, int ifr,int c)
{
	if(ifr)
	{
		rip(x,y,r,c);
	}
}

void area(int x,int y,int r,int a)
{
	switch(a)
	{
	case 0:
		nothing(x,y,r);
		break;
	case 1:
		sea(x,y,r);
		break;
	case 2:
		forest(x,y,r);
		break;
	case 3:
		bridgelr(x,y,r);
		break;
	case 4:
		pathlr(x,y,r);
		break;
	case 5:
		pathrd(x,y,r);
		break;
	case 6:
		pathur(x,y,r);
		break;
	case 7:
		pathrdl(x,y,r);
		break;
	case 8:
		pathurd(x,y,r);
		break;
	case 9:
		pathlurd(x,y,r);
		break;
	case 10:
		village(x,y,r,55);//GRAY
		break;
	case 11:
		castle(x,y,r,4);//RED
		break;
	case 12:
		castle(x,y,r,2);//GREEN
		break;
	case 13:
		castle(x,y,r,63);//YELLOW
		break;
	case 14:
		land(x,y,r);
		break;
	case 15:
		mountain(x,y,r);
		break;
	case 16:
		bridgeud(x,y,r);
		break;
	case 17:
		pathud(x,y,r);
		break;
	case 18:
		pathdl(x,y,r);
		break;
	case 19:
		pathlu(x,y,r);
		break;
	case 20:
		pathdlu(x,y,r);
		break;
	case 21:
		pathlur(x,y,r);
		break;
	case 22:
		fortress(x,y,r);
		break;
	case 23:
		castle(x,y,r,55);//GRAY
		break;
	case 24:
		castle(x,y,r,1);//BLUE
		break;
	case 25:
		castle(x,y,r,0);//BLACK
		break;
	case 26:
		castle(x,y,r,5);//PINK
		break;
	case 27:
		village(x,y,r,4);//RED
		break;
	case 28:
		village(x,y,r,1);//BLUE
		break;
	case 29:
		village(x,y,r,0);//BLACK
		break;
	case 30:
		village(x,y,r,2);//GREEN
		break;
	case 31:
		village(x,y,r,63);//YELLOW
		break;
	case 32:
		village(x,y,r,5);//PINK
		break;
	case 55:
		land(x,y,r);//WALL
		break;
	}
}

void unit(int x,int y,int r,int a, int t, int hp)
{
	switch(a)
	{
	case 1:
		king(x,y,r,t);
		break;
	case 2:
		knight(x,y,r,t);
		break;
	case 3:
		golem(x,y,r,t);
		break;
	case 4:
		dragon(x,y,r,t);
		break;
	case 5:
		morzak(x,y,r,t);
		break;
	case 6:
		archer(x,y,r,t);
		break;
	case 7:
		katapulta(x,y,r,t);
		break;
	case 8:
		ent(x,y,r,t);
		break;
	case 9:
		nekrofil(x,y,r,t);
		break;
	case 10:
		zebuszka(x,y,r,t);
		break;
	case 11:
		gandalf(x,y,r,t);
		break;
	case 12:
		zyd(x,y,r,t);
		break;
	case 55:
		wall(x,y,r,t);
		break;
	case 77:
		boss(x,y,r,t);
		break;
	case 98:
		szkielet(x,y,r,t);
		break;
	case 99:
		duch(x,y,r,t);
		break;
	}

	hpbar(x,y,r,hp);
}

void distance(int x,int y,int Rx,int Ry, int **At, int k)
{
	int p;

	if(k==6) p=3;//Archer
	else if(k==7) p=5;//Katapulta
	else if(k==11) p=3;//Gandalf
	else p=2;
	
	At[x][y]=p;
	for(p;p>0;p--)
	{
		for(int i=0;i<Ry;++i)
		{
			for(int k=0;k<Rx;++k)
			{
				if(p==At[k][i])
				{
					if(((k-1)>=0)&&(At[k-1][i]==0))//<
					{
						At[k-1][i]=p-1;
					}
					if(((k+1)<Rx)&&(At[k+1][i]==0))//>
					{
						At[k+1][i]=p-1;
					}
					if(((i-1)>=0)&&(At[k][i-1]==0))//A
					{
						At[k][i-1]=p-1;
					}
					if(((i+1)<Ry)&&(At[k][i+1]==0))//V
					{
						At[k][i+1]=p-1;
					}
				}
			}
		}
	}
}

void moneta(int x,int y,int r, int c)
{
	setcolor(c);
	pieslice(x,y,180,-180,r/4);
	setcolor(BLACK);
	circle(x,y,r/4);
}

void monetki(int Rx,int Ry,int r,int kasa)
{
	int zolte2;
	int srebrne=kasa%10;
	kasa=(kasa-srebrne)/10;
	int zolte=kasa/10+2;

	for(int i=0;i<srebrne;i++)
	{
		moneta(Rx*r+11*r/4,23*r/4-i*r/4,r,WHITE);
	}
	for(int k=1;k<zolte;k++)
	{
		if(k!=(zolte-1)) zolte2=10;
		else zolte2=kasa%10;

		for(int i=0;i<zolte2;i++)
		{
			moneta(Rx*r+11*r/4-k*r/2,23*r/4-i*r/4,r,63);
		}	
	}
}

void monetki2(int y,int r,int kasa)
{
	int srebrne=kasa%10;
	int zolte=(kasa-srebrne)/10;
	
	for(int k=0;k<zolte;k++)
	{
		moneta(4*r+k*r/4,y*r+r/2,r,63);
	}
	for(int i=0;i<srebrne;i++)
	{
		moneta(4*r+(i+zolte)*r/4,y*r+r/2,r,WHITE);
	}
	
}

void NazwaTeamu(int t)
{
	if(t==0) printf("Czerwony:");//RED
	else if(t==1) printf("Czarny:");//BLACK
	else if(t==2) printf("Zielony:");//GREEN
	else if(t==3) printf("Niebieski:");//BLUE
	else if(t==4) printf("Zolty:");//YELLOW
	else if(t==5) printf("Rozowy:");//PINK
	else if(t==9) printf("ERROR");
	else printf("FATAL ERROR");
}

void NazwaTeamu2(int t)
{
	if(t==0) printf("CZERWONY:");//RED
	else if(t==1) printf("CZARNY:");//BLACK
	else if(t==2) printf("ZIELONY:");//GREEN
	else if(t==3) printf("NIEBIESKI:");//BLUE
	else if(t==4) printf("ZOLTY:");//YELLOW
	else if(t==5) printf("ROZOWY:");//PINK
	else if(t==9) printf("ERROR");
	else printf("FATAL ERROR");
}

void NazwaTeamu3(int t)
{
	if(t==0) printf("Czerwony");//RED
	else if(t==1) printf("Czarny");//BLACK
	else if(t==2) printf("Zielony");//GREEN
	else if(t==3) printf("Niebieski");//BLUE
	else if(t==4) printf("Zolty");//YELLOW
	else if(t==5) printf("Rozowy");//PINK
	else if(t==9) printf("ERROR");
	else printf("FATAL ERROR");
}