#include <stdio.h>
#include <math.h>
#include "winbgi2.h"
#include <stdlib.h>
#include <time.h>

//Uksztaltowanie terenu

void emptyArea(int x,int y,int r)
{
	setcolor(WHITE);
	line(x*r,y*r,x*r+r,y*r);
	line(x*r,y*r,x*r,y*r+r);
	line(x*r,y*r+r,x*r+r,y*r+r);
	line(x*r+r,y*r,x*r+r,y*r+r);
}

void nothing(int x,int y,int r)
{
	setcolor(BLACK);
	bar(x*r,y*r,x*r+r,y*r+r);
}

void sea(int x,int y,int r)
{
	setcolor(BLUE);
	bar(x*r,y*r,x*r+r,y*r+r);
}

void land(int x,int y,int r)
{
	setcolor(WHITE);
	bar(x*r,y*r,x*r+r,y*r+r);
}

void forest(int x,int y,int r)
{
	setcolor(WHITE);
	bar(x*r,y*r,x*r+r,y*r+r);
	setcolor(30);//BROWN
	bar(x*r+r/5,y*r+3*r/5,x*r+2*r/5,y*r+r-1);
	bar(x*r+3*r/5,y*r+2*r/5,x*r+4*r/5,y*r+4*r/5);
	setcolor(40);//GREEN
	pieslice(x*r+7*r/10,y*r+r/10,235,-55,2*r/5);
	pieslice(x*r+7*r/10,y*r+3*r/10,235,-55,2*r/5);
	setcolor(GREEN);
	pieslice(x*r+3*r/10,y*r+r/5,235,-55,2*r/5);
	pieslice(x*r+3*r/10,y*r+22*r/50,235,-55,2*r/5);
}

void mountain(int x,int y,int r)
{
	setcolor(WHITE);
	bar(x*r,y*r,x*r+r,y*r+r);
	setcolor(55);//GRAY
	pieslice(x*r+r/2,y*r+r/5,235,-55,7*r/10);
	
}

void pathlr(int x,int y,int r)
{
	setcolor(WHITE);
	bar(x*r,y*r,x*r+r,y*r+r);
	setcolor(30);//BROWN
	bar(x*r,y*r+r/5,x*r+r,y*r+r-r/5);
}

void pathud(int x,int y,int r)
{
	setcolor(WHITE);
	bar(x*r,y*r,x*r+r,y*r+r);
	setcolor(30);//BROWN
	bar(x*r+r/5,y*r,x*r+r-r/5,y*r+r);
}

void pathlu(int x,int y,int r)
{
	setcolor(WHITE);
	bar(x*r,y*r,x*r+r,y*r+r);
	setcolor(30);//BROWN
	bar(x*r,y*r+r/5,x*r+r-r/5,y*r+r-r/5);
	bar(x*r+r/5,y*r,x*r+r-r/5,y*r+r-r/5);
}

void pathur(int x,int y,int r)
{
	setcolor(WHITE);
	bar(x*r,y*r,x*r+r,y*r+r);
	setcolor(30);//BROWN
	bar(x*r+r/5,y*r,x*r+r-r/5,y*r+r-r/5);
	bar(x*r+r/5,y*r+r/5,x*r+r,y*r+r-r/5);
}

void pathrd(int x,int y,int r)
{
	setcolor(WHITE);
	bar(x*r,y*r,x*r+r,y*r+r);
	setcolor(30);//BROWN
	bar(x*r+r/5,y*r+r/5,x*r+r,y*r+r-r/5);
	bar(x*r+r/5,y*r+r/5,x*r+r-r/5,y*r+r);
}

void pathdl(int x,int y,int r)
{
	setcolor(WHITE);
	bar(x*r,y*r,x*r+r,y*r+r);
	setcolor(30);//BROWN
	bar(x*r,y*r+r/5,x*r+r-r/5,y*r+r-r/5);	
	bar(x*r+r/5,y*r+r/5,x*r+r-r/5,y*r+r);
}

void pathlur(int x,int y,int r)
{
	setcolor(WHITE);
	bar(x*r,y*r,x*r+r,y*r+r);
	setcolor(30);//BROWN
	bar(x*r,y*r+r/5,x*r+r,y*r+r-r/5);
	bar(x*r+r/5,y*r,x*r+r-r/5,y*r+r-r/5);
}

void pathurd(int x,int y,int r)
{
	setcolor(WHITE);
	bar(x*r,y*r,x*r+r,y*r+r);
	setcolor(30);//BROWN
	bar(x*r+r/5,y*r,x*r+r-r/5,y*r+r);
	bar(x*r+r/5,y*r+r/5,x*r+r,y*r+r-r/5);
}

void pathrdl(int x,int y,int r)
{
	setcolor(WHITE);
	bar(x*r,y*r,x*r+r,y*r+r);
	setcolor(30);//BROWN
	bar(x*r,y*r+r/5,x*r+r,y*r+r-r/5);
	bar(x*r+r/5,y*r+r/5,x*r+r-r/5,y*r+r);
}

void pathdlu(int x,int y,int r)
{
	setcolor(WHITE);
	bar(x*r,y*r,x*r+r,y*r+r);
	setcolor(30);//BROWN
	bar(x*r+r/5,y*r,x*r+r-r/5,y*r+r);	
	bar(x*r,y*r+r/5,x*r+r-r/5,y*r+r-r/5);
}

void pathlurd(int x,int y,int r)
{
	setcolor(WHITE);
	bar(x*r,y*r,x*r+r,y*r+r);
	setcolor(30);//BROWN
	bar(x*r,y*r+r/5,x*r+r,y*r+r-r/5);	
	bar(x*r+r/5,y*r,x*r+r-r/5,y*r+r);
}

void bridgelr(int x,int y,int r)
{
	setcolor(BLUE);
	bar(x*r,y*r,x*r+r,y*r+r);
	setcolor(30);//BROWN
	bar(x*r,y*r+r/5,x*r+r,y*r+r-r/5);
}

void bridgeud(int x,int y,int r)
{
	setcolor(BLUE);
	bar(x*r,y*r,x*r+r,y*r+r);
	setcolor(30);//BROWN
	bar(x*r+r/5,y*r,x*r+r-r/5,y*r+r);
}

//----------------------------------------------------------
//Budynki

void village(int x,int y,int r,int c)
{
	setcolor(WHITE);
	bar(x*r,y*r,x*r+r,y*r+r);
	setcolor(c);
	pieslice(x*r+r/2,y*r+r/5,225,-45,5*r/10);
	setcolor(55);//GRAY
	bar(x*r+r/5,y*r+r/2,x*r+4*r/5,y*r+4*r/5);
}

void fortress(int x,int y,int r)//karczma
{
	setcolor(WHITE);
	bar(x*r,y*r,x*r+r,y*r+r);
	setcolor(30);
	pieslice(x*r+r/2,y*r+r/5,225,-45,5*r/10);
	bar(x*r+r/5,y*r+r/2,x*r+4*r/5,y*r+4*r/5);
/*
	setcolor(WHITE);
	bar(x*r,y*r,x*r+r,y*r+r);
	setcolor(55);//GRAY
	pieslice(x*r+r/2,y*r+r/5,235,-55,7*r/10);
	setcolor(BLACK);
	pieslice(x*r+r/2,y*r+r/2,180,-180,r/10);
*/
}

void castle(int x,int y,int r,int c)
{
	setcolor(WHITE);
	bar(x*r,y*r,x*r+r,y*r+r);
	setcolor(55);//GRAY
	bar(x*r+r/5,y*r+r/2,x*r+4*r/5,y*r+9*r/10);
	bar(x*r+r/10,y*r+3*r/10,x*r+9*r/10,y*r+r/2);
	bar(x*r+r/10,y*r+r/10,x*r+3*r/10,y*r+3*r/10);
	bar(x*r+4*r/10,y*r+r/10,x*r+6*r/10,y*r+3*r/10);
	bar(x*r+7*r/10,y*r+r/10,x*r+9*r/10,y*r+3*r/10);
	setcolor(c);
	bar(x*r+3*r/10,y*r+r/2,x*r+5*r/10,y*r+4*r/5);
	
}


//----------------------------------------------------------
//Jednostki

void golem(int x,int y,int r, int c)
{
	c=teamColor(c);
	int s;
	if(c==100)
	{
		c=LIGHTGRAY;
		s=LIGHTGRAY;
	}
	else
	{
		s=31;
	}
	setcolor(s);
	pieslice(x*r+r/2,y*r+r/2,180,-180,2*r/5);//cialo
	setcolor(c);
	pieslice(x*r+2*r/5+2,y*r+r/2,180,-180,r/5);//oko
	setcolor(BLACK);
	circle(x*r+r/2,y*r+r/2,2*r/5);//cialo
	circle(x*r+2*r/5+2,y*r+r/2,r/5);//oko
	arc(x*r+2*r/5+2,y*r+r/2,190,-30,r/10);//powieka
	setcolor(s);
	pieslice(x*r+r/5,y*r+4*r/5,180,-180,r/10);//|noga
	pieslice(x*r+4*r/5,y*r+4*r/5,180,-180,r/10);//noga|
	setcolor(BLACK);
	circle(x*r+r/5,y*r+4*r/5,r/10);//|noga
	circle(x*r+4*r/5,y*r+4*r/5,r/10);//noga|
	//circle(x*r+2*r/5+1,y*r+r/2,r/10);
}

void knight(int x,int y,int r, int c)
{
	c=teamColor(c);
	int s,h;
	if(c==100)
	{
		c=LIGHTGRAY;
		s=LIGHTGRAY;
		h=LIGHTGRAY;
	}
	else
	{
		s=55;
		h=31;
	}
	setcolor(s);//GRAY
	bar(x*r+2*r/5,y*r+r/2,x*r+3*r/5,y*r+9*r/10);//nogi
	bar(x*r+3*r/10,y*r+2*r/5,x*r+7*r/10,y*r+7*r/10);//rece
	setcolor(BLACK);
	line(x*r+3*r/10,y*r+2*r/5,x*r+3*r/10,y*r+7*r/10);//|reka
	line(x*r+3*r/10,y*r+7*r/10,x*r+2*r/5,y*r+7*r/10);//_reka
	line(x*r+2*r/5,y*r+7*r/10,x*r+2*r/5,y*r+9*r/10);//|noga
	line(x*r+2*r/5,y*r+9*r/10,x*r+3*r/5,y*r+9*r/10);//nogi
	line(x*r+3*r/5,y*r+7*r/10,x*r+3*r/5,y*r+9*r/10);//noga|
	line(x*r+7*r/10,y*r+2*r/5,x*r+7*r/10,y*r+7*r/10);//reka|
	line(x*r+3*r/10,y*r+2*r/5,x*r+7*r/10,y*r+2*r/5);//barki
	setcolor(h);
	pieslice(x*r+r/2,y*r+3*r/10,180,-180,r/6);//glowa
	setcolor(c);
	bar(x*r+5*r/10,y*r+2*r/5+2,x*r+8*r/10,y*r+7*r/10+2);//tarcza
	setcolor(BLACK);
	circle(x*r+r/2,y*r+3*r/10,r/6);//glowa
	line(x*r+5*r/10,y*r+2*r/5+2,x*r+5*r/10,y*r+7*r/10+2);//|tarcza
	line(x*r+8*r/10,y*r+2*r/5+2,x*r+8*r/10,y*r+7*r/10+2);//tarcza|
	line(x*r+5*r/10,y*r+7*r/10+2,x*r+8*r/10,y*r+7*r/10+2);//tarcza_
	line(x*r+5*r/10,y*r+2*r/5+2,x*r+8*r/10,y*r+2*r/5+2);//tarcza-
}

void king(int x,int y,int r, int c)
{
	c=teamColor(c);
	int s;
	if(c==100)
	{
		c=LIGHTGRAY;
		s=LIGHTGRAY;
	}
	else
	{
		s=55;
	}
	setcolor(s);//GRAY
	bar(x*r+2*r/5,y*r+2*r/5,x*r+3*r/5,y*r+9*r/10);//nogi
	bar(x*r+r/2-r/7,y*r+r/6,x*r+r/2+r/7,y*r+r/2);//glowa
	setcolor(BLACK);
	line(x*r+2*r/5,y*r+2*r/5,x*r+2*r/5,y*r+9*r/10);//|nogi
	line(x*r+r/2-r/7,y*r+r/6,x*r+r/2+r/7,y*r+r/6);//glowa-
	line(x*r+3*r/5,y*r+2*r/5,x*r+3*r/5,y*r+9*r/10);//nogi|
	line(x*r+r/2-r/7,y*r+r/6,x*r+r/2-r/7,y*r+r/2);//|glowa
	line(x*r+r/2+r/7,y*r+r/6,x*r+r/2+r/7,y*r+r/2);//glowa|
	line(x*r+2*r/5+1,y*r+r/5+1,x*r+2*r/5+1,y*r+2*r/5-1);//|
	line(x*r+r/2,y*r+r/5+1,x*r+r/2,y*r+2*r/5-1);//||
	line(x*r+3*r/5-1,y*r+r/5+1,x*r+3*r/5-1,y*r+2*r/5-1);//|||
	setcolor(s);
	bar(x*r+3*r/10,y*r+2*r/5,x*r+7*r/10,y*r+7*r/10);//rece
	setcolor(BLACK);
	line(x*r+3*r/10,y*r+2*r/5,x*r+3*r/10,y*r+7*r/10);//|reka
	line(x*r+3*r/10,y*r+7*r/10,x*r+2*r/5,y*r+7*r/10);//_reka
	line(x*r+2*r/5,y*r+9*r/10,x*r+3*r/5,y*r+9*r/10);//nogi_
	line(x*r+7*r/10,y*r+2*r/5,x*r+7*r/10,y*r+7*r/10);//reka|
	line(x*r+3*r/10,y*r+2*r/5,x*r+7*r/10,y*r+2*r/5);//barki
	setcolor(c);
	bar(x*r+5*r/10,y*r+2*r/5+2,x*r+8*r/10,y*r+7*r/10+2);//tarcza
	setcolor(BLACK);
	line(x*r+5*r/10,y*r+2*r/5+2,x*r+5*r/10,y*r+7*r/10+2);//|tarcza
	line(x*r+8*r/10,y*r+2*r/5+2,x*r+8*r/10,y*r+7*r/10+2);//tarcza|
	line(x*r+5*r/10,y*r+7*r/10+2,x*r+8*r/10,y*r+7*r/10+2);//tarcza_
	line(x*r+5*r/10,y*r+2*r/5+2,x*r+8*r/10,y*r+2*r/5+2);//tarcza-
}

void dragon(int x,int y,int r, int c)
{
	c=teamColor(c);
	int s;
	int w;
	if(c==100)
	{
		c=LIGHTGRAY;
		s=LIGHTGRAY;
		w=LIGHTGRAY;
	}
	else
	{
		s=31;
		w=WHITE;
	}
	setcolor(BLACK);
	pieslice(x*r+r/2,y*r+r/2,119,-119,2*r/5);//|skrzydlo
	pieslice(x*r+r/2,y*r+r/2,-61,61,2*r/5);//skrzydlo|
	setcolor(c);
	pieslice(x*r+r/2,y*r+r/2,125,-125,2*r/5);//|skrzydlo
	pieslice(x*r+r/2,y*r+r/2,-55,55,2*r/5);//skrzydlo|
	bar(x*r+2*r/5,y*r+2*r/5,x*r+3*r/5,y*r+4*r/5);//cialo
	setcolor(BLACK);
	line(x*r+2*r/5,y*r+2*r/5,x*r+2*r/5,y*r+4*r/5);//|-
	line(x*r+3*r/5,y*r+r/5,x*r+3*r/5,y*r+4*r/5);//-| i glowa|
	line(x*r+2*r/5,y*r+4*r/5,x*r+3*r/5,y*r+4*r/5);//_
	arc(x*r+r/2,y*r+r/2,119,-119,2*r/5);//|skrzydlo
	arc(x*r+r/2,y*r+r/2,-61,61,2*r/5);//skrzydlo|
	setcolor(s);
	bar(x*r+2*r/5+2,y*r+2*r/5,x*r+3*r/5-2,y*r+4*r/5-2);//brzuch
	setcolor(BLACK);
	line(x*r+2*r/5+2,y*r+2*r/5,x*r+2*r/5+2,y*r+4*r/5-2);//|-
	line(x*r+3*r/5-2,y*r+2*r/5,x*r+3*r/5-2,y*r+4*r/5-2);//-|
	line(x*r+2*r/5+2,y*r+4*r/5-2,x*r+3*r/5-2,y*r+4*r/5-2);//_
	setcolor(c);
	bar(x*r+r/5,y*r+r/5,x*r+3*r/5,y*r+2*r/5);//g這wa
	setcolor(BLACK);
	line(x*r+r/5,y*r+r/5,x*r+r/5,y*r+2*r/5);//|g這wa
	line(x*r+r/5,y*r+r/5,x*r+3*r/5,y*r+r/5);//-g這wa
	line(x*r+r/5,y*r+2*r/5,x*r+3*r/5,y*r+2*r/5);//_g這wa
	line(x*r+r/5,y*r+3*r/10,x*r+r/2,y*r+3*r/10);//usta
	setcolor(w);
	pieslice(x*r+r/2,y*r+r/5,-180,180,r/10);//oko
	setcolor(BLACK);
	circle(x*r+r/2,y*r+r/5,r/10);//oko
	putpixel(x*r+r/2-1,y*r+r/5-1,BLACK);
}

void morzak(int x,int y,int r, int c)
{
	c=teamColor(c);
	int s;
	int w;
	if(c==100)
	{
		c=LIGHTGRAY;
		s=LIGHTGRAY;
		w=LIGHTGRAY;
	}
	else
	{
		s=31;
		w=WHITE;
	}
	setcolor(c);
	bar(x*r+2*r/5,y*r+2*r/5,x*r+3*r/5,y*r+4*r/5);//cialo
	bar(x*r+2*r/5,y*r+3*r/5,x*r+9*r/10,y*r+4*r/5);//ogon
	setcolor(BLACK);
	line(x*r+2*r/5,y*r+2*r/5,x*r+2*r/5,y*r+4*r/5);//|-
	line(x*r+3*r/5,y*r+r/5,x*r+3*r/5,y*r+3*r/5);//-| i glowa|
	line(x*r+2*r/5,y*r+4*r/5,x*r+9*r/10,y*r+4*r/5);//_
	line(x*r+3*r/5,y*r+3*r/5,x*r+9*r/10,y*r+3*r/5);//ogon-
	line(x*r+9*r/10,y*r+3*r/5,x*r+9*r/10,y*r+4*r/5);//ogon|
	setcolor(s);
	bar(x*r+2*r/5+2,y*r+2*r/5,x*r+3*r/5-2,y*r+4*r/5-2);//brzuch
	setcolor(BLACK);
	line(x*r+2*r/5+2,y*r+2*r/5,x*r+2*r/5+2,y*r+4*r/5-2);//|-
	line(x*r+3*r/5-2,y*r+2*r/5,x*r+3*r/5-2,y*r+4*r/5-2);//-|
	line(x*r+2*r/5+2,y*r+4*r/5-2,x*r+3*r/5-2,y*r+4*r/5-2);//_
	setcolor(c);
	bar(x*r+r/5,y*r+r/5,x*r+3*r/5,y*r+2*r/5);//g這wa
	setcolor(BLACK);
	line(x*r+r/5,y*r+r/5,x*r+r/5,y*r+2*r/5);//|g這wa
	line(x*r+r/5,y*r+r/5,x*r+3*r/5,y*r+r/5);//-g這wa
	line(x*r+r/5,y*r+2*r/5,x*r+3*r/5,y*r+2*r/5);//_g這wa
	line(x*r+r/5,y*r+3*r/10,x*r+r/2,y*r+3*r/10);//usta
	setcolor(w);
	pieslice(x*r+r/2,y*r+r/5,-180,180,r/10);//oko
	setcolor(BLACK);
	circle(x*r+r/2,y*r+r/5,r/10);//oko
	putpixel(x*r+r/2-1,y*r+r/5-1,BLACK);
}

void archer(int x,int y,int r, int c)
{
	c=teamColor(c);
	int s,h;
	if(c==100)
	{
		c=LIGHTGRAY;
		s=LIGHTGRAY;
		h=LIGHTGRAY;
	}
	else
	{
		s=55;
		h=31;
	}
	setcolor(s);//GRAY
	bar(x*r+2*r/5,y*r+r/2,x*r+3*r/5,y*r+9*r/10);//nogi
	bar(x*r+2*r/5,y*r+2*r/5,x*r+7*r/10,y*r+7*r/10);//reka|
	bar(x*r+r/10+2,y*r+2*r/5,x*r+7*r/10,y*r+r/2);//|reka
	setcolor(BLACK);
	line(x*r+r/10+2,y*r+r/2,x*r+r/2,y*r+r/2);//_reka
	line(x*r+2*r/5,y*r+9*r/10,x*r+3*r/5,y*r+9*r/10);//nogi
	line(x*r+7*r/10,y*r+2*r/5,x*r+7*r/10,y*r+7*r/10);//reka|
	line(x*r+r/10+2,y*r+2*r/5,x*r+7*r/10,y*r+2*r/5);//barki
	setcolor(c);
	bar(x*r+2*r/5,y*r+2*r/5,x*r+3*r/5,y*r+7*r/10);//herb
	setcolor(h);
	pieslice(x*r+r/2,y*r+3*r/10,180,-180,r/6);//glowa
	setcolor(BLACK);
	circle(x*r+r/2,y*r+3*r/10,r/6);//glowa
	line(x*r+2*r/5,y*r+2*r/5,x*r+2*r/5,y*r+9*r/10);//|noga i herb
	line(x*r+3*r/5,y*r+2*r/5,x*r+3*r/5,y*r+9*r/10);//noga i herb|	
	line(x*r+2*r/5,y*r+7*r/10,x*r+7*r/10,y*r+7*r/10);//rece i herb
	arc(x*r+r/2,y*r+r/2,119,-119,2*r/5);//luk(
	arc(x*r+r/2+1,y*r+r/2,119,-119,2*r/5);//luk((
}

void katapulta(int x,int y,int r, int c)
{
	c=teamColor(c);
	int s,h;
	if(c==100)
	{
		c=LIGHTGRAY;
		s=LIGHTGRAY;
		h=LIGHTGRAY;
	}
	else
	{
		s=30;
		h=55;
	}
	setcolor(h);//GRAY
	pieslice(x*r+4*r/5,y*r+r/2,180,-180,r/5);//kamien
	setcolor(BLACK);
	circle(x*r+4*r/5,y*r+r/2,r/5);//kamien
	line(x*r+2*r/5,y*r+r/5,x*r+4*r/5,y*r+r/2);// /
	line(x*r+2*r/5,y*r+r/5+1,x*r+4*r/5,y*r+r/2+1);// //
	setcolor(s);//BROWN
	bar(x*r+r/5,y*r+r/2,x*r+4*r/5,y*r+7*r/10);//_
	bar(x*r+r/5,y*r+r/5,x*r+2*r/5,y*r+7*r/10);//|
	setcolor(BLACK);
	line(x*r+r/5,y*r+7*r/10,x*r+4*r/5,y*r+7*r/10);//_
	line(x*r+r/5,y*r+r/5,x*r+r/5,y*r+7*r/10);//|-
	line(x*r+2*r/5,y*r+r/2,x*r+4*r/5,y*r+r/2);//-
	line(x*r+2*r/5,y*r+r/5,x*r+2*r/5,y*r+r/2);//-|
	line(x*r+r/5,y*r+r/5,x*r+2*r/5,y*r+r/5);//gora
	line(x*r+4*r/5,y*r+r/2,x*r+4*r/5,y*r+7*r/10);//--|
	setcolor(s);//BROWN
	pieslice(x*r+3*r/10,y*r+7*r/10,180,-180,r/5);//lewe kolo
	pieslice(x*r+7*r/10,y*r+7*r/10,180,-180,r/5);//prawe kolo
	setcolor(c);
	pieslice(x*r+3*r/10,y*r+7*r/10,180,-180,r/10);//lewe kolo
	pieslice(x*r+7*r/10,y*r+7*r/10,180,-180,r/10);//prawe kolo
	setcolor(BLACK);
	circle(x*r+3*r/10,y*r+7*r/10,r/5);//lewe kolo
	circle(x*r+7*r/10,y*r+7*r/10,r/5);//prawe kolo
	circle(x*r+3*r/10,y*r+7*r/10,r/10);//lewe kolo
	circle(x*r+7*r/10,y*r+7*r/10,r/10);//prawe kolo
}

void ent(int x,int y,int r, int c)
{
	c=teamColor(c);
	int s,h,g,w;
	if(c==100)
	{
		c=LIGHTGRAY;
		s=LIGHTGRAY;
		h=LIGHTGRAY;
		g=LIGHTGRAY;
		w=LIGHTGRAY;
	}
	else
	{
		s=40;//DARKGREEN
		g=GREEN;//LIGHTGREEN
		w=WHITE;
		h=30;//BROWN
	}
	setcolor(h);//BROWN
	bar(x*r+2*r/5,y*r+3*r/5,x*r+3*r/5,y*r+9*r/10);
	setcolor(BLACK);
	line(x*r+2*r/5,y*r+9*r/10,x*r+3*r/5,y*r+9*r/10);//_
	line(x*r+2*r/5,y*r+3*r/5,x*r+2*r/5,y*r+9*r/10);//|-
	line(x*r+3*r/5,y*r+3*r/5,x*r+3*r/5,y*r+9*r/10);//-|
	setcolor(c);
	pieslice(x*r+2*r/5,y*r+r/2,180,-180,r/5);
	setcolor(BLACK);
	circle(x*r+2*r/5,y*r+r/2,r/5);
	setcolor(c);
	pieslice(x*r+3*r/5,y*r+3*r/10,180,-180,r/5);
	setcolor(BLACK);
	circle(x*r+3*r/5,y*r+3*r/10,r/5);
	setcolor(s);//GREEN
	pieslice(x*r+2*r/5,y*r+r/5,180,-180,r/5);
	setcolor(s);//GREEN
	pieslice(x*r+3*r/5,y*r+6*r/10,180,-180,r/5);
	setcolor(BLACK);
	circle(x*r+2*r/5,y*r+r/5,r/5);
	circle(x*r+3*r/5,y*r+6*r/10,r/5);
	setcolor(w);
	pieslice(x*r+2*r/5,y*r+3*r/10,-180,180,r/10);//|oko
	pieslice(x*r+3*r/5,y*r+3*r/10,-180,180,r/10);//oko|
	setcolor(BLACK);
	circle(x*r+2*r/5,y*r+3*r/10,r/10);//|oko
	circle(x*r+3*r/5,y*r+3*r/10,r/10);//oko|
	putpixel(x*r+2*r/5-1,y*r+3*r/10,BLACK);
	putpixel(x*r+3*r/5-1,y*r+3*r/10,BLACK);
}

void szkielet(int x,int y,int r, int c)
{
	c=teamColor(c);
	int s;
	if(c==100)
	{
		c=LIGHTGRAY;
		s=LIGHTGRAY;
	}
	else
	{
		s=WHITE;
	}
	setcolor(BLACK);
	line(x*r+r/2,y*r+3*r/10,x*r+r/2,y*r+6*r/10);//kregoslup
	line(x*r+2*r/5,y*r+2*r/5+2,x*r+3*r/5+1,y*r+2*r/5+2);//zebra
	line(x*r+2*r/5,y*r+2*r/5+4,x*r+3*r/5+1,y*r+2*r/5+4);//zebra
	line(x*r+2*r/5,y*r+2*r/5+6,x*r+3*r/5+1,y*r+2*r/5+6);//zebra
	line(x*r+r/2-2,y*r+7*r/10,x*r+r/2-2,y*r+9*r/10+2);//|noga
	line(x*r+r/2+2,y*r+7*r/10,x*r+r/2+2,y*r+9*r/10+2);//noga|

	setcolor(s);//GRAY
	bar(x*r+2*r/5,y*r+3*r/5,x*r+3*r/5,y*r+7*r/10);//miednica
	//bar(x*r+2*r/5,y*r+8*r/10,x*r+3*r/5,y*r+9*r/10);//nogi
	setcolor(BLACK);
	line(x*r+3*r/10,y*r+2*r/5,x*r+3*r/10,y*r+7*r/10);//|reka
	line(x*r+2*r/5,y*r+3*r/5,x*r+3*r/5,y*r+3*r/5);//-miednica
	line(x*r+2*r/5,y*r+7*r/10,x*r+3*r/5,y*r+7*r/10);//_miednica
	line(x*r+3*r/5,y*r+3*r/5,x*r+3*r/5,y*r+7*r/10);//miednica|
	line(x*r+2*r/5,y*r+3*r/5,x*r+2*r/5,y*r+7*r/10);//|miednica
	//line(x*r+2*r/5,y*r+4*r/5,x*r+2*r/5,y*r+9*r/10);//|noga
	//line(x*r+2*r/5,y*r+9*r/10,x*r+3*r/5,y*r+9*r/10);//_nogi
	//line(x*r+2*r/5,y*r+4*r/5,x*r+3*r/5,y*r+4*r/5);//-nogi
	//line(x*r+3*r/5,y*r+4*r/5,x*r+3*r/5,y*r+9*r/10);//noga|
	line(x*r+7*r/10-1,y*r+2*r/5,x*r+7*r/10-1,y*r+7*r/10);//reka|
	line(x*r+3*r/10,y*r+2*r/5,x*r+7*r/10-1,y*r+2*r/5);//barki
	setcolor(s);
	pieslice(x*r+r/2,y*r+3*r/10,180,-180,r/6);//glowa

	setcolor(c);
	bar(x*r+5*r/10,y*r+2*r/5+2,x*r+8*r/10,y*r+7*r/10+2);//tarcza
	setcolor(BLACK);
	circle(x*r+r/2,y*r+3*r/10,r/6);//glowa
	line(x*r+5*r/10,y*r+2*r/5+2,x*r+5*r/10,y*r+7*r/10+2);//|tarcza
	line(x*r+8*r/10,y*r+2*r/5+2,x*r+8*r/10,y*r+7*r/10+2);//tarcza|
	line(x*r+5*r/10,y*r+7*r/10+2,x*r+8*r/10,y*r+7*r/10+2);//tarcza_
	line(x*r+5*r/10,y*r+2*r/5+2,x*r+8*r/10,y*r+2*r/5+2);//tarcza-
}

void duch(int x,int y,int r, int c)
{
	c=teamColor(c);
	int s,h;
	if(c==100)
	{
		c=LIGHTGRAY;
		s=LIGHTGRAY;
	}
	else
	{
		s=WHITE;
	}
	setcolor(c);
	pieslice(x*r+8*r/10,y*r+8*r/10,180,-180,r/7);
	setcolor(BLACK);
	circle(x*r+8*r/10,y*r+8*r/10,r/7);
	setcolor(s);
	bar(x*r+3*r/10,y*r+r/2,x*r+7*r/10,y*r+r/2+2*r/5);
	pieslice(x*r+r/2,y*r+r/2,0,180,r/5);
	setcolor(BLACK);
	line(x*r+3*r/10,y*r+r/2-1,x*r+3*r/10,y*r+r/2+2*r/5);
	line(x*r+7*r/10-1,y*r+r/2,x*r+7*r/10-1,y*r+r/2+2*r/5);
	line(x*r+3*r/10,y*r+r/2+2*r/5,x*r+7*r/10,y*r+r/2+2*r/5);
	arc(x*r+r/2,y*r+r/2,0,180,r/5);
	circle(x*r+2*r/5,y*r+r/2,r/10);//|oko
	circle(x*r+3*r/5,y*r+r/2,r/10);//oko|
	putpixel(x*r+2*r/5-1,y*r+r/2,BLACK);
	putpixel(x*r+3*r/5-1,y*r+r/2,BLACK);
}

void zebuszka(int x,int y,int r, int c)
{
	c=teamColor(c);
	int s,h;
	if(c==100)
	{
		c=LIGHTGRAY;
		s=LIGHTGRAY;
		h=LIGHTGRAY;
	}
	else
	{
		s=40;//GREEN;//40?
		h=31;
	}
	setcolor(BLACK);
	pieslice(x*r+r/2,y*r+r/5,250,-70,7*r/10);
	line(x*r+r/5,y*r+r/5,x*r+r/5,y*r+4*r/5);
	line(x*r+r/5-1,y*r+r/5,x*r+r/5-1,y*r+4*r/5);
	setcolor(s);//GREEN
	pieslice(x*r+r/2,y*r+r/5,253,-73,7*r/10);
	bar(x*r+r/10+2,y*r+2*r/5,x*r+r/2,y*r+r/2);//|reka	
	setcolor(c);
	pieslice(x*r+r/5,y*r+r/5,180,-180,r/10);//krysztal
	setcolor(BLACK);
	circle(x*r+r/5,y*r+r/5,r/10);//krysztal
	arc(x*r+r/2,y*r+r/5,250,-70,7*r/10);
	line(x*r+r/10+2,y*r+2*r/5,x*r+r/2,y*r+2*r/5);//barki
	line(x*r+r/10+2,y*r+r/2,x*r+2*r/5,y*r+r/2);//_reka
	line(x*r+r/10+2,y*r+2*r/5,x*r+r/10+2,y*r+r/2);//|reka	
	setcolor(h);
	pieslice(x*r+r/2,y*r+3*r/10,180,-180,r/6);//glowa
	setcolor(BLACK);
	circle(x*r+r/2,y*r+3*r/10,r/6);//glowa
}

void nekrofil(int x,int y,int r, int c)
{
	c=teamColor(c);
	int s,h;
	if(c==100)
	{
		c=LIGHTGRAY;
		s=LIGHTGRAY;
		h=LIGHTGRAY;
	}
	else
	{
		s=55;//GRAY
		h=31;
	}
	setcolor(BLACK);
	pieslice(x*r+r/2,y*r+r/5,250,-70,7*r/10);
	line(x*r+r/5,y*r+r/5,x*r+r/5,y*r+4*r/5);
	line(x*r+r/5-1,y*r+r/5,x*r+r/5-1,y*r+4*r/5);
	setcolor(s);//GREEN
	pieslice(x*r+r/2,y*r+r/5,253,-73,7*r/10);
	bar(x*r+r/10+2,y*r+2*r/5,x*r+r/2,y*r+r/2);//|reka	
	setcolor(c);
	pieslice(x*r+r/5,y*r+r/5,180,-180,r/10);//krysztal
	setcolor(BLACK);
	circle(x*r+r/5,y*r+r/5,r/10);//krysztal
	arc(x*r+r/2,y*r+r/5,250,-70,7*r/10);
	line(x*r+r/10+2,y*r+2*r/5,x*r+r/2,y*r+2*r/5);//barki
	line(x*r+r/10+2,y*r+r/2,x*r+2*r/5,y*r+r/2);//_reka
	line(x*r+r/10+2,y*r+2*r/5,x*r+r/10+2,y*r+r/2);//|reka	
	setcolor(h);
	pieslice(x*r+r/2,y*r+3*r/10,180,-180,r/6);//glowa
	setcolor(BLACK);
	circle(x*r+r/2,y*r+3*r/10,r/6);//glowa
}

void gandalf(int x,int y,int r, int c)
{
	c=teamColor(c);
	int s,h;
	if(c==100)
	{
		c=LIGHTGRAY;
		s=LIGHTGRAY;
		h=LIGHTGRAY;
	}
	else
	{
		s=WHITE;
		h=31;
	}
	setcolor(BLACK);
	pieslice(x*r+r/2,y*r+r/5,250,-70,7*r/10);
	line(x*r+r/5,y*r+r/5,x*r+r/5,y*r+4*r/5);
	line(x*r+r/5-1,y*r+r/5,x*r+r/5-1,y*r+4*r/5);
	setcolor(s);//GREEN
	pieslice(x*r+r/2,y*r+r/5,253,-73,7*r/10);
	bar(x*r+r/10+2,y*r+2*r/5,x*r+r/2,y*r+r/2);//|reka	
	setcolor(c);
	pieslice(x*r+r/5,y*r+r/5,180,-180,r/10);//krysztal
	setcolor(BLACK);
	circle(x*r+r/5,y*r+r/5,r/10);//krysztal
	arc(x*r+r/2,y*r+r/5,250,-70,7*r/10);
	line(x*r+r/10+2,y*r+2*r/5,x*r+r/2,y*r+2*r/5);//barki
	line(x*r+r/10+2,y*r+r/2,x*r+2*r/5,y*r+r/2);//_reka
	line(x*r+r/10+2,y*r+2*r/5,x*r+r/10+2,y*r+r/2);//|reka	
	setcolor(h);
	pieslice(x*r+r/2,y*r+3*r/10,180,-180,r/6);//glowa
	setcolor(BLACK);
	circle(x*r+r/2,y*r+3*r/10,r/6);//glowa
}

void boss(int x,int y,int r, int c)
{
	c=teamColor(c);
	int s;
	if(c==100)
	{
		c=LIGHTGRAY;
		s=LIGHTGRAY;
	}
	else
	{
		s=63;//GOLD
	}
	setcolor(s);//GRAY
	bar(x*r+2*r/5,y*r+2*r/5,x*r+3*r/5,y*r+9*r/10);//nogi
	bar(x*r+r/2-r/7,y*r+r/6,x*r+r/2+r/7,y*r+r/2);//glowa
	setcolor(BLACK);
	//line(x*r+2*r/5,y*r+2*r/5,x*r+2*r/5,y*r+9*r/10);//|nogi
	line(x*r+r/2-r/7,y*r+r/6,x*r+r/2+r/7,y*r+r/6);//glowa-
	//line(x*r+3*r/5,y*r+2*r/5,x*r+3*r/5,y*r+9*r/10);//nogi|
	line(x*r+r/2-r/7,y*r+r/6,x*r+r/2-r/7,y*r+r/2);//|glowa
	line(x*r+r/2+r/7,y*r+r/6,x*r+r/2+r/7,y*r+r/2);//glowa|
	line(x*r+2*r/5+1,y*r+r/5+1,x*r+2*r/5+1,y*r+2*r/5-1);//|
	line(x*r+r/2,y*r+r/5+1,x*r+r/2,y*r+2*r/5-1);//||
	line(x*r+3*r/5-1,y*r+r/5+1,x*r+3*r/5-1,y*r+2*r/5-1);//|||
	setcolor(s);
	bar(x*r+3*r/10,y*r+2*r/5,x*r+7*r/10,y*r+7*r/10);//rece
	setcolor(c);
	bar(x*r+2*r/5,y*r+2*r/5,x*r+3*r/5,y*r+7*r/10);//herb
	setcolor(BLACK);
	line(x*r+3*r/10,y*r+2*r/5,x*r+3*r/10,y*r+7*r/10);//|reka
	//line(x*r+3*r/10,y*r+7*r/10,x*r+2*r/5,y*r+7*r/10);//_reka
	line(x*r+3*r/10,y*r+7*r/10,x*r+7*r/10,y*r+7*r/10);//rece i herb
	line(x*r+2*r/5,y*r+9*r/10,x*r+3*r/5,y*r+9*r/10);//nogi_
	line(x*r+7*r/10,y*r+2*r/5,x*r+7*r/10,y*r+7*r/10);//reka|
	line(x*r+3*r/10,y*r+2*r/5,x*r+7*r/10,y*r+2*r/5);//barki
	line(x*r+2*r/5,y*r+2*r/5,x*r+2*r/5,y*r+9*r/10);//|noga i herb
	line(x*r+3*r/5,y*r+2*r/5,x*r+3*r/5,y*r+9*r/10);//noga i herb|	
	setcolor(c);
	bar(x*r+5*r/10,y*r+2*r/5+2,x*r+8*r/10,y*r+7*r/10+2);//tarcza
	setcolor(BLACK);
	line(x*r+5*r/10,y*r+2*r/5+2,x*r+5*r/10,y*r+7*r/10+2);//|tarcza
	line(x*r+8*r/10,y*r+2*r/5+2,x*r+8*r/10,y*r+7*r/10+2);//tarcza|
	line(x*r+5*r/10,y*r+7*r/10+2,x*r+8*r/10,y*r+7*r/10+2);//tarcza_
	line(x*r+5*r/10,y*r+2*r/5+2,x*r+8*r/10,y*r+2*r/5+2);//tarcza-
}
void zyd(int x,int y,int r, int c)
{
	c=teamColor(c);
	int s,h,m;
	if(c==100)
	{
		c=LIGHTGRAY;
		s=LIGHTGRAY;
		h=LIGHTGRAY;
		m=LIGHTGRAY;
	}
	else
	{
		s=55;
		h=31;
		m=63;//GOLD
	}
	setcolor(c);
	bar(x*r+5*r/10,y*r+3*r/5+2,x*r+9*r/10,y*r+9*r/10);//skrzynka
	setcolor(BLACK);
	line(x*r+5*r/10,y*r+3*r/5+2,x*r+9*r/10,y*r+3*r/5+2);//-skrzynka
	line(x*r+5*r/10,y*r+3*r/5+5,x*r+9*r/10,y*r+3*r/5+5);//szczelina
	line(x*r+9*r/10,y*r+3*r/5+2,x*r+9*r/10,y*r+9*r/10);//skrzynka|
	setcolor(s);//GRAY
	bar(x*r+2*r/5,y*r+r/2,x*r+3*r/5,y*r+9*r/10);//nogi
	bar(x*r+3*r/10,y*r+2*r/5,x*r+7*r/10,y*r+7*r/10);//rece
	setcolor(BLACK);
	line(x*r+3*r/10,y*r+2*r/5,x*r+3*r/10,y*r+7*r/10);//|reka
	//line(x*r+3*r/10,y*r+7*r/10,x*r+2*r/5,y*r+7*r/10);//_reka
	line(x*r+3*r/5,y*r+7*r/10,x*r+7*r/10,y*r+7*r/10);//reka_
	line(x*r+2*r/5,y*r+7*r/10,x*r+2*r/5,y*r+9*r/10);//|noga
	line(x*r+2*r/5,y*r+9*r/10,x*r+9*r/10,y*r+9*r/10);//nogi i skrzynka
	line(x*r+3*r/5,y*r+7*r/10,x*r+3*r/5,y*r+9*r/10);//noga|
	line(x*r+7*r/10,y*r+2*r/5,x*r+7*r/10,y*r+7*r/10);//reka|
	line(x*r+3*r/10,y*r+2*r/5,x*r+7*r/10,y*r+2*r/5);//barki
	setcolor(h);
	pieslice(x*r+r/2,y*r+3*r/10,180,-180,r/6);//glowa
	setcolor(m);
	pieslice(x*r+3*r/10+1,y*r+7*r/10,180,-180,r/10);//monetka
	setcolor(BLACK);
	circle(x*r+3*r/10+1,y*r+7*r/10,r/10);//monetka
	circle(x*r+r/2,y*r+3*r/10,r/6);//glowa
	line(x*r+r/3+1,y*r+3*r/10-1,x*r+r/3+1,y*r+r/2);//|pejs
	line(x*r+r/3,y*r+3*r/10-1,x*r+r/3,y*r+r/2);//| pejs
	line(x*r+2*r/3-1,y*r+3*r/10-1,x*r+2*r/3-1,y*r+r/2);//pejs |
	line(x*r+2*r/3-2,y*r+3*r/10-2,x*r+2*r/3-2,y*r+r/2);//pejs|
	pieslice(x*r+r/2,y*r+2*r/10,0,180,r/10);//jarmu趾a
}

void wall(int x,int y,int r,int c)
{
	setcolor(55);//GRAY
	bar(x*r+r/10,y*r+6*r/10,x*r+9*r/10,y*r+9*r/10);
	bar(x*r+r/10,y*r+4*r/10,x*r+3*r/10,y*r+6*r/10);
	bar(x*r+4*r/10,y*r+4*r/10,x*r+6*r/10,y*r+6*r/10);
	bar(x*r+7*r/10,y*r+4*r/10,x*r+9*r/10,y*r+6*r/10);
	setcolor(BLACK);
	line(x*r+r/10,y*r+9*r/10,x*r+9*r/10,y*r+9*r/10);
	line(x*r+r/10,y*r+4*r/10,x*r+r/10,y*r+9*r/10);
	line(x*r+9*r/10,y*r+4*r/10,x*r+9*r/10,y*r+9*r/10);
	line(x*r+r/10,y*r+4*r/10,x*r+3*r/10,y*r+4*r/10);
	line(x*r+4*r/10,y*r+4*r/10,x*r+6*r/10,y*r+4*r/10);
	line(x*r+7*r/10,y*r+4*r/10,x*r+9*r/10,y*r+4*r/10);
	line(x*r+3*r/10,y*r+4*r/10,x*r+3*r/10,y*r+6*r/10);
	line(x*r+4*r/10,y*r+4*r/10,x*r+4*r/10,y*r+6*r/10);
	line(x*r+6*r/10,y*r+4*r/10,x*r+6*r/10,y*r+6*r/10);
	line(x*r+7*r/10,y*r+4*r/10,x*r+7*r/10,y*r+6*r/10);
	line(x*r+9*r/10,y*r+4*r/10,x*r+9*r/10,y*r+6*r/10);
	line(x*r+3*r/10,y*r+6*r/10,x*r+4*r/10,y*r+6*r/10);
	line(x*r+6*r/10,y*r+6*r/10,x*r+7*r/10,y*r+6*r/10);
}