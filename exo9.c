#include<stdio.h>
#include<string.h>
void saisirChaine(char *tableau);
void CarreeOuNon(char *tableau);
int main()
{
    char chaine[20];
    saisirChaine(chaine);
    CarreeOuNon(chaine);
    return(0);
}
void saisirChaine(char *tableau)
{
    printf("Entrer la chaine de caracteres :");
	scanf("%s", tableau);
}
void CarreeOuNon(char *tableau)
{
    int n=strlen(tableau);
    int i,j,compteur;
    if(n%2 != 0)
    {
        printf("Cette chaine n'est pas carree\n");
    }
    else
    {
        compteur=0;
        j=n/2;
        for(i=0;i<n/2;i++)
        {
            if(tableau[i]==tableau[j])
            {
                compteur++;
                j++;
            }
        }
        if(compteur==n/2)
        {
            printf("Cette chaine est carree\n");
        }
        else
        {
            printf("Cette chaine n'est pas carree\n");
        }
    }
}