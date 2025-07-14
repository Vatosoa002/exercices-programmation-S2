#include<stdio.h>
#include<math.h>
void entrerTaille(int *taille);
void remplirTableau(int *tableau, int taille);
float calculMoyenne(int *tableau, int taille);
void trouverProche(int *tableau, int taille, float moyenne);
int main()
{
    int N;
    float moyenne;
    int T[50];
    entrerTaille(&N);
    remplirTableau(T,N);
    moyenne=calculMoyenne(T,N);
    trouverProche(T,N,moyenne);
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
			printf("La taille du tableau doit etre entre 1 et 50\n");
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
float calculMoyenne(int *tableau, int taille)
{
    int i;
    long int somme=0;
    for(i=0;i<taille;i++)
    {
        somme=somme+tableau[i];
    }
    return(somme/taille);
}
void trouverProche(int *tableau, int taille, float moyenne)
{
    float diff,min;
    int i;
    diff=fabs(moyenne-tableau[0]);
    for(i=1;i<taille;i++)
    {
        if(diff>fabs(moyenne-tableau[i]))
        {
            diff=fabs(moyenne-tableau[i]);
            min=tableau[i];
        }
    }
    printf("Le proche de la moyenne est %f\n",min);
}