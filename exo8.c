#include<stdio.h>
#include<string.h>
void saisirChaine(char *tableau);
void saisir_et_compter_bigramme(char *tableau);
int main()
{
    char chaine[10];
    saisirChaine(chaine);
    saisir_et_compter_bigramme(chaine);
    return(0);
}
void saisirChaine(char *tableau)
{
    printf("Entrer la chaine de caracteres: ");
    scanf("%s", tableau);
    while(getchar()!='\n');
}
void saisir_et_compter_bigramme(char *tableau)
{
    char bigramme[3];
    int i, countbig=0;
    int n=strlen(tableau);
    printf("Entrer le bigramme :");
    scanf("%s", bigramme);
    while(getchar()!='\n');
	for(i=0;i<n;i++)
	{
		if(tableau[i]==bigramme[0] && tableau[i+1]==bigramme[1])
		{
			countbig++;
		}
	}
	printf("Le nombre d'occurences du bigramme '%s' est %d\n",bigramme, countbig);
}