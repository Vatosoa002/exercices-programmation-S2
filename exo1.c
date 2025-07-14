#include <stdio.h>
int entrerTaille(void);
void remplirTableau(int *tableau, int taille);
void triage(int *tableau, int taille);
int main()
{
	int T[50];
	int N;
	N=entrerTaille();
	remplirTableau(T,N);
	triage(T,N);
	return(0);
}
int entrerTaille(void)
{
	int taille;
	printf("Entrer la taille du tableau T:");
	scanf("%d", &taille);
	return(taille);
}
void remplirTableau(int *tableau, int taille)
{
	int i;
	for(i=0;i<taille;i++)
	{
		printf("T[%d]=",i);
		scanf("%d", &tableau[i]);
	}
}

void triage(int *tableau, int taille)
{
	int i,j=0,t=0;
	int temp[taille];
	for(i=0;i<taille;i++)
	{
		if(tableau[i]%2 != 0)
		{
			temp[t]=tableau[i];
			t++;
		}
		else if(tableau[i]%2 == 0)
		{
			tableau[j]=tableau[i];
			j++;
		}
	}
	i=j-1;
	t=-1;
	do
	{
		t++;
		i++;
		tableau[i]=temp[t];
	}while(i<taille);
	for(i=0;i<taille;i++)
	{
		printf("%d ",tableau[i]);
	}
	printf("\n");
}
	


