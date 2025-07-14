#include<stdio.h>
int entrerTaille(void);
void remplirTableau( int taille,int (*tableau)[taille]);
void afficherTableau( int taille,int (*tableau)[taille]);
void magiqueOuNon( int taille,int (*tableau)[taille]);
int main()
{
    int tab[50][50];
    int n;
    n=entrerTaille();
    remplirTableau(n,tab);
    afficherTableau(n,tab);
    magiqueOuNon(n,tab);
    return(0);
}
int entrerTaille(void)
{
    int taille;
    int r;
    do
	{
		printf("Entrer le nombre de ligne et de colonne :");
		r=scanf("%d", &taille);
		if(r!=1)
		{
			while(getchar()!='\n');
			printf("\tERREUR\n");
			taille=0;
		}
		else if(taille<1 || taille>50)
		{
			printf("Taille indisponible\n");
		}
	}while(taille<1 || taille>50);
    return(taille);
}
void remplirTableau( int taille,int (*tableau)[taille])
{
    int i,j;
    for(i=0;i<taille;i++)
	{
		for(j=0;j<taille;j++)
		{
			printf("tab[%d][%d]=",i,j);
			scanf("%d", &tableau[i][j]);
		}
	}
}
void afficherTableau( int taille,int (*tableau)[taille])
{
    int i,j;
    for(i=0;i<taille;i++)
	{
		for(j=0;j<taille;j++)
		{
			printf("%d\t",tableau[i][j]);
		}
		printf("\n");
	}
}
void magiqueOuNon( int taille,int (*tableau)[taille])
{
    int i,count,j,s,c;
    count=0;
    c=0;
    for(i=0;i<taille;i++)
	{
		c=c+tableau[0][i];
		s=0;
		for(j=0;j<taille;j++)
		{
			s=s+tableau[i][j];
			if(s==c)
			{
				count++;
			}
			s=0;
			s=s+tableau[j][i];
			if(s==c)
			{
				count++;
			}
		}
	}
	if(count==2*taille)
	{
		printf("Ce carree est magique\n");
	}
	else
	{
		printf("Ce carree n'est pas magique\n");
	}
}