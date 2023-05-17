#include <stdio.h>
#include <math.h>

int main()
{
    float capitalInicial, taxaJurosMensal, aportesMensais, capitalFinal = 0;
    int mesesInvestindo = 0;

    printf("\n============================================================================\n");
    printf("================== CALCULADORA DE JUROS COMPOSTOS MENSAIS ==================\n");
    printf("============================================================================\n\n");

    // definindo o capital inicial
    printf("Qual seria o valor, inicialmente disponível? ");
    scanf("%f", &capitalInicial);
    printf("Perfeito, seu capital inicinal é de: R$%.2f\n\n", capitalInicial);

    // definindo a taxa juros mensal
    printf("Agora, qual será a taxa de juros mensal? ");
    scanf("%f", &taxaJurosMensal);
    printf("Sendo assim, sua taxa de juros será de: %.2f\n\n", taxaJurosMensal);

    // definindo os aportes mensais
    printf("Dando continuidade, você tem algum valor fixo, para depópistos mensais?\nCaso não haja valores disponíveis para aportes mensais, digite zero! ");

    scanf("%f", &aportesMensais);
    printf("Perfeito, seus aportes mensais será no valor de: R$%.2f\n\n", aportesMensais);

    // definindo o tempo da aplicacao
    printf("Por fim, por quantos messes você tem interesse de investir, lembra-se quanto maior o tempo, maior será seu capital final. ");
    scanf("%d", &mesesInvestindo);
    printf("Ótimo, você investirá por %d meses\n\n", mesesInvestindo);
    printf("Muito bom, já tenho todos os dados de que preciso para realizar os cálculos, só um instante...\n\n");

    // desvio de fluxo baseado na AUSENCIA de aportes memsais
    if (aportesMensais == 0)
    {

        /* realizacao dos calculos, formula: CF = CI*(1+(TX/100))^MI

            onde: CF = capital final
                  CI = capital inicial
                  TX = taxa de juros divido por 100, divide-se por 100 a fim de obter seu valor em porcentagem
                  MI = messes invetido, periodo pelo qual o invetimento ficara aplicado
        */
        capitalFinal = capitalInicial * (pow((1 + (taxaJurosMensal / 100)), mesesInvestindo));
        printf("Na sua escolhe não há aportes mensais, e o prazo definido foi de %d meses.\n\n", mesesInvestindo);
        printf("Sendo assim, seu saldo final será de: R$%.2f\n", capitalFinal);
        printf("============================================================================\n\n");
    }
    // desvio de fluxo baseado na EXISTENCIA de aportes memsais
    else
    {

        for (int i = 1; i <= mesesInvestindo; i++)
        {

            /* realizacao dos calculos, formula: CF = (CI*(1+(TX/100)))+AM

            onde: CF = capital final
                  CI = capital inicial
                  TX = taxa de juros divido por 100, divide-se por 100 a fim de obter seu valor em porcentagem
                  AM = aportes mensais, o valor que será acrescido ao final de todos os meses

            OBSERVACAO: todo numero elevado a um e ele mesmo, como a calculo de juros compostos
                        com aportes deve ser feito linha a linha o perioso sempre sera um, dessa
                        forma pode-se suprimir a parte de exponenciacao.
        */
            capitalFinal = (capitalInicial * (1 + (taxaJurosMensal / 100))) + aportesMensais;

            /* capitalInicial = capitalFinal, isso quer dizer que ao inicio do segundo mes o capital inicial sera
               o capital final do mes anterior.  
            */
            capitalInicial = capitalFinal;
            printf("Na sua escolhe há aportes mensais, no valor de %.2f e o prazo definido foi de %d meses.\n", aportesMensais, mesesInvestindo);
            printf("Sendo assim, seu saldo no final do mês %d será de: R$%.2f\n", i, capitalFinal);
            printf("============================================================================\n\n");
        }
    }
    return (0);
}