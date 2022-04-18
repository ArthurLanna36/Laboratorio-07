#ifndef MERGESORT_H_INCLUDED
#define MERGESORT_H_INCLUDED

void merge1(int vetor[], int comeco, int meio, int fim)
{
    int com1 = comeco, com2 = meio + 1, comAux = 0, tam = fim - comeco + 1;
    int *vetAux;

    vetAux = (int*)malloc(tam * sizeof(int));

    while(com1 <= meio && com2 <= fim)
    {
        if(vetor[com1] < vetor[com2])
        {
            vetAux[comAux] = vetor[com1];
            com1++;
        }
        else
        {
            vetAux[comAux] = vetor[com2];
            com2++;
        }
        comAux++;
    }

    while(com1 <= meio)
    {
        //Caso ainda haja elementos na primeira metade
        vetAux[comAux] = vetor[com1];
        comAux++;
        com1++;
    }

    while(com2 <= fim)
    {
        //Caso ainda haja elementos na segunda metade
        vetAux[comAux] = vetor[com2];
        comAux++;
        com2++;
    }

    for(comAux = comeco; comAux <= fim; comAux++)
    {
        //Move os elementos de volta para o vetor original
        vetor[comAux] = vetAux[comAux-comeco];
    }

    free(vetAux);
}

void merge_sort(int vetor[], int comeco, int fim)
{
    if (comeco < fim)
    {
        int meio = (fim + comeco) / 2;

        merge_sort(vetor, comeco, meio);
        merge_sort(vetor, meio + 1, fim);
        merge1(vetor, comeco, meio, fim);
    }
}

#endif // MERGESORT_H_INCLUDED
