#ifndef QUICKSORT_H_INCLUDED
#define QUICKSORT_H_INCLUDED

void quick_sort(int *vetor, int inicio, int fim)
{
	int i, j, pivo, aux;

	i = inicio;
	j = fim - 1;

	pivo = vetor[(inicio + fim) / 2];

	while(i <= j)
	{
		while(vetor[i] < pivo && i < fim)
		{
			i++;
		}

		while(vetor[j] > pivo && j > inicio)
		{
			j--;
		}

		if(i <= j)
		{
			aux = vetor[i];
			vetor[i] = vetor[j];
			vetor[j] = aux;

			i++;
			j--;
		}
	}

	if(j > inicio)
    {
        quick_sort(vetor, inicio, j + 1);
    }

	if(i < fim)
    {
        quick_sort(vetor, i, fim);
    }
}

#endif // QUICKSORT_H_INCLUDED
