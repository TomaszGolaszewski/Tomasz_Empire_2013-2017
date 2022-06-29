//	TOMASZ EMPIRE 
//	0.8.3
//	TomaszGames studio
//	by Tomasz Golaszewski 
//	2013-2017

//--------------------------------------------------------

#include <stdio.h>
#include <math.h>
#include "winbgi2.h"
#include <stdlib.h>
#include <time.h>

//--------------------------------------------------------

#include "inne_I.h"
#include "teren_i_postacie.h"
#include "parametry.h"
#include "inne_II.h"
#include "AI_1.h"
#include "AI_2.h"
#include "AI_3.h"
#include "AI_4.h"
#include "test.h"

//#######################################################################################################################
//Funkcja glowna

void main()
{
	srand(time(NULL));

	int r=50;
	int Rx=10;
	int Ry=10;
	int mapa=3;
	int sciezka=1;

	FILE *P;

	printf("\"TOMASZ EMPIRE\"\n0.8.3\nTomaszGames studio\nby Tomasz Golaszewski\n2013-2017\n\n\nNr - Nazwa [Maksymalna liczba graczy]\n0 - Mapa testowa [2]\n1 - Male wyspy [4]\n2 - Wyspy [4]\n3 - Szybka gra [2]\n4 - Szybka gra++ [2]\n5 - Szybka gra++++ (#) [4]\n6 - 1 vs 1 vs 1 [3]\n7 - Helmowy Jar 1 vs 2 [3]\n8 - Helmowy Jar+ [2]\n9 - Tomaszland [6]\n10 - Europa [6]\n\nPodaj numer mapy: ");
	scanf("%d",&mapa);//------------------------------------------------------------
	if(mapa==0)
	{
		P=fopen("Mapy/MapaTestowa.txt","r");
	}
	else if(mapa==1)
	{
		P=fopen("Mapy/Mapa6a.txt","r");
	}
	else if(mapa==2)
	{
		P=fopen("Mapy/Mapa1.txt","r");
	}
	else if(mapa==3)
	{
		P=fopen("Mapy/Mapa2.txt","r");
	}
	else if(mapa==4)
	{
		P=fopen("Mapy/Mapa3.txt","r");
	}
	else if(mapa==5)
	{
		P=fopen("Mapy/Mapa4.txt","r");
	}
	else if(mapa==6)
	{
		P=fopen("Mapy/Mapa5.txt","r");
	}
	else if(mapa==7)
	{
		P=fopen("Mapy/MapaHJ.txt","r");
	}
	else if(mapa==8)
	{
		P=fopen("Mapy/MapaHJ2.txt","r");
	}	
	else if(mapa==9)
	{
		P=fopen("Mapy/MapaK1.txt","r");
	}
	else if(mapa==10)
	{
		P=fopen("Mapy/MapaK2.txt","r");
	}
	else
	{
		exit(-1);
	}

	if(P==NULL)
	{
		printf("\nBlad otwarcia pliku\n");
		exit(-1);
	}
	fscanf(P,"%d\t%d\t%d\n",&Rx,&Ry,&r);

	int kasanastart=200;
	int liczbadostepnychjednostek=12;
	int umax=1000;
	int tmax=1000;

	int tura=0;
	int krok=0;
	
	int x=0;
	int y=0;
	int u=1;
	int lx=0;
	int ly=0;
	int lu=0;

	int m=0;
	int b=1;

	int ua;
	int dhp;
	int los;
	int deadteam;
	int team2;
	int lteam=0;
	int zwyciezca;

	int Team[6]={0,0,0,0,0,0};
	int Kasa[6];
	int Punkty[6]={0,0,0,0,0,0};
	int Income[6]={0,0,0,0,0,0};
	int Boot[6]={1,3,3,0,3,3};

	int **A;//Teren
	int **U;//Numer jednostki
	int **Ru;//Przebyta droga
	int **At;//Pola do ataku
	int **Zr;//Zdrowienie i resp
	int **Rip;//Rip

	int **Punktacja;//Historia gry

	int *T;//Team jednostki
	int *K;//Rodzaj jednostki
	int *UA;//Aktywnosc jednostki
	int *HP;//Zycie jednostki

	A=(int**)malloc(Rx*sizeof(int*));
	for(int i=0;i<Rx;++i)
		A[i]=(int*)malloc(Ry*sizeof(int));

	U=(int**)malloc(Rx*sizeof(int*));
	for(int i=0;i<Rx;++i)
		U[i]=(int*)malloc(Ry*sizeof(int));

	Ru=(int**)malloc(Rx*sizeof(int*));
	for(int i=0;i<Rx;++i)
		Ru[i]=(int*)malloc(Ry*sizeof(int));

	At=(int**)malloc(Rx*sizeof(int*));
	for(int i=0;i<Rx;++i)
		At[i]=(int*)malloc(Ry*sizeof(int));

	Zr=(int**)malloc(Rx*sizeof(int*));
	for(int i=0;i<Rx;++i)
		Zr[i]=(int*)malloc(Ry*sizeof(int));

	Rip=(int**)malloc(Rx*sizeof(int*));
	for(int i=0;i<Rx;++i)
		Rip[i]=(int*)malloc(Ry*sizeof(int));

	Punktacja=(int**)malloc(tmax*sizeof(int*));
	for(int i=0;i<tmax;++i)
		Punktacja[i]=(int*)malloc(12*sizeof(int));

	T=(int*)malloc(umax*sizeof(int));

	K=(int*)malloc(umax*sizeof(int));

	UA=(int*)malloc(umax*sizeof(int));

	HP=(int*)malloc(umax*sizeof(int));

	for(int i=0;i<umax;++i)
	{
		UA[i]=1;
		HP[i]=100;
	}

	for(int k=0;k<tmax;k++)
	{
		for(int j=0;j<12;j++)
		{
			Punktacja[k][j]=0;
		}
	}

	for(int i=0;i<6;++i)
	{
		Kasa[i]=kasanastart;
	}

	K[0]=0;
	T[0]=10;
	HP[0]=0;

	graphics(Rx*r+3*r+10,Ry*r+12);
	//graphics(Rx*r+3*r+10,((Ry*r>(liczbadostepnychjednostek+2)*r)?(Ry*r):((liczbadostepnychjednostek+2)*r))+12);
	TomaszGames(Rx*r+3*r+10,Ry*r+12);//-----------------------------------------------------

	for(int i=0;i<Ry;++i)
	{
		for(int k=0;k<Rx;++k)
		{			
			U[k][i]=0;
			Ru[k][i]=0;
			At[k][i]=0;
			Zr[k][i]=0;
			fscanf(P,"%d",&A[k][i]);
			area(k,i,r,A[k][i]);
			if((whatTeam(A[k][i])!=9)&&(whatTeam(A[k][i])!=10))
			{
				U[k][i]=u;
				T[U[k][i]]=whatTeam(A[k][i]);
				K[U[k][i]]=77;
				//unit(k,i,r,1,whatTeam(A[k][i]),HP[u]);
				u++;
				Team[whatTeam(A[k][i])]=1;
			}
			if(A[k][i]==55)
			{
				U[k][i]=u;
				T[U[k][i]]=9;
				K[U[k][i]]=55;
				//unit(k,i,r,55,9,HP[u]);
				u++;			
			}
			Rip[k][i]=0;
		}
	}
	fclose(P);
	
//--------------------------------------------------------	

//Aktywacja graczy i wybór botów
/**/
	setcolor(BLACK);
	//bar(2*r,2*r,12*r,12*r);
	bar(1*r,1*r,13*r,13*r);
	setcolor(WHITE);
	bar(3*r,3*r,11*r,11*r);
	for(int i=0;i<6;i++)
	{
		if(Team[i]) ua=i;
		else ua=9;

		rip(4,4+i,r,ua);
		boss(5,4+i,r,ua);
		szkielet(6,4+i,r,ua);
		knight(7,4+i,r,ua);
		king(8,4+i,r,ua);
		archer(9,4+i,r,ua);

		if(Team[i]) frame(Boot[i]+5,4+i,r,4);
		else frame(4,4+i,r,4);
	}
	while(1)
	{
		if(mousedown()) 
		{	
			x=mousecurrentx()/r;
			y=mousecurrenty()/r;

			if(x>3 && x<10 && y<10 && y>3 && Team[y-4])
			{
				setcolor(WHITE);
				bar(4*r,y*r,10*r,(y+1)*r);
				rip(4,y,r,y-4);
				boss(5,y,r,y-4);
				szkielet(6,y,r,y-4);
				knight(7,y,r,y-4);
				king(8,y,r,y-4);
				archer(9,y,r,y-4);
				frame(x,y,r,4);
				Boot[y-4]=x-5;		
			}
			else if(x<3 || x>10 || y>10 || y<3)
			{
				break;
			}
		}
	}

	for(int i=0;i<6;i++)
	{
		if(Boot[i]==-1) 
		{
			Team[i]=0;
			for(int k=0;k<Rx;k++)
			{
				for(int j=0;j<Ry;j++)
				{
					if(T[U[k][j]]==i) U[k][j]=0;
				}
			}
		}
		if(Team[i]) lteam++;
	}
	if(lteam==0)
	{
		exit(-1);
	}



//--------------------------------------------------------	

	jednostkiTestowe(u,r,U,T,K,HP);


	
	setcolor(WHITE);
	bar(Rx*r+r-2,0,Rx*r+3*r+2,2*r+2);
	bar(Rx*r+2*r-2,Ry*r-r-2,Rx*r+3*r+2,Ry*r+2);
	setcolor(BLACK);
	//bar(2*r,2*r,10*r,12*r);
	bar(1*r,1*r,13*r,13*r);
	bar(Rx*r+2*r,Ry*r-r,Rx*r+3*r,Ry*r);
	rip(Rx+2,Ry-1,r,9);

//--------------------------------------------------------	

	while(1)
	{
//Nowa tura
		tura++;
		team2=0;

		for(int team=0;team<6;team++)
		{
			if(!Team[team])
			{
				continue;
			}

			team2++;
			krok++;

			setcolor(teamColor(team));
			bar(Rx*r+r,0,Rx*r+3*r,2*r);
			setcolor(BLACK);
			bar(Rx*r,3*r,Rx*r+3*r,6*r);
			rip(Rx+2,Ry-1,r,team);

			m=0;
			b=1;

			for(int i=0;i<umax;++i)
			{
				UA[i]=1;
			}
			
			for(int i=0;i<Ry;++i)
			{
				for(int k=0;k<Rx;++k)
				{
					At[k][i]=0;
					Ru[k][i]=0;
					Zr[k][i]=0;
				}
			}

			for(int i=0;i<Ry;++i)
			{
				for(int k=0;k<Rx;++k)
				{
					area(k,i,r,A[k][i]);
					ifrip(k,i,r,Rip[k][i],T[Rip[k][i]]);

					if(U[k][i])
					{
//Leczenie
//Domki
						if((whatTeam(A[k][i])==team)&&(T[U[k][i]]==team))
						{
							HP[U[k][i]]=HP[U[k][i]]+20;
							if(HP[U[k][i]]>100) HP[U[k][i]]=100;
						}
//Ent
						if((T[U[k][i]]==team)&&(K[U[k][i]]==8))
						{
							HP[U[k][i]]=HP[U[k][i]]+10;
							if(HP[U[k][i]]>100) HP[U[k][i]]=100;
						}
//Karczma/Fortress
						if((T[U[k][i]]==team)&&(A[k][i]==22))
						{
							HP[U[k][i]]=HP[U[k][i]]+20;
							if(HP[U[k][i]]>100) HP[U[k][i]]=100;
						}

						unit(k,i,r,K[U[k][i]],T[U[k][i]],HP[U[k][i]]);
					}
//Income
					if(A[k][i]==teamCastle(team)) Kasa[team]=Kasa[team]+5;
					if(A[k][i]==teamVillage(team)) Kasa[team]=Kasa[team]+3;
					if((K[U[k][i]]==12)&&(T[U[k][i]]==team)) Kasa[team]=Kasa[team]+5;

				}
			}

			monetki(Rx,Ry,r,Kasa[team]);

//Punkty
			printf("\n\nNowa tura: %d.%d\t[",tura,team2);
			NazwaTeamu3(team);
			printf("]");
			for(int i=0;i<Ry;++i)
			{
				for(int k=0;k<Rx;++k)
				{
					for(int t=0;t<6;t++)
					{
						if(A[k][i]==teamCastle(t)) Income[t]=Income[t]+5;
						if(A[k][i]==teamVillage(t)) Income[t]=Income[t]+3;
						if((K[U[k][i]]==12)&&(T[U[k][i]]==t)) Income[t]=Income[t]+5;
						if(T[U[k][i]]==t) Punkty[t]=Punkty[t]+HP[U[k][i]]*price(K[U[k][i]])/100;
					}
				}
			}
			for(int i=0;i<6;i++)
			{
				if(Team[i])
				{
					Punkty[i]=Punkty[i]+Kasa[i]+Income[i];
					Punktacja[krok][i]=Punkty[i];
					Punktacja[krok][6+i]=Income[i];
					printf("\n");
					printf("[%d] ",Boot[i]);
					if(i==team) NazwaTeamu2(i);
					else NazwaTeamu(i);
					printf("\t%d\t%d",Punkty[i],Income[i]);//------------------------------------------------------------------------------------
					Punkty[i]=0;
					Income[i]=0;
				}
			}

//Sprawdzenie ilu graczy zostalo
			lteam=0;
			for(int i=0;i<6;i++)
			{
				if(Team[i]) 
				{
					lteam++;
					zwyciezca=i;
				}
			}
			if(lteam==0)
			{
				exit(-1);
			}
			if(lteam==1)
			{
				delay(1000);
				setcolor(teamColor(zwyciezca));
				bar(0,0,Rx*r+3*r+10,Ry*r+12);
				delay(1000);
				wykres(Rx,Ry,r,krok,Punktacja);
				//delay(60000);
				while(1)
				{
					if(mousedown())
					{
						exit(-1);
					}
				}
				//exit(-1);
			}

			printf("\n\nUderzenie:\tOdhit:");



/*
	for(int i=0;i<64;i++)
	{
		setcolor(i);
		bar(i*15,400,i*15+15,600);
	}
*/


//[AI]Sztuczna inteligencja
			if(Boot[team]==1)
			{	
//[AI]Sztuczna inteligencja AI_1 
// - kmiotki kieruja sie na domki
// - rycerze kieruja sie na domki i zamki
// - krol sie nie porusza
				AI_1(u,Rx,Ry,r,U,A,Rip,Ru,At,K,T,HP,UA,Kasa,Team,team,sciezka);
			}

			else if(Boot[team]==2)
			{
//[AI]Sztuczna inteligencja AI_2 
// - kmiotki kieruja sie na domki i krola (o ile maj¹ wiêcej ni¿ 60HP)
// - rycerze kieruja sie na domki, zamki i krola (o ile maj¹ wiêcej ni¿ 40HP)
// - krol sie nie porusza
				AI_2(u,Rx,Ry,r,U,A,Rip,Ru,At,K,T,HP,UA,Kasa,Team,team,sciezka);
			}

			else if(Boot[team]==3)
			{
//[AI]Sztuczna inteligencja AI_3
// - kmiotki kieruja sie na domki i krola (o ile maj¹ wiêcej ni¿ 60HP)
// - rycerze kieruja sie na domki, zamki i krola (o ile maj¹ wiêcej ni¿ 40HP)
// - krol sie nie porusza
// - jednostka po zajeciu nieruchomosci pozostaje na niej
				AI_3(u,Rx,Ry,r,U,A,Rip,Ru,At,K,T,HP,UA,Kasa,Team,team,sciezka);
			}

			else if(Boot[team]==4)
			{
//[AI]Sztuczna inteligencja AI_4
// - kmiotki kieruja sie na domki i krola (o ile maj¹ wiêcej ni¿ 60HP)
// - rycerze kieruja sie na domki, zamki i krola (o ile maj¹ wiêcej ni¿ 40HP)
// - ³ucznicy kieruj¹ siê na jednostki przeciwnika
// - krol sie nie porusza
// - jednostka po zajeciu nieruchomosci pozostaje na niej
// - jednostka ma priorytet uderzenia krola lub jednostki znajduj¹cej siê dalej od siebie
				AI_4(u,Rx,Ry,r,U,A,Rip,Ru,At,K,T,HP,UA,Kasa,Team,team,sciezka);
			}

//Gracz
			else
			{

				while(1)
				{
					if(mousedown()) 
					{	
						x=mousecurrentx()/r;
						y=mousecurrenty()/r;

//Tura
						if((x>Rx)&&(x<(Rx+3))&&(y<2))
						{
							break;
						}

//Wyjscie->Seppuku
						if((x>Rx+1)&&(x<(Rx+3))&&(y>Ry-2)&&(y<Ry))
						{
							//exit(-1);
							//wykres(Rx,Ry,r,krok,Punktacja);
							Team[team]=0;
							for(int ri=0;ri<Ry;++ri)
							{
								for(int rk=0;rk<Rx;++rk)
								{
									if(T[U[rk][ri]]==team)
									{
										Rip[rk][ri]=U[rk][ri];
										U[rk][ri]=0;
										area(rk,ri,r,A[rk][ri]);
										ifrip(rk,ri,r,Rip[rk][ri],T[Rip[rk][ri]]);
									}
								}
							}
							break;
						}

//Nicnierobienie ew. zebuszka
						if((m==3)&&(x==lx)&&(y==ly))
						{
//Zebuszka
							if(K[U[x][y]]==10)
							{
								distance(x,y,Rx,Ry,Zr,6);

								for(int ri=0;ri<Ry;++ri)
								{
									for(int rk=0;rk<Rx;++rk)
									{
										if((T[U[rk][ri]]==team)&&(U[rk][ri])&&(Zr[rk][ri]>0)&&(Zr[rk][ri]!=3))
										{
											HP[U[rk][ri]]=HP[U[rk][ri]]+10;
											if(HP[U[rk][ri]]>100) HP[U[rk][ri]]=100;										
										}
									}
								}
							}

//Nicnierobienie
							UA[lu]=0;

							m=0;

							for(int ri=0;ri<Ry;++ri)
							{
								for(int rk=0;rk<Rx;++rk)
								{
									if(At[rk][ri]||Zr[rk][ri])
									{
										area(rk,ri,r,A[rk][ri]);
										ifrip(rk,ri,r,Rip[rk][ri],T[Rip[rk][ri]]);
										if(U[rk][ri])
										{
											if(!UA[U[rk][ri]])
											{
												ua=9;
											}
											else
											{
												ua=T[U[rk][ri]];
											}
											unit(rk,ri,r,K[U[rk][ri]],ua,HP[U[rk][ri]]);
										}
									}

									Zr[rk][ri]=0;
									At[rk][ri]=0;
									Ru[rk][ri]=0;
								}
							}
						}

//Respienie
						if((x<Rx)&&(y<Ry)&&(m==3)&&(K[lu]==9)&&(U[x][y]==0)&&(Rip[x][y])&&(Zr[x][y]>0))
						{
							U[x][y]=Rip[x][y];
							Rip[x][y]=0;
							T[U[x][y]]=team;						
							HP[U[x][y]]=100;

							los=rand()%5;

							if(los==0)
							{
								K[U[x][y]]=99;
							}
							else
							{
								K[U[x][y]]=98;					
							}

							UA[U[x][y]]=0;
							UA[lu]=0;

							m=0;

							for(int ri=0;ri<Ry;++ri)
							{
								for(int rk=0;rk<Rx;++rk)
								{
									if(At[rk][ri]||Zr[rk][ri])
									{
										area(rk,ri,r,A[rk][ri]);
										ifrip(rk,ri,r,Rip[rk][ri],T[Rip[rk][ri]]);
										if(U[rk][ri])
										{
											if(!UA[U[rk][ri]])
											{
												ua=9;
											}
											else
											{
												ua=T[U[rk][ri]];
											}
											unit(rk,ri,r,K[U[rk][ri]],ua,HP[U[rk][ri]]);
										}
									}

									Zr[rk][ri]=0;
									At[rk][ri]=0;
									Ru[rk][ri]=0;
								}
							}
						}

//Atak
						if((x<Rx)&&(y<Ry)&&(m==3)&&U[x][y]&&(T[U[x][y]]!=team)&&(At[x][y]>0))
						{
//Hit						
							if(!((x==lx)&&(y==ly)))
							{
								dhp=HP[U[lx][ly]]*(damage(K[U[lx][ly]],K[U[x][y]])+randomdamage(K[U[lx][ly]])-defence(K[U[x][y]])-areadefence(A[x][y],K[U[x][y]]))/100;
								if(dhp<0) dhp=0;
								if(dhp>HP[U[x][y]])
								{
									dhp=HP[U[x][y]];
									HP[U[x][y]]=0;
								}
								else
								{
									HP[U[x][y]]=HP[U[x][y]]-dhp;
								}
								printf("\n%d [-%d]\t",HP[U[x][y]],dhp);
								if(HP[U[x][y]]<1)
								{
									if(K[U[x][y]]==77)
									{
										deadteam=T[U[x][y]];
										Team[deadteam]=0;

										for(int ri=0;ri<Ry;++ri)
										{
											for(int rk=0;rk<Rx;++rk)
											{
												if(T[U[rk][ri]]==deadteam)
												{
													Rip[rk][ri]=U[rk][ri];
													U[rk][ri]=0;
													area(rk,ri,r,A[rk][ri]);
													ifrip(rk,ri,r,Rip[rk][ri],T[Rip[rk][ri]]);
												}
											}
										}
									}
									else
									{
										Rip[x][y]=U[x][y];
										U[x][y]=0;	
									}
								}
								
//Wysysanie po hicie
								if(K[U[lx][ly]]==99)
								{
									HP[U[lx][ly]]=HP[U[lx][ly]]+dhp;
									if(HP[U[lx][ly]]>100) HP[U[lx][ly]]=100;
								}								
							}

							m=0;

							for(int ri=0;ri<Ry;++ri)
							{
								for(int rk=0;rk<Rx;++rk)
								{
									if(At[rk][ri]||Zr[rk][ri])
									{
										area(rk,ri,r,A[rk][ri]);
										ifrip(rk,ri,r,Rip[rk][ri],T[Rip[rk][ri]]);
										if(U[rk][ri])
										{
											if(!UA[U[rk][ri]])
											{
												ua=9;
											}
											else
											{
												ua=T[U[rk][ri]];
											}
											unit(rk,ri,r,K[U[rk][ri]],ua,HP[U[rk][ri]]);
										}
									}
								}
							}

//Odhit
							if(U[x][y]&&(At[x][y]==(At[lx][ly]-1))&&(K[U[x][y]]!=55))
							{
								delay(500);

								dhp=HP[U[x][y]]*(damage(K[U[x][y]],K[U[lx][ly]])+randomdamage(K[U[x][y]])-defence(K[U[lx][ly]])-areadefence(A[lx][ly],K[U[lx][ly]]))/100;
								if(dhp<0) dhp=0;
								if(dhp>HP[U[lx][ly]])
								{
									dhp=HP[U[lx][ly]];
									HP[U[lx][ly]]=0;
								}
								else
								{
									HP[U[lx][ly]]=HP[U[lx][ly]]-dhp;
								}
								printf("%d [-%d]",HP[U[lx][ly]],dhp);
								if(HP[U[lx][ly]]<1)
								{
									if(K[U[lx][ly]]==77)
									{
										deadteam=T[U[lx][ly]];
										Team[deadteam]=0;

										for(int ri=0;ri<Ry;++ri)
										{
											for(int rk=0;rk<Rx;++rk)
											{
												if(T[U[rk][ri]]==deadteam)
												{
													Rip[rk][ri]=U[rk][ri];
													U[rk][ri]=0;
													area(rk,ri,r,A[rk][ri]);
													ifrip(rk,ri,r,Rip[rk][ri],T[Rip[rk][ri]]);
												}
											}
										}
										break;
									}
									else
									{
										Rip[lx][ly]=U[lx][ly];
										U[lx][ly]=0;
									}
								}

//Wysysanie po odhicie
								if((K[U[x][y]]==99))
								{
									HP[U[x][y]]=HP[U[x][y]]+dhp;
									if(HP[U[x][y]]>100) HP[U[x][y]]=100;
									unit(x,y,r,99,T[U[x][y]],HP[U[x][y]]);
								}
							}

							area(lx,ly,r,A[lx][ly]);
							ifrip(lx,ly,r,Rip[lx][ly],T[Rip[lx][ly]]);
							unit(lx,ly,r,K[U[lx][ly]],9,HP[U[lx][ly]]);

							UA[lu]=0;

							for(int ri=0;ri<Ry;++ri)
							{
								for(int rk=0;rk<Rx;++rk)
								{
									Zr[rk][ri]=0;
									At[rk][ri]=0;
									Ru[rk][ri]=0;
								}
							}
						}

//Ruch
						if((x<Rx)&&(y<Ry)&&(m==1)&&(Ru[x][y]>0)&&((U[x][y]==0)||((x==lx)&&(y==ly))))
						{
							if(b) 
							{
								U[lx][ly]=0;						
							}

							b=1;
							U[x][y]=lu;
							lx=x;
							ly=y;

//Przejmowanie nieruchomoœci
							if(((K[lu]==77)||(K[lu]==1))&&(A[x][y]!=teamCastle(T[lu]))&&(10!=whatTeam(A[x][y]))&&(27!=A[x][y])&&(29!=A[x][y])&&(30!=A[x][y])&&(28!=A[x][y])&&(31!=A[x][y])&&(32!=A[x][y])&&(10!=A[x][y]))
							{
								A[x][y]=teamCastle(T[lu]);
							}

							if(((K[lu]==77)||(K[lu]==1)||(K[lu]==2))&&(A[x][y]!=teamVillage(T[lu]))&&(10!=whatTeam(A[x][y]))&&(11!=A[x][y])&&(25!=A[x][y])&&(12!=A[x][y])&&(24!=A[x][y])&&(13!=A[x][y])&&(26!=A[x][y])&&(23!=A[x][y]))
							{
								A[x][y]=teamVillage(T[lu]);
							}

							m=2;

							for(int ri=0;ri<Ry;++ri)
							{
								for(int rk=0;rk<Rx;++rk)
								{
									if(Ru[rk][ri])
									{
										area(rk,ri,r,A[rk][ri]);
										ifrip(rk,ri,r,Rip[rk][ri],T[Rip[rk][ri]]);
										if(U[rk][ri])
										{
											if(!UA[U[rk][ri]])
											{
												ua=9;
											}
											else
											{
												ua=T[U[rk][ri]];
											}
											unit(rk,ri,r,K[U[rk][ri]],ua,HP[U[rk][ri]]);	
										}
										Ru[rk][ri]=0;
									}
								}
							}
						}

//Odwolanie wyboru opcji kupowania
						if((x>Rx)&&(x<Rx+3)&&(y>2)&&(y<6)&&(m==10))
						{
							m=20;

							for(int ri=0;ri<Ry;++ri)
							{
								for(int rk=0;rk<Rx;++rk)
								{
									area(rk,ri,r,A[rk][ri]);
									ifrip(rk,ri,r,Rip[rk][ri],T[Rip[rk][ri]]);
									if(U[rk][ri])
									{
										if(!UA[U[rk][ri]])
										{
											ua=9;
										}
										else
										{
											ua=T[U[rk][ri]];
										}
										unit(rk,ri,r,K[U[rk][ri]],ua,HP[U[rk][ri]]);

									}
								}
							}

							monetki(Rx,Ry,r,Kasa[team]);
						}

//Kupowanie
						if((Kasa[team]>=price(y))&&(x==2)&&(y>0)&&(y<(liczbadostepnychjednostek+1))&&(m==10))
						{
							for(int ri=0;ri<Ry;++ri)
							{
								for(int rk=0;rk<Rx;++rk)
								{
									if(A[rk][ri]==teamCastle(team))
									{
										Ru[rk][ri]=unitDystance(y);
									}
								}
							}

							for(int ud=unitDystance(y);ud>0;ud--)
							{
								for(int ri=0;ri<Ry;++ri)
								{
									for(int rk=0;rk<Rx;++rk)
									{
										if(Ru[rk][ri]==ud)
										{
											//<
											if((rk-1>=0)&&(Ru[rk-1][ri]==0)&&((U[rk-1][ri]==0)||(T[U[rk-1][ri]]==team)))
											{
												Ru[rk-1][ri]=Ru[rk][ri]-areaDystance(A[rk-1][ri],y);
											}
											//>
											if((rk+1<Rx)&&(Ru[rk+1][ri]==0)&&((U[rk+1][ri]==0)||(T[U[rk+1][ri]]==team)))
											{
												Ru[rk+1][ri]=Ru[rk][ri]-areaDystance(A[rk+1][ri],y);
											}
											//A
											if((ri-1>=0)&&(Ru[rk][ri-1]==0)&&((U[rk][ri-1]==0)||(T[U[rk][ri-1]]==team)))
											{
												Ru[rk][ri-1]=Ru[rk][ri]-areaDystance(A[rk][ri-1],y);
											}
											//V
											if((ri+1<Ry)&&(Ru[rk][ri+1]==0)&&((U[rk][ri+1]==0)||(T[U[rk][ri+1]]==team)))
											{
												Ru[rk][ri+1]=Ru[rk][ri]-areaDystance(A[rk][ri+1],y);
											}
										}
									}
								}
							}

							m=10;

							for(int ri=0;ri<Ry;++ri)
							{
								for(int rk=0;rk<Rx;++rk)
								{
									if((Ru[rk][ri]>0)&&(U[rk][ri]==0))
									{
										m=1;
									}
								}
							}

							if(m==10)
							{
								for(int ri=0;ri<Ry;++ri)
								{
									for(int rk=0;rk<Rx;++rk)
									{
										Ru[rk][ri]=0;
									}
								}
								rip(2,y,r,9);
							}

							if(m==1)
							{
								for(int ri=0;ri<Ry;++ri)
								{
									for(int rk=0;rk<Rx;++rk)
									{
										area(rk,ri,r,A[rk][ri]);
										ifrip(rk,ri,r,Rip[rk][ri],T[Rip[rk][ri]]);
										if(U[rk][ri])
										{
											if(!UA[U[rk][ri]])
											{
												ua=9;
											}
											else
											{
												ua=T[U[rk][ri]];
											}
											unit(rk,ri,r,K[U[rk][ri]],ua,HP[U[rk][ri]]);

										}

										if((Ru[rk][ri]>0)&&(U[rk][ri]==0))
										{
											frame(rk,ri,r,2);
										}
									}
								}

								Kasa[team]=Kasa[team]-price(y);

								T[u]=team;
								K[u]=y;
								lu=u;
								lx=10000;
								ly=10000;
								u++;
								//printf("u = %d\n",u);

								b=0;

								setcolor(BLACK);
								bar(Rx*r,3*r,Rx*r+3*r,6*r);
								monetki(Rx,Ry,r,Kasa[team]);
							}					
						}
		

//Wybor opcji kupowania
						if((x>Rx)&&(x<Rx+3)&&(y>2)&&(y<6)&&(m==0))
						{
							m=10; 

							setcolor(BLACK);
							bar(0,0,Rx*r,Ry*r);
							monetki(Rx,Ry,r,Kasa[team]);
							
							for(int i=0;i<liczbadostepnychjednostek;i++)
							{
								area(2,i+1,r,14);
								if(Kasa[team]<price(i+1))
								{
									ua=9;
								}
								else
								{
									ua=team;
								}
								unit(2,i+1,r,i+1,ua,0);
								monetki2(i+1,r,price(i+1));
							}
						}

//Wybor postaci
						if((x<Rx)&&(y<Ry)&&U[x][y]&&(m==0)&&(T[U[x][y]]==team)&&UA[U[x][y]])
						{
							frame(x,y,r,4);

							lx=x;
							ly=y;
							lu=U[x][y];

							Ru[x][y]=unitDystance(K[lu]);
							for(int ud=unitDystance(K[lu]);ud>0;ud--)
							{
								for(int ri=0;ri<Ry;++ri)
								{
									for(int rk=0;rk<Rx;++rk)
									{
										if(Ru[rk][ri]==ud)
										{
											//<
											if((rk-1>=0)&&(Ru[rk-1][ri]==0)&&((U[rk-1][ri]==0)||(T[U[rk-1][ri]]==team)))
											{
												Ru[rk-1][ri]=Ru[rk][ri]-areaDystance(A[rk-1][ri],K[lu]);
											}
											//>
											if((rk+1<Rx)&&(Ru[rk+1][ri]==0)&&((U[rk+1][ri]==0)||(T[U[rk+1][ri]]==team)))
											{
												Ru[rk+1][ri]=Ru[rk][ri]-areaDystance(A[rk+1][ri],K[lu]);
											}
											//A
											if((ri-1>=0)&&(Ru[rk][ri-1]==0)&&((U[rk][ri-1]==0)||(T[U[rk][ri-1]]==team)))
											{
												Ru[rk][ri-1]=Ru[rk][ri]-areaDystance(A[rk][ri-1],K[lu]);
											}
											//V
											if((ri+1<Ry)&&(Ru[rk][ri+1]==0)&&((U[rk][ri+1]==0)||(T[U[rk][ri+1]]==team)))
											{
												Ru[rk][ri+1]=Ru[rk][ri]-areaDystance(A[rk][ri+1],K[lu]);
											}
										}
									}
								}
							}

							m=2;

							for(int ri=0;ri<Ry;++ri)
							{
								for(int rk=0;rk<Rx;++rk)
								{
									if((Ru[rk][ri]>0)&&!((x==rk)&&(y==ri))&&(U[rk][ri]==0))
									{
										frame(rk,ri,r,2);
										m=1;
									}
								}
							}
						}

//Dodatkowy bajer
						if(m==20)
						{
							m=0;
						}
					
//Szukanie przeciwnikow
						if(m==2)
						{
							distance(x,y,Rx,Ry,At,K[lu]);

							for(int ri=0;ri<Ry;++ri)
							{
								for(int rk=0;rk<Rx;++rk)
								{
									if((At[rk][ri]>0)&&(U[rk][ri])&&(T[U[rk][ri]]!=team))
									{
										m=3;
									}
								}
							}

							if(m==3)
							{
								for(int ri=0;ri<Ry;++ri)
								{
									for(int rk=0;rk<Rx;++rk)
									{
										if(At[rk][ri]>0)
										{
											frame(rk,ri,r,55);
										}
										if((At[rk][ri]>0)&&(U[rk][ri])&&(T[U[rk][ri]]!=team))
										{
											frame(rk,ri,r,0);
										}
									}
								}

								frame(x,y,r,4);
							}
							
							if(m!=3)
							{
								unit(x,y,r,K[lu],9,HP[lu]);
								UA[lu]=0;

								m=0;

//Zebuszka
								if(K[U[x][y]]==10)
								{
									distance(x,y,Rx,Ry,Zr,6);
		
									for(int ri=0;ri<Ry;++ri)
									{
										for(int rk=0;rk<Rx;++rk)
										{
											if((T[U[rk][ri]]==team)&&(U[rk][ri])&&(Zr[rk][ri]>0)&&(Zr[rk][ri]!=3))
											{
												HP[U[rk][ri]]=HP[U[rk][ri]]+10;
												if(HP[U[rk][ri]]>100) HP[U[rk][ri]]=100;

												if(!UA[U[rk][ri]])
												{
													ua=9;
												}
												else
												{
													ua=T[U[rk][ri]];
												}
												unit(rk,ri,r,K[U[rk][ri]],ua,HP[U[rk][ri]]);

											}
										}
									}
								}

								for(int ri=0;ri<Ry;++ri)
								{
									for(int rk=0;rk<Rx;++rk)
									{
										At[rk][ri]=0;
										Ru[rk][ri]=0;
										Zr[rk][ri]=0;
									}
								}
							}

//Szukanie grobow
							if(K[U[x][y]]==9)
							{
								distance(x,y,Rx,Ry,Zr,9);							
								for(int ri=0;ri<Ry;++ri)
								{
									for(int rk=0;rk<Rx;++rk)
									{
										if((Zr[rk][ri]>0)&&(U[rk][ri]==0)&&(Rip[rk][ri]))
										{
											frame(rk,ri,r,63);
											m=3;
										}
									}
								}
							}
						}
					}
				}
			}
		}
	}

	for(int i=0;i<Rx;++i) free(A[i]);
	free(A);
	for(int i=0;i<Rx;++i) free(U[i]);
	free(U);
	for(int i=0;i<Rx;++i) free(Ru[i]);
	free(Ru);
	for(int i=0;i<Rx;++i) free(At[i]);
	free(At);
	for(int i=0;i<Rx;++i) free(Zr[i]);
	free(Zr);
	for(int i=0;i<Rx;++i) free(Rip[i]);
	free(Rip);
	for(int i=0;i<tmax;++i) free(Punktacja[i]);
	free(Punktacja);
	free(T);
	free(K);
	free(UA);
	free(HP);
}



