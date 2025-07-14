#include <stdio.h>
int entrerTaille(void);
void remplirTableau(int *tableau, int taille);
void trouverMax(int *tableau, int taille);
void trouverMin(int *tableau, int taille);
int main()
{
	int N;
	int T[50];
	N=entrerTaille();
	remplirTableau(T,N);
	trouverMax(T,N);
	trouverMin(T,N);
	return (0);
}
int entrerTaille(void)
{
	int taille,r;
	do
	{
		printf("Entrer la taille du tableau (max 50):");
		r=scanf("%d", &taille);
		if(r != 1) {
			while(getchar() != '\n'); // vider le tampon d'entrée
			printf("Erreur de saisie, veuillez entrer un nombre entier.\n");
			taille = 0; // Réinitialiser taille pour forcer une nouvelle saisie
		}
		// Vérifie si la taille est valide (entre 1 et 50)
		// Si la taille n'est pas valide, demande à l'utilisateur de réessayer
		if(taille < 1 || taille > 50)
		{
			printf("Taille invalide, veuillez reessayer.\n");
		}
	} while(taille < 1 || taille > 50);
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
void trouverMax(int *tableau, int taille)
{
	int max,i,p;
	max=tableau[0];
	for(i=0;i<taille;i++)
	{
		if(max<tableau[i])
		{
			max=tableau[i];
			p=i;
		}
	}
	printf("max=T[%d]=%d\n",p,max);
}
void trouverMin(int *tableau, int taille)
{
	int min,i,p;
	min=tableau[0];
	for(i=0;i<taille;i++)
	{
		if(min>tableau[i])
		{
			min=tableau[i];
			p=i;
		}
	}
	printf("min=T[%d]=%d\n",p,min);
}
