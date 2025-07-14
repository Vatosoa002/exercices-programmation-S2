#include<stdio.h>
void entrerTaille(int *taille);
void remplirTableau(int *tableau, int taille);
void supprimmerElement(int *tableau, int *taille);
void afficherTableau(int *tableau, int taille);
int main()
{
    int N;
    int T[50];
    entrerTaille(&N);
    remplirTableau(T,N);
    supprimmerElement(T,&N);
    afficherTableau(T,N);
    return (0);
}
void entrerTaille(int *taille)
{
    int r;
    do
	{
		printf("Entrer la taille du tableau :");
		r=scanf("%d", taille);
		if(r!=1)
		{
			while(getchar()!='\n');
			printf("\tERREUR\n");
			*taille=0;
		}
		else if(*taille<1 || *taille>50)
		{
			printf("La taille doit etre entre 1 et 50\n");
		}
	}while(*taille<1 || *taille>50);
}
void remplirTableau(int *tableau, int taille)
{
    int i;
    for(i=0;i<taille;i++)
	{
		printf("Entrer l'element %d du tableau :",i+1);
		scanf("%d", &tableau[i]);
	}
}
void supprimmerElement(int *tableau, int *taille)
{
    int i,j,X;
    printf("Entrer l'element X a supprimer :");
	scanf("%d", &X);
    j=0;
	for(i=0;i<*taille;i++)
	{
		if(tableau[i]!=X)
		{
			tableau[j]=tableau[i];
			j++;
		}
	}
    *taille=j;
}
void afficherTableau(int *tableau, int taille)
{
    int i;
    printf("//Affichage//\n");
    for(i=0;i<taille;i++)
    {
        printf("T[%d]=%d\n",i,tableau[i]);
    }
}