#include <stdio.h>
#include <math.h>
#include "winbgi2.h"
#include <stdlib.h>
#include <time.h>

//[AI]Sztuczna inteligencja AI_1 
// - kmiotki kieruja sie na domki
// - rycerze kieruja sie na domki i zamki
// - krol sie nie porusza

void AI_1(int &u,int Rx,int Ry, int r, int **U, int **A, int **Rip, int **Ru, int **At, int *K, int *T, int *HP, int *UA, int *Kasa,int *Team, int team, int sciezka)
{
	int x,y,lx,ly,lu,nx,ny,nd,d,m;
	int dhp,deadteam,ua;
	int kx,ky;
	int zakup=2;
	int kupowanie=1;

	delay(1000);

	for(int i=0;i<Ry;++i)
	{
		for(int k=0;k<Rx;++k)
		{
//[AI][Ruch]
			if((T[U[k][i]]==team)&&(UA[U[k][i]]))
			{
				lx=k;
				ly=i;
				x=k;
				y=i;
				lu=U[k][i];

				if(sciezka) frame(x,y,r,4);

//[AI][Ruch][Kmiotek][Rycerz]
				if(K[U[k][i]]==2 || K[U[k][i]]==1 || K[U[k][i]]==77)
				{
//[AI][Ruch][Kmiotek][Rycerz]Szukanie najblizszego domku lub zamku
					nx=Rx/2;
					ny=Ry/2;
					nd=9999;
					d=9999;

					for(int ni=0;ni<Ry;++ni)
					{
						for(int nk=0;nk<Rx;++nk)
						{
//[AI][Ruch][Kmiotek]Szukanie najblizszego domku
							if((K[lu]==2)&&(A[nk][ni]!=teamVillage(team))&&(10!=whatTeam(A[nk][ni]))&&(11!=A[nk][ni])&&(25!=A[nk][ni])&&(12!=A[nk][ni])&&(24!=A[nk][ni])&&(13!=A[nk][ni])&&(26!=A[nk][ni])&&(23!=A[nk][ni]))
							{
								d=abs(ni-i)+abs(nk-k);
								if(d<nd)
								{
									nx=nk;
									ny=ni;
									nd=d;
								}
							}
//[AI][Ruch][Rycerz]Szukanie najblizszego domku lub zamku
							if((K[lu]==1)&&(A[nk][ni]!=teamCastle(team))&&(A[nk][ni]!=teamVillage(team))&&(10!=whatTeam(A[nk][ni])))
							//if((K[lu]==1)&&(A[nk][ni]!=teamCastle(team))&&(10!=whatTeam(A[nk][ni]))&&(27!=A[nk][ni])&&(29!=A[nk][ni])&&(30!=A[nk][ni])&&(28!=A[nk][ni])&&(31!=A[nk][ni])&&(32!=A[nk][ni])&&(10!=A[nk][ni]))
							{
								d=abs(ni-i)+abs(nk-k);
								if(d<nd)
								{
									nx=nk;
									ny=ni;
									nd=d;
								}
							}
						}
					}

					nd=9999;
					d=9999;
					
					Ru[k][i]=unitDystance(K[lu]);
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

					for(int ri=0;ri<Ry;++ri)
					{
						for(int rk=0;rk<Rx;++rk)
						{
							if((Ru[rk][ri]>0)&&(U[rk][ri]==0))
							{	
								if(sciezka&&(Ru[rk][ri]>0)&&!((x==rk)&&(y==ri))&&(U[rk][ri]==0))
								{
									frame(rk,ri,r,2);
								}

								d=abs(ny-ri)+abs(nx-rk);
								if(d<nd)
								{
									x=rk;
									y=ri;
									nd=d;
								}						
							}
						}
					}

					if(sciezka) delay(500);

//[AI][Ruch][Kmiotek][Rycerz]Przejmowanie nieruchomoœci			
					if(((K[lu]==77)||(K[lu]==1))&&(A[x][y]!=teamCastle(T[lu]))&&(10!=whatTeam(A[x][y]))&&(27!=A[x][y])&&(29!=A[x][y])&&(30!=A[x][y])&&(28!=A[x][y])&&(31!=A[x][y])&&(32!=A[x][y])&&(10!=A[x][y]))
					{
						A[x][y]=teamCastle(T[lu]);
					}

					if(((K[lu]==77)||(K[lu]==1)||(K[lu]==2))&&(A[x][y]!=teamVillage(T[lu]))&&(10!=whatTeam(A[x][y]))&&(11!=A[x][y])&&(25!=A[x][y])&&(12!=A[x][y])&&(24!=A[x][y])&&(13!=A[x][y])&&(26!=A[x][y])&&(23!=A[x][y]))
					{
						A[x][y]=teamVillage(T[lu]);
					}
				}

//[AI][Ruch][King]
				if(K[U[k][i]]==77)
				{
					x=lx;
					y=ly;
					kx=lx;
					ky=ly;
				}

//[AI][Ruch]Przesuniecie postaci
				U[lx][ly]=0;
				U[x][y]=lu;
				if(!sciezka)
				{
					area(lx,ly,r,A[lx][ly]);
					area(x,y,r,A[x][y]);
					ifrip(lx,ly,r,Rip[lx][ly],T[Rip[lx][ly]]);
					ifrip(x,y,r,Rip[x][y],T[Rip[x][y]]);				
					unit(x,y,r,K[lu],T[U[x][y]],HP[lu]);
				}

				for(int ri=0;ri<Ry;++ri)
				{
					for(int rk=0;rk<Rx;++rk)
					{
						if(sciezka && Ru[rk][ri])
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
						Ru[rk][ri]=0;
					}
				}


//[AI][Atak]Szukanie przeciwnikow
				distance(x,y,Rx,Ry,At,K[lu]);
				m=0;
				lx=x;
				ly=y;

				for(int ri=0;ri<Ry;++ri)
				{
					for(int rk=0;rk<Rx;++rk)
					{
						if((At[rk][ri]>0)&&(U[rk][ri])&&(T[U[rk][ri]]!=team))
						{
							m=1;
							x=rk;
							y=ri;
						}
					}
				}

//[AI][Atak]Znaleziono przeciwnika
				if(m==1)
				{
					if(sciezka)
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

					delay(500);
//Hit						
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

					if(sciezka)
					{
						for(int ri=0;ri<Ry;++ri)
						{
							for(int rk=0;rk<Rx;++rk)
							{
								if(At[rk][ri])
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

					}
					else
					{
						area(lx,ly,r,A[lx][ly]);
						area(x,y,r,A[x][y]);
						ifrip(lx,ly,r,Rip[lx][ly],T[Rip[lx][ly]]);
						ifrip(x,y,r,Rip[x][y],T[Rip[x][y]]);
						unit(lx,ly,r,K[U[lx][ly]],T[U[lx][ly]],HP[U[lx][ly]]);
						unit(x,y,r,K[U[x][y]],T[U[x][y]],HP[U[x][y]]);
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
				}

//[AI][Atak]Nie znaleziono przeciwnika			
				if(m!=1)
				{
					//unit(x,y,r,K[lu],9,HP[lu]);
					UA[lu]=0;
				}

				area(lx,ly,r,A[lx][ly]);
				ifrip(lx,ly,r,Rip[lx][ly],T[Rip[lx][ly]]);
				unit(lx,ly,r,K[U[lx][ly]],9,HP[U[lx][ly]]);
				UA[lu]=0;

//[AI][Atak]Czyszczenie po ataku
				for(int ri=0;ri<Ry;++ri)
				{
					for(int rk=0;rk<Rx;++rk)
					{
						At[rk][ri]=0;
					}
				}

				delay(500);
	
			}			
		}
	}

//-------------------------------------------------------------------------------------------

//[AI][Kupowanie]

	while(kupowanie && Team[team])
	{

//[AI][Kupowanie]Wybor postaci
		if(Kasa[team]>3*price(1))
		{
			switch(rand()%2)
			{
				case 0:
					zakup=1;
					break;
				case 1:
					zakup=2;
					break;
			}
		}
		else if(Kasa[team]>price(1))
		{
			switch(rand()%5)
			{
				case 0:
					zakup=1;
					break;
				case 1:
					zakup=2;
					break;
				case 2:
					zakup=2;
					break;
				case 3:
					zakup=2;
					break;
				case 4:
					zakup=2;
					break;
			}
		}
		else if(Kasa[team]>=price(2))
		{
			switch(rand()%2)
			{
				case 0:
					zakup=2;
					break;
				case 1:
					kupowanie=0;
					break;
			}
		}
		else
		{
			kupowanie=0;
			break;
		}

		if(!kupowanie) break;

//[AI][Kupowanie][Ruch][Kmiotek][Rycerz]Szukanie najblizszego domku lub zamku
		nx=Rx/2;
		ny=Ry/2;
		nd=9999;
		d=9999;

		for(int ni=0;ni<Ry;++ni)
		{
			for(int nk=0;nk<Rx;++nk)
			{
//[AI][Kupowanie][Ruch][Kmiotek]Szukanie najblizszego domku
				if((zakup==2)&&(A[nk][ni]!=teamVillage(team))&&(10!=whatTeam(A[nk][ni]))&&(11!=A[nk][ni])&&(25!=A[nk][ni])&&(12!=A[nk][ni])&&(24!=A[nk][ni])&&(13!=A[nk][ni])&&(26!=A[nk][ni])&&(23!=A[nk][ni]))
				{
					d=abs(ni-ky)+abs(nk-kx);
					if(d<nd)
					{
						nx=nk;
						ny=ni;
						nd=d;
					}
				}
//[AI][Kupowanie][Ruch][Rycerz]Szukanie najblizszego domku lub zamku
				if((zakup==1)&&(A[nk][ni]!=teamCastle(team))&&(A[nk][ni]!=teamVillage(team))&&(10!=whatTeam(A[nk][ni])))
				//if((K[lu]==1)&&(A[nk][ni]!=teamCastle(team))&&(10!=whatTeam(A[nk][ni]))&&(27!=A[nk][ni])&&(29!=A[nk][ni])&&(30!=A[nk][ni])&&(28!=A[nk][ni])&&(31!=A[nk][ni])&&(32!=A[nk][ni])&&(10!=A[nk][ni]))
				{
					d=abs(ni-ky)+abs(nk-kx);
					if(d<nd)
					{
						nx=nk;
						ny=ni;
						nd=d;
					}
				}
			}
		}

		nd=9999;
		d=9999;

		for(int ni=0;ni<Ry;++ni)
		{
			for(int nk=0;nk<Rx;++nk)
			{
				if(A[nk][ni]==teamCastle(team))
				{
					Ru[nk][ni]=unitDystance(zakup);
				}
			}
		}



		for(int ud=unitDystance(zakup);ud>0;ud--)
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
							Ru[rk-1][ri]=Ru[rk][ri]-areaDystance(A[rk-1][ri],zakup);
						}
						//>
						if((rk+1<Rx)&&(Ru[rk+1][ri]==0)&&((U[rk+1][ri]==0)||(T[U[rk+1][ri]]==team)))
						{
							Ru[rk+1][ri]=Ru[rk][ri]-areaDystance(A[rk+1][ri],zakup);
						}
						//A
						if((ri-1>=0)&&(Ru[rk][ri-1]==0)&&((U[rk][ri-1]==0)||(T[U[rk][ri-1]]==team)))
						{
							Ru[rk][ri-1]=Ru[rk][ri]-areaDystance(A[rk][ri-1],zakup);
						}
						//V
						if((ri+1<Ry)&&(Ru[rk][ri+1]==0)&&((U[rk][ri+1]==0)||(T[U[rk][ri+1]]==team)))
						{
							Ru[rk][ri+1]=Ru[rk][ri]-areaDystance(A[rk][ri+1],zakup);
						}
					}
				}
			}
		}

		m=0;

		for(int ri=0;ri<Ry;++ri)
		{
			for(int rk=0;rk<Rx;++rk)
			{
				if((Ru[rk][ri]>0)&&(U[rk][ri]==0))
				{

					if(sciezka&&(Ru[rk][ri]>0)&&!((x==rk)&&(y==ri))&&(U[rk][ri]==0))
					{
						frame(rk,ri,r,2);
					}

					d=abs(ny-ri)+abs(nx-rk);
					if(d<nd)
					{
						x=rk;
						y=ri;
						nd=d;
					}

					m=1;
				}
			}
		}

		if(!m) 
		{
			break;
		}
		else
		{
			Kasa[team]-=price(zakup);

			setcolor(BLACK);
			bar(Rx*r,3*r,Rx*r+3*r,6*r);
			monetki(Rx,Ry,r,Kasa[team]);

			lu=u;
			u++;
			K[lu]=zakup;
			T[lu]=team;
		}

		if(sciezka) delay(500);

//[AI][Kupowanie][Ruch][Kmiotek][Rycerz]Przejmowanie nieruchomoœci			
		if(((K[lu]==77)||(K[lu]==1))&&(A[x][y]!=teamCastle(T[lu]))&&(10!=whatTeam(A[x][y]))&&(27!=A[x][y])&&(29!=A[x][y])&&(30!=A[x][y])&&(28!=A[x][y])&&(31!=A[x][y])&&(32!=A[x][y])&&(10!=A[x][y]))
		{
			A[x][y]=teamCastle(T[lu]);
		}

		if(((K[lu]==77)||(K[lu]==1)||(K[lu]==2))&&(A[x][y]!=teamVillage(T[lu]))&&(10!=whatTeam(A[x][y]))&&(11!=A[x][y])&&(25!=A[x][y])&&(12!=A[x][y])&&(24!=A[x][y])&&(13!=A[x][y])&&(26!=A[x][y])&&(23!=A[x][y]))
		{
			A[x][y]=teamVillage(T[lu]);
		}

//[AI][Kupowanie][Ruch]Przesuniecie postaci
		//U[lx][ly]=0;
		U[x][y]=lu;
		if(!sciezka)
		{
			area(lx,ly,r,A[lx][ly]);
			area(x,y,r,A[x][y]);
			ifrip(lx,ly,r,Rip[lx][ly],T[Rip[lx][ly]]);
			ifrip(x,y,r,Rip[x][y],T[Rip[x][y]]);				
			unit(x,y,r,K[lu],T[U[x][y]],HP[lu]);
		}

		for(int ri=0;ri<Ry;++ri)
		{
			for(int rk=0;rk<Rx;++rk)
			{
				if(sciezka && Ru[rk][ri])
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
				Ru[rk][ri]=0;
			}
		}


//[AI][Kupowanie][Atak]Szukanie przeciwnikow
		distance(x,y,Rx,Ry,At,K[lu]);
		m=0;
		lx=x;
		ly=y;

		for(int ri=0;ri<Ry;++ri)
		{
			for(int rk=0;rk<Rx;++rk)
			{
				if((At[rk][ri]>0)&&(U[rk][ri])&&(T[U[rk][ri]]!=team))
				{
					m=1;
					x=rk;
					y=ri;
				}
			}
		}

//[AI][Kupowanie][Atak]Znaleziono przeciwnika
		if(m==1)
		{
			if(sciezka)
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

			delay(500);
//Hit						
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

			if(sciezka)
			{
				for(int ri=0;ri<Ry;++ri)
				{
					for(int rk=0;rk<Rx;++rk)
					{
						if(At[rk][ri])
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

			}
			else
			{
				area(lx,ly,r,A[lx][ly]);
				area(x,y,r,A[x][y]);
				ifrip(lx,ly,r,Rip[lx][ly],T[Rip[lx][ly]]);
				ifrip(x,y,r,Rip[x][y],T[Rip[x][y]]);
				unit(lx,ly,r,K[U[lx][ly]],T[U[lx][ly]],HP[U[lx][ly]]);
				unit(x,y,r,K[U[x][y]],T[U[x][y]],HP[U[x][y]]);
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
		}

//[AI][Kupowanie][Atak]Nie znaleziono przeciwnika			
		if(m!=1)
		{
			//unit(x,y,r,K[lu],9,HP[lu]);
			UA[lu]=0;
		}

		area(lx,ly,r,A[lx][ly]);
		ifrip(lx,ly,r,Rip[lx][ly],T[Rip[lx][ly]]);
		unit(lx,ly,r,K[U[lx][ly]],9,HP[U[lx][ly]]);
		UA[lu]=0;

//[AI][Kupowanie][Atak]Czyszczenie po ataku
		for(int ri=0;ri<Ry;++ri)
		{
			for(int rk=0;rk<Rx;++rk)
			{
				At[rk][ri]=0;
			}
		}

		delay(500);

	}

/**/
	delay(1000);
}