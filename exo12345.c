#include <stdio.h>
void remplirTableau(int *tableau, int taille);
void afficherTableau(int *tableau, int taille);
void afficherSomme(int S);
int entrerTaille();
int calculSomme(int *tableau, int taille);
void afficherMax(int *tableau, int taille);
void effacer0(int *tableau, int *taille);
void separerPosNeg(int *tableau, int *tableau1, int *tableau2, int taille, int *taille1, int *taille2);
void afficherPosNeg(int *tableau1, int taille1, int *tableau2, int taille2);
void inverser(int *tableau, int taille);
int main()
{
	int T[50];
	int N,somme,p,n;
	int TPOS[50], TNEG[50];
	N=entrerTaille();
	remplirTableau(T,N);
	afficherTableau(T,N);
	somme=calculSomme(T,N);
	afficherSomme(somme);
	afficherMax(T,N);
	effacer0(T,&N);
	afficherTableau(T,N);
	separerPosNeg(T,TPOS,TNEG,N,&p,&n);
	afficherPosNeg(TPOS,p,TNEG,n);
	inverser(T,N);
	afficherTableau(T,N);
	return(0);
}
int entrerTaille(void)
{
	int n,r;
	// Demande à l'utilisateur de saisir la taille du tableau
	do
	{
		printf("Entrer la taille du tableau T (max 50):");
		r=scanf("%d", &n);
		if(r!=1)
		{
			while(getchar()!='\n'); // vider le tampon d'entrée
			printf("Erreur de saisie, veuillez entrer un nombre entier.\n");
			n = 0; // Réinitialiser n pour forcer une nouvelle saisie
		}
		// Vérifie si la taille est valide (entre 1 et 50)
		// Si la taille n'est pas valide, demande à l'utilisateur de réessayer
		if(n<1 || n>50)
		{
			printf("Taille invalide, veuillez reessayer.\n");
		}
	} while(n<1 || n>50);
	printf("Entrer la taille du tableau T:");
	scanf("%d", &n);
	return (n);
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
void afficherTableau(int *tableau, int taille)
{
	int i;
	printf("//Affichage//\n");
	for(i=0;i<taille;i++)
	{
		printf("T[%d]=%d",i,tableau[i]);
		printf("\n");
	}
}
int calculSomme(int *tableau, int taille)
{
	int i,S=0;
	for(i=0;i<taille;i++)
	{
		S=S+tableau[i];
	}
	return (S);
}
void afficherSomme(int S)
{
	printf("somme=%d\n", S);
}
void afficherMax(int *tableau, int taille)
{
	int i,max,position;
	max=tableau[0];
	for(i=0;i<taille;i++)
	{
		if(tableau[i]>max)
		{
			max=tableau[i];
			position=i;
		}
	}
	printf("max=T[%d]=%d\n",position,max);
}
void effacer0(int *tableau, int *taille)
{
	int i,j;
	for(i=0;i<*taille;i++)
	{
		if(tableau[i]==0)
		{
			(*taille)--;
			for(j=0;j<*taille;j++)
			{
				if(j>=i)
				{
					tableau[j]=tableau[j+1];
				}
				else
				{
					tableau[j]=tableau[j];
				}
			}
		}
	}
}
void separerPosNeg(int *tableau, int *tableau1, int *tableau2, int taille, int *taille1, int *taille2)
{
	int i;
	*taille1=0;
	*taille2=0;	
	for(i=0;i<taille;i++)
	{
		if(tableau[i]>0)
		{
			tableau1[*taille1]=tableau[i];
			(*taille1)++;
		}
		else
		{
			tableau2[*taille2]=tableau[i];
			(*taille2)++;
		}
	}
}
void afficherPosNeg(int *tableau1, int taille1, int *tableau2, int taille2)
{
	int i;
	printf("//Affichage TPOS//\n");
	for(i=0;i<taille1;i++)
	{
		printf("TPOS[%d]=%d\n",i,tableau1[i]);
	}
	printf("//Affichage TNEG//\n");
	for(i=0;i<taille2;i++)
	{
		printf("TNEG[%d]=%d\n",i,tableau2[i]);
	}
}
void inverser(int *tableau, int taille)
{
	int i,j=taille-1,tmp;
	for(i=0;i<taille/2;i++)
	{
		tmp=tableau[i];
		tableau[i]=tableau[j];
		tableau[j]=tmp;
		j--;
	}
}




