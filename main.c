#include <stdlib.h>
#include <stdint.h>
#include <stdio.h>
#include <locale.h>

//Bibliotecas para medir gasto de tempo e processamento para funcionamento dos algoritmos de ordenação:
#include <windows.h>
#include <winbase.h>
#include <psapi.h>
#include <time.h>

//Algoritmo de gerar os elementos de um vetor:
#include "geracao.h"

//Algoritmos de ordenação quadrática:
#include "heapsort.h"
#include "mergesort.h"
#include "quicksort.h"
#include "shellsort.h"

double get_memory_used_MB()
{
    PROCESS_MEMORY_COUNTERS info;
    GetProcessMemoryInfo(GetCurrentProcess(), &info, sizeof(info));

    return (double)info.PeakWorkingSetSize / (1024 * 1024);
}

int main(int argc, char **argv)
{
    setlocale(LC_ALL, "Portuguese");

    srand(time(0));

    clock_t start_time, end_time;
    double cpu_time_used, memory_used;
    size_t peakSize;

    int tamanho;

    FILE *arquivo;

    arquivo = fopen("Dados dos Algoritmos.txt", "w");

    //testando se o arquivo foi realmente criado
    if(arquivo == NULL)
    {
        printf("Erro na abertura do arquivo!");

        return 1;
    }

    /*
    for(opcao_algoritmo = 1; opcao_algoritmo < 5; opcao_algoritmo++)
    {
        if(opcao_algoritmo == 0)
        {
            printf("Algoritmo: Shell Sort\n\n");
        }
        else if(opcao_algoritmo == 1)
        {
            printf("Algoritmo: Merge Sort\n\n");
        }
        else if(opcao_algoritmo == 2)
        {
            printf("Algoritmo: Quick Sort\n\n");
        }
        else if(opcao_algoritmo == 3)
        {
            printf("Algoritmo: Heap Sort\n\n");
        }

        for(opcao_geracao = 3; opcao_geracao >= 1; opcao_geracao--)
        {
            for(int cont = 1; cont <= 7; cont++)
            {
                tamanho = 100000 * pow(2, cont);

                int *vetor = calloc(tamanho, sizeof(int));

                if(opcao_geracao == 1)
                {
                    decrescente(vetor, tamanho);
                }
                else if(opcao_geracao == 2)
                {
                    aleatorio(vetor, tamanho);
                }
                else if(opcao_geracao = 3)
                {
                    crescente(vetor, tamanho);
                }

                if(opcao_algoritmo == 1)
                {
                    start_time = clock();

                    shell_sort(vetor, tamanho);

                    end_time = clock();
                }
                else if(opcao_algoritmo == 2)
                {
                    start_time = clock();

                    merge_sort(vetor, 0, tamanho);

                    end_time = clock();
                }
                else if(opcao_algoritmo == 3)
                {
                    start_time = clock();

                    quick_sort(vetor, 0, tamanho);

                    end_time = clock();
                }
                else if(opcao_algoritmo == 4)
                {
                    start_time = clock();

                    heap_sort(vetor, tamanho);

                    end_time = clock();
                }

                cpu_time_used = ((double) (end_time - start_time)) / CLOCKS_PER_SEC;
                memory_used = get_memory_used_MB();

                printf("Tempo gasto: %.2lf; Memoria gasta: %.2lf\n", cpu_time_used, memory_used);
                fprintf(arquivo, "Tempo gasto: %.2lf; Memoria gasta: %.2lf\n", cpu_time_used, memory_used);

                free(vetor);
            }

            printf("-------------------------------------------------\n");
        }
    }
    */

    //Qual tipo de algoritmo está sendo utilizado:
    int opcao_algoritmo = 4;

    if(opcao_algoritmo == 1)
    {
        printf("Algoritmo: Shell Sort\n\n");
        fprintf(arquivo, "Algoritmo: Shell Sort\n\n");
    }
    else if(opcao_algoritmo == 2)
    {
        printf("Algoritmo: Merge Sort\n\n");
        fprintf(arquivo, "Algoritmo: Merge Sort\n\n");
    }
    else if(opcao_algoritmo == 3)
    {
        printf("Algoritmo: Quick Sort\n\n");
        fprintf(arquivo, "Algoritmo: Quick Sort\n\n");
    }
    else if(opcao_algoritmo == 4)
    {
        printf("Algoritmo: Heap Sort\n\n");
        fprintf(arquivo, "Algoritmo: Heap Sort\n\n");
    }

    //Qual tipo de geração está sendo utilizado:
    int opcao_geracao = 3;

    if(opcao_geracao == 1)
    {
        printf("Tipo de geração: decrescente\n\n");
        fprintf(arquivo, "Tipo de geração: decrescente\n\n");
    }
    else if(opcao_geracao == 2)
    {
        printf("Tipo de geração: aleatória\n\n");
        fprintf(arquivo, "Tipo de geração: aleatória\n\n");
    }
    else if(opcao_geracao = 3)
    {
        printf("Tipo de geração: crescente\n\n");
        fprintf(arquivo, "Tipo de geração: crescente\n\n");
    }

    for(int cont = 1; cont <= 7; cont++)
    {
        tamanho = 4500000 * pow(2, cont);

        int *vetor = calloc(tamanho, sizeof(int));

        if(opcao_geracao == 1)
        {
            decrescente(vetor, tamanho);
        }
        else if(opcao_geracao == 2)
        {
            aleatorio(vetor, tamanho);
        }
        else if(opcao_geracao = 3)
        {
            crescente(vetor, tamanho);
        }

        if(opcao_algoritmo == 1)
        {
            start_time = clock();

            shell_sort(vetor, tamanho);

            end_time = clock();
        }
        else if(opcao_algoritmo == 2)
        {
            start_time = clock();

            merge_sort(vetor, 0, tamanho);

            end_time = clock();
        }
        else if(opcao_algoritmo == 3)
        {
            start_time = clock();

            quick_sort(vetor, 0, tamanho);

            end_time = clock();
        }
        else if(opcao_algoritmo == 4)
        {
            start_time = clock();

            heap_sort(vetor, tamanho);

            end_time = clock();
        }

        cpu_time_used = ((double) (end_time - start_time)) / CLOCKS_PER_SEC;
        memory_used = get_memory_used_MB();

        //printf("Tamanho do vetor: %i; Tempo gasto: %.2lf; Memoria gasta: %.2lf\n", tamanho, cpu_time_used, memory_used);
        //fprintf(arquivo, "Tamanho do vetor: %i; Tempo gasto: %.2lf; Memoria gasta: %.2lf\n", tamanho, cpu_time_used, memory_used);

        printf("%i; %.2lf; %.2lf\n", tamanho, cpu_time_used, memory_used);
        fprintf(arquivo, "%i; %.2lf; %.2lf\n", tamanho, cpu_time_used, memory_used);

        free(vetor);
    }

    fclose(arquivo);

    return 0;
}
