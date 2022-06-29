#include <stdio.h>
#include <math.h>
#include "winbgi2.h"
#include <stdlib.h>
#include <time.h>

//Inne

void TomaszGames(int Rx,int Ry)
{
	int x;
	int y;
	x=Rx/30;
	y=Ry/20;
	if(y<x)x=y;
	else y=x;
	
	setcolor(BLUE);
	//T
	bar(1*x,2*y,9*x,4*y);
	bar(4*x,2*y,6*x,10*y);
	//o
	bar(7*x,5*y,11*x,6*y);
	bar(7*x,9*y,11*x,10*y);
	bar(7*x,5*y,8*x,10*y);
	bar(10*x,5*y,11*x,10*y);
	//m
	bar(12*x,5*y,17*x,6*y);
	bar(12*x,5*y,13*x,10*y);
	bar(14*x,5*y,15*x,10*y);
	bar(16*x,5*y,17*x,10*y);
	//a
	bar(18*x,5*y,21*x,6*y);
	bar(18*x,5*y,19*x,10*y);
	bar(20*x,5*y,21*x,10*y);
	bar(18*x,7*y,21*x,8*y);
	//s
	bar(22*x,5*y,25*x,6*y);
	bar(22*x,7*y,25*x,8*y);
	bar(22*x,9*y,25*x,10*y);
	bar(22*x,5*y,23*x,8*y);
	bar(24*x,7*y,25*x,10*y);
	//z
	bar(26*x,5*y,29*x,6*y);
	bar(26*x,7*y,29*x,8*y);
	bar(26*x,9*y,29*x,10*y);
	bar(28*x,5*y,29*x,8*y);
	bar(26*x,7*y,27*x,10*y);
	//G
	bar(5*x,11*y,11*x,13*y);
	bar(5*x,17*y,11*x,19*y);
	bar(5*x,11*y,7*x,19*y);
	bar(9*x,15*y,11*x,19*y);
	//a
	bar(12*x,14*y,15*x,15*y);
	bar(12*x,14*y,13*x,19*y);
	bar(14*x,14*y,15*x,19*y);
	bar(12*x,16*y,15*x,17*y);
	//m
	bar(16*x,14*y,21*x,15*y);
	bar(16*x,14*y,17*x,19*y);
	bar(18*x,14*y,19*x,19*y);
	bar(20*x,14*y,21*x,19*y);
	//e
	bar(22*x,14*y,25*x,15*y);
	bar(22*x,16*y,25*x,17*y);
	bar(22*x,18*y,25*x,19*y);
	bar(22*x,14*y,23*x,19*y);
	//s
	bar(26*x,14*y,29*x,15*y);
	bar(26*x,16*y,29*x,17*y);
	bar(26*x,18*y,29*x,19*y);
	bar(26*x,14*y,27*x,17*y);
	bar(28*x,16*y,29*x,19*y);
/*	while(1)
	{
		if(mousedown())
		{
			exit(-1);
		}
	}
*/
	delay(2000);
	setcolor(BLACK);
	bar(0,0,Rx,Ry);
}

int teamColor(int t)
{
	if(t==0) return 4;//RED
	if(t==1) return 0;//BLACK
	if(t==2) return 2;//GREEN
	if(t==3) return 1;//BLUE
	if(t==4) return 63;//YELLOW
	if(t==5) return 5;//PINK
	if(t==9) return 100;
}

int teamCastle(int t)
{
	if(t==0) return 11;//RED Castle
	else if(t==1) return 25;//BLACK Castle
	else if(t==2) return 12;//GREEN Castle
	else if(t==3) return 24;//BLUE Castle
	else if(t==4) return 13;//YELLOW Castle
	else if(t==5) return 26;//PINK Castle
	else if(t==9) return 23;
	else return 100;
}

int teamVillage(int t)
{
	if(t==0) return 27;//RED Village
	else if(t==1) return 29;//BLACK Village
	else if(t==2) return 30;//GREEN Village
	else if(t==3) return 28;//BLUE Village
	else if(t==4) return 31;//YELLOW Village
	else if(t==5) return 32;//PINK Village
	else if(t==9) return 10;
	else return 100;
}

int whatTeam(int t)
{
	if((t==27)||(t==11)) return 0;//RED
	else if((t==29)||(t==25)) return 1;//BLACK
	else if((t==30)||(t==12)) return 2;//GREEN
	else if((t==28)||(t==24)) return 3;//BLUE
	else if((t==31)||(t==13)) return 4;//YELLOW
	else if((t==32)||(t==26)) return 5;//PINK
	else if((t==10)||(t==23)) return 9;
	else return 10;
}

void wykres(int Rx,int Ry, int r,int tura,int **Punktacja)
{
	tura++;
	
	int s;

	setcolor(BLACK);
	//bar(0,0,Rx*r+3*r+10,Ry*r+12);
	//bar(r,r,Rx*r+2*r,Ry*r-r);
	bar(r-20,r-20,Rx*r+2*r+20,Ry*r-r+20);

	for(int i=1;i<tura;i++)
	{
		for(int k=5;k>=0;k--)
		{	
			s=teamColor(k);
			if(s==0) s=55;
			setcolor(s);
			line(Rx*r*(i-1)/tura+50,Ry*r/2-25-Ry*r*Punktacja[i-1][k]/2000,Rx*r*i/tura+50,Ry*r/2-25-Ry*r*Punktacja[i][k]/2000);
			line(Rx*r*(i-1)/tura+50,Ry*r-50-Ry*r*Punktacja[i-1][6+k]/150,Rx*r*i/tura+50,Ry*r-50-Ry*r*Punktacja[i][6+k]/150);

			/*
			if(Punktacja[i][k]) 
			{
				circle(Rx*r*i/tura+50,Ry*r/2-25-Ry*r*Punktacja[i][k]/1500,2);//Punkty
			}
			if(Punktacja[i][6+k]) 
			{
				circle(Rx*r*i/tura+50,Ry*r-50-Ry*r*Punktacja[i][6+k]/120,2);//Income
			}
			*/
		}
	}

	setcolor(WHITE);
	line(50,50,50,Ry*r/2-25);//'
	line(50,Ry*r/2-25,(Rx+3)*r-50,Ry*r/2-25);//-
	line(50,Ry*r/2+25,50,Ry*r-50);//,
	line(50,Ry*r-50,(Rx+3)*r-50,Ry*r-50);//_

}