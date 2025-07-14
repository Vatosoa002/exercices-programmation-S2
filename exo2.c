#include <stdio.h>
void entrerTaille(int *taille);
void remplirTableau(int *tableau, int taille);
void trierTableau(int *tableau, int taille);
void insererX(int *tableau, int *taille);
void afficherTableau(int *tableau, int taille);
int main()
{
    int N;
    int T[50];
    entrerTaille(&N);
    remplirTableau(T,N);
    trierTableau(T,N);
    afficherTableau(T,N);
    insererX(T,&N);
    trierTableau(T,N);
    afficherTableau(T,N);
    return (0);
}
void entrerTaille(int *taille)
{
    printf("Entrer la taille du tableau :");
    scanf("%d", taille);
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
void trierTableau(int *tableau, int taille)
{
    int i,j,tmp;
    for(i=0;i<taille-1;i++)
    {
        for(j=i+1;j<taille;j++)
        {
            if(tableau[i]>tableau[j])//arranger le tableau a l'ordre croissant
            {
                tmp=tableau[i];
                tableau[i]=tableau[j];
                tableau[j]=tmp;
            }
        }
    }
}
void insererX(int *tableau, int *taille)
{
    printf("Veuillez inserer un entier dans le tableau:");
    scanf("%d", &tableau [*taille]);
    (*taille)++;
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
