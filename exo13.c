#include<stdio.h>
int degre(void);
void afficherPascal(int degre);
int main()
{
    int n;
    n=degre();
    afficherPascal(n);
    return(0);
}
int degre(void)
{
    int degre;
    printf("Entrer le degre du triangle de Pascal que vous voulez :");
    scanf("%d", &degre);
    return(degre);
}
void afficherPascal(int degre)
{
    int i,j,k,coef;
    for(i=0;i<degre;i++)
    {
        coef=1;
        for(j=0;j<degre-i-1;j++)
        {
            printf(" ");
        }
        for(j=0;j<=i;j++)
        {
            printf("%d ", coef);
            coef=coef * (i-j) / (j+1);
        }
        printf("\n");
    }
}