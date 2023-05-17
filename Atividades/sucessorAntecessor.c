#include <stdio.h>

int main()
{

    int valorDeInteresse = 0;

    printf("\nInsirado o valor de interrese:");
    scanf("%d", &valorDeInteresse);
  
    printf("\n o antecessor é %d e o sucessor é %d\n\n", valorDeInteresse -1, valorDeInteresse +1);

    return(0);    
}