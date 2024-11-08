#include <stdio.h>

void countingSort(int vetor[], int tamanho) {
    int maximo = vetor[0];

    // Encontrando o valor máximo
    for(int i = 1; i < tamanho; i++) {
        if(vetor[i] > maximo) {
            maximo = vetor[i];
        }
    }

    int contador[maximo + 1];

    // Inicializando o array de contagem
    for(int j = 0; j <= maximo; j++) {
        contador[j] = 0;
    }

    // Contando as ocorrências de cada elemento
    for(int z = 0; z < tamanho; z++) {
        contador[vetor[z]]++;
    }

    // Somando as contagens para criar a posição acumulada
    for(int k = 1; k <= maximo; k++) {
        contador[k] += contador[k - 1];
    }

    // Array de saída para manter a ordem dos elementos originais
    int saida[tamanho];

    // Construindo o array de saída usando o array acumulado
    for(int z = tamanho - 1; z >= 0; z--) {
        saida[contador[vetor[z]] - 1] = vetor[z];
        contador[vetor[z]]--;
    }

    // Copiando o array de saída de volta para vetor
    for(int i = 0; i < tamanho; i++) {
        vetor[i] = saida[i];
    }
}

int main() {
    int vetor[] = {4, 2, 2, 8, 3, 8};
    int tamanho = sizeof(vetor) / sizeof(vetor[0]);

    countingSort(vetor, tamanho);

    printf("Array ordenado: ");
    for (int i = 0; i < tamanho; i++) {
        printf("%d ", vetor[i]);
    }

    return 0;
}
