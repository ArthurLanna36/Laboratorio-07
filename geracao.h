#ifndef GERACAO_H_INCLUDED
#define GERACAO_H_INCLUDED

#include <stdio.h>
#include <math.h>
#include <time.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>

//PROCEDIMENTO PARA TROCAR DOIS ELEMENTOS DO VETOR
void swap1(int *elemento_vetor1, int *elemento_vetor2)
{
   int temp = *elemento_vetor1;

   *elemento_vetor1 = *elemento_vetor2;
   *elemento_vetor2 = temp;
}

//PROCEDIMENTO PARA PREENCHER UM ARRANJO COM ELEMENTOS EM ORDEM CRESCENTE

void crescente(int *vetor, int tamanho)
{
    for (int cont = 0; cont < tamanho; cont++)
    {
        vetor[cont] = cont;
    }
}

// PROCEDIMENTO PARA PREENCHER UM ARRANJO COM ELEMENTOS EM ORDEM DECRESCENTE
void decrescente(int *vetor, int tamanho)
{
    for (int cont = 0; cont < tamanho; cont++)
    {
        vetor[cont] = tamanho - 1 - cont;
    }
}

// PROCEDIMENTO PARA PREENCHER UM ARRANJO COM ELEMENTOS EM ORDEM ALEATORIA
void aleatorio(int *vetor, int tamanho)
{
    crescente(vetor, tamanho);

    srand(time(NULL));

    for (int cont = 0; cont < tamanho; cont++)
    {
        swap1(&vetor[cont], &vetor[rand() % tamanho]);
    }
}

// PROCEDIMENTO PARA PREENCHER UM ARRANJO COM ELEMENTOS DA ENTRADA PADRAO
int entradaPadrao(int *vetor)
{
    int tamanho;

    printf("Digite o tamanho do seu vetor: ");
    scanf("%i", &tamanho);

    *vetor = malloc(tamanho * sizeof(int));

    for (int cont = 0; cont < tamanho; cont++)
    {
        scanf("%i", &vetor[cont]);
    }

    return tamanho;
}

// PROCEDIMENTO PARA EXIBIR OS DADOS PRESENTES NO ARRANJO
void mostrar(int *vetor, int tamanho)
{
    printf("[ ");

    for (int cont = 0; cont < tamanho; cont++)
    {
        printf("%i ", vetor[cont]);
    }

    printf("] \n");
}

// PROCEDIMENTO PARA VERIFICAR SE O ARRANJO ESTA ORDENADO
bool isOrdenado(int *vetor, int tamanho)
{
    bool resposta = true;

    for(int cont = 1; cont < tamanho; cont++)
    {
        if(vetor[cont - 1] > vetor[cont])
        {
            cont = tamanho;

            resposta = false;
        }
    }

    return resposta;
}

#endif // GERACAO_H_INCLUDED

