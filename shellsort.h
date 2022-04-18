#ifndef SHELLSORT_H_INCLUDED
#define SHELLSORT_H_INCLUDED

void shell_sort(int *vetor, int tamanho)
{
    int i, j, valor;
    int h = 1;

    while(h < tamanho)
    {
        h = 3*h+1;
    }
    while (h > 0)
    {
        for(i = h; i < tamanho; i++)
        {
            valor = vetor[i];

            j = i;

            while (j > h-1 && valor <= vetor[j - h])
            {
                vetor[j] = vetor[j - h];
                j = j - h;
            }

            vetor[j] = valor;
        }

        h = h/3;
    }
}

#endif // SHELLSORT_H_INCLUDED
