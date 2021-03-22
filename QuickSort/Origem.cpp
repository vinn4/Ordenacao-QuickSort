#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>
#define VETOR 10
void troca(int vet[], int i, int j);
int particao(int vet[], int p, int u);
void QuickSortC(int vet[], int p, int u);


int main() {

	setlocale(LC_ALL, "portuguese");   //uso de acentuação na main.
	int vet[VETOR] = { 0 };
	srand(time(NULL)); // gera semente aleatoria.
	//inserção de dados.

	for (int i = 0; i < VETOR; i++)
	{
		vet[i] = rand() % 100; //gera valores entre 0 a 99.
	}
	printf("vetor não ordaneado:\n");
	for (int i = 0; i < VETOR; i++)
	{
		printf("%d \n", vet[i]);
	}

	QuickSortC(vet, 0, VETOR - 1);

	printf("Vetor ordenado CRESCENTE: \n\n");
	for (int i = 0; i < VETOR; i++)        // imprime ordanado com quicksort
	{
		printf("%d \n", vet[i]);
	}
	system("pause");
	return 0;
}

// QUICKSORT CRESCENTE ****
void QuickSortC(int vet[], int p, int u)
{
	int m;
	if (p < u)
	{
		m = particao(vet, p, u);
		QuickSortC(vet, p, m);    //esq
		QuickSortC(vet, m + 1, u);    //dire
	}
}

int particao(int vet[], int p, int u)  // encontra o pivo, faz varreduras e troca.
{
	int pivo, pivo_pos, i, j;
	pivo_pos = (p + u) / 2;
	pivo = vet[pivo_pos];

	i = p - 1;
	j = u + 1;

	while (i < j)
	{
		do       //testa lado direito
		{
			j--;
		} while (vet[j] > pivo);
		do   //testa lado esquerdo
		{
			i++;
		} while (vet[i] < pivo);

		if (i < j)
		{
			troca(vet, i, j);
		}
	}
	return j;
}

void troca(int vet[], int i, int j) //função troca
{
	int aux;
	aux = vet[i];
	vet[i] = vet[j];
	vet[j] = aux;
}
