#include <stdio.h>
void entrerTaille(int *tailleA, int *tailleB);
void remplirTableau(int *tableau1, int taille1, int *tableau2, int taille2);
void ajoutdeBaA(int *tableau1, int taille1, int *tableau2, int taille2);
void afficherTableau(int *tableau, int taille1, int taille2);
int main()
{
	int A[100],B[50];
	int N,M;
	entrerTaille(&N,&M);
	remplirTableau(A,N,B,M);
	ajoutdeBaA(A,N,B,M);
	afficherTableau(A,N,M);
	return (0);
}
void entrerTaille(int *tailleA, int *tailleB)
{
	int r;
	do
	{
		printf("Entrer la taille du tableau A (max 100):");
		r=scanf("%d", tailleA);
		if(r != 1) {
			while(getchar() != '\n'); 
			printf("Erreur de saisie, veuillez entrer un nombre entier.\n");
			*tailleA = 0; 
		}
		if(*tailleA < 1 || *tailleA > 100)
		{
			printf("Taille invalide, veuillez reessayer.\n");
		}
	} while(*tailleA < 1 || *tailleA > 100);
	do
	{		
		printf("Entrer la taille du tableau B (max 50):");
		r=scanf("%d", tailleB);
		if(r != 1) {
			while(getchar() != '\n'); 
			printf("Erreur de saisie, veuillez entrer un nombre entier.\n");
			*tailleB = 0; 
		}
		if(*tailleB < 1 || *tailleB > 50)
		{
			printf("Taille invalide, veuillez reessayer.\n");
		}
	} while(*tailleB < 1 || *tailleB > 50);
}
void remplirTableau(int *tableau1, int taille1, int *tableau2, int taille2)
{
	int i;
	printf("Remplissage de A:\n");
	for(i=0;i<taille1;i++)
	{
		printf("A[%d]=",i);
		scanf("%d", &tableau1[i]);
	}
	printf("Remplissage de B:\n");
	for(i=0;i<taille2;i++)
	{
		printf("B[%d]=",i);
		scanf("%d", &tableau2[i]);
	}
}
void ajoutdeBaA(int *tableau1, int taille1, int *tableau2, int taille2)
{
	int i,j=0;
	for(i=taille1;i<taille1 + taille2;i++)
	{
		tableau1[i]=tableau2[j];
		j++;
	}
}
void afficherTableau(int *tableau, int taille1, int taille2)
{
	int i;
	printf("//Affichage de A//\n");
	for(i=0;i<taille1 + taille2;i++)
	{
		printf("A[%d]=%d\n",i,tableau[i]);
	}
}

