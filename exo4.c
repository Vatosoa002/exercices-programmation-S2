#include<stdio.h>
#include<stdbool.h>
void entrerTaille(int *taille1, int *taille2);
void remplirT1etT2(int *tableau1, int *tableau2, int taille1, int taille2);
void afficherT1(int *tableau1, int taille1);
void afficherT2(int *tableau, int taille);
void supprimerT2(int *tableau1, int *tableau2, int *taille1, int taille2, bool *test);
int main()
{
    int n1,n2;
    int T1[50], T2[100];
    bool exister=false;
    entrerTaille(&n1,&n2);
    remplirT1etT2(T1,T2,n1,n2);
    afficherT1(T1,n1);
    afficherT2(T2,n2);
    supprimerT2(T1,T2,&n1,n2,&exister);
    if(exister==true)
    {
        printf("Apres suppression de T1 dans T2: ");
        afficherT1(T1,n1);
    }
    return (0);
}
void entrerTaille(int *taille1, int *taille2)
{
    int r;
    do
	{
		printf("Entrer la taille de T1 :");
		r=scanf("%d", taille1);
		if(r!=1)
		{
			while(getchar()!='\n');
			*taille1=0;
		}
		printf("Entrer la taille de T2 :");
		r=scanf("%d", taille2);
		if(r!=1)
		{
			while(getchar()!='\n');
			*taille2=0;
		}
		if((*taille1<1 || *taille1>50) || (*taille2<1 || *taille2>100))
		{
			printf("La taille doit etre comprise entre 1 et 100 pour T2 et 1 et 50 pour T1\n");
		}
	}while((*taille1<1 || *taille1>50) || (*taille2<1 || *taille2>100));
}
void remplirT1etT2(int *tableau1, int *tableau2, int taille1, int taille2)
{
    int i;
    //Remplissage T1
    for(i=0;i<taille1;i++)
	{
		printf("Entrer l'element %d de T1 :",i+1);
		scanf("%d", &tableau1[i]);
	}
    //Remplissage T2
    for(i=0;i<taille2;i++)
	{
		printf("Entrer l'element %d de T2 :",i+1);
		scanf("%d", &tableau2[i]);
	}
}
void afficherT1(int *tableau1, int taille1)
{
    int i;
    printf("//Affichage T1//\n");
    for(i=0;i<taille1;i++)
	{
		printf("%d ", tableau1[i]);
	}
    printf("\n");
}
void afficherT2(int *tableau,int taille)
{
    int i;
    printf("Affichage T2//\n");
    for(i=0;i<taille;i++)
	{
		printf("%d ",tableau[i]);
	}
    printf("\n");
}
void supprimerT2(int *tableau1, int *tableau2, int *taille1, int taille2, bool *test)
{
    int i,j,k,c;
    i=0;
        debut:
	j=0;
    //parcourir T1
	do
	{
        //Verifier si T2 existe bien dans T1 et dans la meme ordre
		if(tableau1[i]==tableau2[j])
		{
			j++;
		}
        //Si on n'a pas trouver l'ordre des elements de T2, on revient a rechercher T2[0]
		else 
		{
			if(j==0)
			{
				i++;
				goto debut;
			}
			else
			{
				goto debut;
            }
		}
        //Si tous les elements de T2 sont trouvees , quitter la boucle
		if(j==taille2)
		{
			break;
		}
		i++;
	}while(i<*taille1);
    c=0;
    if(j==taille2)//Si tous les elements de T2 ont ete trouve
	{
		printf("T2 existe dans T1\n");
        *test=true;
        //On parcour T1
		for(k=0;k<*taille1;k++)
		{
			if(k<=i && k>i-taille2)//Si on passe par les cases qui contiennent les elements de T2 sauter
			{
				continue;
			}
			else//Sinon on recopie tous les elements dans T1
			{
				tableau1[c]=tableau1[k];
				c++;
			}
		}
        *taille1=c;
    }
    else if(j!=taille2)
	{
		printf("T2 n'existe pas dans T1\n");
	}
}