#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void saisirTexte(char *tableau);
void compter_a_et_es(char *tableau);
int main()
{
    char texte[100];
    saisirTexte(texte);
    compter_a_et_es(texte);
    return (0);
}
void saisirTexte(char *tableau)
{
    int i=0;
    printf("Entrer le texte caractere par caractere :\n");
	do
	{
		scanf("%c", &tableau[i]);
		if(tableau[i]=='.')
		{
			break;
		}
		i++;
	}while(i<50);
}
void compter_a_et_es(char *tableau)
{
	int i;
	int counta=0, countes=0;
	int n=strlen(tableau);
	for(i=0;i<n;i++)
	{
		if(tableau[i]=='a')
		{
			counta++;
		}
		if(tableau[i]=='e' && tableau[1]=='s')
		{
			countes++;
		}
	}
	printf("Le nombre d'appariton de 'a' est %d et celui de 'es' est %d \n",counta,countes);
}
