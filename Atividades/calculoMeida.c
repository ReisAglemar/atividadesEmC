#include <stdio.h>

int main()
{
    float nota1, nota2, nota3, nota4, mediaNotas = 0;

    printf("\ninsirada as notas obtidas nas atividades:\n");
    scanf("%f %f %f %f", &nota1, &nota2, &nota3, &nota4);
    
    mediaNotas = (nota1 + nota2 + nota3 + nota4)/4;

    printf("\nSua média foi: %.2f\n\n", mediaNotas);

    return(0);
}