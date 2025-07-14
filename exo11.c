#include<stdio.h>
#include<string.h>
void saisirPhrase(char *tableau);
void decrypter(char *tableau);
int main()
{
    char phrase[200]={0};
    saisirPhrase(phrase);
    decrypter(phrase);
    return(0);
}
void saisirPhrase(char *tableau)
{
    printf("Entrer la phrase a decrypter :");
	fgets(tableau,200*sizeof(char),stdin);
}
void decrypter(char *tableau)
{
    int n=strlen(tableau);
    char voyelles[6]="aeiouy";
    int i,j,k;
    for(i=0;i<n;i++)
	{
        if(tableau[i]=='\n')
        {
            tableau[i]='\0';
        }
		k=0;
		for(j=0;j<6;j++)
		{
			if(tableau[i]==voyelles[j])
			{
				k++;
				break;
			}
		}
		if(k==0 && tableau[i+1]=='I' && tableau[i+2]=='T')
		{
			for(j=0;j<6;j++)
			{
				if(tableau[i+3]==voyelles[j])
				{
					k++;
					break;
				}
			}
			if(k==1)
			{
				for(j=i+1;j<n-2;j++)
				{
					tableau[j]=tableau[j+2];
				}
				n=n-2;
			}
		}
	}
	printf("Phrase decryptee : %s\n",tableau);
}