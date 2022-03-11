#include <stdio.h>
#include <stdlib.h>

void maiorEMenor(float valor, float menorDoMes);

void diasDeMaiorMenor(float *matrizValores, float menorDoMes,int diasDoMes);

void main(){

    // Variavel que vai amazenar os dias do m�s.
    int diasDoMes;

    // Instanciando os contadores.
    int cont=0, cont2=0;

    // O ponteiro que vai receber os valores que est�o sendo alocados dinamicamente
    float *matrizValores;

    // Variaveis que v�o armazenar os valores 
    float valor =0, maiorDoMes = 0, menorDoMes = 0;

    // Pedindindo a quantidade de dias no mes.
    scanf("%d", &diasDoMes);

    // Uso uma variavel alocada dinamicamente para aramazenar os valores
    // O malloc faz o preparo para a quantidade de memoria necess�ria para o 
    // Funcionamento do programa
    // O sizeof retorna a quantidade de bits necess�ria para armazenar um float --> [4]
    // Que multiplicado pela quantidade de dias, retorna a mam�ria necess�ria.
    matrizValores = (float *)malloc(sizeof(float)*diasDoMes);

    // For que vai axiliar na apanhagem de alguns valores e no filtro.
    for (int i = 0; i < diasDoMes; i++)
    {

        //Pedindo os valores de entrada
        scanf("%f", &matrizValores[i]);

        // Essa variavel � importante por que faz o somat�rio de todos os valores
        // Auxilando na demonstra��o final
        valor += matrizValores[i];

        // Cada dia n�o uitl � marcado como 0, e para termos um apanhado dos dias de lucro
        // Essa variavel realiza a contagem.
        if(matrizValores[i] != 0)
        {

            cont++;

        }

        // Essa condi��o verifica qual o dia com maior rendimento
        if(matrizValores[i] > maiorDoMes)
        {

            maiorDoMes = matrizValores[i];

        }

    }

    // Igualo o menor com o menor para que depois eu possa apenas fazer a compara��o.
    // Achei que me daria menos dor de cabe�a fazendo a apura��o dessa maneira.
    menorDoMes = maiorDoMes;

    // Alaguns dados que n�o precisam de fun��es especificas s�o printados
    printf(" Dias Uteis: %d\n Media de Vendas: %.2f\n Media de Vendas em dias Uteis: %.2f\n", cont, (valor/diasDoMes), (valor/cont));

    // Apenas chamada de fun��o.
    printf(" Maior do Mes: ");
    maiorEMenor(valor, maiorDoMes);

    // Um for que eu relutei em colocar.
    // Tentei tirar o m�ximo de for que consegui, no entanto esse foi necess�rio, j� que preciso percorrer a lista
    // para encontrar o menor valor
    for (int i = 0; i < diasDoMes; i++)
    {
        
        // Apenas verifico se o valor � menor que o exposto.
        if(matrizValores[i] < menorDoMes){

            // Os dias que de n�o lucro n�o entram nessa condi��o
            // ent�o preciso tirar os 0's
            if((int)matrizValores[i] != 0){

                menorDoMes = matrizValores[i];

            }
        }
    }

    // Apenas chamada de fun��o.
    printf(" Dias com o menor rendimento: ");
    diasDeMaiorMenor(matrizValores, maiorDoMes, diasDoMes);
    
    printf("\n");

    // Apenas chamada de fun��o.
    printf(" Menor do Mes: ");
    maiorEMenor(valor, menorDoMes);
    
    // Apenas chamada de fun��o.
    printf(" Dias com o menor rendimento: ");
    diasDeMaiorMenor(matrizValores, menorDoMes, diasDoMes);
}

// Apenas imprime o menor valor e o maior
void maiorEMenor(float valor, float menorDoMes){

    if ((int)valor == valor)
    {
        printf("%.1f\n", menorDoMes);
    }else{

        printf("%.2f\n", menorDoMes);

    }

}

// Vejo em dias o maior valor e o menor aparecem
void diasDeMaiorMenor(float *matrizValores, float menorDoMes,int diasDoMes){

    // For que percorre a lista.
    for (int i = 0; i < diasDoMes; i++)
    {

        // Verifico se s�o iguais.
        if (matrizValores[i] == menorDoMes)
        {

            printf("%d ", (i + 1));

        }
    }
}