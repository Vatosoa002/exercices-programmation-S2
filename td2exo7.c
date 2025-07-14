#include <stdio.h>
void entrerTaille(int *taille);
void remplirTableau(int *tableau1, int *tableau2, int taille);
void produitScalaire(int *tableau1, int *tableau2, int taille);
int main()
{
	int U[10],V[10];
	int n;
	entrerTaille(&n);
	remplirTableau(U,V,n);
	produitScalaire(U,V,n);
	return (0);
}
void entrerTaille(int *taille)
{
	int r;
	do
	{
		printf("Entrer le nombre de coordonnees de U et V (max 10):");
		r=scanf("%d", taille);
		if(r!=1)
		{
			while(getchar()!='\n'); // vider le tampon d'entrée
			printf("Erreur de saisie, veuillez entrer un nombre entier.\n");
			*taille = 0; // Réinitialiser taille pour forcer une nouvelle saisie
		}
		// Vérifie si la taille est valide (entre 1 et 10)
		// Si la taille n'est pas valide, demande à l'utilisateur de réessayer
		if(*taille < 1 || *taille > 10)
		{
			printf("Taille invalide, veuillez reessayer.\n");
		}
	} while(*taille < 1 || *taille > 10);
}
void remplirTableau(int *tableau1, int *tableau2, int taille)
{
	int i;
	for(i=0;i<taille;i++)
	{
		printf("U[%d]=",i);
		scanf("%d",&tableau1[i]);
		printf("V[%d]=",i);
		scanf("%d",&tableau2[i]);
	}
}
void produitScalaire(int *tableau1, int *tableau2, int taille)
{
	int i,s=0;
	for(i=0;i<taille;i++)
	{
		s=s+ tableau1[i] * tableau2[i];
	}
	printf("Le produit scalaire de ces vecteurs=%d\n",s);
}
