#include <stdio.h>
#include <string.h>
void saisirChaine(char *tableau);
void palindrome(char *tableau);
int main()
{
    char chaine[50];
    saisirChaine(chaine);
    palindrome(chaine);
    return(0);
}
void saisirChaine(char *tableau)
{
    printf("Ce programme permet de verifier si une chaine de caracteres est palindrome ou non\n");
	printf("Entrer la chaine :");
	scanf("%s", tableau);
}
void palindrome(char *tableau)
{
    int i,j,count=0;
    int n=strlen(tableau);
    if(n%2==0)
    {
        printf("Ce n'est pas un palindrome\n");
    }
    else
    {
        j=n-1;
        for(i=0;i<n/2;i++)
        {
            if(tableau[i]==tableau[j])
            {
                count++;
                j--;
            }
        }
        if(count==n/2)
        {
            printf("C'est un palindrome\n");
        }
        else
        {
            printf("Ce n'est pas un palindrome\n");
        }
    }
}