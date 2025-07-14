#include<stdio.h>
#include<string.h>
void saisirPhrase(char *tableau);
void crypter(char *tableau);
int main()
{
    char phrase[200]={0};
    saisirPhrase(phrase);
    crypter(phrase);
    return(0);
}
void saisirPhrase(char *tableau)
{
    printf("Entrer une phrase a crypter :");
	fgets(tableau,200*sizeof(char),stdin);
}
void crypter(char *tableau)
{
    char voyelles[6]="aeiouy";
    int n=strlen(tableau);
    int i,j,k;
    for(i=0;i<n;i++)
	{
		k=0;
		for(j=0;j<6;j++)
		{
			if(tableau[i]==voyelles[j])//verifier si phrase[i] est une consonne
			{
				k++;
				break;
			}
		}
		if(k==0 && (i+1)!=n-1)//si phrase[i] est une consonne k=0
		{
			for(j=0;j<6;j++)
			{
				if(tableau[i+1]==voyelles[j])//verifier si phrase[i+1] est une voyelle
				{
					k++;
					break;
				}
			}
			if(k==1)//si phrase[i+1] est une voyelle k=1
			{
				j=n-2;
				while(j>=i+1)//recopier depuis la fin les lettres de la phrase jusqu'au dernier voyelle ou on va ajouter l'IT
				{
					tableau[j+2]=tableau[j];
					j--;
				}
				tableau[i+1]='I';
				tableau[i+2]='T';
				i+=2;
				n=n+2;//la longueur de la chaine augmente de 2 caracteres
			}
		}
	}
	printf("Phrase en cryptee : %s\n", tableau);
}