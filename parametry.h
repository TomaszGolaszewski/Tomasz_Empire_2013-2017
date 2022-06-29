#include <stdio.h>
#include <math.h>
#include "winbgi2.h"
#include <stdlib.h>
#include <time.h>

//Parametry jednostek i terenu

int unitDystance(int t)
{
	if(t==1) return 5;//King
	if(t==2) return 5;//Knight
	if(t==3) return 5;//Golem
	if(t==4) return 10;//Dragon
	if(t==5) return 9;//Morzak
	if(t==6) return 5;//Archer
	if(t==7) return 4;//Katapulta
	if(t==8) return 8;//Ent
	if(t==9) return 5;//Nekrofil
	if(t==10) return 5;//Zebuszka
	if(t==11) return 5;//Gandalf
	if(t==12) return 5;//¯yd
	if(t==77) return 5;//Boss
	if(t==98) return 5;//Szkielet
	if(t==99) return 7;//Duch
}

int areaDystance(int t, int k)
{
	if(k==4)//Dragon
	{
		if(t==0) return 9;//nothing
		else return 1;
	}
	else if(k==99)//Duch
	{
		return 1;
	}
	else if(k==5)//Morzak
	{
		if(t==0) return 9;//nothing
		if(t==1) return 1;//sea
		if(t==2) return 4;//forest
		if(t==3) return 1;//bridge and path
		if(t==4) return 2;//
		if(t==5) return 2;//
		if(t==6) return 2;//
		if(t==7) return 2;//
		if(t==8) return 2;//
		if(t==9) return 2;//
		if(t==10) return 2;//village
		if(t==11) return 2;//castle
		if(t==12) return 2;//
		if(t==13) return 2;//
		if(t==14) return 2;//land
		if(t==15) return 8;//mountain
		if(t==16) return 1;//bridge and path
		if(t==17) return 2;//
		if(t==18) return 2;//
		if(t==19) return 2;//
		if(t==20) return 2;//
		if(t==21) return 2;//
		if(t==22) return 2;//fortress(x,y,r);
		if(t==23) return 2;//castle
		if(t==24) return 2;//
		if(t==25) return 2;//
		if(t==26) return 2;//
		if(t==27) return 2;//village
		if(t==28) return 2;//
		if(t==29) return 2;//
		if(t==30) return 2;//
		if(t==31) return 2;//
		if(t==32) return 2;//
		if(t==55) return 2;//wall
	}
	else if(k==8)//Ent
	{
		if(t==0) return 9;//nothing
		if(t==1) return 7;//sea
		if(t==2) return 3;//forest
		if(t==3) return 2;//bridge and path
		if(t==4) return 2;//
		if(t==5) return 2;//
		if(t==6) return 2;//
		if(t==7) return 2;//
		if(t==8) return 2;//
		if(t==9) return 2;//
		if(t==10) return 2;//village
		if(t==11) return 2;//castle
		if(t==12) return 2;//
		if(t==13) return 2;//
		if(t==14) return 2;//land
		if(t==15) return 7;//mountain
		if(t==16) return 2;//bridge and path
		if(t==17) return 2;//
		if(t==18) return 2;//
		if(t==19) return 2;//
		if(t==20) return 2;//
		if(t==21) return 2;//
		if(t==22) return 2;//fortress(x,y,r);
		if(t==23) return 2;//castle
		if(t==24) return 2;//
		if(t==25) return 2;//
		if(t==26) return 2;//
		if(t==27) return 2;//village
		if(t==28) return 2;//
		if(t==29) return 2;//
		if(t==30) return 2;//
		if(t==31) return 2;//
		if(t==32) return 2;//
		if(t==55) return 2;//wall
	}
	else
	{
		if(t==0) return 9;//nothing
		if(t==1) return 4;//sea
		if(t==2) return 2;//forest
		if(t==3) return 1;//bridge and path
		if(t==4) return 1;//
		if(t==5) return 1;//
		if(t==6) return 1;//
		if(t==7) return 1;//
		if(t==8) return 1;//
		if(t==9) return 1;//
		if(t==10) return 1;//village
		if(t==11) return 1;//castle
		if(t==12) return 1;//
		if(t==13) return 1;//
		if(t==14) return 1;//land
		if(t==15) return 4;//mountain
		if(t==16) return 1;//bridge and path
		if(t==17) return 1;//
		if(t==18) return 1;//
		if(t==19) return 1;//
		if(t==20) return 1;//
		if(t==21) return 1;//
		if(t==22) return 1;//fortress(x,y,r);
		if(t==23) return 1;//castle
		if(t==24) return 1;//
		if(t==25) return 1;//
		if(t==26) return 1;//
		if(t==27) return 1;//village
		if(t==28) return 1;//
		if(t==29) return 1;//
		if(t==30) return 1;//
		if(t==31) return 1;//
		if(t==32) return 1;//
		if(t==55) return 1;//wall
	}
}

int damage(int a,int k)
{
	switch(a)
	{
	case 1:
		return 55;//king
		break;
	case 2:
		return 50;//knight
		break;
	case 3:
		return 60;//golem
		break;
	case 4:
		if(k==8) return 85;//dragon
		else return 70;
		break;
	case 5:
		return 50;//morzak
		break;
	case 6:
		if(k==4) return 65;//archer
		if(k==98) return 35;
		else return 50;
		break;
	case 7:
		if(k==55) return 65;//katapulta
		else return 50;
		break;
	case 8:
		return 70;//ent
		break;
	case 9:
		return 40;//nekrofil
		break;
	case 10:
		return 35;//zebuszka
		break;
	case 11:
		return 100;//gandalf
		break;
	case 12:
		return 30;//¿yd
		break;
	case 77:
		return 55;//boss
		break;
	case 98:
		return 40;//szkielet
		break;
	case 99:
		return 30;//duch
		break;
	default:
		return 0;
		break;
	}
}

int randomdamage(int a)
{
	int l;
	switch(a)
	{
	case 1:
		l=10;//king
		break;
	case 2:
		l=5;//knight
		break;
	case 3:
		l=10;//golem
		break;
	case 4:
		l=10;//dragon	
		break;
	case 5:
		l=5;//morzak
		break;
	case 6:
		l=5;//archer
		break;
	case 7:
		l=20;//katapulta
		break;
	case 8:
		l=10;//ent
		break;
	case 9:
		l=5;//nekrofil
		break;
	case 10:
		l=5;//zebuszka
		break;
	case 11:
		l=20;//gandalf
		break;
	case 12:
		l=5;//¿yd
		break;
	case 77:
		l=10;//boss
		break;
	case 98:
		l=10;//szkielet
		break;
	case 99:
		l=10;//duch
		break;
	default:
		l=1;
		break;
	}
	return rand()%l;
}

int defence(int a)
{
	switch(a)
	{
	case 1:
		return 20;//king
		break;
	case 2:
		return 5;//knight
		break;
	case 3:
		return 30;//golem
		break;
	case 4:
		return 25;//dragon
		break;
	case 5:
		return 10;//morzak
		break;
	case 6:
		return 5;//archer
		break;
	case 7:
		return 10;//katapulta
		break;
	case 8:
		return 30;//ent
		break;
	case 9:
		return 5;//nekrofil
		break;
	case 10:
		return 10;//zebuszka
		break;
	case 11:
		return 15;//gandalf
		break;
	case 12:
		return 5;//¿yd
		break;
	case 55:
		return 35;//wall
		break;
	case 77:
		return 20;//boss
		break;
	case 98:
		return 2;//szkielet
		break;
	case 99:
		return 30;//duch
		break;
	default:
		return 0;
		break;
	}
}

int areadefence(int a, int k)
{
	switch(a)
	{
	case 0:
		return 0;//nothing
		break;
	case 1:
		if(k==5) return 15;//sea
		else return 0;
		break;
	case 2:
		if(k==8) return 15;//forest
		else return 10;
		break;
	case 3:
		if(k==5) return 15;//bridgelr
		else return 0;
		break;
	case 4:
		return 0;//pathlr
		break;
	case 5:
		return 0;//pathrd
		break;
	case 6:
		return 0;//pathur
		break;
	case 7:
		return 0;//pathrdl
		break;
	case 8:
		return 0;//pathurd
		break;
	case 9:
		return 0;//pathlurd
		break;
	case 10:
		return 15;//village GRAY
		break;
	case 11:
		return 15;//castle RED
		break;
	case 12:
		return 15;//castle GREEN
		break;
	case 13:
		return 15;//castle YELLOW
		break;
	case 14:
		return 5;//land
		break;
	case 15:
		return 15;//mountain
		break;
	case 16:
		if(k==5) return 15;//bridgeud
		else return 0;
		break;
	case 17:
		return 0;//pathud
		break;
	case 18:
		return 0;//pathdl
		break;
	case 19:
		return 0;//pathlu
		break;
	case 20:
		return 0;//pathdlu
		break;
	case 21:
		return 0;//pathlur
		break;
	case 22:
		return 15;//fortress
		break;
	case 23:
		return 15;//castle GRAY
		break;
	case 24:
		return 15;//castle BLUE
		break;
	case 25:
		return 15;//castle BLACK
		break;
	case 26:
		return 15;//castle PINK
		break;
	case 27:
		return 15;//village RED
		break;
	case 28:
		return 15;//village BLUE
		break;
	case 29:
		return 15;//village BLACK
		break;
	case 30:
		return 15;//village GREEN
		break;
	case 31:
		return 15;//village YELLOW
		break;
	case 32:
		return 15;//village PINK
		break;
	case 55:
		return 5;//wall
		break;
	default:
		return 0;
		break;
	}
}

int price(int a)
{
	switch(a)
	{
	case 1:
		return 40;//king
		break;
	case 2:
		return 15;//knight
		break;
	case 3:
		return 60;//golem
		break;
	case 4:
		//return 100;//dragon
		return 90;
		break;
	case 5:
		return 30;//morzak
		break;
	case 6:
		return 25;//archer
		break;
	case 7:
		return 70;//katapulta
		break;
	case 8:
		return 80;//ent
		break;
	case 9:
		return 40;//nekrofil
		break;
	case 10:
		return 50;//zebuszka
		break;
	case 11:
		return 90;//gandalf
		break;
	case 12:
		return 35;//¿yd
		break;
	case 77:
		return 40;//boss
		break;
	case 98:
		return 10;//szkielet
		break;
	case 99:
		return 60;//duch
		break;
	default:
		return 0;
		break;
	}
}